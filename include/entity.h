#ifndef ENTITY_H
#define ENTITY_H value

class Entity{

	SDL_Image* image;
	SDL_Rect box;

public:
	Entity();
	~Entity();

	void draw();
	void update();
};

#endif