#include <stdio.h>
#include <stdlib.h>
#include "TAD.animais/animal.h"
#include "TAD.clientes/cliente.h"


int main(void)
{

    int num_clientes;

    printf("Informe o numero de clientes a serem cadastrados: ");
    scanf("%d", &num_clientes);

    Cliente *consumidor = cadastra_cliente(num_clientes);

    imprime_clientes(consumidor, num_clientes);

    free(consumidor);

    
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
}
    