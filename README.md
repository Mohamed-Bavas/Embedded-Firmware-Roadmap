# 🚀 Embedded Firmware Roadmap

Welcome to my **Embedded Firmware Engineer Learning Journey**.

This repository documents my daily progress as I learn **Embedded C**, **Microcontrollers**, **Communication Protocols**, and **Firmware Development**. My goal is to build strong programming skills, create practical projects, and prepare for Embedded Firmware Engineer interviews.

---

# 🎯 Goals

* Build a strong foundation in C and Embedded C programming.
* Master memory management, bit manipulation, register-level programming, and GPIO programming.
* Understand 8051 and STM32 microcontroller architecture and peripherals.
* Learn embedded communication protocols (UART, SPI, I2C, CAN).
* Develop practical embedded firmware projects using Embedded C.
* Strengthen problem-solving and embedded interview skills.
* Maintain a consistent learning portfolio on GitHub.

---

# 🛠️ Technologies & Tools

* C Programming
* Embedded C
* 8051 Microcontroller
* STM32 Microcontroller
* VS Code
* STM32CubeIDE
* Keil μVision
* Proteus
* Git & GitHub

---

# 📅 Learning Roadmap

| Day    | Topic                               | Status |
| ------ | ----------------------------------- | :----: |
| Day 01 | C Programming Basics                |    ✅   |
| Day 02 | Pointers, Arrays & Strings          |    ✅   |
| Day 03 | Functions, Storage Classes & Memory |    ✅   |
| Day 04 | Structures, Unions & Enums          |    ✅   |
| Day 05 | File Handling & Preprocessor        |    ✅   |
| Day 06 | Bitwise Operators & Embedded C      |    ✅   |
| Day 07 | 8051 Microcontroller Basics         |    ✅   |
| Day 08 | GPIO Programming                    |    ✅   |
| Day 09 | Timers                              |    ✅   |
| Day 10 | Interrupts                          |    ✅   |
| Day 11 | UART                                |    ✅   |
| Day 12 | SPI                                 |    ✅   |
| Day 13 | I2C                                 |    ✅   |
| Day 14 | ADC & DAC                           |    ✅   |
| Day 15 | PWM                                 |    ⏳   |
| Day 16 | CAN Protocol                        |    ⏳   |
| Day 17 | Watchdog Timer                      |    ⏳   |
| Day 18 | Bootloader Basics                   |    ⏳   |
| Day 19 | RTOS Basics                         |    ⏳   |
| Day 20 | Mini Embedded Project               |    ⏳   |

---

# 📂 Repository Structure

```text
Embedded-Firmware-Roadmap/

├── README.md

├── Day01_C_Basics/
├── Day02_Pointers/
├── Day03_Functions_Memory/
├── Day04_Structures_Unions/
├── Day05_File_Handling/
├── Day06_Embedded_C/
├── Day07_8051_Basics/
├── Day08_GPIO/
├── Day09_Timers/
├── Day10_Interrupts/
├── Day11_UART/
├── Day12_SPI/
├── Day13_I2C/
├── Day14_ADC_DAC/
├── Day15_PWM/
├── Day16_CAN/
├── Day17_Watchdog/
├── Day18_Bootloader/
├── Day19_RTOS/
├── Day20_Mini_Project/

├── Interview_Programs/
├── Mini_Projects/
├── Notes/
└── Resources/
```

---

# 📚 Learning Resources

* Official C Programming Documentation
* Embedded C Tutorials
* 8051 Datasheets
* STM32 Reference Manuals
* STM32 HAL Documentation
* ARM Cortex-M Documentation

---

# 💻 What You'll Find

* ✅ C Programming Examples
* ✅ Embedded C Programs
* ✅ 8051 Firmware Examples
* ✅ STM32 Projects
* ✅ Communication Protocol Examples
* ✅ Interview-Oriented Programs
* ✅ Detailed Notes and Explanations
* ✅ Practical Mini Projects

---

# 🎯 Current Progress

* ✔️ Started my Embedded Firmware learning journey.
* ✔️ Completed Day 01 – C Programming Basics.
* ✔️ Completed Day 02 – Pointers, Arrays & Strings.
* ✔️ Completed Day 03 – Functions, Storage Classes & Memory.
* ✔️ Completed Day 04 – Structures, Unions & Enums.
* ✔️ Completed Day 05 – File Handling & Preprocessor.
* ✔️ Completed Day 06 – Bitwise Operators & Embedded C.
* ✔️ Completed Day 07 – 8051 Microcontroller Basics.
* ✔️ Completed Day 08 – GPIO Programming.
* ✔️ Completed Day 09 – Timers.
* ✔️ Completed Day 10 – Interrupts.
* ✔️ Completed Day 11 – UART Communication.
* ✔️ Completed Day 12 – SPI Communication.
* ✔️ Completed Day 13 – I2C Communication.
* ✔️ Completed Day 14 – ADC & DAC.
* 🔄 Next: **Day 15 – PWM**

---

# 🏆 Progress Tracker

**Completed:** **14 / 20 Days (70%)**

