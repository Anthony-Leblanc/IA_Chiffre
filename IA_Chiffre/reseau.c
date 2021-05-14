#define _CRT_SECURE_NO_WARNINGS
/*dernière modification 14/05/2021,LEBLANC Anthony,ROUSSEAU Alex*/

#include "reseau.h"
#include<stdio.h> /*printf*/



void printNEURONE(NEURONE neurone,int n) //affiche tout un neurone
{

	printf("Biais : %d Weight :", getBiais(&neurone));
	int i = 0;
	while (i < n )
	{
		printf("%d,", getWeight(&neurone, i));
		i++;
	}
}



unsigned int getBiais(NEURONE* neurone) // obtient le biais d'un neurone 
{
	return neurone->biais;
}

unsigned int getWeight(NEURONE* neurone,int n)// obtient weight position n d'un neurone.
{
	return neurone->weight[n];
}