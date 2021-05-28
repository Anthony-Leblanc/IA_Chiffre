#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 21/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier est le programme principale, permettant de tester les fonctions et d'implémenter le programme principal.
*/



#include <stdio.h>  /*FILE, fopen, puts, printf*/
#include <stdlib.h> /*EXIT_SUCCESS*/

#include "csv_image.h"
#include "saveBMP.h"



void test_GetLine(void);
void test_parametersImages(void);
void test_loadImage(void);
void test_saveBMP(void);
void test_load_dataBase(void);


int main(int argc, char argv[])
{
  //test_GetLine(); // Fonctionne comme souhaité
  //test_parametersImages(); // Fonctionne comme souhaité
  //test_loadImage(); // Fonctionne comme souhaité
  //test_saveBMP(); // Fonctionne comme souhaité
  //test_load_dataBase(); // Fonctionne comme souhaité

  return EXIT_SUCCESS;
}


// Fonction de test de la fonction GetLine
void test_GetLine(void)
{
  printf("****************************************************************************************************\n");
  printf("TEST : getLine\n\n");

  FILE* stream = NULL;

  stream = fopen("images_data.csv", "r");

  if (stream == NULL)
  {
    puts("Error openning stream");
    exit(1);
  }

  char* ligne;
  ligne = getLine(stream);

  printf("\nVoici la ligne du fichier :\n%s\n\n", ligne);
  printf("ICI");

  ligne = getLine(stream);

  fclose(stream);

  printf("\nVoici la ligne du fichier :\n%s\n\n", ligne);
  printf("ICI");

  printf("\n\nFIN DE TEST\n");
  printf("****************************************************************************************************\n");
}

// Fonction de test de la fonction parametersImages
void test_parametersImages(void)
{
  printf("****************************************************************************************************\n");
  printf("TEST : parametersImages\n\n");

  FILE* stream = NULL;

  stream = fopen("images_data.csv", "r");

  if (stream == NULL)
  {
    puts("Error openning stream");
    exit(1);
  }

  int width = 0, height = 0;
  unsigned int nbrImages = parametersImages(stream, &width, &height);

  fclose(stream);

  printf("\nIl y a %d images de largeur : %d, et de longueur : %d\n", nbrImages, width, height);

  printf("\n\nFIN DE TEST\n");
  printf("****************************************************************************************************\n");
}

// Fonction de test de la fonction loadImage
void test_loadImage(void)
{
  printf("****************************************************************************************************\n");
  printf("TEST : loadImage\n\n");

  FILE* stream = NULL;

  stream = fopen("images_data.csv", "r");

  if (stream == NULL)
  {
    puts("Error openning stream");
    exit(1);
  }

  unsigned int width = 0, height = 0; 
  unsigned char* image = NULL, number = 0;
  unsigned int nbrImages = parametersImages(stream, &width, &height);

  image = loadImage(&number, width, height, stream);

  printf("Nombre = %d\nimage : \n", number);
  for (int i = 0; i < width * height; i++)
  {
    printf("%d ", image[i]);
  }
  printf("STOP\n");

  printf("\n\nFIN DE TEST\n");
  printf("****************************************************************************************************\n");
}

// Fonction de test de la fonction saveBMP
void test_saveBMP(void)
{
  printf("****************************************************************************************************\n");
  printf("TEST : saveBMP\n\n");

  FILE* stream = NULL;

  stream = fopen("images_data.csv", "r");
  if (stream == NULL)
  {
    puts("Error openning stream");
    exit(1);
  }

  int width = 0, height = 0;
  unsigned int nbrImages = parametersImages(stream, &width, &height);
  unsigned char* image = NULL, number = 0;

  image = loadImage(&number, width, height, stream);
  saveBMP(image, height, width, "test.bmp");

  printf("\n\nFIN DE TEST\n");
  printf("****************************************************************************************************\n");
}

// Fonction de test de la fonction loadDataFile
void test_load_dataBase(void)
{
  printf("****************************************************************************************************\n");
  printf("TEST : load_dataBase\n\n");

  // Cette première parti est à supprimer par la suite, elle permet de créer un fichier .csv pour le test
  /*
  FILE* stream = NULL;

  stream = fopen("test_load_dataBase.csv", "w");
  if (stream == NULL)
  {
    puts("Error openning stream");
    exit(1);
  }
  fclose(stream);
  */ // Le fichier a bien été crée

  FILE* stream = NULL;

  stream = fopen("test_load_dataBase.csv", "r");
  if (stream == NULL)
  {
    puts("Error openning stream");
    exit(1);
  }

  load_dataBase(stream);

  fclose(stream);

  printf("\n\nFIN DE TEST\n");
  printf("****************************************************************************************************\n");
}
