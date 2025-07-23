/******************************************************************************

Série: Projetos
Projeto 4: Tabela de Times

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_TIMES 20

//FUNÇÕES
typedef struct {
	char nome[50];
	int vitorias, empates, derrotas;
	int golsPro, golsContra;
	int pontos, saldoGols;
} Times;

typedef struct{
    char timeA[50];
    char timeB[50];
    int golsA, golsB;
}Jogos;
//FUNÇÕES

//ASSINATURAS DAS FUNÇÕES
void cadastrarTimes(Times **times, int *qtd); //ponteiro duplo porque será usado o realloc, para alocar mais de um time de forma dinâmica
void verTabela(Times *times, int qtd);
void verJogos(Jogos *jogos, int qtdJogos);
void cadastrarJogos(Jogos **jogos, int *qtdJogos, Times *times, int qtdTimes);
int buscarTime(Times *times, int qtdTimes ,char nomeTime[]);
//ASSINATURAS DAS FUNÇÕES

int main()
{
	Times *times = NULL;
	int qtdTimes = 0;
	int op;
	
	Jogos *jogos = NULL;
	int qtdJogos = 0;

	do {
		printf("/----------Tabela do Brasileirão----------/\n\n");

		printf("1-Ver Tabela\n2-Cadastrar Time(s)\n3-Ver Jogos\n4-Cadastrar Jogos\n5-Buscar Time\n0-Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &op);

		if(op < 0 || op > 5)
		{
			printf("Opção inválida! Escolha novamente.");
			fflush(stdout);
			sleep(2);
            #ifdef _WIN32
            	system("cls");
            #else
        		system("clear");
            #endif
		}

		switch(op)
		{
		    case 1: //ver Tabela
		        #ifdef _WIN32
                	system("cls");
                #else
            		system("clear");
                #endif
                printf("Carregando tabela...");
                fflush(stdout);
                sleep(3);
                #ifdef _WIN32
                	system("cls");
                #else
            		system("clear");
                #endif
			    verTabela(times, qtdTimes);
		    break;

		    case 2: //Cadastro de Times
		        #ifdef _WIN32
                	system("cls");
                #else
            		system("clear");
                #endif
    			
    			int timesCadastrar;
    			printf("Quantos times quer cadastrar? ");
    			scanf("%d", &timesCadastrar);
    
    			if(timesCadastrar > MAX_TIMES)
    			{
                    printf("O máximo de times é %d!", MAX_TIMES);
                    timesCadastrar = MAX_TIMES;
    			}
    
    			for(int i = 0; i < timesCadastrar; i++)
    			{
    		        printf("/-----Cadastro de Times----/\n\n");
    	            cadastrarTimes(&times, &qtdTimes);
    			}
    		break;
    		
    		case 3: //ver jogos

                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
            
                printf("Carregando jogos...\n");
                fflush(stdout);
                sleep(2);
            
                verJogos(jogos, qtdJogos);

    		break;
    		
    		case 4: //cadastro de jogos 
    		    #ifdef _WIN32
                	system("cls");
                #else
            		system("clear");
                #endif
                
                
    		    if (qtdTimes < 2) 
    		    {
                    printf("Cadastre pelo menos dois times antes de registrar um jogo!\n");
                    sleep(2);
                    break;
                }
                
                cadastrarJogos(&jogos, &qtdJogos, times, qtdTimes);
    		break;
    		
    		case 5: 
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
            
                getchar(); // limpar buffer
                char nomeTime[50];
                printf("Digite o nome do time que deseja buscar: ");
                fgets(nomeTime, sizeof(nomeTime), stdin);
                nomeTime[strcspn(nomeTime, "\n")] = 0;
            
                int indiceTime = buscarTime(times, qtdTimes, nomeTime);
            
                if (indiceTime == -1) {
                    printf("Time não encontrado!\n");
                } else {
                    int jogos = times[indiceTime].vitorias + times[indiceTime].empates + times[indiceTime].derrotas;
                    
                    printf("\n/-----Dados do Time-----/\n");
                    printf("Time: %s\n\n", times[indiceTime].nome);
                    printf("Jogos: %d\n", jogos);
                    printf("Vitórias: %d\n", times[indiceTime].vitorias);
                    printf("Empates: %d\n", times[indiceTime].empates);
                    printf("Derrotas: %d\n", times[indiceTime].derrotas);
                    printf("Gols Pró: %d\n", times[indiceTime].golsPro);
                    printf("Gols Contra: %d\n", times[indiceTime].golsContra);
                    printf("Saldo de Gols: %d\n", times[indiceTime].saldoGols);
                    printf("Pontos: %d\n", times[indiceTime].pontos);
                }
            
                sleep(3);
            break;

    		case 0: // sair
    		    #ifdef _WIN32
                	system("cls");
                #else
            		system("clear");
                #endif
    		    printf("Encerrando o programa...");
    		    fflush(stdout);
    		    sleep(3);
    		break;
		
		}

	}while(op != 0);
	
	free(times);//libera memória
	free(jogos);

	return 0;
}

//FUNÇÕES
void verTabela(Times *times, int qtd)
{
    if(qtd == 0)
    {
        printf("Nenhum time foi cadastrado...\n");
        fflush(stdout);
        sleep(2);
        return;
    }
    
    // Criar cópia para ordenar sem modificar o original
    Times *ordenado = malloc(qtd * sizeof(Times));
    memcpy(ordenado, times, qtd * sizeof(Times));
    
    for(int i = 0; i < qtd; i++)
    {
        for(int j = 0; j < qtd - i - 1; j++)
        {
            if(ordenado[j].pontos < ordenado[j+1].pontos ||
              (ordenado[j].pontos == ordenado[j+1].pontos && 
               ordenado[j].saldoGols < ordenado[j+1].saldoGols)) {
                   
                Times temp = ordenado[j];
                ordenado[j] = ordenado[j+1];
                ordenado[j+1] = temp;
            }
        }
    }
    
    printf("/----------TABELA DO CAMPEONATO----------/\n\n");
    
    printf("%-20s %-5s %-5s %-5s %-5s %-5s %-7s %-5s %-5s\n",
           "Time", "Pts", "Jgs", "Vit", "Emp", "Der", "GP", "GC", "SG");

    for (int i = 0; i < qtd; i++) {
        int jogos = ordenado[i].vitorias + ordenado[i].empates + ordenado[i].derrotas;
        printf("%-20s %-5d %-5d %-5d %-5d %-5d %-7d %-5d %-5d\n",
               ordenado[i].nome,
               ordenado[i].pontos,
               jogos,
               ordenado[i].vitorias,
               ordenado[i].empates,
               ordenado[i].derrotas,
               ordenado[i].golsPro,
               ordenado[i].golsContra,
               ordenado[i].saldoGols);
    }

    free(ordenado);
    printf("\n");
    sleep(3);
}

void cadastrarTimes(Times **times, int *qtd)
{
	*times = realloc(*times, (*qtd + 1) * sizeof(Times));
	if(*times == NULL)
		printf("Erro ao alocar a memória!\n");

	printf("Nome do time: ");
	getchar();
	fgets((*times)[*qtd].nome, sizeof((*times)[*qtd].nome), stdin);
	(*times)[*qtd].nome[strcspn((*times)[*qtd].nome, "\n")] = 0;

	(*times)[*qtd].vitorias = 0;
    (*times)[*qtd].empates = 0;
    (*times)[*qtd].derrotas = 0;
    (*times)[*qtd].golsPro = 0;
    (*times)[*qtd].golsContra = 0;
    (*times)[*qtd].pontos = 0;
    (*times)[*qtd].saldoGols = 0;

	(*qtd)++;

	printf("Time(s) Cadastrado com sucesso!\n");
	sleep(2);
}

void verJogos(Jogos *jogos, int qtdJogos)
{
    if (qtdJogos == 0) {
        printf("Nenhum jogo registrado ainda.\n");
        sleep(2);
        return;
    }

    printf("/----------Jogos Registrados----------/\n\n");

    for (int i = 0; i < qtdJogos; i++) {
        printf("%d) %s %d x %d %s\n",
            i + 1,
            jogos[i].timeA,
            jogos[i].golsA,
            jogos[i].golsB,
            jogos[i].timeB);
    }
    printf("\n");
    sleep(3);
}

void cadastrarJogos(Jogos **jogos, int *qtdJogos, Times *times, int qtdTimes)
{
    *jogos = realloc(*jogos, (*qtdJogos + 1) * sizeof(Jogos));
    if(*jogos == NULL) {
        printf("Erro ao alocar a memória!\n");
        exit(1);
    }

    // Ler nome do time A
    getchar(); // consome '\n' pendente do scanf anterior
    printf("Time A: ");
    fgets((*jogos)[*qtdJogos].timeA, sizeof((*jogos)[*qtdJogos].timeA), stdin);
    (*jogos)[*qtdJogos].timeA[strcspn((*jogos)[*qtdJogos].timeA, "\n")] = 0;

    // Ler nome do time B
    printf("Time B: ");
    fgets((*jogos)[*qtdJogos].timeB, sizeof((*jogos)[*qtdJogos].timeB), stdin);
    (*jogos)[*qtdJogos].timeB[strcspn((*jogos)[*qtdJogos].timeB, "\n")] = 0;

    // Procurar índices dos times no vetor times
    int i1 = -1, i2 = -1;
    for (int i = 0; i < qtdTimes; i++) 
    {
        if (strcmp(times[i].nome, (*jogos)[*qtdJogos].timeA) == 0)
            i1 = i;
        else if (strcmp(times[i].nome, (*jogos)[*qtdJogos].timeB) == 0)
            i2 = i;
    }

    if (i1 == -1 || i2 == -1) 
    {
        printf("Um dos times não foi encontrado!\n");
        return;
    }

    // Ler gols do jogo
    int golsTime1, golsTime2;
    printf("Gols do %s: ", times[i1].nome);
    scanf("%d", &golsTime1);
    printf("Gols do %s: ", times[i2].nome);
    scanf("%d", &golsTime2);

    (*jogos)[*qtdJogos].golsA = golsTime1;
    (*jogos)[*qtdJogos].golsB = golsTime2;

    // Atualizar estatísticas dos times
    times[i1].golsPro += golsTime1;
    times[i1].golsContra += golsTime2;
    
    times[i2].golsPro += golsTime2;
    times[i2].golsContra += golsTime1;

    if (golsTime1 > golsTime2) 
    {
        times[i1].vitorias++;
        times[i2].derrotas++;
    } 
    else if (golsTime2 > golsTime1) 
    {
        times[i2].vitorias++;
        times[i1].derrotas++;
    } 
    else 
    {
        times[i1].empates++;
        times[i2].empates++;
    }

    // Atualizar pontos e saldo de gols
    for (int i = 0; i < qtdTimes; i++) 
    {
        times[i].pontos = times[i].vitorias * 3 + times[i].empates;
        times[i].saldoGols = times[i].golsPro - times[i].golsContra;
    }

    (*qtdJogos)++;
    printf("Jogo registrado com sucesso!\n");
    sleep(2);
}

int buscarTime(Times *times, int qtdTimes, char nomeTime[]) 
{
    for (int i = 0; i < qtdTimes; i++) 
    {
        if (strcmp(times[i].nome, nomeTime) == 0) 
        {
            return i;
        }
    }
    return -1;
}

//FUNÇÕES