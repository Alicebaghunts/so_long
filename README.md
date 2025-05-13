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

### Example of a Valid Map
Here is an example of a simple valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
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

### Example of a Minimal `.ber` Map
Below is an example of a minimal `.ber` map:
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

---

## Gameplay
Once the map is validated, the player can navigate through the map to:
1. Collect all the collectibles (`C`).
2. Reach the exit (`E`).

---

## Bonus Features
If the mandatory part is implemented perfectly (i.e., all requirements are satisfied and no malfunctions exist), additional bonus features may be implemented for extra points. The bonus features include:
1. **Enemy Patrols**:
   - The player loses the game if they touch an enemy patrol.

2. **Sprite Animation**:
   - Add animations for the game sprites to enhance visual appeal.

3. **Movement Count Display**:
   - Display the movement count directly on the screen instead of writing it to the shell.

### Note on Bonus Evaluation
- The bonus part will only be evaluated if the **mandatory part is PERFECT**.
- A perfect implementation means the mandatory part works flawlessly without any errors or malfunctions.

---

## Additional Notes
- The program must be able to parse any map file as long as it follows the rules specified above.
- Any additional files or folders created for the bonus part must be justified during evaluation.

---

## Error Handling
- All errors will result in an immediate program exit with the message:
  ```
  Error\n
  [Explicit error message]
  ```

---

## How to Run
1. Ensure your map file follows the rules outlined above.
2. Run the program with the map file as input.
3. Enjoy the game!

---

## Future Scope
While this project focuses on the core mechanics, further graphic-intensive projects await, so it is advised not to spend excessive time on bonus features.
