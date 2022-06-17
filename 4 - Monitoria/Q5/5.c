#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    size_t i, j, k;
    int LINHA, COLUNA;
    printf("\n====================================\n\n");
    printf("Quantidade de linhas da matriz: ");
    scanf("%d", &LINHA);
    printf("Quantidade de colunas da matriz: ");
    scanf("%d", &COLUNA);
    printf("\n====================================\n");

//---------------------------------------------------------------------------------------------------

    ////////////////////////
    // FORMAÇÃO DA MATRIZ //
    ////////////////////////

    int matriz[LINHA][COLUNA], matrizT[COLUNA][LINHA], soma = 0, multiplicacao[LINHA][LINHA];

    printf("\n      ELEMENTOS DA MATRIZ\n\n");

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            printf("        M[%d][%d] = ", (i + 1), (j + 1));
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n====================================\n");

//-----------------------------------------------------------------------------------------------------

    ////////////////////////////
    // EXIBIÇÃO DA MATRIZ (M) //
    ////////////////////////////

    printf("\nMATRIZ\n\n");

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n====================================\n");

//-------------------------------------------------------------------------------------------------------

    ///////////////////////////////////////////////////
    // FORMAÇÃO E EXIBIÇÃO DA MATRIZ TRANSPOSTA (MT) //
    ///////////////////////////////////////////////////

    printf("\nMATRIZ TRANSPOSTA\n\n");

    for (i = 0; i < COLUNA; i++)
    {
        for (j = 0; j < LINHA; j++)
        {
            matrizT[i][j] = matriz[j][i];
            printf("%d  ", matrizT[i][j]);
        }
        printf("\n");
    }

    printf("\n====================================\n");

//-------------------------------------------------------------------------------------------------------

    ///////////////////////////////
    // MULTIPLICAÇÃO MT x M (MP) //
    ///////////////////////////////

    for (i = 0; i < COLUNA; i++) // linha de MT
    {
        for (j = 0; j < COLUNA; j++) // coluna M
        {
            multiplicacao[i][j] = 0;
            
            for (k = 0; k < LINHA; k++) // percorre as colunas de MT (em uma mesma linha) e percorre as linhas de M (em uma mesma coluna)
            {
                soma += matriz[k][i] * matrizT[j][k];
            }

            multiplicacao[i][j] = soma;
            soma = 0;          
        }
    }

//-------------------------------------------------------------------------------------------------------

    ///////////////////////////
    // EXIBIÇÃO DA MATRIZ MP //
    ///////////////////////////

    printf("\nMATRIZ TRANSPOSTA x MATRIZ\n\n");

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < LINHA; j++)
        {
            printf("%d  ", multiplicacao[i][j]);
        }
        printf("\n");
    }
    
    printf("\n====================================\n");

//-------------------------------------------------------------------------------------------------------

    printf("> FIM DO PROGRAMA <\n");

    return 0;

}