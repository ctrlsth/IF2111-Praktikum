// NIM              : 18221171
// Nama             : Hans Stephano E
// Tanggal          : 08 Desember 2022
// Topik praktikum  : Pasca Praktikum 7 - #2
// Deskripsi        : Implementasi Selisih Big Integer

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack Sussy;
    CreateEmpty(&Sussy);
    Stack Baka;
    CreateEmpty(&Baka);
    char S1[100], S2[100];
    scanf("%s", S1);
    scanf("%s", S2);

    int i = 0;
    while (S1[i] != '\0')
    {
        int x = S1[i] - '0';
        Push(&Sussy, x);
        i++;
    }
    int lengthS1 = i;
    // printf("lengthS1 = %d\n", lengthS1);

    i = 0;
    while (S2[i] != '\0')
    {
        int x = S2[i] - '0';
        Push(&Baka, x);
        i++;
    }
    int lengthS2 = i;
    // printf("lengthS2 = %d\n", lengthS2);

    boolean negative = false;
    Stack Amogus, num1, num2;
    CreateEmpty(&Amogus);
    CreateEmpty(&num1);
    CreateEmpty(&num2);
    if (lengthS1 > lengthS2)
    {
        num1 = Sussy;
        num2 = Baka;
        // printf("Passed\n");
    }
    else if (lengthS2 > lengthS1)
    {
        num1 = Baka;
        num2 = Sussy;
        negative = true;
    }
    else
    {
        i = 0;
        while (S1[i] == S2[i] && i < lengthS1)
        {
            i++;
        }
        if (i == lengthS1)
        {
            printf("0\n");
            return 0;
        }
        else
        {
            if (S1[i] > S2[i])
            {
                num1 = Sussy;
                num2 = Baka;
            }
            else
            {
                num2 = Sussy;
                num1 = Baka;
                negative = true;
            }
        }
    }

    i = 0;
    int tempDigit1, tempDigit2, pinjamDepan = 999;
    boolean passed = false;
    while (!IsEmpty(num2))
    {
        if (!passed)
        {
            Pop(&num1, &tempDigit1);
        }
        Pop(&num2, &tempDigit2);
        if (tempDigit2 > tempDigit1)
        {
            Pop(&num1, &pinjamDepan);
            pinjamDepan -= 1;
            tempDigit1 += 10;
            passed = true;
        }
        else
        {
            passed = false;
        }
        tempDigit1 -= tempDigit2;
        // printf("tempDigit1 -= tempDigit2 : %d\n", tempDigit1);
        Push(&Amogus, tempDigit1);
        if (passed)
        {
            tempDigit1 = pinjamDepan;
            pinjamDepan = 999;
        }
    }
    if (pinjamDepan != 999)
    {
        Push(&Amogus, pinjamDepan);
    }

    // printf("Passed.\n");
    // printf("%d\n", num1.TOP);
    while (!IsEmpty(num1))
    {
        // printf("In-Loop.\n");
        int tempo;
        Pop(&num1, &tempo);
        Push(&Amogus, tempo);
        // printf("Tempo: %d\n", tempo);
    }

    if (negative)
    {
        printf("-");
    }
    // printf("Passed Negative.\n");
    int nonZero = false;
    while (!IsEmpty(Amogus))
    {
        int tempo;
        Pop(&Amogus, &tempo);
        if (tempo != 0)
        {
            nonZero = true;
        }
        if (nonZero)
        {
            printf("%d", tempo);
        }
    }
    printf("\n");
    return 0;
}