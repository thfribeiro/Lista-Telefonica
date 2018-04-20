#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaTelefonica.h"

void inicializaLista (LISTA *l)
{
    //Inicializa a lista setando como 0 seu n�mero de elementos
  l->nroElem = 0;
}


void exibirLista(LISTA *l)
{
    int i;
    printf("Lista: \n");
    //Percorre a lista passando por todas as posi��es dispon�veis
    for(i=0;i < l->nroElem; i++)
    {
        printf("\n [Posicao: %d - Nome: %s - Endereco: %s - Telefone: %.0lf]",i,l->A[i].nome,l->A[i].ende, l->A[i].tel);
        printf("\n");
    }
}

void insereElemListaNome(LISTA *l, REGISTRO elem)
{
    int j;
    //Verifica se a lista n�o est� cheia
    if(l -> nroElem >= MAX)
    {
        printf("Error a lista esta cheia");
        return;
    }
    /*Faz a compara��o para ver a posi��o que o elemento a ser inserido ocupar� de maneira ordenada
    alterando a posi��o dos demais elementos se necess�rio*/
    for(j = l->nroElem; j>0&&strcmp(elem.nome,l->A[j-1].nome)<0; j--){

            l->A[j]=l->A[j-1];
    }
 //Insere o novo elemento na lista e acrescenta um no contador de elementos
    l->A[j] = elem;
    l->nroElem = l->nroElem+1;
}


int buscaElemListaNome(LISTA *l, char nomeBusca[]){
    int j;
    //Verifica se a lista n�o est� vazia
    if(l -> nroElem == 0)
    {
        printf("\nA lista ta vazia\n");
        return -1;
    }
    /*Faz a compara��o dos elementos da lista com o elemento buscado retornando a posi��o em que ele se encontra
    caso esteja na lista. Se n�o for encontrado retorna -1 */
    for(j=0; j<l->nroElem&&(strcmp(nomeBusca,l->A[j].nome)!=0); j++);

    if(j<l->nroElem &&((strcmp(nomeBusca,l->A[j].nome))==0)) return j;
    else return -1;

}


int buscaBinaria(LISTA *l, char nomeBusca[], int i, int f){

int meio;
//Primeiramente separa a metade da lista para realizar a compara��o
meio = (int) ((i + f)/2);

/*Ap�s isso entra em um loop de comapara��es buscando localizar o elemento buscado.
O algoritmo pega o elemento do meio da lista e compara se est� antes ou depois do elemento buscado em ordem alfab�tica
caso o elemento buscado esteja antes da metade, ent�o setado um novo "meio" vindo da divis�o entre o inicio da lista e o "meio"
anterior. Caso o elemento buscado esteja depois da metade ent�o tamb�m � setado um novo "meio" vindo da divis�o entre o "meio"
anterior e o final da lista. Ap�s isso independente do caso entram novamente no loop at� que seja encontrado o elemento buscado
e ent�o retorna a posi��o do mesmo para a fun��o principal. Caso o elemento n�o seja encontrado retorna o valor -1*/
while(i <= f && (strcmp(l->A[meio].nome,nomeBusca)!=0)){

    if(strcmp(l->A[meio].nome,nomeBusca)>0)
        f=meio-1;
    else
        i = meio+1;

    meio = (int) ((i+f)/2);
}

if(meio >= 0 && strcmp(l->A[meio].nome,nomeBusca)==0)
    return (meio);
    return (-1);

}

void exclusao(LISTA *l, char nomeExclusao[]){

  int pos=0,i;
  //Utiliza o m�todo de busca bin�ria apresentado anteriormente para localizar o elemento.
if((pos = buscaBinaria(l, nomeExclusao, 0, l->nroElem-1))== -1){
    //Se o elemento n�o for encontrado retorna uma mensagem e volta para a fun��o principal
    printf("Nao foi possivel excluir, pois o elemento nao esta na lista\n");
    return;
}
//Caso o elemento for encontrado o mesmo e substituido pelo elemento presente na pr�xima posi��o, restando lixo de mem�ria.
for(i = pos; i <= l->nroElem; i++){
    strcpy(l->A[i].ende, l->A[i+1].ende);
    strcpy(l->A[i].nome, l->A[i+1].nome);
    l->A[i].tel = l->A[i+1].tel;
}
    l->nroElem = l->nroElem -1;
    printf("\nO elemento %s e todos os seus dados foram excluidos\n", nomeExclusao);
}

void reinicializar(LISTA *l){
//Seta o numero de elementos da lista para 0 reiniciando a mesma
l->nroElem = 0;
}
