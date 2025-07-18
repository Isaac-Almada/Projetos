/******************************************************************************

Projeto - Tabuada 2.0

*******************************************************************************/
#include <stdio.h>

void tab(int n1, int lim);

int main()
{
    int n1, lim;
    
    printf("\tTABUADA SIMPLES\n");
    printf("Escreva um número: ");
    scanf("%d", &n1);
    printf("Escreva o número limite da tabuada: ");
    scanf("%d", &lim);
    
    printf("\nTabuada de %d até %d:\n", n1,lim);
    
    tab(n1,lim);
}

void tab(int n1,int lim)
{
    int tabuada;
    for(int i = 0; i <= lim ; i++)
    {
        tabuada = n1 * i;
        printf("\n%d x %d = %d", n1, i, tabuada);
    }
}
