# 🚀 Day 19 – RTOS Basics

Welcome to **Day 19** of my **Embedded Firmware Engineer Learning Journey**.

Today, I learned the fundamentals of **Real-Time Operating System (RTOS) concepts** and practiced them using **C programming and AT89C51 (8051) microcontroller concepts**.

An RTOS is a small kernel that manages multiple independent **tasks** by deciding which one runs, when, and for how long, based on priority and timing requirements.

> ⚠️ **Note:** AT89C51 has no MMU and only 128 bytes of internal RAM, so it cannot perform a true hardware context switch like STM32 + FreeRTOS. Task scheduling, semaphores, and mutexes are demonstrated here using a **lightweight cooperative scheduler** in Keil C51.

---

## 📚 Topics Covered

* RTOS Basics – Tasks, Task States, Scheduler, RTOS Tick
* Cooperative & Priority-Based Scheduling
* Queues for Inter-Task Communication
* Binary Semaphores for ISR-to-Task Signaling
* Mutexes for Shared Resource Protection
* Priority Inversion & Priority Inheritance (concept)
* Stack Overflow Detection
* AT89C51 Timer0, UART & External Interrupt Configuration

---

## 🔄 RTOS Flow

```text
              MCU RESET
                  |
                  ▼
          +---------------+
          |  Timer0 Tick  |
          +---------------+
                  |
                  ▼
          +---------------+
          |   Scheduler   |
          +---------------+
                  |
        Pick highest-priority
           ready task
                  |
                  ▼
            Run Task
                  |
                  ▼
        Repeat Scheduler Loop
```

---

## 💻 Practice Programs

| # | Program | Description |
|---|---|---|
| 01 | `rtos_task_create.c` | Cooperative round-robin scheduler with multiple tasks |
| 02 | `rtos_task_priority.c` | Priority-based task scheduling |
| 03 | `rtos_queue_demo.c` | Producer–consumer using a circular buffer queue |
| 04 | `rtos_semaphore_isr.c` | ISR-to-task signaling with a binary semaphore |
| 05 | `rtos_mutex_shared_resource.c` | Protecting shared UART access with a mutex |
| 06 | `rtos_stack_overflow_hook.c` | Stack pointer monitoring & overflow detection |
| 07 | `rtos_led_button_demo_at89c51.c` | Combined LED + button + UART multitasking demo |

---

## 📂 Folder Structure

```text
Day19_RTOS/
│
├── README.md
├── rtos_task_create.c
├── rtos_task_priority.c
├── rtos_queue_demo.c
├── rtos_semaphore_isr.c
├── rtos_mutex_shared_resource.c
├── rtos_stack_overflow_hook.c
└── rtos_led_button_demo_at89c51.c
```

---

## 🛠️ Tools & Technologies

C Programming | Embedded C | AT89C51 / 8051 | Keil µVision | Proteus | UART | Cooperative Scheduling | Git & GitHub

---

## 🧠 Important RTOS Terms

| Term | Meaning |
|---|---|
| Task | An independent unit of work managed by the scheduler |
| Scheduler | Decides which task runs and when |
| Tick | Periodic timer interrupt driving scheduling decisions |
| Queue | Structure used to pass data between tasks |
| Semaphore | Signaling mechanism for events |
| Mutex | Lock used to protect a shared resource |
| Priority Inversion | Low-priority task blocking a high-priority task via a resource |
| Stack Overflow | Task exceeds its allocated stack space |

---

## 🎯 Key Takeaways

* An RTOS splits firmware into independent tasks instead of one big super-loop
* A scheduler decides which task runs, based on priority and timing
* Queues, semaphores, and mutexes let tasks safely share data and resources
* Priority inversion can block high-priority tasks — priority inheritance fixes it
* Task stacks are limited resources and must be monitored to avoid overflow
* AT89C51's limited RAM means real preemption needs a proper MCU like STM32 + FreeRTOS

---

## ✅ Day 19 Completed

```text
TASK CREATE → SCHEDULE → COMMUNICATE (QUEUE/SEMAPHORE) → PROTECT (MUTEX) → MONITOR (STACK)
```

This gives me a strong foundation for moving from **8051 cooperative-scheduler concepts to real FreeRTOS development on STM32**.

### Next Topic
**Day 20 – Mini Embedded Project 🛠️**

> *Consistency beats intensity. Keep learning, keep building, and keep improving.* 🚀

---

⭐ Part of my **Embedded Firmware Engineer Learning Journey** and **Embedded Firmware Roadmap**.
