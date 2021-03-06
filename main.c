#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#define MAX 100
#define MIN 100
#define LIMPA_TELA system("clear"); system("clear");

// Protótipos MENU

void siteMenu();
void estiloMenu();
void vestibularMenu();

//Protótipos Vestibulares

void vestibulares();
void cadastrarVest();
void listarVest();
void procurarVest();
void apagaVest();
void atualizaVest();
void procurarUFVest(char *uf);
void procurarInstitucaoVest(char *sigla);
void procurarNomeVest(char *nome);
void validaNomeVest(char *vestNome);
void buscarVest(char *vestNome);

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
void validaOpcao2(int *pOpcao);
void buscaUf(char *pNome);
void busca();
void buscaTipo(char *pNome);
void validaMenuBusca(int *pOpcao);
void validaTipo(char *pTipo);
int uniFacul();

// Protótipos Aplicativos para Intercâmbio

void cadastroApp();
void editaDadosApp();
void listaApp();
void buscaApp();
void deletaApp();
void validaNomeChaveApp(char *pNome);
void validaNumApp (double *num);
void validaOpcaoApp(int *pOpcao);
void validaOpcao2App(int *pOpcao);
void validaNomeApp(char *pNome);
void validaMenuBuscaApp(int *pOpcao);
void validaConfirmaApp(int *pComfima);
void buscaChaveApp(char *pNome);
void buscaPlataformaApp(char *pNome);
void mudaLetraApp (char *palavra);
int appIntercambio();

// Protótipos Viagens

void validaOpcaoViagem(int *pOpcao);
void cadastroViagem();
void editaDadosViagem();
void listaViagem();
void deletaViagem();
void validaNomeViagem(char *pNome);
void validaConfirmaViagem(int *pComfima);
void buscaChaveViagem(char *pNome);
void mudaLetraViagem(char *palavra);
void validaOpcao2Viagem(int *pOpcao);
void buscaContViagem(char *pNome);
void buscaViagem();
void buscaLingViagem(char *pNome);
void validaMenuBuscaViagem(int *pOpcao);
void validaLingViagem(char *pTipo);
int estiloViagens();

// Variáveis globais

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


// Struct Aplicativos

typedef struct
{
    char nome[MAX];
    char plataforma[MAX];
    double memoria;
    char descricao[300];

} aplicativos;

// Struct Viagens

typedef struct
{
    char pais[MAX];
    char continente[MAX];
    char lingua[MAX];
    char descricao[MAX];
    char curiosidades[MAX];
    char dicas[MAX];
    char sites[MAX];

}destinos;





// *** MAIN ***

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
                estiloMenu();
                break;

            case 2:
                system("clear");
                vestibularMenu();
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

