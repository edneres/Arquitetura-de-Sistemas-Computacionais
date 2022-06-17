/*
    > Média de um conjunto de números
    > Duas versões do programa
        >> Única modificação: completar a lacuna indicada
        >> Vetor de números REAIS (float)
        >> VERSÃO 1: float calculaMedia1(float v[], int tam) .: retorna a média
        >> VERSÃO 2: void calculaMedia2(float v[], int tam, float *media) 
*/

#include <stdio.h>
#define TAM 5 // retirar, após os testes, esse define 

//////////////
// VERSÃO 1 //
//////////////

float calculaMedia1(float v[], int tam)
{
    size_t i;
    float media = 0;

    for (i = 0; i < tam; i++)
        media += v[i];

    media = media/tam;
    
    return media; // return media/tam;
}

int main()
{
    float vet[TAM]; // 400
    float media = 0;
    int i;
    printf("Digite os 400 numeros ");
    for (i = 0; i < TAM; i++) // 400
        scanf("%f", &vet[i]);

    // ----------------------------------

    media = calculaMedia1(vet, TAM); // 400

    // ----------------------------------

    printf("Media: %.2f\n", media);


    return 0;
}

/*
//////////////
// VERSÃO 2 //
//////////////

void calculaMedia2(float v[], int tam, float *media) 
{
    size_t i;
    float aux = 0;
    
    for (i = 0; i < tam; i++)
        *media += v[i];

    *media = *media/tam;
}

int main()
{
    float vet[TAM]; // 400
    float media = 0;
    int i;
    printf("Digite os 400 numeros ");
    for (i = 0; i < TAM; i++) // 400
        scanf("%f", &vet[i]);

    // ----------------------------------

    float *pt_media = &media;

    calculaMedia2(vet, TAM, pt_media); // 400 // calculaMedia2(vet, TAM, &media);

    // ----------------------------------

    printf("Media: %.2f\n", media);

    return 0;
}
*/