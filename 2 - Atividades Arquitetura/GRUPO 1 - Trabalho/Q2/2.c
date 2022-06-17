#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_MAX 200
#define TAM 100

void conjunto_palavras(FILE *arquivo, char *encontrado_1, char *encontrado_2, char *substituicao_1, char *substituicao_2);

int localizar(char *arquivo, char *encontrado);

void substituir(char *texto, char *texto_modificado, char *encontrado, int posicao, char *substituicao);

int main()
{
    system("cls");


    //////////////////////////////
    // ABERTURA DO ARQUIVO "es" //
    //////////////////////////////

    FILE *arquivo_es = fopen("es.txt", "r");  

    if (arquivo_es == NULL)
    {    
        printf("\a\nErro na abertura do arquivo 1!\n\n");
        exit(1);
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    // SALVAR AS PALAVRAS QUE DEVERÃO SER ENCONTRADAS E SUBSTITUIDAS E AS SUAS RESPECTIVAS SUBSTITUIÇÕES //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    
    char e1[TAM], s1[TAM], e2[TAM], s2[TAM]; // "e_" para a palavra que deve ser substituida e "s_" para a sua substituição

    conjunto_palavras(arquivo_es, e1, e2, s1, s2);


    ////////////////////////////////
    // FECHAMENTO DO ARQUIVO "es" //
    ////////////////////////////////

    if (fclose(arquivo_es) != 0)
        printf("\a\nErro no fechamento do arquivo 1!\n\n");


    /////////////////////////////////
    // ABERTURA DO ARQUIVO "texto" //
    /////////////////////////////////

    FILE *arquivo_txt = fopen("texto.txt", "r");  

    if (arquivo_txt == NULL)
    {    
        printf("\a\nErro na abertura do arquivo 1!\n\n");
        exit(1);
    }

    size_t i = 0;
    char texto[TAM_MAX];

    texto[i] = getc(arquivo_txt);
    while (texto[i] != EOF)
    {
        i ++;
        texto[i] = getc(arquivo_txt);
    }
    texto[i] = '\0';


    /////////////////////////////////////////////////////////////
    // ENCONTRAR A POSIÇÃO DAS PALAVRAS QUE SERÃO SUBSTITUIDAS //
    /////////////////////////////////////////////////////////////

    int posicao_e1, posicao_e2;

    posicao_e1 = localizar(texto, e1);
    if (posicao_e1 == -1)
    {    
        printf("\n<< ERRO >>\nA palavra [%s] nao consta no arquivo de texto!\n", e1);

        if (fclose(arquivo_txt) != 0)
            printf("\a\nErro no fechamento do arquivo!\n\n");

        printf("\n\n>> ALTERACAO NO ARQUIVO NAO REALIZADA! <<\n\n");

        return 0;
    }

    posicao_e2 = localizar(texto, e2);
    if (posicao_e2 == -1)
    {    
        printf("\n<< ERRO >>\nA palavra [%s] nao consta no arquivo de texto!\n", e2);

        if (fclose(arquivo_txt) != 0)
            printf("\a\nErro no fechamento do arquivo!\n\n");

        printf("\n\n>> ALTERACAO NO ARQUIVO NAO REALIZADA! <<\n\n");

        return 0;
    }


    ///////////////////////////////////
    // FECHAMENTO DO ARQUIVO "texto" //
    ///////////////////////////////////

    if (fclose(arquivo_txt) != 0)
        printf("\a\nErro no fechamento do arquivo!\n\n");


    ////////////////////////////////////////////////////////
    // FORMAÇÃO DO TEXTO A SER GRAVADO NO ARQUIVO "texto" //
    ////////////////////////////////////////////////////////

    char texto_modificado_1[TAM_MAX], texto_modificado_2[TAM_MAX];

    substituir(texto, texto_modificado_1, e2, posicao_e2, s2);
    substituir(texto_modificado_1, texto_modificado_2, e1, posicao_e1, s1);


    ////////////////////////////////////////////////
    // ESCREVER A SUBSTITUIÇÃO NO ARQUIVO "texto" //
    ////////////////////////////////////////////////

    arquivo_txt = fopen("texto.txt", "w");  

    if (arquivo_txt == NULL)
    {    
        printf("\a\nErro na abertura do arquivo!\n\n");
        exit(1);
    }  

    fprintf(arquivo_txt, "%s", texto_modificado_2);

    if (fclose(arquivo_txt) != 0)
        printf("\a\nErro no fechamento do arquivo!\n\n");

    printf("\n\n>> ALTERACAO NO ARQUIVO REALIZADA COM SUCESSO! <<\n\n");

    return 0;
}

void conjunto_palavras(FILE *arquivo, char *encontrado_1, char *encontrado_2, char *substituicao_1, char *substituicao_2)
{   
  
    char lixo;
    size_t i = 0;

    encontrado_1[i] = getc(arquivo);
    while (encontrado_1[i] != ' ')
    {
        i ++; 
        encontrado_1[i] = getc(arquivo);
    } 
    encontrado_1[i] = '\0'; // evita a impressão de caracteres estranhos!

    lixo = getc(arquivo);
    while (lixo == ' ')
        lixo = getc(arquivo);

    i = 0;

    substituicao_1[i] = lixo; // quando "lixo" != 0
    while (substituicao_1[i] != '\n')
    {
        i ++; 
        substituicao_1[i] = getc(arquivo);
    }  
    substituicao_1[i] = '\0';

    lixo = getc(arquivo);
    while (lixo == ' ')
        lixo = getc(arquivo);

    i = 0;

    encontrado_2[i] = lixo; // quando "lixo" != 0
    while (encontrado_2[i] != ' ')
    {
        i ++; 
        encontrado_2[i] = getc(arquivo);
    }  
    encontrado_2[i] = '\0';

    lixo = getc(arquivo);
    while (lixo == ' ')
        lixo = getc(arquivo);

    i = 0;

    substituicao_2[i] = lixo; // quando "lixo" != 0
    while (substituicao_2[i] != EOF) // última sequência de caracteres
    {
        i ++; 
        substituicao_2[i] = getc(arquivo);
    }  
    substituicao_2[i] = '\0';
}

int localizar(char *texto, char *encontrado)
{  
    if (strstr(texto, encontrado) == NULL) // strstr() retorna  um ponteiro nulo se a sequência não estiver presente no vetor
        return -1;
    
    int tamanho_txt = strlen(texto);
    int posicao = tamanho_txt - strlen( strstr(texto, encontrado) );
    /*
        > "strstr(texto, encontrado)" retorna a parte do vetor "texto" à partir da 1ª ocorência
        da string no vetor "encontrado" e "strlen( strstr(texto, encontrado) )" lê justamente esse tamanho.
        > Subtrair esse tamanho do tamanho de "texto" nos retorna a posição de onde começa a palavra no vetor "encontrado"
        no vetor "texto".
    */

   return posicao;
}

void substituir(char *texto, char *texto_modificado, char *encontrado, int posicao, char *substituicao)
{
    char vet_aux_1[TAM_MAX], vet_aux_2[TAM_MAX];
    size_t y = 0;

    strncpy(vet_aux_1, texto, posicao);
    /*
        > "strncpy(vet_aux1, texto, posicao)" copia em vet_aux1 apenas 2 bits (refenrentes à string que vem antes da string
        a ser substituida, no caso em questão) do vetor texto a partir do seu início.
    */  

    vet_aux_1[posicao] = '\0';

    strcpy(texto_modificado, vet_aux_1);        // copia em "texto_modificado" a string que vem antes da string a ser substituída
    strcat(texto_modificado, substituicao);     // o que já tem em "texto_modificado" + a substituição

    for (size_t i = (strlen(encontrado) + posicao); i <= strlen(texto); i++) // "i" começa após a posição de término da string a ser substituída
    {
        vet_aux_2[y] = texto[i]; // copia caractere por caractere
        y ++;
    }

    vet_aux_2[y + 1] = '\0';

    strcat(texto_modificado, vet_aux_2);
    texto_modificado[strlen(texto_modificado) + 1] = '\0';
}

/*
A Nintendo eh uma desenvolvedora e publicadora japonesa de jogos eletronicos e consoles sediada em Quioto.

Nintendo    SEGA
Quioto      Toquio, capital do Japao
*/