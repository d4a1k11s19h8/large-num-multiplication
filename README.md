```markdown
# 🧮 1024-Bit Calculator in C

This project is a high-precision **1024-bit calculator** written in **C**, capable of performing **addition**, **subtraction**, and **multiplication** on signed decimal integers with up to **309 digits** ($\approx$ 1024 bits). It uses string manipulation to handle values far beyond the range of standard data types like `int` or `long long`.

---

## ✨ Features

- ✅ Supports very large integers (up to 309 decimal digits)
- ✅ Handles **signed** numbers (e.g., `-123456789`)
- ✅ Performs:
  - ➕ Addition
  - ➖ Subtraction
  - ✖️ Multiplication
- ✅ Clean command-line interface
- ✅ Pure C, no external libraries needed

---

## 📁 Project Structure


.
├── cpl_new.c   # Main C source file with all logic
└── README.md   # Project documentation
```

---

## ⚙️ How to Compile & Run

### 🔧 Step-by-step

1. **Clone or download this repository**:

   ```bash
   git clone https://github.com/your-username/1024-bit-calculator.git
   cd 1024-bit-calculator
   ```

2. **Compile the C program**:

   ```bash
   gcc cpl_new.c -o calculator
   ```

3. **Run the calculator**:

   ```bash
   ./calculator
   ```

### 🖥️ Example Usage

```
********************************************************************************
    This is a 1024 bit addition,subtractor and multiplication calculator
    This Calculator accepts number in decimal (with sign if negative)
    of maximum length 309 which is 1024 bit in binary
    Choose the appropriate option(number)
    1. Subtraction
    2. Addition
    3. Multiplication
    Press any other key to Exit

    Enter choice Number: 2

    Enter first number  : -999999999999999999999999999999999
    Enter second number : 888888888888888888888888888888888

    Ans:    -111111111111111111111111111111111
********************************************************************************
```

## 🧠 How It Works

- **Input as strings**: Allows very large numbers beyond native limits.
- **String reversal**: Simplifies digit-by-digit operations from the least significant digit.
- **Arithmetic operations**:
  - `add_2_num()` for addition
  - `sub_2_num()` for subtraction with borrow handling
  - `mul_2_num()` for multiplication using a nested loop method
- **Sign handling and magnitude comparison** to support both positive and negative integers.

## 🔍 Core Functions Overview

| Function         | Purpose                                              |
|------------------|------------------------------------------------------|
| `sign_check()`   | Detects and processes the sign of a number           |
| `rev_num_str()`  | Reverses a string to ease digit operations          |
| `add_2_num()`    | Performs addition on reversed string numbers        |
| `sub_2_num()`    | Handles subtraction with manual borrow logic         |
| `mul_2_num()`    | Multiplies two large numbers as strings             |
| `sign_a_minus_b()`| Compares two numbers by magnitude                   |

## 💡 Potential Improvements

- ➗ Add division and modulus support
- 🧪 Add unit tests and validation
- 🧱 Use `struct` for number abstraction
- 🛠️ Create a `Makefile` for easier builds
- 🧼 Improve user input handling and formatting

## 🛠 Requirements

- C compiler (e.g., `gcc`)
- No external dependencies
- Works on Linux, macOS, Windows (with CLI tweaks)
```
