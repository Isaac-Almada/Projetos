/******************************************************************************

Og, o ogro, possui vários filhos. E seus filhos, por sua vez, possuem vários filhos. Og quer saber quantos
netos ele tem. Mas ogros são péssimos em matemática. Portanto, Og quer sua ajuda: dado o número
de filhos que cada filho de Og tem, determine o número total de netos de Og.

A entrada é descrita em duas linhas. A primeira linha contém um inteiro N (1 ≤ N ≤ 1000), indicando
o número de filhos de Og. A segunda linha possui N inteiros F1, F2, . . . , FN . O número Fi (0 ≤ Fi ≤
1000, para todo i entre 1 e N inclusive) representa o número de filhos que o i-ésimo filho de Og possui.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int numFilhos;
    int numNetos;
    int somaNetos = 0;
    
    scanf("%d",&numFilhos);
    
    for(int i = 0; i < numFilhos; i ++)
    {
        scanf("%d",&numNetos);
        somaNetos = somaNetos+numNetos;
    }
    
    printf("%d", somaNetos);
}
