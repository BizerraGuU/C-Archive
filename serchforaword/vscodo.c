#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encontraLetra(const char *palavra, char letraDesejada)
{
    while(*palavra != EOF)
    {
        if (*palavra == letraDesejada)
        {
            return (char*)palavra;
        }
        palavra++;
    }
    return NULL;
}

int main()
{
    char palavraDigitada[50];
    char letraDigitada;
    char *apontaLetra;
    int i;


    fflush(stdin);
    printf ("Digite uma palavra: ");
    gets(palavraDigitada); 
    fflush(stdin);


    printf("Digite a letra que deseja encontrar: ");
    scanf("%c", &letraDigitada);
    


    apontaLetra = encontraLetra(palavraDigitada, letraDigitada);


    if (apontaLetra != NULL)
    {
        for (i=0; palavraDigitada[i] != '\0'; i++)
        {
          printf("\npalavraDigitada[%i] = %c ---> %p", i, palavraDigitada[i], &palavraDigitada[i]);
        }

        printf("\n\nA letra [%c] foi encontrada na palavra [%s] em [%p]\n", letraDigitada, palavraDigitada, apontaLetra);


    } else
        {
            printf("\nA letra %c nao foi encontrada na palavra %s", letraDigitada, palavraDigitada);
        }

    return 0;
}