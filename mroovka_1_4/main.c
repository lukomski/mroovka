#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"mroovka.h"
#include"macierz.h"
#include"obsluga.h"

int main ( int argc, char* argv[] )
{
	int g, i, j, h, numer, ustaww, ustawk;
	int w = argc > 1 ? atoi ( argv[1] ) : 50;
	int k = argc > 2 ? atoi ( argv[2] ) : 50;
	int kroki = argc > 3 ? atoi ( argv[3] ) : 1000;
	int ilosc = argc > 4 ? atoi ( argv[4] ) : 5;
	macierz_t plansza = inicjuj( w, k );
	mrowka_t antek = malloc( sizeof(antek) );

	ustaww = w/(ilosc+1);
	ustawk = k/(ilosc+1);
	for ( h = 1; h < ilosc +1; h++) 
	{
	antek->x[h] = h * ustawk;
	antek->y[h] = h * ustaww;
	antek->kierunek[h] = WSCH;
	}

	//printf("\033[H\033[J");	
	//wypisz( plansza, antek, ilosc );
	//printf("%dx%d\n\n", antek->x[1], antek->y[1]);
	usleep( 100000 );

	for( g = 0; g < kroki; g++ )
	{
		
		for ( i = 1; i< ilosc+1; i++ )
		{	
		
			rozdzielenie ( antek, ilosc, i );

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
		
		if ( kroki < 1000 )
		{
			wypisz( plansza, antek, ilosc );
			printf("%c[%dm", 0x1B, 0);
			usleep( 100000 );
		}
	}
	przetworzPNG( plansza );
	zapiszPNG( "plansza.png" );
	return 0;
}
