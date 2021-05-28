#pragma once

/*
Leblanc Anthony, Rousseau Alex

Derni�re modification : 28/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'�crire un logiciel permettant de lire et reconna�tre des chiffres dans des images.
*/

/*
Ce fichier contient une unique fonction partager par l'encadrant (M. Dubessy) permettant de cr�er une image � partir d'un tableau
*/



#ifndef _SAVEBMP_h_ // Si la constante n'a pas �t� d�finie le fichier n'a jamais �t� inclus
#define _SAVEBMP_h_ // On d�finit la constante pour que la prochaine fois le fichier ne soit plus inclus

#include <stdio.h> /*FILE*/



void saveBMP(unsigned char data[], int rows, int cols, const char* filename);

#endif
