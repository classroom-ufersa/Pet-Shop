#include "animal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../TAD.clientes/cliente.h"
#include <ctype.h>

void limpabuffer()
{
    fflush(stdin);
}

Lista *lista_animais(void)
{
    return NULL;
}

Lista *lista_insere_ordenada(Lista *l, Animal *novo_animal)
{
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = l;

    novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("Erro, memoria insuficiente!");
        exit(1);
    }

    novo->animal = novo_animal;
    novo->proximo = NULL;

    while (p != NULL && strcmp(p->animal->nome_animal, novo_animal->nome_animal) < 0)
    {
        ant = p;
        p = p->proximo;
    }

    if (ant == NULL)
    {
        novo->proximo = l;
        l = novo;
    }
    else
    {
        novo->proximo = ant->proximo;
        ant->proximo = novo;
    }

    return l;
}

int lista_vazia(Lista *l)
{
    return (l == NULL);
}

Animal *add_animal2(Cliente *lista_clientes, char *nome_animal, char *especie, char *saude, int id_animal) {
    Animal *pet = (Animal *)malloc(sizeof(Animal));

    if (pet == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    printf("\nInforme os dados do animal!\n");
    printf("\nDigite o nome do animal:\n ");

    int valido_nome = 1;
    do {
        scanf(" %[^\n]", pet->nome_animal);
        valido_nome = 1;
        for (int i = 0; pet->nome_animal[i] != '\0'; i++) {
            if (!isalpha(pet->nome_animal[i]) && pet->nome_animal[i] != ' ') {
                valido_nome = 0;
                printf("\nNome inválido, tente novamente:\n");
                printf("\nDigite o nome do animal:\n ");
                break;
            }
        }
    } while (!valido_nome);

    printf("\nDigite a espécie do animal:\n ");
    int valido_especie = 1;
    do {
        scanf(" %[^\n]", pet->especie);
        valido_especie = 1;
        for (int i = 0; pet->especie[i] != '\0'; i++) {
            if (!isalpha(pet->especie[i]) && pet->especie[i] != ' ') {
                valido_especie = 0;
                printf("\nEspécie inválida, tente novamente:\n");
                printf("\nDigite a espécie do animal:\n ");
                break;
            }
        }
    } while (!valido_especie);

    printf("\nDigite o estado de saúde do animal:\n ");
    int valido_saude = 1;
    do {
        scanf(" %[^\n]", pet->saude);
        valido_saude = 1;
        for (int i = 0; pet->saude[i] != '\0'; i++) {
            if (!isalpha(pet->saude[i]) && pet->saude[i] != ' ') {
                valido_saude = 0;
                printf("\nEstado de saúde inválido, tente novamente:\n");
                printf("\nDigite o estado de saúde do animal:\n ");
                break;
            }
        }
    } while (!valido_saude);

    printf("\nDigite o ID do animal:\n ");
    int valido_id = 1;
    do {
        valido_id = 1;
        if (scanf(" %d", &pet->id_animal) != 1) {
            valido_id = 0;
            printf("\nID inválido, tente novamente:\n");
            printf("\nDigite o ID do animal:\n ");
            while (getchar() != '\n');
        }
    } while (!valido_id);

    printf("Nome do cliente ao qual deve-se associar este animal: ");
    char nome_cliente[50];
    scanf(" %[^\n]", nome_cliente);

    Cliente *cliente_associado = Lista_busca(nome_cliente, lista_clientes);
    if (cliente_associado == NULL) {
        printf("Cliente não encontrado!");
        return NULL;
    } else {
        pet->cliente_associado = cliente_associado;
        printf("Cliente cadastrado com sucesso! ");
        atualiza_cliente_arquivo(nome_cliente, pet->id_animal, pet->nome_animal, pet->especie, pet->saude);
    }
    return pet;
}


Animal *add_animal(Cliente *lista_clientes)
{
    Animal *pet = (Animal *)malloc(sizeof(Animal));

    if (pet == NULL)
    {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    printf("\n");
    printf("Informe os dados do animal!\n");
    printf("\n");
    printf("Digite o nome do animal:\n ");

    int valido_nome = 1;
    do
    {
        scanf(" %[^\n]", pet->nome_animal);
        valido_nome = 1;
        for (int i = 0; pet->nome_animal[i] != '\0'; i++)
        {
            if (!isalpha(pet->nome_animal[i]) && pet->nome_animal[i] != ' ')
            {
                valido_nome = 0;
                printf("\nNome invalido, tente novamente:\n");
                printf("\nDigite o nome do animal:\n ");
                break;
            }
        }
    } while (!valido_nome);

    printf("\nDigite a especie do animal:\n ");
    int valido_especie = 1;
    do
    {
        scanf(" %[^\n]", pet->especie);
        valido_especie = 1;
        for (int i = 0; pet->especie[i] != '\0'; i++)
        {
            if (!isalpha(pet->especie[i]) && pet->especie[i] != ' ')
            {
                valido_especie = 0;
                printf("\nEspecie invalida, tente novamente:\n");
                printf("\nDigite a especie do animal:\n ");
                break;
            }
        }
    } while (!valido_especie);

    printf("\nDigite o estado de saude do animal:\n ");
    int valido_saude = 1;
    do
    {
        scanf(" %[^\n]", pet->saude);
        valido_saude = 1;
        for (int i = 0; pet->saude[i] != '\0'; i++)
        {
            if (!isalpha(pet->saude[i]) && pet->saude[i] != ' ')
            {
                valido_saude = 0;
                printf("\nEstado de saude invalido, tente novamente:\n");
                printf("\nDigite o estado de saude do animal:\n ");
                break;
            }
        }
    } while (!valido_saude);

    printf("\nDigite o ID do animal:\n ");
    int valido_id = 1;
    do
    {
        valido_id = 1;
        if (scanf(" %d", &pet->id_animal) != 1)
        {
            valido_id = 0;
            printf("\nID invalido, tente novamente:\n");
            printf("\nDigite o ID do animal:\n ");
            while (getchar() != '\n')
                ;
        }
    } while (!valido_id);

    printf("Nome do cliente ao qual deve-se associar este animal: ");
    char nome_cliente[50];
    scanf(" %[^\n]", nome_cliente);

    Cliente *cliente_associado = Lista_busca(nome_cliente, lista_clientes);
    if (cliente_associado == NULL)
    {
        printf("Cliente nao encontrado!");
        return NULL;
    }

    else
    {
        pet->cliente_associado = cliente_associado;
        printf("Cliente cadastrado com sucesso! ");
        atualiza_cliente_arquivo(nome_cliente, pet->id_animal, pet->nome_animal, pet->especie, pet->saude);

    return pet;
}

}
    
Animal *cadastra_animal(int num_animal, Cliente *lista_clientes){

    Animal *pet = (Animal *)malloc(num_animal * sizeof(Animal));

    if (pet == NULL)
    {
        printf("Erro ao alocar memoria! ");
        exit(1);
    }

    for (int i = 0; i < num_animal; i++)
    {
        pet[i] = *add_animal(lista_clientes);
    }
    return pet;
}

void menu()
{
    printf("\n------Menu de Opcoes------\n");
    printf("\n");
    printf("1. Adicionar Cliente\n");
    printf("2. Remover Cliente\n");
    printf("3. Adicionar Animal\n");
    printf("4. Remover Animal\n");
    printf("5. Editar Cadastro de Animal\n");
    printf("6. Buscar Animal por Nome\n");
    printf("7. Listar Clientes e Animais\n");
    printf("8. Sair\n");
    printf("\n--------------------------\n");
}

char ler_opcao(char menor_valor, char maior_valor)
{
    char escolhaop;
    char entrada[100];

    do
    {
        scanf(" %[^\n]", entrada);

        escolhaop = entrada[0];

        if (escolhaop >= menor_valor && escolhaop <= maior_valor && strlen(entrada) == 1)
        {
            return escolhaop;
        }
        else
        {
            printf("Opcao invalida. A opcao deve estar entre %c e %c: ", menor_valor, maior_valor);
        }
    } while (1);
}

void imprime_animais(Lista *animal, const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    fprintf(arquivo, "Animais cadastrados:\n");

    while (animal != NULL)
    {
        fprintf(arquivo, "Nome: %s\n", animal->animal->nome_animal);
        fprintf(arquivo, "Especie: %s\n", animal->animal->especie);
        fprintf(arquivo, "Saude: %s\n", animal->animal->saude);
        fprintf(arquivo, "ID: %d\n", animal->animal->id_animal);
        fprintf(arquivo, "\n");

        animal = animal->proximo;
    }

    fclose(arquivo);
    printf("\nDados dos animais foram impressos no arquivo %s.\n", nome_arquivo);
}

void remove_animal(Lista **lista_animal){
    int id_remover;

    printf("ID do animal que deseja remover:\n");
    scanf(" %d", &id_remover);

    // Busca o animal na lista
    Lista *ant = NULL;
    Lista *p = *lista_animal;

    while (p != NULL && p->animal->id_animal != id_remover) {
        ant = p;
        p = p->proximo;
    }

    // Se não encontrou o animal na lista
    if (p == NULL) {
        printf("Animal nao encontrado!\n");
        return;
    }

    // Remove o animal da lista
    if (ant == NULL)
        *lista_animal = p->proximo;
    else
        ant->proximo = p->proximo;

    free(p);
    printf("Animal removido com sucesso!\n");
}

Lista *lista_busca_animal(char nome[], Lista *l)
{
    Lista *p;

    for (p = l; p != NULL; p = p->proximo)
    {
        if (strcmp(p->animal->nome_animal, nome) == 0)
            return p;
    }

    return NULL;
}

void lista_edita_animal(Lista *animal, int id_alvo)
{
    Lista *temp = animal;

    while (temp != NULL && temp->animal->id_animal != id_alvo)
    {
        temp = temp->proximo;
    }

    if (temp != NULL)
    {

        printf("Digite o novo nome do animal:\n");
        scanf(" %[^\n]", temp->animal->nome_animal);

        printf("Digite a nova especie do animal:\n");
        scanf(" %[^\n]", temp->animal->especie);

        printf("Digite o novo estado de saude do animal:\n");
        scanf(" %[^\n]", temp->animal->saude);

        printf("Edição concluida com sucesso.\n");
    }
    else
    {
        printf("Animal com ID %s nao encontrado na lista.\n", id_alvo);
    }
}

void imprime_animais_editado(Lista *lista)
{
    printf("Lista de animais apos a ediçao:\n");

    if (lista == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    while (lista != NULL)
    {
        printf("Nome: %s, Especie: %s, Saude: %s, ID: %d\n", lista->animal->nome_animal, lista->animal->especie, lista->animal->saude, lista->animal->id_animal);
        lista = lista->proximo;
    }
}

void atualiza_cliente_arquivo(const char *nome_cliente, int id_animal, const char *nome_animal, const char *especie, const char *saude) {
    FILE *arquivo_entrada = fopen("clientes.txt", "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        return;
    }

    FILE *arquivo_saida = fopen("clientes_temp.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo temporário clientes_temp.txt\n");
        fclose(arquivo_entrada);
        return;
    }

    char linha[1000];
    int encontrado = 0;

    // Percorre o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo_entrada) != NULL) {
        // Verifica se a linha contém o nome do cliente
        if (strstr(linha, nome_cliente) != NULL) {
            // Adiciona as informações do animal associado à linha do cliente
            fprintf(arquivo_saida, "%s Animal: %s/ Especie: %s/ Saude: %s/ ID Animal: %d\n", linha, nome_animal, especie, saude, id_animal);
            encontrado = 1;
        } else {
            // Escreve a linha original no arquivo temporário
            fprintf(arquivo_saida, "%s", linha);
        }
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    // Remove o arquivo original
    remove("clientes.txt");

    // Renomeia o arquivo temporário para o nome original
    if (rename("clientes_temp.txt", "clientes.txt") != 0) {
        printf("Erro ao renomear o arquivo temporário\n");
        return;
    }

    if (!encontrado) {
        printf("Cliente não encontrado no arquivo clientes.txt\n");
    } else {
        printf("Associação entre cliente e animal atualizada com sucesso no arquivo clientes.txt\n");
    }
}