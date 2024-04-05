#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.animais/animal.h"
#include "TAD.clientes/cliente.h"

int main(void){
    
    Cliente * lista_clientes = NULL;

     char escolhaop;

    do {
        menu();
        printf("Escolha uma opcao: ");
        escolhaop = ler_opcao('1', '8'); 

        switch (escolhaop) {
        case '1':
        
    	
    	
        break;

        case '2':
        //funçao de remover cliente
		printf("Função indisponivel\n");
        break;

        case '3':
        Animal *novo_animal = add_animal();
        animais = lista_insere_ordenada(animais, novo_animal);   

        imprime_animais(animais, "animais.txt");

		break;

        case '4': 
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
