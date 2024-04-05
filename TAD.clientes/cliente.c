#include "cliente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cliente{

    char nome[50];
    int telefone;
    char endereco[50];
    struct cliente *proximo;
};

Cliente* lista_clientes(void){

    return NULL;
}

Cliente * Lista_insere(Cliente * Lista, char nome[], int telefone, char endereco[]){

    Cliente *novo = (Cliente*) malloc(sizeof(Cliente));
    
    if (novo == NULL){
        printf("Erro ao alocar memoria!");
        exit(1);
    }

    strcpy(novo->nome, nome);
    novo->telefone = telefone;
    strcpy(novo->endereco, endereco);
        return novo;
}

int lista_vazia_clientes(Cliente *lista){
    return(lista == NULL);
}

void lista_imprime(int elemento, Cliente *lista){
    Cliente *p;
    for (p = lista; p != NULL; p = p->proximo){
        printf(" Dados do cliente: ");

        printf("\nNome: %s\n", p->nome);
        printf("\nTelefone: %d\n", p->telefone);
        printf("\nEndereco: %s\n", p->endereco);
    }
}

Cliente * Lista_busca(char elemento[], Cliente * Lista){

    Cliente * p;
    for (p = Lista; p != NULL; p=p->proximo){
        if (strcmp(p->nome, elemento)== 0)
        return p;
    }
    return NULL;
}

Cliente *lista_retira(Cliente *Lista, char nome[]){

    Cliente *anterior = NULL;
    Cliente *p = Lista;

    while(p->nome){
        if (p==NULL)    
        return Lista;
        
        anterior = p;
        p = p->proximo;
    } 

    if (anterior == NULL){

    Lista = p->proximo;
    }

    else{

    anterior->proximo =p->proximo;
    }

    free(p);
    return Lista;
}

void libera_lista(Cliente * Lista){

    Cliente *p = Lista;
    Cliente *t;

    while(p != NULL){
        t = p->proximo;
        free(p);
        p = t;
    }
}

Cliente* insere_ordenada(Cliente *Lista, char nome[], int telefone, char endereco[]){

    Cliente *novo;
    Cliente *anterior= NULL;
    Cliente *p = Lista;

    while(p != NULL && strcmp(p->nome, nome)){

        anterior = p;
        
        p = p->proximo;
    }

    novo = (Cliente*) malloc(sizeof(Cliente));
    strcpy (novo->nome, nome);   
    novo->telefone = telefone;
    strcpy(novo->endereco, endereco); 

    if (anterior == NULL){
        novo->proximo = Lista;
        Lista = novo;
    }

    else {
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }

    return Lista;
    }

    Cliente *Cliente_ler_arquivo(char *nome_arquivo){

        FILE *arquivo;
        int valor;
        Cliente *Lista = lista_clientes();
        char nome[50];
        int telefone;
        char endereco[50];

        arquivo = fopen(nome_arquivo, "r");
        if (arquivo == NULL){
            printf("Erro ao abrir arquivo!\n");
            exit(1);
        }
       while (fscanf(arquivo, "%s %d %s", nome, &telefone, endereco) != EOF) {
        Lista = insere_ordenada(Lista, nome, telefone, endereco);
        }

        fclose(arquivo);
        return Lista;
    }

void adiciona_cliente(Cliente **lista_clientes){
    char nome[50];
    int telefone;
    char endereco[50];

    printf("\nInforme os dados do cliente:\n");

    printf("Nome: ");
    scanf(" %[^\n]", nome);

    printf("\nTelefone: ");
    scanf("%d,", &telefone);

    printf("\nEndereco: ");
    scanf(" %[^\n]", endereco);
    *lista_clientes = insere_ordenada(*lista_clientes, nome, telefone, endereco);
    
    printf("Cliente inserido com sucesso:\n");
}

void remove_cliente(Cliente **lista_clientes){
    char nome[50];

    printf("\nNome do cliente que deseja remover: ");
    scanf("%s", nome);

    Cliente *cliente = Lista_busca(nome, *lista_clientes);

    if (cliente == NULL){
        printf("Cliente nao encontrado! ");
        return;
    }

    *lista_clientes = lista_retira(*lista_clientes, cliente->nome);

    printf("Cliente removido com sucesso! ");

    free(cliente); 
}

void imprime_clientes(Cliente *Lista, const char *nome_arquivo){

    FILE * arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL){
        printf("Erro ao abrir arquivo! ");
        exit(1);
    }

    Cliente *p;
    for (p = Lista; p !=NULL; p = p->proximo) {
        
        fprintf(arquivo, "\nDados do cliente:\n ");
        fprintf(arquivo, "\n\tNome: %s\n", p->nome);
        fprintf(arquivo, "\tTelefone: %d\n", p->telefone);
        fprintf(arquivo, "\tEndereco: %s", p->endereco);
        fprintf(arquivo, "\n");
    }
    
    fclose(arquivo);
    printf("Clientes impressos com sucesso no arquivo %s\n", nome_arquivo);
}