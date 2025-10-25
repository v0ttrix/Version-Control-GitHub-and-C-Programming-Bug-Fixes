/**
 * @file calculator.c
 * @brief Professional Calculator Application
 * @author Jaden Mardini
 * 
 * Robust calculator implementation with comprehensive error handling,
 * input validation, and professional coding standards.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#define MAX_INPUT_LENGTH 256

typedef enum {
    OP_ADD = 1,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_POWER,
    OP_SQRT,
    OP_EXIT
} Operation;

/**
 * @brief Displays welcome banner
 */
static void print_welcome_menu(void) {
    printf("\n");
    printf(" ********************************\n");
    printf("**     Professional Calculator   **\n");
    printf("**        BCS Edition            **\n");
    printf("**      Author: Jaden Mardini    **\n");
    printf(" ********************************\n");
    printf("\n");
}

/**
 * @brief Displays operation menu
 */
static void print_options(void) {
    printf("Available Operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Square Root\n");
    printf("7. Exit\n");
    printf("\n");
}

/**
 * @brief Safely reads a double value with validation
 */
static int read_double(const char* prompt, double* value) {
    char buffer[MAX_INPUT_LENGTH];
    char* endptr;
    
    printf("%s", prompt);
    
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Error: Failed to read input\n");
        return 0;
    }
    
    *value = strtod(buffer, &endptr);
    
    if (endptr == buffer || (*endptr != '\n' && *endptr != '\0')) {
        printf("Error: Invalid number format\n");
        return 0;
    }
    
    return 1;
}

/**
 * @brief Safely reads an integer value with validation
 */
static int read_operation(int* operation) {
    char buffer[MAX_INPUT_LENGTH];
    char* endptr;
    
    printf("Enter operation number (1-7): ");
    
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Error: Failed to read input\n");
        return 0;
    }
    
    long temp = strtol(buffer, &endptr, 10);
    
    if (endptr == buffer || (*endptr != '\n' && *endptr != '\0')) {
        printf("Error: Invalid number format\n");
        return 0;
    }
    
    if (temp < 1 || temp > 7) {
        printf("Error: Operation must be between 1 and 7\n");
        return 0;
    }
    
    *operation = (int)temp;
    return 1;
}

/**
 * @brief Performs addition operation
 */
static void perform_addition(void) {
    double num1, num2, result;
    
    printf("\n=== Addition ===\n");
    
    if (!read_double("Enter first number: ", &num1)) return;
    if (!read_double("Enter second number: ", &num2)) return;
    
    /* Check for overflow */
    if ((num2 > 0 && num1 > DBL_MAX - num2) || 
        (num2 < 0 && num1 < -DBL_MAX - num2)) {
        printf("Error: Result would overflow\n");
        return;
    }
    
    result = num1 + num2;
    printf("Result: %.6f + %.6f = %.6f\n", num1, num2, result);
}

/**
 * @brief Performs subtraction operation
 */
static void perform_subtraction(void) {
    double num1, num2, result;
    
    printf("\n=== Subtraction ===\n");
    
    if (!read_double("Enter first number: ", &num1)) return;
    if (!read_double("Enter second number: ", &num2)) return;
    
    /* Check for overflow */
    if ((num2 < 0 && num1 > DBL_MAX + num2) || 
        (num2 > 0 && num1 < -DBL_MAX + num2)) {
        printf("Error: Result would overflow\n");
        return;
    }
    
    result = num1 - num2;
    printf("Result: %.6f - %.6f = %.6f\n", num1, num2, result);
}

/**
 * @brief Performs multiplication operation
 */
static void perform_multiplication(void) {
    double num1, num2, result;
    
    printf("\n=== Multiplication ===\n");
    
    if (!read_double("Enter first number: ", &num1)) return;
    if (!read_double("Enter second number: ", &num2)) return;
    
    /* Check for overflow */
    if (num1 != 0 && fabs(num2) > DBL_MAX / fabs(num1)) {
        printf("Error: Result would overflow\n");
        return;
    }
    
    result = num1 * num2;
    printf("Result: %.6f * %.6f = %.6f\n", num1, num2, result);
}

/**
 * @brief Performs division operation
 */
static void perform_division(void) {
    double num1, num2, result;
    
    printf("\n=== Division ===\n");
    
    if (!read_double("Enter dividend: ", &num1)) return;
    if (!read_double("Enter divisor: ", &num2)) return;
    
    if (num2 == 0.0) {
        printf("Error: Division by zero is undefined\n");
        return;
    }
    
    result = num1 / num2;
    printf("Result: %.6f / %.6f = %.6f\n", num1, num2, result);
}

/**
 * @brief Performs power operation
 */
static void perform_power(void) {
    double base, exponent, result;
    
    printf("\n=== Power (x^y) ===\n");
    
    if (!read_double("Enter base: ", &base)) return;
    if (!read_double("Enter exponent: ", &exponent)) return;
    
    /* Check for domain errors */
    if (base < 0 && floor(exponent) != exponent) {
        printf("Error: Negative base with non-integer exponent\n");
        return;
    }
    
    if (base == 0 && exponent < 0) {
        printf("Error: Zero to negative power is undefined\n");
        return;
    }
    
    result = pow(base, exponent);
    
    if (!isfinite(result)) {
        printf("Error: Result is infinite or undefined\n");
        return;
    }
    
    printf("Result: %.6f^%.6f = %.6f\n", base, exponent, result);
}

/**
 * @brief Performs square root operation
 */
static void perform_sqrt(void) {
    double num, result;
    
    printf("\n=== Square Root ===\n");
    
    if (!read_double("Enter number: ", &num)) return;
    
    if (num < 0) {
        printf("Error: Square root of negative number is undefined\n");
        return;
    }
    
    result = sqrt(num);
    printf("Result: sqrt(%.6f) = %.6f\n", num, result);
}

/**
 * @brief Main program loop
 */
int main(void) {
    int operation;
    int running = 1;
    
    print_welcome_menu();
    
    while (running) {
        print_options();
        
        if (!read_operation(&operation)) {
            continue;
        }
        
        switch (operation) {
            case OP_ADD:
                perform_addition();
                break;
            case OP_SUBTRACT:
                perform_subtraction();
                break;
            case OP_MULTIPLY:
                perform_multiplication();
                break;
            case OP_DIVIDE:
                perform_division();
                break;
            case OP_POWER:
                perform_power();
                break;
            case OP_SQRT:
                perform_sqrt();
                break;
            case OP_EXIT:
                printf("\nThank you for using the calculator!\n");
                running = 0;
                break;
            default:
                printf("Error: Invalid operation\n");
        }
        
        if (running) {
            printf("\nPress Enter to continue...");
            getchar();
            printf("\n");
        }
    }
    
    return EXIT_SUCCESS;
}
