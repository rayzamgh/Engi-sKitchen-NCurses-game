#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/boolean.h"
#include "../include/mesincommand.h"
#include "../include/mesinkatakomparasi.h"
#include "../include/array.h"
#include "../include/point.h"
#include "../include/queue.h"
#include "../include/stackt.h"
#include "../include/bintree.h"
#include "../include/movement.h"
#include "../include/graph.h"
#include "../include/filemanager.h"
/* Global Variable */
char namaUser[20];
long int uang, nyawa;
boolean sudahInputNama = false;
boolean gameLoaded = false;
boolean isGameOn = false;
int lebarMainMenu = 40, tinggiMainMenu = 20;
int lebarGame = 160, tinggiGame = 40;
WINDOW *MainMenu, *Game;
POINT player;
JAM WaktuSekarang;
Graph Stage;
BinTree PohonMakanan;
Queue AntrianPelanggan;
Stack Food, Hand;
TabKata OrderanPelanggan;
int noRuangan;
MATRIKS Room1, Room2, Room3, Room4;
/* --------------- */

void InisialisasiOrder(TabKata *TabOrder)
{
}

void PlaceOrder(TabKata *TABOrder)
{
}


void hapusWindow(WINDOW *hapus)
{
    wborder(hapus, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(hapus);
    delwin(hapus);
}

void rectangle(WINDOW* Layar,int y1, int x1, int y2, int x2)
{
    mvwhline(Layar,y1, x1, 0, x2-x1);
    mvwhline(Layar,y2, x1, 0, x2-x1);
    mvwvline(Layar,y1, x1, 0, y2-y1);
    mvwvline(Layar,y1, x2, 0, y2-y1);
    mvwaddch(Layar,y1, x1, ACS_ULCORNER);
    mvwaddch(Layar,y2, x1, ACS_LLCORNER);
    mvwaddch(Layar,y1, x2, ACS_URCORNER);
    mvwaddch(Layar,y2, x2, ACS_LRCORNER);
}

void PrintBoxMainMenu()
{
    box(MainMenu, 0, 0);
    wrefresh(MainMenu);
}
void Update()
{
    //Gambar Outline / Garis di Game
    mvwvline(Game,0,30,0,tinggiGame-4);
    mvwvline(Game,0,60,0,2);
    mvwvline(Game,0,90,0,tinggiGame-4);
    mvwhline(Game,2,0,0,lebarGame-40);
    mvwhline(Game,(int)tinggiGame/2,0,0,30);
    mvwhline(Game,(int)tinggiGame/2,lebarGame-69,0,30);
    mvwhline(Game,tinggiGame-4,0,0,lebarGame-40);
    rectangle(Game,0,0,tinggiGame-1,lebarGame-40);
    rectangle(Game,0,0,tinggiGame-1,lebarGame-1);
    //Gambar Default String di game
    mvwprintw(Game,1,1,"Nama : ");
    mvwprintw(Game,1,8,namaUser);
    mvwprintw(Game,1,31,"Uang : ");
    char stringTemp[10];
    sprintf(stringTemp,"%ld",uang);
    mvwprintw(Game,1,38,stringTemp);
    mvwprintw(Game,1,61,"Nyawa : ");
    sprintf(stringTemp,"%ld",nyawa);
    mvwprintw(Game,1,68,stringTemp);
    mvwprintw(Game,1,91,"Waktu : ");
    sprintf(stringTemp,"%ld",JAMToDetik(WaktuSekarang));
    mvwprintw(Game,1,98,stringTemp);
}

void StartGame()
{
    isGameOn = true;
    hapusWindow(MainMenu);
    clear();
    Game = newwin(tinggiGame,lebarGame, 0, 0);
    refresh();
    if (!gameLoaded)
    {
        //Buat Semua ADT secara default
        PohonMakanan = BacaPohonMakanan("../Default Save/pohonMakanan.txt");
        TabKata config = BacaArray("../Default Save/config.txt");
        uang = StringToLongInt(Elmt(config, 4).TabKata);
        nyawa = StringToLongInt(Elmt(config, 6).TabKata);
        WaktuSekarang = DetikToJAM(StringToLongInt(Elmt(config, 8).TabKata));
        int XPos, YPos;
        XPos = StringToLongInt(Elmt(config, 10).TabKata);
        YPos = StringToLongInt(Elmt(config, 11).TabKata);
        player = MakePOINT(XPos, YPos);
        noRuangan = StringToLongInt(Elmt(config, 13).TabKata);
        Room1 = BacaMap("../Default Save/peta1.txt");
        Room2 = BacaMap("../Default Save/peta2.txt");
        Room3 = BacaMap("../Default Save/peta3.txt");
        Room4 = BacaMap("../Default Save/peta4.txt");
        AntrianPelanggan = BacaQueuePelanggan("../Default Save/pelanggan.txt");
        MakeEmptyArray(&OrderanPelanggan);
    }
}

void NewGame()
{
    mvwprintw(MainMenu, 9, 1, "Masukkan Nama Chef : ");
    wgetstr(MainMenu, namaUser);
    sudahInputNama = true;
}

void LoadGame()
{
}

void EXIT()
{
    isGameOn = false;
}

boolean IsPilihanMenuValid(char pilihanMenu[])
{
    if (IsSameString(pilihanMenu, "New Game"))
    {
        return 1;
    }
    else if (IsSameString(pilihanMenu, "Start Game"))
    {
        return 2;
    }
    else if (IsSameString(pilihanMenu, "Load Game"))
    {
        return 3;
    }
    else if (IsSameString(pilihanMenu, "Exit"))
    {
        return 4;
    }
    else
    {
        return 5;
    }
}

void PrintMainMenu(int startX, int startY)
{
    mvwprintw(MainMenu, startY, startX, "SELAMAT DATANG DI ENGI'S KITCHEN!!\n");
    if (sudahInputNama)
    {
        mvwprintw(MainMenu, startY + 9, startX, "Hai ");
        mvwprintw(MainMenu, startY + 9, startX + 4, namaUser);
        mvwprintw(MainMenu, startY + 10, startX, "Ketik Start Game untuk mulai permainan");
    }
    mvwprintw(MainMenu, startY + 1, startX, "MAIN MENU : \n");
    mvwprintw(MainMenu, startY + 2, startX, "1. New Game\n");
    mvwprintw(MainMenu, startY + 3, startX, "2. Start Game\n");
    mvwprintw(MainMenu, startY + 4, startX, "3. Load Game\n");
    mvwprintw(MainMenu, startY + 5, startX, "4. Exit\n");
    mvwprintw(MainMenu, startY + 6, startX, "Masukan pilihan Anda : ");
}

void ProgramMainMenu()
{
    char pilihanMenu[100];
    int pilihan;
    do
    {
        PrintMainMenu(1, 1);
        PrintBoxMainMenu();
        wgetstr(MainMenu, pilihanMenu);
        pilihan = IsPilihanMenuValid(pilihanMenu);
        if (pilihan == 5)
        {
            wclear(MainMenu);
            mvwprintw(MainMenu, 8, 1, "Masukan pilihan Anda tidak valid\n");
        }
    } while (pilihan == 5);
    if (pilihan == 1)
    {
        NewGame();
        wclear(MainMenu);
        ProgramMainMenu();
    }
    else if (pilihan == 2)
    {
        if (sudahInputNama)
        {
            StartGame();
        }
        else
        {
            wclear(MainMenu);
            mvwprintw(MainMenu, 9, 1, "Input nama dulu\n");
            ProgramMainMenu();
        }
    }
    else if (pilihan == 3)
    {
        LoadGame();
        wclear(MainMenu);
        ProgramMainMenu();
    }
    else if (pilihan == 4)
    {
        EXIT();
    }
}

void PrintCommand()
{
    int XPos = lebarGame-19;
    int YPos = 0;
    mvwprintw(Game,YPos,XPos,"DAFTAR COMMAND\n");
    mvwprintw(Game,YPos+1,XPos,"GU : Go Up\n");
    mvwprintw(Game,YPos+2,XPos,"GD : Go Down\n");
    mvwprintw(Game,YPos+3,XPos,"GL : Go Left\n");
    mvwprintw(Game,YPos+4,XPos,"GR : Go Right\n");
    mvwprintw(Game,YPos+5,XPos,"ORDER\n");
    mvwprintw(Game,YPos+6,XPos,"PUT\n");
    mvwprintw(Game,YPos+7,XPos,"TAKE\n");
    mvwprintw(Game,YPos+8,XPos,"CH\n");
    mvwprintw(Game,YPos+9,XPos,"CT\n");
    mvwprintw(Game,YPos+10,XPos,"PLACE\n");
    mvwprintw(Game,YPos+11,XPos,"GIVE\n");
    mvwprintw(Game,YPos+12,XPos,"RECIPE\n");
    mvwprintw(Game,YPos+13,XPos,"SAVE\n");
    mvwprintw(Game,YPos+14,XPos,"LOAD\n");
    mvwprintw(Game,YPos+15,XPos,"EXIT\n");    
    refresh();
}

void GU()
{

    printf("\n");
}

void GD()
{

    printf("\n");
}

void GL()
{

    printf("\n");
}

void GR()
{

    printf("\n");
}

void ORDER()
{

    printf("\n");
}

void PUT()
{

    printf("\n");
}

void TAKE()
{

    printf("\n");
}

void CH()
{

    printf("\n");
}

void CT()
{

    printf("\n");
}

void PLACE()
{

    printf("\n");
}

void GIVE()
{

    printf("\n");
}

void RECIPE()
{

    printf("\n");
}

void SAVE()
{

    printf("\n");
}

void LOAD()
{

    printf("\n");
}

void BacaCommand()
{
    char InputUser[10];
    while (isGameOn)
    {
        Update();
        //PrintCommand();
        mvwprintw(Game,tinggiGame-3,1,"Masukan pilihan Anda : ");
        wrefresh(Game);
        wscanw(Game,"%s",&InputUser);
        if (IsSameString(InputUser,"GU"))
        {
            wclear(Game);
            GU();
        }
        else if (IsSameString(InputUser,"GD"))
        {
            wclear(Game);
            GD();
        }
        else if (IsSameString(InputUser,"GL"))
        {
            wclear(Game);
            GL();
        }
        else if (IsSameString(InputUser,"GR"))
        {
            wclear(Game);
            GR();
        }
        else if (IsSameString(InputUser,"ORDER"))
        {
            wclear(Game);
            ORDER();
        }
        else if (IsSameString(InputUser,"PUT"))
        {
            wclear(Game);
            PUT();
        }
        else if (IsSameString(InputUser,"TAKE"))
        {
            wclear(Game);
            TAKE();
        }
        else if (IsSameString(InputUser,"CH"))
        {
            wclear(Game);
            CH();
        }
        else if (IsSameString(InputUser,"CT"))
        {
            wclear(Game);
            CT();
        }
        else if (IsSameString(InputUser,"PLACE"))
        {
            wclear(Game);
            PLACE();
        }
        else if (IsSameString(InputUser,"GIVE"))
        {
            wclear(Game);
            GIVE();
        }
        else if (IsSameString(InputUser,"RECIPE"))
        {
            wclear(Game);
            RECIPE();
        }
        else if (IsSameString(InputUser,"SAVE"))
        {
            wclear(Game);
            SAVE();
        }
        else if (IsSameString(InputUser,"LOAD"))
        {
            wclear(Game);
            LOAD();
        }
        else if (IsSameString(InputUser,"EXIT"))
        {
            wclear(Game);
            EXIT();
        }
        else
        {
            wclear(Game);
            mvwprintw(Game,tinggiGame-2,1,"Masukan pilihan Anda tidak valid\n");
        }
    }
}

int main()
{
    initscr();
    refresh();
    MainMenu = newwin(tinggiMainMenu, lebarMainMenu, 0, 0);
    box(MainMenu, 0, 0);
    wrefresh(MainMenu);
    ProgramMainMenu();
    BacaCommand(); //Looping disini
    hapusWindow(Game);
    endwin();
    return 0;
}