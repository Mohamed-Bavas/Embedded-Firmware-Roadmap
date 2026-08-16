# 📈 Day 14 – ADC & DAC

Welcome to **Day 14** of my **Embedded Firmware Engineer Learning Journey**.

Today, I learned **ADC (Analog-to-Digital Converter)** and **DAC (Digital-to-Analog Converter)**, which are important interfaces for connecting embedded systems with the real-world analog environment.

ADC converts analog signals from sensors such as temperature sensors, LDRs, potentiometers, and other transducers into digital values that a microcontroller can process.

DAC performs the reverse operation by converting digital data from a microcontroller into an analog signal that can be used for waveform generation, audio, control systems, and other applications.

---

## 📚 Topics Covered

### 🔹 ADC Fundamentals

* What is ADC?
* Why ADC is required in Embedded Systems
* Analog vs Digital Signals
* ADC Resolution
* 8-bit, 10-bit, and 12-bit ADC
* Reference Voltage (Vref)
* Sampling Rate
* Conversion Time
* Quantization
* Quantization Error
* ADC Step Size

### 🔹 ADC Working Principle

* Sample and Hold
* Successive Approximation Register (SAR) ADC
* Flash ADC – Basic Overview
* Analog Input Sampling
* Digital Code Generation
* ADC Conversion Process

### 🔹 ADC Step Size

For an **n-bit ADC**:

```text
Step Size = Vref / 2^n
```

For example, for an 8-bit ADC with 5V reference:

```text
Step Size = 5 / 256
         ≈ 19.53 mV
```

---

## 🔌 ADC in Microcontrollers

### 8051

The standard **8051 microcontroller does not contain a built-in ADC**.

Therefore, an external ADC such as:

* ADC0804
* ADC0808

can be interfaced with the 8051.

### STM32

Modern STM32 microcontrollers commonly provide built-in ADC peripherals, including **12-bit SAR ADCs** on many devices.

Important concepts include:

* ADC Channels
* Channel Selection
* Single Conversion Mode
* Continuous Conversion Mode
* ADC Resolution
* Reference Voltage

---

# 🔧 ADC0808 Interfacing with 8051

ADC0808 provides **8 analog input channels**, selected using the address lines **A, B, and C**.

### Important Control Signals

* ALE – Address Latch Enable
* START – Starts ADC conversion
* EOC – End of Conversion
* OE – Output Enable
* CLK – ADC clock
* D0–D7 – 8-bit digital output

### Basic Conversion Sequence

```text
Select Channel
      ↓
Generate ALE Pulse
      ↓
Generate START Pulse
      ↓
Wait for EOC
      ↓
Enable OE
      ↓
Read D0–D7
      ↓
Disable OE
```

---

## 🔌 ADC0808 with 8051 – Connections

| ADC0808 | 8051           | Function             |
| ------- | -------------- | -------------------- |
| D0–D7   | P0             | 8-bit Data Bus       |
| ALE     | P2.0           | Address Latch Enable |
| START   | P2.1           | Start Conversion     |
| EOC     | P2.2           | End of Conversion    |
| OE      | P2.3           | Output Enable        |
| A       | P2.4           | Channel Select Bit   |
| B       | P2.5           | Channel Select Bit   |
| C       | P2.6           | Channel Select Bit   |
| CLK     | External Clock | ADC Clock            |

> ⚠️ **8051 Port 0 is open-drain**, so external pull-up resistors are normally required when using P0 as a data bus.

---

# 🎚️ DAC Fundamentals

### What is DAC?

**DAC (Digital-to-Analog Converter)** converts a digital binary value into a corresponding analog voltage or current.

```text
Digital Data
     ↓
    DAC
     ↓
Analog Output
```

### Why DAC is Required

DACs are used in:

* Audio signal generation
* Waveform generation
* Motor control
* Signal conditioning
* Function generators
* Analog actuator control

---

## 📐 DAC Concepts

* DAC Resolution
* Reference Voltage
* Step Size
* Settling Time
* Digital Input
* Analog Output

Higher resolution provides smaller output steps and better output precision.

---

# 🔬 DAC Working Principle

### R-2R Ladder DAC

An R-2R ladder uses only two resistor values:

```text
R and 2R
```

The binary input controls switches in the resistor network and produces a proportional analog output.

### Weighted Resistor DAC

Each digital bit is connected through a resistor with a different weight.

The MSB has the highest contribution, while the LSB has the smallest contribution.

---

# 🔌 DAC0808 Interfacing with 8051

DAC0808 is an **8-bit current-output DAC**.

The digital data from the 8051 is applied to the DAC input pins.

The DAC produces a current output which must be converted into a voltage using an **op-amp I-to-V converter**.

```text
8051
  │
  │ 8-bit Digital Data
  ↓
DAC0808
  │
  │ Current Output
  ↓
Op-Amp I-to-V Converter
  │
  ↓
Analog Voltage
```

