#define _CRT_SECURE_NO_WARNINGS
/*dernière modification 21/05/2021,LEBLANC Anthony,ROUSSEAU Alex*/


#include<stdio.h> /*printf*/
#include<stdlib.h>/*calloc*/
#include "reseau.h"



void printNEURONE(NEURONE neurone, int taille) //affiche tout un neurone
{

	printf("Biais : %d Weight :", getBiais(&neurone));
	int i = 0;
	while (i < taille )
	{
		printf("|%d", getWeight(&neurone, i));
		i++;
	}
	printf("|");
}


unsigned int getBiais(NEURONE* neurone) // obtient le biais d'un neurone 
{
	return neurone->biais;
}

unsigned int getWeight(NEURONE* neurone,int n)// obtient weight position n d'un neurone.
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

int getNbrNeurone(COUCHE* couche) // obtient le nombre de neurone dans une couche
{
	return couche->nbrNeurone;
}

NEURONE getNeurone(COUCHE* couche,int n) // à corriger
{
	/*NEURONE neurone;
	neurone.biais = couche->neurone.head->next[n].biais;
	for (int i = 0; i < couche->nbrNeurone; i++)
	{
		neurone.weight[i] = couche->neurone.head->next[n].weight[i];
	}
	return neurone;*/
}


void setBiais(NEURONE* neurone, unsigned int biais) // attribue le biais d'un neurone
{
	neurone->biais = biais;
}

void setWeight(NEURONE* neurone, unsigned int weight, int n)// attribue le weight de la position n
{
	neurone->weight[n] = weight; // je l'attibue pour un vaudrait-il mieux tout le tableau?
}

void setNbrNeurone(COUCHE* couche, int nbrNeurone)//atribue le nombre de Neurone
{
	couche->nbrNeurone = nbrNeurone;
}

void setNeurone(COUCHE* couche, int n, NEURONE neurone) // à corriger
{
	/*couche->neurone.head->next[n].biais = neurone.biais ;
	for (int i = 0; i < couche->nbrNeurone; i++)
		couche->neurone.head->next[n].weight[i] = neurone.weight[i];*/
}

void appendToList(LIST* liste, NEURONE neurone,int n)
{
	COUCHE* couche = calloc(1, sizeof(COUCHE));  // affiche un warning de si pointeur null
	setNeurone(&couche, n, neurone);

	if (liste->tail != 0) // si déjà dans la liste 
	{
		liste->tail->next = couche;
		couche->prev = liste->tail;
		liste->tail = couche;
	}
	else //sinon on ajoute en tant que début et fin de chaine
	{
		liste->tail = couche;
		liste->head = couche;
	}
}