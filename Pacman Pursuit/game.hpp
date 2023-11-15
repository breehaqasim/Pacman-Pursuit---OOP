#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1179; //1000
    const int SCREEN_HEIGHT = 657; //600


    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;

    //SDL_Texture* GTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;

    // Mix_Music* gMusic = NULL;
    

public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    //void music(); // plays the music if it is not already playing
};

