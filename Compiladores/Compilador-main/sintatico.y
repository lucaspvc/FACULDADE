%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexico.c"
#include "utils.c"

int contaVar = 0;
int rotulo = 0;
int ehRegistro = 0;
int tipo;
%}

%token T_PROGRAMA
%token T_INICIO
%token T_FIM
%token T_IDENTIF
%token T_LEIA
%token T_ESCREVA
%token T_ENQTO
%token T_FACA
%token T_FIMENQTO
%token T_SE
%token T_ENTAO
%token T_SENAO
%token T_FIMSE
%token T_ATRIB
%token T_VEZES
%token T_DIV
%token T_MAIS
%token T_MENOS
%token T_MAIOR
%token T_MENOR
%token T_IGUAL
%token T_E
%token T_OU
%token T_V
%token T_F
%token T_NUMERO
%token T_NAO
%token T_ABRE
%token T_FECHA
%token T_LOGICO
%token T_INTEIRO

%token T_DEF
%token T_FIMDEF
%token T_REGISTRO
%token T_IDPONTO

%start programa

%left T_E T_OU
%left T_IGUAL
%left T_MAIOR T_MENOR
%left T_MAIS T_MENOS
%left T_VEZES T_DIV


%%

programa
    : cabecalho define_registro variaveis 
        {
            mostraTabela();
            empilha (contaVar);
            if(contaVar)
                fprintf(yyout, "\tAMEM\t%d\n", contaVar);
        }
    T_INICIO lista_comandos T_FIM
        {
            int conta = desempilha();
            if (conta)
                fprintf(yyout, "\tDMEM\t%d\n", contaVar);
        }
    { 
        fprintf(yyout, "\tFIMP\n"); 
    }
    ;

cabecalho
    : T_PROGRAMA T_IDENTIF
        {
            fprintf(yyout, "\tINPP\n");
        }
    ;

tipo
    : T_LOGICO
        { 
            tipo = LOG;
            //TODO #3
            // Além do tipo, guardar a posição (POS) e o tamanho (TAM) do tipo na tabela de simbolos
        }
    | T_INTEIRO
        { 
            tipo = INT;
            //TODO #3
            // Além do tipo, guardar a posição (POS) e o tamanho (TAM) do tipo na tabela de simbolos
        }
    | T_REGISTRO T_IDENTIF
        { 
            tipo = REG;
            //TODO #4
            // Aqui tem uma chamada de buscaSimbolo para encontrar as informações de TAM e POS do registro
        }
    ;

define_registro
    : define define_registro
    | /* vazio */
    ;

define 
    : T_DEF 
        {
            //TODO #1
            //iniciar a lsita de capos
        }   
    definicao_campos T_FIMDEF T_IDENTIF
        {
            //TODO #2
            //Inserir esse novo tipo na tabela de simbolos
            //com a lista que foi montada
        }
    ;

definicao_campos
    : tipo lista_campos definicao_campos
    | tipo lista_campos
    ;


lista_campos
    : lista_campos T_IDENTIF
    {
        //TODO #0
        //acrescentar esse campo na lista de campos que esta sendo construida
        //o deslocamento (endereço) do próximo campo será o deslocamento anterio mais o tamanho desse campo
    
    }
    | T_IDENTIF
    ;

variaveis
    : /* vazio */
    | declaracao_variaveis
    ;

declaracao_variaveis
    : tipo lista_variaveis declaracao_variaveis
    | tipo lista_variaveis
    ;



lista_variaveis
    :lista_variaveis T_IDENTIF
        {
            strcpy(elemTab.id, atomo);
            elemTab.end = contaVar;
            elemTab.tip = tipo;
            //TODO#6
            //Tem outros campos para acescentar na tabela de simboloso
            insereSimbolo(elemTab);
            contaVar++;
            //TODO#5
            //Se a variavel for registro 
            //contaVar = contaVar + TAM (Tamanho do registro)
        }
    | T_IDENTIF
        {
            strcpy(elemTab.id, atomo);
            elemTab.end = contaVar;
            elemTab.tip = tipo;
            insereSimbolo(elemTab);
            contaVar++; 
            //TODO#5
            //Se a variavel for registro 
            //contaVar = contaVar + TAM (Tamanho do registro)
        }
    ;

lista_comandos
    : /* vazio */
    | comando lista_comandos
    ;

comando
    : entrada_saida
    | repeticao
    | selecao
    | atribuicao
    ;

entrada_saida
    : entrada
    | saida
    ;

entrada
    : T_LEIA T_IDENTIF
    {
        int pos = buscaSimbolo (atomo);
        //TODO #7
        // Se for registro, tem que fazer uma repetição do TAM do registro de leituras
        fprintf(yyout, "\tLEIA\n");
        fprintf(yyout, "\tARZG\t%d\n", tabSimb[pos].end);
    }
    ;

saida  /* TODO: Vai ter que modificar (provavelmente) */
    :T_ESCREVA expressao
        {
            desempilha();
            //TODO#8
            // Se for registro, tem que fazer uma repetição do TAM do registro de escritas
            fprintf(yyout, "\tESCR\n");
        }
    ;

repeticao
    : T_ENQTO 
        {
            fprintf(yyout, "L%d\tNADA\n", ++rotulo);
            empilha(rotulo);
        }
    expressao T_FACA 
        {
            int t = desempilha();
            if (t != LOG) {
                yyerror("Incompatibilidade de tipo!");
            }

            fprintf(yyout, "\tDSVF\tL%d\n", ++rotulo);
            empilha(rotulo);
        }
    lista_comandos T_FIMENQTO
        {
            int rot1 = desempilha();
            int rot2 = desempilha();
            fprintf(yyout, "\tDSVS\tL%d\n", rot2);
            fprintf(yyout, "L%d\tNADA\n", rot1);
        }
    ;

