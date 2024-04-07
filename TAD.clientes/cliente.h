#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente {
    char nome[50];
    char endereco[100];
    char telefone[15];
    struct Animal *animais;
    struct Cliente *prox;
} Cliente;

void adicionarCliente(Cliente **listaClientes);

void removerCliente(Cliente **listaClientes);

Cliente *buscarClientePorNome(Cliente *listaClientes, const char *nome);

void listarClientes(Cliente *listaClientes);

void liberarMemoria(Cliente *listaClientes);

#endif