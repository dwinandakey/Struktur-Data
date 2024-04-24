#include <stdio.h>

int luasPP(int panjang, int lebar) {
    int luas = panjang*lebar;
    return luas;
}

int kelilingPP(int panjang, int lebar) {
    int keliling = 2*(panjang+lebar);
    return keliling;
}

int main() {
int panjang, lebar;

    printf("Perhitungan Luas dan Keliling Persegi Panjang \n");
    printf ("================================================= \n");
    printf("Panjang : "); scanf ("%d", &panjang);
    printf("Lebar : "); scanf ("%d", &lebar);
    printf("\n");
    printf("Hasil \n");
    printf("Luas : %d \n", luasPP(panjang, lebar));
    printf("Keliling : %d \n", kelilingPP(panjang,lebar));

 return(0);
}



