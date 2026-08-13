# 📈 Day 14 – ADC & DAC

Part of my **Embedded Firmware Roadmap** — documenting my daily progress learning Embedded C and Microcontrollers.

---

## 📖 Topics Covered

### ADC Fundamentals
- What is ADC (Analog-to-Digital Converter)?
- Why ADC is Needed in Embedded Systems
- Analog vs Digital Signals
- Resolution (8-bit, 10-bit, 12-bit)
- Reference Voltage (Vref)
- Sampling Rate & Conversion Time

### ADC Working Principle
- Successive Approximation Register (SAR) Method
- Flash ADC (brief overview)
- Sample and Hold Circuit
- Quantization and Quantization Error
- Step Size Calculation (Vref / 2^n)

### ADC in Microcontrollers
- 8051 (no built-in ADC — external ADC0808/ADC0804 used)
- STM32 (built-in 12-bit SAR ADC)
- ADC Channels and Multiplexing
- Single Conversion vs Continuous Conversion Mode

### ADC0808/ADC0804 Interfacing (8051)
- Pin Configuration (START, EOC, ALE, OE, CLK)
- Control Signal Timing
- Reading Digital Output
- 8-channel Multiplexed Input (ADC0808)

### DAC Fundamentals
- What is DAC (Digital-to-Analog Converter)?
- Why DAC is Needed
- Resolution and Step Size
- Settling Time

### DAC Working Principle
- R-2R Ladder Network
- Weighted Resistor Method
- Binary Input to Analog Output Conversion

### DAC0808 Interfacing (8051)
- Pin Configuration
- Current Output to Voltage Conversion (Op-Amp)
- Generating Waveforms (Sine, Triangle, Sawtooth)

---

## 💻 Practice Programs

### ADC Programs
| File | Description |
|------|-------------|
| `adc_initialize.c` | Initializes ADC0808 control lines and data bus |
| `adc_single_channel_read.c` | Reads analog value from a single channel (IN0) |
| `adc_multi_channel_read.c` | Reads analog values from multiple channels (IN0–IN3) |
| `adc_temperature_sensor.c` | Reads temperature using LM35 sensor via ADC |
| `adc_potentiometer_read.c` | Reads variable voltage from a potentiometer |
| `adc_light_sensor_ldr.c` | Reads light intensity using LDR and controls a light |
| `adc_to_uart_display.c` | Reads ADC value and sends it to PC terminal via UART |
| `adc_threshold_alert.c` | Triggers buzzer/LED alert when ADC value exceeds threshold |

### DAC Programs
| File | Description |
|------|-------------|
| `dac_initialize.c` | Initializes DAC0808 digital output port |
| `dac_generate_ramp_wave.c` | Generates a ramp (sawtooth) waveform |
| `dac_generate_triangle_wave.c` | Generates a triangle waveform |
| `dac_generate_sine_wave.c` | Generates a sine waveform using a lookup table |
| `dac_variable_voltage_output.c` | Outputs adjustable analog voltage via push buttons |

---

## 🔌 Hardware Connections

### ADC0808 with 8051
| ADC0808 Pin | 8051 Pin | Function |
|-------------|----------|----------|
| D0–D7 | P0 | Data Bus |
| ALE | P2.0 | Address Latch Enable |
| START | P2.1 | Start Conversion |
| EOC | P2.2 | End of Conversion |
| OE | P2.3 | Output Enable |
| ADD A/B/C | P2.4–P2.6 | Channel Select |

### DAC0808 with 8051
| DAC0808 Pin | 8051 Pin | Function |
|-------------|----------|----------|
| D0–D7 | P1 | Digital Input |
| Iout | Op-Amp Input | Current output (converted to voltage externally) |
| VREF+/VREF− | Reference Voltage | Sets output voltage range |

> ⚠️ DAC0808 is a **current-output** DAC. An op-amp based I-to-V converter circuit is required externally to obtain a measurable analog voltage on an oscilloscope.

---

## 📂 Folder Structure

```text
Day14_ADC_DAC/
├── README.md
├── ADC/
│   ├── adc_initialize.c
│   ├── adc_single_channel_read.c
│   ├── adc_multi_channel_read.c
│   ├── adc_temperature_sensor.c
│   ├── adc_potentiometer_read.c
│   ├── adc_light_sensor_ldr.c
│   ├── adc_to_uart_display.c
│   └── adc_threshold_alert.c
├── DAC/
│   ├── dac_initialize.c
│   ├── dac_generate_ramp_wave.c
│   ├── dac_generate_triangle_wave.c
│   ├── dac_generate_sine_wave.c
│   └── dac_variable_voltage_output.c
└── Notes/
    └── ADC_DAC_Theory.md
```

---

## 🎯 Applications

**ADC:** Temperature Sensing, Light Intensity Measurement, Battery Voltage Monitoring, Joystick/Potentiometer Input, Sound Level Detection, Industrial Sensor Interfacing

**DAC:** Audio Signal Generation, Waveform Generators, Motor Speed Control, Signal Conditioning, Analog Output for Actuators

---

## ✅ Status

- [x] ADC Theory
- [x] ADC Practice Programs (8/8)
- [x] DAC Theory
- [x] DAC Practice Programs (5/5)

**Day 14 Complete ✔️**
**Next:** Day 15 – PWM

---

## 🏆 Milestone

- 📚 **13 Programs Added** (8 ADC + 5 DAC)
- 🔌 **ADC0808 Interfacing Mastered**
- 🎚️ **DAC0808 Waveform Generation Mastered**
- 📈 **Analog I/O with 8051 Completed**

---

⭐ Part of the [Embedded Firmware Roadmap](../README.md) — *Consistency beats intensity.*
