#ifndef _MROOVKA_H
#define _MROOVKA_H

#include"macierz.h"

typedef enum
{
	PLN, WSCH, PLD, ZACH
} kierunek_t;

typedef struct
{
	int x[10];
	int y[10];
	kierunek_t kierunek[10];
} *mrowka_t;

void ruch ( mrowka_t mrowka, int kolor, macierz_t macierz, int ktoramrowka );
void odbicie ( mrowka_t mrowka, macierz_t macierz, int ktora );
void rozdzielenie ( mrowka_t mrowka, int ilosc, int ktora );

#endif
