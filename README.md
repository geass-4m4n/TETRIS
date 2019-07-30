# TETRIS





## ABOUT!
The project I intend to build is the famed arcade single player game TETRIS . I intend to savor the original flavor of the game by writing it in C++ using OpenGL-GLFW library and Simple and Fast Multimedia  library . The traditional game has some bugs related to the pieces I encounter in the game and I intend to make it flawless by fixing those bugs. It will currently consist of a single level following all the constraints of the original TETRIS GAME . Further levels of varying difficulty will be added to the game after the competition. It also displays the current score of yours and high score mad till the game is running.
 
## CONTRIBUTORS
* Aman Agrawal

## ADDING REQUIRED LIBRARIES

### Add GLFW and GL library to your /usr/include folder

1. Download GLFW source files from http://www.glfw.org/download.html
2. Install Build Dependencies by running 
```sh
$ sudo apt-get install cmake xorg-dev libglu1-mesa-dev
```
3. cd in GLFW directory downloaded in step 1
4. Run the command  in terminal 
```sh
$ cmake -G "Unix Makefiles"
$ sudo make
$ sudo make install
```
### Next step is to add glad libraries
1. Copy the glad and KHR folder into /usr/include/
2. Make sure to keep glad.c in the same directory as main.cpp

### Add Simple and Fast Multimedia Library to your SYSYTEM
```sh
$ sudo apt-get install libsfml-dev
```
## IMAGES USED 
THESE ARE DOWNLOADED IMAGES USED TO MAKE GAME. These were imported to the game using Simple and Fast Multimedia Library.
the images were manipulated to form the smooth running game


![alt tag](https://github.com/geass-4m4n/TETRIS/blob/master/images/background.png)
![alt tag](https://github.com/geass-4m4n/TETRIS/blob/master/images/gameover.png)
![alt tag](https://github.com/geass-4m4n/TETRIS/blob/master/images/tiles.png)


## RUNNING CODE
1. download the project from github
2. apply the commands
```sh
$ g++ -c main.cpp
$ g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
```
3. Run the file 
```sh
$ ./a.out
```
## SCREENSHOTS
![alt tag](https://github.com/geass-4m4n/TETRIS/blob/master/screenshots/1s.png)
![alt tag](https://github.com/geass-4m4n/TETRIS/blob/master/screenshots/2s.png)



 

 






