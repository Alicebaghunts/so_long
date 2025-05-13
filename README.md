# Battle City Game Project

## Introduction
This project is a modernized take on the classic "Battle City" game. The game involves navigating a map constructed with walls, collectibles, and free spaces. The player must explore the map, collect items, and reach the exit while adhering to strict validation rules for the map's structure and gameplay.

---

## Map Requirements
The map is a key component of the game and must adhere to the following rules:

### Map Components
The map must be constructed using the following characters only:
- `0`: Represents an empty space.
- `1`: Represents a wall.
- `C`: Represents a collectible.
- `E`: Represents the map exit.
- `P`: Represents the player’s starting position.

- this is mine characters
- `M`: Metal wall.
- `B`: bomb bad coin.

### Example of a Valid Map
Here is an example of a simple valid map:
```
1111111111111111111111111111
1000000000C00000000000000001
1011111110101111111010111001
1C100000010000000101000000C1
1000011101111110101011111001
100C000000000001010000000001
1111011111111010101111101111
1C00P0000000E0010000000000C1
1111111111111111111111111111
```

### Validation Rules
1. **Mandatory Components**:
   - The map must contain exactly **1 exit (`E`)**.
   - The map must contain exactly **1 starting position (`P`)**.
   - The map must contain at least **1 collectible (`C`)**.

2. **Rectangular Structure**:
   - The map must be rectangular in shape.

3. **Enclosed by Walls**:
   - The map must be completely surrounded by walls (`1`). If not, an error will be raised.

4. **No Duplicate Characters**:
   - Duplicates of `E` (exit) or `P` (starting position) are not allowed. If duplicates exist, an error will be raised.

5. **Valid Path**:
   - The game must verify that there is a valid path in the map that allows the player to reach all collectibles and the exit.

6. **Error Handling**:
   - If any misconfiguration is found in the map file, the program will exit cleanly and return:
     ```
     Error\n
     [Explicit error message]
     ```
---

## Gameplay
Once the map is validated, the player can navigate through the map to:
1. Collect all the collectibles (`C`).
2. Reach the exit (`E`).

---

2. **Sprite Animation**:
   - Add animations for the game sprites to enhance visual appeal.
---

## How to Run
