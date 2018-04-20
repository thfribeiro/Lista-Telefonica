#ifndef LISTATELEFONICA_H_INCLUDED
#define LISTATELEFONICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//Indica que TIPOCHAVE será uma maneira de declara uma variável do tipo double
typedef double TIPOCHAVE;

// Define que REGISTRO será uma struct contendo as variáveis as seguintes variáveis:
typedef struct
{
    TIPOCHAVE tel;
    char nome[MAX];
    char ende[80];

}REGISTRO;

//Define que Lista será uma struct contendo a struct REGISTRO e também um contador de elementos
typedef struct
{
  REGISTRO A[MAX];
  int nroElem;

}LISTA;
//-----------------------------------------------------------------


//PROTÓTIPOS

void inicializaLista (LISTA *l);

void exibirLista(LISTA *l);

void insereElemListaNome(LISTA *l, REGISTRO elem);

int buscaElemListaNome(LISTA *l, char nomeBusca[]);

int buscaBinaria(LISTA *l, char nomeBusca[], int i, int f);

void exclusao(LISTA *l, char nomeExclusao[]);

void reinicializar(LISTA *l);
#endif // LISTATELEFONICA_H_INCLUDED
