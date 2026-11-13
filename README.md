*This project has been created as part of the 42 curriculum by mahadout.*

# ft_printf

## Description

The **ft_printf** project is a recreation of the standard C `printf()` function.

The goal is to understand variadic functions in C and learn how to handle a variable number of arguments using `va_list`, `va_start`, `va_arg`, and `va_end`.

The function reads a format string, identifies conversion specifiers, retrieves the corresponding arguments, and prints the formatted output to the standard output.

This implementation supports the following mandatory conversions:

| Specifier | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints an integer in decimal notation. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned integer in lowercase hexadecimal. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal. |
| `%%` | Prints a percent sign. |

The function also returns the total number of characters printed, just like the original `printf()`.

## Instructions

### Requirements

- GCC or Clang compiler.
- Make (if using the provided Makefile).
- A Unix-like environment.

### Compilation

Clone the repository:

```bash
git clone https://github.com/ahadout/42-ft_printf.git ft_printf
cd ft_printf
```

Compile the source files:

```bash
cc -Wall -Wextra -Werror ft_printf.c ft_printf_helpers.c
```

To compile with your own test file:

```bash
cc -Wall -Wextra -Werror ft_printf.c ft_printf_helpers.c main.c -o test
```

### Execution

Run the compiled program:

```bash
./test
```

### Usage example

Include the project header in your source file:

```c
#include "ft_printf.h"

int main(void)
{
    int age = 25;
    char *name = "Mohamed";

    ft_printf("Hello %s, you are %d years old!\n", name, age);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Pointer: %p\n", &age);

    return (0);
}
```

Output:

```text
Hello Mohamed, you are 25 years old!
Hexadecimal: ff
Pointer: 0x...
```

## Algorithm and Data Structures

### 1. Variadic Functions

The main function uses a variadic function to accept a variable number of arguments.

```c
int ft_printf(const char *format, ...);
```

The `...` allows the function to receive additional arguments after the format string.

The following macros from `<stdarg.h>` are used:

- `va_list`: Declares a variable that stores the argument list.
- `va_start`: Initializes the argument list.
- `va_arg`: Retrieves the next argument with the specified type.
- `va_end`: Cleans up the argument list when processing is finished.

### 2. Format String Parsing Algorithm

The main algorithm processes the format string character by character.

It follows these steps:

1. Initialize the argument list using `va_start`.
2. Iterate through the format string.
3. If the current character is not `%`, print it directly.
4. If `%` is encountered, examine the next character to identify the conversion specifier.
5. Retrieve the corresponding argument using `va_arg`.
6. Call the appropriate printing function.
7. Keep track of the number of characters printed.
8. Finish by calling `va_end` and returning the total character count.

This approach allows the function to process multiple conversion specifiers in a single format string.

### 3. Number Conversion Algorithm

A generic base-conversion function is used to print unsigned numbers in different numerical bases.

```c
int ft_putnbr_base(unsigned long n, char *base, int base_len);
```

Instead of implementing a separate conversion algorithm for decimal and hexadecimal numbers, the same function handles different bases.

The algorithm uses division and modulo:

- `n / base_len` determines the remaining higher-order digits.
- `n % base_len` determines the current digit to print.

The function uses recursion to print the digits in the correct order.

For example, converting decimal `255` to hexadecimal:

```text
255 / 16 = 15 remainder 15
15 / 16  = 0  remainder 15

15 = f
15 = f

Result: ff
```

The base string determines which characters represent each digit:

```c
"0123456789"       // Decimal (base 10)
"0123456789abcdef" // Lowercase hexadecimal (base 16)
"0123456789ABCDEF" // Uppercase hexadecimal (base 16)
```

Using `unsigned long` allows the function to handle large unsigned values and pointer addresses on the target 64-bit Linux environment.

### 4. Signed Integer Handling

Signed decimal numbers are handled separately by `ft_putnbr()`.

Negative numbers require special treatment:

1. Check whether the number is negative.
2. Print the minus sign.
3. Convert the absolute magnitude to an unsigned value.
4. Pass it to the generic base-conversion function.

This approach avoids signed integer overflow when handling `INT_MIN`.

### 5. Data Structures and Memory Management

The project does not require complex data structures such as linked lists, arrays of structures, or trees.

The main data structures and types used are:

- `va_list`: Manages the variable argument list.
- `unsigned long`: Stores large unsigned numerical values and pointer addresses.
- `int`: Stores signed integers and character counts.
- Character arrays and strings: Store format strings and numerical bases.

The implementation does not require dynamic memory allocation for its core operations.

## Resources

### Documentation and References

The following resources were useful for understanding the concepts behind this project:

- [printf - Linux Manual Page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h - C Variable Arguments](https://en.cppreference.com/w/c/variadic.html)

### AI Usage

AI tools were used as a learning and support resource throughout the project.

Their use included:

- Understanding variadic functions and the `<stdarg.h>` macros.
- Explaining how format specifiers work and how arguments are retrieved.
- Understanding number conversion algorithms, including decimal and hexadecimal conversion.
- Identifying edge cases involving signed integers, unsigned integers, pointers, and NULL values.

The AI was used to explain concepts, provide debugging guidance, and support the learning process. The implementation, code modifications, testing, and final decisions were carried out by the student.

## Author

- **42 login:** mahadout
- **Project:** ft_printf
- **School:** 1337 / 42 Network