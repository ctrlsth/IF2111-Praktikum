// NIM      : 18221171
// Nama     : Hans Stephano E
// Tanggal  : 05 November 2022
// Topik    : Pra-Prak 9 - #2
// Deskripsi: Implementasi "OddEvenList.h"

#include "listlinier.h"
#include "OddEvenList.h"
#include <stdio.h>
#include <stdlib.h>

void OddEvenList(List L, List *Odd, List *Even)
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/
{
    CreateEmpty(Even);
    CreateEmpty(Odd);

    address p = First(L);
    address n = Next(p);
    while (p != Nil)
    {
        if (Info(p) % 2 == 0)
        {
            InsVFirst(Even, Info(p));
        }
        else  // (Info(p) % 2 == 1)
        {
            InsVFirst(Odd, Info(p));
        }
        p = n;
        if (n != Nil)
        {
            n = Next(p);
        }
    }

    // printf("Not Sorted Even: ");
    // PrintInfo(*Even);
    // printf("\n");
    // printf("Not Sorted Odd: ");
    // PrintInfo(*Odd);
    // printf("\n");

    
    /* Sort Even */
    if (!IsEmpty(*Even))
    {
        List tempEven;
        CreateEmpty(&tempEven);
        address maxP = AdrMax(*Even);
        int i = 1;
        while (i < NbElmt(*Even))
        {
            address pPrev = First(*Even);
            p = First(*Even);
            while (p != maxP)
            {
                pPrev = p;
                p = Next(p);
            }
            if (p == pPrev)
            {
                DelFirst(Even, &maxP);
            }
            else
            {
                DelAfter(Even, &maxP, pPrev);
            }
            InsertFirst(&tempEven, maxP);
            maxP = AdrMax(*Even);

            // printf("#");
            // PrintInfo(*Even);
            // printf("#\n");
        }
        InsertFirst(&tempEven, maxP);
        // printf("Hasil Temp Even: ");
        // PrintInfo(tempEven);
        // printf("\n");
        First(*Even) = First(tempEven);
    }

    if (!IsEmpty(*Odd))
    {
        List tempOdd;
        CreateEmpty(&tempOdd);
        address maxP = AdrMax(*Odd);
        int i = 1;
        while (i < NbElmt(*Odd))
        {
            address pPrev = First(*Odd);
            p = First(*Odd);
            while (p != maxP)
            {
                pPrev = p;
                p = Next(p);
            }
            if (p == pPrev)
            {
                DelFirst(Odd, &maxP);
            }
            else
            {
                DelAfter(Odd, &maxP, pPrev);
            }
            InsertFirst(&tempOdd, maxP);
            maxP = AdrMax(*Odd);
        }
        InsertFirst(&tempOdd, maxP);
        // printf("Hasil Temp Odd: ");
        // PrintInfo(tempOdd);
        // printf("\n");
        First(*Odd) = First(tempOdd);
    }
}

/*
int main()
{
    List ok;
    CreateEmpty(&ok);
    InsVFirst(&ok, 1);
    // InsVFirst(&ok, 69);
    // InsVFirst(&ok, 5);
    // InsVFirst(&ok, 8);
    // InsVFirst(&ok, 12);
    // InsVFirst(&ok, 10);
    // InsVFirst(&ok, 6);
    // InsVFirst(&ok, 103);
    // InsVFirst(&ok, 4);
    // InsVFirst(&ok, 0);
    // InsVFirst(&ok, 55);
    // InsVFirst(&ok, 71);
    PrintInfo(ok);
    printf("\n");

    List even, odd;
    CreateEmpty(&even);
    CreateEmpty(&odd);

    // address p = First(ok);
    // address n = Next(p);
    // int i = 0;
    // while (p != Nil)
    // {
    //     if (Info(p) % 2 == 0)
    //     {
    //         InsertFirst(&even, p);
    //     }
    //     else  // (Info(p) % 2 == 1)
    //     {
    //         InsertFirst(&odd, p);
    //     }
    //     p = n;
    //     if (n != Nil)
    //     {
    //         n = Next(p);
    //     }
    //     i++;
    //     printf("Counter: %d\n", i);
    // }
    // printf("Apakah p Nil? : %d\n", (p == Nil));


    OddEvenList(ok, &odd, &even);
    PrintInfo(ok);
    printf("\n");
    PrintInfo(even);
    printf("\n");
    PrintInfo(odd);
    printf("\n");

    // printf("##############\n");
    // address p;
    // DelFirst(&ok, &p);
    // PrintInfo(ok);
    // printf("#\n");
    // DelFirst(&ok, &p);
    // PrintInfo(ok);
    // printf("#\n");DelFirst(&ok, &p);
    // PrintInfo(ok);
    // printf("#\n");DelFirst(&ok, &p);
    // PrintInfo(ok);
    // printf("#\n");DelFirst(&ok, &p);
    // PrintInfo(ok);
    // printf("#\n");DelFirst(&ok, &p);
    // PrintInfo(ok);
    // printf("#\n");
}
*/