#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 09/06/2021

Projet : Intelligence artificielle
Le but de ce projet est d'écrire un logiciel permettant de lire et reconnaître des chiffres dans des images.
*/

/*
Ce fichier est le programme contenant les fonctions de manipulation des fichiers csv.
*/



#include "csv_image.h"
#include "saveBMP.h"



// Fonction permettant de lire dans le fichier file l'intégralité d'une ligne et de la retourner dans un tableau de caractères alloué dynamiquement
char* getLine(FILE* file)
{/*
  char* str = NULL, * more_str = NULL;
  char buffer[MAX_STR] = "";
  unsigned int taille = 0, tempo_taille = 0;

  while (fgets(buffer, MAX_STR - 1, file) != NULL)
  {
    tempo_taille = taille;
    taille += strlen(buffer);
    more_str = (char*)realloc(str, taille * sizeof(char) + 1);

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
  */
  // Fonction provenant de hackerrank 
  /*
  size_t alloc_length = 1024;
  size_t data_length = 0;

  char* data = malloc(alloc_length);

  while (1) {
    char* cursor = data + data_length;
    char* line = fgets(cursor, alloc_length - data_length, file);

    if (!line) {
      break;
    }

    data_length += strlen(cursor);

    if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
      break;
    }

    alloc_length <<= 1;

    data = realloc(data, alloc_length);

    if (!data) {
      data = '\0';

      break;
    }
  }

  if (data[data_length - 1] == '\n') {
    data[data_length - 1] = '\0';

    data = realloc(data, data_length);

    if (!data) {
      data = '\0';
    }
  }
  else {
    data = realloc(data, data_length + 1);

    if (!data) {
      data = '\0';
    }
    else {
      data[data_length] = '\0';
    }
  }

  return data;
  // Fin de la fonction provenant de hackerrank
  */
  
  char* str = NULL;
  str = (char*)calloc(TAILLE_MAX, sizeof(char));
  fgets(str, TAILLE_MAX, file);
  if (str != NULL)
  {
	  if (str[strlen(str)-1] == '\n')
		str[strlen(str)-1] = '\0';
	  return str;
  }
  else {
    puts("Error getLine\n");
    return NULL;
  }
  
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
unsigned char* loadImage(unsigned char* number, unsigned int width, unsigned int height, FILE* file)
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
// Fonction à modifier par la suite pour s'en servir pour l'entrainement du réseau de neuronnes
void load_dataBase(FILE* dataBase)
{
  unsigned int nbrImages = 0, width = 0, height = 0;
  unsigned char* image = NULL, number = 0, imageName[20];
  FILE* stream = NULL;

  stream = fopen("test_load_dataBase.csv", "r");
  if (stream == NULL)
  {
    puts("Error openning stream");
    exit(1);
  }
  nbrImages = parametersImages(stream, &width, &height);

  for (unsigned int i = 0; i < nbrImages; i++)
  {
    image = loadImage(&number, width, height, stream);
    sprintf(imageName, "image_%d___%d.bmp", i, number); printf("\nTEST : %s\n", imageName);
    saveBMP(image, height, width, imageName); // A remplacer par imageTraining()
  }

  fclose(stream);
}
