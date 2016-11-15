#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#define MAX 100
#define LIMPA_TELA system("clear"); system("clear");

// Protótipos MENU

void siteMenu();
void styleMenu();
void examMenu();

//Protótipos Vestibulares

void exams();
void registerExam();
void listExams();

// Protótipos Faculdades/Universidades

void validaOpcao(int *pOpcao);
void cadastro();
void editaDados();
void lista();
void deleta();
void validaNome(char *pNome);
void validaConfirma(int *pComfima);
void buscaChave(char *pNome);
void mudaLetra (char *palavra);
int university();

// Variáveis globais Faculdades/Universidades

int guardaPosicao = 0;

// Struct Faculdades/Universidades

typedef struct
{
    char nome[MAX];
    char uf[MAX];
    char tipo[MAX];

} faculdades;

// Struct Vestibular

typedef struct
{

    char nome[MAX];
    char uf[MAX];
    char instituicao[MAX];
    char fase[MAX];
    char descricao[300];
    char chamada[MAX];
    char data[MAX];
    float valor;
    int vagas;

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
                university();
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
                listExams();
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
    validaNome(evento.nome);



    printf("\nSigla da Instituicao: ");
    fgets(evento.instituicao,MAX,stdin);
    __fpurge(stdin);
    validaNome(evento.instituicao);



    printf("\nUnidade Federativa: ");
    fgets(evento.uf,MAX,stdin);
    __fpurge(stdin);
    validaNome(evento.uf);


    printf("\nFase: ");
    fgets(evento.fase,MAX,stdin);
    __fpurge(stdin);
    validaNome(evento.fase);

    printf("\nChamada: ");
    fgets(evento.chamada,MAX,stdin);
    __fpurge(stdin);
    validaNome(evento.chamada);

    printf("\nValor da Inscricao: ");
    scanf("%f", &evento.valor);
    __fpurge(stdin);

    printf("\nQuantidade de vagas: ");
    scanf("%d", &evento.vagas);
    __fpurge(stdin);

    printf("\nData da prova: ");
    fgets(evento.data,MAX,stdin);
    validaNome(evento.data);
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
            fwrite(&evento,sizeof(vestibular),1,arqRegistro);
            fclose(arqRegistro);
            break;
        case 2:
            system("clear");
            break;
        default:
            //Do nothing
            break;
    }

}



//Listar Vestibular

void listExams(){

    vestibular eventos;
    FILE *arqListagem;
    int contador = 0;
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;
    int confirma;
    vestibular *pMalloc;


   system("clear");
    if ((arqListagem = fopen("Vestibulares.txt","a+")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }



    while (fread(&eventos,sizeof(vestibular),1,arqListagem) == 1)
    {
        contador++;
    }

    if (contador == 0)
    {
        //LIMPA_TELA;
        printf("Nenhum Vestibular Encontrado\n\n");
        return;
    }

    rewind(arqListagem);

    pMalloc = (vestibular *)malloc(contador * sizeof(vestibular));

    while (fread(&pMalloc[aux],sizeof(vestibular),1,arqListagem) == 1)
    {
        aux++;
    }

    for(aux = 0; aux < contador - 1; aux++)
    {
        for(aux2 = aux + 1; aux2 < contador; aux2++)
        {
            if (strcmp(pMalloc[aux].nome,pMalloc[aux2].nome) > 0)
            {
                eventos = pMalloc[aux2];
                pMalloc[aux2] = pMalloc[aux];
                pMalloc[aux] = eventos;
            }
        }
    }

    printf("\t\t\t\t\t\tVestibulares Cadastrados\n\n");

    while (aux3 != contador)
    {
        printf("Nome: %s Instituicao: %s UF: %s Fase: %s Chamada: %s Vagas: %d Valor: %.2f Data: %s Descricao: %s", pMalloc[aux3].nome, pMalloc[aux3].instituicao, pMalloc[aux3].uf, pMalloc[aux3].fase, pMalloc[aux3].chamada, pMalloc[aux3].vagas, pMalloc[aux3].valor, pMalloc[aux3].data, pMalloc[aux3].descricao);
        aux3++;
    }
    printf("\n");

    printf("0 - Voltar\n");
    scanf("%d",&confirma);

    __fpurge(stdin);

    while(confirma != 0)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",&confirma);
        __fpurge(stdin);
    }

    system("clear");

    fclose(arqListagem);

}
































































































// Parte Lucas Penido e Lucas Siqueira
// Vestibulares - Faculdades/Universidades

