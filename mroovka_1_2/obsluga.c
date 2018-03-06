#include<stdio.h>
#include"obsluga.h"
#include"mroovka.h"
#include"macierz.h"

void wypisz( macierz_t macierz, mrowka_t mrowka )
{
	int i, j, k;
	for ( i = 0; i < macierz->wiersze; i++ )
        {
       		for ( j = 0; j < macierz->kolumny; j++ )
        	{
	        		if ( ( j == mrowka->x[1] && i == mrowka->y[1] ) || ( j == mrowka->x[2] && i == mrowka->y[2] ) || ( j == mrowka->x[3] && i == mrowka->y[3] ) ) 
        				printf("\x1B[36m m");


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
				else if ( macierz->wart[i][j] == 6 )
                                        printf("\x1B[33m 6");
				else if ( macierz->wart[i][j] == 7 )
                                        printf("\x1B[33m 7");
                                else if ( macierz->wart[i][j] == 8 )
                                        printf("\x1B[33m 8");
                                else if ( macierz->wart[i][j] == 9 )
                                        printf("\x1B[33m 9");
  		      		else
        				printf("\x1B[37m 0");

        	}	
        	printf("\n");
      	}
}
