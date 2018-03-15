#ifndef _GRAFIKA_H
#define _GRAFIKA_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <png.h>

#include "macierz.h"

void zapiszPNG( char* file_name );
void przetworzPNG( macierz_t macierz );

#endif
