/*
Leblanc Anthony, Rousseau Alex

Derni�re modification : 21/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'�crire un logiciel permettant de lire et reconna�tre des chiffres dans des images.
*/

/*
Ce fichier est le fichier d'en-t�te du fichier "csv_image.c".
*/


#pragma once

#define MAX_STR 100

#include <stdio.h>    /*FILE, fgets, puts, rewind*/
#include <string.h>   /*strlen, strcpy, strtok*/
#include <stdlib.h>   /*realloc, free, exit, calloc*/



char* getLine(FILE* file);
unsigned int parametersImages(FILE* file, unsigned int* width, unsigned int* height);
unsigned char* loadImage(unsigned char* number, unsigned int width, unsigned int height, FILE* file);
void load_dataBase(FILE* dataBase);