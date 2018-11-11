#ifndef MOVEMENT
#define MOVEMENT

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "point.h"
#include "jam.h"

void GoUp(MATRIKS *M, POINT *P, JAM *J);

void GoDown(MATRIKS *M, POINT *P, JAM *J);

void GoLeft(MATRIKS *M, POINT *P, JAM *J);

void GoRight(MATRIKS *M, POINT *P, JAM *J);

#endif
