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

void ruch ( mrowka_t mrowka, int kolor, macierz_t macierz, int ktoramrowka ); // sluzy do wykonywania kolejnych krokow mrowki
void przejscie ( mrowka_t mrowka, macierz_t macierz, int ktora ); // funkcja ta sluzy przejsciu mrowki na drugi koniec planszy gdy znajdzie sie ona na jednym z brzegow
void rozdzielenie ( mrowka_t mrowka, int ilosc, int ktora ); // funkcja ta sprawdza dla mrowki o indeksie "ktora" czy nie jest na tym samym polu co ktorakolwiek inna mrowka, jesli tak to ustawia ich kierunki przeciwnie. pozwala to na zmniejszenie ilosci zapetlen w ktore moga wpasc dwie mrowki bedac obok siebie

#endif
