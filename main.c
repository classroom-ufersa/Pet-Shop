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
        Animal *novo_animal = cadastra_animal(1, lista_clientes);
        animais = lista_insere_ordenada(animais, novo_animal);
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
		printf("Digite o nome do animal que deseja buscar: ");
        char nome_animal[80];
        scanf(" %[^\n]", nome_animal);

        Lista *animal_encontrado = lista_busca_animal(nome_animal, animais);

        if (animal_encontrado != NULL) {
            printf("Animal encontrado:\n");
            printf("Nome: %s\n", animal_encontrado->animal->nome);
            printf("Especie: %s\n", animal_encontrado->animal->especie);
            printf("Saude: %s\n", animal_encontrado->animal->saude);
        } else {
        printf("Animal nao encontrado.\n");
        }
        break;

	    case '7': 

        listar_clientes("clientes.txt");

	    //imprime_animais(animais, "animais.txt");
        //funçao de Buscar Animal por Nome

	    //imprime_animais(animais, "animais.txt");
        //funçao de Buscar Animal por Nome
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