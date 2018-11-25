#include "../include/matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(int NB, int NK, MATRIKS *M)
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValidMat(int i, int j)
{
	return (((BrsMin <= i) && (i <= BrsMax)) && ((KolMin <= j) && (j <= KolMax)));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs(MATRIKS M)
{
	return (BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol(MATRIKS M)
{
	return (KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs(MATRIKS M)
{
	return NBrsEff(M);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol(MATRIKS M)
{
	return NKolEff(M);
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEffMat(MATRIKS M, indeks i, indeks j)
{
	return (((GetFirstIdxBrs(M) <= i) && (i <= GetLastIdxBrs(M))) && ((GetFirstIdxKol(M) <= j) && (j <= GetLastIdxKol(M))));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS(MATRIKS MIn, MATRIKS *MHsl)
{
	// Kamus
	indeks i, j;
	// Algoritma
	MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), &(*MHsl));
	for (i = GetFirstIdxBrs(*MHsl); i <= GetLastIdxBrs(*MHsl); i++)
	{
		for (j = GetFirstIdxKol(*MHsl); j <= GetLastIdxKol(*MHsl); j++)
		{
			ElmtMat(*MHsl, i, j) = ElmtMat(MIn, i, j);
		}
	}
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS(MATRIKS *M, int NB, int NK)
{
	// Kamus
	indeks i, j;
	// Algoritma
	MakeMATRIKS(NB, NK, &(*M));
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
	{
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
		{
			scanf("%c", &ElmtMat(*M, i, j));
		}
	}
}
/* I.S. IsIdxValidMat(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS(MATRIKS M)
{
	// Kamus
	indeks i, j;
	// Algoritma
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			printf("%c", ElmtMat(M, i, j));
			if (j != GetLastIdxKol(M))
			{
				printf(" ");
			}
			else
			{
				if (i != GetLastIdxBrs(M))
				{
					printf("\n");
				}
			}
		}
	}
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ(MATRIKS M1, MATRIKS M2)
{
	// Kamus
	boolean eq;
	indeks i, j;
	// Algoritma
	if (!(NBElmtMATRIKS(M1) == NBElmtMATRIKS(M2)))
	{
		return false;
	}
	else
	{
		eq = true;
		i = GetFirstIdxBrs(M1);
		while ((eq) && (i <= GetLastIdxBrs(M1)))
		{
			j = GetFirstIdxKol(M1);
			while ((eq) && (j <= GetLastIdxBrs(M1)))
			{
				if (ElmtMat(M1, i, j) != ElmtMat(M2, i, j))
				{
					eq = false;
				}
				j++;
			}
			i++;
		}
		return eq;
	}
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmtMat(M1) = NBElmtMat(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ(MATRIKS M1, MATRIKS M2)
{
	return (!EQ(M1, M2));
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize(MATRIKS M1, MATRIKS M2)
{
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmtMATRIKS(MATRIKS M)
{
	return (NBrsEff(M) * NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar(MATRIKS M)
{
	return (NBrsEff(M) == NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri(MATRIKS M)
{
	// Kamus
	boolean simetris;
	indeks i, j;
	// Algoritma
	if (!IsBujurSangkar(M))
	{
		return false;
	}
	else
	{
		simetris = true;
		i = GetFirstIdxBrs(M);
		while ((simetris) && (i <= GetLastIdxBrs(M)))
		{
			j = GetFirstIdxKol(M) + i;
			while ((simetris) && (j <= GetLastIdxBrs(M)))
			{
				if (ElmtMat(M, i, j) != ElmtMat(M, j, i))
				{
					simetris = false;
				}
				j++;
			}
			i++;
		}
		return simetris;
	}
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
void Transpose(MATRIKS *M)
{
	// Kamus
	indeks i, j;
	ElTypeMat temp;
	// Algoritma
	for (i = GetFirstIdxBrs(*M); i < GetLastIdxBrs(*M); i++)
	{
		for (j = (GetFirstIdxKol(*M) + i); j <= GetLastIdxKol(*M); j++)
		{
			temp = ElmtMat(*M, i, j);
			ElmtMat(*M, i, j) = ElmtMat(*M, j, i);
			ElmtMat(*M, j, i) = temp;
		}
	}
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
