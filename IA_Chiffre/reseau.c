#define _CRT_SECURE_NO_WARNINGS
/*dernière modification 14/05/2021,LEBLANC Anthony,ROUSSEAU Alex*/

#include "reseau.h"
#include<stdio.h> /*printf*/


void printNEURONE(NEURONE neurone)
{

	printf("Biais : %d Weight :", getBiais(&neurone));
	int i = 0;
	while (getWeight(&neurone, i) != "\0")
	{
		printf("%d,", getWeight(&neurone, i));
		i++;
	}
}



unsigned int getBiais(NEURONE* neurone)
{
	return neurone->biais;
}

unsigned int getWeight(NEURONE* neurone,int n)
{
	return neurone->weight[n];
}