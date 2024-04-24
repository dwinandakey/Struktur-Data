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

void merge(int arr[], int l, int m, int r, int ascending) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if ((ascending && L[i] <= R[j]) || (!ascending && L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortAscending(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortAscending(arr, l, m);
        mergeSortAscending(arr, m + 1, r);
        merge(arr, l, m, r, 1);
    }
}

void mergeSortDescending(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortDescending(arr, l, m);
        mergeSortDescending(arr, m + 1, r);
        merge(arr, l, m, r, 0);
    }
}

void main() {
    int data[MAX];
    int size; //ukuran array yang dipakai
    
    printf("\033[2J");
    fill_data(data, &size);

    printf("Data setelah diurutkan secara menaik:\n");
    mergeSortAscending(data, 0, size - 1);
    tampil_data(data, size);

    printf("Data setelah diurutkan secara menurun:\n");
    mergeSortDescending(data, 0, size - 1);
    tampil_data(data, size);
}
