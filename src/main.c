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
TabKata OrderanPelanggan, banyakOrangOrder, NamaBahan, XBahan, YBahan;
int noRuangan;
MATRIKS Room1, Room2, Room3, Room4, curRoom;
/* --------------- */
/* Deklarasi bbrp fungsi */
void ProgramMainMenu();
void UpdateCurRoom();
void UpdateRoomAwal();

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
    int banyakQueueCust = NBElmt(AntrianStar);
    for(int i = 0;i < banyakQueueCust;i++)
    {
        PELANGGAN temp;
        Del(&AntrianStar,&temp);
        if(Durasi(WaktuSekarang,WaktuCabut(temp))>0)
        {
            Add(&AntrianStar,temp);
        }else{
            nyawa -= 1;
        }
    }
    //Cek NonStar
    banyakQueueCust = NBElmt(AntrianNonStar);
    for(int i = 0;i < banyakQueueCust;i++)
    {
        PELANGGAN temp;
        Del(&AntrianNonStar,&temp);
        if(Durasi(WaktuSekarang,WaktuCabut(temp))>0)
        {
            Add(&AntrianNonStar,temp);
        }else{
            nyawa -= 1;
        }
    }
    //Cek Kesabaran customer dimeja
    banyakQueueCust = NBElmt(PelangganDiMeja);
    for(int i = 0;i < banyakQueueCust;i++)
    {
        PELANGGAN temp;
        Del(&PelangganDiMeja,&temp);
        if(Durasi(WaktuSekarang,WaktuCabut(temp))>0)
        {
            Add(&PelangganDiMeja,temp);
        }else{
            //Hapus dari tempatnya
            int noRuanganAwal = noRuangan;
            UpdateRoomAwal();
            noRuangan = Ruangan(temp);
            UpdateCurRoom();
            if(Banyak(temp) == 4)
            {
                ElmtMat(curRoom,Ordinat(Pos(temp))-1,Absis(Pos(temp))) = 'X';
                ElmtMat(curRoom,Ordinat(Pos(temp))+1,Absis(Pos(temp))) = 'X';
            }
            ElmtMat(curRoom,Ordinat(Pos(temp)),Absis(Pos(temp))-1) = 'X';
            ElmtMat(curRoom,Ordinat(Pos(temp)),Absis(Pos(temp))+1) = 'X';
            UpdateRoomAwal();
            noRuangan = noRuanganAwal;
            UpdateCurRoom();
            //Hapus dari List Order jika sudah mengorder
            if(SudahOrder(temp))
            {
                boolean ketemu = false;
                int i = GetFirstIdx(OrderanPelanggan);
                while(i <= GetLastIdx(OrderanPelanggan) && !ketemu)
                {
                    if(IsSameString(Orderan(temp).TabKata,Elmt(OrderanPelanggan,i).TabKata))
                    {
                        ketemu = true;
                        //Hapus dari array orderan dan banyak orang order
                        Kata tempKata;
                        DelEli(&OrderanPelanggan,i,&tempKata);
                        DelEli(&banyakOrangOrder,i,&tempKata);
                    }else{
                        i += 1;
                    }
                }
            }
            //Nyawa --
            nyawa -= 1;
        }
    }
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
    //Gambar Default String di game
    mvwprintw(Game, 1, 3, "Nama : ");
    mvwprintw(Game, 1, 10, namaUser);
    mvwprintw(Game, 1, 33, "Uang : ");
    char stringTemp[10];
    sprintf(stringTemp, "%ld", uang);
    mvwprintw(Game, 1, 40, stringTemp);
    mvwprintw(Game, 1, 63, "Nyawa : ");
    sprintf(stringTemp, "%ld", nyawa);
    mvwprintw(Game, 1, 70, stringTemp);
    mvwprintw(Game, 1, 93, "Waktu : ");
    sprintf(stringTemp, "%ld", JAMToDetik(WaktuSekarang));
    mvwprintw(Game, 1, 100, stringTemp);
    mvwprintw(Game, 3, 33, "Player : ");
    char posPlayer[10];
    sprintf(posPlayer, "%d, %d", player.X, player.Y);
    mvwprintw(Game, 3, 41, posPlayer);
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
    mvwprintw(Game, 3, 3, "Antrean Customer");
    int banyakAntreanStar = NBElmt(AntrianStar);
    for (int i = 0; i < banyakAntreanStar; i++)
    {
        PELANGGAN temp;
        Del(&AntrianStar, &temp);
        //Tulis di layar
        char banyakOrang[5];
        sprintf(banyakOrang, "%d*", Banyak(temp));
        mvwprintw(Game, 4 + i, 3, banyakOrang);
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
        mvwprintw(Game, 4 + i + banyakAntreanStar, 3, banyakOrang);
        //Balikan ke antrean
        Add(&AntrianNonStar, temp);
    }
    //Gambar Orderan
    mvwprintw(Game, (int)tinggiGame / 2 + 1, 3, "Order");
    for (int i = GetFirstIdx(OrderanPelanggan); i <= GetLastIdx(OrderanPelanggan); i++)
    {
        char tulisOrder[1010];
        sprintf(tulisOrder, "%s %s", Elmt(OrderanPelanggan, i).TabKata, Elmt(banyakOrangOrder, i).TabKata);
        mvwaddnstr(Game, (int)tinggiGame / 2 + 1 + i, 3, tulisOrder, 29);
    }
    //Gambar FoodStack
    mvwprintw(Game, 3, 93, "Food Stack");
    int bStack = 1;
    Stack tempStack;
    CreateEmptyStack(&tempStack);
    while (!IsEmptyStack(Food))
    {
        mvwprintw(Game, 3 + bStack, 93, InfoTop(Food).TabKata);
        Kata temp;
        Pop(&Food, &temp);
        Push(&tempStack, temp);
        bStack += 1;
    }
    while (!IsEmptyStack(tempStack))
    {
        Kata temp;
        Pop(&tempStack, &temp);
        Push(&Food, temp);
    }
    //Gambar HandStack
    mvwprintw(Game, (int)tinggiGame / 2 + 1, 93, "Hand Stack");
    bStack = 1;
    while (!IsEmptyStack(Hand))
    {
        mvwprintw(Game, (int)tinggiGame / 2 + 1 + bStack, 93, InfoTop(Hand).TabKata);
        Kata temp;
        Pop(&Hand, &temp);
        Push(&tempStack, temp);
        bStack += 1;
    }
    while (!IsEmptyStack(tempStack))
    {
        Kata temp;
        Pop(&tempStack, &temp);
        Push(&Hand, temp);
    }
}

