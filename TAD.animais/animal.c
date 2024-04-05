#include "animal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Animal* add_animal(void) {
    Animal *pet = (Animal *)malloc(sizeof(Animal));

    if (pet == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    printf("Informe a quantidade de animais que deseja cadastrar:\n ");
    int qtd_animais;
    scanf("%d", &qtd_animais);
    getchar(); 

    for(int i = 0; i < qtd_animais; i++){
        printf("Informe os dados do animal %d:\n", i + 1);

        printf("Digite o nome do animal:\n ");
        scanf(" %[^\n]", pet->nome);

        printf("Digite a especie do animal:\n ");
        scanf(" %[^\n]", pet->especie);

        printf("Digite o estado de saude do animal:\n ");
        scanf(" %[^\n]", pet->saude);

        //printf("Digite o ID de saude do animal:\n ");
        //scanf(" %d", &pet->id_animal);

        printf("\nAnimal cadastrado com sucesso!\n");
    }      

    return pet;
}

Animal *cadastra_animal(int num_animal)
{
    Animal *pet = (Animal *)malloc(num_animal * sizeof(Animal));

    if (pet == NULL)
    {
        printf("Erro ao alocar memoria! ");
        exit(1);
    }

    for (int i = 0; i < num_animal; i++) {
        printf("\n Cadastro do animal\n");
        pet[i] = *add_animal();
    }
    return pet;
}
/*
Lista* lista_ler_arquivo() {
    FILE *arquivo;
    Animal *novo_animal;
    Lista *l = lista_animais();

    arquivo = fopen("pet_shop.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    novo_animal = (Animal *)malloc(sizeof(Animal));
    if (novo_animal == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    while (fscanf(arquivo, "%s %s %s %d", novo_animal->nome, novo_animal->especie, novo_animal->saude, &novo_animal->id_animal) != EOF) {
        l = lista_insere_ordenada(l, novo_animal);
        novo_animal = (Animal *)malloc(sizeof(Animal));
        if (novo_animal == NULL) {
            printf("Erro ao alocar memória!\n");
            exit(1);
        }
    }

    free(novo_animal);
    fclose(arquivo);
    return l;
}*/

void menu(){
    printf("\nMenu de Opcoes:\n");
    printf("\n");
    printf("1. Adicionar Cliente\n");
    printf("2. Remover Cliente\n");
    printf("3. Adicionar Animal\n");
    printf("4. Remover Animal\n");
    printf("5. Editar Cadastro de Animal\n");
    printf("6. Buscar Animal por Nome\n");
    printf("7. Listar Clientes e Animais\n");
    printf("8. Sair\n");
    printf("\n");
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
    FILE *arquivo = fopen(nome_arquivo, "a+");
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
        //fprintf(arquivo, "ID: %d\n", animal->animal->id_animal);

        animal = animal->proximo;
    }

    fclose(arquivo);
    printf("\nDados dos animais foram impressos no arquivo %s.\n", nome_arquivo);
}