#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Derni�re modification : 07/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'�crire un logiciel permettant de lire et reconna�tre des chiffres dans des images.
*/

/*
Ce fichier est le programme principale, permettant de tester les fonctions et d'impl�menter le programme principal.
*/


#include <stdio.h>  /*FILE, fopen, puts, printf*/
#include <stdlib.h> /*EXIT_SUCCESS*/

#include "csv_image.h"


void test_GetLine(void);


int main(int argc, char argv[])
{
  test_GetLine();

  return EXIT_SUCCESS;
}


// Fonction de test de la fonction GetLine
void test_GetLine(void)
{
  FILE* stream = NULL;

  stream = fopen("images_data.csv", "r");

  if (stream == NULL)
  {
    puts("Error (re)allocating memory");
    exit(1);
  }

  char ligne[];
  ligne = getLine(stream);

  printf("\nVoici la ligne du fichier :\n%s\n\n", ligne);
}