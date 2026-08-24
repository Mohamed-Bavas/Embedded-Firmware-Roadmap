# 🚌 Day 16 – CAN Protocol (Controller Area Network)

Welcome to **Day 16** of my **Embedded Firmware Engineer Learning Journey**.

Today, I learned **CAN (Controller Area Network)**, a robust, real-time, message-based communication protocol widely used in **automotive, industrial automation, robotics, medical equipment, elevators, and other embedded systems**.

CAN allows multiple microcontrollers, ECUs, and electronic devices to communicate over a shared two-wire bus without requiring a central host.

CAN is especially important in automotive embedded systems because it provides **multi-master communication, message prioritization, non-destructive arbitration, error detection, fault confinement, and strong noise immunity**.

---

## 📚 Topics Covered

### 🔹 CAN Fundamentals

* What is CAN?
* Why CAN is used in Embedded Systems
* CAN features and advantages
* CAN nodes and communication
* CAN bus architecture
* CAN_H and CAN_L
* Differential signaling
* CAN bus topology
* 120Ω termination resistors

### 🔹 CAN Frame Structure

* Start of Frame (SOF)
* Identifier
* RTR bit
* Control Field
* Data Field
* CRC Field
* ACK Field
* End of Frame (EOF)
* Standard CAN frame
* Extended CAN frame

### 🔹 CAN Arbitration

* Multi-master communication
* Carrier Sense Multiple Access
* Non-destructive bitwise arbitration
* Dominant bit (0)
* Recessive bit (1)
* Message priority
* Lower identifier = Higher priority

### 🔹 CAN Bit Timing

* Bit time
* Sync Segment
* Propagation Segment
* Phase Segment 1
* Phase Segment 2
* CAN baud rate
* Common CAN speeds

### 🔹 CAN Error Handling

* Bit Error
* Stuff Error
* CRC Error
* Form Error
* ACK Error
* Transmit Error Counter (TEC)
* Receive Error Counter (REC)
* Error Active
* Error Passive
* Bus Off

---

# 🔌 CAN Bus Architecture

CAN uses a **two-wire differential bus** consisting of:

* **CAN_H – CAN High**
* **CAN_L – CAN Low**

A typical CAN network uses **120Ω termination resistors at both physical ends of the bus**.

```text
             CAN BUS

120Ω                                             120Ω
 │                                                 │
CAN_H ──────────────────────────────────────────────
CAN_L ──────────────────────────────────────────────
       │              │              │
     Node A         Node B         Node C
```

Multiple CAN nodes can communicate through the same shared bus.

---

# ⚡ CAN Differential Signaling

CAN uses differential signaling to provide better immunity against electrical noise.

### Dominant Bit – Logic 0

Typical CAN bus voltage:

```text
CAN_H ≈ 3.5V
CAN_L ≈ 1.5V
```

The differential voltage is approximately:

```text
CAN_H - CAN_L ≈ 2V
```

### Recessive Bit – Logic 1

Typical CAN bus voltage:

```text
CAN_H ≈ 2.5V
CAN_L ≈ 2.5V
```

The differential voltage is approximately:

```text
CAN_H - CAN_L ≈ 0V
```

> ⚠️ Actual voltages depend on the CAN transceiver and physical-layer implementation.

---

# 📦 CAN Frame Types

CAN supports different types of frames.

| Frame Type     | Purpose                                  |
| -------------- | ---------------------------------------- |
| Data Frame     | Carries application data                 |
| Remote Frame   | Requests transmission of a data frame    |
| Error Frame    | Indicates a detected communication error |
| Overload Frame | Provides additional delay between frames |

---

# 🧩 CAN Standard Data Frame

The **Standard CAN frame** uses an **11-bit identifier**.

| Field         | Size                        | Purpose                                |
| ------------- | --------------------------- | -------------------------------------- |
| SOF           | 1 bit                       | Marks the beginning of the frame       |
| Identifier    | 11 bits                     | Message identification and arbitration |
| RTR           | 1 bit                       | Data or Remote Frame                   |
| Control Field | 6 bits                      | Contains DLC and control information   |
| Data Field    | 0–8 bytes                   | Actual payload                         |
| CRC           | 15-bit sequence + delimiter | Error detection                        |
| ACK           | 2 bits                      | Receiver acknowledgment                |
| EOF           | 7 bits                      | Marks the end of the frame             |

