# Cub3d
A Raycaster programmed in C by [pdruart](https://github.com/MrCrackerplays) and [rdrazsky](https://github.com/LANIK2000) for the Cub3d subject of Codam as part of the 42 network.

Made using [MLX42](https://github.com/W2Codam/MLX42), commit [13a181d73868fbd1ef8aee0b85c3bc0003ee4c40](https://github.com/W2Codam/MLX42/commit/13a181d73868fbd1ef8aee0b85c3bc0003ee4c40), and thus requires GLFW to be installed.

## Compiling
On Mac and Linux run
`make`
within the project directory to compile the mandatory part.
And run `make bonus` to compile the bonus part.

## Running
Syntax: `<executeable> <path_to_scene_file>` where the executable name generated for the mandatory is `cub3d` and the bonus executable name is `cub3d_bonus`.

## Features
### Mandatory
- [x] Different wall textures depending on the side of a wall hit by a ray
- [x] Floor and ceiling colors
- [x] <kbd>←</kbd> and <kbd>→</kbd> for looking left and right
- [x] <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> movement
- [x] <kbd>ESC</kbd> to close the program
### Bonus
- [x] Wall collisions
- [x] Minimap
- [x] Doors that can be opened and closed with <kbd>E</kbd> if the player isn't standing in an open door
- [x] Animated sprite
- [x] Rotate with mouse
### Extra (things we added that weren't asked for in either mandatory or bonus)
- [x] Mirrors reflecting walls
- [x] Looking up/down with mouse
- [x] Floor and ceiling textures instead of solid color
- [x] Animated door texture
- [x] Holding <kbd>SHIFT</kbd> for faster movement

## File Format
Every valid scene file has `.cub` as its extension.
A scene consists of 2 parts; Definitions and a Map, in that order.

Definitions have an identifier followed by at least 1 space and then their definition followed by a newline. Definitions can be spaced out with empty lines between them and be in any order so long as they are defined only once.

A Map is a tiled grid using characters that's always enclosed such that only walls are touching spaces/the outside. A map always has exactly 1 player spawn position.

`<file>`
: path to texture (`.png` or `.xpm` ([XPM42](https://github.com/W2Codam/MLX42#custom-xpm-xpm42-format))) relative to the executeable.

`<color>`
: RGB color described as `R,G,B`.
### Mandatory
#### Identifiers
| Syntax | Description |
| ----------- | ----------- |
| `NO <file>` | the wall's north face |
| `SO <file>` | the wall's south face |
| `EA <file>` | the wall's east face |
| `WE <file>` | the wall's west face |
| `C <color>` | color of the ceiling |
| `F <color>` | color of the floor |
#### Map Tiles
| Syntax | Description |
| ----------- | ----------- |
| <kbd>1</kbd> | wall |
| <kbd>0</kbd> | walkable space |
| <kbd>N</kbd> | player spawn position facing north |
| <kbd>S</kbd> | player spawn position facing south |
| <kbd>E</kbd> | player spawn position facing east |
| <kbd>W</kbd> | player spawn position facing west |
### Bonus
#### Identifiers
| Syntax | Description |
| ----------- | ----------- |
| `NO <file>` | the wall's north face |
| `SO <file>` | the wall's south face |
| `WE <file>` | the wall's west face |
| `EA <file>` | the wall's east face |
| `D0 <file>` | the door's first frame |
| `D1 <file>` | the door's second frame |
| `D2 <file>` | the door's third frame |
| `S0 <file>` | the sprite's first frame |
| `S1 <file>` | the sprite's second frame |
| `S2 <file>` | the sprite's third frame |
| `CI <file>` | the ceiling's repeating texture |
| `FI <file>` | the floor's repeating texture |
#### Map Tiles
| Syntax | Description |
| ----------- | ----------- |
| <kbd>1</kbd> | wall |
| <kbd>0</kbd> | walkable space |
| <kbd>N</kbd> | player spawn position facing north |
| <kbd>S</kbd> | player spawn position facing south |
| <kbd>E</kbd> | player spawn position facing east |
| <kbd>W</kbd> | player spawn position facing west |
| <kbd>C</kbd> | sprite |
| <kbd>D</kbd> | door |
| <kbd>M</kbd> | mirror |
