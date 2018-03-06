#include<stdlib.h>
#include"mroovka.h"
#include"macierz.h"

void ruch ( mrowka_t mrowka, int kolor, macierz_t macierz, int ktoramrowka )
{
	switch ( mrowka->kierunek[ktoramrowka] )
	{
		case PLN:
			if( kolor == ktoramrowka )
			{
				mrowka->kierunek[ktoramrowka] = ZACH;
				mrowka->x[ktoramrowka] -=1;
			}
			else if( 1==1 )
			{
				mrowka->kierunek[ktoramrowka] = WSCH;
				mrowka->x[ktoramrowka] +=1;
			}
			odbicie( mrowka, macierz, ktoramrowka );
		break;
		case WSCH:
			if( kolor == ktoramrowka )
			{
				mrowka->kierunek[ktoramrowka] = PLN;
	                        mrowka->y[ktoramrowka] -=1;
			}
			else if( 1==1 )
			{
				mrowka->kierunek[ktoramrowka] = PLD;
				mrowka->y[ktoramrowka] +=1;
				}
			odbicie( mrowka, macierz, ktoramrowka );
		break;
		case PLD:
			if( kolor == ktoramrowka )
			{
				mrowka->kierunek[ktoramrowka] = WSCH;
				mrowka->x[ktoramrowka] +=1;

			}
			else if( 1==1 )
			{
				mrowka->kierunek[ktoramrowka] = ZACH;
				mrowka->x[ktoramrowka] -=1;
			}
			odbicie( mrowka, macierz, ktoramrowka );
		break;
		case ZACH:
			if( kolor == ktoramrowka )
			{
				mrowka->kierunek[ktoramrowka] = PLD;
				mrowka->y[ktoramrowka] +=1;
			}
			else if( 1==1 )
			{
				mrowka->kierunek[ktoramrowka] = PLN;
				mrowka->y[ktoramrowka] -=1;
			}
			odbicie( mrowka, macierz, ktoramrowka );
		break;
	}	
}

void odbicie( mrowka_t mrowka, macierz_t macierz, int ktora )
{
	if ( mrowka->x[ktora] < 0 )
		mrowka->x[ktora] = macierz->kolumny - 1;
	else if ( mrowka->x[ktora] >= macierz->kolumny )
		mrowka->x[ktora] = 0;

	if ( mrowka->y[ktora] < 0 )
		mrowka->y[ktora] = macierz->wiersze - 1;
	else if ( mrowka->y[ktora] >= macierz->wiersze )
		mrowka->y[ktora] = 0;
}
