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
    mynode temp = head;
    if (head==NULL){
        printf("List tidak memiliki nilai \n");
        return;
    }

    int i = 1;
    while (temp != NULL) {
        printf ("node %d : %d\n", i, temp->data);
        i++;
        temp = temp->next;
    }
}

mynode inputNode(mynode head, int nilai){
    mynode temp = head;

    mynode new_data = createNode(nilai);
    if (head == NULL){
        head = (mynode)malloc(sizeof(struct node));
        head = new_data;
    }

    else {
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_data;
        new_data->prev = temp;
    }
    return head;
}

mynode insert_head(mynode head, int nilai){
    mynode new_data = createNode(nilai);
    new_data->next = head;
    head->prev = new_data;
    head = new_data;

    return (head);
}

int main(){
    int nilai;
    int input;

    mynode head = NULL;
    mynode tail = NULL;
    tail = (mynode)malloc(sizeof(struct node));

    printf("Input the number of nodes: ");
    scanf("%d", &input);

    for (int i=0; i<input; i++) {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", &nilai);

        head = inputNode(head, nilai);
    }

    printf("\nData entered in the list are : \n");
    printNode(head);

    printf("Input data for the first node : ");
    scanf("%d", &nilai);

    head = insert_head(head, nilai);
    printf("\nAfter insertion the new list are : \n");
    printNode(head);

    return 0;
}
