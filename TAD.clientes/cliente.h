#ifndef CLIENTE_H
#define CLIENTE_
#include"../TAD.animais/animal.h"

/* Definição da struct: cliente
*/
struct cliente
{
    char nome[80];
    int telefone;
    char endereco[80];
    char animais[80];
};

/* Definição de um novo tipo: Cliente
*/
typedef struct cliente Cliente;

/* Definição de um novo tipo: No*/
typedef struct no
{
    Cliente cliente;
    struct no *proximo;
}No;

/*Função que aloca memória dinâmicamente para um struct Cliente,
recebe os dados dos clientes via teclado e retorna um ponteiro para Cliente*/
Cliente * cria_cliente(void);

/* Função para criar um nó da lista encadeada
*/
No* cria_no(Cliente cliente);

/* Função que insere um nó no final da lista encadeada
*/
void insere_final(No** cabeca, Cliente cliente);

/* Função que realiza o cadastro de N clientes
*/
Cliente * cadastra_cliente(int num_clientes);

/* Função que abre um arquivo e imprime nele os dados dos clientes cadastradas
*/
void imprime_clientes(No *cabeca, const char *nome_arquivo);

#endif