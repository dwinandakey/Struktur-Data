#include <stdio.h>

struct Mahasiswa {
    char nama[30],nim[9];
}mhs;

int main()
{
    struct Mahasiswa *pointermahasiswa; //pointer yang menunjuk sebuah struktur

    printf("\nInputkan Data Mahasiswa\n");
    printf("Nama : "); gets(mhs.nama);
    printf("NIM : "); gets(mhs.nim);

    pointermahasiswa = &mhs; //nilainya diatur dan disimpan dalam pointer yang menunjuk sebuah struktur

    printf("\nData Mahasiswa \n");
    printf("Nama : %s \n", (*pointermahasiswa). nama);
    printf("NIM : %s \n", (*pointermahasiswa). nim);

    return 0;
}
