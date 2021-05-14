#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 14/05/2021*/

#include "reseau.h"
#include<stdio.h> /*printf*/

void test1(void);

int main(int argc, char argv[])
{
  test1();
}

void test1(void)
{
 int tab[] = { 0,1,2,3,4,5,6,7,8,9 };
 NEURONE neurone;
 neurone.biais = 1;
 neurone.weight = tab; // initialisation d'une strucuture neurone
int x = sizeof(neurone.weight) / sizeof(neurone.weight[0]); // je veux trouver la taille d'un tableau que je ne connais pas. Mais fonctionne pas comme je veux
 printNEURONE(neurone,x); // test des fonctions get et print 
}