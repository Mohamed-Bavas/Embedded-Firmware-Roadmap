# 🛡️ Day 17 – Watchdog Timer (WDT)

Welcome to **Day 17** of my **Embedded Firmware Engineer Learning Journey**.

Today, I learned about the **Watchdog Timer (WDT)**, an important hardware safety mechanism used in embedded systems to automatically recover a microcontroller when the firmware becomes **stuck, unresponsive, or enters an unexpected state**.

A Watchdog Timer works like a countdown timer. The firmware must periodically **refresh, feed, or service** the watchdog before the timeout expires. If the firmware fails to refresh it within the required time, the watchdog can trigger a **system reset**.

Watchdog timers are widely used in **automotive systems, industrial controllers, medical devices, IoT devices, robotics, and other unattended embedded systems** where reliable operation is important.

---

## 📚 Topics Covered

### 🔹 Watchdog Timer Fundamentals

* What is a Watchdog Timer?
* Why WDT is required in Embedded Systems
* Watchdog Timer working principle
* Watchdog timeout period
* Watchdog counter
* Feeding / Kicking / Servicing the watchdog
* Watchdog reset
* Watchdog interrupt
* Watchdog reset vs Power-On Reset

### 🔹 Types of Watchdog Timers

* Independent Watchdog (IWDG)
* Window Watchdog (WWDG)
* Hardware Watchdog
* Software Watchdog
* Timeout-based watchdog operation

### 🔹 Watchdog Timer Operation

* Watchdog counter
* Prescaler
* Reload value
* Timeout calculation
* Refresh operation
* Timeout condition
* Automatic system reset

---

# 🛡️ What is a Watchdog Timer?

A **Watchdog Timer (WDT)** is a timer designed to monitor the health of embedded firmware.

The application periodically refreshes the watchdog:

```text
Start Watchdog
      ↓
Run Application
      ↓
Refresh Watchdog
      ↓
Continue Running
      ↓
Refresh Watchdog
      ↓
Continue Running
```

If the firmware gets stuck:

```text
Start Watchdog
      ↓
Run Application
      ↓
Firmware Hangs
      ↓
No Watchdog Refresh
      ↓
Timeout
      ↓
System Reset
      ↓
Firmware Restarts
```

The main purpose of a watchdog is:

> **Automatically recover the system when software stops operating correctly.**

---

# ⚙️ Watchdog Timer Working Principle

A watchdog contains a counter that continuously counts toward a timeout condition.

The firmware must periodically reload or refresh the counter.

### Healthy System

```text
Watchdog Counter
      ↓
Count
      ↓
Refresh
      ↓
Counter Restart
      ↓
Count
      ↓
Refresh
      ↓
Continue
```

### Faulty System

```text
Watchdog Counter
      ↓
Count
      ↓
Firmware Hang
      ↓
No Refresh
      ↓
Timeout
      ↓
MCU Reset
```

---

# 🔄 Watchdog Feeding / Refreshing

The process of resetting the watchdog counter is commonly called:

* Feeding the watchdog
* Kicking the watchdog
* Servicing the watchdog
* Refreshing the watchdog

Example:

```c
Watchdog_Refresh();
```

The refresh operation tells the watchdog:

> "The firmware is still operating correctly."

---

# ⏱️ Watchdog Timeout

The watchdog timeout determines how long the firmware can run without refreshing the watchdog.

For example:

```text
Watchdog Timeout = 1 second
```

If the firmware does not refresh the watchdog within that period:

```text
1 second elapsed
      ↓
Watchdog Timeout
      ↓
MCU Reset
```

The timeout should be selected carefully.

### Timeout Too Short

```text
False Watchdog Reset
```

The system may reset even though the firmware is operating normally.

### Timeout Too Long

```text
Slow Fault Recovery
```

The system may remain stuck for too long before recovery.

---

# 🧮 Watchdog Timeout Configuration

The watchdog timeout is generally determined by factors such as:

