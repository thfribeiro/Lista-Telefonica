#ifndef LISTATELEFONICA_H_INCLUDED
#define LISTATELEFONICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//Indica que TIPOCHAVE ser� uma maneira de declara uma vari�vel do tipo double
typedef double TIPOCHAVE;

// Define que REGISTRO ser� uma struct contendo as vari�veis as seguintes vari�veis:
typedef struct
{
    TIPOCHAVE tel;
    char nome[MAX];
    char ende[80];

}REGISTRO;

//Define que Lista ser� uma struct contendo a struct REGISTRO e tamb�m um contador de elementos
typedef struct
{
  REGISTRO A[MAX];
  int nroElem;

}LISTA;
//-----------------------------------------------------------------


//PROT�TIPOS

void inicializaLista (LISTA *l);

void exibirLista(LISTA *l);

void insereElemListaNome(LISTA *l, REGISTRO elem);

int buscaElemListaNome(LISTA *l, char nomeBusca[]);

int buscaBinaria(LISTA *l, char nomeBusca[], int i, int f);

void exclusao(LISTA *l, char nomeExclusao[]);

void reinicializar(LISTA *l);
#endif // LISTATELEFONICA_H_INCLUDED
