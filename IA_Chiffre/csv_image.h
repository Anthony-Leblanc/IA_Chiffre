/*
Leblanc Anthony, Rousseau Alex

Derni�re modification : 21/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'�crire un logiciel permettant de lire et reconna�tre des chiffres dans des images.
*/

/*
Ce fichier est le fichier d'en-t�te du fichier "csv_image.c".
*/



#ifndef _CSV_IMAGE_h_ // Si la constante n'a pas �t� d�finie le fichier n'a jamais �t� inclus
#define _CSV_IMAGE_h_ // On d�finit la constante pour que la prochaine fois le fichier ne soit plus inclus

  #pragma once

  #define MAX_STR 100

  #include <stdio.h>    /*FILE, fgets, puts, rewind*/
  #include <string.h>   /*strlen, strcpy, strtok*/
  #include <stdlib.h>   /*realloc, free, exit, calloc*/



  char* getLine(FILE* file);
  unsigned int parametersImages(FILE* file, unsigned int* width, unsigned int* height);
  unsigned char* loadImage(unsigned char* number, unsigned int width, unsigned int height, FILE* file);
  void load_dataBase(FILE* dataBase);

#endif
