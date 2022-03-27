#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "Personne.h"

int main(int argc, char const *argv[])
{
	int temp = 0, temp_1 = 0;
	int exit = 0;
	int fleshYmin = 0;
	int fleshYsar = 0;
	int yejri = 0;
	int naguez = 0;
	int tal3a = 0;
	int d = 0;
	// Personne
	Personne perso;
	SDL_Rect p;
	p.x = 100;
	p.y = 100;
	initPerso(&perso);

	TTF_Font *police=NULL;
	SDL_Color policewhite= {0, 100, 0};
	SDL_Surface *texte=NULL;
	char life[50], score[50], str[100];

	SDL_Event event;

	SDL_Surface *screen = NULL;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO)!=0;
	TTF_Init();
	police=TTF_OpenFont("33713_SerpentineBoldItalic.ttf",47);
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
						case SDLK_UP:
							naguez = 1;
							tal3a = 1;
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
				deplacerPerso(&perso, 9);
				if (yejri)
		 		{
		 			perso.state = 2;
		 			deplacerPerso(&perso, 14);
		 		}
		 	}
		 	else if (fleshYsar == 1) {
		 		perso.direction = 1; // direction : left
		 		perso.state = 1; // state : walking
				deplacerPerso(&perso, -9);
				if (yejri)
				{
		 			perso.state = 2;
		 			deplacerPerso(&perso, -14);
		 		}
		 	} 
		 	else {
		 		perso.state = 0; // state : standing
		 	}

		 	int ground = 375;
		 	int jump_height = 275;
		 	if (naguez) {
		 		printf("naguez\n");
		 		perso.state = 3;
		 		if (perso.pos.y <= ground) {
		 			if (perso.pos.y < jump_height) {
		 				tal3a = 0;
		 			}
		 			printf("%d\n", tal3a);

		 			if (tal3a) {

		 				
		 				if (perso.direction == 1)
		 					perso.animation = 3-1;
		 				else 
		 					perso.animation = 5;
		 				perso.pos.y -= 10;
		 			}
		 			else 
		 			{

		 				
		 				if (perso.direction == 1)
		 					perso.animation = 5-1;
		 				else
		 					perso.animation = 3;
		 				perso.pos.y += 10;
		 			}
		 		}
		 		if (perso.pos.y > ground) {
		 			naguez = 0;
		 			perso.pos.y = ground;
		 		}
		 	}
		 
		 	animerPerso(&perso);
		 	snprintf (score, sizeof(score), "%d",perso.score);
		 	snprintf (life, sizeof(life), "%d",perso.life);
		 	strcat(str, "Life: ");
		 	strcat(str, life);
		 	strcat(str, " Score: ");
		 	strcat(str, score);
		 	texte=TTF_RenderText_Blended(police, str,policewhite);
		 	strcpy(str, "");


		 	SDL_FillRect(screen, NULL, 0xffff );
		 		int nextPart = 0;
			// if(perso.direction == -1) {
			// 	nextPart = 4;
			// }
			// printf("[ %d, %d ] \n",perso.animation,perso.state+nextPart);

		 	SDL_BlitSurface(texte, NULL, screen, &p);

		 	afficherPerso(perso, screen);
		 	SDL_Flip(screen);


		}


	}

	TTF_CloseFont(police);
	SDL_FreeSurface(texte);

	SDL_FreeSurface(screen);
	SDL_Quit();

	return 0;
}