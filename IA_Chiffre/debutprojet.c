#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 28/05/2021*/

#include "debutprojet.h"
#include "reseau.h"

void test5(void);

void test_Alex(void)
{
  test1();
  test2();
  test3();
  test4();
  //test5();
}

void test1(void)  // test des fonctions get,set, initialiseWeight et printNeurone
{
  printf("test des premieres fonction set et get\n");
  double tab[] = { 0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0 };
  COUCHE couche;
  setTailleTabw(&couche, 10);
  NEURONE neurone;
  setBiais(&neurone, 1);
  neurone.weight = initialiseWeight(couche.tailleTabw);//on initialise la taille du tableau
  int taille = getTailleTabw(&couche);
  printf("taille du tableau = %d\n ", taille);
  for (int i = 0; i < couche.tailleTabw; i++)
  {
    setWeight(&neurone, tab[i], i); // initialisation d'une strucuture neurone
  }
  printNEURONE(neurone, couche.tailleTabw); // les fonctions get et set de base fonctionne bien
}

void test2(void)// test de getNeurone
{
  double tab[] = { 0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0 };
  COUCHE couche;
  LIST_NEURONE list = { NULL, NULL };
  setTailleTabw(&couche, 10);
  NEURONE neurone;
  NEURONE *neurone2;
  setBiais(&neurone, 1);
  neurone.weight = initialiseWeight(couche.tailleTabw);
  for (int i = 0; i < couche.tailleTabw; i++)
  {
    setWeight(&neurone, tab[i], i); // initialisation d'une strucuture neurone
  }
  printf("\nici j'affiche mon neurone partie test 2 part 1 \n");
  printNEURONE(neurone, couche.tailleTabw);
  list.head = &neurone;
  couche.neurone.head = list.head;
  printf("\nici j'affiche mon neurone partie 2\n");
  neurone2 = getNeurone(&couche, 0);
  printNEURONE(*neurone2, couche.tailleTabw);
  printf("\n");
}

void test3(void)// dernier test des fonction get/set neurone puis test print couche
{
  printf("\ntest fonction get et set neurone et print couche\n");
  COUCHE couche;
  couche.next = NULL;
  couche.prev = NULL;
  LIST_NEURONE list = { NULL,NULL };
  couche.neurone.head = list.head;
  couche.neurone.tail = list.tail;
  setTailleTabw(&couche, 3);
  NEURONE neurone;
  neurone.weight = initialiseWeight(couche.tailleTabw);
  neurone.biais =1.5;
  int i = 0;
  for (i = 0; i < 3; i++)
    neurone.weight[i] = i;
  NEURONE neurone2;
  neurone2.weight = initialiseWeight(couche.tailleTabw);
  neurone2.biais = 2.4;
  i = 0;
  for (i = 0; i < 3; i++)
    neurone2.weight[i] = i;
  NEURONE neurone3;
  neurone3.weight = initialiseWeight(couche.tailleTabw);
  neurone3.biais = 3.6;;
  i = 0;
  for (i = 0; i < 3; i++)
    neurone3.weight[i] = i; //jusqu'ici création de 3 neurones
  setNeurone(&couche, &neurone);
  setNeurone(&couche, &neurone2);
  setNeurone(&couche,&neurone3); // ajout des 3 neurones dans la liste de la couche créée
  printCouche(couche);// on affiche notre couche
}

