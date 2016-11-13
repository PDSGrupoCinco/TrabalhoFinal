#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define MAX 100

// Protótipos MENU

void siteMenu();
void styleMenu();
void examMenu();
void validaConfirma(int *pComfima);

//Protóripos Vestibulares

void exams();
void registerExam();

// Struct Vestibular

typedef struct
{

    char nome[MAX];
    char uf[MAX];
    char instituicao[MAX];
    char fase[MAX];
    char descricao[300];
    char chamada[MAX];

}vestibular;



int main(){

    siteMenu();
    return 0;

}




//MENU PRINCIPAL DA APLICAÇÃO

void siteMenu(){

    system("clear");
    int opcao = -1;

    while(opcao != 0){

        printf("\t\t *** Site Uol  ***\n");
        printf("1 - Estilo\n");
        printf("2 - Vestibular\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        __fpurge(stdin);

        switch (opcao){

            case 1:
                system("clear");
                styleMenu();
                break;

            case 2:
                system("clear");
                examMenu();
                break;

            case 0:
                system("clear");
                //Simplesmente sai do laço voltando para a main()
                break;

            default:
                system("clear");
                printf("Opcao invalida!\n");
                break;

        }

    }
}





// Menu ESTILO da aplicação

void styleMenu(){

    system("clear");
    int opcao = -1;

    while(opcao !=  0){

        printf("\t\t *** Estilo  ***\n");
        printf("1 - Signos\n");
        printf("2 - Viagens\n");
        printf("0 - Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        __fpurge(stdin);

        switch (opcao){

            case 1:
                system("clear");
                //AQUI ENTRA A FUNÇÃO RESPONSÁVEL PELOS SIGNOS - LUCAS KISHIMA
                printf("Signos\n");
                break;

            case 2:
                //AQUI ENTRA A FUNÇÃO RESPONSÁVEL PELAS VIAGENS - LUCIANA E LUCIANO
                system("clear");
                printf("Viagens\n");
                break;

            case 0:
                system("clear");
                //Sai do laço e volta para a função siteMenu();
                break;

            default:
                system("clear");
                printf("Opcao invalida!\n");
                break;

        }

    }

}




// Menu VESTIBULARES da aplicação

void examMenu(){

    system("clear");
    int opcao = -1;

    while(opcao != 0){

        printf("\t\t *** Vestibular  ***\n");
        printf("1 - Faculdades / Universidades\n");
        printf("2 - Vestibulares\n");
        printf("0 - Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        __fpurge(stdin);

        switch (opcao){

            case 1:
                system("clear");
                //AQUI ENTRA A FUNÇÃO RESPONSÁVEL PELA PARTE FACULDADES / UNIVERSIDADES - LUCAS PENIDO E LUCAS SIQUEIRA
                printf("Faculdades / Universidades \n");
                break;

            case 2:
                //AQUI ENTRA A FUNÇÃO RESPONSÁVEL PELOS VESTIBULARES - LUCAS SOARES E LUDE RIBEIRO
                system("clear");
                exams();
                break;

            case 0:
                system("clear");
                //Sai do laço voltando para função siteMenu()
                break;

            default:
                system("clear");
                printf("Opcao invalida!\n");
                break;

        }

    }

}


// Parte Lucas S. Souza e Lude Ribeiro
// Vestibulares - Vestibulares

void exams(){
    system("clear");
    int opcao = -1;

    while(opcao != 0){

        printf("\t\t *** Vestibulares  ***\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Atualizar\n");
        printf("5 - Excluir\n");
        printf("0 - Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        __fpurge(stdin);

        switch (opcao){

            case 1:
                system("clear");
                registerExam();
                break;

            case 2:
                system("clear");
                printf("Listar\n");
                break;

            case 3:
                system("clear");
                printf("Buscar\n");
                break;

            case 4:
                system("clear");
                printf("Atualizar\n");
                break;

            case 5:
                system("clear");
                printf("Excluir\n");
                break;

            case 0:
                system("clear");
                //Sai do laço voltando para a função examsMenu()
                break;

            default:
                system("clear");
                printf("Opcao invalida!\n");
                break;

        }

    }

}


//Cadastrar Vestibular

void registerExam(){

    FILE *arqRegistro;
    vestibular evento;
    int opcao = -1;

    arqRegistro = fopen("Vestibulares.txt", "a+");

    if(!arqRegistro){
        printf("O arquivo nao pode ser encontrado e/ou aberto!");
        system("PAUSE");
        return;
    }

    system("clear");
    printf("Registre o Vestibular:\n");

    printf("Nome: ");
    fgets(evento.nome,MAX,stdin);
    __fpurge(stdin);

    printf("\nInstituicao: ");
    fgets(evento.instituicao,MAX,stdin);
    __fpurge(stdin);

    printf("\nUnidade Federativa: ");
    fgets(evento.uf,MAX,stdin);
    __fpurge(stdin);

    printf("\nFase: ");
    fgets(evento.fase,MAX,stdin);
    __fpurge(stdin);

    printf("\nChamada: ");
    fgets(evento.chamada,MAX,stdin);
    __fpurge(stdin);

    printf("\nDescricao: ");
    fgets(evento.descricao,MAX,stdin);
    __fpurge(stdin);

    printf("\nDeseja salvar?\n");
    printf("1 - Sim\n");
    printf("0 - Nao\n");
    scanf("%d", &opcao);
    __fpurge(stdin);

    validaConfirma(&opcao);

    switch(opcao){
        case 1:
            system("clear");
            fprintf(arqRegistro,"%s %s %s %s %s %s\n", evento.nome, evento.instituicao, evento.uf, evento.fase, evento.chamada, evento.descricao);
            fclose(arqRegistro);
            break;
        case 2:
            printf("Nao Salvar\n");
            break;
        default:
            //Do nothing
            break;
    }

}

void validaConfirma(int *pConfirma)
{

    while(*pConfirma != 1 && *pConfirma != 0)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pConfirma);
        __fpurge(stdin);
    }
}


// Parte Lucas Penido e Lucas Siqueira
// Vestibulares - Faculdades/Universidades

