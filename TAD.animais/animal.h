#include <stdio.h>
#include <stdlib.h>

typedef struct animal{
    char nome[80];
    char especie[80];
    char saude[80];
}Animal;

void add_animal(Animal *pet, int total_de_pets, FILE *arquivo_petshop);