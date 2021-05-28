#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 28/05/2021*/


#include<stdio.h> /*printf*/
#include<stdlib.h>/*calloc*/
#include "reseau.h"

void test1(void);
void test2(void);
void test3(void);

int main(int argc, char argv[])
{
  test1();
  test2();
  test3();
}

void test1(void)  // test des fonctions get,set, initialiseWeight et printNeurone
{
  printf("test des premières fonction set et get\n");
  int tab[] = { 0,1,2,3,4,5,6,7,8,9 };
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

void test2(void)
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
  printf("\nici j'affiche mon neurone partie test 2 part 1 ");
  printNEURONE(neurone, couche.tailleTabw);
  list.head = &neurone;
  couche.neurone.head = list.head;
  printf("\nici j'affiche mon neurone partie 2");
  neurone2 = getNeurone(&couche, 0);
  printNEURONE(*neurone2, couche.tailleTabw);
}

void test3(void)
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
    neurone3.weight[i] = i;
  setNeurone(&couche, &neurone);
  setNeurone(&couche, &neurone2);
  setNeurone(&couche,&neurone3);
  printCouche(couche);
}