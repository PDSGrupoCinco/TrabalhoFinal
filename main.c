#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

void siteMenu();
void styleMenu();
void examMenu();
void exams();


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
                printf("Cadastro\n");
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



// Parte Lucas Penido e Lucas Siqueira
// Vestibulares - Faculdades/Universidades

