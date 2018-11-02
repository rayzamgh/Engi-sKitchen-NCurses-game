#include "boolean.h"
#include "matriks.h"
//#include "stackt.h"
//#include "queue.h"
#include "layar.h"
#include<stdio.h>


void CreateEmptyLayar(LAYAR *L, int width, int height)
//Membuat layar kosong dengan ukuran width * height
{
    widthLayar(*L) = width;
    heightLayar(*L) = height;
    MakeMATRIKS(width+1, height+1, &isiLayar(*L));
    for(int i = 1;i <= width;i++)
    {
        for(int j = 1;j<=height;j++)
        {
            pixel(*L,i,j) = ' ';
        }
    }
}
void CreateGarisHorizontal(LAYAR *L, int startX, int finishX, int y)
//Membuat garis dari koordinat (startX,y) hingga (finishX, y)
{
    for (int i = startX; i <= finishX; i++)
    {
        pixel(*L, i, y) = '*';
    }
}
void CreateGarisVertikal(LAYAR *L, int x, int startY, int finishY)
//Membuat garis dari koordinat (x, startY) hingga (x, finishY)
{
    for (int i = startY; i <= finishY; i++)
    {
        pixel(*L, x, i) = '*';
    }
}
void CreateTabel(LAYAR *L, int startX, int startY, int finishX, int finishY, int rows, int cols)
//Membuat tabel dari koordinat (startX,startY) hingga (finishX,finishY) dengan rinician
//Baris sebanyak rows, kolom sebanyak cols
//Lebar baris dan kolom disesuaikan dari deltaX/cols dan deltaY/rows
/* Rincian tambahan : 
 * Garis atas tabel ada di (startX,startY) hingga (finishX,startY)
 * Garis bawah ada di (startX,finishY) hingga (finishX,finishY)
 * Garis kiri ada di (startX,startY) hingga (startX,finishY)
 * Garis kanan ada di (finishX,startY) hingga (finishX,finishY)
 */
{
    //Garis atas
    CreateGarisHorizontal(L, startX, finishX, startY);
    //Garis bawah
    CreateGarisHorizontal(L, startX, finishX, finishY);
    //Garis kiri
    CreateGarisVertikal(L, startX, startY, finishY);
    //Garis kanan
    CreateGarisVertikal(L, finishX, startY, finishY);
    //Garis baris
    int tinggiBaris = (finishY - startY) / rows;
    for (int i = 1; i < rows; i++)
    {
        CreateGarisHorizontal(L, startX, finishX, startY + i * tinggiBaris);
    }
    //Garis kolom
    int lebarKolom = (finishX - startX) / cols;
    for (int i = 1; i < cols; i++)
    {
        CreateGarisVertikal(L, startX + i * lebarKolom, startY, finishY);
    }
}
void PutTextAt(LAYAR *L, int x, int y, char str[20])
//Menaruh String str di posisi (x,y) di layar
{
    int i = 0;
    while (str[i] != '\0')
    {
        pixel(*L, x + i, y) = str[i];
        i++;
    }
}
/*
void initLayarGame(LAYAR *L, char nama[20], int money, int life, int time, int waitingCust, Queue order, Stack food, Stack hand, MATRIKS ruangan)
//Mengisi layar dengan semua elemen UI dari game seperti nama, uang, nyawa, waktu, banyak kustomer, orderan
//Food stack, makanan di tangan
{
    CreateEmptyLayar(L, 30, 30);
}
*/
void printLayar(LAYAR L)
//Print layar ke console
{
    for (int i = 1; i <= heightLayar(L); i++)
    {
        for (int j = 1; j <= widthLayar(L); j++)
        {
            printf("%c",pixel(L,j,i));
        }
        printf("\n");
    }
}