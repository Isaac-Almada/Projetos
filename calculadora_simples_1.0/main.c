/******************************************************************************

Projeto - Calculadora 1.0

*******************************************************************************/
#include <stdio.h>

//Assinatura das funções
double calcSoma(double n1,double n2);
double calcSub(double n1, double n2);
double calcMult(double n1, double n2);
double calcDiv(double n1, double n2);


int main()
{
    int op;
    double n1, n2, soma, sub, mult, divisao;
    
    printf("\tCALCULADORA SIMPLES\n");
    
    do
    {
        printf("1 - Soma\n2 - Subtração \n3 - Multiplicação \n4 - Divisão\n");
        printf("Escolha uma operação:");
    
        scanf("%d", &op);
        
        if(op > 4 || op < 1)
        {
            printf("\nOperação inválida!");
        }
        
    }while(op > 4 || op < 1);
    
    switch(op)
    {
        case 1: 
            printf("\nEscreva o primeiro número: ");
            scanf("%lf", &n1);
            printf("Escreva o segundo número: ");
            scanf("%lf", &n2);
            
            soma = calcSoma(n1, n2);
            
            printf("\nA soma de %.2lf e %.2lf é %.2lf.", n1, n2, soma);
        break;
        
        case 2: 
            printf("\nEscreva o primeiro número: ");
            scanf("%lf", &n1);
            printf("Escreva o segundo número: ");
            scanf("%lf", &n2);
            
            sub = calcSub(n1, n2);
            
            printf("\nA diferença entre %.2lf e %.2lf é %.2lf.", n1, n2, sub);
        break;
        
        case 3: 
            printf("\nEscreva o primeiro número: ");
            scanf("%lf", &n1);
            printf("Escreva o segundo número: ");
            scanf("%lf", &n2);
            
            mult = calcMult(n1, n2);
            
            printf("\nO produto de %.2lf e %.2lf é %.2lf.", n1, n2, mult);
        break;
        
        case 4: 
            printf("\nEscreva o primeiro número: ");
            scanf("%lf", &n1);
            printf("Escreva o segundo número: ");
            scanf("%lf", &n2);
            
            
            if(n2 == 0)
            {
                printf("\nDivisão indefida");
            }
            
            else
            {
                divisao = calcDiv(n1, n2);
                printf("\nO quociente de %.2lf e %.2lf é %.2lf.", n1, n2, divisao);
            }
            
        break;
    }
    
}


double calcSoma(double n1,double n2)
{
    return n1+n2;
}

double calcSub(double n1, double n2)
{
    return n1 - n2;
}

double calcMult(double n1, double n2)
{
    return n1 * n2;
}

double calcDiv(double n1, double n2)
{
    if(n2 != 0)
    {
        return n1 / n2;
    }
    else
    {
        return 0;//Erro;
    }
}