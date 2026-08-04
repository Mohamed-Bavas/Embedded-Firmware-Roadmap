# 📘 Day 09 – 8051 Timers

Welcome to **Day 09** of my **Embedded Firmware Engineer Roadmap**.

Today I learned about **8051 Timers**, one of the most important peripherals in microcontrollers. Timers are used to generate accurate delays, measure time intervals, count external events, and control peripherals. Understanding timers is essential before learning **Interrupts**, **UART**, and other communication protocols.

---

# 🎯 Objective

- Understand the working principle of 8051 Timers.
- Learn the difference between Timers and Counters.
- Understand all timer operating modes.
- Generate accurate delays using hardware timers.
- Learn timer overflow polling.
- Build timer-based Embedded C applications.

---

# 📚 Topics Covered

## Part 1 – Introduction to Timers

- What is a Timer?
- Why Timers are used
- Timer vs Software Delay
- Applications of Timers

---

## Part 2 – Timer vs Counter

- Timer Mode
- Counter Mode
- Internal Clock
- External Clock
- Difference between Timer and Counter

---

## Part 3 – 8051 Timers

### Timer 0

- Features
- Registers
- Applications

### Timer 1

- Features
- Registers
- Applications

---

## Part 4 – Timer Registers

### TMOD Register

- Timer Mode Register
- Gate Bit
- C/T Bit
- M1 M0 Bits

### TCON Register

- TF0
- TR0
- TF1
- TR1

### TH0 & TL0

### TH1 & TL1

---

## Part 5 – Timer Modes

### Mode 0

- 13-bit Timer

### Mode 1

- 16-bit Timer

### Mode 2

- 8-bit Auto Reload

### Mode 3

- Split Timer Mode

---

## Part 6 – Timer Programming

- Timer Initialization
- Loading THx & TLx
- Starting Timer
- Polling Overflow Flag
- Clearing Overflow Flag
- Reloading Timer

---

## Part 7 – Delay Calculation

- Machine Cycle
- Crystal Frequency
- Timer Tick
- Delay Formula
- THx/TLx Calculation

---

## Part 8 – Timer Applications

- LED Blinking
- Time Delay
- Square Wave Generation
- Stopwatch
- Digital Clock
- Frequency Measurement

---

# 💻 Practice Programs

| No. | Program |
|-----|---------|
| 1 | timer0_delay.c |
| 2 | timer1_delay.c |
| 3 | led_blink_timer0.c |
| 4 | led_toggle_timer1.c |
| 5 | timer_mode0_demo.c |
| 6 | timer_mode1_demo.c |
| 7 | timer_mode2_demo.c |
| 8 | timer_overflow_polling.c |
| 9 | square_wave_generator.c |
| 10 | stopwatch_timer.c |

---

# 🛠️ Tools Used

- Keil μVision
- Proteus Professional
- AT89C51 / AT89S52
- Embedded C
- Git
- GitHub

---

# ▶️ How to Build

Compile the program using **Keil μVision**.

Generate the HEX file.

Load the HEX file into **Proteus** and simulate the circuit.

---

# 📖 Key Learnings

- Understood the difference between Timers and Counters.
- Learned the purpose of Timer0 and Timer1.
- Configured TMOD and TCON registers.
- Explored all four timer operating modes.
- Learned to generate precise hardware delays.
- Practiced timer overflow polling.
- Calculated THx and TLx values for different delays.
- Generated square waves using timers.
- Built timer-based applications like LED blinking and stopwatch.

---

# 📁 Folder Structure

```text
Day09_Timers/
│── README.md
│── timer0_delay.c
│── timer1_delay.c
│── led_blink_timer0.c
│── led_toggle_timer1.c
│── timer_mode0_demo.c
│── timer_mode1_demo.c
│── timer_mode2_demo.c
│── timer_overflow_polling.c
│── square_wave_generator.c
└── stopwatch_timer.c
```

---

# 🎯 Next Goal

➡️ **Day 10 – 8051 Interrupt Programming**

Upcoming Topics:

- Introduction to Interrupts
- Interrupt Sources
- IE Register
- IP Register
- Interrupt Priority
- External Interrupts
- Timer Interrupts
- Interrupt Service Routine (ISR)

---

# 🚀 Learning Journey

I am documenting my daily progress as I work toward becoming an **Embedded Firmware Engineer**.

Each day includes:

- 📖 Theory Notes
- 💻 Embedded C Programs
- 🛠️ Proteus Simulations
- 📚 Interview Questions
- 📝 Explanations

Feel free to explore the programs, provide feedback, or suggest improvements.

⭐ If you find this repository helpful, consider giving it a star!

---

## 📊 Day 09 Summary

- ✅ Learned 8051 Timer Architecture
- ✅ Understood TMOD & TCON Registers
- ✅ Practiced Timer Modes (0, 1 & 2)
- ✅ Generated Accurate Delays
- ✅ Implemented Timer Overflow Polling
- ✅ Created Timer-Based Embedded C Programs

---

### 🚀 Progress

**Completed:** **9 / 20 Days (45%)**

```text
██████████████████░░ 45%
```

---

**#EmbeddedSystems #EmbeddedC #8051 #Timers #Firmware #Microcontroller #LearningJourney #GitHub #Keil #Proteus**
