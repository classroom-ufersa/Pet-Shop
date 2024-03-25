#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

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
        printf("Erro ao alocar memória!");
        exit(1);
    }

    printf("Informe os dados do animal:\n");

    printf("Digite o nome do animal: ");
    scanf(" %[^\n]", pet->nome);

    printf("Digite a especie do animal: ");
    scanf(" %[^\n]", pet->especie);

    printf("Digite o estado de saude do animal: ");
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