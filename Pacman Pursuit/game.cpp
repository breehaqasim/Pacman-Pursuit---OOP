#include "game.hpp"
#include "Level1.hpp"
#include <SDL_mixer.h>
#include <vector>
#include "pacman.hpp"
#include "pink.hpp"
#include "red.hpp"
#include "purple.hpp"
#include "orange.hpp"
#include "blue.hpp"
#include "dot.hpp"
#include "music.hpp"
#include "SDL.h"
#include <SDL_ttf.h>
#include<iostream>
#pragma once

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}

	else if (TTF_Init() == -1) 
	{
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
        // Handle initialization error or return with an error code
        return 1;
    }
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "PacMan Pursuit", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
    gTexture = loadTexture("./assets/welcome.jpg");
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}


void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void Game::run( )
{
	bool quit = false;
	SDL_Event e;
	//Loading success flag
	bool success = true;
	bool mainscreen=false; //will be true when the game moves from the start screen to the main screen

	//adjusting fps
	const int targetFPS = 60;
    const int frameDelay = 1000 / targetFPS;

    Uint32 frameStart;
    int frameTime;

	//BackgroundMusic BGM("Mainbackgroundmusic.mp3");
	BackgroundMusic BGM("startupmusic.wav");
    BGM.play(-1);

	Pacman pacman;
	Pink pink;
	Purple purple;
	Red red;
	Dot dot;
	Orange orange;
	Blue blue;
	Level1 level1;
	Pacman &pacref = pacman;
	Pink &pinkref=pink;
	Dot &dotref=dot;
	Red &redref=red;
	Purple &purpleref=purple;
	Blue &blueref=blue;
	Orange &orangeref=orange;
	Death death ;
	Death &deathref= death;

	//initializing vector with enemy objects
	std::vector<Enemy*> enemies;
    enemies.push_back(&redref);
    enemies.push_back(&orangeref);
    enemies.push_back(&pinkref);
    enemies.push_back(&purpleref);
    enemies.push_back(&blueref);

	int variable=0;
	int load =1;

	while( !quit )
	{
		frameStart = SDL_GetTicks();
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				assets = loadTexture("./assets/Use Arrow Keys to Play!.png");
				gTexture = loadTexture("./assets/level1.jpeg");
				mainscreen=true;
			}
			// Handle keyboard input for moving pacman
            if (e.type == SDL_KEYDOWN) 
			{
				if (variable==0)
				{
				pacman.movePacman(e.key.keysym.sym);
				}

				else
				{
					pacman.freezepacman(e.key.keysym.sym);
				}
			}
			
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer

		//***********************draw the objects here********************

		level1.drawObjects(gRenderer, assets, enemies, pacref,dotref,deathref,mainscreen);


		if (dot.scoregetter() == 9 && dot.checkvalgetter()==1)
		{
			variable=1;
		}


		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer
		frameTime = SDL_GetTicks() - frameStart;

        // Cap the frame rate to achieve the desired fps
        if (frameDelay > frameTime) {
            //SDL_Delay(frameDelay - frameTime);
			SDL_Delay(10);
        }
	}
}

void Game::renderText(SDL_Renderer* gRenderer, const std::string& text, int x, int y)
{
    // Load a font (you need to initialize SDL_ttf before using it)
    TTF_Font* font = TTF_OpenFont("DejaVuSans-Bold.ttf", 24);
    if (!font) 
    {
        std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
        return;
    }

    // Create a surface from the text
    SDL_Color textColor = {255, 255, 255};  // White color
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    if (!textSurface) 
    {
        std::cerr << "Error creating text surface: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);  // Close the font before returning
        return;
    }

    // Create a texture from the surface
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
    if (!textTexture) 
    {
        std::cerr << "Error creating text texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);  // Free the surface before returning
        TTF_CloseFont(font);  // Close the font before returning
        return;
    }

    // Get the width and height of the text
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;

    // Set the rendering position
    SDL_Rect renderQuad = {x, y, textWidth, textHeight};

    // Render the text
    SDL_RenderCopy(gRenderer, textTexture, NULL, &renderQuad);

    // Free resources
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
}
