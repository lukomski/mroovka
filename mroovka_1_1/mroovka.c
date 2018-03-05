#include<stdlib.h>
#include"mroovka.h"
#include"macierz.h"

void ruch ( mrowka_t mrowka, int kolor, macierz_t macierz )
{
	switch ( mrowka->kierunek )
	{
		case PLN:
			if( kolor == 1 )
			{
				mrowka->kierunek = ZACH;
				mrowka->x--;
			}
			else if( kolor == 0 )
			{
				mrowka->kierunek = WSCH;
				mrowka->x++;
			}
			odbicie( mrowka, macierz );
		break;
		case WSCH:
			if( kolor == 1 )
			{
				mrowka->kierunek = PLN;
				mrowka->y--;
			}
			else if( kolor == 0 )
			{
				mrowka->kierunek = PLD;
				mrowka->y++;
			}
			odbicie( mrowka, macierz );
		break;
		case PLD:
			if( kolor == 1 )
			{
				mrowka->kierunek = WSCH;
				mrowka->x++;
			}
			else if( kolor == 0 )
			{
				mrowka->kierunek = ZACH;
				mrowka->x--;
			}
			odbicie( mrowka, macierz );
		break;
		case ZACH:
			if( kolor == 1 )
			{
				mrowka->kierunek = PLD;
				mrowka->y++;
			}
			else if( kolor == 0 )
			{
				mrowka->kierunek = PLN;
				mrowka->y--;
			}
			odbicie( mrowka, macierz );
		break;
	}	
}

void odbicie( mrowka_t mrowka, macierz_t macierz )
{
	if ( mrowka->x < 0 )
		mrowka->x = macierz->kolumny - 1;
	else if ( mrowka->x >= macierz->kolumny )
		mrowka->x = 0;

	if ( mrowka->y < 0 )
		mrowka->y = macierz->wiersze - 1;
	else if ( mrowka->y >= macierz->wiersze )
		mrowka->y = 0;
}
