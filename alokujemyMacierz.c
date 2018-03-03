#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int **wart;
	int wiersze;
	int kolumny;
} *macierz_t;

macierz_t inicjuj( int w, int k ) //dorobic obsluge bledow
{
	int i;
	macierz_t nowa = malloc( sizeof(nowa) );
	nowa->wart = malloc( w * sizeof(nowa->wart) );
	nowa->wiersze = w;
	nowa->kolumny = k;
	for ( i = 0; i < w; i++ )
		nowa->wart[i] = malloc( k * sizeof(nowa->wart[i]) );
	return nowa;
}

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
