#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Personne.h"

int main(int argc, char const *argv[])
{
	int temp = 0, temp_1 = 0;
	int exit = 0;
	int fleshYmin = 0;
	int fleshYsar = 0;
	int yejri = 0;
	int d = 0;
	// Personne
	Personne perso;
	initPerso(&perso);

	SDL_Event event;

	SDL_Surface *screen = NULL;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO)!=0;
	screen = SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	while(!exit) {
		if(SDL_PollEvent(&event))
			switch(event.type) {
				case SDL_QUIT:
					exit = 1;
					break;

				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						case SDLK_RIGHT:
							fleshYmin = 1;
							break;
						case SDLK_LEFT:
							fleshYsar = 1;
							break;
						case SDLK_s:
							yejri = 1;
							break;
					}	
					break;
				case SDL_KEYUP:
					switch (event.key.keysym.sym) {
						case SDLK_RIGHT:
							fleshYmin = 0;
							break;
						case SDLK_LEFT:
							fleshYsar = 0;
							break;
						case SDLK_s:
							yejri = 0;
							break;
					}
					break;	
			}
		temp = SDL_GetTicks();
		if ( temp - temp_1 >= 100)
		{
			d = 0;
		 	temp_1 = temp; 
		 	if(fleshYmin == 1) {
		 		perso.direction = -1; // direction : right
				perso.state = 1; // state : walking 
				deplacerPerso(&perso, 10); 
		 	}
		 	else if (fleshYsar == 1) {
		 		perso.direction = 1; // direction : left
		 		perso.state = 1; // state : walking
				deplacerPerso(&perso, -10);
		 	} 
		 	else {
		 		perso.state = 0; // state : standing
		 	}
		 	if (yejri) {
		 		perso.state = 2;
		 	}

		 	animerPerso(&perso);

		 	SDL_FillRect(screen, NULL, 0x0 );
		 		int nextPart = 0;
			// if(perso.direction == -1) {
			// 	nextPart = 4;
			// }
			// printf("[ %d, %d ] \n",perso.animation,perso.state+nextPart);

		 	afficherPerso(perso, screen);
		 	SDL_Flip(screen);

		}


	}

	SDL_FreeSurface(screen);
	SDL_Quit();

	return 0;
}