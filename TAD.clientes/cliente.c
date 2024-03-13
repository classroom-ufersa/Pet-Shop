#include<stdio.h>
#include<stdlib.h>
#include"cliente.h"

struct cliente{

char nome[80];
int telefone;
char endereco[80];
char animais[80];
};

Cliente * cria_cliente(char nome[], int telefone, char endereco, char animais){

    Cliente * consumidor = (Cliente*) malloc(sizeof(Cliente*));
    
    if (consumidor == NULL ){
        printf("Erro ao alocar memória!");
        exit (1);
    }

    printf("Informe os dados do cliente: ");

    printf("Nome do cliente: ");
    scanf(" %[^\n]", consumidor->nome);

    printf("Informe o numero de telefone do cliente: ");
    scanf("%d", &consumidor->telefone);

    printf("Informe o endereco do cliente: ");
    scanf(" %[^\n]", consumidor->endereco);

    printf("Informe qual seu animal: ");
    scanf(" %[^\n]", consumidor->animais);

    return consumidor;
}



