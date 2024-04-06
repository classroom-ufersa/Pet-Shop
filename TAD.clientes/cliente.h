#ifndef CLIENTE_H
#define CLIENTE_H

/*Definição de um novo tipo: Cliente*/
typedef struct cliente Cliente;

/* Função que cria uma lista vazia (NULLL)*/
Cliente* lista_clientes(void);

/*Função que insere um elemento no início da lista*/
Cliente * Lista_insere(Cliente * Lista, char nome[], int telefone, char endereco[]);

/* Função que verifica se a lista esta vazia*/
int lista_vazia_clientes (Cliente *lista);

/* Função que imprime os elementos da lista*/
void lista_imprime(int elemento, Cliente *lista);

/* Função que busca um elemento na lista*/
Cliente * Lista_busca(char elemento[], Cliente * Lista);

/* Função que retira um elemento da lista*/
Cliente *lista_retira(Cliente *Lista, char nome[]);

/* Função que libera a memória alocada para a lista*/
void libera_lista(Cliente * Lista);

/* Função que insere de forma ordenada um elemento na lista*/
Cliente* insere_ordenada(Cliente *Lista, char nome[], int telefone, char endereco[]);

/* Função que lê de um arquivo e armazena em uma lista encadeada*/
Cliente *Cliente_ler_arquivo(char *nome_arquivo);

/* Função que solita ao usuário os dados de um cliente e o adiciona a lista de clientes*/
void adiciona_cliente(Cliente **lista_clientes, const char *nome_arquivo);

/* Função que remove um cliente da lista de clientes */
void remove_cliente(Cliente **lista_clientes);

/* Função que imprime os dados dos clientes armazenados em uma lista em um arquivo de texto*/
void imprime_clientes(Cliente *Lista, const char *nome_arquivo);

/* Função que lista os dados armazenados no arquivo de texto*/
void listar_clientes(const char *nome_arquivo);

#endif