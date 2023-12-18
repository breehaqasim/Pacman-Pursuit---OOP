#include "orange.hpp"
#include<iostream>
#pragma once

void Orange::drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets)
{
    SDL_RenderCopy(gRnderer, assets, &orange.srcRect, &orange.moverRect);
        if (orange2.moverRect.x >= 899)
        {
            orange.moverRect.x -= 2;
            if (orange.moverRect.x == 258)
            {
                orange2.moverRect.x=258;
            }
        }
        else if (orange2.moverRect.x < 900)
        {
            orange.moverRect.x += 2;
            if (orange.moverRect.x==900)
            {
                orange2.moverRect.x=899;
            }
        }
}

Unit& Orange :: Orangegetter()
{
        return orange;
}
