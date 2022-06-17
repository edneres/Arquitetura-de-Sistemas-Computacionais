#include <stdio.h>
#include <string.h>

int main()
{
    char nome1[100];
    char nome2[100];

    gets(nome1);
    gets(nome2);
    printf("\n");
    puts(nome1);
    puts(nome2);

    //nome1 = "Beatriz"; // ERRO:  a expressão deve ser um lvalue modificável
    //nome1 = nome2; // ERRO:  a expressão deve ser um lvalue modificável

    strcat(nome1, nome2);

    puts(nome1);
    puts(nome2);



    if (strcmp(nome1, nome2) == 0)
        printf("Iguais!\n");

    else
        printf("\aDiferentes!\n");
 

/*
    printf("O nome %s tem %d letras.", nome1, strlen(nome1));
*/
    return 0;
}