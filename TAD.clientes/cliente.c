#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "../TAD.animais/animal.h"
#include <ctype.h>

void adicionarCliente(Cliente **listaClientes) {
    // Aloca memória para o novo cliente
    Cliente *novoCliente = (Cliente *)malloc(sizeof(Cliente));
    if (novoCliente == NULL) {
        printf("Erro ao alocar memória para o cliente.\n");
        return;
    }

     printf("Digite o nome do cliente: ");
    int valido_nome = 1;
    do {
        scanf(" %[^\n]", novoCliente->nome);
        valido_nome = 1;
        // Verifica se o nome contém apenas letras e espaços
        for (int i = 0; novoCliente->nome[i] != '\0'; i++) {
            if (!isalpha(novoCliente->nome[i]) && novoCliente->nome[i] != ' ') {
                valido_nome = 0;
                printf("Nome invalido, tente novamente:\n ");
                printf("\nDigite o nome do cliente: ");
                break;
            }
        }
    } while (!valido_nome);
    
    printf("Digite o endereco do cliente: ");
    int valido_endereco = 1;
    do {
        scanf(" %[^\n]", novoCliente->endereco);
        valido_endereco = 1;
        // Verifica se o endereço contém apenas letras, espaços e números
        for (int i = 0; novoCliente->endereco[i] != '\0'; i++) {
            if (!isalnum(novoCliente->endereco[i]) && novoCliente->endereco[i] != ' ') {
                valido_endereco = 0;
                printf("Endereço invalido, tente novamente:\n ");
                printf("\nDigite o endereço do cliente: ");
                break;
            }
        }
    } while (!valido_endereco);

    printf("Digite o telefone do cliente: ");
    int valido_telefone = 1;
    do {
        scanf(" %[^\n]", novoCliente->telefone);
        valido_telefone = 1;
        // Verifica se o telefone contém apenas números
        for (int i = 0; novoCliente->telefone[i] != '\0'; i++) {
            if (!isdigit(novoCliente->telefone[i])) {
                valido_telefone = 0;
                printf("Telefone invalido, tente novamente:\n");
                printf("\nDigite o telefone do cliente");
                break;
            }
        }
    } while (!valido_telefone);

    novoCliente->animais = NULL;
    novoCliente->prox = NULL;

    // Caso a lista de clientes esteja vazia, o novo cliente será o primeiro
    if (*listaClientes == NULL) {
        *listaClientes = novoCliente;
    } else {
        Cliente *atual = *listaClientes;
        Cliente *anterior = NULL;

        // Encontra a posição correta para inserir o novo cliente em ordem alfabética
        while (atual != NULL && strcmp(novoCliente->nome, atual->nome) > 0) {
            anterior = atual;
            atual = atual->prox;
        }

        // Insere o novo cliente na lista
        if (anterior == NULL) {
            novoCliente->prox = *listaClientes;
            *listaClientes = novoCliente;
        } else {
            anterior->prox = novoCliente;
            novoCliente->prox = atual;
        }
    }

    printf("Cliente adicionado com sucesso!\n");
}

void removerCliente(Cliente **listaClientes) {
    if (*listaClientes == NULL) {
        printf("Lista de clientes vazia.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do cliente que deseja remover: ");
    scanf(" %[^\n]", nome);

    Cliente *atual = *listaClientes;
    Cliente *anterior = NULL;

    // Procura pelo cliente na lista
    while (atual != NULL && strcmp(nome, atual->nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o cliente não foi encontrado
    if (atual == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    // Remove o cliente da lista
    if (anterior == NULL) {
        *listaClientes = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    // Libera a memória alocada para o cliente removido
    liberarMemoria(atual);

    printf("Cliente removido com sucesso!\n");
}


Cliente *buscarClientePorNome(Cliente *listaClientes, const char *nome) {
    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL) {
        if (strcmp(nome, clienteAtual->nome) == 0) {
            return clienteAtual;
        }
        clienteAtual = clienteAtual->prox;
    }
    return NULL;
}

void listarClientes(Cliente *listaClientes) {
    if (listaClientes == NULL) {
        printf("Lista de clientes vazia.\n");
        return;
    }

    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL) {
        printf("Cliente: %s\n", clienteAtual->nome);
        printf("Endereço: %s\n", clienteAtual->endereco);
        printf("Telefone: %s\n", clienteAtual->telefone);
        printf("Animais:\n");
        Animal *animalAtual = clienteAtual->animais;
        while (animalAtual != NULL) {
            printf("- Nome: %s, Especie: %s, Saude: %s\n", animalAtual->nome, animalAtual->especie, animalAtual->saude);
            animalAtual = animalAtual->prox;
        }
        clienteAtual = clienteAtual->prox;
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
    char nome_animal[50];
    char especie[80];
    char saude[80];
    int id_animal;

    while (fscanf(arquivo, " %49s\t %d\t %49s\t %49s\t %49s\t %d\n", nome, &telefone, endereco, nome_animal, especie, saude, &id_animal) != EOF)
    {
        // Insere o cliente na lista mantendo a ordenação alfabética
        Lista = insere_ordenada(Lista, nome, telefone, endereco);

        // Encontra o cliente recém-inserido na lista
        Cliente *cliente_associado = Lista_busca(nome, Lista);
        if (cliente_associado == NULL)
        {
            printf("Erro ao encontrar o cliente associado ao animal.\n");
            continue;
        }

        // Cadastra e associa o animal ao cliente
        Animal *novo_animal = add_animal2(Lista, nome_animal, especie, saude, id_animal);
    

        if (novo_animal == NULL)
        {
            printf("Erro ao cadastrar o animal associado ao cliente.\n");
            continue;
        }

        cliente_associado->animal_associado = novo_animal;
    }

    fclose(arquivo);
    return Lista;
}


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