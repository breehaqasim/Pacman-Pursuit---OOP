#include "pacman.hpp"

Unit p = {{305,174,37,40}, {310, 174, 30, 30}};

void Pacman::movePacman(SDL_Keycode key) {
    if (key == SDLK_UP) {

        if (((p.moverRect.x > 247 && p.moverRect.x < 398) && (p.moverRect.y < 124))||((p.moverRect.x > 360 && p.moverRect.x < 930) && (p.moverRect.y < 225))) {
            
        }
        else {
            p.moverRect.y -= 4;
        }    

    } 
    else if (key == SDLK_DOWN) {

        if (((p.moverRect.x > 247 && p.moverRect.x < 788) && (p.moverRect.y > 372)) || ((p.moverRect.x > 788 && p.moverRect.x < 930) && (p.moverRect.y > 474))) {

        }
        else {
            p.moverRect.y += 4;
        }
        
    } else if (key == SDLK_RIGHT) {
        if ((p.moverRect.y > 113 && p.moverRect.y < 214) && (p.moverRect.x > 360) || (p.moverRect.y > 214 && p.moverRect.y < 506) && (p.moverRect.x > 900)) {
            
        }
        else {
            p.moverRect.x += 4;
        }
        
    } else if (key == SDLK_LEFT) {
        if ((p.moverRect.y > 113 && p.moverRect.y < 404) && (p.moverRect.x < 258) || (p.moverRect.y > 404 && p.moverRect.y < 506) && (p.moverRect.x < 799)) {
            
        }
        else {
            p.moverRect.x -= 4;
        }
        
    }
}

void Pacman::drawPacman(SDL_Renderer* gRnderer, SDL_Texture* assets)
{
    // this function is drawing one pacman only right now
    SDL_RenderCopy(gRnderer, assets, &p.srcRect, &p.moverRect);  
}
