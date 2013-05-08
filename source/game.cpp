#include "game.h"
#include "util.h"
#include <iostream>
#include <string>
//TESTE
#include "gui.h"
#include "SDL/SDL_ttf.h"


using namespace std;

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

	// Gui* gui;
	// gui = new Gui();
	string text = "texto";
	cout << text << endl;
	SDL_Surface* textSurface;
	SDL_Rect box;
	box.x = 100;
	box.y = 100;
	box.w = 200;
	box.h = 100;
	SDL_Color _color = {0,0,0};
	TTF_Font* font = TTF_OpenFont("UbuntuMono-B.ttf",20);
	if (font == NULL)
		cout << "failed" << endl;
	textSurface = TTF_RenderText_Solid(font,text.c_str(),_color);
	// textSurface = carregaImagem("data/botao_sair.png");
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
		// gui->update();//teste
		//Render
		SDL_BlitSurface(textSurface,NULL,SDL_GetVideoSurface(),&box);
		SDL_Flip(screen);
		//FPS control
	}
}