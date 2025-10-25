# Professional Calculator Application

## Overview

Professional C calculator application demonstrating robust programming practices, comprehensive error handling, and mathematical operations with proper validation.

## Project Structure

```
Version-Control-GitHub-and-C-Programming-Bug-Fixes/
├── src/
│   └── calculator.c       # Main calculator implementation
├── bin/                   # Compiled executable
├── Makefile              # Build configuration
└── README.md             # This file
```

## Features

### Mathematical Operations
- **Addition** - Safe addition with overflow detection
- **Subtraction** - Safe subtraction with overflow detection  
- **Multiplication** - Safe multiplication with overflow detection
- **Division** - Division with zero-division protection
- **Power** - Exponentiation with domain validation
- **Square Root** - Square root with negative number protection

### Safety Features
- Comprehensive input validation
- Overflow and underflow detection
- Domain error checking (negative square roots, etc.)
- Buffer overflow protection
- Graceful error handling

### User Interface
- Professional menu system
- Clear operation prompts
- Detailed error messages
- Interactive operation loop

## Building the Project

### Prerequisites
- GCC compiler (C11 standard)
- Make utility
- Math library (libm)

### Compilation
```bash
# Build the calculator
make all

# Or specifically
make calculator

# Clean build artifacts
make clean
```

## Usage

### Running the Calculator
```bash
./bin/calculator
```

### Example Session
```
 ********************************
**     Professional Calculator   **
**        BCS Edition            **
**      Author: Jaden Mardini    **
 ********************************

Available Operations:
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Power (x^y)
6. Square Root
7. Exit

Enter operation number (1-7): 1

=== Addition ===
Enter first number: 15.5
Enter second number: 24.3
Result: 15.500000 + 24.300000 = 39.800000
```

## Technical Features

### Error Handling
- Input validation for all user inputs
- Mathematical domain checking
- Overflow/underflow detection
- Clear error messages with guidance

### Code Quality
- C11 standard compliance
- Professional naming conventions
- Comprehensive documentation
- Modular function design

### Mathematical Safety
- Proper floating-point arithmetic
- Domain validation for all operations
- Infinity and NaN detection
- Precision-aware calculations

## Improvements from Original

### Bug Fixes
- Fixed inconsistent data types (double vs int)
- Added proper input validation
- Implemented overflow protection
- Added missing return type for main()

### Enhancements
- Expanded from 2 to 6 mathematical operations
- Professional user interface
- Comprehensive error handling
- Interactive operation loop
- Safe input reading with buffer protection

### Code Quality
- Professional documentation
- Consistent coding style
- Modular design
- Proper memory management

## Design Principles

1. **Safety First** - All operations validated for safety
2. **User Experience** - Clear prompts and error messages
3. **Robustness** - Handles all edge cases gracefully
4. **Maintainability** - Clean, documented code
5. **Professional Standards** - Industry best practices

## Author

Jaden Mardini - Computer Science Student

## License

This project is for educational purposes.
