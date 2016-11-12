#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

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
                printf("Estilo\n");
                break;

            case 2:

                system("clear");
                printf("Vestibular\n");
                break;

            case 0:

                system("clear");
                printf("Sair\n");
                return 0;

            default:
                system("clear");
                printf("Opcao invalida!\n");
                break;

        }

    }

    return 0;
}