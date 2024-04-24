#include <stdio.h>
int main()
{
int tugas, uts, uas;
char nama [30], nim [9];
float akhir;
    printf("Nama : "); scanf (" %[^\n]s", &nama);
    printf("NIM : "); scanf ("%s", &nim);
    printf("Nilai Tugas : "); scanf ("%d", &tugas);
    printf("Nilai UTS : "); scanf ("%d", &uts);
    printf("Nilai UAS : "); scanf ("%d", &uas);
    akhir=0.2*tugas+0.3*uts+0.5*uas;
    printf("Nilai Akhir : %.2f", akhir);

 return 0;
}
