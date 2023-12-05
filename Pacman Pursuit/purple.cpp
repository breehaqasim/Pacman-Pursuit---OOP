#include "purple.hpp"
#include <iostream>

Unit purple1= {{663,249,40,38}, {258, 375, 30, 30}};
Unit purple2= {{596,250,40,37}, {258, 375 ,30, 30}};


void Purple::drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets)
{
    SDL_RenderCopy(gRnderer, assets, &purple1.srcRect, &purple1.moverRect);
    if (purple2.moverRect.x >= 899)
    {
        purple1.moverRect.x -= 2;
        if (purple1.moverRect.x == 258)
        {
            purple2.moverRect.x=258;
        }
    }
    else if (purple2.moverRect.x < 900)
    {
        purple1.moverRect.x += 2;
        if (purple1.moverRect.x==900)
        {
            purple2.moverRect.x=899;
        }
    }

}