### Simplified CAN Frame

```text
┌─────┬────────────┬─────┬─────────┬──────────┬─────┬─────┬─────┐
│ SOF │ Identifier │ RTR │ Control │   Data   │ CRC │ ACK │ EOF │
└─────┴────────────┴─────┴─────────┴──────────┴─────┴─────┴─────┘
```

---

# 🔢 Standard vs Extended CAN

CAN supports two identifier formats in Classical CAN.

| Feature              | Standard CAN        | Extended CAN                        |
| -------------------- | ------------------- | ----------------------------------- |
| Identifier           | 11-bit              | 29-bit                              |
| Identifier Range     | 0x000–0x7FF         | 29-bit identifier space             |
| CAN Version          | CAN 2.0A            | CAN 2.0B                            |
| Priority Arbitration | Supported           | Supported                           |
| Applications         | Common CAN networks | Networks requiring more identifiers |

---

# ⚔️ CAN Arbitration

CAN uses **non-destructive bitwise arbitration** to decide which node gets access to the bus.

CAN has two logical states:

```text
Dominant  = 0
Recessive = 1
```

A dominant bit always overrides a recessive bit.

When multiple nodes transmit simultaneously, every node monitors the actual bus state.

### Example

```text
Node A → 1010
Node B → 1001
```

At the third bit:

```text
Node A → 1  (Recessive)
Node B → 0  (Dominant)

Bus → 0
```

Node A detects that the bus value is different from the bit it transmitted and loses arbitration.

Node B continues transmitting.

### Important Rule

```text
Lower CAN Identifier
        ↓
Higher Priority
        ↓
Wins Arbitration
```

For example:

```text
0x100 → Higher Priority
0x300 → Lower Priority
```

---

# ⏱️ CAN Bit Timing

A CAN bit is divided into multiple timing segments.

```text
┌────────────┬───────────────┬──────────────┬────────────┐
│ Sync Seg   │ Propagation   │ Phase Seg 1  │ Phase Seg 2│
└────────────┴───────────────┴──────────────┴────────────┘
```

### Sync Segment

Synchronizes CAN nodes with the beginning of the bit.

### Propagation Segment

Compensates for signal propagation delays.

### Phase Segment 1

Used for synchronization and timing adjustment.

### Phase Segment 2

Used for synchronization and sampling.

---

## Common CAN Baud Rates

Common Classical CAN bit rates include:

* 125 kbps
* 250 kbps
* 500 kbps
* 1 Mbps

All nodes connected to the same CAN network must use compatible CAN bit timing and nominal bit rate.

---

# 🛡️ CAN Error Handling

CAN provides several built-in mechanisms for detecting communication errors.

### 1. Bit Error

Occurs when the transmitted bit does not match the actual bus state, except for situations where CAN arbitration or other defined protocol behavior explains the difference.

### 2. Stuff Error

After five consecutive identical bits, CAN inserts a complementary bit.

Example:

```text
11111 → 0 inserted
00000 → 1 inserted
```

The receiver removes the stuffed bit during decoding.

### 3. CRC Error

The receiver calculates the CRC and compares it with the transmitted CRC.

If the values do not match:

```text
CRC Error
```

### 4. Form Error

Occurs when a fixed-format field contains an invalid value.

### 5. ACK Error

Occurs when the transmitter does not detect an acknowledgment from another node.

---

# 🚦 CAN Error States

CAN controllers maintain two important error counters:

* **TEC – Transmit Error Counter**
* **REC – Receive Error Counter**

A node can move through different error states:

```text
Error Active
     ↓
Error Passive
     ↓
Bus Off
```

### Error Active

The CAN node is operating normally and can actively signal errors.

### Error Passive

The node has accumulated a significant number of errors and becomes restricted in how it signals errors.

### Bus Off

The node has accumulated excessive transmit errors and disconnects itself logically from the CAN bus.

