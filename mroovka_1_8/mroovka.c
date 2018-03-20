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
			else
			{
				mrowka->kierunek[ktoramrowka] = WSCH;
				mrowka->x[ktoramrowka] +=1;
			}
			przejscie( mrowka, macierz, ktoramrowka );
		break;

		case WSCH:
			if( kolor == ktoramrowka )
			{
				mrowka->kierunek[ktoramrowka] = PLN;
	                        mrowka->y[ktoramrowka] -=1;
			}
			else
			{
				mrowka->kierunek[ktoramrowka] = PLD;
				mrowka->y[ktoramrowka] +=1;
				}
			przejscie( mrowka, macierz, ktoramrowka );
		break;

		case PLD:
			if( kolor == ktoramrowka )
			{
				mrowka->kierunek[ktoramrowka] = WSCH;
				mrowka->x[ktoramrowka] +=1;

			}
			else
			{
				mrowka->kierunek[ktoramrowka] = ZACH;
				mrowka->x[ktoramrowka] -=1;
			}
			przejscie( mrowka, macierz, ktoramrowka );
		break;

		case ZACH:
			if( kolor == ktoramrowka )
			{
				mrowka->kierunek[ktoramrowka] = PLD;
				mrowka->y[ktoramrowka] +=1;
			}
			else
			{
				mrowka->kierunek[ktoramrowka] = PLN;
				mrowka->y[ktoramrowka] -=1;
			}
			przejscie( mrowka, macierz, ktoramrowka );
		break;
	}	
}

void przejscie( mrowka_t mrowka, macierz_t macierz, int ktora )
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

void rozdzielenie ( mrowka_t mrowka, int ilosc, int ktora) 
{
	int i;
	for ( i = ktora + 1; i< ilosc+1; i++ )
	{
		if ( mrowka->y[ktora] == mrowka->y[i] && mrowka->x[ktora] == mrowka->x[i] )
		{
			mrowka->kierunek[ktora] = PLN;
			mrowka->kierunek[i] = PLD;
		}
	}

}
