#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#define SCREEN_W 800
#define SCREEN_H 600
#define SCREEN_BPP 32


class Game{

	SDL_Surface* screen;
	SDL_Event events;

	bool running;

public:
	Game();
	~Game();
	void run();
};

#endif
