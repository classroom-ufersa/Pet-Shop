#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../TAD.clientes/cliente.h"
#include "animal.h"

void adicionarAnimal(Cliente *listaClientes) {
    if (listaClientes == NULL) {
        printf("Não há clientes cadastrados para associar o animal.\n");
        return;
    }

    char nomeCliente[50];
    printf("Digite o nome do cliente ao qual o animal será associado: ");
    scanf(" %[^\n]", nomeCliente);

    Cliente *cliente = buscarClientePorNome(listaClientes, nomeCliente);
    if (cliente == NULL) {
        printf("Cliente não encontrado.\n");
        return;
    }

    // Aloca memória para o novo animal
    Animal *novoAnimal = (Animal *)malloc(sizeof(Animal));
    if (novoAnimal == NULL) {
        printf("Erro ao alocar memória para o animal.\n");
        return;
    }

    printf("Digite o nome do animal: ");
    scanf(" %[^\n]", novoAnimal->nome);
    printf("Digite a espécie do animal: ");
    scanf(" %[^\n]", novoAnimal->especie);
    printf("Digite o estado de saúde do animal: ");
    scanf(" %[^\n]", novoAnimal->saude);

    novoAnimal->prox = NULL;

    // Caso o cliente não tenha nenhum animal, o novo animal será o primeiro
    if (cliente->animais == NULL) {
        cliente->animais = novoAnimal;
    } else {
        Animal *atual = cliente->animais;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoAnimal;
    }

    printf("Animal adicionado com sucesso!\n");
}

void removerAnimal(Cliente *cliente) {
    if (cliente == NULL || cliente->animais == NULL) {
        printf("Cliente não possui animais cadastrados.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do animal que deseja remover: ");
    scanf(" %[^\n]", nome);

    Animal *atual = cliente->animais;
    Animal *anterior = NULL;

    // Procura pelo animal na lista do cliente
    while (atual != NULL && strcmp(nome, atual->nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o animal não foi encontrado
    if (atual == NULL) {
        printf("Animal não encontrado.\n");
        return;
    }

    // Remove o animal da lista do cliente
    if (anterior == NULL) {
        cliente->animais = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    // Libera a memória alocada para o animal removido
    free(atual);

    printf("Animal removido com sucesso!\n");
}

void menu()
{
    printf("\n------Menu de Opcoes------\n");
    printf("\n");
    printf("1. Adicionar Cliente\n");
    printf("2. Remover Cliente\n");
    printf("3. Adicionar Animal\n");
    printf("4. Remover Animal\n");
    printf("5. Editar Cadastro de Animal\n");
    printf("6. Buscar Animal por Nome\n");
    printf("7. Listar Clientes e Animais\n");
    printf("8. Sair\n");
    printf("\n--------------------------\n");
}

Animal *buscarAnimalPorNome(Cliente *listaClientes, const char *nome) {
    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL) {
        Animal *animalAtual = clienteAtual->animais;
        while (animalAtual != NULL) {
            if (strcmp(nome, animalAtual->nome) == 0) {
                return animalAtual;
            }
            animalAtual = animalAtual->prox;
        }
        clienteAtual = clienteAtual->prox;
    }
    return NULL;
}

void editarAnimal(Cliente *listaClientes) {
    if (listaClientes == NULL) {
        printf("Não há clientes cadastrados.\n");
        return;
    }

    char nomeCliente[50], nomeAnimal[50];
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nomeCliente);

    Cliente *cliente = buscarClientePorNome(listaClientes, nomeCliente);
    if (cliente == NULL) {
        printf("Cliente não encontrado.\n");
        return;
    }

    printf("Digite o nome do animal que deseja editar: ");
    scanf(" %[^\n]", nomeAnimal);

    Animal *atual = cliente->animais;

    // Procura pelo animal na lista do cliente
    while (atual != NULL && strcmp(nomeAnimal, atual->nome) != 0) {
        atual = atual->prox;
    }

    // Se o animal não foi encontrado
    if (atual == NULL) {
        printf("Animal não encontrado para o cliente %s.\n", nomeCliente);
        return;
    }

    char novoNome[50], novaEspecie[50], novaSaude[50];
    printf("Digite o novo nome do animal: ");
    scanf(" %[^\n]", novoNome);
    printf("Digite a nova espécie do animal: ");
    scanf(" %[^\n]", novaEspecie);
    printf("Digite o novo estado de saúde do animal: ");
    scanf(" %[^\n]", novaSaude);

    // Atualiza as informações do animal
    strcpy(atual->nome, novoNome);
    strcpy(atual->especie, novaEspecie);
    strcpy(atual->saude, novaSaude);

    printf("Cadastro do animal atualizado com sucesso!\n");
}