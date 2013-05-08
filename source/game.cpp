#include "game.h"

#include <iostream>
using namespace std;

Game::Game(){
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		cout << "SDL not initialized." << endl;
	
	if(TTF_Init() == -1)
		cout << "TTF not initialized." << endl;

	this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	SDL_WM_SetCaption("Skel",NULL);

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
