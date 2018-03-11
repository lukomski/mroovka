#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"mroovka.h"
#include"macierz.h"
#include"obsluga.h"

int main ( int argc, char* argv[] )
{
	FILE * in = fopen ( "konffig.txt", "r" );
	if ( in == NULL ) {
        printf ("\nBrak pliku konfiguracyjnego.\n");
        }
	else
	{ 
	char* buff = malloc (sizeof(buff));
	char** konfig = malloc (8* sizeof(konfig));
	int m =0;

	while ( fscanf (in, "%s", buff) != EOF) 
		{
		konfig[m] = buff;
		printf ( "WYRAZ %d -> %s \n", m++, buff );
		}
	
	fclose (in);	
	}

	usleep (5000000);	

	int g, i, j, h, numer, ustaww, ustawk;


	int w = argc > 1 ? atoi ( argv[1] ) : 25;
	int k = argc > 2 ? atoi ( argv[2] ) : 25;
	int kroki = argc > 3 ? atoi ( argv[3] ) : 100;
	int ilosc = argc > 4 ? atoi ( argv[4] ) : 3;
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

	printf("\033[H\033[J");	
	wypisz( plansza, antek, ilosc );
	printf("%dx%d\n\n", antek->x[1], antek->y[1]);
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
		

		wypisz( plansza, antek, ilosc );
		
		printf("Krok: %d\n", g+1);
		for ( j = 1; j< ilosc+1; j++ )
		{
			printf("\x1B[37m Mrowka nr %d: %dx%d\n", j, antek->x[j], antek->y[j]);
		}
//		if (g > 965 )
//			usleep( 1000000 );
//		else
			usleep( 10000 );
	}
	return 0;
}
