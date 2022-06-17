#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct PES
{
    char PE; // próximo estado
    int S;  // saída
};


int main()
{
    system("cls");
    int num_estados, num_entradas, num_saidas;
    char aux;

// -----------------------------------------------------------------------------------------------------------------

    ///////////////////////////////////////////////////////////
    // CAPTURA DOS DADOS PARA A FORMAÇÃO DA TABELA DE ESTADOS//
    ///////////////////////////////////////////////////////////

    printf("=============================\n\n");
    printf("Numero de estados:  ");
    scanf("%d", &num_estados);
    printf("Numero de entradas: ");
    scanf("%d", &num_entradas);
    printf("Numero de saidas:   ");
    scanf("%d", &num_saidas);
    fflush(stdin);
    printf("\n===========================\n\n");

// -----------------------------------------------------------------------------------------------------------------

    //////////////////////////////////
    // FORMAÇÃO DA TABELA DE ESTADOS//
    //////////////////////////////////

    struct PES Tabela[num_estados][num_entradas];

    for (size_t i = 0; i < num_estados; i++)
    {
        printf("\tESTADO %c\n\n", (i + 65));

        for (size_t j = 0; j < num_entradas; j++)
        {
            printf("> ENTRADA %c <\n", (j + 97));   
            printf("\tProximo estado: ");
            scanf(" %c", &(Tabela[i][j].PE));
            fflush(stdin);
            printf("\tSaida: ");
            scanf("%d", &(Tabela[i][j].S));
            printf("\n");
        }

        if ((i + 1) == num_estados)
            continue;

        printf("\n---------------------------\n\n"); 
    }  

    printf("\n===========================\n\n");

// -----------------------------------------------------------------------------------------------------------------

    /////////////////
    // 1ª PARTIÇÃO //
    /////////////////

    for (size_t i = 0; i < num_estados; i++)
    {
        for (size_t j = 0; j < num_entradas; i++)
        {
            
        }     
    }
    


    return 0;
}