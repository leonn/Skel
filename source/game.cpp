#include "game.h"
#include "util.h"
#include <iostream>
#include <string>
#include "text.h"

#include <iostream>
using namespace std;

Game::Game(){
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		cout << "SDL not initialized." << endl;
	
	if(TTF_Init() == -1)
		cout << "TTF not initialized." << endl;
 	
	this->window = SDL_CreateWindow("Skel", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);//SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
	this->screen = SDL_GetWindowSurface(window);
	TTF_Init();
	this->running = true;
}

Game::~Game(){
	SDL_FreeSurface(this->screen);
	TTF_Quit();
	SDL_Quit();
}

void Game::run(){

	//Initializing timer
	this->delta.start();
	
	while(this->running){

		this->start = SDL_GetTicks();
		//Events
		while(SDL_PollEvent(&this->events)){
			switch(this->events.type){
				case SDL_QUIT:
					this->running = false;
				break;
				case SDL_KEYDOWN:
                    switch (events.key.keysym.sym) {
                    	case SDLK_ESCAPE:
                        	this->running = false;
                        break;
                        default:;
                    }
			}
		}
		//Logic
		
		this->delta.start(); // Reinicializing the timer
		//Render
		SDL_RenderPresent(renderer);
		
		//FPS control
		if(1000/FPS > SDL_GetTicks() - this->start)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - this->start));
	}
}
