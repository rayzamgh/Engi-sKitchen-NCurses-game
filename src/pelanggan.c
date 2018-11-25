#include "../include/pelanggan.h"
#include "../include/boolean.h"
#include "../include/point.h"
#include "../include/mesinkatakomparasi.h"
#include "../include/jam.h"
#include<stdio.h>
#include<stdlib.h>

PELANGGAN createNewPelanggan(int banyak,JAM cur,boolean isStar)
{
    PELANGGAN P;
    Pos(P) = MakePOINT(-1,-1);
    Banyak(P) = banyak;
    //Acak deltaT
    int deltaT = rand() % (maxKesabaran-minKesabaran)+minKesabaran;
    WaktuCabut(P) = NextNDetik(cur,deltaT);
    SudahDuduk(P) = false;
    IsStar(P) = isStar;
    return P;
} 

void PlacePelanggan(PELANGGAN *P,POINT meja, JAM cur)
{
    Pos(*P) = meja;
    //Acak deltaT
    int deltaT = rand() % (maxKesabaran-minKesabaran)+minKesabaran;
    WaktuCabut(*P) = NextNDetik(cur,deltaT);
    SudahDuduk(*P) = true;
}