* Clock frequency
* Prescaler
* Counter/reload value

A simplified relationship is:

```text
Timeout ≈ Counter Period × Prescaler
```

The exact formula depends on the specific microcontroller and watchdog peripheral.

---

# 🔐 Types of Watchdog Timers

## 1. Independent Watchdog (IWDG)

An **Independent Watchdog** normally uses a clock source that is independent of the main system clock.

In many STM32 devices, the IWDG is clocked from the internal **LSI oscillator**.

```text
LSI Clock
    ↓
IWDG
    ↓
Counter
    ↓
Timeout
    ↓
System Reset
```

### Advantages

* Independent from the main CPU clock
* Useful for recovering from clock or software problems
* Simple timeout-based supervision
* Suitable for reliable fault recovery

---

# 🪟 2. Window Watchdog (WWDG)

A **Window Watchdog** requires the watchdog to be refreshed within a specific time window.

The firmware must not refresh:

* Too early
* Too late

```text
       Valid Refresh Window
              ↓
     ┌──────────────────┐
─────┤                  ├─────
Early      Refresh      Late
Reset       OK          Reset
```

This helps detect software that is running incorrectly even if it is still periodically executing.

---

# ⚖️ IWDG vs WWDG

| Feature                 | IWDG                            | WWDG                             |
| ----------------------- | ------------------------------- | -------------------------------- |
| Full Name               | Independent Watchdog            | Window Watchdog                  |
| Clock                   | Independent clock source        | Peripheral/system clock domain   |
| Refresh                 | Before timeout                  | Within allowed window            |
| Early Refresh Detection | Generally No                    | Yes                              |
| Late Refresh Detection  | Yes                             | Yes                              |
| Main Purpose            | Recovery from software failures | Detect abnormal execution timing |
| Typical STM32 Use       | Reliable system recovery        | More precise software monitoring |

---

# 🔌 Watchdog Timer in 8051

The watchdog implementation depends on the particular **8051 derivative**.

Many classic 8051 variants do not provide a dedicated watchdog peripheral.

For such devices, watchdog-like behavior can be implemented using:

* Timer 0
* Timer 1
* Timer interrupts
* Software timeout monitoring

Example concept:

```text
Timer
  ↓
Periodic Interrupt
  ↓
Check System Activity
  ↓
System Healthy?
  ├── Yes → Continue
  └── No  → Reset System
```

However, many modern 8051-compatible microcontrollers include a **dedicated hardware watchdog**, so the specific datasheet should always be checked.

---

# 🔧 Watchdog Timer in STM32

STM32 microcontrollers commonly provide watchdog peripherals such as:

* **IWDG – Independent Watchdog**
* **WWDG – Window Watchdog**

The exact availability and implementation depend on the STM32 family.

---

## STM32 IWDG

Important IWDG registers commonly include:

```text
IWDG->KR
IWDG->PR
IWDG->RLR
IWDG->SR
```

### Key Registers

| Register    | Purpose                                     |
| ----------- | ------------------------------------------- |
| `IWDG->KR`  | Key register / watchdog control and refresh |
| `IWDG->PR`  | Prescaler configuration                     |
| `IWDG->RLR` | Reload value                                |
| `IWDG->SR`  | Status information                          |

Typical HAL functions include:

```c
HAL_IWDG_Init();
HAL_IWDG_Refresh();
```

---

# 🪟 STM32 WWDG

The Window Watchdog can be configured using STM32 HAL functions such as:

```c
HAL_WWDG_Init();
HAL_WWDG_Refresh();
```

The WWDG monitors whether the firmware refreshes the watchdog within the configured timing window.

---

# 🔁 Watchdog Reset Sequence

A typical watchdog recovery sequence is:

```text
Firmware Starts
      ↓
Initialize WDT
      ↓
Run Main Application
      ↓
Refresh WDT
      ↓
Application Continues
      ↓
Firmware Failure
      ↓
No Refresh
      ↓
WDT Timeout
      ↓
MCU Reset
      ↓
Firmware Starts Again
```

