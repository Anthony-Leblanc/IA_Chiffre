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


#include <stdio.h>    /*FILE, fgets, strlen, puts, strcat*/
#include <string.h>   /*strlen, strcar*/
#include <stdlib.h>   /*realloc*/


#include "csv_image.h"

// Fonction permettant de lire dans le fichier file l'intégralité d'une ligne et de la retourner dans un tableau de caractères alloué dynamiquement
char* getLine(FILE* file)
{
  char* str = NULL, * more_str = NULL;
  unsigned long taille = 0;
  char buffer[MAX_STR];

  while (fgets(buffer, MAX_STR, file) != NULL)
  {
    taille += strlen(buffer);
    more_str = (char*)realloc(str, taille * sizeof(char));

    if (more_str != NULL) // Traitement après réallocation
    {
      str = more_str;
      str[strlen(str) - 1] = '\0';
    }
    else
    {
      free(str);
      puts("Error (re)allocating memory");
      exit(1);
    }

    strcat(str + strlen(str), buffer);
    taille++;

    if (str[taille] == '\n')
    {
      str[taille] = '\0';
      break;
    }
  }

  return str;

  

  /*
  Fonction getLine
Pseudo code d'une fonction char *getLine(FILE *file) permettant de lire dans le fichier file l'intégralité d'une ligne et de la retourner dans un tableau de caractères alloué dynamiquement:

on déclare un pointeur vers un caractère, str, initialisé à NULL
on déclare une taille initialisée à 0
on déclare un chaîne de caractère de taille fixe et vide, le buffer
tant que l'appel à fgets pour remplir le buffer depuis le fichier n'est pas NULL
 on calcule la taille de la chaine mise dans buffer
on réalloue au pointeur str une nouvelle taille
on copie à la fin de la chaine str le buffer
on incrémente la variable taille
si le dernier caractère de str est '\n'
on le remplace par '\0' (fin de chaîne)
on quite la boucle
on retourne le pointeur str
Indication supplémentaire: la fin de la chaine str se trouve à l'adresse: str+strlen(str)

Modifié le: vendredi 2 avril 2021, 09:57
  */
}