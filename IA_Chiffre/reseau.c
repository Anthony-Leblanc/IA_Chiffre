#define _CRT_SECURE_NO_WARNINGS
/*dernière modification 16/06/2021,LEBLANC Anthony,ROUSSEAU Alex*/


#include<stdio.h> /*printf,fopen*/
#include<stdlib.h>/*calloc*/
#include <string.h> /*strtok*/
#include "reseau.h"
#include "csv_image.h"



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
	if (couche.neurone.tail == NULL)
	{
		printf("\nListe vide\n"); // liste vide on indique une liste vide puis on sort de la fonction 
		exit(1);
	}
	NEURONE *neurone = NULL; // sinon on crée un pointeur null
	int i = 0;
	while(1)
	{
		neurone = getNeurone(&couche, i);
		if (neurone == NULL)
			break;
		printf("\nneurone %d \n", i);
		printNEURONE(*neurone, couche.tailleTabw);// je l'affiche
		i++;
	}
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

void setNeurone(COUCHE* couche,NEURONE *neurone) // attibue un neurone => set neurone et append to list en même temps 
{
  NEURONE *neuronebis = calloc(1,sizeof(NEURONE));
  *neuronebis = *neurone;
	if (couche->neurone.tail == NULL)
	{
		couche->neurone.head = neuronebis;
		couche->neurone.tail = neuronebis;
		neuronebis->prev = NULL;
		neuronebis->next = NULL;
	}
	else
	{
		couche->neurone.tail->next = neuronebis;
		neuronebis->prev = couche->neurone.tail;
		couche->neurone.tail = neuronebis;
		neuronebis->next = NULL;
	}
}

void appendToNetwork(NETWORK* network, COUCHE *layer)
{
  COUCHE* couche = calloc(1, sizeof(COUCHE));
  *couche = *layer;
  if (network->list_layer.tail == NULL) // Cas de la liste vide
  {
    network->list_layer.head = couche;
    network->list_layer.tail = couche;
  }
  else // S'il existe déjà un élément dans la liste
  {
    network->list_layer.tail->next = couche;
    couche->prev = network->list_layer.tail;
    couche->next = NULL;
    network->list_layer.tail = couche;
  }
}

void save_neuralNetwork(NETWORK* network,char* fileName)
{
	FILE* file = fopen(fileName, "w");// on crée un fichier csv ou suavegarder les couches 
	if (file == NULL)
	{
		printf("\nError could not open %s\n", fileName );// si le fichier n'est pas on quitte 
		exit(1);
	}
	int nbrCouche=0;
	COUCHE* couche = NULL;
	couche = network->list_layer.head;
	couche->neurone.head = network->list_layer.head->neurone.head;
	while (couche->next != network->list_layer.tail)// on calcul le nbr de couche 
	{
		couche = couche->next;
		nbrCouche++;
	}
	
	nbrCouche++;
	couche = network->list_layer.head; // on commence du début
	printf("\nnbr couche =%d", nbrCouche+1);
	for (int j = 0; j <= nbrCouche; j++) // tant que l'on a pas fait toutes les couches
	{
		if(j ==0)// pour la premiere couche
		{ 
			int taillew = 0;
			taillew = getTailleTabw(network->list_layer.head); // je récupère la taille des tableaux de weight
			int NbrNerone = 0;
			NEURONE* neurone = NULL; //  on crée un pointeur null
			neurone = getNeurone(network->list_layer.head, NbrNerone); 
			while (neurone->next != network->list_layer.head->neurone.tail)
			{
				neurone = getNeurone(network->list_layer.head, NbrNerone); // je récupère le neurone i
				NbrNerone++; // je compte le neurone i
			}
			NbrNerone++; // car on compte pas le dernier neurone
			fprintf(file, "%d ; %d\n", taillew, NbrNerone); // Première ligne qui renvoie la taille du tableau weight et le nombre de neurone
			for (int i = 0; i < NbrNerone; i++)// ici renvoie sur le fichier en premier le biais puis tous les weights
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
			couche = couche->next;// on va à la prochaine couche
			taillew = getTailleTabw(couche);
			int NbrNerone = 0;
			NEURONE* neurone = NULL; // on crée un pointeur null
			neurone = getNeurone(couche, NbrNerone);
			while (neurone->next != couche->neurone.tail)
			{
				neurone = getNeurone(couche, NbrNerone); // je récupère le neurone i
				NbrNerone++; // je compte le neurone i
			}
			NbrNerone++; // car on compte pas le dernier neurone
			fprintf(file, "%d ; %d\n", taillew, NbrNerone); // Première ligne qui renvoie la taille du tableau weight et le nombre de neurone
			for (int i = 0; i < NbrNerone; i++)// ici renvoie sur le fichier en premier le biais puis tous les weights
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


NETWORK* load_neuralNetwork(FILE* stream)
{
	NETWORK* network = (NETWORK*)calloc(1, sizeof(NETWORK));
	char* str = NULL;
	//LIST_LAYER list_layer = { NULL };

	str = getLine(stream);

	if (str == NULL)
	{
		puts("The neural network file is empty");
		return network;
	}

	while (str != NULL && str[0] != '\0' && str != "") // On parcourt l'ensemble du fichier
	{
		COUCHE couche = { NULL };
		int nbrWeight = 0, nbrNeurone = 0;
		double value = 0.0;
		char* pch = NULL;
		// Étape 1 : reconnaître une COUCHE :
		pch = strtok(str, ";"); nbrWeight = atoi(pch); // Le premier élément est le nombre de poids des neurones de la couche
		pch = strtok(NULL, ";"); nbrNeurone = atoi(pch); // Le deuxième élément est le nombre de neurone de la couche
    setTailleTabw(&couche, nbrWeight); // Initialisation du champ du nombre de poids dans des neuronnes de la couche

		// Étape 2 : initialiser les neurones de la couche (et les y ajouter)
		for (int i = 0; i < nbrNeurone; i++) // Parcours des neurones
		{
			NEURONE neurone = { 0.0, };
			neurone.weight = initialiseWeight(nbrWeight); // On alloue la mémoire nécessaire au poids des neurones de la couche
			str = getLine(stream); // On récupère les infos du neurone
			pch = strtok(str, ";"); value = strtod(pch, NULL);
			setBiais(&neurone, value); // On écrit la valeur du biais du neuronne

			for (int j = 0; j < nbrWeight; j++) // Il faut maintenant enregistrer les poids du neurone
			{
				pch = strtok(NULL, ";"); value = strtod(pch, NULL);
				setWeight(&neurone, value, j); // On enregistre le poids "j"
			}
			setNeurone(&couche, &neurone);  
		}

		// Étape 3 : on ajoute la couche à la liste de couche
    appendToNetwork(network, &couche);
		str = getLine(stream); // On prend un nouvelle ligne, permet aussi de vérifier la condition du while
	}

	// Étape 4 : ajout de la liste de couche dans le réseau de neurones
	//network->list_layer = list_layer;
	return network;
}

// Fin d'ajout
//****************************************************************************************************