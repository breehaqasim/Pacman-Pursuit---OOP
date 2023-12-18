#include "purple.hpp"
#include <iostream>
#pragma once

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


Unit& Purple :: purplegetter()
    {
        return purple1;
    }
