// NIM		: 18221171
// Nama		: Hans Stephano E
// Tanggal	: 06 November 2022
// Topik	: Praktikum 9 - #1
// Deskripsi: Program implementasi cache dengan skema LRU

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main()
{
	int N, Q, i, check;
	scanf("%d", &N);
	scanf("%d", &Q);
	
	List sussy;
	CreateEmpty(&sussy);
	for (i = 1; i <= N; i++)
	{
		InsVLast(&sussy, i);
	}
	
	for (i = 1; i <= Q; i++)
	{
		scanf("%d", &check);
		address loc = Search(sussy, check);
		if (loc != Nil)
		{
			printf("hit ");
			DelP(&sussy, check);
			InsVFirst(&sussy, check);
		}
		else
		{
			printf("miss ");
			InsVFirst(&sussy, check);
			DelVLast(&sussy, &check);
		}
		
		PrintInfo(sussy);
		printf("\n");
	}
	
	return 0;
}
