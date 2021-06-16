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



#include "test_Antho.h"

#include "csv_image.h"
#include "saveBMP.h"
#include "reseau.h"




void test_Antho(void)
{
  //test();
  //test_GetLine(); // Fonctionne comme souhaité
  //test_parametersImages(); // Fonctionne comme souhaité
  //test_loadImage(); // Fonctionne comme souhaité
  //test_saveBMP(); // Fonctionne comme souhaité
  //test_load_dataBase(); // Fonctionne comme souhaité
  //test_load_neuralNetwork(); // Semble fonctionné comme souhaité (ordinateur maison)
  test_feedforward(); // En cours d'étude
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
  // Comparaison avec la ligne du fichier :
  /*rewind(stream);
  getLine(stream);
  char carac = 'a', correct = 1;
  unsigned int compteur = 0;
  while (carac != '\n' && carac != EOF && carac != '\0') {
    carac = fgetc(stream);
    if (ligne[compteur] != carac) {
      correct = 0;
      printf("\nLe fonction a un probleme dans son fonctionnement !\nCaractere fichier : %c, caractere string : %c, a l'adresse : %d\n", carac, ligne[compteur], compteur);
      break;
    }
    compteur++;
  }
  if (correct == 1)
    printf("\nLa fonction fonctionne correctement\n");
  */

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
  for (unsigned int i = 0; i < width * height; i++)
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

// Fonction de test de la fonction load_neuralNetwork
void test_load_neuralNetwork(void)
{
  printf("****************************************************************************************************\n");
  printf("TEST : load_neuralNetwork\n\n");

  NETWORK* network = NULL;
  FILE* stream = NULL;

  stream = fopen("network_30_10.csv", "r");
  if (stream == NULL)
  {
    puts("Error openning stream");
    exit(1);
  }

  network = load_neuralNetwork(stream);
  fclose(stream);
  printCouche(*network->list_layer.head);

  printf("\n\nFIN DE TEST\n");
  printf("****************************************************************************************************\n");
}

// Fonction de test de la fonction feedforward
void test_feedforward(void)
{
  printf("****************************************************************************************************\n");
  printf("TEST : feedforward\n\n");

  FILE* file_neural_network = NULL;
  file_neural_network = fopen("network_30_10.csv", "r");
  if (file_neural_network == NULL) {
    puts("\nError openning stream\n");
    exit(1);
  }
  NETWORK* network = NULL;
  network = load_neuralNetwork(file_neural_network);
  fclose(file_neural_network);
  FILE* data_base = NULL;
  data_base = fopen("images_data.csv", "r");
  if (data_base == NULL) {
    puts("\nError openning stream\n");
    exit(1);
  }
  unsigned int width = 0, height = 0, nbrImages = 0;
  nbrImages = parametersImages(data_base, &width, &height);
  // On cherche le nombre de neurones de la dernière couche
  COUCHE* couche = NULL;
  couche = network->list_layer.tail;
  if (couche == NULL) {
    puts("\nReseau vide\n");
    exit(1);
  }
  if (couche->neurone.tail == NULL) {
    puts("\nCouche vide");
    exit(1);
  }
  unsigned int nbr_neural_last_layer = 0;
  NEURONE* neurone = NULL;
  for (neurone = couche->neurone.head; neurone->next != NULL; neurone = neurone->next)
    nbr_neural_last_layer++;

  double succes_rate = 0.0;

  // On test la sortie du réseau pour chaque image
  for (int i = 0; i < nbrImages; i++)
  {
    char* image = NULL;
    unsigned char number = 0, number_output = -1;
    double* output = NULL, compare_output = 0.0;
    image = loadImage(&number, width, height, data_base);
    output = feedforward(*network, image);
    // On récupère la sortie du réseau de neurones 
    for (int j = 0; j < nbr_neural_last_layer; j++)
    {
      if (output[j] > compare_output)
      {
        compare_output = output[j];
        number_output = j;
      }
    }
    if (number == number_output)
      succes_rate++;
  }
  fclose(data_base);
  printf("\nTaux de succes du reseau de neurones : %f%", (succes_rate / nbrImages) * 100);

  printf("\n\nFIN DE TEST\n");
  printf("****************************************************************************************************\n");
}

// Fonction pour de simple test de débogage
void test(void)
{
  printf("****************************************************************************************************\n");
  printf("TEST : test\n\n");

  FILE* database = NULL;
  database = fopen("images_data.csv", "r");
  if (database == NULL) {
    puts("Impossble d'ouvrir le fichier");
    exit(1);
  }
  unsigned int width = 0, height = 0, nbrImages = 0;
  nbrImages = parametersImages(database, &width, &height);
  for (int i = 0; i < nbrImages; i++) {
    char* str = NULL;
    unsigned char number = 0;
    str = loadImage(&number, width, height, database);
    printf("Nombre = %d\nimage : \n", number);
    for (unsigned int i = 0; i < width * height; i++)
    {
      printf("%d ", str[i]);
    }
    printf("\n\n");
  }
  fclose(database);

  printf("\n\nFIN DE TEST\n");
  printf("****************************************************************************************************\n");
}