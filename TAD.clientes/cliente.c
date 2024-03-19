#include <stdio.h>
#include <stdlib.h>
#include "./cliente.h"
#include "../TAD.animais/animal.h"

No *cria_no(Cliente cliente)
{

    No *Novo_no = (No *)malloc(sizeof(No));

    if (Novo_no == NULL)
    {
        printf("Erro ao alocar memoria para novo no;");
        exit(1);
    }

    Novo_no->cliente = cliente;
    Novo_no->proximo = NULL;
    return Novo_no;
}

void insere_final(No **cabeca, Cliente cliente)
{

    No *Novo_no = cria_no(cliente);
    if (*cabeca == NULL)
    {
        *cabeca = Novo_no;
    }

    else
    {
        No *temp = *cabeca;
        while (temp->proximo != NULL)
        {
            temp = temp->proximo;
        }

        temp->proximo = Novo_no;
    }
}

Cliente *cria_cliente(void)
{

    Cliente *consumidor = (Cliente *)malloc(sizeof(Cliente));

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

    printf("\nInforme qual seu animal:\n ");
    scanf(" %[^\n]", consumidor->animais);

    return consumidor;
}

Cliente *cadastra_cliente(int num_clientes)
{
    Cliente *consumidor = (Cliente *)malloc(num_clientes * sizeof(Cliente));

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

        fprintf(arquivo, "\ncliente:\n\t");
        fprintf(arquivo, "Nome: %s\n\t", cabeca->cliente.nome);
        fprintf(arquivo, "Telefone: %d\n\t", cabeca->cliente.telefone);
        fprintf(arquivo, "Endereco: %s\n\t", cabeca->cliente.endereco);
        fprintf(arquivo, "Animal: %s\n\t", cabeca->cliente.animais);
        cabeca = cabeca->proximo;
    }
    fclose(arquivo);
    printf("\nDados dos clientes foram impressos no arquivo %s.\n", nome_arquivo);
}