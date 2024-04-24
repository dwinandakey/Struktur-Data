#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size) { //mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data:\n");
    for (int i = 0; i < *size; i++) {
        printf("-> ");
        scanf("%d", &data[i]);
    }
}

void tampil_data(int data[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void insertionSortAsc(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDesc(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void main() {
    int data[MAX];
    int size; //ukuran array yang dipakai

    printf("\033[2J");
    fill_data(data, &size);

    insertionSortAsc(data, size);
    printf("Data setelah diurutkan secara menaik:\n");
    tampil_data(data, size);

    insertionSortDesc(data, size);
    printf("Data setelah diurutkan secara menurun:\n");
    tampil_data(data, size);
}