void UpdateRoomAwal()
{
    switch (noRuangan)
    {
    case 1:
        CopyMATRIKS(curRoom,&Room1);
        break;
    case 2:
        CopyMATRIKS(curRoom,&Room2);
        break;
    case 3:
        CopyMATRIKS(curRoom,&Room3);
        break;
    case 4:
        CopyMATRIKS(curRoom,&Room4);
        break;
    default:
        break;
    }
}

void UpdateCurRoom()
{
    switch (noRuangan)
    {
    case 1:
        CopyMATRIKS(Room1,&curRoom);
        break;
    case 2:
        CopyMATRIKS(Room2,&curRoom);
        break;
    case 3:
        CopyMATRIKS(Room3,&curRoom);
        break;
    case 4:
        CopyMATRIKS(Room4,&curRoom);
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
                     &nyawa, &WaktuSekarang, &player, &noRuangan, &OrderanPelanggan, &banyakOrangOrder,
                     &PelangganDiMeja, &Room1, &Room2, &Room3, &Room4, &Stage, &PohonMakanan,
                     &Food, &Hand);
        UpdateCurRoom();
    }
}

void NewGame()
{
    mvwprintw(MainMenu, 9, 3, "Masukkan Nama Chef : ");
    wgetstr(MainMenu, namaUser);
    sudahInputNama = true;
}

