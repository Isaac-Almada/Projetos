/******************************************************************************

Série: Projetos
Projeto 2: Sistema de Reservas para um cinema

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h> //toupper
#include <unistd.h>

#define TAM 3

void inicializaTabuleiro(char tab[TAM][TAM]);
void mostraTabuleiro(char tab[TAM][TAM]);
void realizaJogada(char tab[TAM][TAM], char simbolo);
char verificaVencedor(char tab[TAM][TAM]);

int main()
{
    char tabuleiro[TAM][TAM];
    char jogador, adversario;
    char vencedor = ' ';
    int jogadas = 0;

    inicializaTabuleiro(tabuleiro);

    do {
        printf("TIME X ou TIME O\n");
        printf("Escolha um time: ");
        scanf(" %c", &jogador);
        jogador = toupper(jogador);
    } while(jogador != 'X' && jogador != 'O');

    adversario = (jogador == 'X') ? 'O' : 'X';

    printf("\nSeu time é o %c\n", jogador);
    printf("O time adversário é o %c\n\n", adversario);
    sleep(2);

    while (1) {
        mostraTabuleiro(tabuleiro);

        // Turno do jogador
        realizaJogada(tabuleiro, jogador);
        jogadas++;
        vencedor = verificaVencedor(tabuleiro);
        if (vencedor != ' ' || jogadas == 9) break;

        mostraTabuleiro(tabuleiro);

        // Turno do adversário
        realizaJogada(tabuleiro, adversario);
        jogadas++;
        vencedor = verificaVencedor(tabuleiro);
        if (vencedor != ' ' || jogadas == 9) break;
    }

    mostraTabuleiro(tabuleiro);

    if (vencedor == jogador)
        printf("\nParabéns! Você venceu!\n");
    else if (vencedor == adversario)
        printf("\nVocê perdeu! O adversário venceu!\n");
    else
        printf("\nDeu velha! Empate!\n");

    return 0;
}

void inicializaTabuleiro(char tab[TAM][TAM])
{
    char contador = '1';
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            tab[i][j] = contador;
            contador++;
        }
    }
}

void mostraTabuleiro(char tab[TAM][TAM])
{
    printf("   Tabuleiro\t\n");
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            printf(" %c ", tab[i][j]);
            if(j < TAM-1)
                printf(" | ");
        }
        printf("\n");
        if(i < TAM-1)
            printf("----|-----|----\n");
    }
}

void realizaJogada(char tab[TAM][TAM], char simbolo)
{
    int posicao;
    int linha,coluna;
    
    while(1){
        printf("Escolha uma posição (1-9): ");
        scanf("%d", &posicao);
        
        if(posicao < 1 || posicao > 9)
        {
            printf("Posição inválida! Escolha novamente entre 1 e 9.\n");
            continue;
        }
        
        linha = (posicao - 1) / TAM;
        coluna = (posicao - 1) % TAM;
        
        if(tab[linha][coluna] == 'X' || tab[linha][coluna] == 'O')
        {
            printf("Posição já ocupada! Escolha novamente.\n");
        }
        else
        {
            tab[linha][coluna] = simbolo;
            break;
        }
            
    }
}

char verificaVencedor(char tab[TAM][TAM]) {
    // Verificar linhas e colunas
    for (int i = 0; i < TAM; i++) {
        if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2])
            return tab[i][0];
        if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i])
            return tab[0][i];
    }

    // Verificar diagonais
    if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2])
        return tab[0][0];
    if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0])
        return tab[0][2];

    return ' ';
}