A bus-off node must follow the controller/system recovery procedure before normal communication resumes.

---

# 🔧 CAN Hardware with 8051

The standard **8051 microcontroller does not have a built-in CAN controller**.

An external CAN controller can therefore be used.

A common solution is the **MCP2515**, which communicates with the MCU through SPI.

### Typical Architecture

```text
8051
 │
 │ SPI
 ▼
MCP2515
 │
 ▼
CAN Transceiver
 │
 ├──── CAN_H
 │
 └──── CAN_L
       │
    CAN BUS
```

The **MCP2515** acts as the external CAN controller.

A CAN transceiver such as **TJA1050** or **MCP2551** provides the physical interface between the controller and CAN bus.

---

# 🔧 CAN Hardware with STM32

Many STM32 microcontrollers provide an integrated CAN controller.

For example, selected STM32F1 devices such as the **STM32F103** use the **bxCAN** peripheral.

Typical architecture:

```text
STM32
 │
 │ CAN Peripheral
 ▼
CAN Transceiver
 │
 ├──── CAN_H
 │
 └──── CAN_L
       │
    CAN BUS
```

Unlike the MCP2515 approach, an external CAN controller is not required when the MCU already provides a CAN peripheral.

However, an appropriate **CAN transceiver is still required** to connect the CAN controller to the physical bus.

---

# 📡 CAN Communication Flow

A typical CAN communication path is:

```text
Application
     ↓
CAN Driver
     ↓
CAN Controller
     ↓
CAN Transceiver
     ↓
CAN_H / CAN_L
     ↓
CAN Bus
     ↓
Receiving Transceiver
     ↓
Receiving CAN Controller
     ↓
Application
```

---

# 💻 Practice Programs

## CAN Programs

| #  | Program                          | Description                                         |
| -- | -------------------------------- | --------------------------------------------------- |
| 01 | `can_initialize.c`               | Initializes CAN controller and configures baud rate |
| 02 | `can_send_message.c`             | Transmits a CAN data frame                          |
| 03 | `can_receive_message.c`          | Receives and processes CAN messages                 |
| 04 | `can_filter_setup.c`             | Configures CAN acceptance filters and masks         |
| 05 | `can_error_handling.c`           | Detects and handles CAN communication errors        |
| 06 | `can_two_node_communication.c`   | Demonstrates communication between two CAN nodes    |
| 07 | `can_led_control.c`              | Controls an LED through CAN commands                |
| 08 | `can_sensor_data_transmission.c` | Transmits sensor data from one CAN node to another  |

---

# 📂 Folder Structure

```text
Day16_CAN/
│
├── README.md
├── can_initialize.c
├── can_send_message.c
├── can_receive_message.c
├── can_filter_setup.c
├── can_error_handling.c
├── can_two_node_communication.c
├── can_led_control.c
└── can_sensor_data_transmission.c
```

---

# 🧪 Proteus Simulation Ideas

### CAN Two-Node Communication

```text
Node A ───────── CAN BUS ───────── Node B
```

Node A transmits a CAN message and Node B receives the message.

### LED Control over CAN

```text
Node A
  ↓
CAN Command
  ↓
CAN Bus
  ↓
Node B
  ↓
LED ON/OFF
```

### Sensor Data Transmission

```text
Sensor
  ↓
ADC
  ↓
CAN Node A
  ↓
CAN Bus
  ↓
CAN Node B
  ↓
LCD
```

### CAN Arbitration Demonstration

Use multiple CAN nodes with different identifiers and observe which message wins arbitration.

---

# 🎯 Applications

### CAN Applications

* 🚗 Automotive ECU Communication
* ⚙️ Industrial Automation
* 🏭 PLC Networks
* 🛗 Elevator Control Systems
* 🤖 Robotics
* 🔋 Battery Management Systems (BMS)
* 🚜 Agricultural Machinery
* 🏥 Medical Equipment
* 🏢 Building Automation
* 🚆 Transportation Systems

---

# ⚖️ CAN vs UART vs SPI vs I2C

