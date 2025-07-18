/******************************************************************************

Nos últimos dias, o papo das diferenças entre gerações ficou mais proeminente nas redes sociais. E
isso aconteceu por uma diferença importante: os millennials oficialmente já escalonaram, na visão
da Geração Z, para uma idade na qual já não são mais considerados jovens. Hoje, são vistos pelos
adolescentes e jovens adultos como pessoas mais velhas que tem certos costumes que já estão fora de
moda ou, como a Geração Z gosta de falar, os millennials são cringe.
Os millennials tem o costume de achar que os mais novos, da Geração Z, deveriam ser mais novos do
que realmente são. Por exemplo, um millennial não aceita que uma pessoa que nasceu em 2015 possa
ter 10 anos: quem tem 10 anos deveria ter nascido em 2005!
Um millennial sente o tempo passar na metade do tempo: se uma pessoa da Geração Z nasceu x anos
atrás, um millennial acredita que ela deveria ter nascido 2x anos atrás para ter a idade que ela tem.
Assumindo que o ano é 2025, escreva um programa que, dado o ano Y que uma pessoa da Geração Z
nasceu, calcule o ano que um millennial acredita que ela deveria ter nascido.


A entrada consiste em apenas um número Y (2010 ≤ Y ≤ 2020), o ano em que a pessoa da Geração Z
nasceu.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int idadeReal, anoNascimento, idadeMillennials, anoMillennials;
    
    scanf("%d", &anoNascimento);
    
    idadeReal = 2025 - anoNascimento;
    idadeMillennials = idadeReal*2;
    anoMillennials = 2025 - idadeMillennials;
    
    printf("%d", anoMillennials);
}