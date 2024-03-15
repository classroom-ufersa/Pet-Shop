#include<stdio.h>
#include<stdlib.h>
#include"cliente.h"

struct cliente{

char nome[80];
int telefone;
char endereco[80];
char animais[80];
};

Cliente * cria_cliente(void){

    Cliente * consumidor = (Cliente*) malloc(sizeof(Cliente*));
    
    if (consumidor == NULL ){
        printf("Erro ao alocar memória!");
        exit (1);
    }

    printf("Informe os dados do cliente: ");

    printf("\nNome do cliente: ");
    scanf(" %[^\n]", consumidor->nome);

    printf("\nInforme o numero de telefone do cliente: ");
    scanf("%d", &consumidor->telefone);

    printf("\nInforme o endereco do cliente: ");
    scanf(" %[^\n]", consumidor->endereco);

    printf("\nInforme qual seu animal: ");
    scanf(" %[^\n]", consumidor->animais);

    return consumidor;
}

Cliente * cadastra_cliente(int num_clientes){
    Cliente * consumidor = (Cliente *) malloc(num_clientes * sizeof(Cliente*));

    if (consumidor == NULL){
        printf("Erro ao alocar memoria! ");
        exit(1);
    }

    for (int i = 0; i < num_clientes; i++){

        printf("\n Cadastro do cliente\n");
        consumidor[i] = *cria_cliente();
    }

    return consumidor;
}

void imprime_clientes (Cliente * consumidor, int num_clientes){

    FILE *arquivo = fopen("clientes.txt", "a+");

    if (arquivo == NULL){
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    for (int i = 0; i < num_clientes; i++){

        fprintf(arquivo, "\ncliente:\n\t");
        fprintf(arquivo, "Nome: %s\n\t", consumidor[i].nome);
        fprintf(arquivo, "Telefone: %d\n\t", consumidor[i].telefone);
        fprintf(arquivo, "Endereco: %s\n\t", consumidor[i].endereco);
        fprintf(arquivo, "Animal: %s\n\t", consumidor[i].animais);
    }

    fclose(arquivo);
    printf("\nDados dos clientes foram impressos no arquivo 'clientes.txt'.\n");
}