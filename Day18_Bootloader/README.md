
# 🚀 Day 18 – Bootloader Basics

Part of the **Embedded Firmware Engineer Learning Journey**.

Today, I learned the **fundamentals of Bootloader Development** and implemented basic bootloader-related programs using the **AT89C51 (8051) microcontroller**.

The practice programs cover **Flash Erase, Flash Write, CRC Validation, Application Jump, UART Command Processing, Bootloader Simulation, and AT89C51 Configuration**.

> **Note:** AT89C51 does not support runtime Flash programming and vector-table relocation in the same way as modern MCUs such as STM32. Therefore, some programs simulate these concepts using C so that the bootloader control flow can be understood before moving to a modern MCU.

---

## 🎯 Objectives

- Understand the purpose of a bootloader
- Understand bootloader and application concepts
- Practice Flash erase and write operations
- Understand firmware integrity using CRC
- Practice application jump concepts
- Implement a basic UART bootloader protocol
- Simulate a complete bootloader flow
- Configure UART and GPIO on AT89C51
- Understand firmware validation and safety checks

---

# 📚 Topics Covered

## 1. Bootloader Fundamentals

A **bootloader** is a small firmware program that executes before the main application.

The basic responsibility of a bootloader is:

```text
MCU Reset
    ↓
Bootloader
    ↓
Check Application
    ↓
Validate Firmware
    ↓
Jump to Application
````

If a firmware update is required, the bootloader can receive a new firmware image, erase the application area, program the new firmware, verify it, and then start the application.

---

# 💾 2. Flash Erase Operation

### Program

`bootloader_flash_erase.c`

This program demonstrates the concept of erasing Flash memory.

A simulated Flash memory is created using an array:

```c
#define FLASH_SIZE 1024

unsigned char flash_memory[FLASH_SIZE];
```

The erase operation sets every byte to `0xFF`.

```c
void Flash_Erase(void)
{
    unsigned int i;

    for (i = 0; i < FLASH_SIZE; i++)
    {
        flash_memory[i] = 0xFF;
    }
}
```

### Concept

```text
Before Erase

Flash:
AA 12 45 67 89 10 ...

        ↓ ERASE

After Erase

Flash:
FF FF FF FF FF FF ...
```

### Learning

* Flash erase concept
* Erased Flash state
* Memory initialization
* Application memory management

---

# ✍️ 3. Flash Write Operation

### Program

`bootloader_flash_write.c`

This program demonstrates writing firmware data into a simulated Flash memory array.

```c
void Flash_Write(unsigned int address,
                 unsigned char data)
{
    if (address < FLASH_SIZE)
    {
        flash_memory[address] = data;
    }
}
```

Example:

```c
Flash_Write(0, 0x55);
Flash_Write(1, 0xAA);
Flash_Write(2, 0x12);
```

The data is stored at the specified addresses.

### Learning

* Flash programming concept
* Address checking
* Firmware data storage
* Memory boundaries

---

# 🔐 4. CRC-Based Firmware Validation

### Program

`bootloader_crc_validate.c`

CRC is used to detect errors or corruption in firmware data.

The program calculates a CRC32 value for the firmware image.

```text
Firmware Image
      ↓
   CRC32
      ↓
 CRC Value
```

During verification:

```text
Expected CRC
     ↓
   Compare
     ↑
Calculated CRC
```

If both values are equal:

```text
CRC MATCH
   ↓
Firmware Valid
```

If they are different:

```text
CRC MISMATCH
   ↓
Firmware Invalid
```

### Learning

* CRC32
* Firmware integrity
* Data corruption detection
* Firmware validation

> CRC detects accidental corruption, but CRC alone is not a security mechanism. Secure bootloaders normally use cryptographic authentication/signatures when firmware authenticity matters.

---

# 🚀 5. Application Jump

### Program

`bootloader_vector_relocate.c`

This program demonstrates the basic concept of transferring control from the bootloader to an application.

The program uses a function pointer:

```c
typedef void (*ApplicationFunction)(void);
```

The bootloader calls the application entry function.

```text
Bootloader
    ↓
Validate Application
    ↓
Application Entry
    ↓
Jump
    ↓
Application
```

### Important Note

AT89C51 does **not** have the STM32 `SCB->VTOR` register.

Therefore, this program demonstrates the **application jump concept** using a function pointer rather than performing actual STM32-style vector-table relocation.

### Learning

* Function pointers
* Application entry point
* Bootloader-to-application transition
* Vector-table concept

---

# 📡 6. UART Bootloader Protocol

### Program

`bootloader_uart_protocol.c`

UART can be used as a communication interface between a PC and the bootloader.

AT89C51 UART configuration:

```c
TMOD = 0x20;
TH1 = 0xFD;
SCON = 0x50;
TR1 = 1;
```

The program supports basic bootloader commands.

| Command |  Value | Purpose             |
| ------- | -----: | ------------------- |
| ERASE   | `0x01` | Erase application   |
| WRITE   | `0x02` | Write firmware      |
| VERIFY  | `0x03` | Verify firmware     |
| JUMP    | `0x04` | Jump to application |

Basic communication flow:

```text
PC
 |
 | UART Command
 ↓
AT89C51 Bootloader
 |
 +---- ERASE
 |
 +---- WRITE
 |
 +---- VERIFY
 |
 +---- JUMP
```

### Learning

* UART initialization
* UART transmit
* UART receive
* Command processing
* Bootloader communication
* Command-response protocol

---

# 🧪 7. Bootloader Simulation

### Program

`bootloader_sim.c`

This program simulates the complete bootloader process on a PC.

The simulation demonstrates:

```text
Bootloader Start
       ↓
