#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../TAD.clientes/cliente.h"
#include "animal.h"
#include <ctype.h>

void adicionarAnimal(Cliente *listaClientes) {
    if (listaClientes == NULL) {
        printf("Nao ha clientes cadastrados para associar o animal.\n");
        return;
    }

    char nomeCliente[50];
    printf("Digite o nome do cliente ao qual o animal sera associado: ");
    scanf(" %[^\n]", nomeCliente);

    Cliente *cliente = buscarClientePorNome(listaClientes, nomeCliente);
    if (cliente == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    // Aloca memória para o novo animal
    Animal *novoAnimal = (Animal *)malloc(sizeof(Animal));
    if (novoAnimal == NULL) {
        printf("Erro ao alocar memoria para o animal.\n");
        return;
    }

    printf("Digite o nome do animal: ");
    int valido_nome = 1;
    do {
        scanf(" %[^\n]", novoAnimal->nome);
        valido_nome = 1;
        // Verifica se o nome contém apenas letras e espaços
        for (int i = 0; novoAnimal->nome[i] != '\0'; i++) {
            if (!isalpha(novoAnimal->nome[i]) && novoAnimal->nome[i] != ' ') {
                valido_nome = 0;
                printf("Nome invalido, tente novamente:\n ");
                printf("\nDigite o nome do animal: ");
                break;
            }
        }
    } while (!valido_nome);

    printf("Digite a especie do animal: ");
    int valido_especie = 1;
    do {
        scanf(" %[^\n]", novoAnimal->especie);
        valido_especie = 1;
        // Verifica se a especie contém apenas letras e espaços
        for (int i = 0; novoAnimal->especie[i] != '\0'; i++) {
            if (!isalpha(novoAnimal->especie[i]) && novoAnimal->especie[i] != ' ') {
                valido_especie = 0;
                printf("Especie invalido, tente novamente:\n ");
                printf("\nDigite a especie do animal: ");
                break;
            }
        }
    } while (!valido_especie);

    printf("Digite o estado de saude do animal: ");
    int valido_saude = 1;
    do {
        scanf(" %[^\n]", novoAnimal->saude);
        valido_saude = 1;
        // Verifica se a saude contém apenas letras, espaços e números
        for (int i = 0; novoAnimal->saude[i] != '\0'; i++) {
            if (!isalnum(novoAnimal->saude[i]) && novoAnimal->saude[i] != ' ') {
                valido_saude = 0;
                printf("Saude invalido, tente novamente:\n ");
                printf("\nDigite a saude do animal: ");
                break;
            }
        }
    } while (!valido_saude);


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
        printf("Cliente nao possui animais cadastrados.\n");
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
        printf("Animal nao encontrado.\n");
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
        printf("Nao ha clientes cadastrados.\n");
        return;
    }

    char nomeCliente[50], nomeAnimal[50];
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nomeCliente);

    Cliente *cliente = buscarClientePorNome(listaClientes, nomeCliente);
    if (cliente == NULL) {
        printf("Cliente nao encontrado.\n");
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
        printf("Animal nao encontrado para o cliente %s.\n", nomeCliente);
        return;
    }

    char novoNome[50], novaEspecie[50], novaSaude[50];
    printf("Digite o novo nome do animal: ");
    scanf(" %[^\n]", novoNome);
    printf("Digite a nova especie do animal: ");
    scanf(" %[^\n]", novaEspecie);
    printf("Digite o novo estado de saude do animal: ");
    scanf(" %[^\n]", novaSaude);

    // Atualiza as informações do animal
    strcpy(atual->nome, novoNome);
    strcpy(atual->especie, novaEspecie);
    strcpy(atual->saude, novaSaude);

    printf("Cadastro do animal atualizado com sucesso!\n");
}