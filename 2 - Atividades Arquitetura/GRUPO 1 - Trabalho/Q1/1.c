#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *malloc_ed(size_t quantidade_espaco)
{
    int *ponteiro[quantidade_espaco]; // vet de ptr  
}


int main()
{
    system("cls");
    
    size_t quanto_de_espaco_a_ser_alocado; // não recebe nº negativo
    int *aponta_vet_ptr;

    printf("\nQuanto de espaco deseja reservar?\n> "); // verificar se é int
    scanf("%zu", &quanto_de_espaco_a_ser_alocado);

    //printf("%zu", quanto_de_espaco_a_ser_alocado);

    aponta_vet_ptr = malloc_ed(quanto_de_espaco_a_ser_alocado);

    printf("\nEXIBINDO OS ENDERECOS DAS MEMORIAS\n");
    for (size_t i = 0; i < quanto_de_espaco_a_ser_alocado; i++)
    {
        printf("\t> %d\n", (aponta_vet_ptr + i)); // espaço memória
            /*
                > 6422224
                > 6422228
                > 6422232
            */
        //printf("\t> %d\n", *aponta_vet_ptr + i);
            /*
                > 6422476
                > 4199121
                > 4199122
            */
        //printf("\t> %d\n", *(aponta_vet_ptr + i));
            /*
                > 2482176
                > 4199120
                > 2482176
            */
        //printf("\t> %d\n", &aponta_vet_ptr + i);
            /*
                > 6422292
                > 6422296
                > 6422300
            */
        //printf("\t> %d\n", &(aponta_vet_ptr[i]));
            /*
                > 6422224
                > 6422228
                > 6422232
            */
    }
    
}