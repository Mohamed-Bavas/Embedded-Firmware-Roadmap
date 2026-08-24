# 🛡️ Day 17 – Watchdog Timer (WDT)

Welcome to **Day 17** of my **Embedded Firmware Engineer Learning Journey**.

Today, I learned **Watchdog Timer (WDT)**, an important reliability and fault-recovery mechanism used in embedded systems.

A Watchdog Timer continuously monitors firmware execution. The application must periodically refresh or feed the Watchdog before its timeout period expires. If the firmware becomes stuck, enters an infinite loop, crashes, or fails to refresh the Watchdog, the timer expires and can automatically reset the microcontroller.

Watchdog Timers are widely used in **automotive ECUs, industrial controllers, IoT devices, robotics, medical systems, and safety-critical embedded applications**.

---

## 📚 Topics Covered

### 🔹 Watchdog Timer Fundamentals

* What is a Watchdog Timer?
* Why Watchdog Timer is required in Embedded Systems
* Watchdog Timer working principle
* Watchdog Counter
* Watchdog Timeout
* Watchdog Reset
* Watchdog Refresh / Feed / Kick
* Hardware Watchdog vs Software Watchdog
* Applications of Watchdog Timer

### 🔹 Watchdog Timer Operation

* Watchdog Initialization
* Watchdog Start
* Watchdog Counter
* Watchdog Refresh
* Watchdog Timeout
* Automatic System Reset
* Firmware Recovery

### 🔹 Watchdog Timer Flow

```text
Initialize Watchdog
        ↓
Start Watchdog
        ↓
Run Application
        ↓
Feed / Refresh WDT
        ↓
Continue Application
        ↓
       ┌───────────────┐
       │               │
 Firmware OK      Firmware Hang
       │               │
       ↓               ↓
 Refresh WDT      No Refresh
                       ↓
                 WDT Timeout
                       ↓
                  MCU Reset
                       ↓
                Firmware Restart
```

---

# ⚙️ Watchdog Timer Working Principle

A Watchdog Timer contains a counter that runs continuously using its configured clock source.

The firmware must periodically refresh the Watchdog before the counter reaches its timeout value.

### Normal Operation

```text
Start WDT
   ↓
Execute Firmware
   ↓
Feed WDT
   ↓
Execute Firmware
   ↓
Feed WDT
   ↓
Continue Execution
```

### Fault Condition

```text
Firmware Running
       ↓
Firmware Gets Stuck
       ↓
No WDT Feed
       ↓
Counter Continues
       ↓
Timeout
       ↓
Watchdog Reset
       ↓
System Restart
```

---

# 🔄 Watchdog Feed / Refresh

**Watchdog Feed**, **Refresh**, or **Kick** means resetting the Watchdog counter before the timeout occurs.

The firmware should perform this operation periodically when the monitored system is operating correctly.

```text
Application Task
       ↓
Check System Status
       ↓
Feed Watchdog
       ↓
Continue Execution
```

A Watchdog should not simply be refreshed blindly. In a robust firmware design, the Watchdog should only be fed when the required system tasks are operating correctly.

---

# ⏱️ Watchdog Timeout

The **Watchdog Timeout** is the amount of time available for the firmware to refresh the Watchdog before a reset is generated.

```text
Watchdog Started
       ↓
Counter Running
       ↓
Refresh WDT
       ↓
Counter Reset
       ↓
Counter Running Again
```

If the firmware stops refreshing:

```text
No Refresh
    ↓
Counter Continues
    ↓
Timeout Reached
    ↓
Watchdog Reset
```

The actual timeout depends on the Watchdog clock source, prescaler, reload/counter value, and microcontroller architecture.

---

# 🔧 Watchdog Timer Configuration

Typical Watchdog configuration includes:

* Watchdog clock source
* Prescaler
* Counter / reload value
* Timeout period
* Watchdog enable
* Watchdog start
* Watchdog refresh
* Reset configuration

---

# 🔌 Watchdog Timer in STM32

STM32 microcontrollers commonly provide two Watchdog peripherals:

* **IWDG – Independent Watchdog**
* **WWDG – Window Watchdog**

```text
                 STM32
                   │
          ┌────────┴────────┐
          │                 │
        IWDG              WWDG
          │                 │
 Independent Clock      Window Timing
          │                 │
          └────────┬────────┘
                   ↓
             Fault Recovery
```

---

## 🔹 IWDG – Independent Watchdog

The **Independent Watchdog (IWDG)** is designed for reliable system monitoring and uses an independent clock source.

### Important Concepts

* Independent clock
* Prescaler
* Reload value
* Watchdog start
* Counter refresh
* Timeout
* Automatic reset

The IWDG is particularly useful when robust recovery from firmware failures is required.

---

## 🔹 WWDG – Window Watchdog

The **Window Watchdog (WWDG)** requires the Watchdog to be refreshed within a specific timing window.

Refreshing outside the allowed window can result in a reset.

```text
Invalid        Valid Refresh Window        Invalid
   │                    │                     │
───┼────────────────────┼─────────────────────┼───
                        ↑
                     Refresh
```

### Important Concepts

