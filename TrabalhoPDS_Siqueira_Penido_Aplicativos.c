#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#define MAX 100
#define LIMPA_TELA system("clear"); system("clear");

typedef struct
{
    char nome[MAX];
    char plataforma[MAX];
    double memoria;
    char descricao[300];

} aplicativos;

int guardaPosicao = 0;

//Prototipos

void cadastro();
void editaDados();
void lista();
void busca();
void deleta();
void validaNomeChave(char *pNome);
void validaNum (double *num);
void validaOpcao(int *pOpcao);
void validaOpcao2(int *pOpcao);
void validaNome(char *pNome);
void validaMenuBusca(int *pOpcao);
void validaConfirma(int *pComfima);
void buscaChave(char *pNome);
void buscaPlataforma(char *pNome);
void mudaLetra (char *palavra);

int main(void)
{
// Declaracoes
    int opcao;
// Instrucoes
    while (opcao != 6)
    {
        printf("\t\tAPLICATIVOS PARA INTERCAMBIO\n\n");
        printf("1. Cadastrar \n2. Alterar \n3. Listar\n4. Buscar\n5. Deletar \n6. Sair\n");
        printf("Escolha a opcao que deseja: ");
        scanf("%d",&opcao);
        __fpurge(stdin);
        validaOpcao(&opcao);
        switch (opcao)
        {
        case 1:
            cadastro();
            break;
        case 2:
            editaDados();
            break;
        case 3:
            lista();
            break;
        case 4:
            busca();
            break;
        case 5:
            deleta();
            break;
        }

    }
    return 0;
}



