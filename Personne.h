#ifndef PERSONNE_H
#define PERSONNE_H value

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
	SDL_Surface *image;
	SDL_Rect rect[8][11];
	SDL_Rect pos;
	int animation;
	int direction; // -1 : right, 1 : left
	int state; // 0 : standing, 1 : walking, 2 : sprintion, 3 : jumping
	int sprint;
} Personne;

void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface *screen);
void deplacerPerso(Personne *p, int d);
void animerPerso(Personne *p);

#endif