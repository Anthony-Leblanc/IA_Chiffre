#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 21/05/2021*/


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
  int tab[] = { 0,1,2,3,4,5,6,7,8,9 };
  COUCHE couche;
  setNbrNeurone(&couche, 10);
  NEURONE neurone;
  setBiais(&neurone, 1);
  neurone.weight = initialiseWeight(couche.nbrNeurone);
  int taille = getNbrNeurone(&couche);
  printf("taille = %d ", taille);
  for (int i = 0; i < couche.nbrNeurone; i++)
  {
    setWeight(&neurone, tab[i], i); // initialisation d'une strucuture neurone
  }
  printNEURONE(neurone, couche.nbrNeurone);
}

void test2(void)
{
  int tab[] = { 0,1,2,3,4,5,6,7,8,9 };
  COUCHE couche;
  LIST list = { NULL, NULL };
  setNbrNeurone(&couche, 10);
  NEURONE neurone;
  NEURONE neurone2;
  setBiais(&neurone, 1);
  neurone.weight = initialiseWeight(couche.nbrNeurone);
  for (int i = 0; i < couche.nbrNeurone; i++)
  {
    setWeight(&neurone, tab[i], i); // initialisation d'une strucuture neurone
  }
  printf("\nici j'affiche mon neurone partie test 2 part 1 ");
  printNEURONE(neurone, couche.nbrNeurone);
  list.head = &neurone;
  couche.neurone.head = list.head;
  printf("\nici j'affiche mon neurone partie 2");
  neurone2 = getNeurone(&couche, 0);
  printNEURONE(neurone2, couche.nbrNeurone);
}

void test3(void)
{
  printf("\ntest fonction get et set neurone et print couche\n");
  COUCHE couche;
  LIST list = { NULL,NULL };
  setNbrNeurone(&couche, 3);
  NEURONE neurone;
  neurone.weight = initialiseWeight(couche.nbrNeurone);
  neurone.biais =1.5;
  int i = 0;
  for (i = 0; i < i + 3; i++)
    neurone.weight[i] = i;
  NEURONE neurone2;
  neurone2.weight = initialiseWeight(couche.nbrNeurone);
  neurone2.biais = 1.5;
  i = 0;
  for (i = 0; i < i + 3; i++)
    neurone2.weight[i] = i;
  NEURONE neurone3;
  neurone3.weight = initialiseWeight(couche.nbrNeurone);
  neurone3.biais = 1.5;
  i = 0;
  for (i = 0; i < i + 3; i++)
    neurone3.weight[i] = i;
  setNeurone(&couche, neurone);
  setNeurone(&couche, neurone2);
  setNeurone(&couche, neurone3);
  printCouche(couche);
}