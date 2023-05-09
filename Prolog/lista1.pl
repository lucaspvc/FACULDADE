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