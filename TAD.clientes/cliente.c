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

void imprime_clientes (Cliente * consumidor, int num_clientes){

    FILE *arquivo = fopen("clientes.txt", "a+");

    if (arquivo == NULL){
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    for (int i = 0; i < num_clientes; i++){

        fprintf(arquivo, "\nclientes %d\n\t", i + 1);
        fprintf(arquivo, "Nome: %s\n\t", consumidor[i].nome);
        fprintf(arquivo, "Telefone: %d\n\t", consumidor[i].telefone);
        fprintf(arquivo, "Endereco: %s\n\t", consumidor[i].endereco);
        fprintf(arquivo, "Animal: %s\n\t", consumidor[i].animais);
    }

    fclose(arquivo);
    printf("\nDados dos clientes foram impressos no arquivo 'clientes.txt'.\n");
}