int university(void)
{
// Declaracoes
    int opcao;
// Instrucoes
    while (opcao != 5)
    {

        printf("\t\tFACULDADES\n\n");
        printf("1. Cadastrar \n2. Editar \n3. Listar \n4. Deletar \n5. Sair\n");
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
            deleta();
        }

    }
    return 0;
}

void validaOpcao(int *pOpcao)
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

void validaNomeChave(char *pNome)
{
    FILE *pArquivo;
    faculdades cadastro;

    if ((pArquivo = fopen("faculdades.txt","rt")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (!feof(pArquivo))
    {
        if ((fread(&cadastro,sizeof(faculdades),1,pArquivo)) == 1)
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

void validaConfirma(int *pConfirma)
{

    while(*pConfirma != 1 && *pConfirma != 0)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pConfirma);
        __fpurge(stdin);
    }
}


void cadastro()
{
    //Declaraões locais
    faculdades cadastrar;
    FILE *pArquivo;
    int confirma;

    // Instruções



    if ((pArquivo = fopen("faculdades.txt","a+")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }
    LIMPA_TELA;

    printf("\t\tCadastrar\n\n");

    printf ("Informe o nome da Faculdade : \n");
    fgets(cadastrar.nome,MAX,stdin);
    __fpurge(stdin);



    validaNome(cadastrar.nome);

    validaNomeChave(cadastrar.nome);

    __fpurge(stdin);

    printf("Informe o UF : \n");
    fgets(cadastrar.uf,MAX,stdin);

    __fpurge(stdin);

    validaNome(cadastrar.uf);

    __fpurge(stdin);

    printf("Informe se a faculdade e publica ou particular : \n");
    fgets(cadastrar.tipo,MAX,stdin);
    __fpurge(stdin);



    validaNome(cadastrar.tipo);

    __fpurge(stdin);

    printf("\n1 - Salvar\n0 - Cancelar\n");
    scanf("%d",&confirma);

    __fpurge(stdin);

    validaConfirma(&confirma);
    LIMPA_TELA;

    switch(confirma)
    {
    case 1:
        if (fwrite(&cadastrar,sizeof(faculdades),1,pArquivo) == 1)
        {
            printf("Faculdade cadastrada\n\n");
        }
        else
        {
            printf("Erro no cadastro");
        }
        break;
    }

    fclose(pArquivo);
}

void deleta()
{
    //Declaração locais
    int escolhe;
    //Instruções
    LIMPA_TELA;
    printf("\t\tDeletar\n\n");
    printf("Deseja excluir todas as faculdades cadastradas?\n1 - SIM\n0 - NAO\n");
    scanf("%d",&escolhe);

    __fpurge(stdin);

    validaConfirma(&escolhe);

    switch (escolhe)
    {
    case 1:
        remove("faculdades.txt");
        LIMPA_TELA;
        printf("Arquivo excluido com sucesso. \n");
        break;
    case 0:
        LIMPA_TELA;
        printf("Exclusão de arquivo cancelada. \n");
    }

    return;
}

void lista()
{
//Declaraões locais
    faculdades cadastros;
    FILE *pArquivos;
    int contador = 0;
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;
    int confirma;
    faculdades *pMalloc;
//Instruções

    LIMPA_TELA;
    if ((pArquivos = fopen("faculdades.txt","a+")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }



    while (fread(&cadastros,sizeof(faculdades),1,pArquivos) == 1)
    {
        contador++;
    }

    if (contador == 0)
    {
        LIMPA_TELA;
        printf("Nenhuma Faculdade para listar\n\n");
        return;
    }

    rewind(pArquivos);

    pMalloc = (faculdades *)malloc(contador * sizeof(faculdades));

    while (fread(&pMalloc[aux],sizeof(faculdades),1,pArquivos) == 1)
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
    printf("Nome \t\t UF \t\t Tipo \n");

    while (aux3 != contador)
    {
        printf("\n%s \t\t %s \t\t %s\n",pMalloc[aux3].nome,pMalloc[aux3].uf,pMalloc[aux3].tipo);
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

void editaDados()
{
    //Declarações:
    faculdades dados;
    FILE *pArquivos;
    FILE *arquivoNovo;
    int escolha=0;
    char chave[MAX];
    int opcao2=0;
    int confirmacao=0;

    //Instruções:
    if ((pArquivos = fopen("faculdades.txt","r+")) == NULL)
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
        printf("Nenhuma Faculdade cadastrada\n\n");
        return;
    }
    LIMPA_TELA;
    printf("\t\tEditar\n\n");


    printf("Informe o nome da faculdade que deseja editar: \n");
    fgets(chave,MAX,stdin);



    __fpurge(stdin);

    validaNome(chave);

    buscaChave(chave);

    if(guardaPosicao == 0)
    {
        LIMPA_TELA;
        printf("Faculdade inexistente!! \n");
        return;
    }
    printf("\nEssa e a faculdade que deseja editar?\n1 - SIM\n0 - NAO\n");
    scanf("%d",&escolha);
    __fpurge(stdin);

    validaConfirma(&escolha);

    if (escolha == 0)
    {
        return;
    }

    fseek(pArquivos,((guardaPosicao - 1) * sizeof(faculdades)), SEEK_SET);

    fread(&dados,sizeof(faculdades),1,pArquivos);

    while (opcao2 != 5)
    {
        printf("\nInforme o dado que deseja alterar \n");
        printf("1. Nome \n2. UF \n3. Tipo \n4. Apagar a faculdade \n5. Sair\n");
        printf("Escolha a opcao que deseja: ");
        scanf("%d",&opcao2);
        __fpurge(stdin);

        validaOpcao(&opcao2);

        switch(opcao2)
        {
        case 1:

            printf("Informe o novo nome \n");
            fgets(dados.nome,MAX,stdin);

            __fpurge(stdin);

            validaNome(dados.nome);

            validaNomeChave(dados.nome);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(faculdades)), SEEK_SET);

            if (fwrite(&dados,sizeof(faculdades),1,pArquivos) == 1)
            {
                LIMPA_TELA;
                printf("\t\tEditar\n");
                printf("\nAlteracao realizada com sucesso\n\n");
                printf("Nome: %s \n",dados.nome);
                printf("UF: %s \n",dados.uf);
                printf("Tipo: %s \n",dados.tipo);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);

            break;
        case 2:
            printf("Informe a nova UF \n");
            fgets(dados.uf,MAX,stdin);


            __fpurge(stdin);

            validaNome(dados.uf);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(faculdades)), SEEK_SET);

            if (fwrite(&dados,sizeof(faculdades),1,pArquivos) == 1)
            {
                LIMPA_TELA;
                printf("\t\tEditar\n");
                printf("\nAlteracao realizada com sucesso\n");
                printf("NOME: %s \n",dados.nome);
                printf("UF: %s \n",dados.uf);
                printf("TIPO: %s \n",dados.tipo);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);
            break;

        case 3:
            printf("Informe o novo tipo\n");
            fgets(dados.tipo,MAX,stdin);


            __fpurge(stdin);

            validaNome(dados.nome);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(faculdades)), SEEK_SET);

            if (fwrite(&dados,sizeof(faculdades),1,pArquivos) == 1)
            {
                LIMPA_TELA;
                printf("\t\tEditar\n");
                printf("\nAlteracao realizada com sucesso\n");
                printf("NOME: %s \n",dados.nome);
                printf("UF: %s \n",dados.uf);
                printf("TIPO = %s \n",dados.tipo);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);
            break;
        case 4:
            printf("Deseja mesmo deletar a faculdade(digite 1 para sim ou 0 para nao)\n");
            scanf("%d",&confirmacao);
            fflush(stdin);

            validaConfirma(&confirmacao);
            printf("X%dX",confirmacao);
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
                if(fread(&dados,sizeof(faculdades),1,pArquivos) == 1)
                {
                    if(strcmp(dados.nome,chave)!=0)
                    {
                        if(fwrite(&dados,sizeof(faculdades),1,arquivoNovo) == 1)
                        {
                        }
                    }
                }
            }

            fclose(pArquivos);
            fclose(arquivoNovo);

            remove("faculdades.txt");
            rename("copia.txt","faculdades.txt");
            LIMPA_TELA;
            printf("Faculdade Excluida\n\n");
            return;
        }
    }

    LIMPA_TELA;

    return;
}

void buscaChave(char *pNome)
{
    FILE *pArquivo;
    faculdades cadastro;
    int contador = 0;
    guardaPosicao = 0;


    if ((pArquivo = fopen("faculdades.txt","rt")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (!feof(pArquivo))
    {
        contador++;
        if ((fread(&cadastro,sizeof(faculdades),1,pArquivo)) == 1)
        {
            if (strcmp(pNome,cadastro.nome) == 0)
            {
                printf("Nome: %s \n",cadastro.nome);
                printf("UF: %s \n",cadastro.uf);
                printf("Tipo: %s \n",cadastro.tipo);
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