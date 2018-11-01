//ADT STAGE GAME
#ifndef MATRIKS_H
#define MATRIKS_H

#include "matriks.h"
#include "boolean.h"
#include <stdio.h>

#define BLANK ' '

typedef struct {
	MATRIKS Kitchen;
	MATRIKS Area1;
	MATRIKS Area2;
	MATRIKS Area3;
}STAGE;

CreateEmpty(*St STAGE);
//inisiasi stage menjadi matriks char BLANK 8x8 di semua area 


#endif