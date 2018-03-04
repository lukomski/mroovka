#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"mroovka.h"
#include"macierz.h"
#include"obsluga.h"

int main ( int argc, char* argv[] )
{
	int g;
	int w = argc > 1 ? atoi ( argv[1] ) : 50;
	int k = argc > 2 ? atoi ( argv[2] ) : 50;
	int kroki = argc > 3 ? atoi ( argv[3] ) : 1000;
	macierz_t plansza = inicjuj( w, k );
	mrowka_t antek = malloc( sizeof(antek) );
	antek->x = k/2;
	antek->y = w/2;
	antek->kierunek = WSCH;

	printf("\033[H\033[J");	
	wypisz( plansza, antek );
	printf("%dx%d\n\n", antek->x, antek->y);
	usleep( 100000 );

	for( g = 0; g < kroki; g++ )
	{
		printf("\033[H\033[J");



	/*	for ( i = 0; i < plansza->wiersze; i++ )
		{
			for ( j = 0; j < plansza->kolumny; j++ )
			{
				if ( j == antek->x && i == antek->y )
				{
					if ( plansza->wart[i][j] == 0 )
					{
						ruch( antek, 0 );
						plansza->wart[i][j] = 1;
					}
					else if ( plansza->wart[i][j] == 1 )
					{
						ruch( antek, 1 );
						plansza->wart[i][j] = 0;
					}
					stop = 1;
					odbicie( antek, plansza);
					break;
				}
			}
			if ( stop == 1 )
			{
				stop = 0;
				break;
			}
		}
	*/
		
					if ( plansza->wart[antek->y][antek->x] == 0 )
                                        {
						plansza->wart[antek->y][antek->x] = 1;
                                                ruch( antek, 0 );
                                        }
                                        else if ( plansza->wart[antek->y][antek->x] == 1 )
                                        {
						plansza->wart[antek->y][antek->x] = 0;
                                                ruch( antek, 1 );
                                        }




		wypisz( plansza, antek );
		printf("%d: %dx%d\n\n", g+1, antek->x, antek->y);
	//	usleep( 100000 );
	}
	return 0;
}
