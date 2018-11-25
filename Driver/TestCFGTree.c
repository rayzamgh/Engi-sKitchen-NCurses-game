#include <stdio.h>
#include <stdlib.h>
#include "../include/filemanager.h"
#include "../include/array.h"
#include "../include/boolean.h"
#include "../include/bintree.h"

int main()
{
    BinTree Piring = BacaPohonMakanan("../save/Aditya/pohonMakanan.txt");
    PrintTree(Piring,4);
    ListRek Daun = MakeListDaun(Piring);
    PrintListRek(Daun);
    return 0;
}