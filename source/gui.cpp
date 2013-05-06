#include "gui.h"
#include <iostream>

using namespace std;

Gui::Gui(){

//TODO: Valores entrados pelo usuário
//TODO: Criar contrutor genérico e construtor do usuário
//TESTE
	this->box.x = 100;
	this->box.y = 100;
	this->box.w = 200;
	this->box.h = 100;
	this->fontsize = 12;
	this->color = {255,255,255,0};
	this->text = "teste";
	this->font = TTF_OpenFont("data/Arista.ttf",fontsize);
//FIM TESTE

	

	this->renderType = SOLID;
}

Gui::~Gui(){
	TTF_CloseFont(this->font);
}

void Gui::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
}

void Gui::update(){
	switch(this->renderType){
		case SOLID:
			this->image = TTF_RenderText_Solid(this->font,this->text,this->color);
		break;
		case SHADED:
			this->image = TTF_RenderText_Shaded(this->font,this->text,this->color,this->shadedColor);
		break;
		case BLENDED:
			this->image = TTF_RenderText_Blended(this->font,this->text,this->color);
		break;
	}
}

// void Gui::setText(char* _text){
// 	this->text = _text;
// }

// void Gui::setColor(int r, int g, int b){
// 	this->color = {r,g,b,0};
// }

// void Gui::setShadedColor(int r, int g, int b){
// 	this->shadedColor = {r,g,b,0};	
// }

// void Gui::setFontSize(int size){
// 	this->fontsize = size;
// }

// void Gui::setRenderType(int _renderType){
// 	switch(_renderType){
// 		case SOLID:
// 			this->renderType = SOLID;
// 		break;
// 		case SHADED:
// 			this->renderType = SHADED;
// 		break;
// 		case BLENDED:
// 			this->renderType = BLENDED;
// 		break;
// 		default:
// 			cout << "Error: unknow render type." << endl;

// 	}
// }