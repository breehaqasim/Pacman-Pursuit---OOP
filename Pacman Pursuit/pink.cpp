#include "pink.hpp"
#include <iostream>
#pragma once

void Pink::drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets)
{
    SDL_RenderCopy(gRnderer, assets, &pink.srcRect, &pink.moverRect);
    if (pink2.moverRect.y >= 382)
    {
        pink.moverRect.y -= 2;
        if (pink.moverRect.y == 228)
        {
            pink2.moverRect.y =228;
        }
    }
    else if (pink2.moverRect.y < 383 )
    {
        pink.moverRect.y += 2;
        if (pink.moverRect.y == 382)
        {
            pink2.moverRect.y=382;
        }
    }
}

Unit& Pink :: pinkgetter()
    {
        return pink;
    }
