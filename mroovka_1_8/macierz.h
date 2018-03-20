#ifndef _MACIERZ_H
#define _MACIERZ_H

typedef struct
{
	int **wart;
	int wiersze;
	int kolumny;
} *macierz_t;

macierz_t inicjuj( int w, int k);

#endif
