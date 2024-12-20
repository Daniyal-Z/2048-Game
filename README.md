
# PROJECT - 2048 Game



## Project Members:
Ahmed Salman (23L - 0678)

Muhammad Daniyal Zaidi (23L - 0718)

## Game's Introduction:
In 2048, players would be maneuvering through Numbered Tiles by reaching a specific numbered value each time there's a matching Tile.

## Background:
The game was written by: an Italian web developer Gabriele Cirulli. The game is based on a 4x4 Grid which moves when the player slides them using one of the four arrow keys “up”, “down”, “left” and “right”. The game can be achieved through multiple concepts, one of them being: won when a tile with a value of 2048 appears on the board, when the player merges two 1024 tiles, and one that continues till maximum number of iterations has been reached, and there are no more moves left.

## Game Mechanics: 

## PART 1: The structure and logic
The Grid Structure: 
Our table is divided into a 4x4 Grid with each box 150.0f pixels x 150.0f pixels. (Screen size can be altered but it doesn’t correlate our box size)
Number - Combining:
The numbers distributed across the grid may only be 2s and 4s at first, and multiples of 2 as the game progresses. Once the tile goes through the conjugate numbered till, it will be added to their initial number (i.e or multiplied by 2).



Movement:
The Player makes a move by either of the four arrow keys: four arrow keys “up”, “down”, “left” and “right”. The tiles get merged with the available tile if there isn’t a wall or an occupied tile with a different value.

Tile Spawning:
A random tile is spawned after every move, the tile can only be a 2 or a 4.

Scoring:
He we calculate the total score by summing all the numbered tiles available at the board. The concept of filing is implemented as we record the high-scores and total scores of all players.

Error Handling:
Error handling is taken care of incase any file, object or texture is not loaded properly.


## PART 2: The Interface - GUI
The Grid Structure: 
Our table is divided into a 4x4 Grid of 600.0f x 600.0f pixels. (Screen size can be altered but it doesn’t correlate to our box size)

Graphics:
	Shapes such as RectangleShape have been used to form the grid. Each box                            
         containing 150.0f x 150.0f pixels.

Textures and Sprites:
Images of box and background is used to provide a better and appealing interface to the player.

Audio and Background Animation:
Music playback is included in some parts of the game to make it more attractive.


Font Rendering:
Fonts are be loaded within the textures and the drawn shapes.
## COLORS USED:

| Color             | Hex                                                                |
| ----------------- | ------------------------------------------------------------------ |
| Tile 2 | ![#48c9af](https://via.placeholder.com/10/48c9af?text=+) #48c9af |
| Tile 4| ![#58d68d](https://via.placeholder.com/10/58d68d?text=+) #58d68d |
| Tile 8 | ![#f4d03f](https://via.placeholder.com/10/f4d03f?text=+) #f4d03f |
| Tile 16  | ![#dc7633](https://via.placeholder.com/10/dc7633?text=+) #dc7633 |
| Tile 32 | ![#0e6654](https://via.placeholder.com/10/0e6654?text=+) #0e6654 |
| Tile 64 | ![#1a52b9](https://via.placeholder.com/10/1a52b9?text=+) #1a52b9 |
| Tile 128| ![#99a3a4](https://via.placeholder.com/10/99a3a4?text=+) #99a3a4|
| Tile 256 | ![#00d1a0](https://via.placeholder.com/10/00b48a?text=+) #00d1a0 |
| Tile 512| ![#f9e7a0](https://via.placeholder.com/10/f9e7a0?text=+) #f9e7a0 |
| Tile 1024  | ![#ffd814](https://via.placeholder.com/10/ffd814?text=+)#ffd814 |
| Tile 2048 | ![#f39d12](https://via.placeholder.com/10/f39d12?text=+) #f39d12 |



## Methodology/Implementation:


The portion of methodology and Implementation are divided into following sections:


Compiler Used: The project code is compiled and run on the compiler named as Visual Studio 2022


Programming Tools: The programming tools which are to be used in the project code are as follows:

- Functions

- Built-in libraries (includes cmath, ctime etc.)

- File Handling

- Conditional Statements (which includes if-else & switch case)

- Loops (includes For loop , While loop & do-while loop)

- 1-D/2-D Array
                                                                                                                                         
- SFML Library (audio and graphics)
## Screenshots
Head over to the dropdown at Code and download the ZIP file.
![image](https://github.com/Daniyal-Z/2048-Game/assets/62768256/16bef101-acd1-418c-befe-bf2df7cb0325)


Now save the file at your desired location.
![image](https://github.com/Daniyal-Z/2048-Game/assets/62768256/0c789be1-0432-427a-ba1e-d83957ae27be)


Extract the files from the zipped folder.
![image](https://github.com/Daniyal-Z/2048-Game/assets/62768256/c1f4df19-f8a7-41f3-b089-d1c19336211a)


Open the unzipped folder and extract the main file.
![image](https://github.com/Daniyal-Z/2048-Game/assets/62768256/cc9d79d5-1a83-4be2-8b76-955ddec62593)


Search for the "2048.exe" file and run it.
![image](https://github.com/Daniyal-Z/2048-Game/assets/62768256/844db4a3-a089-449f-a0da-289d8d6e0062)


Main Screen:
![image](https://github.com/Daniyal-Z/2048-Game/assets/62768256/fd24a660-4cc4-41e6-bb9f-5ee5009be003)


After pressing P:
![image](https://github.com/Daniyal-Z/2048-Game/assets/62768256/2d5596a5-d22b-4aa7-b3af-0930f84e420c)




## Authors


- [@Ahmed Salman](https://www.github.com/ahmedsaalman)
- [@Daniyal Zaidi](https://www.github.com/Daniyal-Z)

