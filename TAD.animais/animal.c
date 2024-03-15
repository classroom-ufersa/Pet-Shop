#include "animal.h"

void add_animal(Animal *pet, int total_de_pets, FILE *arquivo_petshop){

    printf("Digite o nome do animal: ");
    scanf(" %[^\n]", pet[total_de_pets].nome);

    printf("Digite a especie do animal: ");
    scanf(" %[^\n]", pet[total_de_pets].especie);

    printf("Digite o estado de saude do animal: ");
    scanf(" %[^\n]", pet[total_de_pets].saude);

    fprintf(arquivo_petshop, "Nome: %s\n", pet[total_de_pets].nome);
    fprintf(arquivo_petshop, "Especie: %s\n", pet[total_de_pets].especie);
    fprintf(arquivo_petshop, "Saude: %s\n", pet[total_de_pets].saude);
    fprintf(arquivo_petshop, "\n");

}