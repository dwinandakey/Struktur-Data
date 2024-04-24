#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct item
{
    int key;
    int value;
};

struct hashtable_item
{
    int flag;
    /* flag = 0 : Tidak ada data
    * flag = 1 : Ada data
    * flag = 2 : Sebelumnya ada datanya */
    struct item data;
};

struct hashtable_item *array;
int max;

//Deklarasi fungsi untuk mengambil input dari pengguna
int getInputMax() {
    printf("Masukkan size dari hastable yang diinginkan:  ");
    scanf("%d", &max); // Mengambil input dari pengguna dan menyimpannya dalam variabel max
    return max; // Mengembalikan nilai yang dimasukkan oleh pengguna
}
/* initializing hash table array */

void init_array()
{
    int i;
    for (i = 0; i < max; i++)
    {
    array[i].flag = 0;
    }
}

/* to every key, it will generate a corresponding
index */
int hashcode(int key, int attempt)
{
    return ((key + attempt*attempt) % max);
}


int size_of_hashtable()
{
    int size = 0; // size dari hashtable
    for (int i = 0; i < max; i++)
    {
        if (array[i].flag == 1)
        {
            size++;
        }
    }
    return size;
}

void insert(int key, int value)
{
    int attempt = 0;
    int index;

    do
    {
        index = hashcode(key, attempt);

        if (array[index].flag == 0)
        {
            //Jika slot kosong, sisipkan elemen baru
            array[index].flag = 1;
            array[index].data.key = key;
            array[index].data.value = value;
            printf("\n Key (%d) telah diinsert \n", key);
            return;
        }
        else if (array[index].flag == 1 && array[index].data.key == key)
        {
            //Jika key sudah ada, update value
            printf("\n Key sudah ada, maka dipudate nilainya \n");
            array[index].data.value = value;
            return;
        }
        else if (array[index].flag == 2)
        {
            printf("\n Cannot insert into a previously deleted position \n");
            return;
        }

        attempt++;
    } while (attempt < max);

    //Jika array penuh, tingkatkan ukurannya
    printf("\n Hash table penuh, tidak dapat menginsert nilai baru \n");
    max *= 2;
    array = realloc(array, max * sizeof(struct hashtable_item));
    init_array();
    printf("\n Ukuran hash table telah dipudet, insertkan nilai terbaru: ");
    insert(key, value);
}

void remove_element(int key)
{
    int attempt = 0;
    int index;

    do
    {
        index = hashcode(key, attempt);

        if (array[index].flag == 1 && array[index].data.key == key)
        {
            key;
            // Jika key ditemukan, hapus elemen
            array[index].flag = 2;
            printf("\n Key (%d) has been removed \n", key);
            return;
        }

        attempt++;
    } while (array[index].flag != 0 && attempt < max);

    // Jika key tidak ditemukan
    printf("\n This key does not exist \n");
}

/* to display all the elements of hash table */
void display()
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (array[i].flag == 1)
        {
            printf("\n Array[%d] has elements -: \n %d(key) and %d(value) ", i, array[i].data.key, array[i].data.value);
        }
        else
        {
            printf("\n Array[%d] has no elements \n", i);
        }
    }
}

int main()
{
    int choice, key, value, n, c;
    int max = getInputMax();
    array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));
    init_array();
    do {
        printf("Implementation of Hash Table in C with Linear Probing \n\n");
        printf("MENU-: \n1.Inserting item in the Hashtable" "\n2.Removing item from the Hashtable" "\n3.Check the size of Hashtable" "\n4.Display Hashtable" "\n\n Please enter your choice-:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Inserting element in Hashtable\n");
                printf("Enter key-:\t");
                scanf("%d", &key);
                printf("Enter value-:\t");
                scanf("%d", &value);
                insert(key, value);
                break;
            case 2:
                printf("Deleting in Hashtable \n Enter the key to delete-:");
                scanf("%d", &key);
                remove_element(key);
                break;
            case 3:
                n = size_of_hashtable();
                printf("Size of Hashtable is-:%d\n",
                n);
                break;
            case 4:
                display();
                break;
            default:
                printf("Wrong Input\n");
        }
        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    } while(c == 1);

    // Free the allocated memory for the hashtable array
    free(array);

    getchar();
    return 0;
}