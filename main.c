#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.animais/animal.h"
#include "TAD.clientes/cliente.h"

int main(void)
{

    No* lista_clientes = NULL;
    int num_clientes;
    int num_animais;
    char escolhaop;

    do {
        menu();
        printf("Escolha uma opcao: ");
        escolhaop = ler_opcao('1', '8'); 

        switch (escolhaop) {
        case '1':
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
        break;

        case '2':
        //funçao de remover cliente
		printf("Função indisponivel\n");
        break;

        case '3':
		printf("Quantos animais deseja cadastrar?");
		scanf(" %d", &num_animais);

		Animal *petshop = cadastra_animal(num_animais);
		free(petshop);            
		break;

        case '4': 
		//funçao de remover animal
		printf("Função indisponivel\n");
        break;

	    case '5':
		//funçao de editar cadastro de animal
		printf("Função indisponivel\n");
        break;

	    case '6':   
		//funçao de Buscar Animal por Nome
		printf("Função indisponivel\n");
        break;

	    case '7': 
		//funçao de Listar Clientes e Animais
		printf("Função indisponivel\n");
        break;

	    case '8':   
		//sair
		printf("Obrigado e volte sempre!\n");
        break;

        default:
        printf("Opção inválida. Tente novamente.\n");
        break;
        }
		
    } while (escolhaop != '8');

    return 0;
}   