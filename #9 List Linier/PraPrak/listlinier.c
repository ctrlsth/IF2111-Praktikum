// NIM      : 18221171
// Nama     : Hans Stephano E
// Tanggal  : 05 November 2022
// Topik    : Pra-Prak 9 - #1
// Deskripsi: Implementasi "listliner.h"

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listlinier.h"

/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

// #include "boolean.h"

// #define Nil NULL

// typedef int infotype;
// typedef struct tElmtlist *address;
// typedef struct tElmtlist { 
// 	infotype info;
// 	address next;
// } ElmtList;
// typedef struct {
// 	address First;
// } List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *Sussy = (ElmtList *)malloc(sizeof(ElmtList));
    if (Sussy != Nil)
    {
        Next(Sussy) = Nil;
        Info(Sussy) = X;
    }
    return Sussy;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address p = First(L);
    while (p != Nil)
    {
        if (Info(p) == X)
        {
            return p;
        }
        else
        {
            p = Next(p);
        }
    }
    return p;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address p = Alokasi(X);
    if (p != Nil)
    {
        InsertFirst(L, p);
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address p = Alokasi(X);
    if (p != Nil)
    {
        InsertLast(L, p);   
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p;
    DelFirst(L, &p);
    (*X) = Info(p);
    Dealokasi(&p);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address p;
    DelLast(L, &p);
    (*X) = Info(p);
    Dealokasi(&p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (!IsEmpty(*L))
    {
        address sussy = First(*L);
        while (Next(sussy) != Nil)
        {
            sussy = Next(sussy);
        }
        Next(sussy) = P;
    }
    else
    {
        InsertFirst(L, P);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    (*P) = First(*L);
    if (First(*L) != Nil)
    {
        First(*L) = Next(*P);
    }
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address p = Search((*L), X);
    if (p != Nil)
    {
        if (p == First(*L))
        {
            DelFirst(L, &p);
            Dealokasi(&p);
        }
        else
        {
            address loc = First(*L);
            while (Next(loc) != p)
            {
                loc = Next(loc);
            }

            Next(loc) = Next(p);
            Dealokasi(&p);
        }
    }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address loc = First(*L);
    address prevLoc = loc;
    while (loc != Nil)
    {
        if (Next(loc) == Nil)
        {
            if (loc == prevLoc)
            {
                DelFirst(L, P);
            }
            else
            {
                (*P) = Next(prevLoc);
                Next(prevLoc) = Nil;
            }
        }
        prevLoc = loc;
        loc = Next(loc);
    }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(Next(Prec));
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address p = First(L);
    printf("[");
    while (p != Nil)
    {
        printf("%d", Info(p));
        p = Next(p);
        if (p != Nil)
        {
            printf(",");
        }
    }
    printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    address p = First(L);
    int i = 0;
    while (p != Nil)
    {
        i++;
        p = Next(p);
    }

    return i;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    address p = First(L);
    infotype maks = Info(p);
    while (p != Nil)
    {
        if (Info(p) > maks)
        {
            maks = Info(p);
        }
        p = Next(p);
    }
    return maks;
}
address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    infotype maks = Max(L);
    address p = First(L);
    while (Info(p) != maks)
    {
        p = Next(p);
    }
    return p;
}

infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    address p = First(L);
    infotype mins = Info(p);
    while (p != Nil)
    {
        if (Info(p) < mins)
        {
            mins = Info(p);
        }
        p = Next(p);
    }
    return mins;
}
address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    infotype mins = Min(L);
    address p = First(L);
    while (Info(p) != mins)
    {
        p = Next(p);
    }
    return p;
}
float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    float counter = 0;
    float sum = 0;
    address p = First(L);
    while (p != Nil)
    {
        sum += Info(p);
        counter++;
        p = Next(p);
    }
    return (sum/counter);
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    int i = 0, j;
    address loc;
    address array[NbElmt((*L))];
    address p = First(*L);
    while (p != Nil)
    {
        array[i] = p;
        i++;
        p = Next(p);
    }
    for (j = i-1; j >= 0; j--)
    {
        if (j == i-1)
        {
            First(*L) = array[j];
            loc = First(*L);
        }
        else
        {
            Next(loc) = array[j];
            loc = Next(loc);
        }
    }
    Next(loc) = Nil;
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    if (!IsEmpty(*L1) && IsEmpty(*L2))
    {
        First(*L3) = First(*L1);
        First(*L1) = Nil;
    }
    else if (IsEmpty(*L1) && !IsEmpty(*L2))
    {
        First(*L3) = First(*L2);
        First(*L2) = Nil; 
    }
    else if (!IsEmpty(*L1) && !IsEmpty(*L2))
    {
        InsertLast(L1, First(*L2));
        First(*L3) = First(*L1);
        First(*L1) = Nil;
        First(*L2) = Nil;
    }
}