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

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    // Loop melalui linked list dan menghitung setiap node
    while (current != NULL) {
        printf("%d -> ", current->data);
        count++;
        current = current->next;
    }
    printf("NULL\n");

    return count;
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

    // Mencetak linked list dan menghitung jumlah node
    printf("Linked List: ");
    int count = countNodes(head);
    printf("Jumlah Node dalam Linked List: %d\n", count);

    return 0;
}
