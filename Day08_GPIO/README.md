# 📘 Day 08 – GPIO Programming (8051)

Welcome to **Day 08** of my **Embedded Firmware Engineer Roadmap**.

Today I learned how to program the **General Purpose Input/Output (GPIO)** ports of the **8051 Microcontroller**. GPIO enables the microcontroller to communicate with external hardware such as LEDs, switches, sensors, buzzers, and displays. Through hands-on programming and simulation, I explored both digital input and output operations using Embedded C.

---

# 🎯 Objective

- Understand the fundamentals of GPIO.
- Learn the GPIO architecture of the 8051.
- Configure GPIO ports as input and output.
- Interface LEDs and push buttons.
- Perform bit-level GPIO operations.
- Build practical GPIO applications using Embedded C.

---

# 📚 Topics Covered

## Part 1 – Introduction to GPIO

- What is GPIO?
- Digital Input
- Digital Output
- Input vs Output
- Importance of GPIO in Embedded Systems

---

## Part 2 – 8051 GPIO Ports

- Port 0
- Port 1
- Port 2
- Port 3

---

## Part 3 – Port Characteristics

- Port 0 (Open Drain)
- External Pull-up Resistor
- Port 1 Internal Pull-up
- Port 2 Internal Pull-up
- Port 3 Alternate Functions

---

## Part 4 – GPIO Register Programming

- P0 Register
- P1 Register
- P2 Register
- P3 Register

Reading GPIO

```c
if(P1 & 0x01)
{
    // Switch Pressed
}
```

Writing GPIO

```c
P2 = 0xFF;
```

---

## Part 5 – LED Interfacing

- LED Connection
- Current Limiting Resistor
- Active HIGH LEDs
- Active LOW LEDs

---

## Part 6 – Switch Interfacing

- Push Button
- Pull-up Resistor
- Switch Debouncing
- Reading Switch Status

---

## Part 7 – Delay

- Software Delay
- Nested Loop Delay

---

## Part 8 – Proteus Simulation

- Creating Project
- Adding AT89C51
- Connecting LEDs
- Connecting Push Buttons
- Loading HEX File
- Running Simulation

---

# 💻 Practice Programs

| No. | Program | Description |
|-----|---------|-------------|
| 1 | button_counter.c | Increment a counter each time a button is pressed. |
| 2 | button_toggle_led.c | Toggle an LED with each button press. |
| 3 | port_test.c | Test all four GPIO ports by outputting different patterns. |
| 4 | walking_one.c | Display a walking '1' bit across LEDs. |
| 5 | walking_zero.c | Display a walking '0' bit across LEDs. |
| 6 | led_bar_graph.c | Create a bar graph effect using LEDs. |
| 7 | knight_rider_led.c | Implement the "Knight Rider" LED scanning effect. |
| 8 | port_output_demo.c | Demonstrate writing various values to a GPIO port. |
| 9 | port_input_demo.c | Read the status of input pins and process the data. |
| 10 | gpio_test_program.c | Comprehensive GPIO test covering both input and output operations. |

---

# 🛠️ Tools Used

- Embedded C
- Keil μVision
- Proteus Professional
- AT89C51 Microcontroller
- VS Code
- Git
- GitHub

---

# ▶️ How to Compile

```text
1. Open the project in Keil μVision.
2. Build the project.
3. Generate the HEX file.
```

---

# ▶️ How to Simulate

1. Open Proteus.
2. Place the AT89C51 microcontroller.
3. Connect LEDs and push buttons.
4. Load the generated HEX file.
5. Run the simulation.

---

# 📖 Key Learnings

- Learned how GPIO enables communication between the microcontroller and external hardware.
- Understood the difference between GPIO input and output operations.
- Explored the characteristics of all four GPIO ports of the 8051.
- Learned why Port 0 requires an external pull-up resistor.
- Practiced button-controlled applications such as LED toggling and event counting.
- Implemented multiple LED patterns including Walking One, Walking Zero, Bar Graph, and Knight Rider effects.
- Tested all GPIO ports using different output patterns.
- Learned how to read digital inputs and mirror them to output ports.
- Built a comprehensive GPIO test application combining both input and output operations.
- Strengthened my understanding of bitwise operations for efficient GPIO programming.
- Simulated all programs successfully using Keil μVision and Proteus.

---

# 📂 Folder Structure

```text
Day08_GPIO/
│── README.md
│── button_counter.c
│── button_toggle_led.c
│── port_test.c
│── walking_one.c
│── walking_zero.c
│── led_bar_graph.c
│── knight_rider_led.c
│── port_output_demo.c
│── port_input_demo.c
└── gpio_test_program.c
```

---

# 🎯 Next Goal

➡️ **Day 09 – Timers in 8051**

Topics to Learn:

- Introduction to Timers
- Timer 0
- Timer 1
- TMOD Register
- TCON Register
- Timer Modes
- Delay Calculation
- Timer Programming
- LED Blink using Timer
- Timer Applications

---

# 🚀 Learning Journey

I am documenting my daily progress as I work toward becoming an **Embedded Firmware Engineer**.

Each day includes:

- 📚 Theory Notes
- 💻 Embedded C Programs
- 🔬 Proteus Simulations
- ❓ Interview Questions
- 📝 Hands-on Practice

This repository reflects my continuous learning journey from **C Programming** to **Embedded Firmware Development**.

Feel free to explore the programs, provide feedback, or suggest improvements.

⭐ If you find this repository helpful, consider giving it a star!

---

# 📌 Day 08 Summary

✅ Learned GPIO fundamentals

✅ Understood 8051 GPIO architecture

✅ Interfaced LEDs and push buttons

✅ Practiced GPIO input and output programming

✅ Developed 10 GPIO-based Embedded C programs

✅ Simulated all programs using Keil μVision and Proteus

---

**Happy Coding! 🚀**

#EmbeddedSystems #EmbeddedC #8051 #GPIO #Firmware #Microcontroller #Keil #Proteus #GitHub #LearningJourney
