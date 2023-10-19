%{
#include "sintatico.h"    
%}
identificador [a-zA-Z]([a-zA-Z0-9])*
numero [0-9]+
espaco [ \t]+
novalinha [\n]

%%
programa     return T_PROGRAMA;
inicio       return T_INICIO;
fimprograma  return T_FIM;
leia         return T_LEIA;
escreva      return T_ESCREVA;
se           return T_SE;
entao        return T_ENTAO;
senao        return T_SENAO;
fimse        return T_FIMSE;
enquanto     return T_ENQTO;
fimemquanto  return T_FIMENQTO;
"+"          return T_MAIS;
"-"          return T_MENOS; 
"*"          return T_VEZES;
div          return T_DIV;
">"          return T_MAIOR;
"<"          return T_MENOR;
"="          return T_IGUAL;
"<-"         return T_ATRIB;
e            return T_E;
ou           return T_OU;
nao          return T_NAO;
"("          return T_ABRE;
")"          return T_FECHA;
inteiro      return T_INTEIRO;
logico       return T_LOGICO;
"V"          return T_V;
"F"          return T_F;  


{identificador} return T_IDENTIF;
{numero}        return T_NUMERO;
{espaco}      /* nada */
{novalinha}   /* nada */
              erro("lexico!");

%%
int yywrap() { return 1;}
int main(){
    yylex();
    return 0;
}