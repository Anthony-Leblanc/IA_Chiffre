#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 21/05/2021*/


#include<stdio.h> /*printf*/
#include<stdlib.h>/*calloc*/
#include "reseau.h"

void test1(void);
void test2(void);

int main(int argc, char argv[])
{
  test1();
  test2();
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
  setNbrNeurone(&couche, 10);
  NEURONE neurone;
  setBiais(&neurone, 1);
  neurone.weight = initialiseWeight(couche.nbrNeurone);
  for (int i = 0; i < couche.nbrNeurone; i++)
  {
    setWeight(&neurone, tab[i], i); // initialisation d'une strucuture neurone
  }
  printNEURONE(neurone, couche.nbrNeurone);
  LIST list = { NULL, NULL };
  //appendToList(&list, neurone, 0);
}