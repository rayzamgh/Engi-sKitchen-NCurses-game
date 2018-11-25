#include "mesinbaris.h"
#include "matriks.h"
#include "bintree.h"
#include "array.h"
#include "graph.h"
#include "queue.h"
#include "stackt.h"
#include "jam.h"
#include "point.h"
#include "mesinkatakomparasi.h"
#ifndef _FILEMANAGER_H_
#define _FILEMANAGER_H_

MATRIKS BacaMap(char namaFile[100]);
BinTree BacaPohonMakanan(char namaFile[100]);
TabKata BacaArray(char namaFile[100]);
void TulisSaveGame(char namaFile[100], Queue ANS, Queue AS, long Uang, long Nyawa, JAM Waktu, POINT Posisi,
                   int Stage, TabKata Orderan, TabKata BOO, Queue PDM, MATRIKS P1, MATRIKS P2, MATRIKS P3, MATRIKS P4,
                   Graph Pintu, BinTree PohM, Stack Food, Stack Hand, TabKata NamaBahan, TabKata XBahan,
                   TabKata YBahan);
void BacaSaveGame(char namaFile[100], Queue *ANS, Queue *AS, long int *Uang, long int *Nyawa, JAM *Waktu,
                  POINT *Posisi, int *Stage, TabKata *Orderan, TabKata *BOO, Queue *PDM, MATRIKS *P1, MATRIKS *P2,
                  MATRIKS *P3, MATRIKS *P4, Graph *Pintu, BinTree *PohM, Stack *Food, Stack *Hand,
                  TabKata *NamaBahan, TabKata *XBahan, TabKata *YBahan);
Queue BacaQueueMejaPelanggan(char namaFile[100]);
Queue BacaQueuePelanggan(char namaFile[100]);
Stack BacaStackFood(char namaFile[100]);
Stack BacaStackHand(char namaFile[100]);
Graph BacaGraphPintu(char namaFile[100]);
#endif