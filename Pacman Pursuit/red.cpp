#include "red.hpp"
#include <iostream>
#pragma once

void Red::drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets)
{
    SDL_RenderCopy(gRnderer, assets, &red.srcRect, &red.moverRect);
        if (red2.moverRect.x >= 899)
        {
            red.moverRect.x -= 2;
            if (red.moverRect.x == 258)
            {
                red2.moverRect.x=258;
            }
        }
        else if (red2.moverRect.x < 900)
        {
            red.moverRect.x += 2;
            if (red.moverRect.x==900)
            {
                red2.moverRect.x=899;
            }
        }
}

Unit& Red :: redgetter()
{
        return red;
}
