#include <stdio.h>
#include <time.h>
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
Queue AntrianNonStar, AntrianStar;
Queue PelangganDiMeja;
Stack Food, Hand;
TabKata OrderanPelanggan;
int noRuangan;
MATRIKS Room1, Room2, Room3, Room4, curRoom;
/* --------------- */
/* Deklarasi bbrp fungsi */
void ProgramMainMenu();

void hapusWindow(WINDOW *hapus)
{
    wborder(hapus, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(hapus);
    delwin(hapus);
}

void rectangle(WINDOW *Layar, int y1, int x1, int y2, int x2)
{
    mvwhline(Layar, y1, x1, 0, x2 - x1);
    mvwhline(Layar, y2, x1, 0, x2 - x1);
    mvwvline(Layar, y1, x1, 0, y2 - y1);
    mvwvline(Layar, y1, x2, 0, y2 - y1);
    mvwaddch(Layar, y1, x1, ACS_ULCORNER);
    mvwaddch(Layar, y2, x1, ACS_LLCORNER);
    mvwaddch(Layar, y1, x2, ACS_URCORNER);
    mvwaddch(Layar, y2, x2, ACS_LRCORNER);
}

void tabel(WINDOW *Layar, int y1, int x1, int row, int col)
{
    int dx = 4;
    int dy = 2;
    int x2 = x1 + col * dx, y2 = y1 + row * dy;
    rectangle(Layar, y1, x1, y2, x2);
    int x3 = x1 + dx, y3 = y1 + dy;
    while (col > 0)
    {
        rectangle(Layar, y1, x1, y2, x3);
        x3 += dx;
        col -= 1;
    }
    while (row > 0)
    {
        rectangle(Layar, y1, x1, y3, x2);
        y3 += dy;
        row -= 1;
    }
}

void PrintBoxMainMenu()
{
    box(MainMenu, 0, 0);
    wrefresh(MainMenu);
}

void UpdateData()
{
    WaktuSekarang = NextDetik(WaktuSekarang);
    //Cek Kesabaran customer ngantre
    //Cek Star
    //Cek NonStar
    //Cek Kesabaran customer dimeja
    //Generate customer baru secara acak
    if (!IsFullQueue(AntrianNonStar) && !IsFullQueue(AntrianStar))
    {
        int genBaru = rand() % 100;
        if (genBaru <= 15)
        {
            //Generate kustomer baru
            PELANGGAN PBaru;
            Ruangan(PBaru) = -1;
            Pos(PBaru) = MakePOINT(-1, -1);
            Banyak(PBaru) = (genBaru % 2 + 1) * 2;
            WaktuCabut(PBaru) = NextNDetik(WaktuSekarang, 30);
            IsStar(PBaru) = (rand() % 100 >= 50);
            SudahOrder(PBaru) = false;
            if (IsStar(PBaru))
            {
                Add(&AntrianStar, PBaru);
            }
            else
            {
                Add(&AntrianNonStar, PBaru);
            }
        }
    }
    //Cek nyawa apakah sudah habis/belum
}

void UpdateGambar()
{
    //Gambar Outline / Garis di Game
    mvwvline(Game, 0, 30, 0, tinggiGame - 4);
    mvwvline(Game, 0, 60, 0, 2);
    mvwvline(Game, 0, 90, 0, tinggiGame - 4);
    mvwhline(Game, 2, 0, 0, lebarGame - 40);
    mvwhline(Game, (int)tinggiGame / 2, 0, 0, 30);
    mvwhline(Game, (int)tinggiGame / 2, lebarGame - 69, 0, 30);
    mvwhline(Game, tinggiGame - 4, 0, 0, lebarGame - 40);
    rectangle(Game, 0, 0, tinggiGame - 1, lebarGame - 40);
    rectangle(Game, 0, 0, tinggiGame - 1, lebarGame - 1);
    //Gambar Default String di game
    mvwprintw(Game, 1, 1, "Nama : ");
    mvwprintw(Game, 1, 8, namaUser);
    mvwprintw(Game, 1, 31, "Uang : ");
    char stringTemp[10];
    sprintf(stringTemp, "%ld", uang);
    mvwprintw(Game, 1, 38, stringTemp);
    mvwprintw(Game, 1, 61, "Nyawa : ");
    sprintf(stringTemp, "%ld", nyawa);
    mvwprintw(Game, 1, 68, stringTemp);
    mvwprintw(Game, 1, 91, "Waktu : ");
    sprintf(stringTemp, "%ld", JAMToDetik(WaktuSekarang));
    mvwprintw(Game, 1, 98, stringTemp);
    mvwprintw(Game, 3, 31, "Player : ");
    char posPlayer[10];
    sprintf(posPlayer, "%d, %d", player.X, player.Y);
    mvwprintw(Game, 3, 39, posPlayer);
    //Gambar Stage
    int dX = 30 + (60 - 4 * GetLastIdxKol(curRoom)) / 2;
    int dY = (35 - 2 * GetLastIdxBrs(curRoom)) / 2;
    tabel(Game, dY, dX, 8, 8);
    //Gambar isi Stage
    for (int i = GetFirstIdxBrs(curRoom); i <= GetLastIdxBrs(curRoom); i++)
    {
        for (int j = GetFirstIdxKol(curRoom); j <= GetLastIdxKol(curRoom); j++)
        {
            char c = ElmtMat(curRoom, i, j);
            if (i == Ordinat(player) && j == Absis(player))
            {
                c = 'P';
            }
            if (c != '_')
            {
                mvwprintw(Game, dY + 2 * i + 1, dX + 4 * j + 2, "%c", c);
            }
        }
    }
    //Gambar queue customer di antrean
    mvwprintw(Game, 3, 1, "Antrean Customer");
    int banyakAntreanStar = NBElmt(AntrianStar);
    for (int i = 0; i < banyakAntreanStar; i++)
    {
        PELANGGAN temp;
        Del(&AntrianStar, &temp);
        //Tulis di layar
        char banyakOrang[5];
        sprintf(banyakOrang, "%d*", Banyak(temp));
        mvwprintw(Game, 4 + i, 1, banyakOrang);
        //Balikan ke antrean
        Add(&AntrianStar, temp);
    }
    int banyakAntreanNonStar = NBElmt(AntrianNonStar);
    for (int i = 0; i < banyakAntreanNonStar; i++)
    {
        PELANGGAN temp;
        Del(&AntrianNonStar, &temp);
        //Tulis di layar
        char banyakOrang[5];
        sprintf(banyakOrang, "%d", Banyak(temp));
        mvwprintw(Game, 4 + i + banyakAntreanStar, 1, banyakOrang);
        //Balikan ke antrean
        Add(&AntrianNonStar, temp);
    }
}

void UpdateCurRoom()
{
    switch (noRuangan)
    {
    case 1:
        curRoom = Room1;
        break;
    case 2:
        curRoom = Room2;
        break;
    case 3:
        curRoom = Room3;
        break;
    case 4:
        curRoom = Room4;
        break;
    default:
        break;
    }
}

void StartGame()
{
    isGameOn = true;
    hapusWindow(MainMenu);
    clear();
    Game = newwin(tinggiGame, lebarGame, 0, 0);
    refresh();
    if (!gameLoaded)
    {
        //Buat Semua ADT secara default
        BacaSaveGame("../Default Save/Default.txt", &AntrianNonStar, &AntrianStar, &uang,
                     &nyawa, &WaktuSekarang, &player, &noRuangan, &OrderanPelanggan,
                     &PelangganDiMeja, &Room1, &Room2, &Room3, &Room4, &Stage, &PohonMakanan,
                     &Food, &Hand);
        UpdateCurRoom();
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
    mvwprintw(MainMenu, 9, 1, "Masukkan Nama Save : ");
    wgetstr(MainMenu, namaUser);
    char letakSave[50];
    sprintf(letakSave, "../save/%s.txt", namaUser);
    FILE *fp = fopen(letakSave, "r");
    if (fp != NULL)
    {
        sudahInputNama = true;
        BacaSaveGame(letakSave, &AntrianNonStar, &AntrianStar, &uang,
                     &nyawa, &WaktuSekarang, &player, &noRuangan, &OrderanPelanggan,
                     &PelangganDiMeja, &Room1, &Room2, &Room3, &Room4, &Stage, &PohonMakanan,
                     &Food, &Hand);
        UpdateCurRoom();
        gameLoaded = true;
        wclear(MainMenu);
        mvwprintw(MainMenu, 9, 1, "Game Loaded\n");
        ProgramMainMenu();
        fclose(fp);
    }
    else
    {
        wclear(MainMenu);
        mvwprintw(MainMenu, 9, 1, "Save Not Found\n");
        ProgramMainMenu();
    }
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
    }
    else if (pilihan == 4)
    {
        EXIT();
    }
}

void PrintCommand()
{
    int XPos = lebarGame - 19;
    int YPos = 0;
    mvwprintw(Game, YPos, XPos, "DAFTAR COMMAND\n");
    mvwprintw(Game, YPos + 1, XPos, "GU : Go Up\n");
    mvwprintw(Game, YPos + 2, XPos, "GD : Go Down\n");
    mvwprintw(Game, YPos + 3, XPos, "GL : Go Left\n");
    mvwprintw(Game, YPos + 4, XPos, "GR : Go Right\n");
    mvwprintw(Game, YPos + 5, XPos, "ORDER\n");
    mvwprintw(Game, YPos + 6, XPos, "PUT\n");
    mvwprintw(Game, YPos + 7, XPos, "TAKE\n");
    mvwprintw(Game, YPos + 8, XPos, "CH\n");
    mvwprintw(Game, YPos + 9, XPos, "CT\n");
    mvwprintw(Game, YPos + 10, XPos, "PLACE\n");
    mvwprintw(Game, YPos + 11, XPos, "GIVE\n");
    mvwprintw(Game, YPos + 12, XPos, "RECIPE\n");
    mvwprintw(Game, YPos + 13, XPos, "SAVE\n");
    mvwprintw(Game, YPos + 14, XPos, "LOAD\n");
    mvwprintw(Game, YPos + 15, XPos, "EXIT\n");
    refresh();
}

void GU()
{
    if (Ordinat(player) > GetFirstIdxBrs(curRoom))
    {
        player = PrevY(player);
    }
    else
    {
        //Cek apakah ini pintu
        int roomTujuan;
        POINT pintuTujuan;
        CariEdgePintu(Stage, player, noRuangan, &roomTujuan, &pintuTujuan);
        if (roomTujuan == -1)
        {
            mvwprintw(Game, tinggiGame - 2, 1, "Kamu menabrak tembok\n");
        }
        else
        {
            //Pindah Stage
            noRuangan = roomTujuan;
            UpdateCurRoom();
            player = pintuTujuan;
        }
    }
}

void GD()
{
    if (Ordinat(player) < GetLastIdxBrs(curRoom))
    {
        player = NextY(player);
    }
    else
    {
        //Cek apakah ini pintu
        int roomTujuan;
        POINT pintuTujuan;
        CariEdgePintu(Stage, player, noRuangan, &roomTujuan, &pintuTujuan);
        if (roomTujuan == -1)
        {
            mvwprintw(Game, tinggiGame - 2, 1, "Kamu menabrak tembok\n");
        }
        else
        {
            //Pindah Stage
            noRuangan = roomTujuan;
            UpdateCurRoom();
            player = pintuTujuan;
        }
    }
}

void GL()
{
    if (Absis(player) > GetFirstIdxKol(curRoom))
    {
        player = PrevX(player);
    }
    else
    {
        //Cek apakah ini pintu
        int roomTujuan;
        POINT pintuTujuan;
        CariEdgePintu(Stage, player, noRuangan, &roomTujuan, &pintuTujuan);
        if (roomTujuan == -1)
        {
            mvwprintw(Game, tinggiGame - 2, 1, "Kamu menabrak tembok\n");
        }
        else
        {
            //Pindah Stage
            noRuangan = roomTujuan;
            UpdateCurRoom();
            player = pintuTujuan;
        }
    }
}

void GR()
{

    if (Absis(player) < GetLastIdxKol(curRoom))
    {
        player = NextX(player);
    }
    else
    {
        //Cek apakah ini pintu
        int roomTujuan;
        POINT pintuTujuan;
        CariEdgePintu(Stage, player, noRuangan, &roomTujuan, &pintuTujuan);
        if (roomTujuan == -1)
        {
            mvwprintw(Game, tinggiGame - 2, 1, "Kamu menabrak tembok\n");
        }
        else
        {
            //Pindah Stage
            noRuangan = roomTujuan;
            UpdateCurRoom();
            player = pintuTujuan;
        }
    }
}

void ORDER()
{
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
    //Cek Sekeliling apakah ada meja
    //Cek kiri
    boolean ketemu = false;
    POINT meja;
    for (int i = Ordinat(player) - 1; i <= Ordinat(player) + 1 && !ketemu; i++)
    {
        for (int j = Absis(player) - 1; j <= Absis(player) + 1 && !ketemu; j++)
        {
            if (IsIdxEffMat(curRoom, i, j))
            {
                if (ElmtMat(curRoom, i, j) == 'X')
                {
                    //Cari titik tengah meja
                    for (int y = i - 1; y <= i + 1 && !ketemu; y++)
                    {
                        for (int x = j - 1; x <= j + 1 && !ketemu; x++)
                        {
                            if (IsIdxEffMat(curRoom, y, x))
                            {
                                char c = ElmtMat(curRoom, y, x);
                                if (c >= '0' && c <= '9')
                                {
                                    //Ketemu
                                    ketemu = true;
                                    meja = MakePOINT(x, y);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ketemu)
    {
        PELANGGAN cek = InfoHead(AntrianNonStar);
        //Cek muat
        int cekX = Absis(meja), cekY = Ordinat(meja) - 1;
        if (IsIdxEffMat(curRoom, cekY, cekX) && ElmtMat(curRoom, cekY, cekX) == 'X')
        {
            //Meja untuk ber 4
            //Taruh pelanggan di meja itu
            PELANGGAN taruh;
            Del(&AntrianNonStar, &taruh);
            Pos(taruh) = meja;
            Orderan(taruh) = GetDaunAcak(PohonMakanan);
            Add(&PelangganDiMeja, taruh);
            ElmtMat(Room1, Ordinat(meja) - 1, Absis(meja)) = 'C';
            ElmtMat(Room1, Ordinat(meja) + 1, Absis(meja)) = 'C';
            ElmtMat(Room1, Ordinat(meja), Absis(meja) - 1) = 'C';
            ElmtMat(Room1, Ordinat(meja), Absis(meja) + 1) = 'C';
            UpdateCurRoom();
        }
        else
        {
            //Meja untuk ber 2
            if (Banyak(cek) == 2)
            {
                PELANGGAN taruh;
                Del(&AntrianNonStar, &taruh);
                Pos(taruh) = meja;
                Orderan(taruh) = GetDaunAcak(PohonMakanan);
                Add(&PelangganDiMeja, taruh);
                ElmtMat(Room1, Ordinat(meja), Absis(meja) - 1) = 'C';
                ElmtMat(Room1, Ordinat(meja), Absis(meja) + 1) = 'C';
                UpdateCurRoom();
            }
            else
            {
                //Ga muat
                mvwprintw(Game, tinggiGame - 2, 1, "Meja tidak muat\n");
            }
        }
    }
    else
    {
        mvwprintw(Game, tinggiGame - 2, 1, "Tidak ada meja disekitarmu\n");
    }
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
    char letakSave[50];
    sprintf(letakSave, "../save/%s.txt", namaUser);
    TulisSaveGame(letakSave, AntrianNonStar, AntrianStar, uang,
                  nyawa, WaktuSekarang, player, noRuangan, OrderanPelanggan,
                  PelangganDiMeja, Room1, Room2, Room3, Room4, Stage, PohonMakanan,
                  Food, Hand);
    mvwprintw(Game, tinggiGame - 2, 1, "Save berhasil\n");
}

void LOAD()
{
    char tempNama[50];
    mvwprintw(Game, tinggiGame - 2, 1, "Masukan nama save : ");
    mvwgetstr(Game, tinggiGame - 2, 21, tempNama);
    char letakSave[50];
    sprintf(letakSave, "../save/%s.txt", tempNama);
    FILE *fp = fopen(letakSave, "r");
    if (fp != NULL)
    {
        sudahInputNama = true;
        BacaSaveGame(letakSave, &AntrianNonStar, &AntrianStar, &uang,
                     &nyawa, &WaktuSekarang, &player, &noRuangan, &OrderanPelanggan,
                     &PelangganDiMeja, &Room1, &Room2, &Room3, &Room4, &Stage, &PohonMakanan,
                     &Food, &Hand);
        UpdateCurRoom();
        gameLoaded = true;
        wclear(Game);
        mvwprintw(Game, tinggiGame - 2, 1, "Game Loaded\n");
        fclose(fp);
    }
    else
    {
        wclear(Game);
        mvwprintw(Game, tinggiGame - 2, 1, "Save not found\n");
    }
}

void BacaCommand()
{
    char InputUser[10];
    while (isGameOn)
    {
        UpdateData();
        UpdateGambar();
        //PrintCommand();
        mvwprintw(Game, tinggiGame - 3, 1, "Masukan pilihan Anda : ");
        wrefresh(Game);
        wgetstr(Game, InputUser);
        if (IsSameString(InputUser, "GU"))
        {
            wclear(Game);
            GU();
        }
        else if (IsSameString(InputUser, "GD"))
        {
            wclear(Game);
            GD();
        }
        else if (IsSameString(InputUser, "GL"))
        {
            wclear(Game);
            GL();
        }
        else if (IsSameString(InputUser, "GR"))
        {
            wclear(Game);
            GR();
        }
        else if (IsSameString(InputUser, "ORDER"))
        {
            wclear(Game);
            ORDER();
        }
        else if (IsSameString(InputUser, "PUT"))
        {
            wclear(Game);
            PUT();
        }
        else if (IsSameString(InputUser, "TAKE"))
        {
            wclear(Game);
            TAKE();
        }
        else if (IsSameString(InputUser, "CH"))
        {
            wclear(Game);
            CH();
        }
        else if (IsSameString(InputUser, "CT"))
        {
            wclear(Game);
            CT();
        }
        else if (IsSameString(InputUser, "PLACE"))
        {
            wclear(Game);
            PLACE();
        }
        else if (IsSameString(InputUser, "GIVE"))
        {
            wclear(Game);
            GIVE();
        }
        else if (IsSameString(InputUser, "RECIPE"))
        {
            wclear(Game);
            RECIPE();
        }
        else if (IsSameString(InputUser, "SAVE"))
        {
            wclear(Game);
            SAVE();
        }
        else if (IsSameString(InputUser, "LOAD"))
        {
            wclear(Game);
            LOAD();
        }
        else if (IsSameString(InputUser, "EXIT"))
        {
            wclear(Game);
            EXIT();
        }
        else
        {
            wclear(Game);
            mvwprintw(Game, tinggiGame - 2, 1, "Masukan pilihan Anda tidak valid\n");
        }
    }
}

int main()
{
    //Init Random Generator
    srand(time(NULL));
    //Init Layar
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