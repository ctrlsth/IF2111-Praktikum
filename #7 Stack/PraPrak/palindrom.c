// NIM              : 18221171
// Nama             : Hans Stephano E
// Tanggal          : 21 Oktober 2022
// Topik praktikum  : Pra-Praktikum 7 - #2
// Deskripsi        : Implementasi "palindrom.c"

#include <stdio.h>
#include "stack.h"

int main()
{
    int i, j, store = 0, reversed = 0;
    boolean Passed = false;
    Stack Sussy;
    CreateEmpty(&Sussy);
    while (i != 0)
    {
        scanf("%d", &i);
        if (i != 0)
        {
            Passed = true;
            Push(&Sussy, i);
            store = store * 10 + i;
        }
        else
        {
            while (Top(Sussy) != Nil)
            {
                Pop(&Sussy, &j);
                reversed = reversed * 10 + j;
            }
        }
    }

    if (Passed)
    {
        if (reversed == store)
        {
            printf("Palindrom\n");
        }
        else
        {
            printf("Bukan Palindrom\n");
        }
    }
    else
    {
        printf("Stack kosong\n");
    }

    return 0;
}