#include <stdio.h>
#include <stdlib.h>

// Struktur untuk node dalam linked list
struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    // Membuat node baru
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Jika linked list kosong, node baru menjadi head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Jika tidak, tambahkan node baru di awal
        newNode->next = *head;
        *head = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}


void reverseValues(struct Node* head) {
    struct Node* current = head;
    int values[100];

    int count = 0;
    while (current != NULL) {
        values[count] = current->data;
        current = current->next;
        count++;
    }

    current = head;
    count--;

    while (current != NULL) {
        current->data = values[count];
        current = current->next;
        count--;
    }
}

int main() {
    struct Node* head = NULL; // Inisialisasi linked list kosong
    int n; // Jumlah node yang akan dimasukkan

    printf("Masukkan jumlah node yang akan dimasukkan: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Masukkan nilai untuk node %d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }

    // Mencetak linked list sebelum membalik nilai
    printf("Linked List Sebelum Membalik Nilai: ");
    printList(head);

    // Memanggil fungsi untuk membalik nilai dalam linked list
    reverseValues(head);

    // Mencetak linked list setelah membalik nilai
    printf("Linked List Setelah Membalik Nilai: ");
    printList(head);

    return 0;
}
