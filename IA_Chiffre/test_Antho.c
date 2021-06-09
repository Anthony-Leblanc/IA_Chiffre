#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 09/06/2021

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
  //test_GetLine(); // Fonctionne comme souhaité
  //test_parametersImages(); // Fonctionne comme souhaité
  //test_loadImage(); // Fonctionne comme souhaité
  //test_saveBMP(); // Fonctionne comme souhaité
  //test_load_dataBase(); // Fonctionne comme souhaité
  test_load_neuralNetwork(); // En cours d'étude
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

// Fonction de teste de la fonction load_neuralNetwork
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
  printCouche(*network->list_layer.head);

  printf("\n\nFIN DE TEST\n");
  printf("****************************************************************************************************\n");
}

//****************************************************************************************************
// A ajouter à reseau.h

// Fonction permettant d'initialiser un réseau de neuronnes à partir d'un fichier
// Bibliothèques à inclure :
//#include <stdio.h> /*puts*/
//#include <string.h> /*strtok*/
//#include <stdlib.h> /*atoi, strtod*/

NETWORK* load_neuralNetwork(FILE* stream)
{
  NETWORK* network = (NETWORK*)calloc(1, sizeof(NETWORK));
  char* str = NULL;
  //LIST_LAYER list_layer = { NULL };
  LIST_NEURONE list_neurone = { NULL };

  str = getLine(stream);

  if (str == NULL)
  {
    puts("The neural network file is empty");
    return network;
  }

  while (str != NULL && str[0] != '\0') // On parcourt l'ensemble du fichier
  {
    COUCHE couche = { NULL };
    int nbrWeight = 0, nbrNeurone = 0;
    double value = 0.0;
    char* pch = NULL; printf("\nJe suis ici : |%s|\n", str);
    // Étape 1 : reconnaître une COUCHE :
    pch = strtok(str, ";"); nbrWeight = atoi(pch); // Le premier élément est le nombre de poids des neurones de la couche
    pch = strtok(NULL, ";"); nbrNeurone = atoi(pch); // Le deuxième élément est le nombre de neurone de la couche
    couche.tailleTabw = nbrWeight; // Initialisation du champ du nombre de poids dans des neuronnes de la couche

    // Étape 2 : initialiser les neurones de la couche (et les y ajouter)
    for (int i = 0; i < nbrNeurone; i++) // Parcours des neurones
    {
      NEURONE neurone = { 0.0, };
      neurone.weight = initialiseWeight(nbrWeight); // On alloue la mémoire nécessaire au poids des neurones de la couche
      str = getLine(stream); // On récupère les infos du neurone
      pch = strtok(str, ";"); value = strtod(pch, NULL); 
      setBiais(&neurone, value); // On écrit la valeur du biais du neuronne
      
      for (int j = 0; j < nbrWeight; j++) // Il faut maintenant enregistrer les poids du neurone
      {
        pch = strtok(NULL, ";"); value = strtod(pch, NULL);
        setWeight(&neurone, value, j); // On enregistre le poids "j"
      }
      setNeurone(&couche, &neurone);  printf("\nTEST :\n"); printCouche(couche); printf("\nFIN TEST\n");// On ajoute le neurone à la couche
    }

    // Étape 3 : on ajoute la couche à la liste de couche
    if (network->list_layer.tail == NULL) // Cas de la liste vide
    {
      network->list_layer.head = &couche;
      network->list_layer.tail = &couche;
    }
    else // S'il existe déjà un élément dans la liste
    {
      network->list_layer.tail->next = &couche;
      couche.prev = network->list_layer.tail;
      couche.next = NULL;
      network->list_layer.tail = &couche;
    }
    str = getLine(stream); // On prend un nouvelle ligne, permet aussi de vérifier la condition du while
  }

  // Étape 4 : ajout de la liste de couche dans le réseau de neurones
  //network->list_layer = list_layer;
  return network;
}

// Fin d'ajout
//****************************************************************************************************