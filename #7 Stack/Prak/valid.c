// NIM              : 18221171
// Nama             : Hans Stephano E
// Tanggal          : 24 Oktober 2022
// Topik praktikum  : Praktikum 7 - #3
// Deskripsi        : Implementasi "valid.h"

#include <stdio.h>
#include <stdlib.h>
#include "valid.h"

Stack validParantheses(char* input, int length)
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/
{
	Stack Sussy;
	CreateEmpty(&Sussy);
	int i;
	int stateOpen = 0;
	char open, close;
	for (i = 0; i < length; i++)
	{
		if (stateOpen == 0)
		{
			if (input[i] != ')' && input[i] != ']' && input[i] != '}')
			{
				open = input[i];
				stateOpen = 1;
			}
		}
		else
		{
			close = input[i];
			if ((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}'))
			{
				Push(&Sussy, open);
				Push(&Sussy, close);
				stateOpen = 0;
			}
			else if (close == '(' || close == '{' || close == '[')
			{
				open = close;
			}
			else
			{
				stateOpen == 0;
			}
		}
	}
	return Sussy;
}
