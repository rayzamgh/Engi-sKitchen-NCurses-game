#ifndef _LAYAR_H
#define _LAYAR_H

#include "boolean.h"
#include "matriks.h"
//#include "stackt.h"
//#include "queue.h"

typedef struct
{
    int width;
    int height;
    MATRIKS isiLayar;

} LAYAR;

//Selektor
#define pixel(L, X, Y) Elmt((L).isiLayar, X, Y)
#define widthLayar(L) (L).width
#define heightLayar(L) (L).height
#define isiLayar(L) (L).isiLayar

void CreateEmptyLayar(LAYAR *L, int width, int height);
//Membuat layar kosong dengan ukuran width * height

void CreateGarisHorizontal(LAYAR *L, int startX, int finishX, int y);
//Membuat garis dari koordinat (startX,y) hingga (finishX, y)

void CreateGarisVertikal(LAYAR *L, int x, int startY, int finishY);
//Membuat garis dari koordinat (x, startY) hingga (x, finishY)

void CreateTabel(LAYAR *L, int startX, int startY, int finishX, int finishY, int rows, int cols);
//Membuat tabel dari koordinat (startX,startY) hingga (finishX,finishY) dengan rinician
//Baris sebanyak rows, kolom sebanyak cols
//Lebar baris dan kolom disesuaikan dari deltaX/cols dan deltaY/rows
/* Rincian tambahan : 
 * Garis atas tabel ada di (startX,startY) hingga (finishX,startY)
 * Garis bawah ada di (startX,finishY) hingga (finishX,finishY)
 * Garis kiri ada di (startX,startY) hingga (startX,finishY)
 * Garis kanan ada di (finishX,startY) hingga (finishX,finishY)
 */

void PutTextAt(LAYAR *L, int x, int y, char str[20]);
//Menaruh String str di posisi (x,y) di layar

//void initLayarGame(LAYAR *L, char nama[20], int money, int life, int time, int waitingCust, Queue order, Stack food, Stack hand, MATRIKS ruangan);
//Mengisi layar dengan semua elemen UI dari game seperti nama, uang, nyawa, waktu, banyak kustomer, orderan
//Food stack, makanan di tangan

void printLayar(LAYAR L);
//Print layar ke console

#endif