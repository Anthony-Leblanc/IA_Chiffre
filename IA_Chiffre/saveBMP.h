#pragma once

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 21/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier contient une unique fonction partager par l'encadrant (M. Dubessy) permettant de créer une image à partir d'un tableau
*/



#include <stdio.h> /*FILE*/



void saveBMP(unsigned char data[], int rows, int cols, const char* filename);