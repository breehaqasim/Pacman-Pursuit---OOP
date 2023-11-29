#include "pink.hpp"
#include <iostream>

Unit pink= {{439,250,39,37}, {701, 228, 30, 30}};
Unit pink2= {{439,250,39,37}, {701, 228, 30, 30}};

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
