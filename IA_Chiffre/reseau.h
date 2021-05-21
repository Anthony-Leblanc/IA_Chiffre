#pragma once
// dernière modification 21/05/2021 Anthony Leblanc, Alex ROUSSEAU

/*
Définition des structures des réseaux de neuronnes
1 : une structure couche contenant une liste de neurone, les pointeurs sur la couche précédente et la couche d'avant ainsi que des buffer d'entrée/sortie
2 : une structure neurone contenant weight (w), le biais b et deux pointeur un sur le neurone précédent et un sur le suivant 
3 : une structure list contenant un pointeur vers le neurone du début de liste et le neurone de fin de liste
*/


typedef struct _NEURONE
{
  unsigned int biais;
  unsigned int* weight;
  struct _NEURONE* next;
  struct _NEURONE* prev;
}NEURONE;

typedef struct _LIST
{
  NEURONE* head;
  NEURONE* tail;
}LIST;

typedef struct _COUCHE
{
  LIST neurone;
  int nbrNeurone;
  struct _COUCHE* next;
  struct _COUCHE* prev;
  double **in;
  double **out;

}COUCHE;


void printNEURONE(NEURONE neurone, int taille);
unsigned int getBiais(NEURONE* neurone);
unsigned int getWeight(NEURONE* neurone,int n);  
int * initialiseWeight(int nbrNeurone);
int getNbrNeurone(COUCHE* couche);
NEURONE getNeurone(COUCHE* couche, int n);
void setBiais(NEURONE* neurone, unsigned int biais);
void setWeight(NEURONE* neurone, unsigned int weight, int n);
void setNbrNeurone(COUCHE* couche, int nbrNeurone);
void setNeurone(COUCHE* couche, int n, NEURONE neurone);
void appendToList(LIST* liste, NEURONE neurone,int n); //en construction