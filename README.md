# ft_printf

## Description

`ft_printf` is a project from the 42 common core that recreates the behavior of the standard C `printf()` function.

The goals are to understand variadic functions, formatted output, and data types .

The implementation supports the following conversions:

* `%c` — prints a character.
* `%s` — prints a string.
* `%p` — prints a pointer address in hexadecimal.
* `%d` — prints a signed decimal integer.
* `%i` — prints a signed integer.
* `%u` — prints an unsigned decimal integer.
* `%x` — prints an unsigned integer in lowercase hexadecimal.
* `%X` — prints an unsigned integer in uppercase hexadecimal.
* `%%` — prints a literal percent sign.

The function returns the number of the characters written.

## Instructions

### Requirements

*  C compiler, such as `cc`.
* `make`.
*  Unix-like environment.
* The accompanying `libft` source code and its Makefile.

### Compilation

Clone the repository and go to the project root directory.

Compile the project:

```
make
```

This builds the static library:

```
libftprintf.a
```

Remove object files:

```
make clean
```

Remove object files and the compiled library:

```
make fclean
```

Rebuild everything:

```
make re
```

### Usage

Include the project header in your C source file:

```
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d, hex: %x, %%\n",
        "42", 42, 42);
    return (0);
}
```

Compile your program and link it with the library:

```
cc -Wall -Wextra -Werror -I . main.c -L . -lftprintf -o program
```

Run the executable:

```bash
./program
```

Expected output:

```text
Hello 42! Number: 42, hex: 2a, %
```

The header is `ft_printf.h`, and the library is `libftprintf.a`. The library must be built before linking a program against it.

## Algorithm and Data Structures

### 1. Format-string traversal

The main function, `ft_printf()`, traverses the provided string from left to right using an integer index.

For ordinary characters, it writes the character directly and increments the return counter.

When it encounters `%`, it examines the following character to identify the requested conversion. It then sends the conversion to the appropriate helper function and adds the number of characters written to a counter.


### 2. Conversion 

The `data_type()` function finds which conversion is requested and sends the work to helper functions:

* `cutdata()` handles characters, strings, and pointers.
* `shortdata()` handles signed and unsigned decimal integers.
* `ft_putnbr_base()` handles unsigned numbers in different bases and pointer formatting.
* `ft_putnbr_base()` function prints an unsigned integer using a supplied base string.

For example:

* Decimal uses `0123456789`.
* Lowercase hexadecimal uses `0123456789abcdef`.
* Uppercase hexadecimal uses `0123456789ABCDEF`.

### 4. Data structures and memory management

The implementation primarily uses:

* **A string:** a constant character sequence traversed by index.
* **An integer counter:** tracks the number of characters written.
* **`va_list`:** accesses the variable arguments supplied to `ft_printf()`.
* **Integer values and a base string:** represent the number being converted and the alphabet used for its output.

Output is written directly through the existing Libft functions and `write()`.

The `va_list` is initialized with `va_start()` and released with `va_end()`.

## Resources

The following resources were used to understand the concepts involved in the project:

* Recreate printf() in C - in Linkedin
* Variadic Functions in C - Geeksforgeeks.org
* 42 peers implementations
* The 42 `ft_printf` subject .

### AI usage

AI was used for further explanations and mostly for edge cases tester during the development of this project.



It was used for:



* &#x20;Identifying edge cases and potential bugs.
* &#x20;Reviewing compilation issues.
* &#x20;Explaining `uintnptr_t` and data type conversions.





**All code was written by kpagkalo.** 
