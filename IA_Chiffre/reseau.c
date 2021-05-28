#define _CRT_SECURE_NO_WARNINGS
/*dernière modification 21/05/2021,LEBLANC Anthony,ROUSSEAU Alex*/


#include<stdio.h> /*printf*/
#include<stdlib.h>/*calloc*/
#include "reseau.h"



void printNEURONE(NEURONE neurone, int taille) //affiche tout un neurone
{

	printf("Biais : %lf Weight :", getBiais(&neurone));
	int i = 0;
	while (i < taille )
	{
		printf("|%lf", getWeight(&neurone, i));
		i++;
	}
	printf("|");
}

void printCouche(COUCHE couche)
{
	if (couche.neurone.head == NULL)
	{
		printf("\nListe vide\n");
		exit(1);
	}
	NEURONE* neurone = NULL;
	int i = 0;
	do
	{
		*neurone = getNeurone(&couche,i);
		printf("neurone %d \n", i);
		printNEURONE(*neurone, couche.nbrNeurone);
		i++;
	} while (neurone != couche.neurone.tail);
}

double getBiais(NEURONE* neurone) // obtient le biais d'un neurone 
{
	return neurone->biais;
}

double getWeight(NEURONE* neurone,int n)// obtient weight position n d'un neurone.
{
	return neurone->weight[n];
}

int* initialiseWeight( int nbrNeurone)// permet d'allouer dynamiquement le tableau de weight
{
	int* weight = NULL;
	weight = (unsigned int*)calloc(nbrNeurone, sizeof(unsigned int));
	if (weight == NULL)
	{
		free(weight);
		puts("Error (re)allocating memory");
		exit(1);
	}
	return weight;
}

int getNbrNeurone(COUCHE* couche) // obtient le nombre de neurone(taille des tableaux) dans une couche
{
	return couche->nbrNeurone;
}

NEURONE getNeurone(COUCHE* couche, int n) // obtenir le neurone position n dans la liste
{
	NEURONE *neurone;
	if (n == 0)
		return *couche->neurone.head;
	neurone = couche->neurone.head;
	for (int i = 0; i < n; i++)
	{
		neurone = neurone->next;
	}
	return *neurone;
}


void setBiais(NEURONE* neurone, double biais) // attribue le biais d'un neurone
{
	neurone->biais = biais;
}

void setWeight(NEURONE* neurone, double weight, int n)// attribue le weight de la position n
{
	neurone->weight[n] = weight; // je l'attibue pour un vaudrait-il mieux tout le tableau?
}

void setNbrNeurone(COUCHE* couche, int nbrNeurone)//atribue le nombre de Neurone
{
	couche->nbrNeurone = nbrNeurone;
}

void setNeurone(COUCHE* couche,NEURONE neurone) // attibue un neurone
{
	if (couche->neurone.head == NULL)
	{
		*couche->neurone.head = neurone;
		*couche->neurone.tail = neurone;
	}
	else
	{
		neurone.prev = couche->neurone.tail;
		neurone.next = NULL;
		*couche->neurone.tail->next = neurone;
	}
}
