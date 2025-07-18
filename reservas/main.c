/******************************************************************************

Série: Projetos
Projeto 1: Sistema de Reservas para um cinema

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMES 3
#define MAX_LINHAS 5
#define MAX_COLUNAS 5

typedef struct {
    char nome[50];
    int idade;
} Cliente;

typedef struct {
    char titulo[100];
    Cliente* sala[MAX_LINHAS][MAX_COLUNAS];
} Filme;

void limparTela() 
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void mostrarMapa(Cliente* sala[5][5]);
void mostrarClientes(Cliente* sala[5][5]);
void reservarPoltrona(Cliente* sala[5][5]);
void cancelarReserva(Cliente* sala[5][5]);

int main() {
    Filme catalogo[MAX_FILMES];
    int opFilme, opMenu;
    
    // Inicializa filmes e salas vazias
    strcpy(catalogo[0].titulo, "Pecadores");
    strcpy(catalogo[1].titulo, "Thunderbolts");
    strcpy(catalogo[2].titulo, "Superman");
    
    for(int f = 0; f < MAX_FILMES; f++) {
        for(int i = 0; i < MAX_LINHAS; i++) {
            for(int j = 0; j < MAX_COLUNAS; j++) {
                catalogo[f].sala[i][j] = NULL;
            }
        }
    }
    
    do {
        limparTela();
        printf("Escolha um filme:\n");
        for(int i = 0; i < MAX_FILMES; i++) {
            printf("%d - %s\n", i+1, catalogo[i].titulo);
        }
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opFilme);
        
        if(opFilme < 0 || opFilme > MAX_FILMES) {
            printf("Opcao invalida!\n");
            continue;
        }
        
        if(opFilme == 0)
            break;
        
        // Menu do filme escolhido
        do {
            sleep(5);
            limparTela();
            printf("\n--- Menu do filme: %s ---\n", catalogo[opFilme-1].titulo);
            printf("1 - Mostrar mapa de assentos\n");
            printf("2 - Reservar poltrona\n");
            printf("3 - Cancelar reserva\n");
            printf("4 - Mostrar clientes\n");
            printf("0 - Voltar para catalogo\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opMenu);
            
            switch(opMenu) {
                case 1:
                    mostrarMapa(catalogo[opFilme-1].sala);
                    break;
                case 2:
                    reservarPoltrona(catalogo[opFilme-1].sala);
                    break;
                case 3:
                    cancelarReserva(catalogo[opFilme-1].sala);
                    break;
                case 4:
                    mostrarClientes(catalogo[opFilme-1].sala);
                    break;
                case 0:
                    printf("Voltando ao catalogo de filmes...\n");
                    break;
                default:
                    printf("Opcao invalida!\n");
            }
        } while(opMenu != 0);
        
    } while(1);
    
    //lIBERA MEMÓRIA
    for(int f = 0; f < MAX_FILMES; f++) {
        for(int i = 0; i < MAX_LINHAS; i++) {
            for(int j = 0; j < MAX_COLUNAS; j++) {
                if(catalogo[f].sala[i][j] != NULL) {
                    free(catalogo[f].sala[i][j]);
                }
            }
        }
    }
    //lIBERA MEMÓRIA
    
    printf("Programa encerrado.\n");
    return 0;
}

//FUNÇÕES

void mostrarMapa(Cliente* sala[5][5]) {
    printf("MAPA DA SALA: \n");
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 5; j ++) {
            if(sala[i][j] == NULL)
                printf("L "); // livre
            else
                printf("O "); // ocupado
        }
        printf("\n");
    }
}

void mostrarClientes(Cliente* sala[5][5]) {
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 5; j ++) {
            if(sala[i][j] != NULL) {
                printf("Assento [%d][%d]: Ocupado - Cliente: %s - Idade: %d\n",
                    i, j, sala[i][j]->nome, sala[i][j]->idade);
            }
        }
    }
}

void reservarPoltrona(Cliente* sala[5][5]) {
    int fileira, cadeira;
    
    printf("Escolha a fileira (0-4): ");
    scanf("%d", &fileira);
    printf("Escolha a cadeira da fileira %d (0-4): ", fileira);
    scanf("%d", &cadeira);
    
    if (fileira < 0 || fileira >= 5 || cadeira < 0 || cadeira >= 5) {
        printf("Assento invalido!\n");
        return;
    }
    
    if(sala[fileira][cadeira] == NULL) {
        sala[fileira][cadeira] = (Cliente*) malloc(sizeof(Cliente));
        if(sala[fileira][cadeira] == NULL) {
            printf("Erro de alocacao de memoria!\n");
            return;
        }
        
        printf("Digite o nome: ");
        scanf("%s", sala[fileira][cadeira]->nome);
        printf("Digite a idade: ");
        scanf("%d", &sala[fileira][cadeira]->idade);
        
        printf("Reserva efetuada!\n");
    } else {
        printf("Assento ocupado!\n");
    }
}

void cancelarReserva(Cliente* sala[5][5]) {
    int fileira, cadeira;
    
    printf("Cancelamento de reserva:\n");
    printf("Insira a fileira (0-4): ");
    scanf("%d", &fileira);
    printf("Insira a cadeira reservada (0-4): ");
    scanf("%d", &cadeira);
    
    if (fileira < 0 || fileira >= 5 || cadeira < 0 || cadeira >= 5) {
        printf("Assento invalido!\n");
        return;
    }
    
    if(sala[fileira][cadeira] == NULL) {
        printf("Assento ja esta vazio!\n");
    } else {
        free(sala[fileira][cadeira]);
        sala[fileira][cadeira] = NULL;
        printf("Reserva cancelada!\n");
    }
}
