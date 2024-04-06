#include "animal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../TAD.clientes/cliente.h"

void limpabuffer()
{
    fflush(stdin);
}

Lista* lista_animais(void) {
    return NULL;
}

Lista* lista_insere_ordenada(Lista* l, Animal *novo_animal) {
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = l;
    
    novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL){
        printf("Erro, memoria insuficiente!");
        exit(1);
    }
    
    novo->animal = novo_animal;
    novo->proximo = NULL;
    
    while(p != NULL && strcmp(p->animal->nome, novo_animal->nome) < 0){
        ant = p;
        p = p->proximo;
    }
    
    if(ant == NULL){
        novo->proximo = l;
        l = novo;
    } else {
        novo->proximo = ant->proximo;
        ant->proximo = novo;
    }
    
    return l;
}

int lista_vazia(Lista *l){
    return (l == NULL);
}

Animal* add_animal(Cliente *lista_clientes) {
    Animal *pet = (Animal *)malloc(sizeof(Animal));

    if (pet == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
        printf("\n");
        printf("Informe os dados do animal!\n");
        printf("\n");
        printf("Digite o nome do animal:\n ");
        scanf(" %[^\n]", pet->nome);
       
        printf("Digite a especie do animal:\n ");
        scanf(" %[^\n]", pet->especie);

        printf("Digite o estado de saude do animal:\n ");
        scanf(" %[^\n]", pet->saude);

        printf("Digite o ID do animal:\n ");
        scanf(" %d", &pet->id_animal);

        printf("Nome do cliente ao qual deve-se associar este animal: ");
        char nome_cliente[50];
        scanf(" %[^\n]", nome_cliente);

        Cliente* cliente_associado = Lista_busca(nome_cliente, lista_clientes);
        if (cliente_associado == NULL){
            printf("Cliente nao encontrado!" );
            return NULL;
        }

        else{

            pet->cliente_associado = cliente_associado;

        printf("Animal cadastrado com sucesso!\n");

        }

        return pet;
    }      

Animal *cadastra_animal(int num_animal, Cliente *lista_clientes)
{
    Animal *pet = (Animal *)malloc(num_animal * sizeof(Animal));

    if (pet == NULL)
    {
        printf("Erro ao alocar memoria! ");
        exit(1);
    }

    for (int i = 0; i < num_animal; i++) {
        pet[i] = *add_animal(lista_clientes);
    }
    return pet;
}

void menu(){
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

void imprime_animais(Lista *animal, const char *nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    fprintf(arquivo, "Animais cadastrados:\n");

    while (animal != NULL)
    {
        fprintf(arquivo, "Nome: %s\n", animal->animal->nome);
        fprintf(arquivo, "Especie: %s\n", animal->animal->especie);
        fprintf(arquivo, "Saude: %s\n", animal->animal->saude);
        fprintf(arquivo, "ID: %d\n", animal->animal->id_animal);
        fprintf(arquivo, "\n");

        animal = animal->proximo;
    }

    fclose(arquivo);
    printf("\nDados dos animais foram impressos no arquivo %s.\n", nome_arquivo);
}

void remove_animal(Lista **lista_animal){
    int id_remover;

    printf("ID do animal que deseja remover:\n");
    scanf(" %d", &id_remover);

    // Busca o animal na lista
    Lista *ant = NULL;
    Lista *p = *lista_animal;

    while (p != NULL && p->animal->id_animal != id_remover) {
        ant = p;
        p = p->proximo;
    }

    // Se não encontrou o animal na lista
    if (p == NULL) {
        printf("Animal nao encontrado!\n");
        return;
    }

    // Remove o animal da lista
    if (ant == NULL)
        *lista_animal = p->proximo;
    else
        ant->proximo = p->proximo;

    free(p);
    printf("Animal removido com sucesso!\n");
}

Lista *lista_busca_animal(char nome[], Lista *l) {
    Lista *p;

    for(p = l; p != NULL; p = p->proximo) {
        if(strcmp(p->animal->nome, nome) == 0)
            return p;
    }

    return NULL;
}

void lista_edita_animal(Lista* animal, int id_alvo) {
    Lista* temp = animal;

    while (temp != NULL && temp->animal->id_animal != id_alvo) {
        temp = temp->proximo;
    }

    if (temp != NULL) {
    
        printf("Digite o novo nome do animal:\n");
        scanf(" %[^\n]", temp->animal->nome);

        printf("Digite a nova especie do animal:\n");
        scanf(" %[^\n]", temp->animal->especie);

        printf("Digite o novo estado de saude do animal:\n");
        scanf(" %[^\n]", temp->animal->saude);

        printf("Edição concluida com sucesso.\n");
    } else {
        printf("Animal com ID %s nao encontrado na lista.\n", id_alvo);
    }
}

void imprime_animais_editado(Lista *lista){
    printf("Lista de animais apos a ediçao:\n");
    
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    while (lista != NULL) {
        printf("Nome: %s, Especie: %s, Saude: %s, ID: %d\n", lista->animal->nome, lista->animal->especie, lista->animal->saude, lista->animal->id_animal);
        lista = lista->proximo;
    }
}
