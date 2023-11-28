#include "orange.hpp"
#include<iostream>

Unit orange= {{353,250,41,34}, {258, 269, 30, 30}};
Unit orange2= {{353,250,41,34}, {258, 269, 30, 30}};

void Orange::drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets)
{

    bool flag = false;
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
