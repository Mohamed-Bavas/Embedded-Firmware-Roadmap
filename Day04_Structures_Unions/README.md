# 📘 Day 04 – Structures, Unions & Enums

Welcome to **Day 04** of my **Embedded Firmware Engineer Roadmap**.

Today I learned about **Structures, Unions, and Enumerations (Enums)** in C. These user-defined data types help organize related data efficiently and are widely used in embedded firmware for representing hardware registers, communication packets, and device configurations.

---

## 🎯 Goal

- Understand user-defined data types in C.
- Learn how to create and use structures.
- Store and manage multiple records using arrays of structures.
- Access structure members using pointers.
- Understand the difference between structures and unions.
- Learn how enumerations improve code readability.
- Explore `typedef` and bit fields.
- Build a strong foundation for data organization in Embedded C.

---

## 📚 Topics Covered

- ✅ Structures (`struct`)
- ✅ Structure Declaration and Initialization
- ✅ Accessing Structure Members
- ✅ Array of Structures
- ✅ Nested Structures
- ✅ Pointer to Structure
- ✅ Self-Referential Structure
- ✅ Unions (`union`)
- ✅ Structure vs Union
- ✅ Enumerations (`enum`)
- ✅ `typedef`
- ✅ Bit Fields
- ✅ Structure Padding & Memory Alignment

---

## 💻 Programs

| No. | Program |
|-----|---------|
| 1 | structure_basics.c |
| 2 | structure_initialization.c |
| 3 | array_of_structures.c |
| 4 | nested_structure.c |
| 5 | pointer_to_structure.c |
| 6 | union_demo.c |
| 7 | structure_vs_union.c |
| 8 | enum_demo.c |
| 9 | typedef_demo.c |
| 10 | bit_field_demo.c |

---

## 🛠️ Tools Used

- Visual Studio Code
- GCC (MinGW)
- Git
- GitHub

---

## ▶️ How to Compile

```bash
gcc structure_basics.c -o structure_basics
```

## ▶️ How to Run

### Windows (PowerShell)

```powershell
.\structure_basics.exe
```

### Windows (Command Prompt)

```cmd
structure_basics.exe
```

---

## 📖 Key Learnings

- Learned how structures group related data of different data types.
- Used arrays and nested structures to organize complex data.
- Accessed structure members using pointers and the `->` operator.
- Understood how unions save memory by sharing the same memory location.
- Compared structures and unions based on memory usage.
- Used enumerations (`enum`) to represent meaningful constant values.
- Simplified code using `typedef`.
- Learned how bit fields optimize memory usage.
- Understood structure padding and memory alignment.

---

## 📂 Folder Structure

```text
Day04_Structures_Unions/
│── README.md
│── structure_basics.c
│── structure_initialization.c
│── array_of_structures.c
│── nested_structure.c
│── pointer_to_structure.c
│── union_demo.c
│── structure_vs_union.c
│── enum_demo.c
│── typedef_demo.c
└── bit_field_demo.c
```

---

## 🔧 Embedded Firmware Relevance

Structures, unions, and enums are widely used in embedded systems for:

- Organizing sensor and device data.
- Representing communication packets (UART, SPI, I²C, CAN).
- Mapping hardware registers.
- Saving memory using unions.
- Defining device states with enums.
- Creating readable and maintainable firmware.
- Optimizing memory using bit fields.

These concepts are fundamental for developing scalable and efficient embedded firmware.

---

## 🎯 Next Goal

➡️ **Day 05 – File Handling & Preprocessor**

Upcoming topics:

- File Handling in C
- File Operations (`fopen`, `fclose`, `fprintf`, `fscanf`)
- Reading and Writing Files
- Preprocessor Directives
- Macros
- Header Files
- Conditional Compilation
- Include Guards

---

## 🚀 Learning Journey

I am documenting my daily progress as I work toward becoming an **Embedded Firmware Engineer**.

Feel free to explore the programs, provide feedback, or suggest improvements.

⭐ If you find this repository helpful, consider giving it a star!

#EmbeddedC #Structures #Unions #Enums #Firmware #EmbeddedSystems #CProgramming #GitHub #LearningJourney
