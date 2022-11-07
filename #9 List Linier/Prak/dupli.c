#include <stdio.h>
#include <stdlib.h>
#include "removeDuplicate.c"

int main()
{
	List a, b;
	CreateEmpty(&a);
	InsVLast(&a, 1);
	InsVLast(&a, 1);
	InsVLast(&a, 2);
	InsVLast(&a, 2);
	InsVLast(&a, 3);
	InsVLast(&a, 4);
	InsVLast(&a, 5);
	InsVLast(&a, 6);
	InsVLast(&a, 6);
	InsVLast(&a, 7);
	
	b = removeDuplicate(a);
	PrintInfo(b);
	printf("\n");
	return 0;
}