---

# 🔍 Watchdog Reset vs Power-On Reset

Embedded systems often need to determine **why the MCU restarted**.

Possible reset causes include:

* Power-On Reset
* External Reset
* Software Reset
* Watchdog Reset
* Brownout Reset

The microcontroller usually provides reset-status information through dedicated registers.

The firmware can use this information for:

* Debugging
* Fault diagnosis
* Event logging
* Reliability monitoring

---

# 🧠 Watchdog Design Considerations

A watchdog should not simply be refreshed blindly.

### 1. Choose the Correct Timeout

The timeout should be:

```text
Long enough → Avoid false resets
Short enough → Recover quickly from faults
```

### 2. Refresh at the Correct Location

A common approach is to refresh the watchdog only after important parts of the system have successfully executed.

```text
Task A
 ↓
Task B
 ↓
Task C
 ↓
System Healthy
 ↓
Refresh Watchdog
```

### 3. Avoid Blind ISR Refreshing

Refreshing the watchdog inside an interrupt that continues running even when the main application is stuck can hide software failures.

Bad design:

```text
Timer ISR
   ↓
Refresh WDT
   ↓
Main Application Hangs
   ↓
WDT Never Resets
```

Better approach:

```text
Main Application
      ↓
Check System Health
      ↓
Refresh WDT
```

---

# 💻 Practice Programs

## Watchdog Timer Programs

| #  | Program                          | Description                                   |
| -- | -------------------------------- | --------------------------------------------- |
| 01 | `wdt_initialize.c`               | Initializes the watchdog timer                |
| 02 | `wdt_feed_basic.c`               | Demonstrates periodic watchdog refresh        |
| 03 | `wdt_timeout_reset_demo.c`       | Demonstrates automatic reset after timeout    |
| 04 | `wdt_stm32_iwdg_config.c`        | Configures STM32 Independent Watchdog         |
| 05 | `wdt_stm32_wwdg_config.c`        | Configures STM32 Window Watchdog              |
| 06 | `wdt_reset_cause_detection.c`    | Detects watchdog and other reset causes       |
| 07 | `wdt_hang_recovery_simulation.c` | Simulates firmware hang and watchdog recovery |

---

# 📂 Folder Structure

```text
Day17_Watchdog/
│
├── README.md
├── wdt_initialize.c
├── wdt_feed_basic.c
├── wdt_timeout_reset_demo.c
├── wdt_stm32_iwdg_config.c
├── wdt_stm32_wwdg_config.c
├── wdt_reset_cause_detection.c
├── wdt_hang_recovery_simulation.c
└── Proteus_Simulations/
```

---

# 🧪 Proteus Simulation Ideas

### Watchdog Timeout Demonstration

```text
MCU
 ↓
Start WDT
 ↓
Normal Operation
 ↓
No Refresh
 ↓
Timeout
 ↓
MCU Reset
```

### Healthy Main Loop

```text
Main Loop
   ↓
Execute Tasks
   ↓
Check System Health
   ↓
Refresh WDT
   ↓
Repeat
```

### Firmware Hang Simulation

```text
Normal Operation
      ↓
Firmware Hang
      ↓
Infinite Loop
      ↓
No WDT Refresh
      ↓
Watchdog Timeout
      ↓
MCU Reset
```

### Reset Cause Indicator

```text
MCU Reset
    ↓
Check Reset Status
    ↓
┌───────────────┐
│ Watchdog Reset│ → LED Indicator
└───────────────┘
```

---

# 🎯 Applications

### Watchdog Timer Applications

* 🚗 Automotive ECUs
* 🏭 Industrial Controllers
* 🤖 Robotics
* 🏥 Medical Devices
* 📡 IoT Devices
* 🔋 Battery Management Systems
* 🛡️ Safety-Critical Systems
* 🏢 Building Automation
* 🚜 Agricultural Machinery
* ⚙️ Industrial Embedded Systems

