#include "red.hpp"
#include<iostream>

// Unit red= {{596,250,40,37}, {443, 228, 30, 30}};
Unit red= {{596,250,40,37}, {258, 228, 30, 30}};


Unit red2= {{596,250,40,37}, {258, 228, 30, 30}};

void Red::drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets)
{

    bool flag = false;
    SDL_RenderCopy(gRnderer, assets, &red.srcRect, &red.moverRect);

    // std::cout<<red.moverRect.x<<std::endl;


        if (red2.moverRect.x >= 899)
        {
            // SDL_RenderCopy(gRnderer, assets, &red.srcRect, &red.moverRect);
            red.moverRect.x -= 2;
            std::cout<<red.moverRect.x<<"check"<<std::endl;


            if (red.moverRect.x == 258)
            {
                red2.moverRect.x=258;
            }


        }
        else if (red2.moverRect.x < 900)
        {
            //SDL_RenderCopy(gRnderer, assets, &red.srcRect, &red.moverRect);
            red.moverRect.x += 2;
            std::cout<<red.moverRect.x<<"check"<<std::endl;

            if (red.moverRect.x==900)
            {
                red2.moverRect.x=899;
            }

        }

    // Draw the enemy
    // SDL_RenderCopy(gRnderer, assets, &red.srcRect, &red.moverRect);


    // Update the screen
    // SDL_RenderPresent(gRnderer);


}
