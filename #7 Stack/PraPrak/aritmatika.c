// NIM              : 18221171
// Nama             : Hans Stephano E
// Tanggal          : 21 Oktober 2022
// Topik praktikum  : Pra-Praktikum 7 - #3
// Deskripsi        : Implementasi "aritmatika.h"

// #include "stack.h"
// #include "boolean.h"
// #include "string.h"
// #include "stdlib.h"
#include "aritmatika.h"

boolean isOperator(char input)
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/
{
    return (input == '+' || input == '-' || input == '*' || input == '/');
}

int hitung(int angka1, int angka2, char op)
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/
{
    if (op == '+')
    {
        return (angka1 + angka2);
    }
    else if (op == '-')
    {
        return (angka1 - angka2);
    }
    else if (op == '*')
    {
        return (angka1 * angka2);
    }
    else if (op == '/')
    {
        return (angka1 / angka2);
    }
}

int eval(char *input, int length)
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)
*/
{
    int ctr = 0;
    int angka1, angka2;
    Stack Sussy;
    CreateEmpty(&Sussy);
    while (ctr != length)
    {
        // printf("Loop %d\n", ctr);
        if (!isOperator((*input)))
        {
            // printf("Pass Push %d\n", ctr);
            Push(&Sussy, ((int)(*input) - 48));
            // printf("Pushed: %d\n", ((int)(*input) - 48));
        }
        else
        {
            Pop(&Sussy, &angka2);
            // printf("Pop angka2: %d\n", angka2);
            Pop(&Sussy, &angka1);
            // printf("Pop angka1: %d\n", angka1);
            // printf("%c\n", (*input));
            Push(&Sussy, hitung(angka1, angka2, (*input)));
            // printf("Push Hasil: %d\n", hitung(angka1, angka2, (*input)));
        }
        input++;
        ctr++;
    }
    Pop(&Sussy, &angka1);
    return angka1;
}