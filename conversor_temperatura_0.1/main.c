/******************************************************************************

Projeto - Calculadora de Conversão de Temperatura 0.1

*******************************************************************************/
#include <stdio.h>

// Funções de conversão
double calculaCelsius(double celsius, int op2);
double calculaFahrenheit(double fahrenheit, int op2);
double calculaKelvin(double kelvin, int op2);

int main()
{
    int op1, op2, continuar;
    double resultado;

    do {
        printf("\n\tCONVERSOR DE TEMPERATURA\n");

        // Escolha da unidade de entrada
        do 
        {
            printf("Escolha a unidade de temperatura de entrada:\n1 - Celsius (°C)\t2 - Fahrenheit (°F)\t3 - Kelvin (K): ");
            scanf("%d", &op1);
        } while (op1 < 1 || op1 > 3);

        switch (op1)
        {
            case 1: { // Celsius
                double celsius;
                do 
                {
                    printf("Escolha a unidade de destino:\n1 - Fahrenheit (°F)\t2 - Kelvin (K): ");
                    scanf("%d", &op2);
                } while (op2 < 1 || op2 > 2);

                printf("Digite a temperatura em Celsius: ");
                scanf("%lf", &celsius);

                resultado = calculaCelsius(celsius, op2);

                if (op2 == 1)
                {
                    printf("Resultado: %.2lf °F\n", resultado);
                }
                else
                {
                    printf("Resultado: %.2lf K\n", resultado);
                }

                break;
            }

            case 2: 
            { // Fahrenheit
                double fahrenheit;
                do 
                {
                    printf("Escolha a unidade de destino:\n1 - Celsius (°C)\t2 - Kelvin (K): ");
                    scanf("%d", &op2);
                } while (op2 < 1 || op2 > 2);

                printf("Digite a temperatura em Fahrenheit: ");
                scanf("%lf", &fahrenheit);

                resultado = calculaFahrenheit(fahrenheit, op2);

                if (op2 == 1)
                {
                    printf("Resultado: %.2lf °C\n", resultado);
                }
                else
                {
                    printf("Resultado: %.2lf K\n", resultado);
                }
                
                break;
            }

            case 3: 
            { // Kelvin
                double kelvin;
                do 
                {
                    printf("Escolha a unidade de destino:\n1 - Celsius (°C)\t2 - Fahrenheit (°F): ");
                    scanf("%d", &op2);
                } while (op2 < 1 || op2 > 2);

                printf("Digite a temperatura em Kelvin: ");
                scanf("%lf", &kelvin);

                resultado = calculaKelvin(kelvin, op2);

                if (op2 == 1)
                {
                    printf("Resultado: %.2lf °C\n", resultado);
                }
                else
                {
                    printf("Resultado: %.2lf °F\n", resultado);
                }
                
                break;
            }

            default:
                printf("Erro inesperado!\n");
        }

        // Pergunta se o usuário quer continuar
        do 
        {
            printf("\nDeseja realizar outra conversão? (1 - Sim / 0 - Não): ");
            scanf("%d", &continuar);
        } while (continuar != 0 && continuar != 1);

    } while (continuar == 1);

    printf("\nFim do Programa. Até a próxima!\n");
    return 0;
}

// Funções de conversão
double calculaCelsius(double celsius, int op2)
{
    if (op2 == 1)
    {
        return (9.0 / 5.0 * celsius) + 32;
    }
    else
    {
        return celsius + 273.15;
    }
        
}

double calculaFahrenheit(double fahrenheit, int op2)
{
    if (op2 == 1)
    {
        return (fahrenheit - 32) * 5.0 / 9.0;
    }
    else
    {
        return ((fahrenheit - 32) * 5.0 / 9.0) + 273.15;
    }
}

double calculaKelvin(double kelvin, int op2)
{
    if (op2 == 1)
    {
        return kelvin - 273.15;
    }
    else
    {
        return (9.0 / 5.0 * (kelvin - 273.15)) + 32;
    }
}

