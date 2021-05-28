#pragma once
#ifndef _reseau_h_ // Si la constante n'a pas �t� d�finie le fichier n'a jamais �t� inclus
#define _reseau_h_ // On d�finit la constante pour que la prochaine fois le fichier ne soit plus inclus
// derni�re modification 28/05/2021 Anthony Leblanc, Alex ROUSSEAU

/*
D�finition des structures des r�seaux de neuronnes
1 : une structure couche contenant une liste de neurone, les pointeurs sur la couche pr�c�dente et la couche d'avant ainsi que des buffer d'entr�e/sortie
2 : une structure neurone contenant weight (w), le biais b et deux pointeur un sur le neurone pr�c�dent et un sur le suivant 
3 : une structure list contenant un pointeur vers le neurone du d�but de liste et le neurone de fin de liste
*/


typedef struct _NEURONE
{
  double biais;
  double* weight;
  struct _NEURONE* next;
  struct _NEURONE* prev;
}NEURONE;

typedef struct _LIST_NEURONE 
{
  NEURONE* head;
  NEURONE* tail;
}LIST_NEURONE;

typedef struct _COUCHE
{
  LIST_NEURONE neurone;
  int tailleTabw;
  struct _COUCHE* next;
  struct _COUCHE* prev;
  double **in;
  double **out;

}COUCHE;

typedef struct _LIST_LAYER
{
  COUCHE* head;
  COUCHE* tail;
}LIST_LAYER;

typedef struct _NETWORK
{
  LIST_LAYER list_layer;
}NETWORK;

//void load_neuralNetwork(FILE* stream, NETWORK* network);

void printNEURONE(NEURONE neurone, int taille);
void printCouche(COUCHE couche);
double getBiais(NEURONE* neurone);
double getWeight(NEURONE* neurone,int n);
double * initialiseWeight(int tailleTabw);
int getTailleTabw(COUCHE* couche);
NEURONE* getNeurone(COUCHE* couche, int n);
void setBiais(NEURONE* neurone, double biais);
void setWeight(NEURONE* neurone, double weight, int n);
void setTailleTabw(COUCHE* couche, int nbrNeurone);
void setNeurone(COUCHE* couche,NEURONE* neurone);

void save_neuralNetwork(NETWORK* network);

#endif