```text
████████████████████████████░░░░░░░░░░ 70%
```

---

# 📡 UART (Day 11)

## UART Fundamentals

* What is UART?
* Why UART is Used
* Features of UART
* Applications of UART

## Communication Basics

* Serial Communication
* Parallel Communication
* Asynchronous Communication
* Full Duplex Communication
* TX and RX Lines

## 8051 UART Hardware

* UART Serial Port
* TXD (P3.1)
* RXD (P3.0)

## UART Registers

* SCON Register
* SBUF Register
* TMOD Register
* TH1 Register
* PCON Register

## UART Modes

* Mode 0
* Mode 1 (8-bit UART)
* Mode 2
* Mode 3

## Baud Rate

* What is Baud Rate?
* Baud Rate Calculation
* Timer1 Mode 2
* TH1 Value Calculation
* Common Baud Rates

## UART Practice Programs

* uart_initialize.c
* uart_transmit_char.c
* uart_receive_char.c
* uart_send_string.c
* uart_echo.c
* uart_terminal_demo.c
* uart_receive_string.c
* uart_uppercase_converter.c
* uart_led_control.c
* uart_menu_program.c

## UART Applications

* PC Communication
* GPS Modules
* GSM Modules
* Bluetooth HC-05
* ESP8266 Wi-Fi Module
* Firmware Debugging
* Industrial Automation

---

# 🔌 SPI (Day 12)

## SPI Fundamentals

* What is SPI?
* Why SPI is Used
* Features of SPI
* Applications of SPI
* Advantages and Limitations of SPI

---

## SPI Communication Basics

* Synchronous Communication
* Master and Slave Architecture
* Full Duplex Communication
* Clock Synchronization
* Data Transfer Process

---

## SPI Communication Lines

| Signal | Full Form           | Function                  |
| ------ | ------------------- | ------------------------- |
| MOSI   | Master Out Slave In | Master sends data         |
| MISO   | Master In Slave Out | Slave sends data          |
| SCK    | Serial Clock        | Clock generated by master |
| SS/CS  | Slave Select        | Selects slave device      |

---

## SPI in 8051

* Classic 8051 does not have built-in SPI hardware.
* SPI is implemented using GPIO pins.
* Software SPI technique is used.
* Data transfer is controlled manually.

---

## SPI Pin Configuration

| 8051 Pin | SPI Function |
| -------- | ------------ |
| P1.0     | MOSI         |
| P1.1     | MISO         |
| P1.2     | SCK          |
| P1.3     | SS / CS      |

---

## SPI Programming

* SPI Initialization
* Master Transmission
* Slave Reception
* Master Reception
* String Transfer
* External Device Interface

---

## SPI Practice Programs

* spi_initialize.c
* spi_master_transmit.c
* spi_slave_receive.c
* spi_master_receive.c
* spi_send_string.c
* spi_receive_string.c
* spi_eeprom_interface.c
* spi_adc_interface.c
* spi_sensor_interface.c
* spi_display_interface.c

---

## SPI Applications

* EEPROM Interface
* Flash Memory
* SD Card Communication
* OLED Display
* TFT Display
* ADC/DAC Modules
* Sensors
* Industrial Controllers
* Automotive Electronics

---

# 🔗 I2C (Day 13)

## I2C Fundamentals

* What is I2C?
* Why I2C is Used
* Features of I2C
* Applications of I2C
* Advantages and Limitations of I2C

---

## I2C Communication Basics

* Synchronous, Two-Wire Communication
* Master and Slave Architecture
* Half Duplex Communication
* Open-Drain Configuration & Pull-Up Resistors
* START, STOP, and ACK/NACK Conditions
* 7-bit and 10-bit Addressing

---

## I2C Communication Lines

| Signal | Full Form    | Function                  |
| ------ | ------------ | ------------------------- |
| SDA    | Serial Data  | Bidirectional data line   |
| SCL    | Serial Clock | Clock generated by master |

---

## I2C in 8051

* Classic 8051 does not have built-in I2C hardware.
* I2C is implemented using GPIO pins.
* Software I2C (bit-banging) technique is used.
* Data transfer is controlled manually via bit-level timing.

---

## I2C Pin Configuration

| 8051 Pin | I2C Function |
| -------- | ------------ |
| P1.0     | SDA          |
| P1.1     | SCL          |

---

## I2C Programming

* I2C Initialization
* Start and Stop Condition Generation
* Master Transmit (Write)
* Master Receive (Read)
* Multi-Byte Data Transfer
* External Device Interface

---

## I2C Practice Programs

* i2c_initialize.c
* i2c_start_stop.c
* i2c_master_write.c
* i2c_master_read.c
* i2c_send_string.c
* i2c_receive_string.c
* i2c_eeprom_interface.c
* i2c_rtc_interface.c
* i2c_sensor_interface.c
* i2c_display_interface.c

---

## I2C Applications

* EEPROM Interface
* RTC Modules (DS1307/DS3231)
* Sensors (Temperature, Accelerometer, etc.)
* OLED Displays
* Port Expanders
* Multi-Device Bus Communication
* Industrial Controllers
* Consumer Electronics

