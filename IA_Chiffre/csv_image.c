#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 07/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier est le programme contenant les fonctions de manipulation des fichiers csv.
*/


#include <stdio.h>    /*FILE, fgets, puts, rewind*/
#include <string.h>   /*strlen, strcpy, strtok*/
#include <stdlib.h>   /*realloc, free, exit, calloc*/

#include "csv_image.h"


// Fonction permettant de lire dans le fichier file l'intégralité d'une ligne et de la retourner dans un tableau de caractères alloué dynamiquement
char* getLine(FILE* file)
{
  char* str = NULL, * more_str = NULL;
  char buffer[MAX_STR] = "";
  unsigned int taille = 0;

  while (fgets(buffer, MAX_STR, file) != NULL)
  {
    taille += strlen(buffer);
    more_str = (char*)realloc(str, taille * sizeof(char));
    
    // Test de l'allocation
    if (more_str != NULL) {
      str = more_str;
      str[taille] = '\0';
    }
    else {
      free(str);
      puts("Error (re)allocating memory");
      exit(1);
    }

    strcpy(str + strlen(str) - strlen(buffer), buffer);

    if (str[strlen(str) - 1] == '\n')
    {
      str[strlen(str) - 1] = '\0';
      break;
    }
  }

  return str;
}


// Fonction permettant d'enregistrer les paramètres que la première ligne du fichier csv donne : Nbr Images;Largeur;Hauteur
unsigned int parametersImages(FILE* file, int* width, int* height)
{
  rewind(file); // On s'assure qu'on se trouve bien au début du fichier

  char* str = NULL, * pch = NULL;
  unsigned int nbrImages = 0;

  str = getLine(file);
  
  pch = strtok(str, ";");

  nbrImages = atoi(pch);  pch = strtok(NULL, ";");
  *width = atoi(pch);     pch = strtok(NULL, ";");
  *height = atoi(pch);

  return nbrImages;
}


// Fonction permettant de charger l'image dans un tableau tout en donnant la valeur de l'entier de l'image
int loadImage(char* out, int width, int height, FILE* file)
{
  int number = 0, pixel = 0, size_image = 0, index_image = 0;
  char* pImage = NULL, * str = NULL, * pch = NULL;

  size_image = width * height;

  pImage = (char*)calloc(size_image, sizeof(char));

  if (pImage == NULL)
  {
    puts("Error (re)allocating memory");
    exit(1);
  }

  str = getLine(file);

  pch = strtok(str, ";");
  number = atoi(pch);

  do
  {
    pch = strtok(NULL, ";");
    pixel = atoi(pch);

    if (pixel == 0) // S'il y a un 0 alors le chiffre qui suit est le nombre d'occurence de ce 0
    {
      pch = strtok(NULL, ",");
      for (int i = 0; i < atoi(pch); i++)
        pImage[index_image + i] = pixel;
    }
    else
      pImage[index_image] = pixel;

    index_image++;
  } while (pch != NULL);

  return number;
}