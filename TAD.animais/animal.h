#ifndef ANIMAL_H
#define ANIMAL_H

#include "../TAD.clientes/cliente.h"

typedef struct animal {
    char nome_animal[80];
    char especie[80];
    char saude[80];
    int id_animal;
    Cliente *cliente_associado; 
    struct animal *proximo;
} Animal;

typedef struct lista {
    Animal *animal;
    struct lista *proximo;
} Lista;

void limpabuffer();

void adicionarAnimal(Cliente *listaClientes);

Animal *buscarAnimalPorNome(Cliente *listaClientes, const char *nome);

void removerAnimal(Cliente *cliente);

Lista* lista_animais(void);

void editarAnimal(Cliente *listaClientes);

void imprime_animais_editado(Lista *lista);

void menu();

char ler_opcao(char menor_valor, char maior_valor);

void atualiza_cliente_arquivo(const char *nome_cliente, int id_animal, const char *nome_animal, const char *especie, const char *saude);

#endif
