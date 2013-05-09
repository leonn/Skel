#include "game.h"
#include "util.h"
#include <iostream>
#include <string>
//TESTE
#include "gui.h"
#include "SDL/SDL_ttf.h"


using namespace std;

#include <iostream>
using namespace std;

Game::Game(){
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		cout << "SDL not initialized." << endl;
	
	if(TTF_Init() == -1)
		cout << "TTF not initialized." << endl;

	this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	SDL_WM_SetCaption("Skel",NULL);
<<<<<<< HEAD

	TTF_Init();
=======
>>>>>>> 8a5dc4fa1295ec2338ec9838a39721a9403158a0

	this->running = true;
}

Game::~Game(){
	SDL_FreeSurface(this->screen);
<<<<<<< HEAD

=======
>>>>>>> 8a5dc4fa1295ec2338ec9838a39721a9403158a0
	TTF_Quit();
	SDL_Quit();
}

void Game::run(){
	//BLOCO DE TESTE de renderização de texto

	Gui* gui;
	// gui = new Gui();
	gui = new Gui("texto",40);

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
		gui->draw();

		SDL_Flip(screen);
		//FPS control
	}
}