void estiloMenu(){

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
                printf("\nTrecho ainda nao implementado!\n");
                break;

            case 2:
                //AQUI ENTRA A FUNÇÃO RESPONSÁVEL PELAS VIAGENS - LUCIANA E LUCIANO
                system("clear");
                estiloViagens();
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

void vestibularMenu(){

    system("clear");
    int opcao = -1;

    while(opcao != 0){

        printf("\t\t *** Vestibular  ***\n");
        printf("1 - Faculdades / Universidades\n");
        printf("2 - Vestibulares\n");
        printf("3 - Aplicativos de Auxilio a Intercambio\n");
        printf("0 - Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        __fpurge(stdin);

        switch (opcao){

            case 1:
                system("clear");
                //AQUI ENTRA A FUNÇÃO RESPONSÁVEL PELA PARTE FACULDADES / UNIVERSIDADES - LUCAS PENIDO E LUCAS SIQUEIRA
                uniFacul();
                break;

            case 2:
                //AQUI ENTRA A FUNÇÃO RESPONSÁVEL PELOS VESTIBULARES - LUCAS SOARES E LUDE RIBEIRO
                system("clear");
                vestibulares();
                break;
            case 3:
                //AQUI ENTRA A FUNÇÃO RESPONSÁVEL PELOS APLICATIVOS - LUCAS PENIDO
                system("clear");
                appIntercambio();
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



/**********************************************************************************************************************************/
// Parte Lucas S. Souza e Lude Ribeiro
// Vestibulares - Vestibulares

void vestibulares(){
    int opcao = -1;
    system("clear");
    while(opcao != 0){
        printf("\t\t *** Vestibulares  ***\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Atualizar\n");
        printf("5 - Deletar\n");
        printf("0 - Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        __fpurge(stdin);

        switch (opcao){

            case 1:
                system("clear");
                cadastrarVest();
                break;

            case 2:
                listarVest();
                break;

            case 3:
                system("clear");
                procurarVest();
                break;

            case 4:
                system("clear");
                atualizaVest();
                break;

            case 5:
                system("clear");
                apagaVest();
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

void cadastrarVest(){

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
    validaNomeVest(evento.nome);

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
    system("clear");

    switch(opcao){
        case 1:
            system("clear");
            if(fwrite(&evento,sizeof(vestibular),1,arqRegistro) == 1){
                printf("\nCadastro realizado com sucesso!\n");
            }else{
                printf("\nHouve um erro no cadastro!\n");
            }
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

void listarVest(){

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
        system("clear");
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
        //printf("NOME: %s INSTITUICAO: %s UF: %s FASE: %s CHAMADA: %s VAGAS: %d VALOR: %.2fR$ DATA: %s DESCRICAO: %s", pMalloc[aux3].nome, pMalloc[aux3].instituicao, pMalloc[aux3].uf, pMalloc[aux3].fase, pMalloc[aux3].chamada, pMalloc[aux3].vagas, pMalloc[aux3].valor, pMalloc[aux3].data, pMalloc[aux3].descricao);
        printf("NOME: %s ", pMalloc[aux3].nome);
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

void procurarVest(){

    int opt = -1;
    char palavra[MAX];


    while(opt != 0){

        printf("\t\t\tBusque um Vestibular\n\n");
        printf("1 - Nome\n");
        printf("2 - Sigla da Instituicao\n");
        printf("3 - Unidade Federativa\n");
        printf("0 - Voltar\n");
        printf("\nEscolha um filtro: ");

        scanf("%d", &opt);
        __fpurge(stdin);

        switch(opt){
            case 1:
                system("clear");
                printf("\t\t\tBusca pelo nome:\n\n");
                printf("Digite o nome do evento: ");
                fgets(palavra,MAX,stdin);
                validaNome(palavra);
                __fpurge(stdin);
                procurarNomeVest(palavra);
                break;

            case 2:
                system("clear");
                printf("\t\t\tBusca pela Instituicao:\n\n");
                printf("Digite a sigla da instituicao responsavel pelo evento: ");
                fgets(palavra,MAX,stdin);
                validaNome(palavra);
                __fpurge(stdin);
                procurarInstitucaoVest(palavra);
                break;

            case 3:
                system("clear");
                printf("\t\t\tBusca pela Unidade Federativa:\n\n");
                printf("Digite a sigla da Unidade Federativa onde ocorrerá o evento: ");
                fgets(palavra,MAX,stdin);
                __fpurge(stdin);
                procurarUFVest(palavra);
                break;

            case 0:
                break;

            default:
                system("clear");
                printf("\nValor inválido. Tente novamente\n");
        }

    }
    system("clear");
}

void procurarUFVest(char *uf){

    vestibular eventos;
    FILE *arqListagem;
    int contador = 0;
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;
    int confirma;
    vestibular *pMalloc;

   validaNome(uf);
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
        system("clear");
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

    printf("\t\t\t\t\t\tBusca por vestibulares do %s\n\n", uf);
    int flag = 0;
    while (aux3 != contador)
    {

        if(strcmp(uf,pMalloc[aux3].uf) == 0){
        printf("NOME: %s INSTITUICAO: %s UF: %s FASE: %s CHAMADA: %s VAGAS: %d VALOR: %.2f DATA: %s DESCRICAO: %s", pMalloc[aux3].nome, pMalloc[aux3].instituicao, pMalloc[aux3].uf, pMalloc[aux3].fase, pMalloc[aux3].chamada, pMalloc[aux3].vagas, pMalloc[aux3].valor, pMalloc[aux3].data, pMalloc[aux3].descricao);
        flag++;
        }
        aux3++;
    }

    if(flag == 0){
        printf("Nenhum vestibular desta unidade federativa foi encontrado!");
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

void procurarInstitucaoVest(char *sigla){

    vestibular eventos;
    FILE *arqListagem;
    int contador = 0;
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;
    int confirma;
    vestibular *pMalloc;

   validaNome(sigla);
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
        system("clear");
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

    printf("\t\t\t\t\t\tBusca por vestibulares da instituicao %s\n\n", sigla);
    int flag = 0;
    while (aux3 != contador)
    {

        if(strcmp(sigla,pMalloc[aux3].instituicao) == 0){
        printf("NOME: %s INSTITUICAO: %s UF: %s FASE: %s CHAMADA: %s VAGAS: %d VALOR: %.2f DATA: %s DESCRICAO: %s", pMalloc[aux3].nome, pMalloc[aux3].instituicao, pMalloc[aux3].uf, pMalloc[aux3].fase, pMalloc[aux3].chamada, pMalloc[aux3].vagas, pMalloc[aux3].valor, pMalloc[aux3].data, pMalloc[aux3].descricao);
        flag++;
        }
        aux3++;
    }

    if(flag == 0){
        printf("Nenhum vestibular desta instituicao foi encontrado!");
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

void procurarNomeVest(char *name){

    vestibular eventos;
    FILE *arqListagem;
    int contador = 0;
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;
    int confirma;
    vestibular *pMalloc;

   validaNome(name);
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
        system("clear");
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

    printf("\t\t\t\t\t\tBusca por vestibulares com o nome: %s\n\n", name);
    int flag = 0;
    while (aux3 != contador)
    {

        if(strcmp(name,pMalloc[aux3].nome) == 0){
        printf("NOME: %s INSTITUICAO: %s UF: %s FASE: %s CHAMADA: %s VAGAS: %d VALOR: %.2f DATA: %s DESCRICAO: %s", pMalloc[aux3].nome, pMalloc[aux3].instituicao, pMalloc[aux3].uf, pMalloc[aux3].fase, pMalloc[aux3].chamada, pMalloc[aux3].vagas, pMalloc[aux3].valor, pMalloc[aux3].data, pMalloc[aux3].descricao);
        flag++;
        }
        aux3++;
    }

    if(flag == 0){
        printf("Nenhum vestibular com este nome foi encontrado!\n");
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




void validaNomeVest(char *vestNome)
{
    FILE *arqVest;
    vestibular evento;

    if ((arqVest = fopen("Vestibulares.txt","rt")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (!feof(arqVest))
    {
        if ((fread(&evento,sizeof(vestibular),1,arqVest)) == 1)
        {
            if (strcmp(vestNome,evento.nome) == 0)
            {
                printf("Um vestibular com este nome já foi cadastrado. Por favor entre com outro nome: \n");
                fgets(vestNome,MAX,stdin);
                validaNome(vestNome);
                rewind(arqVest);
            }
        }
    }

    fclose(arqVest);

}

void apagaVest(){

    FILE *arqVest;
    FILE *arqVestNovo;
    vestibular evento;
    char vest[MAX];
    int opt = -1;

    arqVest  =  fopen("Vestibulares.txt", "r+");

    if(!arqVest){
       printf("\nO arquivo com os vestibulares nao pode ser encontrado!\n");
    }


     //Verifica se o arquivo está vazio
    fseek (arqVest, 0, SEEK_END);
    if (ftell (arqVest) == 0)
    {
        system("clear");
        printf("Nenhum vestibular cadastrado!\n\n");
        return;
    }

    printf("\nEntre com o nome do vestibular a ser deletado: \n");
    fgets(vest,MAX,stdin);
    system("clear");
    buscarVest(vest);
    if(guardaPosicao == 0)
    {
        system("clear");
        printf("Vestibular nao encontrado no sistema! \n");
        return;
    }
    printf("\nEste é o vestibular que voce deseja excluir?\n");
    printf("\n1 - Sim\n");
    printf("\n0 - Nao\n");
    scanf("%d", &opt);
    validaConfirma(&opt);

    switch(opt){
        case 1:{
            system("clear");

            arqVestNovo = fopen("temp.txt","wt");
            if(!arqVestNovo){
                printf("\nNovo arquivo vestibular não pode ser criado!\n");
            }

            rewind(arqVest);

            while(!feof(arqVest))
            {
                if(fread(&evento,sizeof(vestibular),1,arqVest) == 1)
                {
                    if(strcmp(evento.nome,vest)!=0)
                    {
                        if(fwrite(&evento,sizeof(vestibular),1,arqVestNovo) == 1)
                        {
                        }
                    }
                }
            }

            fclose(arqVest);
            fclose(arqVestNovo);

            remove("Vestibulares.txt");
            rename("temp.txt","Vestibulares.txt");
            system("clear");
            printf("\nO vestibular foi excluido com sucesso!\n");
            return;
            break;
        }
        case 0:{
            system("clear");
            printf("\nO intem não foi excluido!\n");
            break;
        }
    }

    fclose(arqVest);
}

void buscarVest(char *vestNome)
{
    FILE *arqVest;
    int contador = 0;
    guardaPosicao = 0;
    vestibular evento;

    validaNome(vestNome);
    arqVest = fopen("Vestibulares.txt","rt");

    if (!arqVest){
        printf("Arquivo vestibulares não escontrado!\n");
        return;
    }

    while (!feof(arqVest)){
        contador++;
        if ((fread(&evento,sizeof(vestibular),1,arqVest)) == 1)
        {
            if (strcmp(vestNome,evento.nome) == 0)
            {

                printf("NOME: %s INSTITUICAO: %s UF: %s FASE: %s CHAMADA: %s VAGAS: %d VALOR: %.2fR$ DATA: %s DESCRICAO: %s", evento.nome, evento.instituicao, evento.uf, evento.fase, evento.chamada, evento.vagas, evento.valor, evento.data, evento.descricao);

                guardaPosicao = contador;
            }
        }
    }
    fclose(arqVest);
}

void atualizaVest(){

    FILE *arqVest;
    FILE *arqVestNovo;
    vestibular evento;
    int opcao = 0;
    char vest[MAX];
    int opt = -1;

    arqVest  =  fopen("Vestibulares.txt", "r+");

    if(!arqVest){
       printf("\nO arquivo com os vestibulares nao pode ser encontrado!\n");
    }


     //Verifica se o arquivo está vazio
    fseek (arqVest, 0, SEEK_END);
    if (ftell (arqVest) == 0)
    {
        system("clear");
        printf("Nenhum vestibular cadastrado!\n\n");
        return;
    }

    printf("\nEntre com o nome do vestibular a ser modificado: \n");
    fgets(vest,MAX,stdin);
    system("clear");
    buscarVest(vest);
    if(guardaPosicao == 0)
    {
        system("clear");
        printf("Vestibular nao encontrado no sistema! \n\n");
        return;
    }
    printf("\nEste é o vestibular que voce deseja modificar?\n");
    printf("\n1 - Sim\n");
    printf("\n0 - Nao\n");
    scanf("%d", &opt);
    validaConfirma(&opt);

    switch(opt){
        case 1:{
            system("clear");
            __fpurge(stdin);
            fseek(arqVest,((guardaPosicao - 1) * sizeof(vestibular)), SEEK_SET);
            fread(&evento,sizeof(vestibular),1,arqVest);

            printf("Atualize o Vestibular:\n");
            printf("Nome: ");
            fgets(evento.nome,MAX,stdin);
            __fpurge(stdin);
            validaNomeVest(evento.nome);
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
            if(opcao == 0){
                system("clear");
                printf("\nO intem não foi modificado!\n");
                return;
            }
            fseek(arqVest,((guardaPosicao - 1) * sizeof(vestibular)), SEEK_SET);

            if (fwrite(&evento,sizeof(vestibular),1,arqVest) == 1)
            {
                system("clear");
                printf("\nAlteracao realizada com sucesso\n\n");
            }
            else
            {
                printf("Erro na atualizacao do vestibular\n");
            }
            fclose(arqVest);
            return;
            break;
        }
        case 0:{
            system("clear");
            printf("\nO intem não foi modificado!\n");
            break;
        }
    }

    fclose(arqVest);

}


/**********************************************************************************************************************************/
// Parte Lucas Penido e Lucas Siqueira
// Vestibulares - Faculdades/Universidades

int uniFacul(void)
{
// Declaracoes
    int opcao=-1;
// Instrucoes
    while (opcao != 0)
    {
        printf("\t\t*** Faculdades ***\n\n");
        printf("1 - Cadastrar \n2 - Listar \n3 - Buscar\n4 - Atualizar\n5 - Deletar \n0 - Voltar\n");
        printf("\nEscolha a opcao que deseja: ");
        scanf("%d",&opcao);
        __fpurge(stdin);
        validaOpcao(&opcao);
        switch (opcao)
        {
        case 1:
            cadastro();
            break;
        case 2:
            lista();
            break;
        case 3:
            busca();
            break;
        case 4:
            editaDados();
            break;
        case 5:
            deleta();
            break;
        }
    }
    LIMPA_TELA;
    return 0;
}

void busca()
{
    int escolha;
    int confirma;
    char busca[MAX];

    LIMPA_TELA;
    printf("\t\tBUSCAR\n\n");
    printf("Busca por:\n 1-Nome \n 2-UF \n 3-Tipo \n 4-Sair\n");
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

        if(guardaPosicao == 0)
    {
        LIMPA_TELA;
        printf("Faculdade inexistente!! \n");
        return;
    }
        break;

    case 2:
        printf("informe a UF: \n");
        fgets(busca,MAX,stdin);
        __fpurge(stdin);
        validaNome(busca);
        LIMPA_TELA;
        buscaUf(busca);
        if(guardaPosicao == 0)
    {
        LIMPA_TELA;
        printf("UF inexistente!! \n");
        return;
    }
        break;

    case 3:
        printf("informe o tipo: \n");
        fgets(busca,MAX,stdin);
        __fpurge(stdin);
        validaTipo(busca);
        LIMPA_TELA;
        buscaTipo(busca);
        if(guardaPosicao == 0)
    {
        LIMPA_TELA;
        printf("Tipo inexistente!! \n");
        return;
    }
        break;

    case 4:
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

void validaMenuBusca(int *pOpcao)
{

    while(*pOpcao < 1 || *pOpcao > 4)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

    }
}


void validaOpcao(int *pOpcao)
{

    while(*pOpcao < 0 || *pOpcao > 5)
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
                printf("Nome ja cadastrado, digite um nome novo \n");
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

    validaTipo(cadastrar.tipo);

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
    printf("Nome \n");

    while (aux3 != contador)
    {
        printf("\n%s \n",pMalloc[aux3].nome);
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
    printf("\t\tATUALIZAR\n\n");


    printf("Informe o nome da faculdade que deseja atualizar: \n");
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
    printf("\nEssa e a faculdade que deseja atualizar?\n1 - SIM\n0 - NAO\n");
    scanf("%d",&escolha);
    __fpurge(stdin);

    validaConfirma(&escolha);

    if (escolha == 0)
    {
        LIMPA_TELA;
        return;
    }

    fseek(pArquivos,((guardaPosicao - 1) * sizeof(faculdades)), SEEK_SET);

    fread(&dados,sizeof(faculdades),1,pArquivos);

    while (opcao2 != 5)
    {
        printf("\nInforme o dado que deseja atualizar \n");
        printf("1. Nome \n2. UF \n3. Tipo \n4. Apagar a faculdade \n5. Sair\n");
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

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(faculdades)), SEEK_SET);

            if (fwrite(&dados,sizeof(faculdades),1,pArquivos) == 1)
            {
                LIMPA_TELA;
                printf("\nAtualizacao realizada com sucesso\n\n");
                printf("Nome: %s \n",dados.nome);
                printf("UF: %s \n",dados.uf);
                printf("Tipo: %s \n",dados.tipo);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
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
                printf("\nAtualizacao realizada com sucesso\n");
                printf("NOME: %s \n",dados.nome);
                printf("UF: %s \n",dados.uf);
                printf("TIPO: %s \n",dados.tipo);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
            break;

        case 3:
            printf("Informe o novo tipo\n");
            fgets(dados.tipo,MAX,stdin);
            __fpurge(stdin);
            validaNome(dados.tipo);
            validaTipo(dados.tipo);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(faculdades)), SEEK_SET);

            if (fwrite(&dados,sizeof(faculdades),1,pArquivos) == 1)
            {
                LIMPA_TELA;
                printf("\nAtualizacao realizada com sucesso\n");
                printf("NOME: %s \n",dados.nome);
                printf("UF: %s \n",dados.uf);
                printf("TIPO = %s \n",dados.tipo);
            }
            else
            {
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
            break;
        case 4:
            printf("Deseja mesmo deletar a faculdade?\n1 - SIM\n0 - NAO\n");
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
                printf("Tipo: %s \n\n",cadastro.tipo);
                guardaPosicao = contador;
            }
        }
    }
    fclose(pArquivo);
}

void buscaUf(char *pNome)
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
            if (strcmp(pNome,cadastro.uf) == 0)
            {
                printf("Nome: %s \n",cadastro.nome);
                printf("UF: %s \n",cadastro.uf);
                printf("Tipo: %s \n\n",cadastro.tipo);
                guardaPosicao = contador;
            }
        }
    }
    fclose(pArquivo);
}

void buscaTipo(char *pNome)
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
            if (strcmp(pNome,cadastro.tipo) == 0)
            {
                printf("Nome: %s \n",cadastro.nome);
                printf("UF: %s \n",cadastro.uf);
                printf("Tipo: %s \n\n",cadastro.tipo);
                guardaPosicao = contador;
            }
        }
    }
    fclose(pArquivo);
}

void validaTipo(char *pTipo)
{
    validaNome(pTipo);

    while((strcmp(pTipo,"PARTICULAR\0") != 0) && (strcmp(pTipo,"PUBLICA\0") != 0))
    {
        printf("Tipo invalido, digite particular ou publica\n");
        fgets(pTipo,MAX,stdin);
        __fpurge(stdin);
        validaNome(pTipo);
    }


}

void mudaLetra(char *palavra)
{
    int i;

    for (i=0; palavra[i]!='\0'; i++)
    {
        palavra[i] = toupper(palavra[i]);
    }
}

/**********************************************************************************************************************************/
//Vestibulares - Aplicativos de Auxilo de Intercambio

int appIntercambio(void)
{
// Declaracoes
    int opcao = -1;
// Instrucoes
    while (opcao != 0)
    {
        printf("\t\t *** Aplicativos para Auxilio a Intercambio ***\n\n");
        printf("1 - Cadastrar \n2 - Listar \n3 - Buscar\n4 - Atualizar\n5 - Deletar \n0 - Voltar\n");
        printf("\nEscolha a opcao que deseja: ");
        scanf("%d",&opcao);
        __fpurge(stdin);
        validaOpcaoApp(&opcao);
        switch (opcao)
        {
        case 1:
            cadastroApp();
            break;
        case 2:
            listaApp();
            break;
        case 3:
            buscaApp();
            break;
        case 4:
            editaDadosApp();
            break;
        case 5:
            deletaApp();
            break;
        }

    }
    LIMPA_TELA;
    return 0;
}



void cadastroApp()
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

    validaNomeApp(cadastrar.nome);

    validaNomeChaveApp(cadastrar.nome);

    __fpurge(stdin);

    printf("Informe a Plataforma : \n");
    fgets(cadastrar.plataforma,MAX,stdin);

    __fpurge(stdin);

    validaNomeApp(cadastrar.plataforma);

    __fpurge(stdin);

    printf("Informe o Tamanho em MB: \n");

    scanf("%lf",&cadastrar.memoria);

    __fpurge(stdin);


    validaNumApp(&cadastrar.memoria);

    printf("Informe a Descricao : \n");

    fgets(cadastrar.descricao,300,stdin);

    __fpurge(stdin);

    validaNomeApp(cadastrar.descricao);

    __fpurge(stdin);

    printf("\n1 - Salvar\n0 - Cancelar\n");
    scanf("%d",&confirma);

    __fpurge(stdin);

    validaConfirmaApp(&confirma);
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

void editaDadosApp()
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
        printf("Nenhum Aplicativo para atualizar\n\n");
        return;
    }
    LIMPA_TELA;
    printf("\t\tATUALIZAR\n\n");


    printf("Informe o nome do aplicativo que deseja atualizar: \n");
    fgets(chave,MAX,stdin);

    __fpurge(stdin);

    validaNomeApp(chave);

    buscaChaveApp(chave);

    if(guardaPosicao == 0)
    {
        LIMPA_TELA;
        printf("Aplicativo inexistente!! \n");
        return;
    }
    printf("\nEsse e o aplicativo que deseja atualizar?\n1 - SIM\n0 - NAO\n");
    scanf("%d",&escolha);
    __fpurge(stdin);

    validaConfirmaApp(&escolha);

    if (escolha == 0)
    {
        LIMPA_TELA;
        return;
    }

    fseek(pArquivos,((guardaPosicao - 1) * sizeof(aplicativos)), SEEK_SET);

    fread(&dados,sizeof(aplicativos),1,pArquivos);

    while (opcao2 != 6)
    {
        printf("\nInforme o dado que deseja atualizar \n");
        printf("1. Nome \n2. Plataforma \n3. Tamanho \n4. Descricao \n5. Apagar o Aplicativo \n6. Sair\n");
        printf("Escolha a opcao que deseja: ");
        scanf("%d",&opcao2);
        __fpurge(stdin);

        validaOpcao2App(&opcao2);

        switch(opcao2)
        {
        case 1:

            printf("Informe o novo nome \n");
            fgets(dados.nome,MAX,stdin);

            __fpurge(stdin);

            validaNomeApp(dados.nome);

            validaNomeChaveApp(dados.nome);

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

            validaNomeApp(dados.plataforma);

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
            validaNumApp(&dados.memoria);


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

            validaNomeApp(dados.descricao);

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

           validaConfirmaApp(&confirmacao);

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


void listaApp()
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

void buscaApp()
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
    validaMenuBuscaApp(&escolha);
    __fpurge(stdin);
    switch(escolha)
    {
    case 1:
        printf("informe o nome: \n");
        fgets(busca,MAX,stdin);
        __fpurge(stdin);
        validaNomeApp(busca);
        LIMPA_TELA;
        buscaChaveApp(busca);
        break;

    case 2:
        printf("informe a Plataforma: \n");
        fgets(busca,MAX,stdin);
        __fpurge(stdin);
        validaNomeApp(busca);
        LIMPA_TELA;
        buscaPlataformaApp(busca);
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


void deletaApp()
{
    //Declaração locais
    int escolhe;
    //Instruções
    LIMPA_TELA;
    printf("\t\tDeletar\n\n");
    printf("Deseja excluir todos os Aplicativos cadastrados?\n1 - SIM\n0 - NAO\n");
    scanf("%d",&escolhe);

    __fpurge(stdin);

    validaConfirmaApp(&escolhe);

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

void validaNomeChaveApp(char *pNome)
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
                validaNomeApp(pNome);
                rewind(pArquivo);
            }
        }
    }

    fclose(pArquivo);

}

void validaNumApp(double *num)
{
    while(*num<=0)
    {
        printf("Digite um tamanho valido\n");
        scanf("%lf",num);
    }
}

void validaOpcaoApp(int *pOpcao)
{

    while(*pOpcao < 0 || *pOpcao > 5)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

    }
}

void validaOpcao2App(int *pOpcao)
{

    while(*pOpcao < 1 || *pOpcao > 5)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

    }
}

void validaNomeApp(char *pNome)
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
    mudaLetraApp(pNome);
}

void validaMenuBuscaApp(int *pOpcao)
{

    while(*pOpcao < 1 || *pOpcao > 4)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

    }
}

void validaConfirmaApp(int *pConfirma)
{

    while(*pConfirma != 1 && *pConfirma != 0)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pConfirma);
        __fpurge(stdin);
    }
}

void buscaChaveApp(char *pNome)
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

void buscaPlataformaApp(char *pNome)
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

void mudaLetraApp(char *palavra)
{
    int i;

    for (i=0; palavra[i]!='\0'; i++)
    {
        palavra[i] = toupper(palavra[i]);
    }
}

/**********************************************************************************************************************************/
//Parte Viagens
//VIAGENS - LUCIANA E LUCIANO


int estiloViagens(void)
{
// Declaracoes
    int opcao = -1;
// Instrucoes
    while (opcao != 6){
      printf("\t\t *** Viagem ***\n\n");
      printf("1 - Cadastrar \n2 - Alterar \n3 - Listar\n4 - Buscar\n5 - Deletar \n6 - Sair\n");
      printf("\nEscolha a opcao que deseja: ");
      scanf("%d",&opcao);
      __fpurge(stdin);
      validaOpcaoViagem(&opcao);
      switch (opcao)
{
      case 1:
          cadastroViagem();
          break;
      case 2:
          editaDadosViagem();
          break;
      case 3:
          listaViagem();
          break;
      case 4:
          buscaViagem();
          break;
      case 5:
        deletaViagem();
          break;
    }
  }
  return 0;
}
/******************************************************************************/
void buscaChaveViagem(char *pNome){ //ESSA FUNCAO EH ESPECIFICA: NAO APAGAR!!!
    FILE *pArquivo;
    destinos cadastro;
    int contador = 0;
    guardaPosicao = 0;


    if ((pArquivo = fopen("viagem.txt","rt")) == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }
    while (!feof(pArquivo)){
        contador++;
        if ((fread(&cadastro,sizeof(destinos),1,pArquivo)) == 1){
            if (strcmp(pNome,cadastro.pais) == 0){
                printf("Pais: %s \n",cadastro.pais);
                printf("Continente: %s \n",cadastro.continente);
                printf("Lingua Falada: %s \n",cadastro.lingua);
                printf("Descricao: %s \n",cadastro.descricao);
                printf("Curiosidades: %s \n",cadastro.curiosidades);
                printf("Dicas: %s \n",cadastro.dicas);
                printf("Sites Recomendados: %s \n\n",cadastro.sites);
                guardaPosicao = contador;
            }
        }

    }
    fclose(pArquivo);
  }
/******************************************************************************/
void buscaContViagem(char *pNome){ //ESSA FUNCAO EH ESPECIFICA: NAO APAGAR!!!

      FILE *pArquivo;
      destinos cadastro;
      int contador = 0;
      guardaPosicao = 0;


      if ((pArquivo = fopen("viagem.txt","rt")) == NULL){
          printf("Erro ao abrir o arquivo");
          return;
      }
      while (!feof(pArquivo)){
          contador++;
          if ((fread(&cadastro,sizeof(destinos),1,pArquivo)) == 1){
              if (strcmp(pNome,cadastro.continente) == 0){
                printf("Pais: %s \n",cadastro.pais);
                printf("Continente: %s \n",cadastro.continente);
                printf("Lingua Falada: %s \n",cadastro.lingua);
                printf("Descricao: %s \n",cadastro.descricao);
                printf("Curiosidades: %s \n",cadastro.curiosidades);
                printf("Dicas: %s \n",cadastro.dicas);
                printf("Sites Recomendados: %s \n\n",cadastro.sites);
                  guardaPosicao = contador;
              }
          }


    }
      fclose(pArquivo);
  }

  void buscaLingViagem(char *pNome){
      FILE *pArquivo;
      destinos cadastro;
      int contador = 0;
      guardaPosicao = 0;


      if ((pArquivo = fopen("viagem.txt","rt")) == NULL){
          printf("Erro ao abrir o arquivo");
          return;
      }

      while (!feof(pArquivo)){
          contador++;
          if ((fread(&cadastro,sizeof(destinos),1,pArquivo)) == 1){
              if (strcmp(pNome,cadastro.lingua) == 0){
                printf("Pais: %s \n",cadastro.pais);
                printf("Continente: %s \n",cadastro.continente);
                printf("Lingua Falada: %s \n",cadastro.lingua);
                printf("Descricao: %s \n",cadastro.descricao);
                printf("Curiosidades: %s \n",cadastro.curiosidades);
                printf("Dicas: %s \n",cadastro.dicas);
                printf("Sites Recomendados: %s \n\n",cadastro.sites);
                  guardaPosicao = contador;
              }
          }

      }
      fclose(pArquivo);
  }

void buscaViagem(){
    int escolha;
    int confirma;
    char busca[MIN];

    LIMPA_TELA;
    printf("\t\tBUSCAR\n\n");
    printf("Busca por:\n 1 - Pais \n 2 - Continente \n 3 - Lingua Falada \n 4 - Sair\n");
    printf("Escolha a opcao que deseja: ");
    scanf("%d",&escolha);
    validaMenuBuscaViagem(&escolha);
    __fpurge(stdin);
    switch(escolha){
    case 1:
        printf("Informe o Pais: \n");
        fgets(busca,MIN,stdin);
        __fpurge(stdin);
        validaNomeViagem(busca);
        LIMPA_TELA;
        buscaChaveViagem(busca);
        break;

    case 2:
        printf("informe o Continente: \n");
        fgets(busca,MIN,stdin);
        __fpurge(stdin);
        validaNomeViagem(busca);
        LIMPA_TELA;
        buscaContViagem(busca);
        break;

    case 3:
        printf("informe a Lingua Falada: \n");
        fgets(busca,MIN,stdin);
        __fpurge(stdin);
        validaNomeViagem(busca);
        LIMPA_TELA;
        buscaLingViagem(busca);
        break;

    case 4:
        LIMPA_TELA;
        return;
    }

    printf("1 - Voltar\n");
    scanf("%d",&confirma);

    __fpurge(stdin);

    while(confirma != 1){
        printf("Opcao invalida digite novamente \n");
        scanf("%d",&confirma);
        __fpurge(stdin);
    }

    LIMPA_TELA;
}

void validaMenuBuscaViagem(int *pOpcao){

    while(*pOpcao < 1 || *pOpcao > 4){
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

    }
}

void validaOpcaoViagem(int *pOpcao){

    while(*pOpcao < 1 || *pOpcao > 6)
    {
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

    }
}

void validaOpcao2Viagem(int *pOpcao){

    while(*pOpcao < 1 || *pOpcao > 9){
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pOpcao);
        __fpurge(stdin);

    }
}

void validaNomeViagem(char *pNome){

    while(strlen(pNome) == 1){
        printf("Nome invalido, digite um nome valido\n");
        fgets(pNome,MAX,stdin);

        __fpurge(stdin);
    }
    if (pNome[strlen(pNome) - 1] == '\n'){
        pNome[strlen(pNome) -1  ] = '\0';
    }
    mudaLetraViagem(pNome);
}

void validaNomeChaveViagem(char *pNome){
    FILE *pArquivo;
    destinos listaCadastro;

    if ((pArquivo = fopen("viagem.txt","rt")) == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (!feof(pArquivo)){
        if ((fread(&listaCadastro,sizeof(destinos),1,pArquivo)) == 1){
            if (strcmp(pNome,listaCadastro.pais) == 0){
                printf("Pais ja cadastrado, digite um pais novo \n");
                fgets(pNome,MAX,stdin);
                validaNomeViagem(pNome);
                rewind(pArquivo);
            }
        }
    }

    fclose(pArquivo);

}

void validaConfirmaViagem(int *pConfirma){

    while(*pConfirma != 1 && *pConfirma != 0){
        printf("Opcao invalida digite novamente \n");
        scanf("%d",pConfirma);
        __fpurge(stdin);
    }
}

void cadastroViagem(){
    //Declaraões locais
    destinos cadastrar;
    FILE *pArquivo;
    int confirma;

    // Instruções
    pArquivo=fopen("viagem.txt","a+");
    if (pArquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }
    LIMPA_TELA;

    printf("\t\tCadastrar\n\n");

    printf ("Informe o nome do Pais : \n");
    fgets(cadastrar.pais,MIN,stdin);
    __fpurge(stdin);

    validaNomeViagem(cadastrar.pais);

    validaNomeChave(cadastrar.pais);

    __fpurge(stdin);
////////////////////////////////////////////

    printf("Informe o Continente : \n");
    fgets(cadastrar.continente,MIN,stdin);

    __fpurge(stdin);

    validaNomeViagem(cadastrar.continente);

    __fpurge(stdin);
////////////////////////////////////////////

    printf("Informe a Lingua Falada : \n");
    fgets(cadastrar.lingua,MIN,stdin);
    __fpurge(stdin);

    validaNomeViagem(cadastrar.lingua);

    __fpurge(stdin);
////////////////////////////////////////////
    printf("Informe a Descricao: \n");
    fgets(cadastrar.descricao,MAX,stdin);
    __fpurge(stdin);

    validaNomeViagem(cadastrar.descricao);

    __fpurge(stdin);
////////////////////////////////////////////
    printf("Informe as Curiosidades: \n");
    fgets(cadastrar.curiosidades,MAX,stdin);
    __fpurge(stdin);

    validaNomeViagem(cadastrar.curiosidades);

    __fpurge(stdin);
////////////////////////////////////////////
    printf("Informe as Dicas: \n");
    fgets(cadastrar.dicas,MAX,stdin);
    __fpurge(stdin);

    validaNomeViagem(cadastrar.dicas);
    __fpurge(stdin);
////////////////////////////////////////////
    printf("Informe os Sites: \n");
    fgets(cadastrar.sites,MIN,stdin);
    __fpurge(stdin);

    validaNomeViagem(cadastrar.sites);
    __fpurge(stdin);
////////////////////////////////////////////

    printf("\n1 - Salvar\n0 - Cancelar\n");
    scanf("%d",&confirma);

    __fpurge(stdin);

    validaConfirmaViagem(&confirma);
    LIMPA_TELA;

    switch(confirma){
    case 1:
        if (fwrite(&cadastrar,sizeof(destinos),1,pArquivo) == 1){
            printf("Faculdade cadastrada\n\n");
        }
        else{
            printf("Erro no cadastro");
        }
        break;
    }

    fclose(pArquivo);
}

void listaViagem(){

    destinos cadastros;
    FILE *pArquivos;
    int contador = 0;
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;
    int confirma;
    destinos *pMalloc;

    LIMPA_TELA;
    if ((pArquivos = fopen("viagem.txt","a+")) == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (fread(&cadastros,sizeof(destinos),1,pArquivos) == 1){
        contador++;
    }

    if (contador == 0){
        LIMPA_TELA;
        printf("Nenhuma Nenhum Pais para Listar\n\n");
        return;
    }

    rewind(pArquivos);

    pMalloc = (destinos *)malloc(contador * sizeof(destinos));

    while (fread(&pMalloc[aux],sizeof(destinos),1,pArquivos) == 1){
        aux++;
    }

    for(aux = 0; aux < contador - 1; aux++){
        for(aux2 = aux + 1; aux2 < contador; aux2++){
            if (strcmp(pMalloc[aux].pais,pMalloc[aux2].pais) > 0){
                cadastros = pMalloc[aux2];
                pMalloc[aux2] = pMalloc[aux];
                pMalloc[aux] = cadastros;
            }
        }
    }

    printf("\t\tListar\n\n");
    printf("PAISES: \n");

    while (aux3 != contador){
        printf("\n%s\n",pMalloc[aux3].pais);
        aux3++;
    }
    printf("\n");

    printf("1 - Voltar\n");
    scanf("%d",&confirma);

    __fpurge(stdin);

    while(confirma != 1){
        printf("Opcao invalida digite novamente \n");
        scanf("%d",&confirma);
        __fpurge(stdin);
    }

    LIMPA_TELA;

    fclose(pArquivos);

}

void mudaLetraViagem(char *palavra){
    int i;

    for (i=0; palavra[i]!='\0'; i++){
        palavra[i] = toupper(palavra[i]);
    }
}

void deletaViagem(){

    FILE *pArquivos;
    FILE *pArquivosNovo;
    destinos evento;
    char pais[MAX];
    int opt = -1;

    pArquivos  =  fopen("viagem.txt", "r+");

    if(!pArquivos){
       printf("\nO arquivo nao pode ser encontrado!\n");
    }


     //Verifica se o arquivo está vazio
    fseek (pArquivos, 0, SEEK_END);
    if (ftell (pArquivos) == 0){
        system("clear");
        printf("Nenhum pais cadastrado!\n\n");
        return;
    }

    printf("\nEntre com o nome do pais a ser deletado: \n");
    fgets(pais,MAX,stdin);
    system("clear");
    validaNomeViagem(pais);
    buscaChaveViagem(pais);
    if(guardaPosicao == 0){
        system("clear");
        printf("Pais nao encontrado no sistema! \n");
        return;
    }
    printf("\nEste é o pais que voce deseja excluir?\n");
    printf("\n1 - Sim\n");
    printf("\n0 - Nao\n");
    scanf("%d", &opt);
    validaConfirmaViagem(&opt);

    switch(opt){
        case 1:{
            system("clear");

            pArquivosNovo = fopen("temp.txt","wt");
            if(!pArquivosNovo){
                printf("\nNovo arquivo não pode ser criado!\n");
            }

            rewind(pArquivos);

            while(!feof(pArquivos)){
                if(fread(&evento,sizeof(destinos),1,pArquivos) == 1){
                    if(strcmp(evento.pais,pais)!=0){
                        if(fwrite(&evento,sizeof(destinos),1,pArquivosNovo) == 1)
                        {}
                    }
                }
            }

            fclose(pArquivos);
            fclose(pArquivosNovo);

            remove("viagem.txt");
            rename("temp.txt","viagem.txt");
            system("clear");
            printf("\nO pais foi excluido com sucesso!\n");
            return;
            break;
        }
        case 0:{
            system("clear");
            printf("\nO intem não foi excluido!\n");
            break;
        }
    }

    fclose(pArquivos);
}


void editaDadosViagem(){
    //Declarações:
    destinos dados;
    FILE *pArquivos;
    FILE *arquivoNovo;
    int escolha=0;
    char chave[MAX];
    int opcao2=0;
    int confirmacao=0;

    //Instruções:
    pArquivos = fopen("viagem.txt","r+");
    if ((pArquivos = fopen("viagem.txt","r+")) == NULL){
        LIMPA_TELA;
        printf("Erro ao abrir o arquivo\n\n");
        return;
    }

    //Verifica se o arquivo está vazio
    fseek (pArquivos, 0, SEEK_END);
    if (ftell (pArquivos) == 0){
        LIMPA_TELA;
        printf("Nenhum Pais Cadastrado\n\n");
        return;
    }
    LIMPA_TELA;
    printf("\t\tALTERAR\n\n");


    printf("Informe o nome do pais que deseja alterar \n");
    fgets(chave,MAX,stdin);



    __fpurge(stdin);

    validaNomeViagem(chave);

    buscaChaveViagem(chave);

    if(guardaPosicao == 0){
        LIMPA_TELA;
        printf("Esse Pais Não Existe!! \n");
        return;
    }
    printf("\nEsse eh o pais que deseja alterar?\n1 - SIM\n0 - NAO\n");
    scanf("%d",&escolha);
    __fpurge(stdin);

    validaConfirmaViagem(&escolha);

    if (escolha == 0){
        return;
    }

    fseek(pArquivos,((guardaPosicao - 1) * sizeof(destinos)), SEEK_SET);

    fread(&dados,sizeof(destinos),1,pArquivos);

    while (opcao2 != 8){
        printf("\nInforme o dado que deseja alterar \n");
        printf("1 - Pais \n2 - Continente \n3 - Lingua Falada \n4 - Descricao \n5 - Curiosidades \n6 - Dicas \n7 - Sites Recomendados \n8 - Sair\n");
        printf("Escolha a opcao que deseja: ");
        scanf("%d",&opcao2);
        __fpurge(stdin);

        validaOpcao2Viagem(&opcao2);

        switch(opcao2){
   case 1:

            printf("Informe o novo pais \n");
            fgets(dados.pais,MAX,stdin);

            __fpurge(stdin);

            validaNomeViagem(dados.pais);

            validaNomeChave(dados.pais);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(destinos)), SEEK_SET);

            if (fwrite(&dados,sizeof(destinos),1,pArquivos) == 1){
                LIMPA_TELA;
                printf("\nAlteracao realizada com sucesso\n\n");
                printf("Pais: %s \n",dados.pais);
                printf("Continente: %s \n",dados.continente);
                printf("Lingua Falada: %s \n",dados.lingua);
                printf("Descricao: %s \n",dados.descricao);
                printf("Curiosidades: %s \n",dados.curiosidades);
                printf("Dicas: %s \n",dados.dicas);
                printf("Sites Recomendados: %s \n\n",dados.sites);
            }
            else{
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
            break;
    case 2:
            printf("Informe o Novo Continente \n");
            fgets(dados.continente,MAX,stdin);


            __fpurge(stdin);

            validaNomeViagem(dados.continente);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(destinos)), SEEK_SET);

            if (fwrite(&dados,sizeof(destinos),1,pArquivos) == 1){
                LIMPA_TELA;
                printf("\nAlteracao realizada com sucesso\n\n");
                printf("Pais: %s \n",dados.pais);
                printf("Continente: %s \n",dados.continente);
                printf("Lingua Falada: %s \n",dados.lingua);
                printf("Descricao: %s \n",dados.descricao);
                printf("Curiosidades: %s \n",dados.curiosidades);
                printf("Dicas: %s \n",dados.dicas);
                printf("Sites Recomendados: %s \n\n",dados.sites);
            }
            else{
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
            break;

    case 3:

            printf("Informe a Nova Lingua\n");
            fgets(dados.lingua,MAX,stdin);
            __fpurge(stdin);
            validaNomeViagem(dados.lingua);


            fseek(pArquivos,((guardaPosicao - 1) * sizeof(destinos)), SEEK_SET);

            if (fwrite(&dados,sizeof(destinos),1,pArquivos) == 1){
                LIMPA_TELA;
                printf("\nAlteracao realizada com sucesso\n\n");
                printf("Pais: %s \n",dados.pais);
                printf("Continente: %s \n",dados.continente);
                printf("Lingua Falada: %s \n",dados.lingua);
                printf("Descricao: %s \n",dados.descricao);
                printf("Curiosidades: %s \n",dados.curiosidades);
                printf("Dicas: %s \n",dados.dicas);
                printf("Sites Recomendados: %s \n\n",dados.sites);
            }
            else{
                printf("Erro\n");
            }
            fclose(pArquivos);
            return;
            break;

    case 4:

            printf("Informe a Nova Discricao\n");
            fgets(dados.descricao,MAX,stdin);
            __fpurge(stdin);
            validaNomeViagem(dados.descricao);

            fseek(pArquivos,((guardaPosicao - 1) * sizeof(destinos)), SEEK_SET);

            if (fwrite(&dados,sizeof(destinos),1,pArquivos) == 1){
                  LIMPA_TELA;
                  printf("\nAlteracao realizada com sucesso\n\n");
                  printf("Pais: %s \n",dados.pais);
                  printf("Continente: %s \n",dados.continente);
                  printf("Lingua Falada: %s \n",dados.lingua);
                  printf("Descricao: %s \n",dados.descricao);
                  printf("Curiosidades: %s \n",dados.curiosidades);
                  printf("Dicas: %s \n",dados.dicas);
                  printf("Sites Recomendados: %s \n\n",dados.sites);
                }
          else{
                printf("Erro\n");
                }
                fclose(pArquivos);
                return;
                break;

   case 5:
                printf("Informe as Novas Curiosidades\n");
                fgets(dados.curiosidades,MAX,stdin);
                __fpurge(stdin);
                validaNomeViagem(dados.curiosidades);

                fseek(pArquivos,((guardaPosicao - 1) * sizeof(destinos)), SEEK_SET);

        if (fwrite(&dados,sizeof(destinos),1,pArquivos) == 1){
                LIMPA_TELA;
                printf("\nAlteracao realizada com sucesso\n\n");
                printf("Pais: %s \n",dados.pais);
                printf("Continente: %s \n",dados.continente);
                printf("Lingua Falada: %s \n",dados.lingua);
                printf("Descricao: %s \n",dados.descricao);
                printf("Curiosidades: %s \n",dados.curiosidades);
                printf("Dicas: %s \n",dados.dicas);
                printf("Sites Recomendados: %s \n\n",dados.sites);
              }
      else{
                printf("Erro\n");
              }
                fclose(pArquivos);
                  return;
                  break;

  case 6:

              printf("Informe as Novas Dicas\n");
              fgets(dados.dicas,MAX,stdin);
              __fpurge(stdin);
              validaNomeViagem(dados.dicas);

              fseek(pArquivos,((guardaPosicao - 1) * sizeof(destinos)), SEEK_SET);

      if (fwrite(&dados,sizeof(destinos),1,pArquivos) == 1){
            LIMPA_TELA;
            printf("\nAlteracao realizada com sucesso\n\n");
            printf("Pais: %s \n",dados.pais);
            printf("Continente: %s \n",dados.continente);
            printf("Lingua Falada: %s \n",dados.lingua);
            printf("Descricao: %s \n",dados.descricao);
            printf("Curiosidades: %s \n",dados.curiosidades);
            printf("Dicas: %s \n",dados.dicas);
            printf("Sites Recomendados: %s \n\n",dados.sites);
          }
    else{
            printf("Erro\n");
        }
          fclose(pArquivos);
          return;
          break;

  case 7:

          printf("Informe os Novos Sites Recomendados\n");
          fgets(dados.sites,MAX,stdin);
          __fpurge(stdin);
          validaNomeViagem(dados.sites);

          fseek(pArquivos,((guardaPosicao - 1) * sizeof(destinos)), SEEK_SET);

          if (fwrite(&dados,sizeof(destinos),1,pArquivos) == 1){
    LIMPA_TELA;
          printf("\nAlteracao realizada com sucesso\n\n");
          printf("Pais: %s \n",dados.pais);
          printf("Continente: %s \n",dados.continente);
          printf("Lingua Falada: %s \n",dados.lingua);
          printf("Descricao: %s \n",dados.descricao);
          printf("Curiosidades: %s \n",dados.curiosidades);
          printf("Dicas: %s \n",dados.dicas);
          printf("Sites Recomendados: %s \n\n",dados.sites);
}
      else{
          printf("Erro\n");
}
          fclose(pArquivos);
          return;
          break;
        }
    }

    LIMPA_TELA;

    return;
}
