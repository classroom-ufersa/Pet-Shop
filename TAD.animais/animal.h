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

Animal *add_animal2(Cliente *lista_clientes, char *nome_animal, char *especie, char *saude, int id_animal);

Lista *lista_retira_animal(Lista*l, char nome[]); // Corrigido o tipo do parâmetro

Lista *lista_busca_animal(char nome[], Lista *l);

void remove_animal(Lista **lista_animal);

Animal *cadastra_animal(int num_animal, Cliente *lista_clientes);

Lista* lista_insere_ordenada(Lista* l, Animal *novo_animal);

Lista* lista_animais(void);

int lista_vazia(Lista *l);

void imprime_animais(Lista *animal, const char *nome_arquivo);

void lista_edita_animal(Lista* animal, int id_alvo);

void imprime_animais_editado(Lista *lista);

void menu();

char ler_opcao(char menor_valor, char maior_valor);

void atualiza_cliente_arquivo(const char *nome_cliente, int id_animal, const char *nome_animal, const char *especie, const char *saude);

#endif
