# 🎚️ Day 15 – PWM (Pulse Width Modulation)

Part of my **Embedded Firmware Roadmap** — documenting my daily progress learning Embedded C and Microcontrollers.

---

## 📖 Topics Covered

### PWM Fundamentals
- What is PWM?
- Why PWM is Used
- Features of PWM
- Applications of PWM

### PWM Basics
- Duty Cycle
- Period and Frequency
- Average Voltage / Power
- Types of PWM (Analog vs Digital)

### PWM Generation Methods
- Timer-Based PWM (Software)
- Hardware PWM (STM32-style)

### PWM in 8051
- No dedicated PWM peripheral
- Software PWM using Timer0/Timer1
- Manual GPIO toggling with calculated ON/OFF delay

### PWM in STM32
- Dedicated PWM Timer Channels
- PWM Mode 1 / PWM Mode 2
- Key Registers: ARR, CCR, PSC, CR1

### PWM Programming Concepts
- PWM Initialization
- Setting PWM Frequency
- Setting/Varying Duty Cycle
- LED Brightness Control
- DC Motor Speed Control
- Servo Motor Angle Control
- Multiple PWM Channels

---

## 💻 Practice Programs

| File | Description |
|------|-------------|
| `pwm_initialize.c` | Initializes software-based PWM output pin |
| `pwm_generate_signal.c` | Generates a basic PWM signal with fixed 50% duty cycle |
| `pwm_vary_duty_cycle.c` | Varies duty cycle from 0% to 100% and back |
| `pwm_led_brightness_control.c` | Controls LED brightness with a fade in/out effect |
| `pwm_dc_motor_speed_control.c` | Controls DC motor speed (low/medium/high) via PWM |
| `pwm_servo_motor_control.c` | Controls servo motor angle (0°–180°) using PWM pulses |
| `pwm_fan_speed_control.c` | Controls fan speed with 3 preset levels via push buttons |
| `pwm_potentiometer_controlled.c` | Reads potentiometer via ADC and maps it to PWM duty cycle |

---

## 🔌 Hardware Connections (8051)

| Signal | 8051 Pin | Function |
|--------|----------|----------|
| PWM Output | P1.0 | Software-generated PWM signal |
| Motor Direction | P1.1 | H-Bridge direction control (optional) |
| Speed UP Button | P3.0 | Increase speed level (active low) |
| Speed DOWN Button | P3.1 | Decrease speed level (active low) |
| ADC Data Bus | P0 | Potentiometer reading via ADC0808 |
| ADC Control (ALE/START/EOC/OE) | P2.0–P2.3 | ADC0808 control lines |

---

## 📐 Key Formulas

**Duty Cycle**
```
Duty Cycle (%) = (Ton / T) × 100
```

**Period & Frequency**
```
T = Ton + Toff
Frequency (Hz) = 1 / T
```

**Average Output Voltage**
```
Vavg = Duty Cycle × Vsupply
```

**Servo Pulse Width (Standard 20ms period)**
| Angle | Pulse Width |
|-------|-------------|
| 0° | ~1.0 ms |
| 90° | ~1.5 ms |
| 180° | ~2.0 ms |

---

## 📂 Folder Structure

```text
Day15_PWM/
├── README.md
├── pwm_initialize.c
├── pwm_generate_signal.c
├── pwm_vary_duty_cycle.c
├── pwm_led_brightness_control.c
├── pwm_dc_motor_speed_control.c
├── pwm_servo_motor_control.c
├── pwm_fan_speed_control.c
└── pwm_potentiometer_controlled.c

```

---

## 🎯 Applications

- LED Dimming / Brightness Control
- DC Motor Speed Control
- Servo Motor Angle Control
- Fan Speed Regulation
- Power Converters (Buck/Boost)
- Audio Amplification (Class D)
- Heater / Temperature Control Systems

---

## ⚖️ PWM vs DAC

| Feature | PWM | DAC |
|---------|-----|-----|
| Output Type | Digital (switched) | True Analog |
| Hardware Needed | Timer + GPIO | Dedicated DAC IC/peripheral |
| Smoothing | Needs filter for true analog | Native analog output |
| Common Use | Motor/LED control | Audio/waveform generation |
| Cost/Complexity | Simple, low-cost | More complex hardware |

---

## ✅ Status

- [x] PWM Theory
- [x] PWM Practice Programs (8/8)

**Day 15 Complete ✔️**
**Next:** Day 16 – CAN Protocol

---

## 🏆 Milestone

- 📚 **8 Programs Added**
- 🎚️ **Software PWM Generation Mastered (8051)**
- 💡 **LED, Motor & Servo Control via PWM Completed**
- 🎛️ **Analog-Style Control using Digital Signals Understood**

---

⭐ Part of the [Embedded Firmware Roadmap](../README.md) — *Consistency beats intensity.*
