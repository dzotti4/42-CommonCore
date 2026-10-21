*This project has been created as part of the 42 curriculum by dzotti and gwindey.*

# cub3D — Our first RayCaster with miniLibX

## Description

cub3D is a 3D maze exploration project inspired by the classic game Wolfenstein 3D, widely regarded as the first true first-person shooter. The goal is to render a realistic 3D view of the inside of a maze from a first-person perspective using ray-casting techniques.

The program reads a `.cub` scene file that defines wall textures, floor and ceiling colors, and a map layout. It then renders the scene in real time using the miniLibX graphics library, allowing the player to navigate through the maze using the keyboard.

This project explores practical applications of mathematics — vectors, trigonometry, and geometry — in the context of graphics programming.

## Instructions

### Requirements

- Linux (tested on Ubuntu)
- miniLibX (`mlx_linux`) — clone into the project root:
  ```
  git clone https://github.com/42Paris/minilibx-linux mlx_linux
  ```
- libft — included in the `libft/` folder

### Compilation

```bash
make
```

This compiles both libft and mlx_linux automatically, then links the final binary.

```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # full recompile
```

### Execution

```bash
./cub3D maps/test.cub
```

The argument must be a valid `.cub` scene file. See `maps/test.cub` for an example.

### Controls

| Key | Action |
|-----|--------|
| W | Move forward |
| S | Move backward |
| A | Strafe left |
| D | Strafe right |
| ← | Rotate left |
| → | Rotate right |
| ESC | Quit |

### Scene file format

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 100,80,50
C 30,60,120

111111111
100000001
10N000001
111111111
```

- `NO/SO/WE/EA` — texture paths per wall direction
- `F` — floor color (R,G,B)
- `C` — ceiling color (R,G,B)
- Map characters: `1` = wall, `0` = empty, `N/S/E/W` = player start + orientation

## Resources

### Ray-casting references

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — primary reference for DDA algorithm and texture mapping
- [miniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx) — window management, hooks, image handling
- [Wolfenstein 3D source code](https://github.com/id-Software/wolf3d) — original implementation for reference

### AI usage

AI was used during this project for the following tasks:

- **Debugging**: identifying root causes of memory leaks in the mlx cleanup path (`game_destroy`) and resolving norminette violations (forbidden ternary operators).
- **Error handling**: improving file I/O error messages using `perror` for cases such as missing files, permission errors, and directory arguments.
- **Map validation**: discussing the flood fill approach and the additional `check_all_zeros` function for detecting disconnected open cells.
- **Code review**: verifying that all error paths free memory correctly before valgrind testing.

All AI-generated suggestions were reviewed, tested, and understood before being integrated into the project.