void cadastro()
{
    //Declaraões locais
    aplicativos cadastrar;
    FILE *pArquivo;
    int confirma;

    // Instruções

    if ((pArquivo = fopen("aplicativos.txt","a+")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }
    LIMPA_TELA;

    printf("\t\tCadastrar\n\n");

    printf ("Informe o nome do Aplicativo : \n");
    fgets(cadastrar.nome,MAX,stdin);
    __fpurge(stdin);

    validaNome(cadastrar.nome);

    validaNomeChave(cadastrar.nome);

    __fpurge(stdin);

    printf("Informe a Plataforma : \n");
    fgets(cadastrar.plataforma,MAX,stdin);

    __fpurge(stdin);

    validaNome(cadastrar.plataforma);

    __fpurge(stdin);

    printf("Informe o Tamanho em MB: \n");

    scanf("%lf",&cadastrar.memoria);

    __fpurge(stdin);


    validaNum(&cadastrar.memoria);

    printf("Informe a Descricao : \n");

    fgets(cadastrar.descricao,300,stdin);

    __fpurge(stdin);

    validaNome(cadastrar.descricao);

    __fpurge(stdin);

    printf("\n1 - Salvar\n0 - Cancelar\n");
    scanf("%d",&confirma);

    __fpurge(stdin);

    validaConfirma(&confirma);
    LIMPA_TELA;

    switch(confirma)
    {
    case 1:
        if (fwrite(&cadastrar,sizeof(aplicativos),1,pArquivo) == 1)
        {
            printf("Aplicativo cadastrado\n\n");
        }
        else
        {
            printf("Erro no cadastro");
        }
        break;
    }

    fclose(pArquivo);
}

void editaDados()
{
    //Declarações:
    aplicativos dados;
    FILE *pArquivos;
    FILE *arquivoNovo;
    int escolha=0;
    char chave[MAX];
    int opcao2=0;
    int confirmacao=0;

    //Instruções:
    if ((pArquivos = fopen("aplicativos.txt","r+")) == NULL)
    {
        LIMPA_TELA;
        printf("Erro ao abrir o arquivo\n\n");
        return;
    }

    //Verifica se o arquivo está vazio
    fseek (pArquivos, 0, SEEK_END);
    if (ftell (pArquivos) == 0)
    {
        LIMPA_TELA;
        printf("Nenhum Aplicativo para alterar\n\n");
        return;
    }
    LIMPA_TELA;
    printf("\t\tALTERAR\n\n");


    printf("Informe o nome do aplicativo que deseja alterar: \n");
    fgets(chave,MAX,stdin);

    __fpurge(stdin);

    validaNome(chave);

    buscaChave(chave);

    if(guardaPosicao == 0)
    {
        LIMPA_TELA;
        printf("Aplicativo inexistente!! \n");
        return;
    }
    printf("\nEssa e o aplicativo que deseja alterar?\n1 - SIM\n0 - NAO\n");
    scanf("%d",&escolha);
    __fpurge(stdin);

    validaConfirma(&escolha);

    if (escolha == 0)
    {
        return;
    }

    fseek(pArquivos,((guardaPosicao - 1) * sizeof(aplicativos)), SEEK_SET);

    fread(&dados,sizeof(aplicativos),1,pArquivos);

    while (opcao2 != 6)
    {
        printf("\nInforme o dado que deseja alterar \n");
        printf("1. Nome \n2. Plataforma \n3. Tamanho \n4. Descricao \n5. Apagar o Aplicativo \n6. Sair\n");
        printf("Escolha a opcao que deseja: ");
        scanf("%d",&opcao2);
        __fpurge(stdin);

        validaOpcao2(&opcao2);

        switch(opcao2)
        {
        case 1:

            printf("Informe o novo nome \n");
            fgets(dados.nome,MAX,stdin);

            __fpurge(stdin);

            validaNome(dados.nome);

            validaNomeChave(dados.nome);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(aplicativos)), SEEK_SET);

            if (fwrite(&dados,sizeof(aplicativos),1,pArquivos) == 1)
            {
                LIMPA_TELA;
                printf("\nAlteracao realizada com sucesso\n\n");
                printf("Nome: %s \n",dados.nome);
                printf("Plataforma: %s \n",dados.plataforma);
                printf("Tamanho: %.2lf MB \n",dados.memoria);
                printf("Descricao: %s \n",dados.descricao);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
            break;
        case 2:
            printf("Informe a nova Plataforma \n");
            fgets(dados.plataforma,MAX,stdin);


            __fpurge(stdin);

            validaNome(dados.plataforma);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(aplicativos)), SEEK_SET);

            if (fwrite(&dados,sizeof(aplicativos),1,pArquivos) == 1)
            {
                LIMPA_TELA;
                printf("\nAlteracao realizada com sucesso\n\n");
                printf("Nome: %s \n",dados.nome);
                printf("Plataforma: %s \n",dados.plataforma);
                printf("Tamanho: %lf MB \n",dados.memoria);
                printf("Descricao: %s \n",dados.descricao);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
            break;

        case 3:
            printf("Informe o novo Tamanho em MB \n");
            scanf(".2%lf",&dados.memoria);
            __fpurge(stdin);
            validaNum(&dados.memoria);


            fseek(pArquivos,((guardaPosicao - 1) * sizeof(aplicativos)), SEEK_SET);

            if (fwrite(&dados,sizeof(aplicativos),1,pArquivos) == 1)
            {
                LIMPA_TELA;
                printf("\nAlteracao realizada com sucesso\n\n");
                printf("Nome: %s \n",dados.nome);
                printf("Plataforma: %s \n",dados.plataforma);
                printf("Tamanho: %lf MB \n",dados.memoria);
                printf("Descricao: %s \n",dados.descricao);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
            break;
        case 4:
            printf("Informe a nova descricao \n");
            fgets(dados.descricao,MAX,stdin);

            __fpurge(stdin);

            validaNome(dados.descricao);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(aplicativos)), SEEK_SET);

            if (fwrite(&dados,sizeof(aplicativos),1,pArquivos) == 1)
            {
                LIMPA_TELA;
                printf("\nAlteracao realizada com sucesso\n\n");
                printf("Nome: %s \n",dados.nome);
                printf("Plataforma: %s \n",dados.plataforma);
                printf("Tamanho: MB %.2lf \n",dados.memoria);
                printf("Descricao: %s \n",dados.descricao);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
            break;
        case 5:
            printf("\nDeseja mesmo deletar o Aplicativo?\n1 - SIM\n0 - NAO\n");
            scanf("%d",&confirmacao);
            fflush(stdin);

            validaConfirma(&confirmacao);

            switch(confirmacao)
            {
            case 0:
                return;
            }

            if((arquivoNovo = fopen("copia.txt","wt")) == NULL)
            {
            }

            rewind(pArquivos);

            while(!feof(pArquivos))
            {
                if(fread(&dados,sizeof(aplicativos),1,pArquivos) == 1)
                {
                    if(strcmp(dados.nome,chave)!=0)
                    {
                        if(fwrite(&dados,sizeof(aplicativos),1,arquivoNovo) == 1)
                        {
                        }
                    }
                }
            }

            fclose(pArquivos);
            fclose(arquivoNovo);

            remove("aplicativos.txt");
            rename("copia.txt","aplicativos.txt");
            LIMPA_TELA;
            printf("Aplicativo Excluido\n\n");
            return;
        }
    }

    LIMPA_TELA;

    return;
}


