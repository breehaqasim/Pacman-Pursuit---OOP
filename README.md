# Pacman-Pursuit---OOP

This project combines elements from Pac-Man and the World's Hardest Game implemented using SDL2 library in C++, creating an engaging and challenging gameplay experience. Players take control of the iconic Pac-Man character, navigating through dynamic maze filled with little ghosts, all while eating yellow dots and striving for victory. 
Collect all the yellow dots in level to complete the level. Players should avoid the little ghosts along the way, otherwise you will return to the starting area of that  level. If you collide with a ghost your failed attempts will get incremented.

![This is our game implementation](https://github.com/breehaqasim/Pacman-Pursuit---OOP/blob/f0d4fc84a6fd0a7063aca29e7c38f4e74f2525aa/Pacman%20Pursuit/game%20screen.jpeg)

## UML Diagram:
![This is our game UML Diagram](https://github.com/breehaqasim/Pacman-Pursuit---OOP/blob/f70dbf05a8b7113f4a77f339ce0d9778fd42179b/UML%20Diagram.jpg)

## Instructions:
Use arrow keys (UP/DOWN/LEFT/RIGHT) to guide the pac man character 
Eat all yellow dots on the screen while avoiding the chase of little ghosts

## How to build the project?
First, you have to make sure that you have installed SDL2 and SDL2-image libraries.
- Open this folder in VSCode
- Open VSCode terminal and put this command to compile everything:
	g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2 -lSDL2_mixer

- Run the game by this command:

	.\a.exe
