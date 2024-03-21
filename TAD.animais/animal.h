#include <stdio.h>
#include <stdlib.h>

typedef struct animal{
    char nome[80];
    char especie[80];
    char saude[80];
    int id;
}Animal;

typedef struct No {
    Animal animal;
    struct No *proximo;
} No2;

/* Esta função solicita ao usuário o nome, espécie e saúde de um animal e armazena esses dados no array pet.*/
void add_animal(Animal *pet, int total_de_pets, FILE *arquivo_petshop);

/*Esta função aloca dinamicamente memória para um array de estruturas Animal com base no número fornecido em num_animal. 
Em seguida, abre um arquivo chamado "petshop.txt" para adicionar.*/
Animal *cadastra_animal(int num_animal);