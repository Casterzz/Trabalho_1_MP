/*
Copyright
Nome: Victor Eduardo Fernandes Castor
Matricula: 170115127
Data: 14/09/18
Projeto Pilha
*/

#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

/*Todas as funções que contém o inteiro code como paramêtro 
é porque são funções que mudam seu funcionamento de acordo
com o tipo de pilha, algumas funções tais como "SetSize" não possui
esse parâmetro, já que uma pilha estática não requer essa função.
O mesmo ocorre com a função "DestroyStack", já que a alocação de uma pilha
estática é feita com vetor, essa pilha se auto-destroi no final da execução
do programa.*/

int push(int valor, pilha *primeiro, int size, int code) {
    pilha *aux = primeiro;
    int cont = 0;

    if (code) {
        while (aux->prox != NULL) {
            aux = aux->prox;
            cont++;
        }
        if (cont >= size)
            return -1;
        aux->prox = (pilha*)malloc(sizeof(pilha));
        aux = aux->prox;
        aux->prox = NULL;
        aux->item.valor = valor;
    } else {
        while (aux->estado) {
            aux++;
            cont++;
        }
        if (cont >= size)
            return -1;
        aux->item.valor = valor;
        aux->estado = 1;
    }

    return 0;
}

/*Ambos os whiles, servem para achar o próximo elemento não preenchido no 
vetor ou lista. Após encontrado a posição, aloca o novo elemento*/

int pop(pilha *primeiro, int code) {
    if (code) {
        pilha *sentinela = primeiro;
        pilha *aux = primeiro->prox;
        if (aux == NULL)
            return -1;

        while (aux->prox != NULL) {
            aux = aux->prox;
            sentinela = sentinela->prox;
        }

        free(aux);
        sentinela->prox = NULL;
    } else {
        pilha *aux = primeiro;
        if (aux->estado == 0) {
            return -1;
        }
        while (aux->estado) {
        aux++;
        }
        aux--;
        aux->estado = 0;
    }

    return 0;
}

/*Ambos os whiles são executados até o ultimo servem para achar o ultimo elemento 
do conjunto e assim eliminá-los*/

float top(pilha *primeiro, int size, int code) {
    pilha *aux = primeiro;

    if (code) {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        return aux->item.valor;
    } else {
        if (aux->estado == 0) {
            return -1;
        }
        int tam = StackSize(primeiro, size, code);

        for (int i = 0; i < tam-1; i++) {
            aux++;
        }

        return aux->item.valor;
    }
}

/*É procurado o último elemento, retornando seu valor*/

pilha *CreateStack(int size, int code) {
    if (code) {
        pilha *primeiro = (pilha*)malloc(sizeof(pilha));
        primeiro->prox = NULL;
        primeiro->item.valor = -1;

        return primeiro;
    } else {
        pilha PILHA[size];

        for (int i = 0; i < size; i++) {
            PILHA[i].estado = 0;
        }

        pilha *primeiro = &PILHA[0];

        return primeiro;
    }
}

/*Retorna um ponteiro apontando para para um novo espaço alocado com malloc caso 
seja uma pilha dinâmica ou retorna um ponteiro apontando para a posição 0 
do array, caso seja estático*/

int StackSize(pilha *primeiro, int size, int code) {
    int cont = 0;

    pilha *aux = primeiro;

    if (code) {
        while (aux->prox != NULL) {
            aux = aux->prox;
            cont++;
        }
    } else {
        while (aux->estado) {
            if (cont < size) {
                aux++;
                cont++;
            } else {
                break;
            }
        }
    }

    return cont;
}

/*Os whiles são executados até o ultimo elemento, ao mesmo passo que 
o cont é incrementado, retornando a quantidade de elementos*/

int IsFull(pilha *primeiro, int size, int code) {
    int atual = StackSize(primeiro, size, code);

    if (atual == size)
        return 1;
    else
        return 0;
}

/*Verifica se o tamanho da pilha atual é o mesmo que máximo, se for retorna 
1 como verdadeiro, caso contrário 0 (falso)*/

int IsEmpty(pilha *primeiro, int size, int code) {
    int atual = StackSize(primeiro, size, code);

    if (atual == 0)
        return 1;
    else
        return 0;
}

/*Verifica se o tamanho da pilha atual é 0, se for retorna 1 como verdadeiro, 
caso contrário 0 (falso)*/

int SetSize(pilha *primeiro, int NewSize, int *OldSize) {
    if (IsFull(primeiro, *OldSize, 1)) {
        if (NewSize < *OldSize) {
            pilha *aux = primeiro;
            for (int i=0; i < NewSize; i++) {
                aux = aux->prox;
            }
            int validez = DestroyStack(aux->prox);
            aux->prox = NULL;

            if (validez == 0)
                return 0;
            else
                return -1;
        }
    }
    *OldSize = NewSize;

    return 0;
}

/*Só se aplica a pilha dinâmica. Se a quantidade de elementos na pilha for maior 
que o espaço redefinido, a parte da pilha excedente é destruida,
caso contrário apenas redefine o tamanho.*/

int DestroyStack(pilha *primeiro) {
    pilha *aux = primeiro->prox;
    pilha *sentinela = primeiro;

    while (primeiro->prox != NULL) {
        aux = primeiro->prox;
        sentinela = primeiro;

        while (aux->prox != NULL) {
            aux = aux->prox;
            sentinela = sentinela->prox;
        }
        free(aux);
        sentinela->prox = NULL;
    }
    free(primeiro);
    primeiro = NULL;

    if (primeiro == NULL)
        return 0;
    else
        return -1;
}

/*Só se aplica a pilha dinâmica. Ela basicamente começa a destruir os elementos a partir 
do topo até chegar na cabeça e destrui-la. O primeiro while é executado até sobrar 
apenas a célula cabeça, o segundo funciona até o último depois da cabeça.*/

