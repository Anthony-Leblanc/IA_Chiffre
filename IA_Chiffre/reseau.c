#define _CRT_SECURE_NO_WARNINGS
/*dernière modification 28/05/2021,LEBLANC Anthony,ROUSSEAU Alex*/


#include<stdio.h> /*printf,fopen*/
#include<stdlib.h>/*calloc*/
#include "reseau.h"



void printNEURONE(NEURONE neurone, int taille) //affiche tout un neurone (la taille est nécessaire pour le tableau de weight alloué dynamiquement)
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
		printf("\nListe vide\n"); // liste vide on indique une liste vide puis on sort de la fonction 
		exit(1);
	}
	NEURONE *neurone = NULL; // sinon on crée un pointeur null
	int i = 0;
	do
	{
		neurone = getNeurone(&couche,i); // je récupère le neurone numéro i
		printf("\nneurone %d \n", i);
		printNEURONE(*neurone, couche.tailleTabw);// je l'affiche
		i++;
	} while (neurone->next != couche.neurone.tail);
	neurone = getNeurone(&couche, i);//on est à la fin j'affiche le dernier neurone
	printf("\nneurone %d \n", i);
	printNEURONE(*neurone, couche.tailleTabw);
}

double getBiais(NEURONE* neurone) // obtient le biais d'un neurone 
{
	return neurone->biais;
}

double getWeight(NEURONE* neurone,int n)// obtient weight position n d'un neurone.
{
	return neurone->weight[n];
}

double* initialiseWeight( int tailleTabw)// permet d'allouer dynamiquement le tableau de weight
{
	double* weight = NULL;
	weight = (double*)calloc(tailleTabw, sizeof(double));
	if (weight == NULL)
	{
		free(weight);
		puts("Error (re)allocating memory");
		exit(1);
	}
	return weight;
}

int getTailleTabw(COUCHE* couche) // obtient le nombre de neurone(taille des tableaux) dans une couche
{
	return couche->tailleTabw;
}

NEURONE* getNeurone(COUCHE* couche, int n) // obtenir le neurone position n dans la liste
{
	NEURONE *neurone;
	if (n == 0)
		return couche->neurone.head;
	neurone = couche->neurone.head;
	for (int i = 0; i < n; i++)
	{
		neurone = neurone->next;
	}
	return neurone;
}


void setBiais(NEURONE* neurone, double biais) // attribue le biais d'un neurone
{
	neurone->biais = biais;
}

void setWeight(NEURONE* neurone, double weight, int n)// attribue le weight de la position n
{
	neurone->weight[n] = weight; 
}

void setTailleTabw(COUCHE* couche, int tailleTabw)//atribue la taille des tableau de weight
{
	couche->tailleTabw = tailleTabw;
}

void setNeurone(COUCHE* couche,NEURONE* neurone) // attibue un neurone => set neurone et append to list en même temps 
{
	if (couche->neurone.tail == NULL)
	{
		couche->neurone.head = neurone;
		couche->neurone.tail = neurone;
		neurone->prev = NULL;
		neurone->next = NULL;
	}
	else
	{
		couche->neurone.tail->next = neurone;
		neurone->prev = couche->neurone.tail;
		couche->neurone.tail = neurone;
	}
}



void save_neuralNetwork(NETWORK* network)
{
	char name[] = "neuralNetwork2.csv";
	FILE* file = fopen(name, "w");
	if (file == NULL)
	{
		printf("Error could not open %s\n", name);
		exit(1);
	}
	int nbrCouche=0;
	COUCHE* couche = NULL;
	couche = network->list_layer.head;
	couche->neurone.head = network->list_layer.head->neurone.head;
	while (couche->next != network->list_layer.tail)
	{
		couche = couche->next;
		nbrCouche++;
	}
	
	nbrCouche++;
	couche = network->list_layer.head;
	printf("\nnbr couche =%d", nbrCouche+1);
	for (int j = 0; j <= nbrCouche; j++)
	{
		if(j ==0)
		{ 
			int taillew = 0;
			taillew = getTailleTabw(network->list_layer.head); // je récupère la taille des tableaux de weight
			int NbrNerone = 0;
			NEURONE* neurone = NULL; // sinon on crée un pointeur null
			neurone = getNeurone(network->list_layer.head, NbrNerone); // je travail pour une couche pour l'instant à changer quand plus
			while (neurone->next != network->list_layer.head->neurone.tail)
			{
				neurone = getNeurone(network->list_layer.head, NbrNerone); // je récupère le neurone i
				NbrNerone++; // je compte le neurone i
			}
			NbrNerone++; // car on compte pas le dernier neurone
			fprintf(file, "%d ; %d\n", taillew, NbrNerone); // Première ligne qui renvoie la taille du tableau weight et le nombre de neurone
			for (int i = 0; i < NbrNerone; i++)
			{
				neurone = getNeurone(network->list_layer.head, i);
				fprintf(file, "%lf ;", getBiais(neurone));
				for (int k = 0; k < network->list_layer.head->tailleTabw; k++)
				{
					fprintf(file, "%lf ;", getWeight(neurone, k));
				}
				fprintf(file, "\n");
			}
		}
		else
		{
			int taillew = 0;
			couche = couche->next;
			taillew = getTailleTabw(couche);
			int NbrNerone = 0;
			NEURONE* neurone = NULL; // sinon on crée un pointeur null
			neurone = getNeurone(couche, NbrNerone);
			while (neurone->next != couche->neurone.tail)
			{
				neurone = getNeurone(couche, NbrNerone); // je récupère le neurone i
				NbrNerone++; // je compte le neurone i
			}
			NbrNerone++; // car on compte pas le dernier neurone
			fprintf(file, "%d ; %d\n", taillew, NbrNerone); // Première ligne qui renvoie la taille du tableau weight et le nombre de neurone
			for (int i = 0; i < NbrNerone; i++)
			{
				neurone = getNeurone(couche, i);
				fprintf(file, "%lf ;", getBiais(neurone));
				for (int k = 0; k < couche->tailleTabw; k++)
				{
					fprintf(file, "%lf ;", getWeight(neurone, k));
				}
				fprintf(file, "\n");
			}
		}
	}
	fclose(file);
}