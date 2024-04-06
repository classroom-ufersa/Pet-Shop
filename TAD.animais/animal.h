#ifndef ANIMAL_H
#define ANIMAL_H

typedef struct animal {
    char nome[80];
    char especie[80];
    char saude[80];
    struct animal *proximo;
} Animal;

typedef struct lista {
    Animal *animal;
    struct lista *proximo;
} Lista;

Animal* add_animal(void);

Lista *lista_retira_animal(Lista*l, char nome[]); // Corrigido o tipo do parâmetro

Lista *lista_busca_animal(char nome[], Lista *l);

void remove_animal(Lista **lista_animal);

Animal *cadastra_animal(int num_animal);

Lista* lista_insere_ordenada(Lista* l, Animal *novo_animal);

Lista* lista_animais(void);

int lista_vazia(Lista *l);

void imprime_animais(Lista *animal, const char *nome_arquivo);

void menu();

char ler_opcao(char menor_valor, char maior_valor);

#endif
