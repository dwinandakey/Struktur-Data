#include <stdio.h>

struct number {
    int *nomor1,nomor2; // sebuah structure dengan elemen pointer di dalamnya
} angka;

int main() {
    angka.nomor2 = 2;
    angka.nomor1 = &angka.nomor2;
    printf("\nNilai yang disimpan dalam struktur : %d \n", *angka.nomor1);
    printf("\nAlamat yang disimpan dalam struktur : %d \n", angka.nomor1);
    *angka.nomor1 = 1;
    printf("\nNilai setelah diubah melalui struktur : %d \n", *angka.nomor1);
    printf("\nAlamat setelah diubah melalui struktur : %d \n", angka.nomor1);

    return 0;
}
