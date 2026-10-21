*This project has been created as part of the 42 curriculum by dzotti.*

# libft

## Description

My own C library: re-implementations of standard libc functions (`strlen`, `memcpy`, `atoi`, …), extra string helpers (`ft_split`, `ft_strjoin`, `ft_itoa`, …) and a linked-list toolkit (`ft_lstnew`, `ft_lstmap`, …). It is reused in most later projects.

## Instructions

```bash
make         # builds libft.a
make bonus   # adds the linked-list functions
```

Link it with `cc main.c -L. -lft`.

## What I learned

- Memory management with `malloc`/`free` and avoiding leaks
- Writing a Makefile that builds a static library
