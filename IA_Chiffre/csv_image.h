/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 07/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier est le fichier d'en-tête du fichier "csv_image.c".
*/


#pragma once

#define MAX_STR 100


char* getLine(FILE* file);
unsigned int parametersImages(FILE* file, int* width, int* height);
int loadImage(char* out, int width, int height, FILE* file);