/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 21/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier est le fichier d'en-tête du fichier "csv_image.c".
*/



#ifndef _CSV_IMAGE_h_ // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define _CSV_IMAGE_h_ // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

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
