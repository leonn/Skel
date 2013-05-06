#ifndef GUI_H
#define GUI_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

#define SOLID 1
#define SHADED 2
#define BLENDED 3

class Gui{

	TTF_Font* font;

	SDL_Surface* image;
	SDL_Color color;
	SDL_Color shadedColor;

	SDL_Rect box;

	char* text;
	
	int fontsize;

	int renderType;

public:
	Gui();
	~Gui();

	void draw();
	void update();

	void setText(char* _text);
	void setColor(int r, int g, int b);
	void setShadedColor(int r, int g, int b);
	void setFontSize(int size);
	void setRenderType(int _renderType);

};

#endif