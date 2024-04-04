#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "../TAD.animais/animal.h"

No *cria_no(Cliente cliente)
{
    //Aloca memoria para novo no da lista encadeada
    No *Novo_no = (No *)malloc(sizeof(No));

    if (Novo_no == NULL)
    {
        printf("Erro ao alocar memoria para novo no;");
        exit(1);
    }
    //Inicializa campos do no com os dados fornecidos do cliente
    Novo_no->cliente = cliente;
    Novo_no->proximo = NULL; //Define próximo no como null, por se tratar do ultimo
    return Novo_no;
}

void insere_final(No **cabeca, Cliente cliente)
{
    //Cria um novo no, passando o cliente como parâmetro
    No *Novo_no = cria_no(cliente);

    //verifica se a lista esta vazia
    if (*cabeca == NULL)
    {

        //Caso lista esteja vazia, novo no se torna o primeiro da lista
        *cabeca = Novo_no;
    }

    else
    {
        //Caso lista não esteja vazia, percorre a lista até encontrar último no
        No *temp = *cabeca;
        while (temp->proximo != NULL)
        {
            temp = temp->proximo;
        }

        //Conecta novo no ao final da lista
        temp->proximo = Novo_no;
    }
}

No *insere_ordenada(No *lista, Cliente cliente) {
    No *novo_no = cria_no(cliente);
    No *atual = lista;
    No *anterior = NULL;

    // Caso a lista esteja vazia ou o novo cliente deva ser o primeiro
    if (lista == NULL || strcmp(cliente.nome, lista->cliente.nome) < 0) {
        novo_no->proximo = lista;
        return novo_no;
    }

    // Encontra o local correto para inserir o novo cliente
    while (atual != NULL && strcmp(cliente.nome, atual->cliente.nome) > 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Insere o novo cliente na posição correta
    novo_no->proximo = atual;

    if(anterior != NULL){

        anterior->proximo = novo_no;    
    }
    
    else {
        lista = novo_no;
    }

    return lista;
}


Cliente *cria_cliente(void)
{

    Cliente *consumidor = (Cliente *)malloc(sizeof(Cliente));

    int num_animais;
    int *ptr_animal;

    if (consumidor == NULL)
    {
        printf("Erro ao alocar memória!");
        exit(1);
    }

    printf("\nInforme os dados do cliente:\n ");

    printf("\nNome do cliente: ");
    scanf(" %[^\n]", consumidor->nome);

    printf("\nInforme o numero de telefone do cliente: ");
    scanf("%d", &consumidor->telefone);

    printf("\nInforme o endereco do cliente: ");
    scanf(" %[^\n]", consumidor->endereco);   

    return consumidor;
}

Cliente *cadastra_cliente(int num_clientes)
{
    Cliente *consumidor = (Cliente *)malloc(num_clientes * sizeof(Cliente));

    int num_animais;

    if (consumidor == NULL)
    {
        printf("Erro ao alocar memoria! ");
        exit(1);
    }

    for (int i = 0; i < num_clientes; i++)
    {

        printf("\n Cadastro do cliente\n");
        consumidor[i] = *cria_cliente();
    }

    return consumidor;
}

void imprime_clientes(No *cabeca, const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "a+");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    fprintf(arquivo, "\nClientes cadastrados:\n");

    while (cabeca != NULL)
    {
        fprintf(arquivo, "\nCliente:\n");
        fprintf(arquivo, "Nome: %s\n", cabeca->cliente.nome);
        fprintf(arquivo, "Telefone: %d\n", cabeca->cliente.telefone);
        fprintf(arquivo, "Endereco: %s\n", cabeca->cliente.endereco);

        cabeca = cabeca->proximo;
    }

    fclose(arquivo);
    printf("\nDados dos clientes foram impressos no arquivo %s.\n", nome_arquivo);
}