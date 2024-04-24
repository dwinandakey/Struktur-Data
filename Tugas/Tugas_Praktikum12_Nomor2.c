#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define MAX 100 // ukuran maksimum array

void fillData(int data[], int *size) // mengisi data
{
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);

    for (int i = 0; i < *size; i++)
    {
        printf("Input data[%d]: ", i + 1);
        scanf("%d", &data[i]);
    }
}

void displayData(int data[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
}

void swapData(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSortAsc(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDesc(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSortAsc(int data[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int minIdx = step;
        for (int i = step + 1; i < size; i++)
            if (data[i] < data[minIdx])
                minIdx = i;
        swapData(&data[minIdx], &data[step]);
    }
}

void selectionSortDesc(int data[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int minIdx = step;
        for (int i = step + 1; i < size; i++)
            if (data[i] > data[minIdx])
                minIdx = i;
        swapData(&data[minIdx], &data[step]);
    }
}

void mergeDesc(int arr[], int l, int m, int r)
{
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
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeAsc(int arr[], int l, int m, int r)
{
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
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortAsc(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortAsc(arr, l, m);
        mergeSortAsc(arr, m + 1, r);
        mergeAsc(arr, l, m, r);
    }
}

void mergeSortDesc(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortDesc(arr, l, m);
        mergeSortDesc(arr, m + 1, r);
        mergeDesc(arr, l, m, r);
    }
}

void bubbleSortAsc(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapData(&arr[j], &arr[j + 1]);
}

void bubbleSortDesc(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swapData(&arr[j], &arr[j + 1]);
}

int main(void)
{
    int data[MAX] = {0}; // inisiasi elemen array dari 0
    int size, c, choice;
    char type;

    // make a menu
    do
    {
        printf("AVAILABLE SORTING METHODS\n");
        printf("1. Insert data\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Bubble Sort\n");
        printf("ENTER YOUR CHOICE = ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Choose Sort Type Ascending/Descending (A/D) = ");
            scanf(" %s", &type);
            fillData(data, &size);
            break;
        case 2:
                if (data[0] == 0)
                    {
                        printf("Insert data you want to sort first!");
                    }
                else
                {
                    if (type == 1)
                    {
                        printf("Sorted Ascending\n");
                        insertionSortAsc(data, size);
                    }
                    else if (type == 2)
                    {
                        printf("Sorted Descending\n");
                        insertionSortDesc(data, size);
                    }
                    printf("Data after sorted: \n");
                    displayData(data, size);
                }
                break;
            case 3:
                if (type == 1)
                {
                    printf("Sorted Ascending\n");
                    selectionSortAsc(data, size);
                }
                else if (type == 2)
                {
                    printf("Sorted Descending\n");
                    selectionSortDesc(data, size);
                }
                printf("Data after sorted: \n");
                displayData(data, size);
                break;
            case 4 :
                if (type == 'A')
                {
                    printf("Sorted Ascending\n");
                    mergeSortAsc(data, 0, size - 1);
                }
                else
                {
                    printf("Sorted Descending\n");
                    mergeSortDesc(data, 0, size - 1);
                }
                printf ("Data after sorted : \n");
                displayData (data, size);
                break;
            case 5 :
                if (type == 'A')
                {
                    printf("Sorted Ascending\n");
                    bubbleSortAsc(data, size);
                }
                else
                {
                    printf("Sorted Descending\n"); 
                    mergeSortDesc(data, 0, size - 1);
                }
                printf ("Data after sorted : \n");
                displayData (data, size);
                break;
            default :
                printf ("Wrong Input, Try Another\n");
                break;
        }
        printf("\nDo you want to continue? (Press 1 for 'Yes') = ");
        scanf("%d", &c);
    } while (c == 1);
    getchar();
    return 0;
}