#include<stdio.h>
#include"obsluga.h"
#include"mroovka.h"
#include"macierz.h"

void wypisz( macierz_t macierz, mrowka_t mrowka )
{
	int i, j;
	for ( i = 0; i < macierz->wiersze; i++ )
        {
       		for ( j = 0; j < macierz->kolumny; j++ )
        	{
        		if ( j == mrowka->x && i == mrowka->y )
        			printf("\x1B[36m m");
        		else if ( macierz->wart[i][j] == 1 )
        			printf("\x1B[33m 1");
        		else
        			printf("\x1B[37m 0");
        	}	
        	printf("\n");
      	}
}
