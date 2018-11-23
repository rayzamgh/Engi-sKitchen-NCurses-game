#include "../include/listrek.h"
#include "../include/mesinkatakomparasi.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Manajemen Memori *** */
addressListRek AlokasiListRek(infotypeLR X)
{
    addressListRek P = (addressListRek)malloc(sizeof(infotypeLR));
    if (P != Nil)
    {
        InfoListRek(P) = X;
        NextListRek(P) = Nil;
    }
    else
    {
        return Nil;
    }
}
/* Mengirimkan addressListRek hasil alokasiListRek sebuah elemen */
/* Jika alokasiListRek berhasil, maka addressListRek tidak Nil, dan misalnya menghasilkan P, 
  maka InfoListRek(P) = X, NextListRek(P) = Nil */
/* Jika alokasiListRek gagal, mengirimkan Nil */
void DealokasiListRek(addressListRek P)
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasiListRek/pengembalian addressListRek P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi ListRek */
int IsEmptyListRek(ListRek L)
{
    if (L == Nil)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmtListRek(ListRek L)
{
    //Cek Kosong
    if (IsEmptyListRek(L))
    {
        return 0;
    }
    else
    {
        if (NbElmtListRek(L) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotypeLR FirstElmtListRek(ListRek L)
{
    return InfoListRek(L);
}
/* Mengirimkan elemen pertama sebuah listRek L yang tidak kosong */
ListRek TailListRek(ListRek L)
{
    return NextListRek(L);
}
/* Mengirimkan listRek L tanpa elemen pertamanya, mungkin menjadi listRek kosong */

/* *** Konstruktor *** */
ListRek KonsoListRek(infotypeLR e, ListRek L)
{
    addressListRek P = AlokasiListRek(e);
    if (P == Nil)
    {
        return L;
    }
    else
    {
        NextListRek(P) = L;
        return P;
    }
}
/* Mengirimkan listRek L dengan tambahan e sebagai elemen pertamanya. 
e dialokasiListRek terlebih dahulu. Jika alokasiListRek gagal, mengirimkan L. */
ListRek KonsBListRek(ListRek L, infotypeLR e)
{
    addressListRek P = AlokasiListRek(e);
    if (P == Nil)
    {
        return L;
    }
    else
    {
        if (IsEmptyListRek(L) == 1)
        {
            return P;
        }
        else
        {
            //Cari akhir
            addressListRek awal = L;
            while (NextListRek(L) != Nil)
            {
                L = NextListRek(L);
            }
            NextListRek(L) = P;
            return awal;
        }
    }
}
/* Mengirimkan listRek L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasiListRek terlebih dahulu */
/* Jika alokasiListRek e gagal, mengirimkan L */

/* *** Operasi Lain *** */
ListRek CopyListRek(ListRek L)
{
    if (IsEmptyListRek(L) == 1)
    {
        return Nil;
    }
    else
    {
        ListRek hasil = AlokasiListRek(InfoListRek(L));
        addressListRek awal = hasil;
        L = NextListRek(L);
        while (L != Nil)
        {
            addressListRek P = AlokasiListRek(InfoListRek(L));
            if (P == Nil)
            {
                return L;
            }
            else
            {
                NextListRek(hasil) = P;
                hasil = NextListRek(hasil);
                L = NextListRek(L);
            }
        }
        return awal;
    }
}
/* Mengirimkan salinan listRek L (menjadi listRek baru) */
/* Jika ada alokasiListRek gagal, mengirimkan L */
void MCopyListRek(ListRek Lin, ListRek *Lout)
{
    if (IsEmptyListRek(Lin) == 1)
    {
        *Lout = Nil;
    }
    else
    {
        *Lout = CopyListRek(Lin);
    }
}
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
ListRek ConcatListRek(ListRek L1, ListRek L2)
{
    ListRek hasil = Nil;
    if (IsEmptyListRek(L1) == 0)
    {
        hasil = CopyListRek(L1);
        if (hasil == L1)
        {
            return Nil;
        }
        else
        {
            addressListRek P = hasil;
            while (NextListRek(P) != Nil)
            {
                P = NextListRek(P);
            }
            if (IsEmptyListRek(L2) == 1)
            {
                return hasil;
            }
            else
            {
                ListRek hasil2 = CopyListRek(L2);
                if (hasil2 == L2)
                {
                    return Nil;
                }
                else
                {
                    NextListRek(P) = hasil2;
                    return hasil;
                }
            }
        }
    }
    else
    {
        if (IsEmptyListRek(L2) == 0)
        {
            hasil = CopyListRek(L2);
            if (hasil == L2)
            {
                return Nil;
            }
            else
            {
                return hasil;
            }
        }
        else
        {
            return Nil;
        }
    }
}
/* Mengirimkan salinan hasil konkatenasi listRek L1 dan L2 (menjadi listRek baru) */
/* Jika ada alokasiListRek gagal, menghasilkan Nil */
void MConcatListRek(ListRek L1, ListRek L2, ListRek *LHsl)
{
    *LHsl = ConcatListRek(L1, L2);
}
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi listRek L1 dan L2 */
void PrintListRek(ListRek L)
{
    if (IsEmptyListRek(L) != 1)
    {
        while (L != Nil)
        {
            printf("%s\n", InfoListRek(L).TabKata);
            L = NextListRek(L);
        }
    }
}
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen listRek dicetak. */
int NbElmtListRek(ListRek L)
{
    int cnt = 0;
    while (L != Nil)
    {
        cnt++;
        L = NextListRek(L);
    }
    return cnt;
}
/* Mengirimkan banyaknya elemen listRek L, Nol jika L kosong */
boolean SearchListRek(ListRek L, infotypeLR X)
{
    if (IsEmptyListRek(L) == 1)
    {
        return false;
    }
    else
    {
        addressListRek P = L;
        while (NextListRek(P) != Nil && !IsSameString(InfoListRek(P).TabKata,X.TabKata))
        {
            P = NextListRek(P);
        }
        if (IsSameString(InfoListRek(P).TabKata,X.TabKata))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
/* Mengirim true jika X adalah anggota listRek, false jika tidak */