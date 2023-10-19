%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexico.c"
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
%token T_ENTAO

%start programa

%left T_E T_OU
%left T_IGUAL
%left T_MAIOR T_MENOR
%left T_VEZES T_DIV

%%

programa
    : cabecalho variaveis T_INICIO lista_comandos T_FIM
    ;

cabecalho
    : T_PROGRAMA T_IDENTIF
    ;

variaveis
    : /* vazio*/
    | declaracao_variaveis
    ;

declaracao_variaveis
    : tipo lista_variaveis declaracao_variaveis
    | tipo lista_variaveis
    ;

tipo
    : T_LOGICO 
    | T_INTEIRO
    ;

lista_variaveis
    : T_IDENTIF lista_variaveis
    | T_IDENTIF
    ;

lista_comandos
    : /*vazio*/
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
    : T_LEIA T_IDENTIF
    ;

saida
    : T_ESCREVA expressao
    ;

atribuicao
    : T_IDENTIF T_ATRIB expressao
    ;

selecao
    : T_SE expressao T_ENTAO lista_comandos T_SENAO lista_comandos T_FIMSE
    ;

repeticao
    : T_ENQTO expressao T_FACA lista_comandos T_FIMENQTO
    ;

expressao
    : expressao T_VEZES expressao
    | expressao T_DIV expressao
    | expressao T_MAIS expressao
    | expressao T_MENOS expressao
    | expressao T_MAIOR expressao
    | expressao T_MENOR expressao
    | expressao T_E expressao
    | expressao T_IGUAL expressao
    | expressao T_OU expressao
    | termo
    ;

termo
    : T_IDENTIF
    | T_NUMERO
    | T_V
    | T_F
    | T_NAO termo
    | T_ABRE expressao T_FECHA
    ;
%%

int main(){
    yyparse();
    printf("Programa: \e[1;32mok!\n\n");
    return 0;
}
