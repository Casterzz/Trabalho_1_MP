/*
Copyright
Nome: Victor Eduardo Fernandes Castor
Matricula: 170115127
Data: 14/09/18
Projeto Pilha
*/

#include <stdlib.h>
#include <stdio.h>
#define type int

/*Struct ItemType pedida na documentação*/

typedef struct ItemType {
    type valor;
}itemtype;

/*Na struct "pilha" abaixo, o item "estado" serve como um auxiliar
das funções, caso caso estas estejam trabalhando com uma alocação estática*/

typedef struct Pilha {
    itemtype item;
    int estado;
    struct Pilha *prox;
}pilha;

/*Declaração de todas as funções a serem usadas*/

int push(int valor, pilha *primeiro, int size, int code);

int pop(pilha *primeiro, int code);

float top(pilha *primeiro, int size, int code);

pilha *CreateStack(int size, int code);

int StackSize(pilha *primeiro, int size, int code);

int IsFull(pilha *primeiro, int size, int code);

int IsEmpty(pilha *primeiro, int size, int code);

int SetSize(pilha *primeiro, int NewSize, int *OldSize);

int DestroyStack(pilha *primeiro);
