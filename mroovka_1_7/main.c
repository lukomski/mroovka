#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"mroovka.h"
#include"macierz.h"
#include"obsluga.h"
#include<time.h>
#include<string.h>


int main ( int argc, char* argv[] )
{
	int g, i, j, h, numer, ustaww, ustawk;
	int w = argc > 1 ? atoi ( argv[1] ) : 20;
	int k = argc > 2 ? atoi ( argv[2] ) : 20;
	int kroki = argc > 3 ? atoi ( argv[3] ) : 100;
	int ilosc = argc > 4 ? atoi ( argv[4] ) : 3;

	macierz_t plansza = inicjuj( w, k );
        mrowka_t antek = malloc( sizeof(antek) );
	
	int z,x;
	for ( z = 1; z < argc; z++ )
	{
		for ( x = 0; x < strlen(argv[z] ); x++ )
		{
			if ( argv[z][x] <= 57 && argv[z][x] >= 48 );
			else
			{
			printf (" Podales litere w podawaniu argumentow, a przyjmowane sa jedynie liczby.\n Prosze wywolac program jeszcze raz z podanymi poprawnymi argumentami, badz tez z ustawieniami domyslnymi.\n");
			return EXIT_FAILURE;
			}
		}
	}
	
	int czy_liczba_argumentow_ok = 1000000;
	if ( argc >=5 )
		czy_liczba_argumentow_ok = 5 + 2*( atoi( argv[4] )) ;
	
	if (  argc >= czy_liczba_argumentow_ok  ) 
	{
	
		if ( czy_liczba_argumentow_ok < argc )
			printf (" \nPodales za duzo wspolrzednych. Wczytuje ustawienia oraz ignoruje dodatkowe informacje.\n");
		else
			printf (" \nPodales odpowiednia ilosc argumentow oraz wspolrzednych. Wczytuje ustawienia.\n");
	
		int konsola = 5;
		int m;
		for ( m = 1; m < ilosc+1; m++ )
		{
       		antek->kierunek[m] = WSCH;
		antek->x[m] = atoi ( argv[konsola] );
		konsola++;
		antek->y[m] = atoi ( argv[konsola] );
		konsola++;
	
	}

	}
	else 
	{	
	srand( time( NULL) );
	
	if ( argc > 5 && argc < czy_liczba_argumentow_ok )
        printf (" \nWprowadziles argumenty z konsoli, ale podales zla liczbe par wspolrzednych dla mrowek. Mrowki zostaja rozmieszczone losowo.\n");
	else if ( argc == 5 )
        printf (" \nZostaly wczytane ustawienia z konsoli, ale bez podania wspolrzednych mrowek. Mrowki zostaja rozmieszczone losowo.\n");
	else if ( argc > 1 && argc < 5 )
	printf (" \nUstawienia ktore wpisales zostaly wczytane. Reszta ustawien zostaje ustawiona domyslnie.\n");
	else
	printf ("\nWczytuje domyslne ustawienia.\n");

	for ( h = 1; h < ilosc +1; h++ )
	{
        antek->x[h] = rand() % k  ;
        antek->y[h] = rand() % w  ;
        antek->kierunek[h] = WSCH;
        }

	}


//	printf("\033[H\033[J");	
//	wypisz( plansza, antek, ilosc );
//	printf("%dx%d\n\n", antek->x[1], antek->y[1]);

// EJ MONIKA WLASCIWIE TO PO CO TO BYLO? CHYBA TEGO NIE TRZEBA CO? XD


	printf (" Liczba wierszy to %d,\n liczba kolumn to %d,\n liczba krokow to %d,\n liczba mrowek to %d.\n\n", w, k, kroki, ilosc );
	int p;
	for ( p = 1; p < ilosc+1; p++ )
		printf ("Wspolrzedne mrowki %d to : %d x %d \n", p, antek->x[p], antek->y[p] );

	usleep( 5000000 );

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
		
		if ( kroki < 1000 && ilosc < 6 )
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
