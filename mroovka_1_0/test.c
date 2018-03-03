#include<stdio.h>
#include<stdlib.h>
#include"macierz.h"

int main( int argc, char* argv[] )
{
	int w = argc > 1 ? atoi( argv[1] ) : 5;
	int k = argc > 2 ? atoi( argv[2] ) : 5;
	macierz_t macierz = inicjuj( w, k );
	int i, j;

	for ( i = 0; i < macierz->wiersze; i++ )
		for ( j = 0; j < macierz->kolumny; j++ )
			macierz->wart[i][j] = (i+1)*(j+1);

	for ( i = 0; i < macierz->wiersze; i++ )
	{
		for ( j = 0; j < macierz->kolumny; j++ )
			printf("%c[%dm %3d ", 0x1B, 31+(i%7),  macierz->wart[i][j]);
		printf("\n");
	}
	printf("%c[%dm", 0x1B, 0);
	return 0;
}
