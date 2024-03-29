#include "animal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

No2 *lista_remove(No2 *cabeca, int v){
    No2 *ant = NULL;
    No2 *p = cabeca;

    while(p != NULL && p->animal.id != v){
        ant = p;
        p = p->proximo;
    }
    if(p == NULL){
        return cabeca;
    }
    if(ant == NULL){
        cabeca = p->proximo;
    }
    else{
        ant->proximo = p->proximo;
    }
    free(p);
    return cabeca;
}

No2 *cria_no2(Animal animal) {
    No2 *Novo_no = (No2 *)malloc(sizeof(No2));

    if (Novo_no == NULL) {
        printf("Erro ao alocar memória para novo no;");
        exit(1);
    }

    Novo_no->animal = animal;
    Novo_no->proximo = NULL;
    return Novo_no;
}

void insere_final2(No2 **cabeca, Animal animal)
{

    No2 *Novo_no = cria_no2(animal);
    if (*cabeca == NULL)
    {
        *cabeca = Novo_no;
    }

    else
    {
        No2 *temp = *cabeca;
        while (temp->proximo != NULL)
        {
            temp = temp->proximo;
        }

        temp->proximo = Novo_no;
    }
}

Animal* add_animal(void){

    Animal *pet = (Animal *)malloc(sizeof(Animal));

    if (pet == NULL)
    {
    printf("Erro ao alocar memória!\n");
    exit(1);
    }

    printf("Informe os dados do animal.\n");

    printf("Digite o nome do animal:\n ");
    scanf(" %[^\n]", pet->nome);

    printf("Digite a especie do animal:\n ");
    scanf(" %[^\n]", pet->especie);

    printf("Digite o estado de saude do animal:\n ");
    scanf(" %[^\n]", pet->saude);

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