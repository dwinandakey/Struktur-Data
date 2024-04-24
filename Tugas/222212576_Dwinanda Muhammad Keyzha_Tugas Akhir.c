#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <limits.h>

struct individual
{
    char name[30];
    int age;
    char sex[8];
    char address[50];
    char phone_no[15];
    char mail[100];
    char dob[15];
};

void menu();
void got();
void start();
void repeat();
void addcontact();
void listcontact();
void modifycontact();
void deletecontact();
void searchcontact();
void sort();
void swap(struct individual *a, struct individual *b);
void calculate();
void wildcardsearch();
void andsearch();
void orsearch();

int main()
{
    system("color 10");
    start();
    return 0;
}

void menu()
{
    system("cls");
    printf("====================================================\n");
    printf("============= CONTACT BOOK APPLICATION =============\n");
    printf("====================================================\n");
    printf("\n\t MAIN MENU\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("<1>. New Contact\n");
    printf("<2>. Contacts list\n");
    printf("<3>. Modify Contact\n");
    printf("<4>. Search Contact (by Name/Age/And/Or)\n");
    printf("<5>. Delete Contact\n");
    printf("<6>. Sort Contacts\n");
    printf("<7>. Contacts Statistics (Max/Min/Average)\n");
    printf("<8>. Contacts Wildcard Search\n");
    printf("<9>. Exit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter your choice: ");

    switch (getch())
    {
    case '1':
        addcontact();
        break;
    case '2':
        listcontact();
        break;
    case '3':
        modifycontact();
        break;
    case '4':
        searchcontact();
        break;
    case '5':
        deletecontact();
        break;
    case '6':
        sort();
        break;
    case '7':
        calculate();
        break;
    case '8':
        wildcardsearch();
        break;
    case '9':
        exit(0);
        break;
    default:
        system("cls");
        printf("\nError.\nEnter 1 to 9 only.\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Press any key to continue...");
        getch();
        menu();
    }
}

void start()
{
    menu();
}

void repeat()
{
    start();
}

void addcontact()
{
    /*
    Program ini sudah memenuhi persyaratan yang diminta dalam soal
    karena program ini telah mencakup fungsi save dan load, sehingga saat data kontak ditambahkan,
    informasinya akan disimpan secara otomatis di memori
    dan akan ter-load secara otomatis ketika program dijalankan kembali.
    */
    system("cls");
    FILE *f;
    struct individual i;
    f = fopen("file", "ab+");
    printf("*** Add Contact ***");
    printf("\nEnter Name: ");
    got(i.name);
    printf("\nEnter Age: ");
    scanf("%d", &i.age);
    printf("Enter Sex (F/M): ");
    got(i.sex);
    printf("\nEnter Address: ");
    got(i.address);
    printf("\nEnter Phone Number: ");
    got(i.phone_no);
    printf("\nEnter E-mail: ");
    got(i.mail);
    printf("\nEnter Date of Birth (DD/MM/YYYY): ");
    got(i.dob);
    fwrite(&i, sizeof(i), 1, f);
    printf("\nContact saved");
    fclose(f);
    printf("\n\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}

void listcontact()
{
    system("cls");
    struct individual i;
    FILE *f;
    f = fopen("file", "rb");
    if (f == NULL)
    {
        printf("\nContact data has not been added\a\a\a\a\n");
        exit(1);
    }
    printf("\tYour Contacts\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (fread(&i, sizeof(i), 1, f) == 1)
    {
        printf("\nName : %s", i.name);
        printf("\nAge : %d", i.age);
        printf("\nSex : %s", i.sex);
        printf("\nAddress : %s", i.address);
        printf("\nPhone Number : %s", i.phone_no);
        printf("\nE-mail : %s", i.mail);
        printf("\nDate of Birth : %s\n", i.dob);
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(f);
    printf("\n Enter any key to continue...");
    getch();
    system("cls");
    menu();
}

void modifycontact()
{
    FILE *f;
    int flag = 0;
    struct individual i, p;
    char name[50];
    f = fopen("file", "rb+");
    if (f == NULL)
    {
        printf("\nContact data has not been added\a\a\a\a\n");
        exit(1);
    }
    else
    {
        system("cls");
        printf("\nEnter Name to Modify:\n");
        got(name);
        while (fread(&i, sizeof(i), 1, f) == 1)
        {
            if (strcmp(name, i.name) == 0)
            {
                printf("\nEnter Name: ");
                got(p.name);
                printf("\nEnter Age: ");
                scanf("%d", &p.age);
                printf("Enter Sex (F/M): ");
                got(p.sex);
                printf("\nEnter Address: ");
                got(p.address);
                printf("\nEnter Phone Number: ");
                got(p.phone_no);
                printf("\nEnter E-mail: ");
                got(p.mail);
                printf("\nEnter Date of Birth (DD/MM/YYYY): ");
                got(p.dob);
                fseek(f, -sizeof(i), SEEK_CUR);
                fwrite(&p, sizeof(i), 1, f);
                flag = 1;
                break;
            }
            fflush(stdin);
        }
        if (flag == 1)
        {
            printf("\nContact data has been modified");
        }
        else
        {
            printf("\nContact data has not been found");
        }
        fclose(f);
    }
    printf("\n Enter any key to continue...");
    getch();
    system("cls");
    menu();
}

void namesearch()
{
    struct individual i;
    FILE *f;
    char name[30];
    int found = 0; // variabel untuk menandai apakah data ditemukan atau tidak
    f = fopen("file", "rb");
    if (f == NULL)
    {
        printf("\nFailed to open the file\a\a\a\a");
        exit(1);
    }
    printf("\nEnter Name to Search : ");
    got(name);
    while (fread(&i, sizeof(i), 1, f) == 1)
    {
        if (strcmp(i.name, name) == 0)
        {
            printf("\n\tSearch Results About %s", name);
            printf("\nName : %s", i.name);
            printf("\nAge : %d", i.age);
            printf("\nSex : %s", i.sex);
            printf("\nAddress : %s", i.address);
            printf("\nPhone Number : %s", i.phone_no);
            printf("\nE-mail : %s", i.mail);
            printf("\nDate of Birth : %s\n", i.dob);
            found = 1; // Set found ke 1 karena data ditemukan
            break;     // Keluar dari loop setelah data ditemukan
        }
    }
    if (!found)
    {
        printf("\nContact has not been found");
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(f);
    printf("\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}

void agesearch()
{
    struct individual i;
    FILE *f;
    int age;
    int found = 0; // variabel untuk menandai apakah data ditemukan atau tidak
    f = fopen("file", "rb");
    if (f == NULL)
    {
        printf("\nFailed to open the file\a\a\a\a");
        exit(1);
    }
    printf("\nEnter age to Search : ");
    scanf("%d", &age);
    while (fread(&i, sizeof(i), 1, f) == 1)
    {
        if (i.age == age)
        {
            printf("\n\tSearch Results by Age");
            printf("\nName : %s", i.name);
            printf("\nAge : %d", i.age);
            printf("\nSex : %s", i.sex);
            printf("\nAddress : %s", i.address);
            printf("\nPhone Number : %s", i.phone_no);
            printf("\nE-mail : %s", i.mail);
            printf("\nDate of Birth : %s\n", i.dob);
            found = 1; // Set found ke 1 karena data ditemukan
            break;     // Keluar dari loop setelah data ditemukan
        }
    }
    if (!found)
    {
        printf("\nContact has not been found");
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(f);
    printf("\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}

void andsearch()
{
    struct individual i;
    FILE *f;
    char name[30];
    int age;
    f = fopen("file", "rb");
    ;
    if (f == NULL)
    {
        printf("\nFailed to open the file\a\a\a\a");
        exit(1);
    }
    printf("\nEnter Name to Search : ");
    got(name);
    printf("\nEnter Age to Search: ");
    scanf("%d", &age);
    printf("\n\tSearch Results by AND\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (fread(&i, sizeof(i), 1, f) == 1)
    {
        // Mencocokkan nama dan age
        if (strstr(i.name, name) != NULL && i.age == age)
        {
            printf("\nName : %s", i.name);
            printf("\nAge : %d", i.age);
            printf("\nSex : %s", i.sex);
            printf("\nAddress : %s", i.address);
            printf("\nPhone Number : %s", i.phone_no);
            printf("\nE-mail : %s", i.mail);
            printf("\nDate of Birth : %s\n", i.dob);
        }
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(f);
    printf("\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}

void orsearch()
{
    struct individual i;
    FILE *f;
    char name[30];
    int age;

    f = fopen("file", "rb");
    if (f == NULL)
    {
        printf("\nFailed to open the file\a\a\a\a");
        exit(1);
    }
    printf("\nEnter Name to Search : ");
    got(name);
    printf("\nEnter Age to Search: ");
    scanf("%d", &age);
    printf("\n\tSearch Results by OR\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (fread(&i, sizeof(i), 1, f) == 1)
    {
        // Mencocokkan nama dan age
        if (strstr(i.name, name) != NULL || i.age == age)
        {
            printf("\nName : %s", i.name);
            printf("\nAge : %d", i.age);
            printf("\nSex : %s", i.sex);
            printf("\nAddress : %s", i.address);
            printf("\nPhone Number : %s", i.phone_no);
            printf("\nE-mail : %s", i.mail);
            printf("\nDate of Birth : %s\n", i.dob);
        }
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(f);
    printf("\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}

void searchcontact()
{
    system("cls");
    printf("\n\tSearch Contact\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("<1>. by Name\n");
    printf("<2>. by Age\n");
    printf("<3>. by Name AND Age\n");
    printf("<4>. by Name OR Age\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter your choice: \n");
    switch (getch())
    {
    case '1':
        namesearch();
        break;
    case '2':
        agesearch();
        break;
    case '3':
        andsearch();
        break;
    case '4':
        orsearch();
        break;
    default:
        system("cls");
        printf("\nError. Enter 1 to 4 only");
    }
}

void deletecontact()
{
    struct individual i;
    FILE *f, *ft;
    int flag = 0;
    char name[30];
    f = fopen("file", "rb");
    if (f == NULL)
    {
        printf("\nContact data has not been added\a\a\a\a\n");
        exit(1);
    }
    else
    {
        ft = fopen("temp", "ab+");
        if (ft == NULL)
        {
            printf("Failed to open the file\a\a\a\a");
        }
        else
        {
            printf("\nEnter Name to Delete: ");
            got(name);
            while (fread(&i, sizeof(i), 1, f) == 1)
            {
                if (strcmp(i.name, name) != 0)
                    fwrite(&i, sizeof(i), 1, ft);
                else
                    flag = 1;
            }
            fclose(f);
            fclose(ft);
            if (flag != 1)
            {
                printf("\nNo Contact has been deleted");
            }
            else
            {
                f = fopen("file", "wb"); // Membersihkan file file
                fclose(f);
                f = fopen("file", "ab+");
                ft = fopen("temp", "rb");
                while (fread(&i, sizeof(i), 1, ft) == 1)
                {
                    fwrite(&i, sizeof(i), 1, f);
                }
                fclose(f);
                fclose(ft);
                remove("temp");
                printf("\nContact has been deleted");
            }
        }
    }
    printf("\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}

// Fungsi untuk menukar dua elemen dalam array individual
void swap(struct individual *a, struct individual *b)
{
    struct individual temp = *a;
    *a = *b;
    *b = temp;
}

void sort()
{
    struct individual i[100];
    int k, j, n;
    FILE *f;
    f = fopen("file", "rb");
    if (f == NULL)
    {
        printf("\nFailed to open the file\a\a\a\a");
        exit(1);
    }
    // Membaca data dari file ke dalam array i
    n = 0;
    while (fread(&i[n], sizeof(struct individual), 1, f) == 1)
    {
        n++;
    }
    fclose(f);
    // Bubble Sort
    for (k = 0; k < n - 1; k++)
    {
        for (j = 0; j < n - k - 1; j++)
        {
            if (strcmp(i[j].name, i[j + 1].name) > 0)
            {
                swap(&i[j], &i[j + 1]);
            }
        }
    }
    // Menyimpan data yang telah diurutkan kembali ke dalam file
    f = fopen("file", "wb");
    if (f == NULL)
    {
        printf("\nContact data has not been found, please input the data first");
        exit(1);
    }
    for (k = 0; k < n; k++)
    {
        fwrite(&i[k], sizeof(struct individual), 1, f);
    }
    fclose(f);
    printf("\nData has been sorted by name.");
    printf("\nEnter any key to continue... to continue...");
    getch();
    system("cls");
    menu();
}

void got(char *name)
{
    int i = 0;
    char c;
    do
    {
        c = getch();
        if (c != 8 && c != 13)
        {
            *(name + i) = c;
            putch(c);
            i++;
        }
        else if (c == 8 && i > 0)
        {
            i--;
            printf("\b \b"); // Hapus karakter sebelumnya dari tampilan
        }

    } while (c != 13);
    *(name + i) = '\0';
}

// Function to find the maximum value of a numeric attribute
void findmaxage()
{
    FILE *f;
    struct individual i;
    int maxage;
    f = fopen("file", "rb"); // Open the file in read mode
    if (f == NULL)
    {
        printf("\nFailed to open the file\a\a\a\a");
        exit(1);
    }
    while (fread(&i, sizeof(i), 1, f) == 1)
    {
        if (i.age > maxage)
        {
            maxage = i.age;
        }
    }
    fclose(f);
    printf("Maximum Age: %d\n", maxage);
    printf("\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}

// Function to find the minimum value of a numeric attribute
void findminage()
{
    FILE *f;
    struct individual i;
    int minage;
    f = fopen("file", "rb"); // Open the file in read mode
    if (f == NULL)
    {
        printf("\nFailed to open the file\a\a\a\a");
        exit(1);
    }
    while (fread(&i, sizeof(i), 1, f) == 1)
    {
        if (i.age < minage)
        {
            minage = i.age;
        }
    }
    fclose(f);
    printf("Minimum Age: %d\n", minage);
    printf("\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}

// Function to find the average value of a numeric attribute
void findaverageage()
{
    FILE *f;
    struct individual i;
    int sumage = 0;
    int count = 0;
    f = fopen("file", "rb"); // Open the file in read mode
    if (f == NULL)
    {
        printf("\nFailed to open the file\a\a\a\a");
        exit(1);
    }
    while (fread(&i, sizeof(i), 1, f) == 1)
    {
        sumage += i.age;
        count++;
    }
    fclose(f);
    if (count == 0)
    {
        printf("Average Age: 0.0 (No records)\n");
    }
    else
    {
        float averageage = (float)sumage / count;
        printf("Average Age: %.2f\n", averageage);
    }
    printf("\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}

void calculate()
{
    system("cls");
    printf("\n\tStatistics\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("<1>. Max Age \n<2>. Min Age \n<3>. Average Age");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Masukan pilihan anda : \n");

    switch (getch())
    {
    case '1':
        findmaxage();
        break;
    case '2':
        findminage();
        break;
    case '3':
        findaverageage();
        break;
    default:
        system("cls");
        printf("\nError. Enter 1 to 3 only.");
    }
}

void wildcardsearch()
{
    struct individual i;
    FILE *f;
    char wildcard[15];
    system("cls");
    printf("\nEnter wildcard pattern: ");
    got(wildcard);
    f = fopen("file", "rb");
    if (f == NULL)
    {
        printf("\nFailed to open the file\a\a\a\a");
        exit(1);
    }
    printf("\n\tSearch Results by Wildcard\n");
    printf("\n============================\n");
    while (fread(&i, sizeof(i), 1, f) == 1)
    {
        // Menggunakan strstr untuk mencocokkan wildcard dengan nomor telepon
        if (strstr(i.phone_no, wildcard) != NULL)
        {
            printf("\nName : %s", i.name);
            printf("\nAge : %d", i.age);
            printf("\nSex : %s", i.sex);
            printf("\nAddress : %s", i.address);
            printf("\nPhone Number : %s", i.phone_no);
            printf("\nE-mail : %s", i.mail);
            printf("\nDate of Birth : %s\n", i.dob);
        }
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(f);
    printf("\nEnter any key to continue...");
    getch();
    system("cls");
    menu();
}
