[5:15 PM, 11/24/2023] Breeha: #include<SDL.h>
#include <SDL_mixer.h>
#pragma once

class Level1
{
    public:
        void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
};
[5:17 PM, 11/24/2023] Breeha: #include<iostream>
#include "Level1.hpp"
#include <vector>
#include "SDL.h"
#include "pacman.hpp"
#include "red.hpp"

using namespace std;

// Unit p = {{305,174,37,40}, {310, 174, 30, 30}};
// Unit red= {{596,250,40,37}, {443, 228, 30, 30}};
Unit orange= {{353,250,41,34}, {443, 260, 30, 30}};
Unit pink= {{439,250,39,37}, {701, 328, 30, 30}};
Unit blue= {{519,250,41,37}, {701, 360, 30, 30}};

Unit dot1= {{394,185,18,18}, {570, 256, 20, 20}};
Unit dot2= {{394,185,18,18}, {599, 256, 20, 20}};
Unit dot3= {{394,185,18,18}, {627, 256, 20, 20}};
Unit dot4= {{394,185,18,18}, {656, 256, 20, 20}};

Unit dot5= {{394,185,18,18}, {277, 325, 20, 20}};
Unit dot6= {{394,185,18,18}, {314, 325, 20, 20}};
Unit dot7= {{394,185,18,18}, {277, 359, 20, 20}};
Unit dot8= {{394,185,18,18}, {314, 359, 20, 20}};

Unit dot9= {{394,185,18,18}, {588, 359, 20, 20}};
// First rectangle is srcRect, second is moverRect
// these values are taken from the corresponding image in assets file
// we've used spritecow.com to find exact values of other asset images


void Level1::drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets){

    // // this function is drawing one pacman only right now
    // SDL_RenderCopy(gRenderer, assets, &p.srcRect, &p.moverRect); 

    Pacman pac;
    pac.drawPacman(gRenderer, assets);  

    //this function is drawing red enemy
    // SDL_RenderCopy(gRenderer, assets, &red.srcRect, &red.moverRect); 
    // red.moverRect.y+=1; 

    Red red;
    red.drawEnemy(gRenderer, assets);

    //this function is drawing orange enemy
    SDL_RenderCopy(gRenderer, assets, &orange.srcRect, &orange.moverRect);  
    orange.moverRect.y+=1; 

    //this function is drawing pink enemy
    SDL_RenderCopy(gRenderer, assets, &pink.srcRect, &pink.moverRect);  
    pink.moverRect.y+=1;

    //this function is drawing blue enemy
    SDL_RenderCopy(gRenderer, assets, &blue.srcRect, &blue.moverRect);  
    blue.moverRect.y+=1;

    //this function is drawing dots
    SDL_RenderCopy(gRenderer, assets, &dot1.srcRect, &dot1.moverRect);
    SDL_RenderCopy(gRenderer, assets, &dot2.srcRect, &dot2.moverRect);
    SDL_RenderCopy(gRenderer, assets, &dot3.srcRect, &dot3.moverRect);
    SDL_RenderCopy(gRenderer, assets, &dot4.srcRect, &dot4.moverRect);

    SDL_RenderCopy(gRenderer, assets, &dot5.srcRect, &dot5.moverRect);
    SDL_RenderCopy(gRenderer, assets, &dot6.srcRect, &dot6.moverRect);
    SDL_RenderCopy(gRenderer, assets, &dot7.srcRect, &dot7.moverRect);
    SDL_RenderCopy(gRenderer, assets, &dot8.srcRect, &dot8.moverRect);

    SDL_RenderCopy(gRenderer, assets, &dot9.srcRect, &dot9.moverRect);

}
