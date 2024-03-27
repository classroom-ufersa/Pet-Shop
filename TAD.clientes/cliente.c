#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "../TAD.animais/animal.h"

No *cria_no(Cliente cliente)
{
    //Aloca memoria para novo no da lista encadeada
    No *Novo_no = (No *)malloc(sizeof(No));

    if (Novo_no == NULL)
    {
        printf("Erro ao alocar memoria para novo no;");
        exit(1);
    }
    //Inicializa campos do no com os dados fornecidos do cliente
    Novo_no->cliente = cliente;
    Novo_no->proximo = NULL; //Define próximo no como null, por se tratar do ultimo
    return Novo_no;
}

void insere_final(No **cabeca, Cliente cliente)
{
    //Cria um novo no, passando o cliente como parâmetro
    No *Novo_no = cria_no(cliente);

    //verifica se a lista esta vazia
    if (*cabeca == NULL)
    {

        //Caso lista esteja vazia, novo no se torna o primeiro da lista
        *cabeca = Novo_no;
    }

    else
    {
        //Caso lista não esteja vazia, percorre a lista até encontrar último no
        No *temp = *cabeca;
        while (temp->proximo != NULL)
        {
            temp = temp->proximo;
        }

        //Conecta novo no ao final da lista
        temp->proximo = Novo_no;
    }
}

Cliente *cria_cliente(void)
{

    Cliente *consumidor = (Cliente *)malloc(sizeof(Cliente));

    int num_animais;

    if (consumidor == NULL)
    {
        printf("Erro ao alocar memória!");
        exit(1);
    }

    printf("\nInforme os dados do cliente:\n ");

    printf("\nNome do cliente: ");
    scanf(" %[^\n]", consumidor->nome);

    printf("\nInforme o numero de telefone do cliente: ");
    scanf("%d", &consumidor->telefone);

    printf("\nInforme o endereco do cliente: ");
    scanf(" %[^\n]", consumidor->endereco);

    printf("Quantos animais deseja cadastrar?\n");
	add_animal();         

    return consumidor;
}

Cliente *cadastra_cliente(int num_clientes)
{
    Cliente *consumidor = (Cliente *)malloc(num_clientes * sizeof(Cliente));

    if (consumidor == NULL)
    {
        printf("Erro ao alocar memoria! ");
        exit(1);
    }

    for (int i = 0; i < num_clientes; i++)
    {

        printf("\n Cadastro do cliente\n");
        consumidor[i] = *cria_cliente();
    }

    return consumidor;
}

void imprime_clientes(No *cabeca, const char *nome_arquivo, No2 *cabeca_animais)
{

    FILE *arquivo = fopen(nome_arquivo, "a+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    fprintf(arquivo, "\nClientes cadastrados:\n");

     while (cabeca != NULL)
    {
        No2 *ptr_animal = cabeca_animais;

        fprintf(arquivo, "\ncliente:\n\t");
        fprintf(arquivo, "Nome: %s\n\t", cabeca->cliente.nome);
        fprintf(arquivo, "Telefone: %d\n\t", cabeca->cliente.telefone);
        fprintf(arquivo, "Endereco: %s\n\t", cabeca->cliente.endereco);

        while (ptr_animal != NULL){
            
            fprintf(arquivo, "\nAnimal:\n\t");
            fprintf(arquivo, "Nome: %s\n\t", ptr_animal->animal.nome);
            fprintf(arquivo, "Especie: %s\n\t", ptr_animal->animal.especie);
            fprintf(arquivo, "Saude: %s\n\t", ptr_animal->animal.saude);

            ptr_animal = ptr_animal->proximo;
        }

        cabeca = cabeca->proximo;
    }
    fclose(arquivo);
    printf("\nDados dos clientes foram impressos no arquivo %s.\n", nome_arquivo);
}