> ⚠️ **DAC0808 provides current output, not direct voltage output. An external op-amp based current-to-voltage converter is required to obtain a measurable analog voltage.**

---

# 💻 Practice Programs

## ADC Programs

| #  | Program                     | Description                                        |
| -- | --------------------------- | -------------------------------------------------- |
| 01 | `adc_initialize.c`          | Initializes ADC0808 control signals and data bus   |
| 02 | `adc_single_channel_read.c` | Reads analog value from a single ADC channel       |
| 03 | `adc_multi_channel_read.c`  | Reads analog values from multiple ADC0808 channels |
| 04 | `adc_temperature_sensor.c`  | Reads temperature using an LM35 sensor             |
| 05 | `adc_potentiometer_read.c`  | Reads variable voltage from a potentiometer        |
| 06 | `adc_light_sensor_ldr.c`    | Reads LDR sensor value and controls an output      |
| 07 | `adc_to_uart_display.c`     | Sends ADC value to a PC terminal through UART      |
| 08 | `adc_threshold_alert.c`     | Generates an LED/buzzer alert above a threshold    |

## DAC Programs

| #  | Program                         | Description                                             |
| -- | ------------------------------- | ------------------------------------------------------- |
| 01 | `dac_initialize.c`              | Initializes the digital output port for DAC interfacing |
| 02 | `dac_generate_ramp_wave.c`      | Generates a ramp/sawtooth waveform                      |
| 03 | `dac_generate_triangle_wave.c`  | Generates a triangle waveform                           |
| 04 | `dac_generate_sine_wave.c`      | Generates a sine waveform using a lookup table          |
| 05 | `dac_variable_voltage_output.c` | Generates adjustable analog output using push buttons   |

---

# 📂 Folder Structure

```text
Day14_ADC_DAC/
│
├── README.md
│
├── ADC/
│   ├── adc_initialize.c
│   ├── adc_single_channel_read.c
│   ├── adc_multi_channel_read.c
│   ├── adc_temperature_sensor.c
│   ├── adc_potentiometer_read.c
│   ├── adc_light_sensor_ldr.c
│   ├── adc_to_uart_display.c
│   └── adc_threshold_alert.c
│
└── DAC/
    ├── dac_initialize.c
    ├── dac_generate_ramp_wave.c
    ├── dac_generate_triangle_wave.c
    ├── dac_generate_sine_wave.c
    └── dac_variable_voltage_output.c


```

---

# 🎯 Applications

### ADC Applications

* 🌡️ Temperature Measurement
* 💡 Light Intensity Measurement
* 🔋 Battery Voltage Monitoring
* 🎮 Joystick Input
* 🎛️ Potentiometer Reading
* 🔊 Sound Level Measurement
* 🏭 Industrial Sensor Interfacing

### DAC Applications

* 🎵 Audio Signal Generation
* 📈 Waveform Generation
* ⚙️ Motor Control
* 🔊 Signal Generation
* 🔧 Signal Conditioning
* 🤖 Analog Actuator Control

---

# 🧪 Practical Learning

During Day 14, I practiced:

* Interfacing ADC0808 with 8051
* Reading analog sensor values
* Selecting ADC channels
* Understanding ADC conversion timing
* Converting ADC output into usable digital data
* Interfacing DAC0808 with 8051
* Generating ramp, triangle, and sine waveforms
* Understanding DAC current-to-voltage conversion

---

# ✅ Day 14 Checklist

* [x] ADC Fundamentals
* [x] ADC Resolution and Step Size
* [x] ADC Working Principle
* [x] ADC0808 Interfacing
* [x] ADC Sensor Interfacing
* [x] ADC Practice Programs – 8/8
* [x] DAC Fundamentals
* [x] R-2R Ladder Concept
* [x] DAC0808 Interfacing
* [x] DAC Waveform Generation
* [x] DAC Practice Programs – 5/5

---

# 🏆 Day 14 Milestone

* 📚 **13 ADC & DAC Programs Added**
* 🔌 **ADC0808 Interfacing Practiced**
* 🎚️ **DAC0808 Interfacing Practiced**
* 📈 **Analog-to-Digital Conversion Understood**
* 📉 **Digital-to-Analog Conversion Understood**
* ⚙️ **Waveform Generation Implemented**

---

# 🚀 Learning Progress

**Day 14 – ADC & DAC Completed ✔️**

Today I strengthened my understanding of how embedded systems interact with the **analog world** using ADC and DAC techniques.

### Next Topic

**Day 15 – PWM (Pulse Width Modulation)**

> *Consistency beats intensity. Keep learning, keep building, and keep improving.* 🚀

---

⭐ Part of my **Embedded Firmware Engineer Learning Journey** and **Embedded Firmware Roadmap**.
