#include "../MesinBaris/mesinbaris.h"
#include "../Matriks/matriks.h"
#include "../BinTree/bintree.h"
#include "../Array/array.h"
#include "../Graph/graph.h"
#include "../Queue/queue.h"
#include "../Stack/stackt.h"
#include "../Jam/jam.h"
#include "../Point/point.h"
#include "../MesinKomparasi/mesinkatakomparasi.h"
#ifndef _FILEMANAGER_H_
#define _FILEMANAGER_H_

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
#endif