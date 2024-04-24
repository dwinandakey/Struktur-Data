#include <stdio.h>
#include <stdlib.h>

struct Student {
    int nim;
    char nama[50];
};

int main() {
    int n;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    // Mengalokasikan memori untuk array dinamis dari struktur Student
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    // Memasukkan data mahasiswa ke dalam array dinamis
    for (int i = 0; i < n; i++) {
        printf("Masukkan NIM mahasiswa %d: ", i + 1);
        scanf("%d", &students[i].nim);
        printf("Masukkan nama mahasiswa %d: ", i + 1);
        getchar();
        scanf("%[^\n]s", students[i].nama);
    }

    // Menampilkan data mahasiswa yang telah disimpan
    printf("\nData Mahasiswa:\n");
    for (int i = 0; i < n; i++) {
        printf("Mahasiswa %d\n", i + 1);
        printf("NIM: %d\n", students[i].nim);
        printf("Nama: %s\n", students[i].nama);
    }

    // Membebaskan memori yang dialokasikan untuk array dinamis
    free(students);

    return 0;
}

