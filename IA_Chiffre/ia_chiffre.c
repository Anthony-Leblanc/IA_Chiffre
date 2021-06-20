#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 16/06/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier est le programme principale, permettant de tester les fonctions et d'implémenter le programme principal.
*/


#include <stdio.h>  /*FILE, fopen, puts, printf*/
#include <stdlib.h> /*EXIT_SUCCESS*/

#include "debutprojet.h"
#include "test_Antho.h"



int main(int argc, char argv[])
{
  test_Alex();
  printf("\n\n\n");
  test_Antho();

  return EXIT_SUCCESS;
}