---

# 📈 ADC & DAC (Day 14)

## ADC Fundamentals

* What is ADC (Analog-to-Digital Converter)?
* Why ADC is Needed in Embedded Systems
* Analog vs Digital Signals
* ADC Conversion Process
* ADC Resolution
* ADC Reference Voltage
* ADC Accuracy
* ADC Sampling
* Quantization
* ADC Applications

---

## ADC Working Principle

```text
Analog Input
     ↓
   Sampling
     ↓
 Quantization
     ↓
Digital Conversion
     ↓
Digital Output
```

---

## ADC Resolution

```text
Number of Levels = 2^n
```

Examples:

```text
8-bit ADC  → 256 levels
10-bit ADC → 1024 levels
12-bit ADC → 4096 levels
```

### ADC Digital Value

```text
Digital Value = (Analog Input × (2^n - 1)) / Reference Voltage
```

---

## DAC Fundamentals

* What is DAC (Digital-to-Analog Converter)?
* Why DAC is Used in Embedded Systems
* Digital vs Digital Signals
* DAC Conversion Process
* DAC Resolution
* DAC Reference Voltage
* DAC Accuracy
* DAC Applications

---

## DAC Working Principle

```text
Digital Input
     ↓
Digital-to-Analog Conversion
     ↓
Analog Output
```

---

## ADC vs DAC

| Feature      | ADC                         | DAC                         |
| ------------ | --------------------------- | --------------------------- |
| Full Form    | Analog-to-Digital Converter | Digital-to-Analog Converter |
| Input        | Analog                      | Digital                     |
| Output       | Digital                     | Analog                      |
| Main Purpose | Measures analog signals     | Generates analog signals    |
| Applications | Sensors, monitoring         | Audio, waveform generation  |

---

## ADC & DAC in 8051

* Classic 8051 microcontrollers generally do not contain an internal ADC or DAC.
* External ADC and DAC devices can be interfaced with the 8051.
* GPIO pins can be used for data transfer with external converter ICs.
* ADC allows analog sensors to be connected to digital processing systems.
* DAC allows the 8051 to generate analog output signals.

---

## ADC & DAC Practice Programs

* adc_initialize.c
* adc_read_channel.c
* adc_read_potentiometer.c
* adc_sensor_interface.c
* adc_voltage_monitor.c
* adc_multi_channel.c
* dac_initialize.c
* dac_generate_voltage.c
* dac_ramp_waveform.c
* dac_triangle_waveform.c
* adc_dac_interface.c

---

## ADC & DAC Applications

### ADC Applications

* Temperature Sensors
* Light Sensors
* Potentiometers
* Battery Voltage Monitoring
* Pressure Sensors
* Analog Joysticks
* Industrial Measurement Systems

### DAC Applications

* Audio Signal Generation
* Waveform Generation
* Signal Generation
* Function Generators
* Motor Control
* Industrial Control Systems

---

## Proteus Simulation

* Potentiometer to ADC
* Sensor to ADC
* ADC Value Display
* ADC-Based Voltage Measurement
* DAC Voltage Generation
* DAC Ramp Waveform
* ADC/DAC Interfacing with 8051

---

# 🚀 Upcoming Topics

* 🎚️ PWM
* 🚌 CAN Protocol
* 🛡️ Watchdog Timer
* 🚀 Bootloader Basics
* ⚡ RTOS Basics
* 🛠️ Mini Embedded Project

---

# 🤝 Connect With Me

I enjoy learning, building embedded systems, and sharing my progress.

If you have suggestions, feedback, or ideas for improvement, feel free to open an issue or connect with me on GitHub.

---

# ⭐ Support

If you find this repository helpful, consider giving it a ⭐ Star.

Your support motivates me to continue learning, building projects, and sharing my progress with the community.

---

# 📈 Learning Philosophy

> **"Consistency beats intensity."**

One day at a time.
One concept at a time.
One program at a time.
One project at a time.

---

# 🎯 Current Milestone

* ✅ **14 Days Completed**
* 📚 **140+ C & Embedded C Programs**
* 💻 **8051 Programming Completed**
* 🔌 **GPIO Programming Completed**
* ⏱️ **8051 Timers Completed**
* ⚡ **8051 Interrupts Completed**
* 📡 **8051 UART Communication Completed**
* 🔄 **SPI Communication Completed**
* 🔗 **I2C Communication Completed**
* 📈 **ADC & DAC Completed**
* 🚀 **Preparing for PWM**

---

# 🌟 Repository Highlights

* 📖 Well-structured learning roadmap
* 💻 140+ C and Embedded C programs
* 📚 Detailed notes with theory
* 🔬 8051 practical firmware examples
* 🛠️ Proteus simulation projects
* 🎯 Interview-oriented coding questions
* 🚀 Mini projects for hands-on practice
* 📈 Daily progress tracking

---

**Thank you for visiting my repository!**

⭐ **If you found this repository useful, don't forget to Star it!**

**Happy Coding! 🚀**
