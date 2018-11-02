/* 	NIM/Nama : 13517040/Ariel Ansa Razumardi
	Nama file : matriks.c
	Topik : Pra Praktikum 04
	Tanggal : 15 September 2018
	Deskripsi : Implementasi semua fungsi dan prosedur yang sudah didefinisikan di file matriks.h */


#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
		NBrsEff(*M) = NB;
		NKolEff(*M) = NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
	return ( ( (BrsMin <= i) && (i <=BrsMax) ) && ( (KolMin <= j) && (j <=KolMax) ) );
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
	return (BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
	return (KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
	return (BrsMin + NBrsEff(M) - 1);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
	return (KolMin + NKolEff(M) - 1);
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
	return ( ( (GetFirstIdxBrs(M) <= i) && (i <= GetLastIdxBrs(M)) ) && ( (GetFirstIdxKol(M) <= j) && (j <= GetLastIdxKol(M)) ) );
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
	return (Elmt(M, i, i));
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
	// Kamus
	indeks i, j;
	// Algoritma
	MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), &(*MHsl));
	for (i = GetFirstIdxBrs(*MHsl); i <= GetLastIdxBrs(*MHsl); i++) {
		for (j = GetFirstIdxKol(*MHsl); j <= GetLastIdxKol(*MHsl); j++) {
			Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
		}
	}
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
	// Kamus
	indeks i, j;
	// Algoritma
	MakeMATRIKS(NB, NK, &(*M));
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
			scanf("%c", &Elmt(*M, i, j));
		}
	}
}
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M){
	// Kamus
	indeks i, j;
	// Algoritma
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
			printf("%c", Elmt(M, i, j));
			if (j != GetLastIdxKol(M)){
				printf(" ");
			}
			else{
				if (i != GetLastIdxBrs(M)){
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

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
	// Kamus
	indeks i, j;
	// Algoritma
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
		for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
			Elmt(M1, i, j) += Elmt(M2, i, j);
		}
	}
	return M1;
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
	// Kamus
	indeks i, j;
	// Algoritma
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
		for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
			Elmt(M1, i, j) -= Elmt(M2, i, j);
		}
	}
	return M1;
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
	// Kamus
	MATRIKS tempM;
	indeks i, j, k;
	ElType temp;
	// Algoritma
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &tempM);
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
		for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++) {
			temp = 0;
			for (k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++) {
				temp += Elmt(M1, i, k) * Elmt(M2, k, j);
			}
			Elmt(tempM, i, j) = temp;
		}
	}
	return tempM;
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
	// Kamus
	indeks i, j;
	// Algoritma
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
			Elmt(M, i, j) *= X;
		}
	}
	return M;
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K){
	// Kamus
	indeks i, j;
	// Algoritma
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
			Elmt(*M, i, j) *= K;
		}
	}
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
	// Kamus
	boolean eq;
	indeks i, j;
	// Algoritma
	if (!(NBElmtMATRIKS(M1) == NBElmtMATRIKS(M2))){
		return false;
	}
	else{
		eq = true;
		i = GetFirstIdxBrs(M1);
		while ((eq) && (i <= GetLastIdxBrs(M1))){
			j = GetFirstIdxKol(M1);
			while ((eq) && (j <= GetLastIdxBrs(M1))){
				if (Elmt(M1, i, j) != Elmt(M2, i, j)){
					eq = false;
				}
				j++;
			}
			i++;
		}
		return eq;
	}
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2){
	return (!EQ(M1, M2));
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmtMATRIKS (MATRIKS M){
	return (NBrsEff(M) * NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
	return (NBrsEff(M) == NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
	// Kamus
	boolean simetris;
	indeks i, j;
	// Algoritma
	if (!IsBujurSangkar(M)){
		return false;
	}
	else{
		simetris = true;
		i = GetFirstIdxBrs(M);
		while ((simetris) && (i <= GetLastIdxBrs(M))){
			j = GetFirstIdxKol(M) + i;
			while ((simetris) && (j <= GetLastIdxBrs(M))){
				if (Elmt(M, i, j) != Elmt(M, j, i)){
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
boolean IsSatuan (MATRIKS M){
	// Kamus
	boolean satuan;
	indeks i, j;
	// Algoritma
	if (!IsBujurSangkar(M)){
		return false;
	}
	else{
		satuan = true;
		i = GetFirstIdxBrs(M);
		while ((satuan) && (i < GetLastIdxBrs(M))){
			j = GetFirstIdxKol(M);
			while ((satuan) && (j <= GetLastIdxBrs(M))){
				if ((i == j) && (Elmt(M, i, j) != 1)){
					satuan = false;
				}
				else if ((i != j) && (Elmt(M, i, j) != 0)){
					satuan = false;
				}
				j++;
			}
			i++;
		}
		return satuan;
	}
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean IsSparse (MATRIKS M){
	// Kamus
	indeks i, j;
	int count  = 0;
	// Algoritma
	for (i = GetFirstIdxBrs(M); i < GetLastIdxBrs(M); i++){
		for(j = (GetFirstIdxKol(M) + i); j <= GetLastIdxKol(M); j++){
			if (Elmt(M, i, j) != 0){
				count++;
			}
		}
	}
	return (((float) count / NBElmtMATRIKS(M)) <= 0.05);
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
MATRIKS Inverse1 (MATRIKS M){
		return (KaliKons(M, -1));
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M){
	// Kamus
	indeks i, j, k, l;
	float sum  = 0;
	MATRIKS temp;
	boolean passj;
	// Algoritma
	if (NBElmtMATRIKS(M) == 1){
		return ((float) Elmt(M, 1, 1));
	}
	else{
		i = 1;
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
			MakeMATRIKS(NBrsEff(M) - 1, NKolEff(M) - 1, &temp);
			for (k = GetFirstIdxBrs(temp); k <= GetLastIdxBrs(temp); k++){
				passj = false;
				for(l = GetFirstIdxKol(temp); l <= GetLastIdxKol(temp); l++){
					if (l == j){
						passj = true;
					}
					if (passj){
						Elmt(temp, k , l) = Elmt(M, k+1, l+1);
					}
					else{
						Elmt(temp, k , l) = Elmt(M, k+1, l);
					}
				}
			}
			if ((j%2) == 0){
				sum -= Determinan(temp) * Elmt(M, i, j);
			}
			else{
				sum += Determinan(temp) * Elmt(M, i, j);
			}
		}
		return sum;
	}
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M){
	PKaliKons(&(*M), -1);
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
	// Kamus
	indeks i, j;
	ElType temp;
	// Algoritma
	for (i = GetFirstIdxBrs(*M); i < GetLastIdxBrs(*M); i++){
		for(j = (GetFirstIdxKol(*M) + i); j <= GetLastIdxKol(*M); j++){
			temp = Elmt(*M, i, j);
			Elmt(*M, i, j) = Elmt(*M, j, i);
			Elmt(*M, j, i) = temp;
		}
	}
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
