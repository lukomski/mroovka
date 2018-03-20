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

	if ( czyLitera( argc, argv ) == 1 )
        {
                printf ("\nW podanych danych wystapila litera - uruchom program ponownie zgodnie z dokumentacja lub z danymi domyslnymi.\n\n");
                return EXIT_FAILURE;
        }

	int w = argc > 1 ? atoi ( argv[1] ) : 600;
	int k = argc > 2 ? atoi ( argv[2] ) : 600;
	int kroki = argc > 3 ? atoi ( argv[3] ) : 200000;
	int ilosc = argc > 4 ? atoi ( argv[4] ) : 1;

	macierz_t plansza = inicjuj( w, k );
        mrowka_t antek = malloc( sizeof(antek) );
	
	int czy_liczba_argumentow_ok = 1000000;
	if ( argc >=5 ) // jezeli warunek jest spelniony to uzytkownik chcial podac polozenia mrowek
		czy_liczba_argumentow_ok = 5 + 2*( atoi( argv[4] )) ; //w tej sytuacji tyle powinna wynosic liczba argumentow
	
	if (  argc >= czy_liczba_argumentow_ok  ) 
	{
	
		if ( czy_liczba_argumentow_ok < argc )
			printf ("\nZbyt wiele argumentow. Wczytuje ustawienia oraz ignoruje dodatkowe informacje...\n");
		else
			printf ("\nArgumenty zaakceptowano. Wczytuje ustawienia...\n");
	
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
        		printf ("\nNieodpowiednia ilosc pozycji mrowek. Wczytuje losowe pozycje mrowek...\n");
		else if ( argc == 5 )
        		printf ("\nBrak podanych pozycji mrowek. Wczytuje losowe pozycje mrowek...\n");
		else if ( argc > 1 && argc < 5 )
			printf ("\nZaakceptowano podane ustawienia. Ustawiam resztę ustawień jako domyślne...\n");
		else
			printf ("\nWczytuje domyslne ustawienia...\n");

		for ( h = 1; h < ilosc +1; h++ )
		{
        		antek->x[h] = rand() % k  ;
        		antek->y[h] = rand() % w  ;
        		antek->kierunek[h] = WSCH;
        	}

	}

	printf ("\n   Liczba wierszy: %d\n   liczba kolumn: %d\n   liczba krokow: %d\n   liczba mrowek: %d\n\n", w, k, kroki, ilosc );
	int p;
	for ( p = 1; p < ilosc+1; p++ )
		printf ("   Wspolrzedne mrowki nr. %d: %d x %d \n", p, antek->x[p], antek->y[p] );
	printf("\n");

	usleep( 5000000 );

	for( g = 0; g < kroki; g++ )
	{
		
		for ( i = 1; i< ilosc+1; i++ )
		{	
		
			rozdzielenie ( antek, ilosc, i );

			numer = plansza->wart[antek->y[i]][antek->x[i]];
			if ( numer != i )
        	        {
				plansza->wart[antek -> y[i] ][ antek -> x[i] ] = i;
        	                ruch( antek, numer, plansza, i );
              	 	}
               	 	else
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
	printf("Wynik zapisano w pliku plansza.png\n");
	printf("Copyright 2018, M. Osiak & K. Gawart - 'Mroovka' Software House\n\n");
	return 0;
}
