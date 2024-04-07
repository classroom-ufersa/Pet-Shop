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

Animal *cadastra_animal(int num_animal, Cliente *lista_clientes){

    Animal *pet = (Animal *)malloc(num_animal * sizeof(Animal));

    if (pet == NULL)
    {
        printf("Erro ao alocar memoria! ");
        exit(1);
    }

    for (int i = 0; i < num_animal; i++)
    {
        pet[i] = *add_animal(lista_clientes);
    }
    return pet;
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

char ler_opcao(char menor_valor, char maior_valor)
{
    char escolhaop;
    char entrada[100];

    do
    {
        scanf(" %[^\n]", entrada);

        escolhaop = entrada[0];

        if (escolhaop >= menor_valor && escolhaop <= maior_valor && strlen(entrada) == 1)
        {
            return escolhaop;
        }
        else
        {
            printf("Opcao invalida. A opcao deve estar entre %c e %c: ", menor_valor, maior_valor);
        }
    } while (1);
}

void imprime_animais(Lista *animal, const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    fprintf(arquivo, "Animais cadastrados:\n");

    while (animal != NULL)
    {
        fprintf(arquivo, "Nome: %s\n", animal->animal->nome_animal);
        fprintf(arquivo, "Especie: %s\n", animal->animal->especie);
        fprintf(arquivo, "Saude: %s\n", animal->animal->saude);
        fprintf(arquivo, "ID: %d\n", animal->animal->id_animal);
        fprintf(arquivo, "\n");

        animal = animal->proximo;
    }

    fclose(arquivo);
    printf("\nDados dos animais foram impressos no arquivo %s.\n", nome_arquivo);
}

Lista *lista_busca_animal(char nome[], Lista *l)
{
    Lista *p;

    for (p = l; p != NULL; p = p->proximo)
    {
        if (strcmp(p->animal->nome_animal, nome) == 0)
            return p;
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