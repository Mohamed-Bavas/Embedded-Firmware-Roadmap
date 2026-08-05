# 📘 Day 10 – 8051 Interrupt Programming

Welcome to **Day 10** of my **Embedded Firmware Engineer Roadmap**.

Today I learned about **Interrupts in the 8051 Microcontroller**, one of the most important concepts in embedded systems. Interrupts allow the microcontroller to respond immediately to external or internal events without continuously polling devices, making firmware more efficient and responsive.

---

# 🎯 Objective

* Understand the concept of interrupts.
* Learn the interrupt architecture of the 8051.
* Study interrupt registers and vector addresses.
* Configure external, timer, and serial interrupts.
* Write Embedded C programs using Interrupt Service Routines (ISR).
* Build a foundation for real-time embedded firmware development.

---

# 📚 Topics Covered

* ✅ Introduction to Interrupts
* ✅ Why Interrupts are Used
* ✅ Polling vs Interrupt
* ✅ Interrupt Flow
* ✅ Types of 8051 Interrupts
* ✅ External Interrupt (INT0 & INT1)
* ✅ Timer Interrupt (Timer0 & Timer1)
* ✅ Serial Interrupt
* ✅ Interrupt Vector Addresses
* ✅ IE (Interrupt Enable) Register
* ✅ IP (Interrupt Priority) Register
* ✅ TCON Register
* ✅ Edge Triggered Interrupt
* ✅ Level Triggered Interrupt
* ✅ Interrupt Service Routine (ISR)
* ✅ Interrupt Priority
* ✅ Interrupt Programming Steps
* ✅ Applications of Interrupts

---

# 💻 Practice Programs

| No. | Program                      |
| --- | ---------------------------- |
| 1   | external_interrupt_led.c     |
| 2   | external_interrupt_counter.c |
| 3   | timer0_interrupt_blink.c     |
| 4   | timer1_interrupt_blink.c     |
| 5   | serial_interrupt_demo.c      |
| 6   | interrupt_priority_demo.c    |
| 7   | nested_interrupt_demo.c      |
| 8   | interrupt_toggle_led.c       |
| 9   | external_interrupt_switch.c  |
| 10  | interrupt_stopwatch.c        |

---

# 🛠️ Tools Used

* Keil μVision
* Proteus Professional
* AT89C51 / AT89S52 Microcontroller
* Embedded C
* Git
* GitHub

---

# ▶️ How to Compile

```bash
Build the project using Keil μVision.
```

---

# ▶️ How to Simulate

1. Compile the project in **Keil μVision**.
2. Generate the **HEX** file.
3. Open the circuit in **Proteus**.
4. Load the generated HEX file into the 8051.
5. Run the simulation and observe the interrupt operation.

---

# 📖 Key Learnings

* Learned how interrupts improve CPU efficiency compared to polling.
* Understood the five interrupt sources available in the standard 8051.
* Learned the purpose of the **IE**, **IP**, and **TCON** registers.
* Configured External Interrupts (INT0 and INT1).
* Implemented Timer0 and Timer1 interrupt programs.
* Learned the difference between **edge-triggered** and **level-triggered** interrupts.
* Wrote Interrupt Service Routines (ISRs) in Embedded C.
* Understood interrupt priority and nested interrupt concepts.
* Built interrupt-based applications such as LED control, counters, and stopwatches.
* Strengthened the foundation for real-time embedded firmware development.

---

# 📁 Folder Structure

```text
Day10_Interrupts/
│── README.md
│── external_interrupt_led.c
│── external_interrupt_counter.c
│── timer0_interrupt_blink.c
│── timer1_interrupt_blink.c
│── serial_interrupt_demo.c
│── interrupt_priority_demo.c
│── nested_interrupt_demo.c
│── interrupt_toggle_led.c
│── external_interrupt_switch.c
└── interrupt_stopwatch.c
```

---

# 🎯 Interview Topics Covered

* What is an Interrupt?
* Polling vs Interrupt
* Types of Interrupts
* 8051 Interrupt Sources
* Interrupt Vector Addresses
* IE Register
* IP Register
* TCON Register
* ISR (Interrupt Service Routine)
* Edge vs Level Triggering
* Interrupt Priority
* External Interrupt Programming
* Timer Interrupt Programming
* Serial Interrupt Programming

---

# 🚀 Next Goal

➡️ **Day 11 – UART (Serial Communication)**

Topics include:

* UART Basics
* Serial Communication
* SBUF Register
* SCON Register
* Baud Rate Calculation
* Timer1 for Baud Rate Generation
* Serial Transmission
* Serial Reception
* Proteus Virtual Terminal
* UART Programming in Embedded C

---

# 📈 Learning Journey

I am documenting my daily progress as I work toward becoming an **Embedded Firmware Engineer**.

Every day includes:

* 📖 Theory Notes
* 💻 Embedded C Programs
* 🛠️ Proteus Simulations
* 🎯 Interview Questions
* 📚 Practical Examples

Feel free to explore the programs, provide feedback, or suggest improvements.

⭐ **If you find this repository helpful, consider giving it a Star!**

---

## 🏆 Day 10 Achievement

* ✅ Learned the fundamentals of 8051 Interrupts.
* ✅ Implemented 10 interrupt-based Embedded C programs.
* ✅ Understood interrupt registers and vector addresses.
* ✅ Practiced External, Timer, and Serial Interrupts.
* ✅ Improved real-time programming skills for embedded firmware.

---

**#EmbeddedSystems #EmbeddedC #8051 #Interrupts #Firmware #FirmwareEngineer #Microcontroller #Keil #Proteus #LearningJourney #GitHub #Programming #EmbeddedProgramming**
