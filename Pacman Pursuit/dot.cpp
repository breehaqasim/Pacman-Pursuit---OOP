#include "dot.hpp"
#include<iostream>
#include <SDL.h>
#include "pacman.hpp"
#include "SDL.h"
#include <SDL_ttf.h>
#pragma once

Dot::Dot() 
{
    initializeDots();
}

void Dot::initializeDots() 
{
    // Initialize dot positions
    dots = 
    {
        {{394, 185, 18, 18}, {570, 256, 20, 20}},
        {{394, 185, 18, 18}, {599, 256, 20, 20}},
        {{394, 185, 18, 18}, {627, 256, 20, 20}},
        {{394, 185, 18, 18}, {656, 256, 20, 20}},
        {{394, 185, 18, 18}, {277, 325, 20, 20}},
        {{394, 185, 18, 18}, {314, 325, 20, 20}},
        {{394, 185, 18, 18}, {277, 359, 20, 20}},
        {{394, 185, 18, 18}, {314, 359, 20, 20}},
        {{394, 185, 18, 18}, {588, 359, 20, 20}},
    };
}

int Dot::drawDot(SDL_Renderer* gRnderer, SDL_Texture* assets, Pacman& pac) 
{
    for (auto& dot : dots) {
        SDL_RenderCopy(gRnderer, assets, &dot.srcRect, &dot.moverRect);

        if (pac.pacgetter().checkCollision(dot)) {
            dot = {{0, 0, 0, 0}, {0, 0, 0, 0}};
            score += 1;
            std::cout << "Score is " << score << std::endl;
        }

        // int x= 1179 / 2;
        int x= 860/2;
        int y = 600 / 2;
        Game a;

        if(flag!=true)
        {
            if (pac.pacgetter().moverRect.x > 788 && pac.pacgetter().moverRect.y > 420)
                if(score == 9)
                {
                    flag=true;
                    checkval=1;
                    // std::cout<<"You won"<<std::endl;
                    a.renderText(gRnderer, "Game Over. You won!", x, y);
                    
                    // SDL_Event e;
                    // pac.freezepacman(e.key.keysym.sym);
                }
        }

        if(score==9 && flag==true)
        {
            a.renderText(gRnderer, "Game Over. You won!", x, y);
        }
    }
    return 1;
}

int Dot:: scoregetter()
{
    return score;
}

int Dot :: checkvalgetter()
{
    return checkval;
}
