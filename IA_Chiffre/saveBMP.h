#pragma once

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 28/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier contient une unique fonction partager par l'encadrant (M. Dubessy) permettant de créer une image à partir d'un tableau
*/



#ifndef _SAVEBMP_h_ // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define _SAVEBMP_h_ // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

#include <stdio.h> /*FILE*/



void saveBMP(unsigned char data[], int rows, int cols, const char* filename);

#endif
