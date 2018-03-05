#ifndef _MROOVKA_H
#define _MROOVKA_H

#include"macierz.h"

typedef enum
{
	PLN, WSCH, PLD, ZACH
} kierunek_t;

typedef struct
{
	int x;
	int y;
	kierunek_t kierunek;
} *mrowka_t;

void ruch ( mrowka_t mrowka, int kolor, macierz_t macierz );
void odbicie ( mrowka_t mrowka, macierz_t macierz );

#endif
