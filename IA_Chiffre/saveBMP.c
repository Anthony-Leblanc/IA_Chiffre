#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 21/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier contient une unique fonction partager par l'encadrant (M. Dubessy) permettant de créer une image à partir d'un tableau
*/



#include "saveBMP.h"
#include <stdlib.h> /*malloc, free*/



void saveBMP (unsigned char data[], int rows, int cols, const char *filename)
{
  int width = rows, height = cols;
  int pad = (4-(3*width)%4)%4;
  int filesize = 54+(3*width+pad)*height;
  unsigned char header[54] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0, 40,0,0,0,
                                       0,0,0,0, 0,0,0,0, 1,0,24,0};
  char padding[3] = {0,0,0};
  unsigned char *img;
  FILE *file;
  int  i;
  for (i = 0; i < 4; i++)
  {
    header[2+i] = (unsigned char)((filesize>>(8*i))&255);
    header[18+i] = (unsigned char)((width  >>(8*i))&255);
    header[22+i] = (unsigned char)((height >>(8*i))&255);
  }
  img = malloc (sizeof(char)*3*(size_t)width*(size_t)height);
  if (img == NULL)
    printf ("Error could not allocate memory !\n");
  else
  {
    for (i = 0; i < width*height; i++)
    {
      int color = data[i];
      img[3*i+2] = img[3*i+1] = img[3*i] = (unsigned char) (color & 0xFF);
    }
    file = fopen (filename, "wb");
    if (file == NULL)
      printf ("Error: could not open file '%s' !\n", filename);
    else
    {
      fwrite (header, 54, 1, file);
      for (i = height - 1; i >= 0; i--)
      {
        fwrite ((char*)(img+3*width*i), 3*(size_t)width, 1, file);
        fwrite (padding, (unsigned int)pad, 1, file);
      }
      fclose (file);
    }
    free (img);
  }
}
