#pragma once
// 07/05/2021 Anthony Leblanc, Alex ROUSSEAU

/*
D�finition des structures des r�seaux de neuronnes
1 : une structure couches contenant une liste de neuronne et une structure 
2 : une structure neurone contenant weight (w) et le biais b
3 : une structure list contenant un pointeur vers un pointeur d'entr�e et un pointeur vers un buffer de sortie
*/

// #define N 784 pas sur � changer peut �tre 

typedef struct _LIST
{
  NEURONE* head;
  NEURONE* tail;
}LIST;

typedef struct _COUCHE
{
  LIST nerone;
  struct _COUCHE* next;
  struct _COUCHE* prev;
}COUCHE;

typedef struct _NEURONE
{
  unsigned int biais; 
  unsigned int *weight; 
}NEURONE;