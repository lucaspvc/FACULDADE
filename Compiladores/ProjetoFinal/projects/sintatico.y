%{
/*+=============================================================
         UNIFAL = Universidade Federal de Alfenas.
         BACHARELADO EM CIENCIA DA COMPUTACAO.
Trabalho..: Registro e verificacao de tipos
Disciplina: Teoria de Linguagens e Compiladores
Professor.: Luiz Eduardo da Silva
Aluno.....: Lucas Pessoa Oliveira Alves
Data......: 14/12/2023
+=============================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexico.c"
#include "utils.c"
int contaVar = 0;
int rotulo = 0;
int ehRegistro = 0;
int tipo;
int tam = 1; // tamanho da estrutura qdo percorre expressão de acesso
int des = 0; // deslocamento para chegar no campo
int pos = 0; // posicao do tipo na tabela de simbolos
int tamREG = 0; // tamanho total do REG (soma dos tipos dentro do registro)
int posDECL = 2; //posição da declaração de REG
ptno listaInicial; //lista de campos
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
   : cabecalho definicoes variaveis 
        { 
            mostraTabela();
            empilha (contaVar);
            if (contaVar)
               fprintf(yyout, "\tAMEM\t%d\n", contaVar); 
        }
     T_INICIO lista_comandos T_FIM
        { 
            int conta = desempilha();
            if (conta)
               fprintf(yyout, "\tDMEM\t%d\n", conta); 
        }
        { fprintf(yyout, "\tFIMP\n"); }
   ;

cabecalho
   : T_PROGRAMA T_IDENTIF
       {
         fprintf(yyout, "\tINPP\n"); 

         //Inicia o tipo primitivo inteiro
         strcpy(elemTab.id, "inteiro");
         elemTab.end = -1;
         elemTab.tip = 0;
         elemTab.tam = 1;
         elemTab.pos = 0;
         elemTab.ptno = NULL;
         insereSimbolo(elemTab);

         //Inicia o tipo primitivo logico
         strcpy(elemTab.id, "logico");
         elemTab.end = -1;
         elemTab.tip = 1;
         elemTab.tam = 1;
         elemTab.pos = 1;
         elemTab.ptno = NULL;
         insereSimbolo(elemTab);
      }
   ;

tipo
   : T_LOGICO
         { 
            tipo = LOG; 
            // TODO #1 FEITO
            // Além do tipo, precisa guardar o TAM (tamanho) do
            // tipo e a POS (posição) do tipo na tab. símbolos
            tam = 1;
            elemTab.tam = tam;
            pos = 1;
            elemTab.pos = pos;
         }
   | T_INTEIRO
         { 
            tipo = INT;
            // TODO #1 FEITO
            tam = 1;
            elemTab.tam = tam;
            pos = 0;
            elemTab.pos = pos;     
        }
   | T_REGISTRO T_IDENTIF
         { 
            tipo = REG; 
            // TODO #2 FEITO
            // Aqui tem uma chamada de buscaSimbolo para encontrar
            // as informações de TAM e POS do registro
            pos = buscaSimbolo(atomo);
            tam = tabSimb[pos].tam;
            elemTab.tam = tam;
            elemTab.pos = pos;
         }
   ;

definicoes
   : define definicoes
   | /* vazio */
   ;

define 
   : T_DEF
        {
            // TODO #3 FEITO
            // Iniciar a lista de campos
            listaInicial = NULL;
            // inicia o tamanho do REG 
            tamREG = 0;
        } 
   definicao_campos T_FIMDEF T_IDENTIF
       {
           // TODO #4 FEITO
           // Inserir esse novo tipo na tabela de simbolos
           // com a lista que foi montada
           elemTab.tam = tamREG;
           elemTab.end = -1;
           elemTab.pos = posDECL++;
           elemTab.tip = REG;
           elemTab.ptno = listaInicial;
           strcpy(elemTab.id, atomo);
           insereSimbolo(elemTab); 
           //zera o deslocamento apos a insercao na tabela
           des = 0;
       }
   ;

definicao_campos
   : tipo lista_campos definicao_campos
   | tipo lista_campos 
   ;

lista_campos
   : lista_campos T_IDENTIF
      {
         // TODO #5 FEITO
         // acrescentar esse campo na lista de campos que
         // esta sendo construida
         // o deslocamento (endereço) do próximo campo
         // será o deslocamento anterior mais o tamanho desse campo
         listaCampos novoNo;
         strcpy(novoNo.nome, atomo);
         novoNo.tam = tam;
         novoNo.tipo = tipo;
         novoNo.pos = pos;
         novoNo.desl = des;
         des = des + tam;
         listaInicial = insereLista(listaInicial, novoNo);
         tamREG = tamREG + tam;
      }
      
   | T_IDENTIF
      {
        // idem
         listaCampos novoNo;
         strcpy(novoNo.nome, atomo);
         novoNo.tam = tam;
         novoNo.tipo = tipo;
         novoNo.pos = pos;
         novoNo.desl = des;
         des = des + tam;
         listaInicial = insereLista(listaInicial, novoNo);
         tamREG = tamREG + tam;
      }
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
   : lista_variaveis
     T_IDENTIF 
        { 

            strcpy(elemTab.id, atomo);
            elemTab.end = contaVar;
            elemTab.tip = tipo;
            // TODO #6 FEITO
            // Tem outros campos para acrescentar na tab. símbolos
            // TODO #7 FEITO
            // Se a variavel for registro
            // contaVar = contaVar + TAM (tamanho do registro)
            elemTab.ptno = tabSimb[pos].ptno;
            elemTab.pos = pos;
            elemTab.tam = tabSimb[pos].tam;
            contaVar = contaVar + tabSimb[pos].tam;
            insereSimbolo (elemTab);
        }
   | T_IDENTIF
       { 
            strcpy(elemTab.id, atomo);
            elemTab.end = contaVar;
            elemTab.tip = tipo;
            // idem
            elemTab.ptno = tabSimb[pos].ptno;
            elemTab.pos = pos;
            elemTab.tam = tabSimb[pos].tam;
            contaVar = contaVar + tabSimb[pos].tam;
            insereSimbolo (elemTab);
       }
   ;

lista_comandos
   : /* vazio */
   | comando lista_comandos
   ;

comando
   : entrada_saida
   | atribuicao
   | selecao
   | repeticao
   ;

entrada_saida
   : entrada
   | saida 
   ;

entrada
   : T_LEIA expressao_acesso
       { 
         // TODO #8 FEITO
         // Se for registro, tem que fazer uma repetição do
         // TAM do registro de leituras
         if(tabSimb[pos].tip == REG){
            for(int i = 0; i < tam; i++){
               fprintf(yyout, "\tLEIA\n");
               fprintf(yyout, "\tARZG\t%d\n", des + i);
            }
         } else{
            fprintf(yyout, "\tLEIA\n"); 
            fprintf(yyout, "\tARZG\t%d\n", tabSimb[pos].end);
         }
       }
   ;

saida
   : T_ESCREVA expressao_acesso
       {  
          // TODO #9 FEITO
          // Se for registro, tem que fazer uma repetição do
          // TAM do registro de escritas
          if(tabSimb[pos].tip == REG){
            for(int i = tam - 1; i >= 0; i--){
               fprintf(yyout, "\tCRVG\t%d\n", des + i);
            }
            for(int i = 0; i < tam; i++){
               fprintf(yyout, "\tESCR\n");
            }
         }else{
            fprintf(yyout, "\tCRVG\t%d\n", tabSimb[pos].end);
            fprintf(yyout, "\tESCR\n"); 
         }
      }
   ;

atribuicao
   : expressao_acesso
       { 
         // TODO #10 - FEITO
         // Tem que guardar o TAM, DES e o TIPO (POS do tipo, se for registro)
          empilha(tam);
          empilha(des);
          empilha(tipo);
       }
     T_ATRIB expressao
       { 
          int tipexp = desempilha();
          int tipvar = desempilha();
          int des = desempilha();
          int tam = desempilha();
          if (tipexp != tipvar)
             yyerror("Incompatibilidade de tipo!");
          // TODO #11 - FEITO
          // Se for registro, tem que fazer uma repetição do
          // TAM do registro de ARZG
          for (int i = 0; i < tam; i++)
             fprintf(yyout, "\tARZG\t%d\n", des + i); 
       }
   ;

selecao
   : T_SE expressao T_ENTAO 
       {  
          int t = desempilha();
          if (t != LOG)
            yyerror("Incompatibilidade de tipo!");
          fprintf(yyout, "\tDSVF\tL%d\n", ++rotulo); 
          empilha(rotulo);
       }
     lista_comandos T_SENAO 
       {  
           fprintf(yyout, "\tDSVS\tL%d\n", ++rotulo);
           int rot = desempilha(); 
           fprintf(yyout, "L%d\tNADA\n", rot);
           empilha(rotulo); 
       }
     lista_comandos T_FIMSE
       {  
          int rot = desempilha();
          fprintf(yyout, "L%d\tNADA\n", rot);  
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
         if (t != LOG)
            yyerror("Incompatibilidade de tipo!");
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

expressao
   : expressao T_VEZES expressao
       {  testaTipo(INT,INT,INT); fprintf(yyout, "\tMULT\n");  }
   | expressao T_DIV expressao
       {  testaTipo(INT,INT,INT); fprintf(yyout, "\tDIVI\n");  }
   | expressao T_MAIS expressao
      {  testaTipo(INT,INT,INT); fprintf(yyout, "\tSOMA\n");  }
   | expressao T_MENOS expressao
      {  testaTipo(INT,INT,INT); fprintf(yyout, "\tSUBT\n");  }
   | expressao T_MAIOR expressao
      {  testaTipo(INT,INT,LOG); fprintf(yyout, "\tCMMA\n");  }
   | expressao T_MENOR expressao
      {  testaTipo(INT,INT,LOG); fprintf(yyout, "\tCMME\n");  }
   | expressao T_IGUAL expressao
      {  testaTipo(INT,INT,LOG); fprintf(yyout, "\tCMIG\n");  }
   | expressao T_E expressao
      {  testaTipo(LOG,LOG,LOG); fprintf(yyout, "\tCONJ\n");  }
   | expressao T_OU expressao
      {  testaTipo(LOG,LOG,LOG); fprintf(yyout, "\tDISJ\n");  }
   | termo
   ;

expressao_acesso
   : T_IDPONTO
       {   //--- Primeiro nome do registro
           if (!ehRegistro) {
              ehRegistro = 1;
              // TODO #12 FEITO
              // 1. busca o simbolo na tabela de símbolos
              // 2. se não for do tipo registo tem erro
              // 3. guardar o TAM, POS e DES desse t_IDENTIF
              pos = buscaSimbolo(atomo);
              if(tabSimb[pos].tip == REG){
               tam = tabSimb[pos].tam;
               des = tabSimb[pos].end;
              }else{
               char msg[200];
               sprintf(msg, "O identificador [%s] não é registro!", atomo);
               yyerror(msg);
              }
           } else {
              //--- Campo que eh registro
              // 1. busca esse campo na lista de campos
              // 2. se não encontrar, erro
              // 3. se encontrar e não for registro, erro
              // 4. guardar o TAM, POS e DES desse CAMPO
              ptno LOCAL;
              listaInicial = tabSimb[pos].ptno;
              LOCAL = buscaLista(listaInicial, atomo);
              if(LOCAL == NULL){
                  char msg[200];
                  sprintf(msg, "O campo [%s] não existe na estrutura", atomo);
                  yyerror(msg);
              } else if (LOCAL->campos.tipo != REG){
                  char msg[200];
                  sprintf(msg, "O campo [%s] não é registro!", atomo);
                  yyerror(msg);
              } else{
                  tam = LOCAL->campos.tam;
                  pos = LOCAL->campos.pos;
                  des = LOCAL->campos.desl + des;
              }
           }
       }
     expressao_acesso
   | T_IDENTIF
       {   
           if (ehRegistro) {
               // TODO #13 FEITO
               // 1. buscar esse campo na lista de campos
               // 2. Se não encontrar, erro
               // 3. guardar o TAM, DES e TIPO desse campo.
               //    o tipo (TIP) nesse caso é a posição do tipo
               //    na tabela de simbolos
               ptno LOCAL;
              listaInicial = tabSimb[pos].ptno;
               LOCAL = buscaLista(listaInicial, atomo);
               if(LOCAL == NULL){
                  char msg[200];
                  sprintf(msg, "O campo [%s] não existe na estrutura", atomo);
                  yyerror(msg);
               }else{
                  tam = LOCAL->campos.tam;
                  tipo = LOCAL->campos.tipo;
                  des = LOCAL->campos.desl + des;
               }
           }
           else {
              // TODO #14 FEITO
              int pos = buscaSimbolo (atomo);
              // guardar TAM, DES e TIPO dessa variável
              tam = tabSimb[pos].tam;
              des = tabSimb[pos].end;
              tipo = tabSimb[pos].tip;
           }
           ehRegistro = 0;
       };

termo
   : expressao_acesso
       {
          // TODO #15 FEITO
          // Se for registro, tem que fazer uma repetição do
          // TAM do registro de CRVG (em ondem inversa)
          if(tabSimb[pos].tip == REG){
            for(int i = tam - 1 ; i >= 0; i--){
               fprintf(yyout, "\tCRVG\t%d\n", des + i );
            }            
          }else{
            fprintf(yyout, "\tCRVG\t%d\n", tabSimb[pos].end);
          }
          empilha(tipo);
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
          int t = desempilha();
          if (t != LOG)
              yyerror ("Incompatibilidade de tipo!");
          fprintf(yyout, "\tNEGA\n");
          empilha(LOG);
       }
   | T_ABRE expressao T_FECHA
   ;
%%

int main(int argc, char *argv[]) {
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
    yyin = fopen(nameIn, "rt");
    if (!yyin) {
        puts ("Programa fonte não encontrado!");
        exit(2);
    }
    yyout = fopen(nameOut, "wt");
    yyparse();
    printf("programa ok!\n\n");
    return 0;
}