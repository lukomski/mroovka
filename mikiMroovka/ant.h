#ifndef _ANT_H
#define _ANT_H

typedef struct
{
	int x;
	int y;
	int pos;
}*ant_t;

void move(ant_t, int s);
void mirror(ant_t ant, int x, int y);
#endif
