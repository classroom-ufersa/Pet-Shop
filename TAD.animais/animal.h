#ifndef ANIMAL_H
#define ANIMAL_H

#include "../TAD.clientes/cliente.h"

typedef struct Animal {
    char nome[50];
    char especie[50];
    char saude[50];
    struct Animal *prox;
} Animal;

/*funçao que adiciona animais*/
void adicionarAnimal(Cliente *listaClientes);

/*funçao que busca animal pelo nome*/
Animal *buscarAnimalPorNome(Cliente *listaClientes);

/*funçao que remove animal*/
void removerAnimal(Cliente *cliente);

/*funçao que edita os animais*/
void editarAnimal(Cliente *listaClientes);

/*funçao que libera a memoria*/
void liberarMemoria(Cliente *listaClientes);

#endif
