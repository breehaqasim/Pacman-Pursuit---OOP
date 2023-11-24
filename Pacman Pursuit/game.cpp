#include "game.hpp"
#include "Level1.hpp"
#include <SDL_mixer.h>
#include "pacman.hpp"


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

	// gMusic = Mix_LoadMUS("./music/startup music.wav");
	// if (gMusic == NULL)
	// {
	// 	printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	// 	success = false;
	// }
	// return success;
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
	// Mix_FreeMusic(gMusic);
	// gMusic = NULL;
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

	//adjusting fps
	const int targetFPS = 60;
    const int frameDelay = 1000 / targetFPS;

    Uint32 frameStart;
    int frameTime;

	Pacman pacman;
	Level1 level1;


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
				assets = loadTexture("./assets/elements.png");
				gTexture = loadTexture("./assets/level1.jpeg");
				// if(assets==NULL || GTexture==NULL)
				// {
				// 	printf("Unable to run due to error: %s\n",SDL_GetError());
				// 	//success =false;
				// }
				//return success;
			}
			// Handle keyboard input for moving pacman
            if (e.type == SDL_KEYDOWN) {
				pacman.movePacman(e.key.keysym.sym);
            }
			// if( Mix_PlayingMusic() == 0 ) // Tells you if music is actively playing,
			// {
			// 	//Play the music
			// 	Mix_PlayMusic( gMusic, 2 );
			// }
			
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		level1.drawObjects(gRenderer, assets);
	
		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer
		frameTime = SDL_GetTicks() - frameStart;

        // Cap the frame rate to achieve the desired fps
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
		// SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds

	}
	
}
