prog:main.o Personne.o
	gcc main.o Personne.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
Personne.o:Personne.c
	gcc -c Personne.c -g

