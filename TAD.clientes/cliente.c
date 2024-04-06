#include "cliente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct cliente
{

    char nome[50];
    int telefone;
    char endereco[50];
    struct cliente *proximo;
};

Cliente *lista_clientes(void)
{

    return NULL;
}

Cliente *Lista_insere(Cliente *Lista, char nome[], int telefone, char endereco[])
{

    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!");
        exit(1);
    }

    strcpy(novo->nome, nome);
    novo->telefone = telefone;
    strcpy(novo->endereco, endereco);
    return novo;
}

int lista_vazia_clientes(Cliente *lista)
{
    return (lista == NULL);
}

void lista_imprime(int elemento, Cliente *lista)
{
    Cliente *p;
    for (p = lista; p != NULL; p = p->proximo)
    {
        printf(" Dados do cliente: ");

        printf("\nNome: %s\n", p->nome);
        printf("\nTelefone: %d\n", p->telefone);
        printf("\nEndereco: %s\n", p->endereco);
    }
}

Cliente *Lista_busca(char elemento[], Cliente *Lista)
{

    Cliente *p;
    for (p = Lista; p != NULL; p = p->proximo)
    {
        if (strcmp(p->nome, elemento) == 0)
            return p;
    }
    return NULL;
}

Cliente *lista_retira(Cliente *Lista, char nome[])
{
    Cliente *anterior = NULL;
    Cliente *atual = Lista;

    // Procura pelo cliente na lista
    while (atual != NULL && strcmp(atual->nome, nome) != 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    // Se não encontrar o cliente, retorna a lista sem alterações
    if (atual == NULL)
    {
        printf("Cliente não encontrado!\n");
        return Lista;
    }

    // Remove o cliente da lista
    if (anterior == NULL)
    {
        Lista = atual->proximo;
    }
    else
    {
        anterior->proximo = atual->proximo;
    }

    // Libera a memória alocada para o cliente removido
    free(atual);

    printf("Cliente removido com sucesso!\n");

    return Lista;
}

void libera_lista(Cliente *Lista)
{

    Cliente *p = Lista;
    Cliente *t;

    while (p != NULL)
    {
        t = p->proximo;
        free(p);
        p = t;
    }
}

Cliente *insere_ordenada(Cliente *Lista, char nome[], int telefone, char endereco[])
{
    Cliente *novo;
    Cliente *anterior = NULL;
    Cliente *p = Lista;

    // Criar o novo cliente
    novo = (Cliente *)malloc(sizeof(Cliente));
    if (novo == NULL)
    {
        printf("[ERRO] Memoria insuficiente!");
        exit(1);
    }

    // Preencher os dados do novo cliente
    strcpy(novo->nome, nome);
    novo->telefone = telefone;
    strcpy(novo->endereco, endereco);
    novo->proximo = NULL;

    // Encontrar o ponto de inserção
    while (p != NULL && strcmp(p->nome, nome) < 0)
    {
        anterior = p;
        p = p->proximo;
    }

    // Inserir o novo cliente na lista
    if (anterior == NULL)
    {
        novo->proximo = Lista;
        Lista = novo;
    }
    else
    {
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }

    return Lista;
}

void adiciona_cliente(Cliente **lista_clientes, const char *nome_arquivo)
{
    char nome[50];
    char telefone_str[20];
    int telefone;
    char endereco[50];

    printf("\nInforme os dados do cliente:\n");

    printf("Nome: ");
    int valido = 1;
    do
    {
        scanf(" %[^\n]", nome);
        valido = 1;
        for (int i = 0; nome[i] != '\0'; i++)
        {

            if (!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '\'')
            {
                valido = 0;

                printf("Invalido, tente novamente\n");
                printf("\nNome: ");
                break;
            }
        }
    } while (!valido);

   printf("\nTelefone: ");
    int valido_telefone = 1;
    do
    {
        scanf(" %[^\n]", telefone_str);
        valido_telefone = 1;
        // Verifica se todos os caracteres da string são dígitos
        for (int i = 0; telefone_str[i] != '\0'; i++)
        {
            if (!isdigit(telefone_str[i]))
            {
                valido_telefone = 0;
                printf("Telefone invalido, tente novamente:\n");
                printf("\nTelefone: ");
                break;
            }
        }
    } while (!valido_telefone);
    
    // Converte a string do telefone para um inteiro
    telefone = atoi(telefone_str);


    printf("\nEndereco: ");
    int valido_endereco = 1;
    do
    {
        scanf(" %[^\n]", endereco);
        valido_endereco = 1;
        for (int i = 0; endereco[i] != '\0'; i++)
        {
            if (!isalpha(endereco[i]) && endereco[i] != ' ' && endereco[i] != '\'')
            {
                valido_endereco = 0;
                printf("Invalido, tente novamente:\n");
                printf("\nEndereco: ");
                break;
            }
        }
    } while (!valido_endereco);

    *lista_clientes = insere_ordenada(*lista_clientes, nome, telefone, endereco);

    imprime_clientes(*lista_clientes, nome_arquivo);

    printf("Cliente inserido com sucesso.\n");
}

void remove_cliente(Cliente **lista_clientes)
{
    char nome[50];

    printf("\nNome do cliente que deseja remover: ");
    scanf(" %[^\n]", nome);

    Cliente *cliente = Lista_busca(nome, *lista_clientes);

    if (cliente == NULL)
    {
        printf("Cliente nao encontrado! ");
        return;
    }

    else
    {

        *lista_clientes = lista_retira(*lista_clientes, cliente->nome);

        imprime_clientes(*lista_clientes, "clientes.txt");

        printf("Cliente removido com sucesso! ");

        return;
    }

    free(cliente);

    return;
}

Cliente *Cliente_ler_arquivo(char *nome_arquivo)
{
    FILE *arquivo;
    Cliente *Lista = NULL; // Inicializa a lista de clientes como vazia

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        arquivo = fopen(nome_arquivo, "w");
        if (arquivo == NULL)
        {
            printf("Erro ao criar o arquivo %s\n", nome_arquivo);
            exit(1);
        }
        printf("Arquivo criado!\n");
        fclose(arquivo); // Fecha o arquivo após a criação
        return NULL;     // Retorna uma lista vazia, já que o arquivo está vazio
    }

    char nome[50];
    int telefone;
    char endereco[50];

    while (fscanf(arquivo, " %49s\t %d\t %49s\n", nome, &telefone, endereco) == 3)
    {
        // Insere o cliente na lista mantendo a ordenação alfabética
        Lista = insere_ordenada(Lista, nome, telefone, endereco);
    }

    fclose(arquivo);
    return Lista;
}

// Função para imprimir os clientes no arquivo no formato especificado
void imprime_clientes(Cliente *lista, const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    for (Cliente *p = lista; p != NULL; p = p->proximo)
    {
        fprintf(arquivo, "%s \t %d \t %s\n", p->nome, p->telefone, p->endereco);
    }

    fclose(arquivo);
    printf("Clientes impressos com sucesso no arquivo %s\n", nome_arquivo);
}

void listar_clientes(const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    printf("Clientes cadastrados:\n");
    printf("---------------------\n");

    char nome[50];
    int telefone;
    char endereco[50];

    while (fscanf(arquivo, " %49s %d %49s", nome, &telefone, endereco) == 3)
    {
        printf("Nome: %s\n", nome);
        printf("Telefone: %d\n", telefone);
        printf("Endereco: %s\n", endereco);
        printf("---------------------\n");
    }

    fclose(arquivo);
}