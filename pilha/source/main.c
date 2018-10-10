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

int main() {
    int codigo, codigoPilha = -1, size, NewSize, valor;
    pilha *primeiro = NULL;

    do {
        if (codigoPilha == -1) {
            printf("Selecione o tipo de pilha a ser criado, ou 2 para sair:");
            printf("\n\n0. Estatica\n1. Dinamica\n2. Sair\n");
            scanf("%d", &codigoPilha);
            if (codigoPilha == 1 || codigoPilha == 0) {
                printf("Entre com o tamanho da pilha: \n");
                scanf("%d", &size);
                if (size < 0) {
                    codigoPilha = -1;
                    printf("\nEntre com um valor > 0\n\n");
                } else {
                    primeiro = CreateStack(codigoPilha, size);
                }
            } else {
                if (codigoPilha == 2) {
                    return 0;
                } else {
                    printf("Codigo Invalido!\n");
                    codigoPilha = -1;
                }
            }
        }

        if (codigoPilha != -1) {
            printf("\nEntre com um dos codigos abaixo:");
            printf("\n\n1. Push\n2. Pop\n3. Top\n4. IsFull?\n");
            printf("5. IsEmpty?\n6. SetSize\n7. DestroyStack\n8. Sair\n");
            scanf("%d", &codigo);
            switch (codigo) {
                case 1:
                    printf("\nEntre com o valor a ser colocado:\n");
                    scanf("%d", &valor);
                    putchar('\n');
                    push(valor, primeiro, size, codigoPilha);
                    break;
                case 2:
                    if (StackSize(primeiro, size, codigoPilha) != 0)
                        pop(primeiro, codigoPilha);
                    else
                        printf("\nNao ha elementos a serem retirados!\n");
                    break;
                case 3:
                    if (StackSize(primeiro, size, codigoPilha) != 0) {
                        valor = top(primeiro, size, codigoPilha);
                        printf("\nO valor atual da pilha eh: %d\n", valor);
                    } else {
                        printf("\nNao ha valor na pilha!\n");
                    }
                    break;
                case 4:
                    valor = IsFull(primeiro, size, codigoPilha);
                    if (valor)
                        printf("Sim (%d)\n", valor);
                    else
                        printf("Nao (%d)\n", valor);
                    break;
                case 5:
                    valor = IsEmpty(primeiro, size, codigoPilha);
                    if (valor)
                        printf("Sim (%d)\n", valor);
                    else
                        printf("Nao (%d)\n", valor);
                    break;
                case 6:
                    if (codigoPilha == 0) {
                        printf("\nA pilha que esta sendo usada eh estatica ");
                        printf("e por isso nao pode ter seu tamanho ");
                        printf("redimensionado!\n");
                    } else {
                        printf("Entre com o novo valor da pilha:\n");
                        scanf("%d", &NewSize);
                        if (NewSize <= 0) {
                            printf("\nFalha na operacao!");
                            printf(" Valor tem que ser > 0\n");
                        } else {
                            SetSize(primeiro, NewSize, &size);
                        }
                    }
                    break;
                case 7:
                    if (codigoPilha)
                        DestroyStack(primeiro);
                    codigoPilha = -1;
                    printf("Pilha destruida com sucesso!\n");
                case 8:
                    break;
                default:
                    printf("\nCodigo invalido!\n");
                    codigo = 0;
                    break;
            }
        }
    }while(codigo != 8);

    return 0;
}
