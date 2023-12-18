#include "blue.hpp"
#include <iostream>
#pragma once

void Blue::drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets)
{
    SDL_RenderCopy(gRnderer, assets, &blue.srcRect, &blue.moverRect);
    if (blue2.moverRect.y >= 382)
    {
        blue.moverRect.y -= 2;

        if (blue.moverRect.y == 228)
        {
            blue2.moverRect.y =228;
        }
    }
    else if (blue2.moverRect.y < 383 )
    {
        blue.moverRect.y += 2;
        if (blue.moverRect.y == 382)
        {
            blue2.moverRect.y=382;
        }
    }
}


Unit& Blue :: Bluegetter()
{
        return blue;
}