| Feature          | CAN                        | UART                 | SPI               | I2C                 |
| ---------------- | -------------------------- | -------------------- | ----------------- | ------------------- |
| Communication    | Multi-master bus           | Point-to-point       | Master/Slave      | Multi-device bus    |
| Wires            | 2 bus wires                | TX/RX                | SCLK/MOSI/MISO/CS | SDA/SCL             |
| Arbitration      | Yes                        | No                   | Typically No      | Yes                 |
| Error Detection  | Strong built-in mechanisms | Limited              | Limited           | ACK/NACK            |
| Noise Immunity   | High                       | Moderate             | Moderate          | Moderate            |
| Typical Distance | Long                       | Short/Medium         | Short             | Short               |
| Typical Usage    | Automotive/Industrial      | Serial Communication | Sensors/Memory    | Sensors/Peripherals |

---

# 🧠 Important CAN Terms

| Term        | Meaning                                             |
| ----------- | --------------------------------------------------- |
| CAN         | Controller Area Network                             |
| CAN_H       | CAN High                                            |
| CAN_L       | CAN Low                                             |
| ID          | Message Identifier                                  |
| RTR         | Remote Transmission Request                         |
| DLC         | Data Length Code                                    |
| CRC         | Cyclic Redundancy Check                             |
| ACK         | Acknowledgment                                      |
| TEC         | Transmit Error Counter                              |
| REC         | Receive Error Counter                               |
| MCP2515     | External CAN Controller                             |
| TJA1050     | CAN Transceiver                                     |
| bxCAN       | CAN Controller Peripheral in selected STM32 devices |
| Arbitration | Process used to determine bus access                |
| Bus Off     | CAN state caused by excessive errors                |

---

# 🧪 Practical Learning

During Day 16, I practiced:

* Understanding CAN protocol fundamentals
* Understanding CAN_H and CAN_L
* Learning CAN differential signaling
* Understanding CAN bus topology
* Studying CAN frame structure
* Understanding Standard and Extended CAN
* Learning CAN arbitration
* Understanding dominant and recessive bits
* Studying CAN bit timing
* Understanding CAN error detection
* Learning TEC and REC
* Understanding Error Active, Error Passive, and Bus Off states
* Understanding MCP2515 CAN controller
* Understanding CAN transceivers
* Learning STM32 CAN architecture
* Exploring CAN communication and Proteus simulation concepts

---

# ✅ Day 16 Checklist

* [x] CAN Fundamentals
* [x] CAN Bus Topology
* [x] CAN_H and CAN_L
* [x] Differential Signaling
* [x] CAN Frame Structure
* [x] Standard & Extended CAN
* [x] CAN Arbitration
* [x] CAN Bit Timing
* [x] CAN Error Detection
* [x] TEC & REC
* [x] Error Active / Error Passive / Bus Off
* [x] 8051 CAN Interface
* [x] STM32 CAN Concepts
* [x] CAN Practice Programs – 8/8

---

# 🏆 Day 16 Milestone

* 📚 **CAN Protocol Fundamentals Completed**
* 🚌 **CAN Bus Architecture Understood**
* ⚔️ **CAN Arbitration Mechanism Understood**
* 📦 **CAN Frame Structure Studied**
* 🛡️ **CAN Error Handling Concepts Learned**
* 🔧 **MCP2515 + CAN Transceiver Interface Understood**
* 🔌 **STM32 CAN Peripheral Concepts Learned**
* 🧪 **CAN Communication Simulation Concepts Practiced**

---

# 🚀 Learning Progress

**Day 16 – CAN Protocol Completed ✔️**

Today I strengthened my understanding of **CAN communication**, one of the most important communication protocols used in automotive and industrial embedded systems.

I learned how multiple nodes communicate over a shared two-wire bus, how CAN performs **non-destructive arbitration**, how message priority is determined, and how the protocol detects and handles communication errors.

### Next Topic

**Day 17 – Watchdog Timer 🛡️**

> *Consistency beats intensity. Keep learning, keep building, and keep improving.* 🚀

---

⭐ Part of my **Embedded Firmware Engineer Learning Journey** and **Embedded Firmware Roadmap**.
