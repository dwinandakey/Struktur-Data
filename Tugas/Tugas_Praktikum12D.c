#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size) { //mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data:\n");
    for (int i = 0; i <* size; i++){
        printf("-> ");
        scanf("%d", &data[i]);
    }
}

void tampil_data(int data[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ",data[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortAsc(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void bubbleSortDesc(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] < arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void main() {
    int data[MAX];
    int size; //ukuran array yang dipakai

    printf("\033[2J");
    fill_data(data,&size);

    bubbleSortAsc(data,size);
    printf("Data setelah diurutkan secara menaik:\n");
    tampil_data(data,size);

    bubbleSortDesc(data,size);
    printf("Data setelah diurutkan secara menurun:\n");
    tampil_data(data,size);
}