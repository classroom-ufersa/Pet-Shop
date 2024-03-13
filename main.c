#include "animal.h"

int main(void)
{
    Animal *pet;
    int total_de_pets = 0;

    FILE *arquivo_petshop = fopen("arquivo_dados_do_petshop.txt", "w");
     if (arquivo_petshop == NULL)
    {
        printf("Erro ao criar o arquivo\n");
        exit(1);
    }

    add_animal(pet, total_de_pets, arquivo_petshop);

    return 0;
}
    
