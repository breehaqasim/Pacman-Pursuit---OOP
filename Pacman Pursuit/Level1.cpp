#include <iostream>
#include "Level1.hpp"
#include <vector>
#include "SDL.h"
#pragma once
using namespace std;


void Level1::drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets,std::vector<Enemy*>& enemies, Pacman& pac,Dot& dot,Death& death)
{
    Game a;

    //drawing arrow keys to screen
    SDL_RenderCopy(gRenderer, assets, &arrow.srcRect, &arrow.moverRect);

    // this function is drawing one pacman only right now
    pac.drawPacman(gRenderer, assets);  

    //iterating over enemies to draw all of them
    for (auto enemy : enemies) {
        enemy->drawEnemy(gRenderer, assets);

        if (Red* redEnemy = dynamic_cast<Red*>(enemy)) {
            // Access the Red object and check collision
            if (pac.pacgetter().checkCollision(redEnemy->redgetter())) {
                pac.pacresetter(pac.pacgetter());
                cout<<"Red collision"<<endl;
                ++death;
                int ab =1;
                death.display();
            }
        }

        if (Blue* BlueEnemy = dynamic_cast<Blue*>(enemy)) {
            // Access the Red object and check collision
            if (pac.pacgetter().checkCollision(BlueEnemy->Bluegetter())) {
                pac.pacresetter(pac.pacgetter());
                cout<<"Blue collision"<<endl;
                ++death;
                death.display();
            }
        }

        if (Orange* OrangeEnemy = dynamic_cast<Orange*>(enemy)) {
            // Access the Red object and check collision
            if (pac.pacgetter().checkCollision(OrangeEnemy->Orangegetter())) {
                pac.pacresetter(pac.pacgetter());
                cout<<"Orange collision"<<endl;
                ++death;
                death.display();
            }
        }

        if (Pink* PinkEnemy = dynamic_cast<Pink*>(enemy)) {
            // Access the Red object and check collision
            if (pac.pacgetter().checkCollision(PinkEnemy->pinkgetter())) {
                pac.pacresetter(pac.pacgetter());
                cout<<"Pink collision"<<endl;
                ++death;
                death.display();
            }
        }

        if (Purple* PurpleEnemy = dynamic_cast<Purple*>(enemy)) {
            // Access the Red object and check collision
            if (pac.pacgetter().checkCollision(PurpleEnemy->purplegetter())) {
                pac.pacresetter(pac.pacgetter());
                cout<<"Purple collision"<<endl;
                ++death;
                death.display();
            }
        }

        string deathText = "Deaths: " + to_string(death.valueget());

        Unit pacvoid=  {{305,174,37,40}, {310, 174, 30, 30}};
        
        a.renderText(gRenderer, deathText, 500, 500);
        // a.renderText(gRenderer, deathText, 500, 500);
    }

    // this function is drawing dots right now
    dot.drawDot(gRenderer, assets, pac);
}
