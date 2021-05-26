#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 21/05/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier est le programme contenant les fonctions de manipulation des fichiers csv.
*/



#include "csv_image.h"



// Fonction permettant de lire dans le fichier file l'intégralité d'une ligne et de la retourner dans un tableau de caractères alloué dynamiquement
char* getLine(FILE* file)
{
  char* str = NULL, * more_str = NULL;
  char buffer[MAX_STR] = "";
  unsigned int taille = 0, tempo_taille = 0;

  while (fgets(buffer, MAX_STR - 1, file) != NULL)
  {
    tempo_taille = taille;
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

    strcpy(str + tempo_taille, buffer);

    if (str[taille - 1] == '\n')
    {
      str[taille - 1] = '\0';
      break;
    }
  }

  return str;
}


// Fonction permettant d'enregistrer les paramètres que la première ligne du fichier csv donne : Nbr Images;Largeur;Hauteur
unsigned int parametersImages(FILE* file, unsigned int* width, unsigned int* height)
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
unsigned char* loadImage(unsigned char *number, unsigned int width, unsigned int height, FILE* file)
{
  unsigned long size_image = 0, index_image = 0;
  char* str = NULL, * pch = NULL, * pImage = NULL, pixel = 0;

  size_image = width * height;
  pImage = (unsigned char*)calloc(size_image, sizeof(unsigned char));
  if (pImage == NULL)
  {
    puts("Error (re)allocating memory");
    exit(1);
  }
  str = getLine(file);
  pch = strtok(str, ",;");
  if (pch == NULL)
  {
    puts("line error, number not encountered");
    exit(1);
  }
  *number = atoi(pch);
  do
  {
    pch = strtok(NULL, ",;");
    pixel = atoi(pch);
    if (pixel == 0) // S'il y a un 0 alors le chiffre qui suit est le nombre d'occurence de ce 0
    {
      pch = strtok(NULL, ",;");
      for (int i = 0; i < atoi(pch); i++)
      {
        pImage[index_image] = pixel;
        index_image++;
      }
    }
    else
    {
      pImage[index_image] = pixel;
      index_image++;
    }
  } while ((pch != NULL) && (index_image < size_image - 1));
  return pImage;
}


// Fonction permettant de charger les images d'une base de données
void load_dataBase(FILE* dataBase)
{
  unsigned int nbrImages = 0, width = 0, height = 0;
  unsigned char* image = NULL, number = 0;
  FILE* stream = NULL;

  stream = fopen("test_load_dataBase.csv", "r");
  if (stream == NULL)
  {
    puts("Error openning stream");
    exit(1);
  }
  nbrImages = parametersImages(stream, &width, &height);

  for (int i = 0; i < nbrImages; i++)
  {
    image = loadImage(&number, width, height, stream);
    // sprintf (pour la chaine du nom du fichier)
  }

  fclose(stream);
}
