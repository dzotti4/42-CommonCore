*This project has been created as part of the 42 curriculum by dzotti.*

# minitalk

## Description

A client and server that talk to each other using only UNIX signals. The client sends a string bit by bit with `SIGUSR1` and `SIGUSR2`; the server rebuilds the characters and prints the message.

## Instructions

```bash
make
./server              # prints its PID
./client <PID> "Hello"
```

## What I learned

- UNIX signals and `sigaction`
- Bit manipulation
