# Printf
Because ft_putnbr() and ft_putstr() aren’t enough.

The goal of this project is to replicate the printf function. This was the first time I used variadic functions.

## Documentation

## Scope of the project
While the goal of the project is to replicate the printf function, not all of it's original features are to be implemented. The following conversions are implemented:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

## Installing and Using
To download, clone the repository into your device and navigate inside using 'cd printf', then typing 'make' to compile all the functions and generate the library archive 'libftprintf.a', which you will then need to implement these fucntion in your own project.

To compile a program with the printf library, you can compile the program as follows:

```
cc ./program_name.c -L/path/to/printf -lft -o program_name
```

Alternatively, you can download my [libft](libft) from this repository, which compiles the printf archive into it's own archive, meaning you can use ft_printf with my libft library.

## Disclaimer
At 42 School our projects have to adhere to the 42 Norm of coding standards and good practices. These include:
- Maximum 25 lines per function and 5 functions per file;
- No variable declarations and assignments in the same line;
- Forbiden structures: 'for', 'switch', 'goto' and 'case';
- No more than 5 variables per function.

All of my projects strictly adhere to this Norm, that promotes code simplicity and readability.
