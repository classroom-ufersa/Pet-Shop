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

void lista_edita_animal(Lista *animal, int id_alvo)
{
    Lista *temp = animal;

    while (temp != NULL && temp->animal->id_animal != id_alvo)
    {
        temp = temp->proximo;
    }

    if (temp != NULL)
    {

        printf("Digite o novo nome do animal:\n");
        scanf(" %[^\n]", temp->animal->nome_animal);

        printf("Digite a nova especie do animal:\n");
        scanf(" %[^\n]", temp->animal->especie);

        printf("Digite o novo estado de saude do animal:\n");
        scanf(" %[^\n]", temp->animal->saude);

        printf("Edição concluida com sucesso.\n");
    }
    else
    {
        printf("Animal com ID %s nao encontrado na lista.\n", id_alvo);
    }
}

void imprime_animais_editado(Lista *lista)
{
    printf("Lista de animais apos a ediçao:\n");

    if (lista == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    while (lista != NULL)
    {
        printf("Nome: %s, Especie: %s, Saude: %s, ID: %d\n", lista->animal->nome_animal, lista->animal->especie, lista->animal->saude, lista->animal->id_animal);
        lista = lista->proximo;
    }
}

void atualiza_cliente_arquivo(const char *nome_cliente, int id_animal, const char *nome_animal, const char *especie, const char *saude) {
    FILE *arquivo_entrada = fopen("clientes.txt", "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        return;
    }

    FILE *arquivo_saida = fopen("clientes_temp.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo temporário clientes_temp.txt\n");
        fclose(arquivo_entrada);
        return;
    }

    char linha[1000];
    int encontrado = 0;

    // Percorre o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo_entrada) != NULL) {
        // Verifica se a linha contém o nome do cliente
        if (strstr(linha, nome_cliente) != NULL) {
            // Adiciona as informações do animal associado à linha do cliente
            fprintf(arquivo_saida, "%s Animal: %s/ Especie: %s/ Saude: %s/ ID Animal: %d\n", linha, nome_animal, especie, saude, id_animal);
            encontrado = 1;
        } else {
            // Escreve a linha original no arquivo temporário
            fprintf(arquivo_saida, "%s", linha);
        }
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    // Remove o arquivo original
    remove("clientes.txt");

    // Renomeia o arquivo temporário para o nome original
    if (rename("clientes_temp.txt", "clientes.txt") != 0) {
        printf("Erro ao renomear o arquivo temporário\n");
        return;
    }

    if (!encontrado) {
        printf("Cliente não encontrado no arquivo clientes.txt\n");
    } else {
        printf("Associação entre cliente e animal atualizada com sucesso no arquivo clientes.txt\n");
    }
}