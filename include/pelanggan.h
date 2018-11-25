#include "boolean.h"
#include "point.h"
#include "mesinkatakomparasi.h"
#include "jam.h"

#define minKesabaran 15
#define maxKesabaran 20

typedef struct
{
    int noRuangan;
    POINT posisi;
    int banyak;    
    JAM waktuCabut;
    Kata orderan;
    boolean isStarPelanggan;
    boolean sudahOrder;
} PELANGGAN ;

/* Selektor */
#define Ruangan(P) (P).noRuangan
#define Pos(P) (P).posisi
#define Banyak(P) (P).banyak
#define WaktuCabut(P) (P).waktuCabut
#define Orderan(P) (P).orderan
#define IsStar(P) (P).isStarPelanggan
#define SudahOrder(P) (P).sudahOrder