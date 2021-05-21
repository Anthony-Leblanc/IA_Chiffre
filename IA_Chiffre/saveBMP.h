#pragma once

/*
Leblanc Anthony, Rousseau Alex

Derni�re modification : 21/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'�crire un logiciel permettant de lire et reconna�tre des chiffres dans des images.
*/

/*
Ce fichier contient une unique fonction partager par l'encadrant (M. Dubessy) permettant de cr�er une image � partir d'un tableau
*/



#include <stdio.h> /*FILE*/



void saveBMP(unsigned char data[], int rows, int cols, const char* filename);