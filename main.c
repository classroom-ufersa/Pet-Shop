#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TAD.animais/animal.h"
#include "./TAD.clientes/cliente.h"

void salvarDados(Cliente *listaClientes) {
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Cliente *clienteAtual = listaClientes;
    while (clienteAtual != NULL) {
        fprintf(arquivo, "Cliente:\n");
        fprintf(arquivo, "  Nome: %s\n", clienteAtual->nome);
        fprintf(arquivo, "  Endereco: %s\n", clienteAtual->endereco);
        fprintf(arquivo, "  Telefone: %s\n", clienteAtual->telefone);

        Animal *animalAtual = clienteAtual->animais;
        if (animalAtual == NULL) {
            fprintf(arquivo, "  Nenhum animal cadastrado.\n");
        } else {
            fprintf(arquivo, "  Animais:\n");
            while (animalAtual != NULL) {
                fprintf(arquivo, "    - Nome: %s, Especie: %s, Saude: %s\n", animalAtual->nome, animalAtual->especie, animalAtual->saude);
                animalAtual = animalAtual->prox;
            }
        }

        fprintf(arquivo, "\n");

        clienteAtual = clienteAtual->prox;
    }

    fclose(arquivo);
}

// Função para carregar os dados de um arquivo texto
void carregarDados(Cliente **listaClientes) {
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de dados nao encontrado ou erro ao abrir o arquivo.\n");
        return;
    }

    char linha[200];
    Cliente *clienteAtual = NULL; 
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strncmp(linha, "Cliente:", 8) == 0) {
            clienteAtual = (Cliente *)malloc(sizeof(Cliente));
            if (clienteAtual == NULL) {
                printf("Erro ao alocar memoria para o cliente.\n");
                fclose(arquivo);
                return;
            }

            fgets(linha, sizeof(linha), arquivo); 
            sscanf(linha, "  Nome: %[^\n]", clienteAtual->nome);

            fgets(linha, sizeof(linha), arquivo); 
            sscanf(linha, "  Endereco: %[^\n]", clienteAtual->endereco);

            fgets(linha, sizeof(linha), arquivo); 
            sscanf(linha, "  Telefone: %[^\n]", clienteAtual->telefone);

            clienteAtual->animais = NULL;
            clienteAtual->prox = NULL;

            if (*listaClientes == NULL) {
                *listaClientes = clienteAtual;
            } else {
                Cliente *atual = *listaClientes;
                Cliente *anterior = NULL;

                while (atual != NULL && strcmp(clienteAtual->nome, atual->nome) > 0) {
                    anterior = atual;
                    atual = atual->prox;
                }

                if (anterior == NULL) {
                    clienteAtual->prox = *listaClientes;
                    *listaClientes = clienteAtual;
                } else {
                    anterior->prox = clienteAtual;
                    clienteAtual->prox = atual;
                }
            }
        } else if (strncmp(linha, "    - Nome:", 11) == 0 && clienteAtual != NULL) {
            Animal *novoAnimal = (Animal *)malloc(sizeof(Animal));
            if (novoAnimal == NULL) {
                printf("Erro ao alocar memoria para o animal.\n");
                fclose(arquivo);
                return;
            }

            sscanf(linha, "    - Nome: %[^\n], Especie: %[^\n], Saude: %[^\n]", 
                    novoAnimal->nome, novoAnimal->especie, novoAnimal->saude);

            novoAnimal->prox = NULL;

            if (clienteAtual->animais == NULL) {
                clienteAtual->animais = novoAnimal;
            } else {
                Animal *atual = clienteAtual->animais;
                while (atual->prox != NULL) {
                    atual = atual->prox;
                }
                atual->prox = novoAnimal;
            }
        }
    }

    fclose(arquivo);
}

int main() {
    Cliente *listaClientes = NULL;
    carregarDados(&listaClientes);
    int validar;

    int opcao;
    do {
        do{
            printf("\n--- Menu ---\n");
            printf("1. Adicionar cliente\n");
            printf("2. Remover cliente\n");
            printf("3. Adicionar animal\n");
            printf("4. Remover animal\n");
            printf("5. Editar cadastro de animal\n");
            printf("6. Buscar animal por nome\n");
            printf("7. Listar clientes e seus respectivos animais\n");
            printf("8. Sair\n");
            printf("Escolha uma opcao: ");
            validar = scanf("%d", &opcao);

            if(validar != 1 || opcao < 1 || opcao > 8){
                printf("Opcao invalida, digite novamente.\n");
                while(getchar() != '\n');
            }
        }while(validar != 1 || opcao < 1 || opcao > 8);

        switch (opcao) {
            case 1:
                adicionarCliente(&listaClientes);
                salvarDados(listaClientes);
                break;
            case 2:
                removerCliente(&listaClientes);
                salvarDados(listaClientes);
                break;
            case 3:
                adicionarAnimal(listaClientes);
                salvarDados(listaClientes);
                break;
            case 4:
                removerAnimal(listaClientes);
                salvarDados(listaClientes);
                break;
            case 5:
                editarAnimal(listaClientes);
                salvarDados(listaClientes);
                break;
            case 6: {
                Animal *animal = buscarAnimalPorNome(listaClientes);
                if (animal != NULL) {
                    printf("Animal encontrado - Nome: %s, Especie: %s, Saude: %s\n", animal->nome, animal->especie, animal->saude);
                } else {
                    printf("Animal nao encontrado.\n");
                }
                break;
            }
            case 7:
                listarClientes(listaClientes);
                break;
            case 8:
                printf("Obrigado e volte sempre!\n");
                break;
            default:
                printf("Opcao invalida. Por favor, Tente novamente.\n");
        }
    } while (opcao != 8);

    liberarMemoria(listaClientes);

    return 0;
}