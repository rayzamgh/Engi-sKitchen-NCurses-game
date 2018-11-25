#include "boolean.h"
#include "point.h"
#include "mesinkatakomparasi.h"
#include "jam.h"

#define minKesabaran 15
#define maxKesabaran 20

typedef struct
{
    POINT posisi;
    int banyak;    
    JAM waktuCabut;
    boolean sudahDuduk;
    Kata orderan;
    boolean isStarPelanggan;
} PELANGGAN ;

/* Selektor */
#define Pos(P) (P).posisi
#define Banyak(P) (P).banyak
#define WaktuCabut(P) (P).waktuCabut
#define SudahDuduk(P) (P).sudahDuduk
#define Orderan(P) (P).orderan
#define IsStar(P) (P).isStarPelanggan

PELANGGAN createNewPelanggan(int banyak,JAM cur,boolean isStar);
void PlacePelanggan(PELANGGAN *P,POINT meja, JAM cur);
