#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.animais/animal.h"
#include "TAD.clientes/cliente.h"

int main(void){
    
    Cliente * lista_clientes = NULL;
    Lista *animais = NULL;
    char escolhaop;
    int num_clientes;
    lista_clientes = Cliente_ler_arquivo("clientes.txt");
    do {
        menu();
        printf("Escolha uma opcao: ");
        escolhaop = ler_opcao('1', '8'); 
        switch (escolhaop) {
       case '1':
        
        printf("Quantos clientes deseja cadastrar? ");
        scanf("%d", &num_clientes);
        
        for(int i = 0; i< num_clientes; i++){
        adiciona_cliente(&lista_clientes, "clientes.txt");
        }


        break;

        case '2':
        
        remove_cliente(&lista_clientes);
        break;

        case '3':
        printf("\n Cadastro de animal\n");

        Animal *novo_animal = add_animal();
        animais = lista_insere_ordenada(animais, novo_animal);
        printf("Animal adicionado com sucesso!\n");

        imprime_animais(animais, "animais.txt");

		break;

        case '4': 
		remove_animal(&animais);
        imprime_animais(animais, "animais.txt");
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

	    //imprime_animais(animais, "animais.txt");
        //funçao de Buscar Animal por Nome

	    //imprime_animais(animais, "animais.txt");
        //funçao de Buscar Animal por Nome
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