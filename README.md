# Tubes-Alstrukdat
Engi's Kitchen DLC

Cara Compile
gcc src/main.c Module/Array/array.c Module/BinTree/bintree.c Module/FileManager/filemanager.c Module/Graph/graph.c Module/Jam/jam.c Module/Matriks/matriks.c Module/MesinBaris/mesinbaris.c Module/MesinBaris/mesinkar.c Module/MesinCommand/mesincommand.c Module/MesinCommand/mesinkarinput.c Module/MesinKomparasi/mesinkarkomparasi.c Module/MesinKomparasi/mesinkatakomparasi.c Module/Point/point.c Module/Queue/queue.c Module/Stack/stackt.c -o bin/game.exe -lncurses

jika gagal
install dahulu ncurses
jika masih gagal
ganti #include<ncurses.h> jadi #include<ncurses/ncurses.h>

Jika masih tidak bisa
silahkan langsung buka game.exe di bin untuk windows
atau
game.o di bin untuk linux