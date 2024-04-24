#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *mynode;

mynode createnode(int nilai){
    mynode temp;
    temp = (mynode)malloc(sizeof(struct node));
    temp->data = nilai;
    temp->prev = NULL;
    temp->next = NULL;

    return(temp);
}

void reversenode(mynode *head){
    mynode temp = NULL;
    mynode current = *head;

    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    //jika list kosong atau hanya 1 node
    if (temp != NULL)
        *head = temp->prev;
}

mynode push(mynode head, int nilai){
    mynode temp = head;

    mynode new_node = createnode(nilai);
    if (temp == NULL)
    {
        head = (mynode)malloc(sizeof(struct node));
        head = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        new_node->prev = temp;
        new_node->next = NULL;

        temp->next = new_node;
    }

    return head;
}

void printnode(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    mynode head = NULL;

    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);

    printf("Double linked list awal: ");
    printnode(head);

    reversenode(&head);

    printf("Double linked list setelah direverse: ");
    printnode(head);

    return 0;
}
