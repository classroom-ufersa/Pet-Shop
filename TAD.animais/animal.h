#ifndef ANIMAL_H
#define ANIMAL_H

typedef struct animal {
    char nome[80];
    char especie[80];
    char saude[80];
    int id_animal;
} Animal;

typedef struct lista {
    Animal *animal;
    struct lista *proximo;
} Lista;

/* Esta função solicita ao usuário o nome, espécie e saúde de um animal e armazena esses dados no array pet.*/
Animal* add_animal(void);

/*Esta função aloca dinamicamente memória para um array de estruturas Animal com base no número fornecido em num_animal. 
Em seguida, abre um arquivo chamado "petshop.txt" para adicionar.*/
Animal *cadastra_animal(int num_animal);

Lista* lista_insere_ordenada(Lista* l, Animal *novo_animal);

Lista* lista_animais(void);

int lista_vazia(Lista *l);

//Lista* lista_ler_arquivo();

void imprime_animais(Lista *animal, const char *nome_arquivo);

/*
Menu com as opçoes
*/
void menu();

/*Essa função lê a opção escolhida pelo usuário e verifica se a opção é válida,
recebendo como parâmetro o menor valor e o maior valor que a opção pode ter.*/
char ler_opcao(char menor_valor, char maior_valor);

/*
funçao que remove um elemento da lista
*/
//No2 *lista_remove(No2 *cabeca, int v);

#endif