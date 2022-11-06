// NIM      : 18221171
// Nama     : Hans Stephano E
// Tanggal  : 05 November 2022
// Topik    : Pra-Prak 9 - #2
// Deskripsi: Program Daftar Nilai Kuliah
//          : Menerima masukan nilai hingga input di luar range nilai [0..100]
//          : Meampilkan output sesuai ketentuan

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

int main()
{
    List Sussy, copySussy;
    CreateEmpty(&Sussy);
    CreateEmpty(&copySussy);
    int masukan;
    scanf("%d", &masukan);
    while (masukan >= 0 && masukan <= 100)
    {
        InsVFirst(&Sussy, masukan);
        InsVLast(&copySussy, masukan);
        scanf("%d", &masukan);
    }

    if (IsEmpty(Sussy))
    {
        printf("Daftar nilai kosong\n");
    }
    else
    {
        printf("%d\n", NbElmt(Sussy));
        printf("%d\n", Max(Sussy));
        printf("%d\n", Min(Sussy));
        printf("%.2f\n", Average(Sussy));
        PrintInfo(copySussy);
        printf("\n");
        PrintInfo(Sussy);
        printf("\n");
    }

    return 0;
}