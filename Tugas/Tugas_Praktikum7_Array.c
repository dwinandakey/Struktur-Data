#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pendeklarasian node
typedef struct
{
    char nama[20];
    int alpro;
    int kalkulus;
} mahasiswa;

int count = 0;

//Fungsi untuk melakukan push menurut prioritas
void enqueue(mahasiswa arr[], char nama[], int alp, int kal)
{
    if (count < 5)
    {
        strcpy(arr[count].nama, nama);
        arr[count].alpro = alp;
        arr[count].kalkulus = kal;
        (count)++;
    }
    else
    {
        int minIndex = 0;
        for (int i = 1; i < 5; i++)
        {
            if (arr[i].alpro < arr[minIndex].alpro ||
                (arr[i].alpro == arr[minIndex].alpro && arr[i].kalkulus < arr[minIndex].kalkulus))
            {
                minIndex = i;
            }
        }

        if (alp > arr[minIndex].alpro || (alp == arr[minIndex].alpro && kal > arr[minIndex].kalkulus))
        {
            strcpy(arr[minIndex].nama, nama);
            arr[minIndex].alpro = alp;
            arr[minIndex].kalkulus = kal;
        }
    }
}

//Fungsi untuk menampilkan data
void tampilkanmahasiswa(mahasiswa arr[], int count)
{
    if (count == 0)
    {
        printf("Belum ada yang daftar\n");
    }
    else
    {
        printf("Daftar 5 mahasiswa Terbaik (urutan dari nilai terbaik):\n");
        for (int i = 0; i < count; i++)
        {
            printf("Nama: %s | Alpro: %d | Kalkulus: %d\n", arr[i].nama, arr[i].alpro, arr[i].kalkulus);
        }
    }
}

int main()
{
    mahasiswa mahasiswa[5];

    enqueue(mahasiswa, "Budi", 50, 20);
    enqueue(mahasiswa, "Eko", 50, 20);
    enqueue(mahasiswa, "bambang", 60, 20);
    enqueue(mahasiswa, "Eka", 60, 20);
    enqueue(mahasiswa, "wawo", 60, 20);
    enqueue(mahasiswa, "Ame", 60, 30);

    tampilkanmahasiswa(mahasiswa, count);

    return 0;
}

