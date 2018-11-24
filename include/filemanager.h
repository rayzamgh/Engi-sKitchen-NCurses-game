#include "mesinbaris.h"
#include "matriks.h"
#include "bintree.h"
#include "array.h"
#include "queue.h"
#include "stackt.h"
#include "jam.h"
#include "point.h"

#ifndef _FILEMANAGER_H_
#define _FILEMANAGER_H_


MATRIKS BacaMap(char namaFile[100]);
BinTree BacaPohonMakanan(char namaFile[100]);
TabKata BacaArray(char namaFile[100]);
Queue BacaQueuePelanggan(char namaFile[100]);
Stack BacaStackFood(char namaFile[100]);
Stack BacaStackHand(char namaFile[100]);
#endif 