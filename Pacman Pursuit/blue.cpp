#include "blue.hpp"
#include <iostream>

Unit blue= {{519,250,41,37}, {400, 228, 30, 30}};

Unit blue2= {{519,250,41,37}, {400, 228, 30, 30}};

void Blue::drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets)
{
    // bool flag = false;
    SDL_RenderCopy(gRnderer, assets, &blue.srcRect, &blue.moverRect);
    // std::cout<<red.moverRect.x<<std::endl;


        if (blue2.moverRect.y >= 382)
        {
            // SDL_RenderCopy(gRnderer, assets, &red.srcRect, &red.moverRect);
            blue.moverRect.y -= 2;
            // std::cout<<red.moverRect.x<<"check"<<std::endl;

            if (blue.moverRect.y == 228)
            {
                blue2.moverRect.y =228;
            }
        }
        else if (blue2.moverRect.y < 383 )
        {
            //SDL_RenderCopy(gRnderer, assets, &red.srcRect, &red.moverRect);
            blue.moverRect.y += 2;
            // std::cout<<blue.moverRect.y<<std::endl;
            // std::cout<<red.moverRect.x<<"check"<<std::endl;
            if (blue.moverRect.y == 382)
            {
                blue2.moverRect.y=382;
                // std::cout<<blue.moverRect.y<<std::endl;
            }
        }
}
