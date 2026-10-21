*This project has been created as part of the 42 curriculum by dzotti.*

# get_next_line

## Description

A function that returns one line at a time from a file descriptor, for any `BUFFER_SIZE`.

## Instructions

```bash
cc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

`get_next_line(fd)` returns the next line (including `\n`), or `NULL` at the end of the file.

## What I learned

- Static variables that keep state between calls
- Reading with `read()` and a buffer of any size
