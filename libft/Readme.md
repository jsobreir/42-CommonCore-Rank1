# Libft
My own very first library.

The goal of this project is to develop a library consisting of basic C functions that can be later used throughout the Common Core.

## Documentation

## Functions
| No  | Libc Functions        | No | Additional Functions   | No | Bonus Functions      |
|-----|-----------------------|----|------------------------|----|----------------------|
| 1   | 'ft_memset'           | 1  | 'ft_substr'            | 1  | 'ft_lstnew'          |
| 2   | 'ft_bzero'            | 2  | 'ft_strjoin'           | 2  | 'ft_lstadd_front'    |
| 3   | 'ft_memcpy'           | 3  | 'ft_strtrim'           | 3  | 'ft_lstsize'         |
| 4   | 'ft_memccpy'          | 4  | 'ft_split'             | 4  | 'ft_lstlast'         |
| 5   | 'ft_memmove'          | 5  | 'ft_itoa'              | 5  | 'ft_lstadd_back'     |
| 6   | 'ft_memchr'           | 6  | 'ft_strmapi'           | 6  | 'ft_lstdelone'       |
| 7   | 'ft_memcmp'           | 7  | 'ft_putchar_fd'        | 7  | 'ft_lstclear'        |
| 8   | 'ft_strlen'           | 8  | 'ft_putstr_fd'         | 8  | 'ft_lstiter'         |
| 9   | 'ft_strlcpy'          | 9  | 'ft_putendl_fd'        | 9  | 'ft_lstmap'          |
| 10  | 'ft_strlcat'          | 10 | 'ft_putnbr_fd'         |    |                      |
| 11  | 'ft_strchr'           |    |                        |    |                      |
| 12  | 'ft_strrchr'          |    |                        |    |                      |
| 13  | 'ft_strnstr'          |    |                        |    |                      |
| 14  | 'ft_strncmp'          |    |                        |    |                      |
| 15  | 'ft_atoi'             |    |                        |    |                      |
| 16  | 'ft_isalpha'          |    |                        |    |                      |
| 17  | 'ft_isdigit'          |    |                        |    |                      |
| 18  | 'ft_isalnum'          |    |                        |    |                      |
| 19  | 'ft_isascii'          |    |                        |    |                      |
| 20  | 'ft_isprint'          |    |                        |    |                      |
| 21  | 'ft_toupper'          |    |                        |    |                      |
| 22  | 'ft_tolower'          |    |                        |    |                      |
| 23  | 'ft_calloc'           |    |                        |    |                      |
| 24  | 'ft_strdup'           |    |                        |    |                      |

## Installing and Using
To download, clone the repository into your device and navigate inside using 'cd libft', then typing 'make' to compile all the functions and generate the library archive, which you will then need to implement these fucntions in your own project.

To compile a program with the libft library, you can compile the program as follows:

```
cc ./program_name.c -L/path/to/libft -lft -o program_name
```

## Disclaimer
At 42 School our projects have to adhere to the 42 Norm of coding standards and good practices. These include:
- Maximum 25 lines per function and 5 functions per file;
- No variable declarations and assignments in the same line;
- Forbiden structures: 'for', 'switch', 'goto' and 'case';
- No more than 5 variables per function.

All of my projects strictly adhere to this Norm, that promotes code simplicity and readability.
