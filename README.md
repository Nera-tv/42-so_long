

# So_Long
*And thanks for all the apples!*

<p align="center">
   <img src="https://github.com/Neress-dono/pictures/blob/108ebb57006ec708c79fc4f66bf1ce5bdd248fd7/commun-core_42/so_long/apple.png">   
</p>

### Table of Contents
* **About the project**
* * [Introduction](#introduction)
*  * [Map Rules](#map-rules)
* **Usage**
* * [Requirements](#requirements)
* * [Instructions](#instructions)
* * [How to play](#how-to-play)
* [**Goals**](#goals)
* [**Skills**](#skills)


## About the project

### Introduction
A top-down game with Minecraft graphics, where you have to collect all the diamonds to escape through the trapdoor. 

In the bonus mode you must also escape from a zombie, if you get hit by it, you lose.

*(Only available on MAC)*

### Map Rules

The game we choose must follow a set of rules. The executable  `so_long`  will receive a map as the only argument, and this map will have a  `.ber`  filetype.

The file also must follow these rules:

-   Only  `P`  _(player)_,  `1`  _(wall)_,  `0`  _(ground)_,  `C`  _(collectible)_, and  `E`  _(exit)_  will be accepted characters in our map (except if you add enemies as bonus)
-   The map must be rectangular, i.e. all rows must have the same length
-   There must be at least one exit, one player, and one collectible on the map
-   The map must be closed, i.e. surrounded by walls

Map exemple :

```ber
111111111111111
10C010C010C01E1
101010101010101
1P10C010C010C01
111111111111111
```
<p>
   <img src="https://github.com/Neress-dono/pictures/blob/72bbbd4644d61cda5fb2e63c3fa859cf2f7f00d9/commun-core_42/so_long/Screen%20Shot%202022-02-14%20at%2011.43.10%20AM.png">   
</p>

In bonus mode, the map can have exta rule:

- You can add as many `O` _(opponent)_ as you want

Map exemple :

```ber
1111111111111111111111111
1P100000000000000001001C1
101000100001100000C100001
1000001C00O1C000100000001
1011001000010000100000001
100100000000000010C000111
1C000000000000000000000E1
1111111111111111111111111
```

<p>
   <img src="https://github.com/Neress-dono/pictures/blob/72bbbd4644d61cda5fb2e63c3fa859cf2f7f00d9/commun-core_42/so_long/Screen%20Shot%202022-02-14%20at%2011.44.55%20AM.png">   
</p>

If any of these checks fail, the game must end with  `Error\n`  followed by a custom message.

## Usage

### Requirements

The function is written in C language and thus needs the  **`gcc`  compiler**  and some standard  **C libraries**  to run.

### Instructions

**1. Cloning the repositories**

```shell
git clone https://github.com/Neress-dono/Tronc-Commun_42.git 
cd Tronc-Commun_42/so_long
```

**2. Compiling the library**

~ You need to compile all source files with  `make` for play normal mode or compile all bonus source files with  `make bonus`.

**3. Launch the game**

~ To launch the game in normal mode, execute  `./so_long`  with a map as argument:  
   `./so_long maps/map.ber`
   
   or in bonus mode, execute  `./so_long_bonus`  with a map as argument:  
    `./so_long_bonus maps/map.ber`  

### How to play

-   To move, press `W` `A` `S` `D` key.
-   To quit game, press `Esc` key.

**extra command in bonus mode**:
-   To put block on map, press `↑` `←` `↓` `→` key and to remove the blocks just press these same keys.
-   To retry or to go to next level, press  `↵` key.

### Game Play

- **Game play in normal mode**:
<p>
   <img src="https://github.com/Neress-dono/pictures/blob/cace87e78622a12c9e639fefa856f1c52e8650d1/commun-core_42/so_long/Filmage_2022-02-14_131502_AdobeCreativeCloudExpress.gif">   
</p>

- **Game play in bonus mode**:
<p>
   <img src="https://github.com/Neress-dono/pictures/blob/2be68be1e22e1c66d5a9bcd53ca27b39a9762c2c/commun-core_42/so_long/Filmage_2022-02-14_133726_AdobeCreativeCloudExpress.gif">   
</p>

 ## Goals:

- Applicative

## Skills:

- Graphics  
- Imperative programming

### [Go back](https://github.com/Neress-dono/common-core_42)
