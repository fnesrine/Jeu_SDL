#include "Personne.h"

void initPerso(Personne *p) {
	int i,j;
	// image
	p->image = IMG_Load("spritsheet-nesrine.png");

	// rect
	for (i = 0; i < 8; i++)
	{
		for(j = 0; j < 11; j++) {
			p->rect[i][j].h = 325;	
			p->rect[i][j].w = 200;
		}
	}
	for(j = 0; j < 11; j++) {
		for(i = 0; i < 8; i++) {
			p->rect[i][j].x = 200 * j;
			p->rect[i][j].y = 400 * i;
		}
	}
	// pos
	p->pos.x = 100;
	p->pos.y = 100;

	// animation
	p->animation = 0;

	// state
	p->state = 0;

	// direction
	p->direction = -1;

	// sprint
	p->sprint = 0;

}

void afficherPerso(Personne p, SDL_Surface *screen) {
	int nextPart = 0;
	if(p.direction == -1) {
		nextPart = 4;
	}
	SDL_BlitSurface(p.image, &p.rect[p.state+nextPart][p.animation], screen, &p.pos);
}

void deplacerPerso(Personne *p, int d) {
	p->pos.x = p->pos.x + d;
}

void animerPerso(Personne *p) {
	p->animation += p->direction;
	if (p->state == 0) {
		if(p->animation > 10)
			p->animation = 0;
		if(p->animation < 0)
			p->animation = 10;
	}
	else if (p->state == 1) {
		if(p->animation > 7)
			p->animation = 0;
		if(p->animation < 0)
			p->animation = 7;
	}
	else 
		if (p->state == 2) {
		if(p->animation > 5)
			p->animation = 0;
		if(p->animation < 0)
			p->animation = 5;
	}
	else { // p->state == 3
		if(p->animation > 7)
			p->animation = 0;
		if(p->animation < 0)
			p->animation = 7;
	}
}


