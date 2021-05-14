/*
Leblanc Anthony, Rousseau Alex

Derni�re modification : 07/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'�crire un logiciel permettant de lire et reconna�tre des chiffres dans des images.
*/

/*
Ce fichier est le fichier d'en-t�te du fichier "csv_image.c".
*/


#pragma once

#define MAX_STR 100


char* getLine(FILE* file);
unsigned int parametersImages(FILE* file, int* width, int* height);
int loadImage(char* out, int width, int height, FILE* file);