---

# ⚖️ Watchdog Timer vs Normal Timer

| Feature              | Watchdog Timer          | Normal Timer                    |
| -------------------- | ----------------------- | ------------------------------- |
| Main Purpose         | Fault recovery          | Timing/events                   |
| Timeout Action       | Usually reset/interrupt | Interrupt/event                 |
| Firmware Monitoring  | Yes                     | Not necessarily                 |
| Used for Reliability | High                    | General purpose                 |
| Typical Application  | System recovery         | Delays, scheduling, measurement |

---

# 🧠 Important Watchdog Terms

| Term           | Meaning                                     |
| -------------- | ------------------------------------------- |
| WDT            | Watchdog Timer                              |
| IWDG           | Independent Watchdog                        |
| WWDG           | Window Watchdog                             |
| Timeout        | Maximum allowed time before watchdog action |
| Refresh        | Reloads/resets watchdog counter             |
| Feed           | Another term for refreshing watchdog        |
| Prescaler      | Divides watchdog clock                      |
| Reload Value   | Counter value used for timeout              |
| Reset Cause    | Reason why the MCU restarted                |
| Fault Recovery | Automatic recovery from firmware failure    |

---

# 🧪 Practical Learning

During Day 17, I practiced:

* Understanding Watchdog Timer fundamentals
* Learning why watchdog timers are important
* Understanding watchdog timeout operation
* Learning watchdog feeding and refreshing
* Understanding IWDG and WWDG
* Understanding watchdog prescaler and reload concepts
* Learning watchdog reset behavior
* Understanding watchdog reset cause detection
* Studying watchdog implementation on 8051-based systems
* Understanding STM32 IWDG
* Understanding STM32 WWDG
* Learning proper watchdog refresh strategies
* Understanding firmware hang recovery
* Exploring Watchdog Timer simulation concepts

---

# ✅ Day 17 Checklist

* [x] Watchdog Timer Fundamentals
* [x] Watchdog Working Principle
* [x] Watchdog Timeout Concepts
* [x] Feeding / Refreshing the Watchdog
* [x] Independent Watchdog (IWDG)
* [x] Window Watchdog (WWDG)
* [x] Watchdog Reset
* [x] Reset Cause Detection
* [x] 8051 Watchdog Concepts
* [x] STM32 IWDG Concepts
* [x] STM32 WWDG Concepts
* [x] Watchdog Design Considerations
* [x] Firmware Hang Recovery
* [x] Watchdog Practice Programs – 7/7

---

# 🏆 Day 17 Milestone

* 📚 **Watchdog Timer Fundamentals Completed**
* 🛡️ **Firmware Fault Recovery Understood**
* ⏱️ **Watchdog Timeout & Refresh Concepts Learned**
* 🔄 **IWDG & WWDG Concepts Understood**
* 🔧 **STM32 Watchdog Configuration Studied**
* 💻 **8051 Watchdog Implementation Concepts Learned**
* 🔍 **Reset Cause Detection Understood**
* 🧪 **Watchdog Recovery Simulation Practiced**

---

# 🚀 Learning Progress

**Day 17 – Watchdog Timer Completed ✔️**

Today I strengthened my understanding of how **Watchdog Timers improve embedded system reliability** by automatically recovering the microcontroller when firmware becomes stuck or unresponsive.

I learned how watchdog timers monitor software execution, how the firmware periodically refreshes the watchdog, and how a timeout can trigger an automatic system reset.

I also learned the difference between **Independent Watchdog (IWDG)** and **Window Watchdog (WWDG)** and how watchdog mechanisms are implemented in embedded platforms such as **8051 and STM32**.

### Next Topic

**Day 18 – RTOS Fundamentals ⚙️**

> *Consistency beats intensity. Keep learning, keep building, and keep improving.* 🚀

---

⭐ Part of my **Embedded Firmware Engineer Learning Journey** and **Embedded Firmware Roadmap**.
