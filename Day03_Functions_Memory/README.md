# 📘 Day 03 – Functions, Storage Classes & Memory

Welcome to **Day 03** of my **Embedded Firmware Engineer Roadmap**.

Today I learned how functions improve code reusability and modularity, explored different storage classes in C, and understood how memory is organized inside a C program. These concepts are essential for writing efficient and maintainable embedded firmware.

---

## 🎯 Goal

- Understand different types of functions in C.
- Learn function prototypes and function calls.
- Understand Call by Value and Call by Reference.
- Implement recursive functions.
- Learn the different storage classes in C.
- Understand the scope and lifetime of variables.
- Explore the memory layout of a C program.
- Build a strong foundation for Embedded C programming.

---

## 📚 Topics Covered

- ✅ Functions in C
- ✅ Function Prototype
- ✅ Function without Arguments and Return Value
- ✅ Function with Arguments and Return Value
- ✅ Call by Value
- ✅ Call by Reference (Pointers)
- ✅ Recursion
- ✅ Storage Classes
- ✅ Local Variables
- ✅ Global Variables
- ✅ Memory Layout of C Program

---

## 💻 Programs

| No. | Program |
|-----|---------|
| 1 | function_without_argument.c |
| 2 | function_with_argument.c |
| 3 | function_return_value.c |
| 4 | function_prototype.c |
| 5 | call_by_value.c |
| 6 | call_by_reference.c |
| 7 | factorial_recursion.c |
| 8 | static_variable.c |
| 9 | global_local_variable.c |
| 10 | storage_class_demo.c |

---

## 🛠️ Tools Used

- Visual Studio Code
- GCC (MinGW)
- Git
- GitHub

---

## ▶️ How to Compile

```bash
gcc function_without_argument.c -o function_without_argument
```

## ▶️ How to Run

### Windows (PowerShell)

```powershell
.\function_without_argument.exe
```

### Windows (Command Prompt)

```cmd
function_without_argument.exe
```

---

## 📖 Key Learnings

- Learned how functions make programs modular and reusable.
- Understood the importance of function prototypes.
- Practiced passing data using Call by Value and Call by Reference.
- Implemented recursion to solve repetitive problems.
- Learned the difference between local and global variables.
- Explored storage classes (`auto`, `register`, `static`, and `extern`).
- Understood how memory is organized into Text, Data, BSS, Heap, and Stack segments.

---

## 📂 Folder Structure

```text
Day03_Functions_Memory/
│── README.md
│── function_without_argument.c
│── function_with_argument.c
│── function_return_value.c
│── function_prototype.c
│── call_by_value.c
│── call_by_reference.c
│── factorial_recursion.c
│── static_variable.c
│── global_local_variable.c
└── storage_class_demo.c
```

---

## 🔧 Embedded Firmware Relevance

Functions and memory management are fundamental in embedded firmware because they help developers:

- Write modular and reusable code.
- Improve code readability and maintenance.
- Manage memory efficiently in resource-constrained systems.
- Preserve data using static variables.
- Share data across multiple source files using global and extern variables.
- Develop scalable firmware for microcontrollers.

Understanding these concepts is essential before working with hardware peripherals and embedded drivers.

---

## 🎯 Next Goal

➡️ **Day 04 – Structures, Unions & Enums**

Upcoming topics:

- Structures
- Nested Structures
- Arrays of Structures
- Unions
- Enumerations (enum)
- Typedef
- Bit Fields
- Embedded Applications of Structures and Unions

---

## 🚀 Learning Journey

I am documenting my daily progress as I work toward becoming an **Embedded Firmware Engineer**.

Feel free to explore the programs, provide feedback, or suggest improvements.

⭐ If you find this repository helpful, consider giving it a star!

#EmbeddedC #CProgramming #Functions #StorageClasses #MemoryManagement #Firmware #EmbeddedSystems #GitHub #LearningJourney
