# ft_printf

*This project has been created as part of the 42 curriculum by nda-roch.*

## Description

`ft_printf` is a C library that reimplements the standard `printf()` function from libc. The goal is to understand variadic functions, format string parsing, and base conversion by building the function from scratch without relying on the original implementation.

The library is compiled as a static archive `libftprintf.a` and supports the following conversions:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer in base 10 |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in hexadecimal lowercase |
| `%X` | Prints a number in hexadecimal uppercase |
| `%%` | Prints a literal percent sign |

## Instructions

### Compilation

```bash
make
```

This will compile all source files and create `libftprintf.a` at the root of the repository.

### Cleaning

```bash
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

### Usage

Include the header in your source file:

```c
#include "ft_printf.h"
```

Link against the library when compiling:

```bash
cc main.c -L. -lftprintf -o my_program
```

### Example

```c
ft_printf("Hello, %s! You are %d years old.\n", "Alice", 30);
ft_printf("Pointer address: %p\n", ptr);
ft_printf("Hex: %x | %X\n", 255, 255);
```

## Algorithm and Data Structure

### Format string parsing

`ft_printf` iterates through the format string one character at a time. When it encounters a regular character, it prints it directly using `write()`. When it encounters a `%`, it looks at the next character to determine which conversion to apply, then advances past both characters.

### Variadic arguments

The extra arguments are accessed using the `va_list` mechanism from `<stdarg.h>`. A `va_list` acts as a cursor over the argument stack. `va_start` initializes it, `va_arg` advances it and retrieves the next argument as a given type, and `va_end` cleans up. The format string drives which type is pulled at each step.

### Base conversion

Number printing is handled recursively. For a given number `n` in base `b`:
- If `n >= b`, recurse with `n / b` (higher digits), then print `n % b` (current digit)
- If `n < b`, print the digit directly using a lookup string (e.g. `"0123456789abcdef"`)

This naturally prints digits in the correct left-to-right order without needing a buffer or reversal. The same algorithm handles base 10 (decimal), unsigned, and base 16 (hexadecimal) — only the base value and lookup string change.

### Character count

Every helper function returns the number of characters it wrote. The main loop accumulates these return values into a running total, which is returned at the end — matching the behavior of the real `printf()`.

### Pointer printing

Pointers are cast to `unsigned long` to safely handle 64-bit addresses. A separate helper handles the recursive hex conversion, while the outer function prepends the `0x` prefix and handles the `NULL` case (printed as `(nil)`).

## Resources

- [printf - Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic functions in C - cppreference](https://en.cppreference.com/w/c/variadic)
- [stdarg.h - va_list, va_start, va_arg, va_end](https://en.cppreference.com/w/c/variadic/va_list)
- [Number base conversion explained](https://www.mathsisfun.com/hexadecimals.html)
- [42 Docs - ft_printf subject](https://cdn.intra.42.fr/pdf/pdf/96330/en.subject.pdf)

### AI Usage

AI was used as a **learning tool** throughout this project. Rather than generating code directly, it was used to:
- Explain concepts such as variadic functions, `va_list`, and base conversion algorithms
- Guide the reasoning behind function signatures and return value design
- Review code written by the student and point out bugs without providing direct fixes
- Help structure the project files and understand the overall architecture
