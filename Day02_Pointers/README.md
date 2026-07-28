# 📘 Day 02 – Pointers, Arrays & Strings

Welcome to **Day 02** of my **Embedded Firmware Engineer Roadmap**.

Today I explored **Pointers**, **Arrays**, and **Strings** in C. These are fundamental concepts in Embedded C programming and are widely used for memory access, peripheral control, data manipulation, and firmware development.

---

## 🎯 Goal

- Understand the fundamentals of pointers in C.
- Learn how memory addresses are accessed using pointers.
- Use the Address (`&`) and Dereference (`*`) operators.
- Implement Call by Reference using pointers.
- Learn array declaration, traversal, and manipulation.
- Perform basic string operations without using standard library functions.
- Build a strong foundation for memory handling in Embedded C.

---

## 📚 Topics Covered

- ✅ Introduction to Pointers
- ✅ Pointer Declaration and Initialization
- ✅ Address Operator (`&`)
- ✅ Dereference Operator (`*`)
- ✅ Call by Reference
- ✅ Arrays
- ✅ Array Traversal
- ✅ Array Sum
- ✅ Array Reverse
- ✅ String Basics
- ✅ String Length
- ✅ String Copy
- ✅ String Compare

---

## 💻 Programs

| No. | Program |
|-----|---------|
| 1 | pointer_basics.c |
| 2 | address_operator.c |
| 3 | dereference_operator.c |
| 4 | swap_using_pointers.c |
| 5 | array_basics.c |
| 6 | array_sum.c |
| 7 | array_reverse.c |
| 8 | string_length.c |
| 9 | string_copy.c |
| 10 | string_compare.c |

---

## 🛠️ Tools Used

- Visual Studio Code
- GCC (MinGW)
- Git
- GitHub

---

## ▶️ How to Compile

```bash
gcc pointer_basics.c -o pointer_basics
```

## ▶️ How to Run

### Windows (PowerShell)

```powershell
.\pointer_basics.exe
```

### Windows (Command Prompt)

```cmd
pointer_basics.exe
```

---

## 📖 Key Learnings

- Understood how pointers store memory addresses.
- Learned the difference between the Address (`&`) and Dereference (`*`) operators.
- Implemented Call by Reference using pointers.
- Worked with one-dimensional arrays.
- Performed array traversal, summation, and reversal.
- Implemented string operations manually without using standard library functions.
- Improved understanding of memory access, which is essential for Embedded C programming.

---

## 📂 Folder Structure

```text
Day02_Pointers/
│── README.md
│── pointer_basics.c
│── address_operator.c
│── dereference_operator.c
│── swap_using_pointers.c
│── array_basics.c
│── array_sum.c
│── array_reverse.c
│── string_length.c
│── string_copy.c
└── string_compare.c
```

---

## 🔧 Embedded Firmware Relevance

Pointers, arrays, and strings are essential in embedded firmware because they are used for:

- Memory-mapped register access
- Peripheral driver development
- UART, SPI, I2C, and CAN communication
- Sensor data buffering
- Efficient memory management
- Passing data between functions
- Firmware optimisation

Mastering these concepts is an important step toward becoming an Embedded Firmware Engineer.

---

## 🎯 Next Goal

➡️ **Day 03 – Functions, Storage Classes & Memory**

Upcoming topics:

- Functions in C
- Function Prototypes
- Call by Value vs Call by Reference
- Recursion
- Storage Classes (`auto`, `static`, `extern`, `register`)
- Stack and Heap Memory
- Memory Layout of a C Program

---

## 🚀 Learning Journey

I am documenting my daily progress as I work toward becoming an **Embedded Firmware Engineer**.

Feel free to explore the programs, provide feedback, or suggest improvements.

⭐ If you find this repository helpful, consider giving it a star!

#EmbeddedC #Pointers #Arrays #Strings #MemoryManagement #Firmware #EmbeddedSystems #CProgramming #GitHub #LearningJourney
