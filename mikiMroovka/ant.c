#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ant.h"

int main(int argc, char ** argv)
{
	int t[50][50] = {0};//pole do poruszania sie mrowki
	
	int n = 11000;//ilosc krokow do wykonania 

	int brk = 0;//do wychodzenia z petli moze to zmienie na cos lepszego jak wymysle

	ant_t mrowa = malloc(sizeof(mrowa));
	mrowa->x = 26;//poczatkowe polozenie mrowki
	mrowa->y = 16;
	mrowa->pos = 4;//1 - N; 2 - E; 3 - S; 4 - W
	
	while(n-- >= 0)
	{
		printf("\033[H\033[J");
		for(int i = 0; i < 50; i++)
		{
			for(int j = 0; j < 50; j++)
			{
				if( i == mrowa->y && j == mrowa->x)
					printf("\x1B[91m  m");
				else if(t[i][j] == 1)
					printf("\x1B[93m  1");	
				else 
					printf("\x1B[90m  0");			
			}
			printf("\n");
		}

		for(int i = 0; i < 50; i++)
		{
			for(int j = 0; j < 50; j++)
			{
				if(i == mrowa->y && j == mrowa->x)
				{
					if(t[i][j] == 0) 
					{
						move(mrowa, 0);
						t[i][j] = 1;
				
					}
					else if(t[i][j] == 1)
					{
						move(mrowa, 1);
						t[i][j] = 0;
						
					}
					brk = 1;
					mirror(mrowa, 50, 50);
					break;
				}
			}
			
			if(brk == 1)
			{
				brk = 0;
				break;
			}
		}
		
		usleep(100000);
	}
}
