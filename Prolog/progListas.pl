%Exercícios dos slides

/*
Exercício 1
Escreva o predicado Prolog m ́aximo/2 que retorna o maior valor de
uma lista de inteiros. Exemplo de uso:
?-maximo(X,[4,3,7,9,1]).
X = 9
*/

maximo(A,[A]).
/*A é o máximo valor de uma lista que só tem A */
maximo(A, [A|B]):-maximo(C, B), A > C.
/*A cabeça é o maior que o máximo da cauda*/
maximo(C, [A|B]):-maximo(C, B), C >= A.
/*O máximo está na cauda da lista*/

/*
Exercício 2
Escreva o predicado Prolog comprimento/2 que calcula o
comprimento de uma lista. Exemplo de uso:
?-comprimento(X,[a,b,c])
X = 3
*/

comprimento(0,[]).
comprimento(A,[_|Y]):-comprimento(A1,Y), A is A1+1.
