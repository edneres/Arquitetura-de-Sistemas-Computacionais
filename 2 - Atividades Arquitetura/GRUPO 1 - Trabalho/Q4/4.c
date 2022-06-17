#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 50

int linhas()
{ 
	int linha;

	printf("> Quantidade de linhas da matriz: ");
	scanf("%d", &linha);

	while (linha <= 0)
	{
		printf("\tValor invalido!\n");
		printf("> Quantidade de linhas da matriz: ");
		scanf("%d", &linha);
	}
	
	return linha;
}

int valor_F()
{ 
	int F;

	printf("> Digite o valor de F (F > 0): ");
	scanf("%d", &F);

	while (F <= 0)
	{
		printf("\tValor invalido!\n");
		printf("> Digite o valor de F (F > 0): ");
		scanf("%d", &F);
	}

	return F;
}

int valor_A()
{
	int A;

	printf("> Digite o valor de A (A >= 0): ");
	scanf("%d", &A);

	while (A < 0)
	{
		printf("\tValor invalido!\n");
		printf("> Digite o valor de A (A >= 0): ");
		scanf("%d", &A);
	}
	
	return A;
}

int main()
{
	system("cls");

	size_t i, j, k;
	int linha, F, A, aux, deslocamento, indice = 0;
	int X[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; // É preciso inicializar os vetores X e Y com os valores pré definidos a fim de evitar o "lixo de memória", deixando o comportamento do código indefinido!
	int Y[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; 
	int x_aux[TAM][TAM]; // recebe o vetor X alterado
	int y_aux[TAM][TAM]; // recebe o vetor Y alterado
	int M[TAM][TAM];     // recebe a junção da matriz "x_aux" e da matriz "y_aux"

	linha = linhas();
	F = valor_F();
	A = valor_A();

// -----------------------------------------------------------------------------------------------------------------

	//////////////////////////////
	// FORMAÇÃO DA MATRIZ y_aux //
	//////////////////////////////

	for (deslocamento = 0, i = 0; deslocamento <= linha; deslocamento ++, i++)
	{ 
		for (aux = F, j = 0; aux >= 0; aux --, j++)
			y_aux[i][j] = Y[aux + deslocamento]; // "y_aux" recebe os valores de Y de acordo com o valor de F
	}

// -----------------------------------------------------------------------------------------------------------------

	//////////////////////////
	// EXIBIÇÃO DA MATRIZ Y //
	//////////////////////////

	printf("\n\nMATRIZ Y \n");
	for (i = 0; i < linha; i++)
	{
		for (j = 0; j < (F + 1); j++)
			printf("%d   ",  y_aux[i][j]);

		printf("\n");
	}

// -----------------------------------------------------------------------------------------------------------------

	//////////////////////////////
	// FORMAÇÃO DA MATRIZ x_aux //
	//////////////////////////////

	for (deslocamento = 0, i = 0; deslocamento <= linha; deslocamento ++, i++) 
	{ 
		for (aux = A, j = 0 ; aux >= 0; aux --, j++)
			x_aux[i][j] = X[aux + deslocamento]; // "x_aux" recebe os valores de X de acordo com o valor de A
	}

// -----------------------------------------------------------------------------------------------------------------

	//////////////////////////
	// EXIBIÇÃO DA MATRIZ X //
	//////////////////////////

	printf("\n\nMATRIZ X\n");
	for (i = 0; i < linha; i++)
	{
		for (j = 0; j < (A + 1); j++)
			printf("%d   ",  x_aux[i][j]);

		printf("\n");
	}

// -----------------------------------------------------------------------------------------------------------------

	////////////////////////////////
	// FORMAÇÃO DA MATRIZ FINAL M //
	////////////////////////////////

	for (i = 0; i < linha; i++)
	{ 
		for (j = 0; j < (F + 1); j++)
			M[i][j] = y_aux[i][j]; //Atribui os valores da matriz y para as primeriras colunas da matriz M.
	}
	
	for (i = 0; i < linha; i++)
	{
		for (j = (F + 1), k = 0; j < (F + A + 2), k < (A + 1); j++, k++)
			M[i][j] = x_aux[i][k]; //Atribui os valores da matriz x para a matriz M, ao lado dos valores da matriz y j� inseridos anteriormente.
	}

// -----------------------------------------------------------------------------------------------------------------

	//////////////////////////
	// EXIBIÇÃO DA MATRIZ M //
	//////////////////////////

	printf("\n\nMATRIZ M\n");
	for (i = 0; i < linha; i++)
	{
		for (j = 0; j < (F + A + 2); j++)
			printf("%d   ", M[i][j]); //Imprime as duas matrizes lado a lado

		printf("\n");
	}

// -----------------------------------------------------------------------------------------------------------------

	printf("\n\n> FIM DO PROGRAMA <\n\n");

	return 0;
}