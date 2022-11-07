// NIM		: 18221171
// Nama		: Hans Stephano E
// Tanggal	: 06 November 2022
// Topik	: Praktikum 9 - #2
// Deskripsi: Program listfibbonaci yang menerima masukan banyak elemen
//			: dan elemen pertama dan kedua, kemudian menghasilkan list
//			: berisikan deret fibonacci

#include <stdio.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    scanf("%d", &el);

    if (el == 0) {
		
        PrintInfo(fibonacci);
        return 0;
        
    } else if (el == 1) {
        infotype first;
        scanf("%d", &first);
        InsVFirst(&fibonacci, first);

        PrintInfo(fibonacci);
        return 0;
    } else {
        infotype first, second, nth;
        scanf("%d", &first);
        scanf("%d", &second);
        InsVFirst(&fibonacci, second);
        InsVFirst(&fibonacci, first);
        
        int i = NbElmt(fibonacci);
        while (i != el)
        {
			nth = first + second;
			InsVLast(&fibonacci, nth);
			first = second;
			second = nth;
			i++;
		}
        
        PrintInfo(fibonacci);
    }

    return 0;
}
