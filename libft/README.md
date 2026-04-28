*This project has been created as part of the 42 curriculum by cllaurad.*

# libft

## Description
libft is a C library built from scratch that reimplements a set of standard C functions, plus some extra utilities. It covers string manipulation, memory management, character checks, integer conversion, output functions, and linked list operations. The goal is to understand how these functions work under the hood and have a personal library to reuse in future 42 projects.

## Instructions
Clone the repo and run `make` to create `libft.a` at the root.

To use it in another project, include the header and compile with:

    cc main.c -L. -lft

Other Makefile rules:
- `make clean` — removes object files
- `make fclean` — removes object files and libft.a
- `make re` — recompiles everything from scratch

## Library overview

**Character checks**
- `ft_isalpha` — checks if character is a letter
- `ft_isdigit` — checks if character is a digit
- `ft_isalnum` — checks if character is alphanumeric
- `ft_isascii` — checks if character is in ASCII table
- `ft_isprint` — checks if character is printable

**String functions**
- `ft_strlen` — returns length of a string
- `ft_strchr` — finds first occurrence of a character in a string
- `ft_strrchr` — finds last occurrence of a character in a string
- `ft_strncmp` — compares two strings up to n bytes
- `ft_strnstr` — finds a substring within a string up to n bytes
- `ft_strlcpy` — copies a string into a buffer safely
- `ft_strlcat` — appends a string to a buffer safely
- `ft_strdup` — duplicates a string into a new allocation
- `ft_substr` — extracts a substring from a string
- `ft_strjoin` — concatenates two strings into a new one
- `ft_strtrim` — removes characters from both ends of a string
- `ft_split` — splits a string by a delimiter into an array
- `ft_strmapi` — applies a function to each character, returns new string
- `ft_striteri` — applies a function to each character in place

**Memory functions**
- `ft_memset` — fills memory with a byte value
- `ft_bzero` — sets memory to zero
- `ft_memcpy` — copies memory from src to dst
- `ft_memmove` — copies memory handling overlaps safely
- `ft_memchr` — searches for a byte in memory
- `ft_memcmp` — compares two memory areas

**Conversion**
- `ft_atoi` — converts a string to integer
- `ft_itoa` — converts an integer to string
- `ft_toupper` — converts char to uppercase
- `ft_tolower` — converts char to lowercase

**Allocation**
- `ft_calloc` — allocates zero-initialised memory

**Output**
- `ft_putchar_fd` — writes a character to a file descriptor
- `ft_putstr_fd` — writes a string to a file descriptor
- `ft_putendl_fd` — writes a string followed by newline to a file descriptor
- `ft_putnbr_fd` — writes an integer to a file descriptor

**Linked list**
- `ft_lstnew` — creates a new node
- `ft_lstadd_front` — adds a node at the beginning
- `ft_lstadd_back` — adds a node at the end
- `ft_lstsize` — counts nodes in the list
- `ft_lstlast` — returns the last node
- `ft_lstdelone` — deletes one node
- `ft_lstclear` — deletes and frees the entire list
- `ft_lstiter` — applies a function to each node
- `ft_lstmap` — creates a new list by applying a function to each node

## Resources
- [man pages](https://man7.org/linux/man-pages/) — reference for all reimplemented functions
- [42 Norm](https://github.com/42School/norminette) — norminette rules
