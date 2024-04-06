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
    FILE *arquivo = fopen(nome_arquivo, "w");
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

        animal = animal->proximo;
    }

    fclose(arquivo);
    printf("\nDados dos animais foram impressos no arquivo %s.\n", nome_arquivo);
}

void remove_animal(Lista **lista_animal){
    char nome[50];

    printf("\nNome do animal que deseja remover: ");
    scanf("%s", nome);

    // Busca o animal na lista
    Lista *animal = lista_busca_animal(nome, *lista_animal);

    if (animal == NULL){
        printf("Animal nao encontrado!\n");
        return;
    }

    // Remove o animal da lista
    *lista_animal = lista_retira_animal(*lista_animal, nome);

    printf("Animal removido com sucesso!\n");
}

Lista *lista_retira_animal(Lista*l, char nome[]){ // Corrigido o tipo do parâmetro
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while(p != NULL && strcmp(p->animal->nome, nome) != 0){
        ant = p;
        p = p->proximo;
    }
    
    /* retira elemento */
    if (p == NULL)
        return l; /* não achou: retorna lista original */
    if (ant == NULL)
        l = p->proximo; /* retira elemento do inicio */
    else
        ant->proximo = p->proximo; /* retira elemento do meio da lista */
    free(p);
    return l;
}

Lista *lista_busca_animal(char nome[], Lista *l) {
    Lista *p;

    for(p = l; p != NULL; p = p->proximo) {
        if(strcmp(p->animal->nome, nome) == 0)
            return p;
    }

    return NULL;
}