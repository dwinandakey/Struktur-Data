#include <stdio.h>

struct Penduduk
{
  char nama[100];
  char alamat[100];
  int umur;
  float gaji;
};

int
main ()
{

  //array dalam struct karena pdk[1,2,..,n] merupakan array dari structure Penduduk
  //struct dalam array karena setiap elemen dari array pdk adalah struktur yang memiliki nama, alamat, umur, dan gaji
  struct Penduduk pdk[3];

  printf ("\nMasukkan Data Penduduk\n");
  for (int i = 0; i < 3; i++)
        {
          printf ("Penduduk %d\n", i + 1);
          printf ("Nama: ");
          scanf (" %[^\n]s", &pdk[i].nama);
          printf ("Alamat: ");
          scanf (" %[^\n]s", &pdk[i].alamat);
          printf ("Umur: ");
          scanf (" %d", &pdk[i].umur);
          printf ("Gaji: ");
          scanf (" %f", &pdk[i].gaji);
        }

  printf ("\nData Penduduk:\n");
      for (int i = 0; i < 3; i++)
        {
          printf ("Penduduk %d\n", i + 1);
          printf ("Nama: %s\n", pdk[i].nama);
          printf ("Alamat: %s\n", pdk[i].alamat);
          printf ("Umur: %d\n", pdk[i].umur);
          printf ("Gaji: %.2f\n", pdk[i].gaji);
        }

  return 0;
}