void LoadGame()
{
    mvwprintw(MainMenu, 9, 3, "Masukkan Nama Save : ");
    wgetstr(MainMenu, namaUser);
    char letakSave[50];
    sprintf(letakSave, "../save/%s.txt", namaUser);
    FILE *fp = fopen(letakSave, "r");
    if (fp != NULL)
    {
        sudahInputNama = true;
        BacaSaveGame(letakSave, &AntrianNonStar, &AntrianStar, &uang,
                     &nyawa, &WaktuSekarang, &player, &noRuangan, &OrderanPelanggan, &banyakOrangOrder,
                     &PelangganDiMeja, &Room1, &Room2, &Room3, &Room4, &Stage, &PohonMakanan,
                     &Food, &Hand);
        UpdateCurRoom();
        gameLoaded = true;
        wclear(MainMenu);
        mvwprintw(MainMenu, 9, 3, "Game Loaded\n");
        ProgramMainMenu();
        fclose(fp);
    }
    else
    {
        wclear(MainMenu);
        mvwprintw(MainMenu, 9, 3, "Save Not Found\n");
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
        mvwprintw(MainMenu, startY + 10, startX, "Start Game untuk mulai permainan");
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
        PrintMainMenu(3, 1);
        PrintBoxMainMenu();
        wgetstr(MainMenu, pilihanMenu);
        pilihan = IsPilihanMenuValid(pilihanMenu);
        if (pilihan == 5)
        {
            wclear(MainMenu);
            mvwprintw(MainMenu, 8, 3, "Masukan pilihan Anda tidak valid\n");
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
            mvwprintw(MainMenu, 9, 3, "Input nama dulu\n");
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
            mvwprintw(Game, tinggiGame - 2, 3, "Kamu menabrak tembok\n");
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
            mvwprintw(Game, tinggiGame - 2, 3, "Kamu menabrak tembok\n");
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
            mvwprintw(Game, tinggiGame - 2, 3, "Kamu menabrak tembok\n");
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
            mvwprintw(Game, tinggiGame - 2, 3, "Kamu menabrak tembok\n");
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

POINT NearestTable(char cari)
{
    boolean ketemu = false;
    POINT meja = MakePOINT(-1, -1);
    for (int i = Ordinat(player) - 1; i <= Ordinat(player) + 1 && !ketemu; i++)
    {
        for (int j = Absis(player) - 1; j <= Absis(player) + 1 && !ketemu; j++)
        {
            if (IsIdxEffMat(curRoom, i, j))
            {
                if (ElmtMat(curRoom, i, j) == cari)
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
    return meja;
}

void ORDER()
{
    //Cek Sekeliling apakah ada meja
    //Cek kiri
    POINT meja = NearestTable('C');
    boolean ketemu = !PointEQ(meja, MakePOINT(-1, -1));
    if (ketemu)
    {
        addressQueue i = Head(PelangganDiMeja);
        while ((!PointEQ(Pos(InfoQueue(PelangganDiMeja, i)), meja)) || (Ruangan(InfoQueue(PelangganDiMeja, i)) != noRuangan))
        {
            if (i == MaxElQueue(PelangganDiMeja))
            {
                i = 1;
            }
            else
            {
                i += 1;
            }
        }
        if (SudahOrder(InfoQueue(PelangganDiMeja, i)))
        {
            mvwprintw(Game, tinggiGame - 2, 1, "Customer tersebut sudah diambil order-nya\n");
        }
        else
        {
            Orderan(InfoQueue(PelangganDiMeja, i)) = GetDaunAcak(PohonMakanan);
            SudahOrder(InfoQueue(PelangganDiMeja, i)) = true;
            AddAsLastEl(&OrderanPelanggan, Orderan(InfoQueue(PelangganDiMeja, i)));
            char s[2];
            if (Banyak(InfoQueue(PelangganDiMeja, i)) == 2)
            {
                s[0] = '2';
                s[1] = '\000';
            }
            else
            {
                s[0] = '4';
                s[1] = '\000';
            }
            STARTKATAB(s);
            AddAsLastEl(&banyakOrangOrder, CKataB);
        }
    }
    else
    {
        mvwprintw(Game, tinggiGame - 2, 1, "Tidak ada customer disekitarmu\n");
    }
}

void PUT()
{
    if (IsFullStack(Food)){
        mvwprintw(Game, tinggiGame - 2, 1, "Food Stack milikmu sudah penuh sehingga tidak bisa menampung makanan lagi\n");
    }
    else{
        if (IsEmptyStack(Hand)){
            mvwprintw(Game, tinggiGame - 2, 1, "Tidak ada bahan makanan pada tanganmu, sehingga tidak ada yang bisa ditaruh ke tray\n");
        }
        else{
            BinTree P = PohonMakanan;
            Stack TempStack = Hand;
            Stack S;
            Kata temp;
            while (!IsEmptyStack(Hand)){
                Pop(&Hand,&temp);
                Push(&S, temp);
            }
            boolean fail = false;
            Pop(&S, &temp);
            if (!IsSameKata(temp, Akar(P))){
                fail = true;
            }
            while ((!IsEmptyStack(S)) && (!IsTreeOneElmt(Left(P)) || !IsTreeOneElmt(Right(P))) && (!fail)){
                Pop(&S, &temp);
                if (IsSameKata(Akar(Right(P)), temp)){
                    P = Right(P);
                }
                else if (IsSameKata(Akar(Left(P)), temp)){
                    P = Left(P);
                }
                else{
                    fail = true;
                }
            }
            if (IsTreeOneElmt(Left(P))){
                P = Left(P);
            }
            else if (IsTreeOneElmt(Right(P))){
                P = Right(P);
            }
            else{
                fail = true;
            }
            if(!IsEmptyStack(S)){
                fail = true;
            }
            if (fail){
                mvwprintw(Game, tinggiGame - 2, 1, "Tidak ada resep yang sesuai dengan stack bahan makanan di tanganmu\n");
                Hand = TempStack;
            }
            else{
                CreateEmptyStack(&Hand);
                Push(&Food, Akar(P));
            }
        }
    }
}

void TAKE()
{
    if (IsFullStack(Hand)){
        mvwprintw(Game, tinggiGame - 2, 1, "Tanganmu sudah penuh, tidak bisa mengambil bahan makanan lagi\n");
    }
    else{
        IdxType i = GetFirstIdx(NamaBahan);
        boolean found;
        POINT temp;
        while ((!found)&&(i<=GetLastIdx(NamaBahan))){
            temp = MakePOINT(StringToLongInt(Elmt(XBahan, i).TabKata), StringToLongInt(Elmt(YBahan, i).TabKata));
            if (PointEQ(temp, PrevX(player)) || PointEQ(temp, NextX(player)) || PointEQ(temp, PrevY(player)) || PointEQ(temp, NextY(player))){
                found = true;
            }
            else{
                i += 1;
            }
        }
        Push(&Hand, Elmt(NamaBahan, i));
    }
}

void CH()
{
    if (IsEmptyStack(Hand)){
        mvwprintw(Game, tinggiGame - 2, 1, "Tanganmu sudah kosong dari bahan makanan, tidak ada lagi yang bisa dijatuhkan\n");
    }
    else{
        CreateEmptyStack(&Hand);
    }
}

void CT()
{
    if (IsEmptyStack(Food)){
        mvwprintw(Game, tinggiGame - 2, 1, "Tidak ada makanan yang bisa kamu jatuhkan dari food stack milikmu yang kosong\n");
    }
    else{
        CreateEmptyStack(&Food);
    }
}

void PLACE()
{
    //Cek Sekeliling apakah ada meja
    //Cek kiri
    POINT meja = NearestTable('X');
    boolean ketemu = !PointEQ(meja, MakePOINT(-1, -1));
    if (ketemu)
    {
        PELANGGAN cek;
        if (IsEmptyQueue(AntrianStar))
        {
            if (IsEmptyQueue(AntrianNonStar))
            {
                mvwprintw(Game, tinggiGame - 2, 3, "Tidak ada pelanggan untuk ditaruh\n");
            }
            else
            {
                cek = InfoHead(AntrianNonStar);
            }
        }
        else
        {
            cek = InfoHead(AntrianStar);
        }
        //Cek muat
        int cekX = Absis(meja), cekY = Ordinat(meja) - 1;
        if (IsIdxEffMat(curRoom, cekY, cekX) && ElmtMat(curRoom, cekY, cekX) == 'X')
        {
            //Meja untuk ber 4
            //Taruh pelanggan di meja itu
            PELANGGAN taruh;
            if (IsStar(cek))
            {
                Del(&AntrianStar, &taruh);
            }
            else
            {
                Del(&AntrianNonStar, &taruh);
            }
            Ruangan(taruh) = noRuangan;
            Pos(taruh) = meja;
            WaktuCabut(taruh) = NextNDetik(WaktuSekarang, rand() % 10 + 30);
            Add(&PelangganDiMeja, taruh);
            if (Banyak(taruh) == 4)
            {
                ElmtMat(curRoom, Ordinat(meja) - 1, Absis(meja)) = 'C';
                ElmtMat(curRoom, Ordinat(meja) + 1, Absis(meja)) = 'C';
            }
            ElmtMat(curRoom, Ordinat(meja), Absis(meja) - 1) = 'C';
            ElmtMat(curRoom, Ordinat(meja), Absis(meja) + 1) = 'C';
            UpdateRoomAwal();
        }
        else
        {
            //Meja untuk ber 2
            if (Banyak(cek) == 2)
            {
                PELANGGAN taruh;
                if (IsStar(cek))
                {
                    Del(&AntrianStar, &taruh);
                }
                else
                {
                    Del(&AntrianNonStar, &taruh);
                }
                Ruangan(taruh) = noRuangan;
                Pos(taruh) = meja;
                WaktuCabut(taruh) = NextNDetik(WaktuSekarang, rand() % 10 + 30);
                Add(&PelangganDiMeja, taruh);
                ElmtMat(curRoom, Ordinat(meja), Absis(meja) - 1) = 'C';
                ElmtMat(curRoom, Ordinat(meja), Absis(meja) + 1) = 'C';
                UpdateRoomAwal();
            }
            else
            {
                //Ga muat
                mvwprintw(Game, tinggiGame - 2, 3, "Meja tidak muat\n");
            }
        }
    }
    else
    {
        mvwprintw(Game, tinggiGame - 2, 3, "Tidak ada meja kosong disekitarmu\n");
    }
}

void GIVE()
{
    if (IsEmptyStack(Food))
    {
        mvwprintw(Game, tinggiGame - 2, 1, "Tidak ada makanan yang bisa diberi ke customer padamu\n");
    }
    else
    {
        POINT meja = NearestTable('C');
        POINT undef = MakePOINT(-1, -1);
        if (PointEQ(meja, undef))
        {
            mvwprintw(Game, tinggiGame - 2, 1, "Tidak ada customer yang diberi makanan olehmu didekatmu\n");
        }
        else
        {
            addressQueue i = Head(PelangganDiMeja);
            while ((!PointEQ(Pos(InfoQueue(PelangganDiMeja, i)), meja)) || (Ruangan(InfoQueue(PelangganDiMeja, i)) != noRuangan))
            {
                i += 1;
            }
            if (IsSameKata(InfoTop(Food), Orderan(InfoQueue(PelangganDiMeja, i))))
            {
                Kata dummy;
                Queue newQ;
                PELANGGAN temp;
                PELANGGAN Delete = InfoQueue(PelangganDiMeja, i);
                Pop(&Food, &dummy);
                CreateEmptyQueue(&newQ, MaxElQueue(PelangganDiMeja));
                while (!IsEmptyQueue(PelangganDiMeja))
                {
                    Del(&PelangganDiMeja, &temp);
                    if ((!PointEQ(Pos(temp), Pos(Delete))) || (Ruangan(temp) != Ruangan(Delete)))
                    {
                        Add(&newQ, temp);
                    }
                }
                DeAlokasi(&PelangganDiMeja);
                PelangganDiMeja = newQ;
                uang += Level(PohonMakanan, Orderan(Delete)) * 1000;
            }
            else
            {
                mvwprintw(Game, tinggiGame - 2, 1, "Orderan customer dan makanan paling atas di food stack harus sama untuk bisa memberi\n");
            }
        }
    }
}

void RECIPE(BinTree Pohon, int h, int XAwal, int YAwal)
{
    if (IsTreeOneElmt(Pohon))
    {
        mvwaddnstr(Game, YAwal, XAwal, Akar(Pohon).TabKata, 50);
    }
    else
    {
        if (!IsTreeEmpty(Pohon))
        {
            int dYUntukRight = 1;
            if (Left(Pohon) != Nil && Right(Pohon) != Nil)
            {
                dYUntukRight += NbElmtTree(Left(Pohon));
            }
            mvwvline(Game, YAwal + 1, XAwal + 1, 0, dYUntukRight);
            mvwaddnstr(Game, YAwal, XAwal, Akar(Pohon).TabKata, 50);
            RECIPE(Left(Pohon), h, XAwal + h, YAwal + 1);
            RECIPE(Right(Pohon), h, XAwal + h, YAwal + dYUntukRight);
            if (IsUnerLeft(Pohon) || IsUnerRight(Pohon))
            {
                mvwaddch(Game, YAwal + 1, XAwal + 1, ACS_LLCORNER);
                mvwhline(Game, YAwal + 1, XAwal + 2, 0, 1);
            }
            else
            {
                mvwaddch(Game, YAwal + 1, XAwal + 1, ACS_LTEE);
                mvwhline(Game, YAwal + 1, XAwal + 2, 0, 1);
                mvwaddch(Game, YAwal + dYUntukRight, XAwal + 1, ACS_LLCORNER);
                mvwhline(Game, YAwal + dYUntukRight, XAwal + 2, 0, 1);
            }
        }
    }
}

void SAVE()
{
    char letakSave[50];
    sprintf(letakSave, "../save/%s.txt", namaUser);
    TulisSaveGame(letakSave, AntrianNonStar, AntrianStar, uang,
                  nyawa, WaktuSekarang, player, noRuangan, OrderanPelanggan, banyakOrangOrder,
                  PelangganDiMeja, Room1, Room2, Room3, Room4, Stage, PohonMakanan,
                  Food, Hand);
    mvwprintw(Game, tinggiGame - 2, 3, "Save berhasil\n");
}

void LOAD()
{
    char tempNama[50];
    mvwprintw(Game, tinggiGame - 2, 3, "Masukan nama save : ");
    mvwgetstr(Game, tinggiGame - 2, 23, tempNama);
    char letakSave[50];
    sprintf(letakSave, "../save/%s.txt", tempNama);
    FILE *fp = fopen(letakSave, "r");
    if (fp != NULL)
    {
        sudahInputNama = true;
        BacaSaveGame(letakSave, &AntrianNonStar, &AntrianStar, &uang,
                     &nyawa, &WaktuSekarang, &player, &noRuangan, &OrderanPelanggan, &banyakOrangOrder,
                     &PelangganDiMeja, &Room1, &Room2, &Room3, &Room4, &Stage, &PohonMakanan,
                     &Food, &Hand);
        UpdateCurRoom();
        gameLoaded = true;
        wclear(Game);
        mvwprintw(Game, tinggiGame - 2, 3, "Game Loaded\n");
        fclose(fp);
    }
    else
    {
        wclear(Game);
        mvwprintw(Game, tinggiGame - 2, 3, "Save not found\n");
    }
}

void BacaCommand()
{
    char InputUser[10];
    while (isGameOn)
    {
        UpdateGambar();
        //PrintCommand();
        mvwprintw(Game, tinggiGame - 3, 3, "Masukan pilihan Anda : ");
        wrefresh(Game);
        wgetstr(Game, InputUser);
        if (IsSameString(InputUser, "GU"))
        {
            wclear(Game);
            GU();
            UpdateData();
        }
        else if (IsSameString(InputUser, "GD"))
        {
            wclear(Game);
            GD();
            UpdateData();
        }
        else if (IsSameString(InputUser, "GL"))
        {
            wclear(Game);
            GL();
            UpdateData();
        }
        else if (IsSameString(InputUser, "GR"))
        {
            wclear(Game);
            GR();
            UpdateData();
        }
        else if (IsSameString(InputUser, "ORDER"))
        {
            wclear(Game);
            ORDER();
            UpdateData();
        }
        else if (IsSameString(InputUser, "PUT"))
        {
            wclear(Game);
            PUT();
            UpdateData();
        }
        else if (IsSameString(InputUser, "TAKE"))
        {
            wclear(Game);
            TAKE();
            UpdateData();
        }
        else if (IsSameString(InputUser, "CH"))
        {
            wclear(Game);
            CH();
            UpdateData();
        }
        else if (IsSameString(InputUser, "CT"))
        {
            wclear(Game);
            CT();
            UpdateData();
        }
        else if (IsSameString(InputUser, "PLACE"))
        {
            wclear(Game);
            PLACE();
            UpdateData();
        }
        else if (IsSameString(InputUser, "GIVE"))
        {
            wclear(Game);
            GIVE();
            UpdateData();
        }
        else if (IsSameString(InputUser, "RECIPE"))
        {
            wclear(Game);
            rectangle(Game, 0, 0, tinggiGame - 1, lebarGame - 1);
            RECIPE(PohonMakanan, 3, 123, 3);
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
            mvwprintw(Game, tinggiGame - 2, 3, "Masukan pilihan Anda tidak valid\n");
            UpdateData();
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