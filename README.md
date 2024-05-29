# 🎮 Pacman Pursuit - OOP

"Pacman Pursuit" is an engaging and challenging game that infuses elements from the classic Pac-Man game with the dynamic challenges of the World's Hardest Game. Developed using the SDL2 library in C++, this project offers a nostalgic yet fresh gameplay experience. Control the iconic Pac-Man, navigate through intricately designed mazes, avoid the pesky ghosts, and collect all the yellow dots to advance through levels.

## 📸 Game Screenshot
![Pacman Pursuit Gameplay](https://github.com/breehaqasim/Pacman-Pursuit---OOP/blob/f0d4fc84a6fd0a7063aca29e7c38f4e74f2525aa/Pacman%20Pursuit/game%20screen.jpeg)

## 📊 UML Diagram
Here's a look at our project's architecture:
![Pacman Pursuit UML Diagram](https://github.com/breehaqasim/Pacman-Pursuit---OOP/blob/c102de98dc87406fda6970f8c4a233391493e02c/UML%20Diagram.jpg)

## 🎮 How to Play
- Use the **arrow keys (UP/DOWN/LEFT/RIGHT)** to navigate Pac-Man through the maze.
- Aim to eat all the yellow dots on each level while avoiding collisions with the ghosts.
- Each collision with a ghost sends Pac-Man back to the starting area of the level and increments your failed attempts counter.

## 🔧 How to Build the Project
Ensure you have the SDL2 and SDL2-image libraries installed on your system. Follow these steps to compile and run the game on your local machine:

1. **Open the project folder in VSCode.**
2. **Compile the game using the following command in the VSCode terminal:**
   ```bash
   g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
2. **Run the game**
   ```bash
.\a.exe