void lista()
{
//Declaraões locais
    aplicativos cadastros;
    FILE *pArquivos;
    int contador = 0;
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;
    int confirma;
    aplicativos *pMalloc;
//Instruções

    LIMPA_TELA;
    if ((pArquivos = fopen("aplicativos.txt","a+")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }



    while (fread(&cadastros,sizeof(aplicativos),1,pArquivos) == 1)
    {
        contador++;
    }

    if (contador == 0)
    {
        LIMPA_TELA;
        printf("Nenhum Aplicativo para listar\n\n");
        return;
    }

    rewind(pArquivos);

    pMalloc = (aplicativos *)malloc(contador * sizeof(aplicativos));

    while (fread(&pMalloc[aux],sizeof(aplicativos),1,pArquivos) == 1)
    {
        aux++;
    }

    for(aux = 0; aux < contador - 1; aux++)
    {
        for(aux2 = aux + 1; aux2 < contador; aux2++)
        {
            if (strcmp(pMalloc[aux].nome,pMalloc[aux2].nome) > 0)
            {
                cadastros = pMalloc[aux2];
                pMalloc[aux2] = pMalloc[aux];
                pMalloc[aux] = cadastros;
            }
        }
    }

    printf("\t\tListar\n\n");
    printf("Nome\n");

    while (aux3 != contador)
    {
        printf("\n%s\n",pMalloc[aux3].nome);
        aux3++;
    }
    printf("\n");

    printf("1 - Voltar\n");
    scanf("%d",&confirma);

    __fpurge(stdin);

    while(confirma != 1)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",&confirma);
        __fpurge(stdin);
    }

    LIMPA_TELA;

    fclose(pArquivos);

}

void busca()
{
    FILE *pArquivos;
    int escolha;
    int confirma;
    char busca[MAX];

    //Instruções:
    if ((pArquivos = fopen("aplicativos.txt","r+")) == NULL)
    {
        LIMPA_TELA;
        printf("Erro ao abrir o arquivo\n\n");
        return;
    }

    //Verifica se o arquivo está vazio
    fseek (pArquivos, 0, SEEK_END);
    if (ftell (pArquivos) == 0)
    {
        LIMPA_TELA;
        printf("Nenhum Aplicativo para buscar\n\n");
        return;
    }

    LIMPA_TELA;
    printf("\t\tBUSCAR\n\n");
    printf("Busca por:\n 1-Nome \n 2-Plataforma \n 3-Sair\n");
    printf("Escolha a opcao que deseja: ");
    scanf("%d",&escolha);
    validaMenuBusca(&escolha);
    __fpurge(stdin);
    switch(escolha)
    {
    case 1:
        printf("informe o nome: \n");
        fgets(busca,MAX,stdin);
        __fpurge(stdin);
        validaNome(busca);
        LIMPA_TELA;
        buscaChave(busca);
        break;

    case 2:
        printf("informe a Plataforma: \n");
        fgets(busca,MAX,stdin);
        __fpurge(stdin);
        validaNome(busca);
        LIMPA_TELA;
        buscaPlataforma(busca);
        break;

    case 3:
        LIMPA_TELA;
        return;
    }

    printf("1 - Voltar\n");
    scanf("%d",&confirma);

    __fpurge(stdin);

    while(confirma != 1)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",&confirma);
        __fpurge(stdin);
    }

    LIMPA_TELA;
}


