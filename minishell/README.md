*This project has been created as part of the 42 curriculum by dzotti and gwindey.*

# minishell

## Description

A small shell, as beautiful as a little bash. It has a lexer, parser and executor, and supports:

- pipes `|` and redirections `<`, `>`, `>>` and heredoc `<<`
- environment variables and `$?`
- single and double quotes
- the builtins `echo`, `cd`, `pwd`, `export`, `unset`, `env` and `exit`
- `ctrl-C`, `ctrl-D` and `ctrl-\` like in bash

## Instructions

```bash
make
./minishell
```

## What I learned

- Parsing input into tokens and commands
- Processes with `fork`, `execve`, `pipe` and `dup2`
- Signals and the terminal
