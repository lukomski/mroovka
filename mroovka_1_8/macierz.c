#include"macierz.h"
#include<stdlib.h>

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
