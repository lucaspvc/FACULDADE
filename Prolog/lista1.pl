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


%Exercício 8
elemento_n(List,N,X):-elemento_n(List,N,1,X).%passa a função para 4 parametros
elemento_n([A|_],N,N,A):-!.
elemento_n([_|B],N,I,X):-
    I1 is I+1,
    elemento_n(B,N,I1,X).


%Exercício 9
comprimento(0,[]).
comprimento(A,[_|Y]):- %função para achar o comprimento da lista
    comprimento(A1,Y),
    A is A1+1. 

somatorio(0,[]).
somatorio(Y,[A|B]):- %função para fazer o somatório da lista
    somatorio(Y1,B), Y is Y1+A. 

media(L,X):- 
    somatorio(Soma,L),
    comprimento(Comp, L),
    X is Soma/Comp.


%Exercício 10
minimo([X],X).
minimo([A|T],B):- minimo(T,B), B =< A.
minimo([A|T],A):- minimo(T,B), B > A.


%Exercício 11
intervalo(X,X,[X]).
intervalo(X,Y,[]):- X > Y.
intervalo(X,Y,[X|R]):- Y =\= X, X1 is X+1, intervalo(X1, Y, R).

%Exercício 12
mdc(X,X,X).
mdc(X,Y,D) :- X < Y, Y1 is Y - X, mdc(X,Y1,D).
mdc(X,Y,D) :- Y < X, mdc(Y,X,D).


%Exercício 13
ocorrencias(_, [], 0).

ocorrencias(Palavra, [Palavra|Xs], N1) :-
    ocorrencias(Palavra, Xs, N),
    N1 is N + 1.

ocorrencias(Palavra, [_|Xs], N) :-
    ocorrencias(Palavra, Xs, N).


%Exercício 14
divisores(Numero, List):-
    divisores(Numero, 1, List).

divisores(Numero, D, [D|Divisores]) :-
    D =< Numero, 
    Numero mod D =:= 0, 
    D1 is D + 1,
    divisores(Numero, D1, Divisores).

divisores(Numero, D, Divisores) :-
    D =< Numero,
    D1 is D+1,
    divisores(Numero, D1, Divisores).

divisores(N, D, []) :-
    D > N.