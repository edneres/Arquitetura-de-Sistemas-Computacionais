#include<stdio.h>
//#include<conio.h> // >> tem que baixar no projeto
#include <stdlib.h>
#include<math.h>

#define SIZE 10

int main()
{
		 float a[SIZE][SIZE];
         int n;

		 //clrscr(); // >> semelhante ao cls no MS DOS
         system("cls");

//-------------------------------------------------------------------------------------------------------

    //////////////
    // ENTRADAS //
    /////////////

    // 1. Ordem de leitura da matriz 
    printf("Digite a ordem da Matriz: ");
    scanf("%d", &n);
    printf("\n");

    // 2. Lendo Matriz
    printf("Insira os coeficientes:\n");
    for(size_t i = 0;i < n;i++)
    {
        for(size_t j = 0;j < n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%f", &a[i][j]);
        }
    }

//-------------------------------------------------------------------------------------------------------

    ////////////////////////////
    // EXIBIÇÃO DA MATRIZ "a" //
    ////////////////////////////

	printf("\nMATRIZ M\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
           printf("%0.3f\t", a[i][j]);
        } 
		printf("\n");
    } 

//-------------------------------------------------------------------------------------------------------

    /////////////////////////////////////////////////////
	// FORMAÇÃO E EXIBIÇÃO DA MATRIZ TRANSPOSTA DE "a" //
    /////////////////////////////////////////////////////

	float aT[n][n];

	printf("\nMATRIZ TRANSPOSTA MT\n");
	for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
			aT[i][j] = a[j][i];
            printf("%0.3f\t", aT[i][j]);
        } 
		printf("\n");
    }

//-------------------------------------------------------------------------------------------------------

    /////////////////////////////////////////////////////////////
	// FORMAÇÃO E EXIBIÇÃO DA MATRIZ RESULTANTE DE "aT x a": P //
    /////////////////////////////////////////////////////////////

    float P[n][n], soma = 0;
    printf("\nMATRIZ P = MT x M\n");
    for (size_t i = 0; i < n; i++) // linha de aT
    {
        for (size_t j = 0; j < n; j++) // coluna de a
        {
            P[i][j] = 0;

            for (size_t k = 0; k < n; k++)
                soma += aT[j][k] * a[k][i];

            P[i][j] = soma;
			printf("%0.3f\t", P[i][j]);
            soma = 0;
        }

        printf("\n");
    } 

//-------------------------------------------------------------------------------------------------------

    double aux1 = 0, aux2 = 0, determinante;
    int cont = 0;

    float iP[SIZE][SIZE]; // recebe os valores da multiplicação (inversa)
    float matriz_aux1[SIZE][SIZE]; // recebe os valores da multiplicação (determinante)
	
	
    for(size_t i = 0; i < n; i++)
	{
		for(size_t j = 0; j < n; j++)
		{
			matriz_aux1[i][j] = P[i][j];
			iP[i][j] = P[i][j];
		}
	}

    ///////////////////////////////////////////////////////////////////
    // TRIANGUULAÇÃO DA "matriz_aux1" PARA O CÁLCULO DO DETERMINANTE //
    ///////////////////////////////////////////////////////////////////

    for(size_t i = 0; i < (n - 1); i++)
    {
        if(matriz_aux1[i][i] == 0)
        {
            for(size_t k = i; k < n; k++)
            {
                if(matriz_aux1[k][i] != 0)
                {
                    for(size_t j = 0; j < n; j++)
                    {
                        aux1 = matriz_aux1[i][j];
                        matriz_aux1[i][j] = matriz_aux1[k][j];
                        matriz_aux1[k][j] = aux1;
                    }
                    k = n;
                }
            }
        	    cont++;
        }

        else
        {
            for(size_t k = (i + 1); k < n; k++)
            {
                aux2 = (-1.0 * matriz_aux1[k][i]) /  matriz_aux1[i][i];

                for(size_t j = i; j < n; j++)
                    matriz_aux1[k][j] = matriz_aux1[k][j] + (aux2 * matriz_aux1[i][j]);
            }
        }
    }

    aux1 = 1.0;

