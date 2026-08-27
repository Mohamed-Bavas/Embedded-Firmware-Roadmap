# Day 18 — Bootloader Basics 🚀

Part of the **Embedded Firmware Roadmap** series (Day 18/20).

---

## 1. What Is a Bootloader?

A **bootloader** is a small piece of firmware that runs **before the main application**, right after reset. Its job is to initialize minimal hardware and decide *what* to run next — either jump to the main application or enter a special mode to receive new firmware.

Think of it as the "gatekeeper" of the MCU: every reset goes through it first.

**Core responsibilities:**
- Run at the reset vector (lowest flash address, e.g. `0x08000000` on STM32).
- Check for a "firmware update" trigger (button press, UART command, flag in flash/EEPROM).
- If update requested → receive new firmware and write it to flash.
- If not → relocate the vector table and jump to the application.

---

## 2. Why Bootloaders Matter

| Without a Bootloader | With a Bootloader |
|---|---|
| Need a JTAG/SWD programmer to update firmware | Update firmware over UART/USB/CAN/Wi-Fi |
| Field devices can't be updated remotely | Enables OTA (Over-The-Air) updates |
| Risk of bricking device on bad flash | Can support dual-bank / rollback recovery |

Used everywhere: IoT devices, automotive ECUs, medical devices, consumer electronics — anywhere firmware needs field updates.

---

## 3. Types of Bootloaders