Flash Erase
       ↓
Flash Write
       ↓
CRC Validation
       ↓
Application Valid?
     /       \
   YES        NO
    |          |
    ↓          ↓
  Jump       Reject
    |
    ↓
Application
```

The program demonstrates three situations:

### Case 1 – No Application

The bootloader checks the application and refuses to jump because valid firmware is not available.

### Case 2 – Valid Application

The application is programmed and its CRC is calculated.

```text
Flash
 ↓
Write
 ↓
CRC
 ↓
Verify
 ↓
Jump
```

### Case 3 – Corrupted Application

One byte of the application is intentionally modified.

```text
Valid Firmware
      ↓
Corrupt Data
      ↓
CRC Mismatch
      ↓
Jump Rejected
```

This demonstrates why firmware verification is important.

---

# ⚙️ 8. AT89C51 Bootloader Configuration

### Program

`bootloader_at89c51_config.c`

This program demonstrates basic AT89C51 configuration required for the bootloader concept.

### GPIO Configuration

```c
P1 = 0x00;
```

### UART Configuration

```c
TMOD = 0x20;
TH1 = 0xFD;
SCON = 0x50;
TR1 = 1;
```

For a typical **11.0592 MHz crystal**, this configuration is commonly used for **9600 baud UART communication**.

---

# 🔄 Complete Bootloader Flow

```text
                 RESET
                   |
                   ↓
          +----------------+
          |  Bootloader    |
          +----------------+
                   |
                   ↓
             UART Command
                   |
        +----------+----------+
        |          |          |
      ERASE      WRITE      VERIFY
        |          |          |
        +----------+----------+
                   |
                   ↓
               CRC Check
                   |
             +-----+-----+
             |           |
           PASS         FAIL
             |           |
             ↓           ↓
       Application    Stay in
          Jump        Bootloader
             |
             ↓
        Application
```

---

# 🛡️ Bootloader Safety Concepts

A reliable bootloader should:

* Protect the bootloader memory
* Validate application address
* Validate application size
* Verify firmware integrity
* Reject corrupted firmware
* Prevent jumping to invalid firmware
* Handle UART communication errors
* Provide a recovery mechanism

The basic safety rule is:

```text
             Firmware Valid?
                /       \
              YES        NO
               |          |
               ↓          ↓
             JUMP       REJECT
```

---

# 📁 Project Structure

```text
Day18_Bootloader/
│
├── bootloader_flash_erase.c
├── bootloader_flash_write.c
├── bootloader_crc_validate.c
├── bootloader_vector_relocate.c
├── bootloader_uart_protocol.c
├── bootloader_sim.c
├── bootloader_at89c51_config.c
└── README.md
```

---

# 🛠️ Tools & Technologies

* **C Programming**
* **Embedded C**
* **AT89C51 / 8051**
* **Keil µVision**
* **Proteus**
* **UART**
* **CRC32**
* **Git & GitHub**

---

# 🧠 Key Learning

| Topic               | What I Learned                            |
| ------------------- | ----------------------------------------- |
| Bootloader          | Firmware that runs before the application |
| Flash Erase         | Clearing application memory               |
| Flash Write         | Programming firmware data                 |
| CRC32               | Detecting firmware corruption             |
| Application Jump    | Transferring control to application       |
| Vector Table        | Understanding interrupt-vector concepts   |
| UART                | Communication with the bootloader         |
| Command Protocol    | Processing firmware commands              |
| Firmware Validation | Checking firmware integrity               |
| Safety              | Preventing invalid firmware execution     |

---

# 💡 Interview Questions

1. What is a bootloader?
2. Why is a bootloader required?
3. What is the difference between a bootloader and an application?
4. What is ISP?
5. What is IAP?
6. Why is CRC used in firmware updates?
7. What happens if firmware CRC verification fails?
8. Why should the bootloader region be protected?
9. What is the purpose of UART in a bootloader?
10. What is an application jump?
11. What is a vector table?
12. Does AT89C51 have an STM32-style VTOR register?
13. Why should firmware be verified before execution?
14. What happens when Flash is erased?
15. How can a bootloader prevent a corrupted firmware update?

---

# 🚀 Future Improvements

The next improvements for this project are:

1. Implement a complete UART firmware-transfer protocol.
2. Add application size validation.
3. Add bootloader memory protection.
4. Add firmware version checking.
5. Add CRC verification after programming.
6. Add UART timeout handling.
7. Add ACK/NACK response handling.
8. Simulate firmware update from a PC.
9. Port the bootloader concepts to STM32.
10. Implement actual STM32 Flash erase/write operations.
11. Implement proper vector-table relocation on STM32.
12. Explore fail-safe firmware updates and rollback.

---

# 📊 Day 18 Program Status

* ✅ `bootloader_flash_erase.c` – Flash erase operation
* ✅ `bootloader_flash_write.c` – Flash write operation
* ✅ `bootloader_crc_validate.c` – CRC-based image validation
* ✅ `bootloader_vector_relocate.c` – Application jump concept
* ✅ `bootloader_uart_protocol.c` – UART command-based bootloader
* ✅ `bootloader_sim.c` – Complete bootloader simulation
* ✅ `bootloader_at89c51_config.c` – AT89C51 configuration

---

## ✅ Day 18 Completed

**Day 18 – Bootloader Basics → ✅ Completed**

Today I learned the fundamentals of **Bootloader Development** and practiced **Flash erase, Flash write, CRC validation, application jumping, UART command processing, and bootloader simulation** using C and AT89C51 concepts.

This practice provides a foundation for implementing a **real firmware bootloader on modern microcontrollers such as STM32**.
