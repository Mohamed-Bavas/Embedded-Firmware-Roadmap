# 📘 Day 06 – Bitwise Operators & Embedded C

Welcome to **Day 06** of my **Embedded Firmware Engineer Roadmap**.

Today I learned **Bitwise Operators** and the fundamentals of **Embedded C Programming**. These concepts are essential for firmware development because embedded systems interact directly with hardware registers using bit-level operations.

---

## 🎯 Goal

- Understand binary and hexadecimal number systems.
- Learn all bitwise operators in C.
- Perform bit manipulation using masks.
- Understand the basics of Embedded C programming.
- Learn the importance of `volatile` and `const`.
- Understand register-level programming.
- Learn memory-mapped I/O concepts.
- Build a strong foundation for GPIO programming on microcontrollers.

---

## 📚 Topics Covered

- ✅ Binary Number System
- ✅ Hexadecimal Number System
- ✅ Bitwise AND (`&`)
- ✅ Bitwise OR (`|`)
- ✅ Bitwise XOR (`^`)
- ✅ Bitwise NOT (`~`)
- ✅ Left Shift (`<<`)
- ✅ Right Shift (`>>`)
- ✅ Setting a Bit
- ✅ Clearing a Bit
- ✅ Toggling a Bit
- ✅ Checking a Bit
- ✅ Bit Masks
- ✅ Introduction to Embedded C
- ✅ Difference Between C and Embedded C
- ✅ `volatile` Keyword
- ✅ `const` Keyword
- ✅ Register-Level Programming
- ✅ Memory-Mapped I/O
- ✅ Embedded Coding Best Practices

---

## 💻 Programs

| No. | Program |
|-----|---------|
| 1 | bitwise_and.c |
| 2 | bitwise_or.c |
| 3 | bitwise_xor.c |
| 4 | bitwise_not.c |
| 5 | left_shift.c |
| 6 | right_shift.c |
| 7 | set_clear_toggle_bit.c |
| 8 | check_bit.c |
| 9 | volatile_demo.c |
| 10 | const_demo.c |

---

## 🛠️ Tools Used

- Visual Studio Code
- GCC (MinGW)
- Git
- GitHub

---

## ▶️ How to Compile

```bash
gcc bitwise_and.c -o bitwise_and
```

## ▶️ How to Run

### Windows (PowerShell)

```powershell
.\bitwise_and.exe
```

### Windows (Command Prompt)

```cmd
bitwise_and.exe
```

---

## 📖 Key Learnings

- Learned how data is represented in binary and hexadecimal.
- Understood how bitwise operators manipulate individual bits.
- Practiced setting, clearing, toggling, and checking bits using bit masks.
- Learned why bitwise operations are essential for hardware control in embedded systems.
- Understood the difference between standard C and Embedded C.
- Learned the importance of the `volatile` keyword for hardware registers and interrupts.
- Used the `const` keyword to create read-only variables.
- Explored register-level programming and memory-mapped I/O concepts.
- Built a stronger foundation for programming microcontrollers such as the 8051 and STM32.

---

## 📂 Folder Structure

```text
Day06_Embedded_C/
│── README.md
│── bitwise_and.c
│── bitwise_or.c
│── bitwise_xor.c
│── bitwise_not.c
│── left_shift.c
│── right_shift.c
│── set_clear_toggle_bit.c
│── check_bit.c
│── volatile_demo.c
└── const_demo.c
```

---

## 🔧 Embedded Firmware Relevance

Bitwise operations and Embedded C concepts are fundamental in firmware development because they allow direct control of hardware.

Applications include:

- Controlling GPIO pins
- Configuring UART, SPI, and I2C peripherals
- Enabling and disabling interrupts
- Setting timer and ADC registers
- Register-level programming
- Memory optimization
- Efficient hardware communication

These concepts are used daily by Embedded Firmware Engineers.

---

## 🎯 Next Goal

➡️ **Day 07 – 8051 Microcontroller Basics**

Upcoming topics:

- Introduction to Embedded Systems
- 8051 Architecture
- Pin Diagram
- Memory Organization
- Special Function Registers (SFRs)
- Ports (P0, P1, P2, P3)
- Clock and Reset Circuit
- Machine Cycle
- Instruction Cycle
- Keil µVision Setup
- Proteus Simulation
- LED Blink Program

---

## 🚀 Learning Journey

I am documenting my daily progress as I work toward becoming an **Embedded Firmware Engineer**.

Feel free to explore the programs, provide feedback, or suggest improvements.

⭐ If you find this repository helpful, consider giving it a star!

#EmbeddedC #BitwiseOperators #EmbeddedSystems #Firmware #8051 #STM32 #RegisterProgramming #Microcontrollers #GitHub #LearningJourney