void deleta()
{
    //Declaração locais
    int escolhe;
    //Instruções
    LIMPA_TELA;
    printf("\t\tDeletar\n\n");
    printf("Deseja excluir todos os Aplicativos cadastrados?\n1 - SIM\n0 - NAO\n");
    scanf("%d",&escolhe);

    __fpurge(stdin);

    validaConfirma(&escolhe);

    switch (escolhe)
    {
    case 1:
        remove("aplicativos.txt");
        LIMPA_TELA;
        printf("Arquivo excluido com sucesso. \n");
        break;
    case 0:
        LIMPA_TELA;
        printf("Exclusão de arquivo cancelada. \n");
    }

    return;
}

void validaNomeChave(char *pNome)
{
    FILE *pArquivo;
    aplicativos cadastro;

    if ((pArquivo = fopen("aplicativos.txt","rt")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (!feof(pArquivo))
    {
        if ((fread(&cadastro,sizeof(aplicativos),1,pArquivo)) == 1)
        {
            if (strcmp(pNome,cadastro.nome) == 0)
            {
                printf("Nome ja cadastrada, digite um nome novo \n");
                fgets(pNome,MAX,stdin);
                validaNome(pNome);
                rewind(pArquivo);
            }
        }
    }

    fclose(pArquivo);

}

void validaNum (double *num)
{
    while(*num<=0)
    {
        printf("Digite um tamanho valido\n");
        scanf("%lf",num);
    }
}

void validaOpcao(int *pOpcao)
{

    while(*pOpcao < 1 || *pOpcao > 6)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

    }
}

void validaOpcao2(int *pOpcao)
{

    while(*pOpcao < 1 || *pOpcao > 5)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

    }
}

void validaNome(char *pNome)
{



    while(strlen(pNome) == 1)
    {
        printf("Nome invalido, digite um nome valido\n");
        fgets(pNome,MAX,stdin);

        __fpurge(stdin);
    }
    if (pNome[strlen(pNome) - 1] == '\n')
    {
        pNome[strlen(pNome) -1  ] = '\0';
    }
    mudaLetra(pNome);
}

void validaMenuBusca(int *pOpcao)
{

    while(*pOpcao < 1 || *pOpcao > 4)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

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

void buscaChave(char *pNome)
{
    FILE *pArquivo;
    aplicativos cadastro;
    int contador = 0;
    guardaPosicao = 0;


    if ((pArquivo = fopen("aplicativos.txt","rt")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (!feof(pArquivo))
    {
        contador++;
        if ((fread(&cadastro,sizeof(aplicativos),1,pArquivo)) == 1)
        {
            if (strcmp(pNome,cadastro.nome) == 0)
            {
                printf("\nNome: %s \n",cadastro.nome);
                printf("Plataforma: %s \n",cadastro.plataforma);
                printf("Tamanho: %.2f MB \n",cadastro.memoria);
                printf("Descricao %s \n",cadastro.descricao);
                guardaPosicao = contador;
            }
        }
    }
    fclose(pArquivo);
}

void buscaPlataforma(char *pNome)
{
    FILE *pArquivo;
    aplicativos cadastro;
    int contador = 0;
    guardaPosicao = 0;


    if ((pArquivo = fopen("aplicativos.txt","rt")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (!feof(pArquivo))
    {
        contador++;
        if ((fread(&cadastro,sizeof(aplicativos),1,pArquivo)) == 1)
        {
            if (strcmp(pNome,cadastro.plataforma) == 0)
            {
                printf("\nNome: %s \n",cadastro.nome);
                printf("Plataforma: %s \n",cadastro.plataforma);
                printf("Tamanho: %.2f MB \n",cadastro.memoria);
                printf("Descricao %s \n",cadastro.descricao);
                guardaPosicao = contador;
            }
        }
    }
    fclose(pArquivo);
}

void mudaLetra(char *palavra)
{
    int i;

    for (i=0; palavra[i]!='\0'; i++)
    {
        palavra[i] = toupper(palavra[i]);
    }
}
