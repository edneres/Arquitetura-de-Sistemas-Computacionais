/*
    > 100 questões (1 ponto cada)
        >> 5 alternativas (ex: a, b, c, d, e)
    > 25 candidatos
    > Informar quantos candidatos acertaram mais de 90 questões (90 > 100/2)
    > Não é necessário validar as entradas!
*/

#include <stdio.h>
#define CAN 25
#define QUES 100
#define AUX 90

int main()
{
    char gabarito[QUES];
    size_t i, j;

    printf("Digite o GABARITO da prova:\n");

    for (i = 0; i < QUES; i++)
    {
        printf("  > Questao %d: ", (i+1));
        scanf("%c", &gabarito[i]);
        fflush(stdin); // limpa o buffer do teclado
    }

    printf("\n===========================================\n\n");

    char candidato_res[CAN][QUES];
    int cont_ques = 0, cont_can = 0;

    for (i = 0; i < CAN; i++)
    {
        printf("Respostas do CANDIDATO %d\n", (i+1));

        for (j = 0; j < QUES; j++)
        {
            printf("\t> Q%d: ", (j+1));
            scanf("%c", &candidato_res[i][j]);
            fflush(stdin); // limpa o buffer do teclado

           if (candidato_res[i][j] == gabarito[j])
           {
               cont_ques++;

                if (cont_ques > AUX)
                {
                    cont_can++;
                    cont_ques = 0;
                }
           }
        }

        cont_ques = 0;

        printf("\n");
    }

    printf("\n\n===========================================\n\n");

    printf("%d CANDIDATOS ACERTARAM MAIS QUE %d QUESTOES!\n", cont_can, AUX);

    return 0;
}