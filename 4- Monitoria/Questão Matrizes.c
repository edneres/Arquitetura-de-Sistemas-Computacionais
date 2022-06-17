//////////////
// EDIVÂNIA //
//   UFPI   //
//   2022   //
//////////////

/*
    Faça um programa que leia uma Matriz[l][c] de inteiros e que calcule para o usário:
        a) A trasnposta.
        b) O seu determinante, se for uma matriz 2x2, da matriz original e da sua trasposta.

    OBS: utilize no mínimo duas funções.
*/

#include <stdio.h>

void calcular_trasnposta(int l, int c, int MT[l][c], int M[l][c])
{
    size_t i, j;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            MT[i][j] = M[j][i];
        }
    }      
}

int calcular_determinante(int M[2][2])
{  
    size_t i, j;
    int aux1 = 1, aux2 = 1, det;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {   
            if ((i == 0 && j == 0) || (i == 1 && j == 1)) // diagonal principal (00 e 11)
            {
                aux1 *= M[i][j];
            }
                      
            else
                aux2 *= M[i][j]; // diagonal secundária (01 e 10)
        }
    }

    return det = aux1 - aux2;
}

int main()
{
    size_t i, j;
    int l, c;

    printf("\n====================================\n\n");
    printf("Quantidade de linhas da matriz: ");
    scanf("%d", &l);
    printf("Quantidade de colunas da matriz: ");
    scanf("%d", &c);
    printf("\n====================================\n\n");

//---------------------------------------------------------------------------------------------------

    ////////////////////////
    // FORMAÇÃO DA MATRIZ //
    ////////////////////////

    int Matriz[l][c], MatrizT[l][c];

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("M[%d][%d] = ", (i+1), (j+1));
            scanf("%d", &Matriz[i][j]);
        }
    }
    
//-----------------------------------------------------------------------------------------------------

    ////////////////////////////
    // EXIBIÇÃO DA MATRIZ (M) //
    ////////////////////////////

    printf("\nMATRIZ M\n");

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", Matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n====================================\n");

//-----------------------------------------------------------------------------------------------------

    ///////////////////////////////////////////////////
    // FORMAÇÃO E EXIBIÇÃO DA MATRIZ TRANSPOSTA (MT) //
    ///////////////////////////////////////////////////

    calcular_trasnposta(l, c, MatrizT, Matriz);

    printf("\nMATRIZ TRANSPOSTA\n");

    for (i = 0; i < c; i++)
    {
        for (j = 0; j < l; j++)
        {
            printf("%d  ", MatrizT[i][j]);
        }  
        printf("\n");  
    }
    
    printf("\n====================================\n");

//-----------------------------------------------------------------------------------------------------

    /////////////////////////////
    // CÁLCULO DO DETERMINATE  //
    /////////////////////////////

    if (l == 2 && c == 2)
    {
        int det1, det2;

        det1 = calcular_determinante(Matriz);
        det2 = calcular_determinante(MatrizT);

        printf("\nO determinante da matriz M eh: %d\n", det1);
        printf("\nO determinante da matriz MT eh: %d\n", det2);

        printf("\n====================================\n");
    }

    else
    {
        printf("\n\tFIM DO PROGRAMA\n");

        printf("\n====================================\n");   
    }

//-----------------------------------------------------------------------------------------------------
    return 0;
}