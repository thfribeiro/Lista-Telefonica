#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaTelefonica.h"


// Nome: Thiago Fernandes Ribeiro

//RA: 120160

//Trabalho Implementação lista sequencial estática (LISTA TELEFÔNICA)

//Realizado com o auxilio do docente Willian Molina Ibanez - RA:120175


int main()
{
    LISTA lista;
    REGISTRO elem;
    char nomeBusca[50]="Jose Geraldo Ribeiro";
    char nomeExclusao[50]="Joseph";
    int opt=0;

    //Inicializa a lista:
    inicializaLista(&lista);

    //Adiciona os elementos na lista:
    elem = (const REGISTRO){43996069321, "Thiago", "Comendador Luiz Meneghel"};
        insereElemListaNome(&lista,elem);

    elem = (const REGISTRO){43999816811, "Jose Geraldo Ribeiro", "Av. dos Pinheiros"};
        insereElemListaNome(&lista,elem);

    elem = (const REGISTRO){43999119584, "Luciene Fernandes Ribeiro", "Av. dos Pinheiros"};
        insereElemListaNome(&lista,elem);

    elem = (const REGISTRO){43999006539, "Ana Paula da Silva Barbosa", "Av. das Palmeiras"};
        insereElemListaNome(&lista,elem);

    elem = (const REGISTRO){43999356773, "Willian", "Rua dos Canteiros"};
        insereElemListaNome(&lista,elem);

    elem = (const REGISTRO){43999043242, "Joseph", "Rua das Flores"};
        insereElemListaNome(&lista,elem);

    elem = (const REGISTRO){43999006539, "Rodrigo", "Rua das Flores"};
        insereElemListaNome(&lista,elem);
    //Exibe a lista com os elementos cadastrados anteriormente:
    exibirLista(&lista);

    //Um menu para opção de busca na lista
    puts("\n--------------------------------------------------------------\n");
    puts("\nEscolha a busca que deseja fazer:\n 1 - Sequencial \t 2 - Binaria");
    scanf("%i", &opt);

    if(opt!=1&&opt!=2){
        puts("Por gentileza escolha uma opcao valida");
        return 0;
    }
    //Realiza a busca sequencial:
if(opt==1){
    puts("\nBusca por nome:\n");

    if ((buscaElemListaNome(&lista, nomeBusca))!= -1){

    printf("Posicao: %d - Nome: %s - Endereco: %s - Telefone: %.0lf]\n",buscaElemListaNome(&lista, nomeBusca),lista.A[buscaElemListaNome(&lista, nomeBusca)].nome, lista.A[buscaElemListaNome(&lista, nomeBusca)].ende, lista.A[buscaElemListaNome(&lista, nomeBusca)].tel);
    }
    else printf("\n[O nome nao esta na lista]\n");
}

    //Realiza a busca binária:
else if(opt==2){

    puts("\nBusca por nome (binaria):\n");

if(buscaBinaria(&lista,nomeBusca,0,lista.nroElem) == -1)
    printf("Elemento %s nao esta na lista",nomeBusca);
else
    printf("Posicao: %d - Nome: %s - Endereco: %s - Telefone: %.0lf]\n",buscaBinaria(&lista, nomeBusca,0,lista.nroElem),lista.A[buscaBinaria(&lista, nomeBusca,0,lista.nroElem)].nome, lista.A[buscaBinaria(&lista, nomeBusca,0,lista.nroElem)].ende, lista.A[buscaBinaria(&lista, nomeBusca,0,lista.nroElem)].tel);

}
puts("\n--------------------------------------------------------------\n");
//Exclui um elemento cadastrado na lista:
puts("Exclusao de elementos\n");
exclusao(&lista, nomeExclusao);
puts("\n--------------------------------------------------------------\n");
//Reexibe a lista:
puts("Reexibicao da lista\n");
exibirLista(&lista);

strcpy(nomeExclusao, "Rodrigo");
puts("\n--------------------------------------------------------------\n");
//Exclui um elemento cadastrado na lista:
puts("Exclusao de elementos\n");
exclusao(&lista, nomeExclusao);
puts("\n--------------------------------------------------------------\n");
//Reexibe a lista:
puts("Reexibicao da lista\n");
exibirLista(&lista);

strcpy(nomeExclusao, "Thiago");
puts("\n--------------------------------------------------------------\n");
//Exclui um elemento cadastrado na lista:
puts("Exclusao de elementos\n");
exclusao(&lista, nomeExclusao);
puts("\n--------------------------------------------------------------\n");
//Reexibe a lista:
puts("Reexibicao da lista\n");
exibirLista(&lista);
//Reinicializa a lista
reinicializar(&lista);
return 0;
}