### By programming method
- **ISP (In-System Programming)** — MCU is programmed while soldered on the board, usually via UART/USB using the **factory/system bootloader** baked into ROM (e.g., STM32's built-in bootloader in System Memory).
- **IAP (In-Application Programming)** — A **custom bootloader** you write yourself, stored in flash, that can reprogram the application area while the MCU is running your own code.

### By structure
- **Primary Bootloader (1st stage):** Minimal, rarely updated, resides in a protected flash sector. Only job: verify and jump to secondary bootloader or app.
- **Secondary Bootloader (2nd stage):** More complex — handles communication protocol, flash erase/write, CRC checks. Can itself be updated by the primary stage in advanced designs.

### By communication interface
UART, USB (DFU), CAN, SPI, I2C, or even Ethernet/Wi-Fi (for OTA).

---

## 4. Flash Memory Layout for a Bootloader System

A typical layout for an STM32-class MCU:

```
0x08000000 ┌───────────────────────────┐
           │   Bootloader Region        │  (e.g., 16–32 KB)
0x08008000 ├───────────────────────────┤
           │   Application Region       │  (rest of flash)
           │                            │
0x0800Fxxx ├───────────────────────────┤
           │  (Optional) Config/Flags   │  (last page: update flag, version, CRC)
           └───────────────────────────┘
```

**Key design rule:** the bootloader region must be **write-protected** from the application (via flash option bytes) so a buggy app update can never overwrite the bootloader itself — otherwise the device becomes unrecoverable ("bricked").

---

## 5. Boot Process Flow (Custom Bootloader)

```
        ┌─────────────┐
        │   Reset      │
        └──────┬───────┘
               ▼
     ┌────────────────────┐
     │ Bootloader starts   │
     │ at 0x08000000       │
     └──────┬─────────────┘
            ▼
   ┌───────────────────────────┐
   │ Check update trigger:      │
   │ - GPIO pin state (button)  │
   │ - Flag in flash/EEPROM     │
   │ - UART byte received in    │
   │   a timeout window         │
   └───────┬───────────┬───────┘
           │ Yes        │ No
           ▼            ▼
 ┌───────────────┐  ┌─────────────────────┐
 │ Enter update    │  │ Relocate vector      │
 │ mode: receive    │  │ table (SCB->VTOR)    │
 │ firmware, erase  │  │ Set MSP from app     │
 │ + write flash    │  │ Jump to app reset    │
 └────────┬─────────┘  │ handler               │
          │             └──────────────────────┘
          ▼
  Reset MCU → re-run bootloader → boots into new app
```

---

## 6. Jumping to the Application — The Critical Code

This is the piece most beginners get wrong. Three steps are mandatory:

```c
#define APP_ADDRESS 0x08008000U

typedef void (*app_entry_t)(void);

void JumpToApplication(void)
{
    uint32_t app_stack_ptr = *(volatile uint32_t *)APP_ADDRESS;
    uint32_t app_reset_handler_addr = *(volatile uint32_t *)(APP_ADDRESS + 4);

    /* 1. Disable all interrupts / peripherals used by bootloader */
    HAL_DeInit();
    __disable_irq();

    /* 2. Relocate the vector table to the application's location */
    SCB->VTOR = APP_ADDRESS;

    /* 3. Set the Main Stack Pointer to the app's stack pointer */
    __set_MSP(app_stack_ptr);

    /* 4. Jump to the application's Reset_Handler */
    app_entry_t app_entry = (app_entry_t)app_reset_handler_addr;
    __enable_irq();
    app_entry();
}
```

**Common mistakes:**
- Forgetting to reset `SCB->VTOR` → app's interrupts fire the bootloader's ISR addresses → hard fault.
- Not resetting peripheral clocks/registers used by the bootloader before jumping.
- Not checking that the application region actually contains valid code (see CRC check below) before jumping — jumping into erased/blank flash (`0xFFFFFFFF`) will hard fault.

---

## 7. Flash Erase & Write Operations

Bootloaders must erase flash **before** writing (flash bits can only go 1→0 when writing; erase resets them to 1).

Typical STM32 HAL sequence:

```c
HAL_FLASH_Unlock();

FLASH_EraseInitTypeDef eraseInit;
eraseInit.TypeErase   = FLASH_TYPEERASE_PAGES;
eraseInit.PageAddress = APP_ADDRESS;
eraseInit.NbPages     = APP_SIZE_IN_PAGES;

uint32_t pageError;
HAL_FLASHEx_Erase(&eraseInit, &pageError);

/* Write received data, word by word */
HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, data_word);

HAL_FLASH_Lock();
```

**Rules of thumb:**
- Always erase full pages/sectors (can't erase a single byte).
- Write in the native program size (word/half-word/double-word depending on MCU).
- Verify what was written (read-back or CRC) before trusting it.

---

## 8. Firmware Image Validation

Before jumping to the app, the bootloader should verify the image is valid — otherwise a corrupted transfer bricks the device.

Common techniques:
1. **CRC32 check** — Store a CRC of the app image; bootloader recomputes and compares.
2. **Magic number / signature** at a fixed address to confirm "this is a valid firmware."
3. **Version + size metadata** stored in a header before the app code.
4. **Stack pointer sanity check** — first word of app region should point into valid RAM (e.g., `0x20000000`–`0x20005000` range).

```c
if ((app_stack_ptr & 0x2FFE0000) == 0x20000000)  // looks like valid RAM address
{
    // proceed with CRC check, then jump
}
else
{
    // stay in bootloader — invalid app
}
```

---

## 9. STM32-Specific Notes

- STM32 chips ship with a **built-in ROM bootloader** in "System Memory," entered by pulling **BOOT0** high (and BOOT1 low, depending on family) at reset — supports UART, USB DFU, CAN, I2C, SPI depending on the chip.
- You can use this factory bootloader for initial programming, **or** write your **own IAP bootloader** in flash for custom protocols/OTA.
- `AN2606` (Application Note) from ST documents exactly which peripherals each STM32 system bootloader supports.
- Dual-bank flash (available on some STM32 lines, e.g., F76x/L4/H7) allows **A/B firmware swapping** — write new image to bank B while running from bank A, then swap on next boot. This gives safe rollback if the new image fails.

---

## 10. UART Bootloader — Minimal Command Protocol Example

A simple custom protocol you might implement for Day 18's mini-exercise:

| Command Byte | Meaning |
|---|---|
| `0x01` | Enter bootloader / handshake ("ACK" back) |
| `0x02` | Erase application flash |
| `0x03` | Write data packet (address + length + payload + CRC) |
| `0x04` | Verify CRC of written image |
| `0x05` | Jump to application |

```c
switch (cmd) {
    case CMD_ERASE:
        Flash_ErasePages(APP_ADDRESS, APP_PAGES);
        UART_SendByte(ACK);
        break;

    case CMD_WRITE:
        Flash_Write(rx_address, rx_buffer, rx_length);
        UART_SendByte(ACK);
        break;

    case CMD_VERIFY:
        if (CRC_Check(APP_ADDRESS, APP_SIZE) == stored_crc)
            UART_SendByte(ACK);
        else
            UART_SendByte(NACK);
        break;

    case CMD_JUMP:
        JumpToApplication();
        break;
}
```

---

## 11. Key Interview Questions for Day 18

1. What's the difference between ISP and IAP?
2. Why must you reset `VTOR` and `MSP` before jumping to the application?
3. How do you prevent a bootloader from bricking a device during a failed update?
4. Why can't you erase a single byte of flash?
5. What happens if you jump to an erased (blank) flash region?
6. How would you design a **fail-safe** bootloader (dual-bank / rollback)?
7. What is flash write protection and how does it protect the bootloader region?
8. How does STM32's BOOT0 pin affect the boot process?

---

## 12. Suggested Mini-Task for Today

Build a **minimal 2-stage system** on STM32 (or simulate in Proteus):
1. Bootloader at `0x08000000` that blinks an LED slowly if no UART command is received in 3 seconds, then jumps to the app.
2. Application at `0x08008000` that blinks the same LED fast, to visually confirm the jump worked.
3. Add a UART command to "erase + reflash" the app region with a new hex image sent from a PC script (Python + `pyserial`).

This exercise touches nearly everything above: memory layout, vector table relocation, flash erase/write, and a simple communication protocol — perfect prep before **Day 19 (RTOS Basics)**.

---

**Status:** ⏳ In Progress — Day 18 of 20
**Next:** Day 19 – RTOS Basics