void test4(void)
{
  printf("\n\ntest fonction save neural network\n");
  NETWORK network;
  COUCHE couche;
  couche.next = NULL;
  couche.prev = NULL;
  LIST_NEURONE list = { NULL,NULL };
  couche.neurone.head = list.head;
  couche.neurone.tail = list.tail;
  setTailleTabw(&couche, 3);
  NEURONE neurone;
  neurone.weight = initialiseWeight(couche.tailleTabw);
  neurone.biais = 1.5;
  int i = 0;
  for (i = 0; i < 3; i++)
    neurone.weight[i] = i;
  NEURONE neurone2;
  neurone2.weight = initialiseWeight(couche.tailleTabw);
  neurone2.biais = 2.4;
  i = 0;
  for (i = 0; i < 3; i++)
    neurone2.weight[i] = i;
  NEURONE neurone3;
  neurone3.weight = initialiseWeight(couche.tailleTabw);
  neurone3.biais = 3.6;
  i = 0;
  for (i = 0; i < 3; i++)
    neurone3.weight[i] = i; //jusqu'ici création de 3 neurones dans la couche 0
  setNeurone(&couche, &neurone);
  setNeurone(&couche, &neurone2);
  setNeurone(&couche, &neurone3);
  network.list_layer.head = &couche;
  printCouche(*network.list_layer.head);
  COUCHE couche1;
  couche1.next = NULL;
  couche1.prev = network.list_layer.head;
  LIST_NEURONE list1 = { NULL,NULL };
  couche1.neurone.head = list1.head;
  couche1.neurone.tail = list1.tail;
  setTailleTabw(&couche1, 3);
  NEURONE neurone4;
  neurone4.weight = initialiseWeight(couche1.tailleTabw);
  neurone4.biais = 2.5;
  i = 0;
  for (i = 0; i < 3; i++)
    neurone4.weight[i] = i+8.0;
  NEURONE neurone5;
  neurone5.weight = initialiseWeight(couche1.tailleTabw);
  neurone5.biais = 4.2;
  i = 0;
  for (i = 0; i < 3; i++)
    neurone5.weight[i] = i+1.7;
  NEURONE neurone6;
  neurone6.weight = initialiseWeight(couche1.tailleTabw);
  neurone6.biais = 7.2;
  i = 0;
  for (i = 0; i < 3; i++)
    neurone6.weight[i] = i-1.0; 
  NEURONE neurone7;
  neurone7.weight = initialiseWeight(couche1.tailleTabw);
  neurone7.biais = 6.2;
  i = 0;
  for (i = 0; i < 3; i++)
    neurone7.weight[i] = i+2.0; //jusqu'ici création de 4 neurones dans la couche 1
  setNeurone(&couche1, &neurone4);
  setNeurone(&couche1, &neurone5);
  setNeurone(&couche1, &neurone6);
  setNeurone(&couche1, &neurone7);
  network.list_layer.head->next = &couche1;
  network.list_layer.tail = &couche1;
  printf("\n\n");
  printCouche(*network.list_layer.head->next);
  COUCHE couche2;
  couche2.next = NULL;
  couche2.prev = network.list_layer.head->next;
  LIST_NEURONE list2 = { NULL,NULL };
  couche2.neurone.head = list2.head;
  couche2.neurone.tail = list2.tail;
  setTailleTabw(&couche2, 5);
  NEURONE neurone8;
  neurone8.weight = initialiseWeight(couche2.tailleTabw);
  neurone8.biais = 1.5;
  i = 0;
  for (i = 0; i < 5; i++)
    neurone8.weight[i] = i + 6.0;
  NEURONE neurone9;
  neurone9.weight = initialiseWeight(couche2.tailleTabw);
  neurone9.biais = 5.78;
  i = 0;
  for (i = 0; i < 5; i++)
    neurone9.weight[i] = i - 1.7;
  NEURONE neurone10;
  neurone10.weight = initialiseWeight(couche2.tailleTabw);
  neurone10.biais = 7.2;
  i = 0;
  for (i = 0; i < 5; i++)
    neurone10.weight[i] = i - 1.458; 
  NEURONE neurone11;
  neurone11.weight = initialiseWeight(couche2.tailleTabw);
  neurone11.biais = 3.75;
  i = 0;
  for (i = 0; i < 5; i++)
    neurone11.weight[i] = i + 15.5; //jusqu'ici création de 4 neurones dans le couche 2
  setNeurone(&couche2, &neurone8);
  setNeurone(&couche2, &neurone9);
  setNeurone(&couche2, &neurone10);
  setNeurone(&couche2, &neurone11);
  network.list_layer.head->next->next = &couche2;
  network.list_layer.tail = &couche2;
  printf("\n\n");
  printCouche(*network.list_layer.head->next->next);
  save_neuralNetwork(&network);
  printf("\nsauvegarde sur un fichier csv\n");
}

void test5(void)
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
  save_neuralNetwork(network);
}