#include <stdio.h>
#include <stdlib.h>
#include "TAD.animais/animal.h"
#include "TAD.clientes/cliente.h"

void add_animal(Animal *pet, int total_de_pets, FILE *arquivo_petshop);
Animal *cadastra_animal(int num_animal);

int main(void)
{
    int num_animal;

    printf("Quantos animais deseja cadastra?\n");
    scanf(" %d", &num_animal);

    Animal *petshop = cadastra_animal(num_animal);

    //void add_animal(Animal *pet, int total_de_pets, FILE *arquivo_petshop);

    //Animal *cadastra_animal(int num_animal);

    free(petshop);

    /*
    No* lista_clientes = NULL;
    int num_clientes;

    printf("Informe o numero de clientes a serem cadastrados: ");
    scanf("%d", &num_clientes);

    for (int i = 0; i < num_clientes; i++) {
        Cliente* novo_cliente = cria_cliente();
        insere_final(&lista_clientes, *novo_cliente);
        free(novo_cliente); 
    }

    imprime_clientes(lista_clientes, "clientes.txt");

    No* temp;
    while (lista_clientes != NULL) {
        temp = lista_clientes;
        lista_clientes = lista_clientes->proximo;
        free(temp);
    }
    */

    return 0;
}

    
    /*Animal *pet;
    int total_de_pets = 0;

    FILE *arquivo_petshop = fopen("arquivo_dados_do_petshop.txt", "w");
     if (arquivo_petshop == NULL)
    {
        printf("Erro ao criar o arquivo\n");
        exit(1);
    }

    add_animal(pet, total_de_pets, arquivo_petshop);

    return 0;
    */

    