%Lista de Exercício
%Autor: Lucas Pessoa Oliveira Alves

%Exercício 1
analisa_lista([]):- write('A lista está vazia').
analisa_lista([A|B]):- write('A cabeça da lista é: '),write(A),nl,
    write('A cauda da lista é: '),write(B).

%Exercício 2
pertence(X,[X|_]).
pertence(X,[_|R]):-pertence(X,R).

rm([],[]).
rm([A|B],List):-pertence(A,B),!,rm(B,List).
rm([A|B],[A|List]):-rm(B,List).


%Exercício 3
troca([],_,_,[]).
troca([A|B],X,Y,[Y|Rlist]):-
    X=:=A,
    troca(B,X,Y,Rlist).
troca([A|B],X,Y,[A|Rlist]):-
    troca(B,X,Y,Rlist).


%Resolução do Chat GePeTo.
trocaGPT([], _, _, []).
trocaGPT([X|Xs], X, Y, [Y|Ys]) :-
        trocaGPT(Xs, X, Y, Ys).

trocaGPT([X|Xs], X1, Y1, [X|Ys]) :- 
        trocaGPT(Xs, X1, Y1, Ys).

%Exercício 4


%Exercício 5
mais_longa([],_).
mais_longa([_|R],[_|R1]):-mais_longa(R,R1).

%Exercício 6
somatorio([],0).
somatorio([A|B],Y):- %função para fazer o somatório da lista
    Y is Y1+A,
    somatorio(B,Y1). 

comprimento(0,[]).
comprimento(A,[_|Y]):- %função para achar o comprimento da lista
    comprimento(A1,Y),
    A is A1+1. 

distancia((X1,Y1),(X2,Y2),R):-
    R is sqrt((X2-X1)**2+(Y2-Y1)**2). %resolução da fórmula do cálculo da distância

%Exercício 7

escreva(0,_). %caso base da escrita
escreva(A,Caracter):- %função para escrever uma linha
    write(Caracter),
    write(' '),
    A1 is A-1,
    escreva(A1,Caracter). 

quadrado(A, Caracter):-quadrado(A, A, Caracter). %passa a função para 3 parametros sabendo que é um quadrado n*n
quadrado(0,_,_). %caso base do quadrado
quadrado(A, L, Caracter):-
    escreva(L, Caracter),
    nl,
    A1 is A-1,
    quadrado(A1, L, Caracter).