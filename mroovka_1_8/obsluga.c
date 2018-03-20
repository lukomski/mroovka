#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"obsluga.h"
#include"mroovka.h"
#include"macierz.h"

int czyLitera( int liczba, char* argumenty[] )
{
	int z, x;
        for ( z = 1; z < liczba; z++ )
        {
                for ( x = 0; x < strlen( argumenty[z] ); x++ )
                {
                        //if ( argumenty[z][x] <= 57 && argumenty[z][x] >= 48 );
			//else
			if ( isalpha ( argumenty[z][x] ) != 0 )
                        	return 1;
                }
        }
	return 0;
}

void wypisz( macierz_t macierz, mrowka_t mrowka, int ilosc )
{
	int i, j, k, l, wyjdz;
	printf("\033[H\033[J");
	for ( i = 0; i < macierz->wiersze; i++ )
        {
       		for ( j = 0; j < macierz->kolumny; j++ )
        	{
				wyjdz = 0;
				for ( l = 1; l < ilosc+1; l++ )
				{
					if ( j == mrowka->x[l] && i == mrowka->y[l] )
					{
						printf("\x1B[36m m");
						wyjdz = 1;
						break;
					}
				}

				if ( wyjdz == 1 )
					continue;
        			else if ( macierz->wart[i][j] == 1 )
        				printf("\x1B[31m 1");
				else if ( macierz->wart[i][j] == 2 )
                                        printf("\x1B[32m 2");
				else if ( macierz->wart[i][j] == 3 )
                                        printf("\x1B[33m 3");
				else if ( macierz->wart[i][j] == 4 )
                                        printf("\x1B[34m 4");
				else if ( macierz->wart[i][j] == 5 )
                                        printf("\x1B[35m 5");
  		      		else
        				printf("\x1B[30m 0\x1B[37m");

        	}	
        	printf("\n");
      	}
}
