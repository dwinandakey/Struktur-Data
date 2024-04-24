/* Aturan Scope pada Bahasa C */
#include<stdio.h>
int main()
{
    {
        int x = 10, y = 20; //variabel global
            {
                printf("x = %d, y = %d\n", x, y);
                    {
                        int y = 40; //variabel y dideklarasi disini sebagai variabel lokal
                        x++; //x=x+1 sehingga x=11
                        y++; //y=y+1 sehingga y=41
                        printf("x = %d, y = %d\n", x, y); //menampilkan hasil dari assignment x=11 dan y=41
                    }
                printf("x = %d, y = %d\n", x, y);
                // menampilkan variabel global x yang sudah bertambah 1 menjadi x=11, dan variabel global y yang masih tetap bernilai menjadi y=20
            }
    }
    return 0;
}
