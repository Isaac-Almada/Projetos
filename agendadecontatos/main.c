/******************************************************************************

Série: Projetos
Projeto 3 - Agenda de Contatos

*******************************************************************************/
//bibliotecas
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
//bibliotecas

#define MAX_CONTATOS 20

//Struct 
typedef struct{
    char nome[50];
    char telefone[15];
    char email[40];
}Contato;
//Struct

//assinatura das funções
int lerContatos(Contato vet[], char nomeArquivo[]);
void listarContatos(Contato vet[], int tam);
int buscarContato(Contato vet[], int tam, char contatoBuscado[]);
//assinatura das funções

//MAIN
int main()
{
    // Declaração das Variáveis
    Contato contatos[MAX_CONTATOS];
    char nomeArquivo[20];
    int tam;
    int op;
    //Declaração das Variáveis

    printf("Nome do arquivo: ");
    scanf("%s", nomeArquivo);
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    tam = lerContatos(contatos, nomeArquivo);

    do { // Menu
        printf("/-------------Agenda de Contatos-------------/\n\n");
        printf("1 - Listar Contatos\n");
        printf("2 - Buscar Contato\n");
        printf("3 - Adicionar Contato\n");
        printf("4 - Remover Contato\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &op) != 1) {  // Verifica se foi digitado um número
            while(getchar() != '\n');  // Limpa o buffer de entrada
            printf("Entrada inválida! Por favor, digite um número.\n");
            op = -1;  // Para forçar repetir o menu
            sleep(2);
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            continue;
        }

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch(op)
        {
            case 1://Lista os contatos
                printf("Carregando contatos...\n");
                fflush(stdout);
                sleep(2);
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                printf("/-------------Lista de Contatos-------------/\n\n");
                listarContatos(contatos, tam);
            break;

            case 2: //Busca o contato
                char nomeContato[50];
                int indiceContato;

                printf("Escreva o nome do contato que deseja buscar: ");
                getchar(); // limpa o \n do scanf anterior
                fgets(nomeContato, sizeof(nomeContato), stdin);
                nomeContato[strcspn(nomeContato, "\n")] = 0;

                indiceContato = buscarContato(contatos, tam, nomeContato);

                printf("Buscando contato...\n");
                fflush(stdout);
                sleep(2);

                if (indiceContato == -1)
                    printf("Contato não encontrado!\n");
                else {
                    printf("Contato achado!\n\n");
                    printf("[%d] Nome: %s\n", indiceContato + 1, contatos[indiceContato].nome);
                    printf("Telefone: %s\n", contatos[indiceContato].telefone);
                    printf("Email: %s\n", contatos[indiceContato].email);
                }
            break;
            

            case 3: //adiciona um contato
                if (tam >= MAX_CONTATOS) {
                    printf("Agenda cheia!\n");
                    break;
                }

                Contato novo;
                printf("Insira as informações! Novo contato\n\n");
                getchar(); // limpa \n
                printf("Nome: ");
                fgets(novo.nome, sizeof(novo.nome), stdin);
                novo.nome[strcspn(novo.nome, "\n")] = 0;

                printf("Telefone: ");
                fgets(novo.telefone, sizeof(novo.telefone), stdin);
                novo.telefone[strcspn(novo.telefone, "\n")] = 0;

                printf("Email: ");
                fgets(novo.email, sizeof(novo.email), stdin);
                novo.email[strcspn(novo.email, "\n")] = 0;

                contatos[tam] = novo;
                tam++;

                FILE *arq = fopen(nomeArquivo, "a");
                if (arq == NULL)
                    printf("Erro ao salvar o contato!\n");
                else {
                    fprintf(arq, "%s;%s;%s\n", novo.nome, novo.telefone, novo.email);
                    fclose(arq);
                    printf("Adicionando o contato...\n");
                    fflush(stdout);
                    sleep(2);
                    printf("Contato salvo com sucesso!\n");
                }
            break;

            case 4: //remover contato
                char nomeRemover[50];
                int indiceRemover;
                
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                
                printf("Insira as informações! Remover contato\n\n");
                getchar();
                printf("Nome: ");
                fgets(nomeRemover, sizeof(nomeRemover), stdin);
                nomeRemover[strcspn(nomeRemover, "\n")] = 0;
                
                indiceRemover = buscarContato(contatos, tam, nomeRemover);
                
                printf("Procurando contato...\n\n");
                fflush(stdout);
                sleep(2);
                
                if(indiceRemover == -1)
                    printf("Contato não encontrado!\n");
                else 
                {
                    printf("Contato encontrado!\n\n");
                    for (int i = indiceRemover; i < tam - 1; i++) 
                    {
                        contatos[i] = contatos[i + 1];
                    }
                    tam--; //reduz o número de contatos
                    
                    FILE *arq = fopen(nomeArquivo, "w");
                    if (arq == NULL) 
                    {
                        printf("Erro ao atualizar o arquivo!\n");
                    } 
                    else 
                    {
                        for (int i = 0; i < tam; i++) 
                        {
                            fprintf(arq, "%s;%s;%s\n", contatos[i].nome, contatos[i].telefone, contatos[i].email);
                        }
                        
                        fclose(arq);
                        printf("Removendo contato...\n");
                        fflush(stdout);
                        sleep(5);
                        printf("Contato removido com sucesso!\n");
                    }
                }
                
            break;    

            case 0: // sair do programa 
                printf("Saindo...\n");
                sleep(2);
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                sleep(2);
                break;
        }

        printf("\n"); // Espaço para melhor leitura

    } while(op != 0); // Menu

    return 0;
}
//MAIN


//Funções
int lerContatos(Contato vet[], char nomeArquivo[])//função 1 - ler os contatos
{
    int i = 0;
    char linha[200];
    FILE *arq;
    
    arq = fopen(nomeArquivo, "r");
    if(arq==NULL)
        return 1;
    
     while(fgets(linha, sizeof(linha), arq) != NULL && i < MAX_CONTATOS)
    {
        // Remove o \n do final da linha (se existir)
        linha[strcspn(linha, "\n")] = 0;

        // Quebra a linha pelos ';'
        char *nome = strtok(linha, ";");
        char *telefone = strtok(NULL, ";");
        char *email = strtok(NULL, ";");

        if(nome && telefone && email)
        {
            strncpy(vet[i].nome, nome, sizeof(vet[i].nome));
            strncpy(vet[i].telefone, telefone, sizeof(vet[i].telefone));
            strncpy(vet[i].email, email, sizeof(vet[i].email));
            i++;
        }
    }
    fclose(arq);
    
    return i;
}

void listarContatos(Contato vet[], int tam)//função 2 - lista os contatos
{
    for(int i = 0; i < tam; i++)
    {
        printf("[%d] Nome: %s\n", i+1, vet[i].nome);
        printf("Telefone: %s\n", vet[i].telefone);
        printf("Email: %s\n", vet[i].email);
        printf("\n");
    }
}

int buscarContato(Contato vet[], int tam, char contatoBuscado[])//função 3 - busca o contato
{
    for(int i = 0; i < tam; i ++)
    {
        if(strcmp(vet[i].nome, contatoBuscado) == 0)
        {
            return i;
        }
    }
    
    return -1;
}
//Funções