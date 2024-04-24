#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pendeklarasian node
typedef struct node
{
    char nama[30];
    int alpro;
    int kalkulus;
    struct node *next;
} mahasiswa;

int count = 0;

//Fungsi untuk membuat node baru
mahasiswa *newmahasiswa(char a[], int alp, int kal)
{
    mahasiswa *temp = (mahasiswa *)malloc(sizeof(mahasiswa));
    strcpy(temp->nama, a);
    temp->alpro = alp;
    temp->kalkulus = kal;
    temp->next = NULL;

    return temp;
}

//Fungsi untuk menghapus pendaftar
void dequeue(mahasiswa **head)
{
    if ((*head) != NULL)
    {

        mahasiswa *temp = *head;
        (*head) = (*head)->next;

        free(temp);
    }
}

//Fungsi untuk melakukan push menurut prioritas
void enqueue(mahasiswa **head, char n[], int alp, int kal)
{
    mahasiswa *temp = newmahasiswa(n, alp, kal);
    if ((*head) == NULL)
    {
        (*head) = temp;
    }
    else if (((*head)->alpro < alp) || (alp == (*head)->alpro && kal > (*head)->kalkulus))
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        mahasiswa *start = (*head);
        while (start->next != NULL && start->next->alpro > alp)
        {
            start = start->next;
        }

        if (start->next != NULL)
        {
            while (start->next != NULL && start->next->alpro == alp && start->next->kalkulus > kal)
            {
                start = start->next;
            }
        }

        temp->next = start->next;
        start->next = temp;
    }

    if (count >= 5)
    {
        mahasiswa *current = *head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        dequeue(&(current->next));
    }
    else
    {
        count++;
    }
}

//Fungsi untuk menampilkan data
void display(mahasiswa *head)
{
    if (count == 0)
    {
        printf("Belum ada yang daftar\n");
    }
    else
    {
        printf("Daftar 5 Mahasiswa Terbaik (urutan dari nilai terbaik):\n");
        for (int i = count; i > 0; i--)
        {
            printf("Nama: %s | Alpro: %d | Kalkulus: %d\n", head->nama, head->alpro, head->kalkulus);

            head = head->next;
        }
    }
}

int main()
{
    mahasiswa *wakil = NULL;
    enqueue(&wakil, "Eko", 50, 20);
    enqueue(&wakil, "Budi", 50, 20);

    enqueue(&wakil, "bambang", 60, 20);
    enqueue(&wakil, "Eka", 60, 20);
    enqueue(&wakil, "wawo", 60, 20);

    enqueue(&wakil, "Ame", 60, 30);
    display(wakil);

    return 0;
}


