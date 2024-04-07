#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "../TAD.animais/animal.h"
#include <ctype.h>

void adicionarCliente(Cliente **listaClientes) {
    // Aloca memória para o novo cliente
    Cliente *novoCliente = (Cliente *)malloc(sizeof(Cliente));
    if (novoCliente == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return;
    }

     printf("Digite o nome do cliente: ");
    int valido_nome = 1;
    do {
        scanf(" %[^\n]", novoCliente->nome);
        valido_nome = 1;
        // Verifica se o nome contém apenas letras e espaços
        for (int i = 0; novoCliente->nome[i] != '\0'; i++) {
            if (!isalpha(novoCliente->nome[i]) && novoCliente->nome[i] != ' ') {
                valido_nome = 0;
                printf("Nome invalido, tente novamente:\n ");
                printf("\nDigite o nome do cliente: ");
                break;
            }
        }
    } while (!valido_nome);
    
    printf("Digite o endereco do cliente: ");
    int valido_endereco = 1;
    do {
        scanf(" %[^\n]", novoCliente->endereco);
        valido_endereco = 1;
        // Verifica se o endereço contém apenas letras, espaços e números
        for (int i = 0; novoCliente->endereco[i] != '\0'; i++) {
            if (!isalnum(novoCliente->endereco[i]) && novoCliente->endereco[i] != ' ') {
                valido_endereco = 0;
                printf("Endereco invalido, tente novamente:\n ");
                printf("\nDigite o endereco do cliente: ");
                break;
            }
        }
    } while (!valido_endereco);

    printf("Digite o telefone do cliente: ");
    int valido_telefone = 1;
    do {
        scanf(" %[^\n]", novoCliente->telefone);
        valido_telefone = 1;
        // Verifica se o telefone contém apenas números
        for (int i = 0; novoCliente->telefone[i] != '\0'; i++) {
            if (!isdigit(novoCliente->telefone[i])) {
                valido_telefone = 0;
                printf("Telefone invalido, tente novamente:\n");
                printf("\nDigite o telefone do cliente");
                break;
            }
        }
    } while (!valido_telefone);

    novoCliente->animais = NULL;
    novoCliente->prox = NULL;

    // Caso a lista de clientes esteja vazia, o novo cliente será o primeiro
    if (*listaClientes == NULL) {
        *listaClientes = novoCliente;
    } else {
        Cliente *atual = *listaClientes;
        Cliente *anterior = NULL;

        // Encontra a posição correta para inserir o novo cliente em ordem alfabética
        while (atual != NULL && strcmp(novoCliente->nome, atual->nome) > 0) {
            anterior = atual;
            atual = atual->prox;
        }

        // Insere o novo cliente na lista
        if (anterior == NULL) {
            novoCliente->prox = *listaClientes;
            *listaClientes = novoCliente;
        } else {
            anterior->prox = novoCliente;
            novoCliente->prox = atual;
        }
    }

    printf("Cliente adicionado com sucesso!\n");
}

void removerCliente(Cliente **listaClientes) {
    if (*listaClientes == NULL) {
        printf("Lista de clientes vazia.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do cliente que deseja remover: ");
    scanf(" %[^\n]", nome);

    Cliente *atual = *listaClientes;
    Cliente *anterior = NULL;

    // Procura pelo cliente na lista
    while (atual != NULL && strcmp(nome, atual->nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o cliente não foi encontrado
    if (atual == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    // Remove o cliente da lista
    if (anterior == NULL) {
        *listaClientes = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    // Libera a memória alocada para o cliente removido
    liberarMemoria(atual);

    printf("Cliente removido com sucesso!\n");
}


Cliente *buscarClientePorNome(Cliente *listaClientes, const char *nome) {
    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL) {
        if (strcmp(nome, clienteAtual->nome) == 0) {
            return clienteAtual;
        }
        clienteAtual = clienteAtual->prox;
    }
    return NULL;
}

void listarClientes(Cliente *listaClientes) {
    if (listaClientes == NULL) {
        printf("Lista de clientes vazia.\n");
        return;
    }

    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL) {
        printf("Cliente: %s\n", clienteAtual->nome);
        printf("Endereço: %s\n", clienteAtual->endereco);
        printf("Telefone: %s\n", clienteAtual->telefone);
        printf("Animais:\n");
        Animal *animalAtual = clienteAtual->animais;
        while (animalAtual != NULL) {
            printf("- Nome: %s, Especie: %s, Saude: %s\n", animalAtual->nome, animalAtual->especie, animalAtual->saude);
            animalAtual = animalAtual->prox;
        }
        clienteAtual = clienteAtual->prox;
    }
}

void liberarMemoria(Cliente *listaClientes) {
    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL) {
        Cliente *clienteRemover = clienteAtual;
        clienteAtual = clienteAtual->prox;

        Animal *animalAtual = clienteRemover->animais;
        while (animalAtual != NULL) {
            Animal *animalRemover = animalAtual;
            animalAtual = animalAtual->prox;
            free(animalRemover);
        }

        free(clienteRemover);
    }
}