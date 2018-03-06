#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"mroovka.h"
#include"macierz.h"
#include"obsluga.h"

int main ( int argc, char* argv[] )
{
	int g, i, numer;
	int w = argc > 1 ? atoi ( argv[1] ) : 50;
	int k = argc > 2 ? atoi ( argv[2] ) : 50;
	int kroki = argc > 3 ? atoi ( argv[3] ) : 1000;
	int ilosc = argc > 4 ? atoi ( argv[3] ) : 3;
	macierz_t plansza = inicjuj( w, k );
	mrowka_t antek = malloc( sizeof(antek) );
	antek->x[1] = k/2;
	antek->y[1] = w/2;

	antek->x[2] = (k/2) + 10;
        antek->y[2] = (w/2) + 10;

        antek->x[3] = (k/2) - 10;
        antek->y[3] = (w/2) - 10;

	antek->kierunek[1] = WSCH;
	antek->kierunek[2] = WSCH;
	antek->kierunek[3] = WSCH;


	printf("\033[H\033[J");	
	wypisz( plansza, antek );
	printf("%dx%d\n\n", antek->x[1], antek->y[1]);
	usleep( 100000 );

	for( g = 0; g < kroki; g++ )
	{
		for ( i = 1; i< ilosc+1; i++ )
		{
			numer = plansza->wart[antek->y[i]][antek->x[i]];
			printf("\033[H\033[J");
			if ( numer != i )
        	        {
				plansza->wart[antek -> y[i] ][ antek -> x[i] ] = i;
        	                ruch( antek, numer, plansza, i );
              	 	 }
               	 	else if ( numer == i )
               	 	{
				plansza->wart[antek -> y[i] ][ antek -> x[i] ] = 0;
               		        ruch( antek, i, plansza, i );
        	       	}

		}

		wypisz( plansza, antek );
		printf("%d: %dx%d\n\n", g+1, antek->x[1], antek->y[1]);
		 usleep( 50000 );
	}
	return 0;
}
