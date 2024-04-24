#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct node
{
    char nama[30];
    struct node *left;
    struct node *right;
};

struct node *newNode(char *nama)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    strcpy(node->nama, nama);
    node->left = NULL;
    node->right = NULL;

    return node;
}

void displayPreorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%s ", node->nama);    // root
    displayPreorder(node->left);  // subtree kiri
    displayPreorder(node->right); // subtree kanan
}
void displayInorder(struct node *node)
{
    if (node == NULL)
        return;
    displayInorder(node->left);  // subtree kiri
    printf("%s ", node->nama);   // root
    displayInorder(node->right); // subtree kanan
}
void displayPostorder(struct node *node)
{
    if (node == NULL)
        return;
    displayPostorder(node->left);  // subtree kiri
    displayPostorder(node->right); // subtree kanan
    printf("%s ", node->nama);     // root
}

struct node *insert(struct node *root, char *newData)
{
    if (root == NULL)
    {
        root = newNode(newData);
    }
    else
    {
        int is_left = 0;
        struct node *cursor = root;
        struct node *prev = NULL;
        while (cursor != NULL)
        {
            prev = cursor;

            int cmp = strcasecmp(cursor->nama, newData); //membandingkan string 1 dengan string 2

            if (cmp == 0) //string 1 ekuivalen dengan string 2
            {
                printf("\nNama sudah ada");
                return root;
            }
            else if (cmp > 0)  //string 1 lebih besar daripada string 2
            {
                is_left = 1;
                cursor = cursor->left;
            }
            else //string 1 lebih kecil daripada string 2
            {
                is_left = 0;
                cursor = cursor->right;
            }
        }
        if (is_left == 1)
            prev->left = newNode(newData);
        else
            prev->right = newNode(newData);
    }
    return root;
}

void search_node(struct node *root, char *nama)
{
    struct node *cursor = root;

    while (cursor != NULL)
    {
        int cmp = strcasecmp(cursor->nama, nama); //membandingkan string 1 dengan string 2

        if (cmp == 0) //string 1 ekuivalen dengan string 2
        {
            printf("\nNode %s ditemukan", nama);
            return;
        }
        else if (cmp > 0)  //string 1 lebih besar daripada string 2
        {
            cursor = cursor->left;
        }
        else //string 1 lebih kecil daripada string 2
        {
            cursor = cursor->right;
        }
    }

    printf("\nNode %s tidak ditemukan", nama);
    return;
}

struct node *delete_node(struct node *root, char *deletedData)
{
    if (root == NULL)
        return root;

    struct node *cursor;

    int cmp = strcasecmp(root->nama, deletedData);  //membandingkan string 1 dengan string 2

    if (cmp > 0) //string 1 lebih besar daripada string 2
    {
        root->left = delete_node(root->left, deletedData);
    }
    else if (cmp < 0) //string 1 lebih kecil daripada string 2
    {
        root->right = delete_node(root->right, deletedData);
    }
    else
    {
        // 1 CHILD
        if (root->left == NULL)
        {
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if (root->right == NULL)
        {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        // 2 CHILDS NODE
        else
        {
            cursor = root->right;
            while (cursor->left != NULL)
            {
                cursor = cursor->left;
            }
            strcpy(root->nama, cursor->nama);
            root->right = delete_node(root->right, cursor->nama);
        }
    }

    return root;
}

int main()
{
    struct node *root = NULL;
    char choice, string[30];

    printf("Insert Data Anda");
    do
    {
        printf("\nMasukkan nama: ");
        scanf("%s", string);
        root = insert(root, string);
        printf("Apakah anda akan memasukkan nama lagi? (y/n): ");
        scanf(" %c", &choice);
    } while (tolower(choice) != 'n');

    //system("@cls||clear");

    printf("\n\nList Daftar Data Anda");
    printf("\nPreorder: ");
    displayPreorder(root);
    printf("\nInorder: ");
    displayInorder(root);
    printf("\nPostorder: ");
    displayPostorder(root);

    printf("\n\nPencarian Data Anda");
    choice = 'y';
    do
    {
        printf("\nMasukkan nama: ");
        scanf("%s", string);
        search_node(root, string);
        printf("\nApakah anda akan mencari nama lagi? (y/n): ");
        scanf(" %c", &choice);
    } while (tolower(choice) != 'n');

    printf("\n\nPenghapusan Data Anda");
    choice = 'y';
    do
    {
        printf("\nMasukkan nama: ");
        scanf("%s", string);
        root = delete_node(root, string);
        printf("\nApakah anda akan menghapus nama lagi? (y/n): ");
        scanf(" %c", &choice);
    } while (tolower(choice) != 'n');

    printf("\n\nList Daftar Anda Setelah Pengeditan");
    printf("\nPreorder: ");
    displayPreorder(root);
    printf("\nInorder: ");
    displayInorder(root);
    printf("\nPostorder: ");
    displayPostorder(root);

    return 0;
}
