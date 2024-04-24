#include <stdio.h>
#include <stdlib.h>

//struktur untuk node dalam linked list
struct node
{
    int data;
    struct node *next;
};
typedef struct node *mynode;

//pembuatan node baru ke dalam linked list
mynode createNode(int nilai)
{
    mynode p;
    p = (mynode)malloc(sizeof(struct node));
    p -> data = nilai;
    p -> next = NULL;
    return (p);
}

//menambahkan node baru ke dalam linked list sebagai head
mynode push(int new_value, mynode head)
{
    mynode new_node = createNode(new_value);
    new_node->next = head;
    new_node = head;
    return (head);
}

//menghapuskan head di dalam linked list yang telah dibuat
mynode pop(mynode head)
{
    //jika linked list kosong maka akan memberikan pesan
    if (head == NULL)
        printf("Node masih kosong. \n");
        return NULL;
    mynode temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    return (head);
}

//menampilkan nilai dari linked list yang berisikan binary
void printNode(mynode head)
{
    mynode temp;

    if (head == NULL)
    {
        printf("Node masih kosong. \n");
        return;
    }

    temp = head;
    printf("List dari node:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//menambahkan node baru ke dalam linked list
mynode addNode(int nilai_baru, mynode *node)
{
    mynode temp;
    temp = (mynode)malloc(sizeof(struct node));
    temp->data = nilai_baru;
    temp->next = *node;

    return temp;
}

//mengubah nilai desimal ke binary
void DesimalBinary(int value, mynode *head)
{
    int sisa_bagi;
    for (int i = value; i > 0; i = i / 2)
    {
        sisa_bagi = i % 2; //% : operator modulus karena binary maka 2
        *head = addNode(sisa_bagi, head);
    }
    printf("Hasil konversi desimal ke biner = ");
    mynode temp = *head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

//mengubah nilai desimal ke oktal
void DesimalOktal(int value, mynode *head)
{
    int sisa_bagi;
    for (int i = value; i > 0; i = i / 8)
    {
        sisa_bagi = i % 8; //% : operator modulus karena oktal maka 8
        *head = addNode(sisa_bagi, head);
    }
    printf("Hasil konversi desimal ke oktal = ");
    mynode temp = *head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    mynode head = NULL;
    int bil_desimal;
    int choice;

    printf("Program konversi Desimal\n\n");
    //mengintputkan nilai bilangan desimal yang ingin dikonversikan
    printf("Masukkan bilangan desimal = ");
    scanf("%d", &bil_desimal);
    do
    {
        printf("\n\nMasukkan pilihan\n1: Biner\n2: Octal\n3: Exit\n=> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (bil_desimal == 0) //jika nilai bilangan desimal 0 maka akan keluar output 0 juga
                printf("Hasil konversi ke biner = 0");
            else if (bil_desimal < 0) // mengkonversi bilangan desimal negatif ke biner
            {
                int bil_sama = 1;
                while (bil_sama < (bil_desimal * -1))
                {
                    bil_sama *= 2;
                }
                printf("%d", bil_sama);

                DesimalBinary(bil_sama - (bil_desimal * -1), &head);
            }
            else
            {
                DesimalBinary(bil_desimal, &head); //mengkonversi bilangan desimal positif ke biner
                // DesimalBinary(bil_desimal, &stack);
            }
            break;


        case 2:
            DesimalOktal(bil_desimal, &head); //mengkonversi bilangan desimal positf ke oktal
            break;

        case 3:
            printf("Keluar \n");
            break;

        default:
            printf("Pilihan salah\n");
            break;
        }
    }
    while (choice !=3); //looping akan keluar jika user memilih opsi nomor 3
    return 0;
}
