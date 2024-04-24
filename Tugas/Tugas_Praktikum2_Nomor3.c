#include <stdio.h>

int matriks [3][4];

void inputmatriks () {
    for(int baris = 1;baris<=3;baris++) {
        for(int kolom = 1;kolom<=4;kolom++) {
            printf("Masukkan matriks ke %d,%d : ", baris, kolom);
            scanf("%d", &matriks [baris][kolom]);
        }
    }
}

void outputmatriks () {
    for(int baris = 1;baris<=3;baris++) {
        for(int kolom = 1;kolom<=4;kolom++) {
            printf("%d ", matriks[baris][kolom]);
        }
        printf ("\n");
    }
}


int main()
{
    inputmatriks();
    printf ("Matriks : \n");
    outputmatriks();
    return 0;
}


