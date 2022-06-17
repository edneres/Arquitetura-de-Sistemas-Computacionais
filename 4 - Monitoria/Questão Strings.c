//////////////
// EDIVÂNIA //
//   UFPI   //
//   2022   //
//////////////

/*
    > Faça um programa que leia duas palavras de no máximo 29 caracteres e determina se 
    a segunda é um anagrama da primeira. 
    > Uma palavra é um anagrama de outra se as duas possuem a mesma quantidade de letras e todas as letras de uma ocorrem na outra, 
    independentemente da posição. 
    > Exemplos: AMOR, MORA, ORAM, AMOR, RAMO são anagramas entre si. 
    > Atenção: você deve implementar e usar adequadamente pelo menos mais uma função além do main
*/

#include <stdio.h>
#include <string.h>
#define TAM 29

int ehAnagrama(char v1[], char v2[])
{ 
    size_t i, j;

    // ordenação lexografica usando o código ASCII
    int aux;
    
    for ( i = 0; i < strlen(v1); i++)
    {
        for ( j = i + 1; j < strlen(v1); j++)
        {
            if (v1[i] > v1[j]) // crescente (EDCBA >> ABCDE)
            {
                aux = v1[i];
                v1[i] = v1[j];
                v1[j] = aux;
            }        
        }   
    }  

    for ( i = 0; i < strlen(v2); i++)
    {
        for ( j = i + 1; j < strlen(v2); j++)
        {
            if (v2[i] > v2[j]) // crescente (EDCBA >> ABCDE)
            {
                aux = v2[i];
                v2[i] = v2[j];
                v2[j] = aux;
            }        
        }   
    }  

    // Comparação entre os dois vetores após a ordenação
    if (strcmp(v1, v2) == 0)
        return 1;
    
    else
        return 0;
}

int main()
{
    char palavra1[TAM], palavra2[TAM],p1[TAM], p2[TAM];

    printf("\nDigite a primeira palavra: ");
    gets(palavra1);
    printf("Digite a segunda palavra: ");
    gets(palavra2);

    printf("\n");

    strcpy(p1, palavra1);
    strcpy(p2, palavra2);

    if (ehAnagrama(palavra1, palavra2) == 0)
        printf("<%s> NAO EH ANAGRAMA de <%s>\n\n", p1, p2);
    
    else
        printf("<%s> EH ANAGRAMA de <%s>\n\n", p1, p2);

    return 0;
}