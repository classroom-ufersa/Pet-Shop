#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

void add_animal(Animal *pet, int total_de_pets, FILE *arquivo_petshop){

    //Animal *pet = (Animal *)malloc(sizeof(Animal));

    if (pet == NULL)
    {
        printf("Erro ao alocar memória!");
        exit(1);
    }

    printf("Digite o nome do animal: ");
    scanf(" %[^\n]", pet[total_de_pets].nome);

    printf("Digite a especie do animal: ");
    scanf(" %[^\n]", pet[total_de_pets].especie);

    printf("Digite o estado de saude do animal: ");
    scanf(" %[^\n]", pet[total_de_pets].saude);

    //fprintf(arquivo_petshop, "Nome: %s\n", pet[total_de_pets].nome);
    //fprintf(arquivo_petshop, "Especie: %s\n", pet[total_de_pets].especie);
    //fprintf(arquivo_petshop, "Saude: %s\n", pet[total_de_pets].saude);
    //fprintf(arquivo_petshop, "\n");

}

Animal *cadastra_animal(int num_animal)
{
    Animal *pet = (Animal *)malloc(num_animal * sizeof(Animal));

    if (pet == NULL)
    {
        printf("Erro ao alocar memoria! ");
        exit(1);
    }

   FILE *arquivo_petshop = fopen("petshop.txt", "a");
    if (arquivo_petshop == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    for (int i = 0; i < num_animal; i++) {
        printf("\n Cadastro do animal %d\n", i+1);
        add_animal(pet, i, arquivo_petshop);
    }

    fclose(arquivo_petshop);
    return pet;
}

No2 *cria_no(Animal animal) {
    No2 *Novo_no = (No2 *)malloc(sizeof(No2));

    if (Novo_no == NULL) {
        printf("Erro ao alocar memória para novo nó;");
        exit(1);
    }

    Novo_no->animal = animal;
    Novo_no->proximo = NULL;
    return Novo_no;
}

void insere_final(No2 **cabeca, Animal animal)
{

    No2 *Novo_no = cria_no(animal);
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