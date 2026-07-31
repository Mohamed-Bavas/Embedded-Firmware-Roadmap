# 📘 Day 05 – File Handling & Preprocessor

Welcome to **Day 05** of my **Embedded Firmware Engineer Roadmap**.

Today I learned about **File Handling** and the **C Preprocessor**, two important concepts for writing modular, maintainable, and scalable C programs. Although file handling is mainly used in desktop applications, preprocessor directives are widely used in Embedded C projects for hardware configuration, debugging, and code organization.

---

## 🎯 Goal

- Understand file handling in C.
- Learn different file opening modes.
- Read and write data using text and binary files.
- Understand the C Preprocessor.
- Learn macros and function-like macros.
- Organize programs using header files.
- Understand conditional compilation and include guards.
- Build a strong foundation for modular Embedded C programming.

---

## 📚 Topics Covered

- ✅ File Handling in C
- ✅ File Pointer (`FILE *`)
- ✅ File Opening Modes (`r`, `w`, `a`, `r+`, `w+`, `a+`)
- ✅ `fopen()`
- ✅ `fclose()`
- ✅ `fprintf()`
- ✅ `fscanf()`
- ✅ `fputc()` & `fgetc()`
- ✅ `fputs()` & `fgets()`
- ✅ `fwrite()` & `fread()`
- ✅ Preprocessor Directives
- ✅ Header Files
- ✅ Macros (`#define`)
- ✅ Function-like Macros
- ✅ Conditional Compilation (`#ifdef`, `#ifndef`, `#endif`)
- ✅ Include Guards
- ✅ `#undef`
- ✅ `#pragma`

---

## 💻 Programs

| No. | Program |
|-----|---------|
| 1 | file_write.c |
| 2 | file_read.c |
| 3 | file_append.c |
| 4 | character_file_operations.c |
| 5 | string_file_operations.c |
| 6 | binary_file_demo.c |
| 7 | macro_demo.c |
| 8 | function_macro.c |
| 9 | conditional_compilation.c |
| 10 | header_file_demo.c |

---

## 🛠️ Tools Used

- Visual Studio Code
- GCC (MinGW)
- Git
- GitHub

---

## ▶️ How to Compile

```bash
gcc file_write.c -o file_write
```

## ▶️ How to Run

### Windows (PowerShell)

```powershell
.\file_write.exe
```

### Windows (Command Prompt)

```cmd
file_write.exe
```

---

## 📖 Key Learnings

- Learned how to create, open, read, write, append, and close files.
- Understood the different file opening modes and when to use them.
- Practiced character, string, and binary file operations.
- Learned how the C Preprocessor works before compilation.
- Used macros to define constants and simplify code.
- Created function-like macros for reusable expressions.
- Organized programs using header files.
- Understood conditional compilation for enabling and disabling debug code.
- Learned how include guards prevent multiple inclusion of header files.

---

## 📂 Folder Structure

```text
Day05_File_Handling/
│── README.md
│── file_write.c
│── file_read.c
│── file_append.c
│── character_file_operations.c
│── string_file_operations.c
│── binary_file_demo.c
│── macro_demo.c
│── function_macro.c
│── conditional_compilation.c
└── header_file_demo.c
```

---

## 🔧 Embedded Firmware Relevance

Although microcontrollers often do not use traditional file systems, the concepts learned today are highly valuable in Embedded C development.

- Organize large firmware projects using header files.
- Configure hardware using macros (`#define`).
- Enable or disable debugging with conditional compilation.
- Share function declarations across multiple source files.
- Improve code readability and maintainability.
- Optimize firmware configuration using preprocessor directives.

These concepts are essential for developing scalable and professional embedded firmware.

---

## 🎯 Next Goal

➡️ **Day 06 – Bitwise Operators & Embedded C**

Upcoming topics:

- Bitwise Operators (`&`, `|`, `^`, `~`, `<<`, `>>`)
- Setting, Clearing, Toggling & Checking Bits
- Bit Masks
- Embedded C Basics
- `volatile` Keyword
- `const` Keyword
- Register Access
- Memory-Mapped I/O
- GPIO Register Manipulation

---

## 🚀 Learning Journey

I am documenting my daily progress as I work toward becoming an **Embedded Firmware Engineer**.

Feel free to explore the programs, provide feedback, or suggest improvements.

⭐ If you find this repository helpful, consider giving it a star!

#EmbeddedC #CProgramming #FileHandling #Preprocessor #Macros #Firmware #EmbeddedSystems #GitHub #LearningJourney
