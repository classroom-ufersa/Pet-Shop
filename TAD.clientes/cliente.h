#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente
{
    char nome[50];
    char endereco[100];
    char telefone[15];
    struct Animal *animais;
    struct Cliente *prox;
} Cliente;

/* Função para adicionar um cliente*/
void adicionarCliente(Cliente **listaClientes);

/* Função para remover um cliente*/
void removerCliente(Cliente **listaClientes);

/* Função para buscar um cliente com base no seu nome*/
Cliente *buscarClientePorNome(Cliente *listaClientes, const char *nome);

/* Função para listar clientes e seus respectivos animais*/
void listarClientes(Cliente *listaClientes);

/* Função para liberar a memória alocada para os cliente se animais*/
void liberarMemoria(Cliente *listaClientes);

#endif