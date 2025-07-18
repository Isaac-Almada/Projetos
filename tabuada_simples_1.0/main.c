/******************************************************************************

Projeto - Tabuada 1.0

*******************************************************************************/
#include <stdio.h>

void tab(int n1);

int main()
{
    int n1;
    
    printf("\tTABUADA SIMPLES\n");
    printf("Escreva um número: ");
    scanf("%d", &n1);
    
    printf("\nTabuada de %d até 10:\n", n1);
    
    tab(n1);
}

void tab(int n1)
{
    int tabuada;
    for(int i = 0; i <= 10 ; i++)
    {
        tabuada = n1 * i;
        printf("\n%d x %d = %d", n1, i, tabuada);
    }
}