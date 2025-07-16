# Loan Amortization Calculator (C)

This project includes multiple C implementations of a loan amortization calculator. Each version explores different techniques for memory management, input handling, and data modeling — using arrays, pointers, and structs.

## 💡 Features

- Calculates monthly payments, total interest, and principal
- Supports multiple implementation styles:
  - Procedural (`loan.c`)
  - Modular with functions (`loanCalc(1).c`)
  - Array-based approach (`loanCalcArr.c`)
  - Pointer-based version (`loanCalcPtr.c`)
  - Struct-based model (`loanCalcStruct.c`)
- Command-line interface with user input

## 🔧 Files

| File Name           | Description                                      |
|---------------------|--------------------------------------------------|
| `loan.c`            | Basic amortization calculator                    |
| `loanCalc(1).c`     | Modularized with reusable functions              |
| `loanCalcArr.c`     | Uses arrays to store monthly breakdown           |
| `loanCalcPtr.c`     | Pointer version for dynamic data handling        |
| `loanCalcStruct.c`  | Struct-based model for clean data encapsulation  |

## 🚀 How to Run

Compile any version using `gcc`:

```bash
gcc loanCalcStruct.c -o loan_calc
./loan_calc
