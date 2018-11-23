#include <stdio.h>
#include <string.h>
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

/* Global Variable */
char namaUser[20];
boolean sudahInputNama = false;
boolean isGameOn = false;
int lebarMainMenu = 40, tinggiMainMenu = 20;
int lebarGame = 120, tinggiGame = 40;
WINDOW *MainMenu, *Game;
POINT player;
/* --------------- */

void InisialisasiOrder(TabInt *TabOrder)
{
}

void PlaceOrder(TabInt *TABOrder)
{
}

void Update()
{
}

void hapusWindow(WINDOW *hapus)
{
    wborder(hapus, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(hapus);
    delwin(hapus);
}

void StartGame()
{
    isGameOn = true;
    hapusWindow(MainMenu);
    clear();
    Game = newwin(lebarGame, tinggiGame, 0, 0);
    refresh();
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

void PrintBoxGame()
{
    box(Game, 0, 0);
    wrefresh(Game);
}

void PrintBoxMainMenu()
{
    box(MainMenu, 0, 0);
    wrefresh(MainMenu);
}

void PrintMainMenu(int startX, int startY)
{
    mvwprintw(MainMenu, startY, startX, "SELAMAT DATANG DI ENGI'S KITCHEN!!\n");
    if(sudahInputNama)
    {
        mvwprintw(MainMenu,startY+9,startX,"Hai ");
        mvwprintw(MainMenu,startY+9,startX+4,namaUser);
        mvwprintw(MainMenu,startY+10,startX,"Ketik Start Game untuk mulai permainan");
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
    }
    else if (pilihan == 4)
    {
        EXIT();
    }
}

void PrintCommand()
{
    printf("DAFTAR COMMAND\n");
    printf("GU : Go Up\n");
    printf("GD : Go Down\n");
    printf("GL : Go Left\n");
    printf("GR : Go Right\n");
    printf("ORDER\n");
    printf("PUT\n");
    printf("TAKE\n");
    printf("CH\n");
    printf("CT\n");
    printf("PLACE\n");
    printf("GIVE\n");
    printf("RECIPE\n");
    printf("SAVE\n");
    printf("LOAD\n");
    printf("EXIT\n");
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
    char pilihanCommand[10];
    while (isGameOn)
    {
        PrintCommand();
        printf("Masukan pilihan Anda : ");
        STARTCOMMAND();
        if (CommandIs("GU"))
        {
            GU();
        }
        else if (CommandIs("GD"))
        {
            GD();
        }
        else if (CommandIs("GL"))
        {
            GL();
        }
        else if (CommandIs("GR"))
        {
            GR();
        }
        else if (CommandIs("ORDER"))
        {
            ORDER();
        }
        else if (CommandIs("PUT"))
        {
            PUT();
        }
        else if (CommandIs("TAKE"))
        {
            TAKE();
        }
        else if (CommandIs("CH"))
        {
            CH();
        }
        else if (CommandIs("CT"))
        {
            CT();
        }
        else if (CommandIs("PLACE"))
        {
            PLACE();
        }
        else if (CommandIs("GIVE"))
        {
            GIVE();
        }
        else if (CommandIs("RECIPE"))
        {
            RECIPE();
        }
        else if (CommandIs("SAVE"))
        {
            SAVE();
        }
        else if (CommandIs("LOAD"))
        {
            LOAD();
        }
        else if (CommandIs("EXIT"))
        {
            EXIT();
        }
        else
        {
            printf("Masukan pilihan Anda tidak valid\n");
        }
        Update();
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
    endwin();
    return 0;
}