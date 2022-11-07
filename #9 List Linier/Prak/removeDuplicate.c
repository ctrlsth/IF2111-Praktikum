// NIM		: 18221171
// Nama		: Hans Stephano E
// Tanggal	: 06 November 2022
// Topik	: Praktikum 9 - #3
// Deskripsi: Implementasi "removeDuplicate.h"

#include "listlinier.h"

List removeDuplicate(List l)

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/
{
	List sussy;
	CreateEmpty(&sussy);
	
	int i = NbElmt(l);
	while (i != 0)
	{
		int X;
		DelVFirst(&l, &X);
		if (Search(sussy, X) == Nil)
		{
			InsVLast(&sussy, X);
		}
		InsVLast(&l, X);
		i--;
	}
	
	return sussy;
}
