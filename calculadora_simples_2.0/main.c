/******************************************************************************

Projeto - Calculadora Simples 2.0

*******************************************************************************/
#include <stdio.h>
#include <math.h>

//Assinatura das funções
double calcSoma(double n1,double n2);
double calcSub(double n1, double n2);
double calcMult(double n1, double n2);
double calcDiv(double n1, double n2);
double calcPot(double base, double expoente);
double calcRaiz(double n1, double indice);
double calcResto(double n1, double n2);


int main()
{
    int op;
    double n1, n2, base, expoente, indice,soma, sub, mult, divisao;
    double potencia, raiz, resto;
    
    printf("\tCALCULADORA SIMPLES\n");
    
    do
    {
        printf("1 - Soma\n2 - Subtração \n3 - Multiplicação \n4 - Divisão\n5 - Potência\n6 - Raiz\n7 - Resto da divisão\n");
        printf("Escolha uma operação:");
    
        scanf("%d", &op);
        
        if(op > 7 || op < 1)
        {
            printf("\nOperação inválida!\n");
        }
        
    }while(op > 7 || op < 1);
    
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
        
        case 5:
            printf("\nEscreva a base: ");
            scanf("%lf", &base);
            printf("Escreva o expoente: ");
            scanf("%lf", &expoente);
            
            potencia = calcPot(base, expoente);
            
            printf("\nA potência de %.2lf elevado a %.2lf é %.2lf", base, expoente, potencia);
        break;
        
        case 6:
            printf("\nEscreva a base: ");
            scanf("%lf", &base);
            printf("Escreva o índice: ");
            scanf("%lf", &indice);

            if (indice == 0) 
            {
                printf("Erro: índice da raiz não pode ser zero.");
            }
            else if ((int)indice % 2 == 0 && base < 0) 
            {
                printf("Não existe raiz de índice par de número negativo nos reais!");
            }
            else 
            {
                raiz = calcRaiz(base, indice);
                printf("\nA raiz de índice %.2lf de %.2lf é %.2lf", indice, base, raiz);
            }
        break;
        
        case 7:
            printf("\nEscreva o primeiro número: ");
            scanf("%lf", &n1);
            printf("Escreva o segundo número: ");
            scanf("%lf", &n2);

            if ((int)n2 == 0)
            {
                printf("Erro: divisão por zero!");
            }   
            else
            {
                resto = calcResto(n1, n2);
                printf("\nO resto da divisão entre %.2lf e %.2lf é %.2lf", n1, n2, resto);
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

double calcPot(double base, double expoente)
{
    return pow(base, expoente);
}

double calcRaiz(double base, double indice)
{
    if(indice == 2)
    {
            return sqrt(base);
    }
    
    if((int)indice % 2 == 0 && base < 0)
    {
            return 0;
    }
    
    //pra outras raizes
    if (base < 0)
    {
        return -pow(-base, 1.0 / indice);
    }
        
    else
    {
        return pow(base, 1.0 / indice);
    }
}

double calcResto(double n1, double n2)
{
    return fmod(n1, n2);
}
