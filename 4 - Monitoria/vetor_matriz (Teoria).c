#include <stdio.h>
#define tamanho1 3
#define tamanho2 3


int main()
{
    size_t i, j;

    char vetor_nome[tamanho1];
    int matriz[tamanho1][tamanho2];

    ////////////////////////////////////////////
    // Modos de captura e impressão de string //
    ////////////////////////////////////////////

/*
    scanf("%s:%s", vetor_nome);
    printf("%s", vetor_nome);
*/

/*
    gets(vetor_nome);
    puts(vetor_nome);
*/



    //////////////////////////////////////////////
    // Captura e impressão de dados em matrizes //
    //////////////////////////////////////////////
    
    for (i = 0; i < tamanho1; i++)
    {    
        for (j = 0; j < tamanho2; j++)
        {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }  
    }

    printf("\n");

    for (i = 0; i < tamanho1; i++)
    {    
        for (j = 0; j < tamanho2; j++)
            printf("%d  ", matriz[i][j]);

        printf("\n");
    }



    ///////////////////////////////////////
    // Manipulação de vetores de strings //
    ///////////////////////////////////////
/*
    // Construir a solução
*/


    return 0;
}