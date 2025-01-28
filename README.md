![so_longl](images/so_long.png)

# 𒅒𒈔𒇫𒄆🥷🏼🎎
So Long is a simple 2D game project where you play as a **samurai** 👹  
on a quest to collect flowers or save hostages before escaping on your horse 🐴.

---

## 🕹️ Controls

- **W** – Move Up ⬆️  
- **A** – Move Left ⬅️  
- **S** – Move Down ⬇️  
- **D** – Move Right ➡️  
- **Arrow Keys** – You can also use the **Arrow Keys** for movement:
  - **↑** – Move Up
  - **←** – Move Left
  - **↓** – Move Down
  - **→** – Move Right

---

## 👾 Gameplay

### **Mandatory Version**:

<img src="images/so_long_terminal.png" alt="so_long_terminal" width="400" height="200">

- You control the **samurai** 👹.
- Your goal is to **collect all the flowers** 🌸.
- Once all flowers are collected, you can **escape on your horse** 🐴 to finish the level!

### **Bonus Version**:

<img src="images/so_long_terminal_bonus.png" alt="so_long_terminal_bonus" width="400" height="200">

- Same gameplay as the mandatory version, but with an extra twist: 
- This time you must **save all the hostages** 🧑‍🤝‍🧑 before escaping on your horse 🐴.
- Watch out for the **ninjas** 🥷 patrolling the map!

---

## 🌍 Built With

- **C** – The game logic.
- **Libft** – My own custom utility library. [LIBFT](https://github.com/josmanov/Libft)
- **MLX42** – The 2D graphical library [MLX42](https://github.com/codam-coding-college/MLX42)

---

Are you able to save everyone and escape?

---

## 🛠️ Creating Your Own Map

To create your own custom map for the game, follow these conditions to make sure your map is valid:

### Map Format

The map is represented as a **2D grid** using the following characters:

- `1` = Wall
- `0` = Empty space
- `P` = Player starting position
- `E` = Exit
- `C` = Collectable 
(BONUS)
- `X` = Enemy (works only in bonus version)

### Map Conditions
- The map fiels name must have the **.ber** extension: **(map.ber**)
- The map must contain:
  - Exactly **1 player (`P`)**.
  - Exactly **1 exit (`E`)**.
  - At least **1 collectable or more (`C`)**.
  - Optional: **empty spaces (`0`)**
- The **player (`P`)** must be able to have a path to all **collectables (`C`)**.
- The **player (`P`)** must be able to have a path to the **exit (`E`)**.
- The **exit (`E`)** must not obstruct the path to a collectable.
- The map must be **rectangular**.
- The **outside walls** must be fully closed **( must be 1's )**.

- **Bonus Version**:
  - The **enemy (`X`)** can be used for the bonus version to patrol the map.

---
# To help you visualize the 2D map:
## Mandatory Version:
- `P` = Player (samurai) starting position.
- `C` = Collectable (flower).
- `E` = Exit.
- `1` = Wall.
```bash
11111111
1P0000E1
100C0001
11111111
```
## Bonus Version:
- `X` = Enemy (ninja).
- `P` = Player (samurai) starting position.
- `C` = Collectable (hostage).
- `E` = Exit.
- `1` = Wall.
```bash
11111111
1P0X00E1
1000C001
11111111
```
