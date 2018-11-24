# Tubes-Alstrukdat
Engi's Kitchen DLC

jika berada di folder root / luar src compile dengan
```
gcc src/*.c src/libncurses.a -o bin/game.o -lncurses && cd bin && ./game.o && cd ..
```
atau jika berada didalam folder bin
```
gcc ../src/*.c ../src/libncurses.a -o game.o -lncurses && ./game.o
```