//-------------------------------------------------------------------------------------------------------

    /////////////////////////////
    // CÁLCULO DO DETERMINANTE //
    /////////////////////////////

    for(size_t i = 0; i < n; i++)
        aux1 *= matriz_aux1[i][i];

	determinante = aux1;

    if (determinante == 0)
    {
        printf("\n\n--------------------------------------\n");
        printf("\n        Mathematical Error!\n");
        printf("\nO determinante da matriz P eh 0,logo,\nnao se pode calcular a sua inversa!\n");
        printf("\n----------------------------------------\n");
        printf("\n\n      > FIM DO PROGRAMA < \n\n");

        return 0;
    }
    
    //////////////////////////////
    // PROCESSO DE GAUSS JORDAN //
    //////////////////////////////

	else
	{
		// Aumentando a Matriz de Identidade da Ordem n
		for(size_t i = 0; i < n; i++)
        {
            for(size_t j = 0; j < n;j++)
            {
                if(i==j)
                    iP[i][j+n] = 1;
                else
                    iP[i][j+n] = 0;
            }
        }

		float ratio; 

		// Aplicando a Eliminação de Gauss Jordan
		for(size_t i = 0; i < n; i++)
		{
			if(iP[i][i] == 0.0)
			{	
                printf("           Mathematical Error!\n");
                printf("\nNao eh pode calcular a inversa da matriz P!\n");
                printf("\n----------------------------------------\n");
                printf("\n\n       > FIM DO PROGRAMA < \n\n");

                return 0;
            }

			for(size_t j = 0; j < n; j++)
			{
				if(i != j)
				{
					ratio = iP[j][i] / iP[i][i];
					for(size_t k = 0; k < (2 * n); k++)
						iP[j][k] = iP[j][k] - (ratio * iP[i][k]);
				}
			}
		}

		// Operação de linha para fazer a diagonal principal em 1
		for(size_t i = 0; i < n; i++)
		{
			for(size_t j = n; j < (2 * n); j++)
			    iP[i][j] = iP[i][j] / iP[i][i];
		}

        /////////////////////////////////////
		// EXIBIÇÃO DA MATRIZ INVERSA "iP" //
        /////////////////////////////////////

		printf("\nMATRIZ INVERSA DE P (iP)\n");
		for(size_t i = 0; i < n; i++)
		{
			for(size_t j = n; j < (2 * n); j++)
				printf("%.3f\t", iP[i][j]);

			printf("\n");
		}
	}

//-------------------------------------------------------------------------------------------------------

    float aT_aux[SIZE][SIZE]; // "aT_aux" recebe os valores de "aT"

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
            aT_aux[i][j] = aT[i][j];
    }

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = n; j < (2 * n); j++)
            aT_aux[i][j] = aT_aux[i][j - n];
    }

    //////////////////////////////////////////////////
    // MULTIPLICAÇÃO DAS MATRIZES iP E MT (iP x MT) //
    //////////////////////////////////////////////////

    printf("\nMATRIZ iP x MT\n");

    float iP_x_MT[SIZE][SIZE],  soma2 = 0;

    for (size_t i = 0; i < n; i++) // linha de iP
    {
        for (size_t j = n; j < (2 * n); j++) // coluna MT
        {
            iP_x_MT[i][j] = 0;
            
            for (size_t k = 0; k < n; k++) // percorre as colunas de iP (em uma mesma linha) e percorre as linhas de MT (em uma mesma coluna)
            {
                soma2 += iP[i][k + n] * aT_aux[k][j];
            }

            iP_x_MT[i][j] = soma2;
            soma2 = 0;          
        }
    }

    //////////////////////////////////
    // EXIBIÇÃO DA MATRIZ "iP_x_MT" //
    //////////////////////////////////

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = n; j < (2 * n); j++)
        {
            printf("%0.3f\t", iP_x_MT[i][j]);
        }
        printf("\n");
    }

//-------------------------------------------------------------------------------------------------------

    printf("\n\n> FIM DO PROGRAMA < \n\n\n");

	//getch();

	return(0);
}