#include "game.h"

Game::Game(){
	SDL_Init(SDL_INIT_EVERYTHING);
	this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	SDL_WM_SetCaption("ClickColor",NULL);

	this->running = true;
}

Game::~Game(){
	SDL_FreeSurface(this->screen);
}

void Game::run(){
	while(this->running){
		//Events
		while(SDL_PollEvent(&this->events)){
			switch(this->events.type){
				case SDL_QUIT:
					this->running = false;
				break;
			}
		}
		//Logic

		//Render

		//FPS control
	}
}