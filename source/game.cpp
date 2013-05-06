#include "game.h"

//TESTE
#include "gui.h"

Game::Game(){
	SDL_Init(SDL_INIT_EVERYTHING);
	this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	SDL_WM_SetCaption("Skel",NULL);

	this->running = true;
}

Game::~Game(){
	SDL_FreeSurface(this->screen);
}

void Game::run(){
	//BLOCO DE TESTE de renderização de texto

	Gui* gui;
	gui = new Gui();

	//FIM DO BLOCO DE TESTE

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
		gui->update();//teste
		//Render
		gui->draw();//teste
		//FPS control
	}
}