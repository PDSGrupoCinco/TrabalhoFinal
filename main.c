#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

void styleMenu();
void examMenu();

int main(){
    system("clear");
    int opcao = -1;

    while(true){

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
                printf("Sair\n");
                exit(0);
                break;

            default:
                system("clear");
                printf("Opcao invalida!\n");
                break;

        }

    }

    return 0;
}

void styleMenu(){

    system("clear");
    int opcao = -1;

    while(true){

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
                main();
                break;

            default:
                system("clear");
                printf("Opcao invalida!\n");
                break;

        }

    }

}

void examMenu(){

    system("clear");
    int opcao = -1;

    while(true){

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
                printf("Vestibulares\n");
                break;

            case 0:
                system("clear");
                main();
                break;

            default:
                system("clear");
                printf("Opcao invalida!\n");
                break;

        }

    }

}