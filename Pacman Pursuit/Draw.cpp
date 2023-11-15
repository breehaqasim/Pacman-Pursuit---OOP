#include<iostream>
#include "Draw.hpp"
#include <vector>
using namespace std;

Unit pacman = {{305,174,37,40}, {310, 174, 30, 30}};
Unit red= {{596,250,40,37}, {443, 228, 30, 30}};
Unit orange= {{353,250,41,34}, {443, 260, 30, 30}};
Unit pink= {{439,250,39,37}, {701, 328, 30, 30}};
Unit blue= {{519,250,41,37}, {701, 360, 30, 30}};
Unit dot= {{394,185,18,18}, {570, 256, 20, 20}};
// First rectangle is srcRect, second is moverRect
// these values are taken from the corresponding image in assets file
// we've used spritecow.com to find exact values of other asset images


//228+32=260

// vector<Unit> pacmans;
// vector<Unit> redenemy;
// vector<Unit> orangenemy;


void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets){

    // this function is drawing one pacman only right now
    SDL_RenderCopy(gRenderer, assets, &pacman.srcRect, &pacman.moverRect);   

    //this function is drawing red enemy
    SDL_RenderCopy(gRenderer, assets, &red.srcRect, &red.moverRect); 
    red.moverRect.y+=4; 

    //this function is drawing orange enemy
    SDL_RenderCopy(gRenderer, assets, &orange.srcRect, &orange.moverRect);  
    orange.moverRect.y+=4; 

    //this function is drawing pink enemy
    SDL_RenderCopy(gRenderer, assets, &pink.srcRect, &pink.moverRect);  
    pink.moverRect.y+=4;

    //this function is drawing blue enemy
    SDL_RenderCopy(gRenderer, assets, &blue.srcRect, &blue.moverRect);  
    blue.moverRect.y+=4;

    //this function is drawing dot 
    for (int i=0;i<4;i++)
    {
        SDL_RenderCopy(gRenderer, assets, &dot.srcRect, &dot.moverRect);
        dot.moverRect.x+=20;
    }
    // SDL_RenderCopy(gRenderer, assets, &dot.srcRect, &dot.moverRect);  
    

}

// void createObject(int x, int y){

//     // TODO: create an object randomly, and push it into corresponding vector
//     std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
// }
