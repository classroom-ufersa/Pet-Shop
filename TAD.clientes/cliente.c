#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "../TAD.animais/animal.h"
#include <ctype.h>

void adicionarCliente(Cliente **listaClientes)
{

    Cliente *novoCliente = (Cliente *)malloc(sizeof(Cliente));
    if (novoCliente == NULL)
    {
        printf("Erro ao alocar memoria para o cliente.\n");
        return;
    }

    printf("Digite o nome do cliente: ");
    int valido_nome = 1;
    do
    {
        scanf(" %[^\n]", novoCliente->nome);
        valido_nome = 1;

        for (int i = 0; novoCliente->nome[i] != '\0'; i++)
        {
            if (!isalpha(novoCliente->nome[i]) && novoCliente->nome[i] != ' ')
            {
                valido_nome = 0;
                printf("Nome invalido, tente novamente:\n ");
                printf("\nDigite o nome do cliente: ");
                break;
            }
        }
    } while (!valido_nome);

    printf("Digite o endereco do cliente: ");
    int valido_endereco = 1;
    do
    {
        scanf(" %[^\n]", novoCliente->endereco);
        valido_endereco = 1;

        for (int i = 0; novoCliente->endereco[i] != '\0'; i++)
        {
            if (!isalnum(novoCliente->endereco[i]) && novoCliente->endereco[i] != ' ')
            {
                valido_endereco = 0;
                printf("Endereco invalido, tente novamente:\n ");
                printf("\nDigite o endereco do cliente: ");
                break;
            }
        }
    } while (!valido_endereco);

    printf("Digite o telefone do cliente: ");
    int valido_telefone = 1;
    do
    {
        scanf(" %[^\n]", novoCliente->telefone);
        valido_telefone = 1;

        for (int i = 0; novoCliente->telefone[i] != '\0'; i++)
        {
            if (!isdigit(novoCliente->telefone[i]))
            {
                valido_telefone = 0;
                printf("Telefone invalido, tente novamente:\n");
                printf("\nDigite o telefone do cliente:");
                break;
            }
        }
    } while (!valido_telefone);

    novoCliente->animais = NULL;
    novoCliente->prox = NULL;

    if (*listaClientes == NULL)
    {
        *listaClientes = novoCliente;
    }
    else
    {
        Cliente *atual = *listaClientes;
        Cliente *anterior = NULL;

        while (atual != NULL && strcmp(novoCliente->nome, atual->nome) > 0)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL)
        {
            novoCliente->prox = *listaClientes;
            *listaClientes = novoCliente;
        }
        else
        {
            anterior->prox = novoCliente;
            novoCliente->prox = atual;
        }
    }

    printf("Cliente adicionado com sucesso!\n");
}

void removerCliente(Cliente **listaClientes)
{
    if (*listaClientes == NULL)
    {
        printf("Lista de clientes vazia.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do cliente que deseja remover: ");
    scanf(" %[^\n]", nome);

    Cliente *atual = *listaClientes;
    Cliente *anterior = NULL;

    while (atual != NULL && strcmp(nome, atual->nome) != 0)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Cliente nao encontrado.\n");
        return;
    }

    if (anterior == NULL)
    {
        *listaClientes = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    liberarMemoria(atual);

    printf("Cliente removido com sucesso!\n");
}

Cliente *buscarClientePorNome(Cliente *listaClientes, const char *nome)
{
    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL)
    {
        if (strcmp(nome, clienteAtual->nome) == 0)
        {
            return clienteAtual;
        }
        clienteAtual = clienteAtual->prox;
    }
    return NULL;
}

void listarClientes(Cliente *listaClientes)
{
    if (listaClientes == NULL)
    {
        printf("Lista de clientes vazia.\n");
        return;
    }

    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL)
    {
        printf("Cliente: %s\n", clienteAtual->nome);
        printf("Endereco: %s\n", clienteAtual->endereco);
        printf("Telefone: %s\n", clienteAtual->telefone);
        printf("Animais:\n");
        Animal *animalAtual = clienteAtual->animais;
        while (animalAtual != NULL)
        {
            printf("- Nome: %s, Especie: %s, Saude: %s\n", animalAtual->nome, animalAtual->especie, animalAtual->saude);
            animalAtual = animalAtual->prox;
        }
        clienteAtual = clienteAtual->prox;
    }
}

void liberarMemoria(Cliente *listaClientes)
{
    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL)
    {
        Cliente *clienteRemover = clienteAtual;
        clienteAtual = clienteAtual->prox;

        Animal *animalAtual = clienteRemover->animais;
        while (animalAtual != NULL)
        {
            Animal *animalRemover = animalAtual;
            animalAtual = animalAtual->prox;
            free(animalRemover);
        }

        free(clienteRemover);
    }
}