#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *mynode;

mynode createNode(int nilai){
    mynode temp;
    temp = (mynode)malloc(sizeof(struct node));
    temp->data = nilai;
    temp->prev = NULL;
    temp->next = NULL;

    return(temp);
}

void printNode(mynode head){
    mynode tmp = head;
    if (head==NULL){
        printf("List tidak memiliki nilai \n");
        return;
    }
    while (tmp != NULL) {
        printf ("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

mynode insert_tail(mynode head, int new_data, mynode *tail){
    mynode new_node = createNode(new_data);
    new_node->next = NULL;

    if (head == NULL){
        new_node->prev=NULL;
        head=new_node;
        return head;
    }

    mynode cursor = head;
    while (cursor->next != NULL){
        cursor= cursor->next;
    }

    cursor->next = new_node;
    new_node->prev = cursor;

    *tail = new_node;
    return head;
}

mynode remove_end(mynode head, mynode *tail){
    if (head == NULL)
        return head;

    mynode cursor = head;
    while (cursor->next != NULL){
        cursor = cursor -> next;
    }

    *tail =  cursor->prev;
    cursor->prev->next=NULL;
    cursor->prev = NULL;
    free(cursor);

    return(head);
}

int main(){
    mynode head = NULL;
    mynode tail = NULL;
    head = (mynode)malloc(sizeof(struct node));
    tail = (mynode)malloc(sizeof(struct node));

    head = createNode(1);
    tail = head;
    printf("Linked list setelah pembuatan simpul awal \n");
    printf("Head : "); printNode(head);
    printf("Tail : "); printNode(tail);

    head = insert_tail(head, 2, &tail);
    printf("Linked list setelah insert kanan \n");
    printf("Head : "); printNode(head);
    printf("Tail : "); printNode(tail);

    head = remove_end(head, &tail);
    printf("Linked list setelah delete kanan \n");
    printf("Head : "); printNode(head);
    printf("Tail : "); printNode(tail);

    return 0;
}


