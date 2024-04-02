#ifndef ANIMAL_H
#define ANIMAL_H

/* Definição da struct
*/
struct animal{
    char nome[80];
    char especie[80];
    char saude[80];
    int id;
};

/* Definição de um novo tipo: Animal
*/
typedef struct animal Animal;

/* Definicão de um novo tipo: No2
*/
typedef struct No {
    Animal animal;
    struct No *proximo;
} No2;

/* Esta função solicita ao usuário o nome, espécie e saúde de um animal e armazena esses dados no array pet.*/
Animal* add_animal(void);

/*Esta função aloca dinamicamente memória para um array de estruturas Animal com base no número fornecido em num_animal. 
Em seguida, abre um arquivo chamado "petshop.txt" para adicionar.*/
Animal *cadastra_animal(int num_animal);

/*Esta função cria um novo nó para ser adicionado a uma lista encadeada. Ela recebe um animal como 
parâmetro, que será armazenado no nó criado. A função aloca dinamicamente memória para o novo nó, inicializa 
os campos animal e proximo do nó com os valores passados e retorna o ponteiro para o novo nó criado.*/
No2 *cria_no2(Animal animal);

/*
Esta função insere um novo nó contendo um animal ao final de uma lista encadeada. 
Ela recebe um ponteiro para o ponteiro da cabeça da lista e um animal a ser inserido na 
lista. Se a lista estiver vazia, o novo nó será inserido como o primeiro nó da lista. 
Caso contrário, a função percorre a lista até encontrar o último nó e adiciona o novo nó como seu próximo nó.
*/
void insere_final2(No2 **cabeca, Animal animal);

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
No2 *lista_remove(No2 *cabeca, int v);

#endif