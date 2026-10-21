*This project has been created as part of the 42 curriculum by dzotti.*

# Philosophers

## Description

The dining philosophers problem: philosophers sit around a table, share forks and must eat, sleep and think without dying of hunger. Each philosopher is a thread, each fork a mutex, and a monitor stops the simulation as soon as one philosopher dies.

## Instructions

```bash
make
./philo 5 800 200 200 [7]
```

Arguments: number of philosophers, time to die, time to eat, time to sleep (in ms) and optionally how many times each philosopher must eat.

## What I learned

- Threads with `pthread`
- Mutexes, data races and deadlocks