selecao
    : T_SE expressao T_ENTAO 
        {
            int t = desempilha();

            if (t != LOG) {
                yyerror("Incompatibilidade de tipo!");
            }

            fprintf(yyout, "\tDSVF\t%d\n", ++rotulo);
            empilha(rotulo);
        }
    lista_comandos T_SENAO 
        {
            fprintf(yyout, "\tDSVS\tL%d\n", ++rotulo);
            int rot = desempilha();
            fprintf(yyout, "%d\tNADA\n", rot);
            empilha(rotulo);
        }
    lista_comandos T_FIMSE
        {
            int rot = desempilha();
            fprintf(yyout, "L%d\tNADA\n", rot);
        }
    ;

atribuicao
    : T_IDENTIF 
        {
            int pos = buscaSimbolo(atomo);
            empilha(pos);
            //Tem que guardar o TAM e a POS se for registro
        }
    T_ATRIB expressao
        {
            int tip = desempilha();
            int pos = desempilha();

            if(tabSimb[pos].tip != tip) {
                yyerror("Incompatibilidade de tipo!");
            }
            //TODO #9
            //Se for registro, tem que fazer uma repetição do TAM do registro de ARZG

            fprintf(yyout, "\tARZG\t%d\n", tabSimb[pos].end);
        }
    ;

expressao
    : expressao T_VEZES expressao
        { 
            testaTipo(INT, INT, INT);
            fprintf(yyout, "\tMULT\n");
        }
    | expressao T_DIV expressao
        {
            testaTipo(INT, INT, INT);
            fprintf(yyout, "\tDIVI\n");
        }
    | expressao T_MAIS expressao
        {
            testaTipo(INT, INT, INT);
            fprintf(yyout, "\tSOMA\n");
        }
    | expressao T_MENOS expressao
        {
            testaTipo(INT, INT, INT);
            fprintf(yyout, "\tSUBT\tLy\n");
        }
    | expressao T_MAIOR expressao
        {
            testaTipo(INT, INT, LOG);
            fprintf(yyout, "\tCMMA\n");
        }
    | expressao T_MENOR expressao
        {
            testaTipo(INT, INT, LOG);
            fprintf(yyout, "\tCMME\n");
        }
    | expressao T_IGUAL expressao
        {
            testaTipo(INT, INT, LOG);
            fprintf(yyout, "\tCMIG\n");
        }
    | expressao T_E expressao
        {
            testaTipo(LOG, LOG, LOG);
            fprintf(yyout, "\tCONJ\n");
        }
    | expressao T_OU expressao
        {
            testaTipo(LOG, LOG, LOG);
            fprintf(yyout, "\tDISJ\n");
        }
    | termo
    ;

expressao_acesso
    : T_IDPONTO 
        { //Primeiro nome deo registro
            if (!ehRegistro) {
                ehRegistro = 1;
                //TODO #10
                //1. Busca o simbolo na tabalea de simbolos
                //2. se não for do tipo registro tem erro
                //3. guardar o TAM, POS e DES desse t_IDENTIF
            }else{
                // Campo que eh registro
                //1. busca esse campo na lista de campos
                //2. se não encotrar, erro
                //3. se encontrar e não for registro, erro
                //4. guardar o TAM, POS e DES desse CAMPO 
            }

        }
        expressao_acesso
    |T_IDENTIF
        {
            if (ehRegistro) {
                //TODO #11
                //1. buscar esse campo na lista de campos
                //2. se não encontrar, erro
                //3. guardar o TAM, DES e TIP desse campo
                //  o tipo (TIP) nesse caso é a posição do tipo na tabela de simbolo
            } else {
                //TODO #12
                int pos = buscaSimbolo(atomo);
                //guardar TAM, DES e TIP dessa variável 
            }
            
            ehRegistro = 0;
        };

termo
    : expressao_acesso
        {
            //TODO #13
            //se for registro, tem que fazer uma repetição do TAM do registro de CRZG (em ordem inersa)
            fprintf(yyout, "\tCRVG\t%d\n", tabSimb[pos].end);
            empilha(tabSimb[pos].tip);
        }
    | T_NUMERO
        { 
            fprintf(yyout, "\tCRCT\t%s\n", atomo); 
            empilha(INT);    
        }
    | T_V
        { 
            fprintf(yyout, "\tCRCT\t1\n"); 
            empilha(LOG);
        }
    | T_F
        { 
            fprintf(yyout, "\tCRCT\t0\n");
            empilha(LOG);   
        }
    | T_NAO termo
        { 
            fprintf(yyout, "\tNEGA\n");
            empilha(LOG);    
        }
    | T_ABRE expressao T_FECHA    
    ;

%%

int main (int argc, char *argv[]) {
   char *p, nameIn[100], nameOut[100];
   argv++;
   if (argc < 2) {
        puts("\nCompilador da linguagem SIMPLES");
        puts("\n\tUSO: ./simples <NOME>[.simples]\n\n");
        exit(1);
   }
   p = strstr(argv[0], ".simples");
   if (p) *p = 0;
   strcpy(nameIn, argv[0]);
   strcat(nameIn, ".simples");
   strcpy(nameOut, argv[0]);
   strcat(nameOut, ".mvs");
   yyin = fopen(nameIn, "rt"); // Pegar o arquivo para ser compilado
   if(!yyin) {
    puts("Programa fonte nao encontrado");
    exit(2);
   }
   yyout = fopen(nameOut, "wt");
   yyparse();
   printf("Programa OK \n");
   return 0;
}