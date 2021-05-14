#define _CRT_SECURE_NO_WARNINGS

/*
Leblanc Anthony, Rousseau Alex

Dernière modification : 14/05/2021*/

#include "reseau.h"
#include<stdio.h> /*printf*/

void test1(void);

int main(int argc, char argv[])
{
  void test1();
}

void test1(void)
{
 int tab[] = { 0,1,2,3,4,5,6,7,8,9 };
 NEURONE neurone;
 neurone.biais = 1;
 neurone.weight = tab;
 printNEURONE(neurone);
}