* Prescaler
* Counter
* Window value
* Refresh timing
* Early refresh detection
* Late refresh detection
* Watchdog reset

---

# 🔍 Watchdog Reset Cause Detection

After a system reset, firmware can check reset-status flags to determine whether the previous reset was caused by the Watchdog.

```text
System Reset
      ↓
Check Reset Cause
      ↓
┌─────┴─────┐
│           │
WDT Reset   Other Reset
│           │
↓           ↓
Analyze     Analyze
Failure     Reset Source
```

This is useful for:

* Debugging
* Fault analysis
* System diagnostics
* Failure logging
* Reliability monitoring

---

# 💻 Practice Programs

The following programs were practiced during **Day 17**:

| #  | Program                          | Description                                          |
| -- | -------------------------------- | ---------------------------------------------------- |
| 01 | `wdt_initialize.c`               | Initializes and configures the Watchdog Timer        |
| 02 | `wdt_feed_basic.c`               | Demonstrates basic Watchdog feed / refresh operation |
| 03 | `wdt_timeout_reset_demo.c`       | Demonstrates Watchdog timeout and automatic reset    |
| 04 | `wdt_stm32_iwdg_config.c`        | Configures the STM32 Independent Watchdog (IWDG)     |
| 05 | `wdt_stm32_wwdg_config.c`        | Configures the STM32 Window Watchdog (WWDG)          |
| 06 | `wdt_reset_cause_detection.c`    | Detects and identifies Watchdog reset cause          |
| 07 | `wdt_hang_recovery_simulation.c` | Simulates firmware hang and Watchdog-based recovery  |

---

# 📂 Folder Structure

```text
Day17_Watchdog/
│
├── README.md
│
├── wdt_initialize.c
├── wdt_feed_basic.c
├── wdt_timeout_reset_demo.c
├── wdt_stm32_iwdg_config.c
├── wdt_stm32_wwdg_config.c
├── wdt_reset_cause_detection.c
└── wdt_hang_recovery_simulation.c
```

---

# 🎯 Applications

### Watchdog Timer Applications

* 🚗 Automotive ECU Systems
* 🏭 Industrial Automation
* 🤖 Robotics
* 📡 IoT Devices
* 🏥 Medical Equipment
* ⚙️ Motor Controllers
* 🚀 Aerospace Systems
* 🔌 Embedded Control Systems
* 🛡️ Safety-Critical Systems
* 🏠 Consumer Electronics

---

# ⚖️ IWDG vs WWDG

| Feature                 | IWDG                     | WWDG                     |
| ----------------------- | ------------------------ | ------------------------ |
| Full Name               | Independent Watchdog     | Window Watchdog          |
| Clock                   | Independent clock source | Peripheral/system clock  |
| Refresh                 | Before timeout           | Within valid window      |
| Early Refresh Detection | No                       | Yes                      |
| Late Refresh Detection  | Yes                      | Yes                      |
| Main Purpose            | Robust fault recovery    | Timing-window monitoring |
| STM32 Availability      | Common                   | Common                   |

---

# 🧪 Practical Learning

During Day 17, I practiced:

* Initializing the Watchdog Timer
* Starting and configuring the WDT
* Feeding / refreshing the Watchdog
* Understanding Watchdog timeout
* Demonstrating automatic system reset
* Configuring STM32 IWDG
* Configuring STM32 WWDG
* Detecting Watchdog reset causes
* Simulating firmware hang conditions
* Understanding automatic firmware recovery

---

# ✅ Day 17 Checklist

* [x] Watchdog Timer Fundamentals
* [x] Watchdog Working Principle
* [x] Watchdog Initialization
* [x] Watchdog Feed / Refresh
* [x] Watchdog Timeout
* [x] Watchdog Reset
* [x] STM32 IWDG Configuration
* [x] STM32 WWDG Configuration
* [x] Watchdog Reset Cause Detection
* [x] Firmware Hang Recovery
* [x] Watchdog Practice Programs – 7/7

---

# 🏆 Day 17 Milestone

* 🛡️ **Watchdog Timer Fundamentals Completed**
* ⚙️ **WDT Initialization Implemented**
* 🔄 **Watchdog Feed / Refresh Implemented**
* ⏱️ **Watchdog Timeout & Reset Demonstrated**
* 🔧 **STM32 IWDG Configuration Practiced**
* 🔧 **STM32 WWDG Configuration Practiced**
* 🔍 **Watchdog Reset Cause Detection Practiced**
* 🛠️ **Firmware Hang Recovery Simulation Practiced**
* 💻 **7 Watchdog Timer Programs Added**

---

# 🚀 Learning Progress

**Day 17 – Watchdog Timer Completed ✔️**

Today I strengthened my understanding of how Watchdog Timers improve **firmware reliability, system stability, and automatic fault recovery**.

I also practiced both **basic Watchdog concepts and STM32-specific IWDG/WWDG configuration**, along with reset-cause detection and firmware hang recovery.

### Next Topic

**Day 18 – Bootloader Basics**

> *Consistency beats intensity. Keep learning, keep building, and keep improving.* 🚀

---

⭐ Part of my **Embedded Firmware Engineer Learning Journey** and **Embedded Firmware Roadmap**.
