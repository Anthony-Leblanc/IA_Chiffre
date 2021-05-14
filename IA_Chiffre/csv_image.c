#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Derni�re modification : 07/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'�crire un logiciel permettant de lire et reconna�tre des chiffres dans des images.
*/

/*
Ce fichier est le programme contenant les fonctions de manipulation des fichiers csv.
*/


#include <stdio.h>    /*FILE, fgets, strlen, puts, strcat*/
#include <string.h>   /*strlen, strcar*/
#include <stdlib.h>   /*realloc*/


#include "csv_image.h"

// Fonction permettant de lire dans le fichier file l'int�gralit� d'une ligne et de la retourner dans un tableau de caract�res allou� dynamiquement
char* getLine(FILE* file)
{
  char* str = NULL, * more_str = NULL;
  unsigned long taille = 0;
  char buffer[MAX_STR];

  while (fgets(buffer, MAX_STR, file) != NULL)
  {
    taille += strlen(buffer);
    more_str = (char*)realloc(str, taille * sizeof(char));

    if (more_str != NULL) // Traitement apr�s r�allocation
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
Pseudo code d'une fonction char *getLine(FILE *file) permettant de lire dans le fichier file l'int�gralit� d'une ligne et de la retourner dans un tableau de caract�res allou� dynamiquement:

on d�clare un pointeur vers un caract�re, str, initialis� � NULL
on d�clare une taille initialis�e � 0
on d�clare un cha�ne de caract�re de taille fixe et vide, le buffer
tant que l'appel � fgets pour remplir le buffer depuis le fichier n'est pas NULL
 on calcule la taille de la chaine mise dans buffer
on r�alloue au pointeur str une nouvelle taille
on copie � la fin de la chaine str le buffer
on incr�mente la variable taille
si le dernier caract�re de str est '\n'
on le remplace par '\0' (fin de cha�ne)
on quite la boucle
on retourne le pointeur str
Indication suppl�mentaire: la fin de la chaine str se trouve � l'adresse: str+strlen(str)

Modifi� le: vendredi 2 avril 2021, 09:57
  */
}