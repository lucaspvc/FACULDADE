% Aluno: Lucas Pessoa Oliveira Alves      RA:2022.1.08.044
sudoku(S) :- resolve(S), mostraSolucao(S).

resolve(S) :- 
    resolveLinhas(S),
    resolveColunas(S),
    resolveQuadros(S).

resolveLinhas([]) :- !.
resolveLinhas([A|B]) :- diferente(A), resolveLinhas(B).

% Resolucao
resolveColunas([[A,B,C,D],[A1,B1,C1,D1],[A2,B2,C2,D2],[A3,B3,C3,D3]]) :-
  diferente([A,A1,A2,A3]),diferente([B,B1,B2,B3]),
  diferente([C,C1,C2,C3]),diferente([D,D1,D2,D3]).

resolveQuadros([[A,B,C,D],[A1,B1,C1,D1],[A2,B2,C2,D2],[A3,B3,C3,D3]]):-
  diferente([A,B,A1,B1]), diferente([C,D,C1,D1]),
  diferente([A2,B2,A3,B3]), diferente([C2,D2,C3,D3]).

diferente([A, B, C, D]) :- 
   num(A), num(B), num(C), num(D), 
   A\=B, A\=C, A\=D, B\=C, B\=D, C\=D.

num(1).
num(2).
num(3).
num(4).

mostraSolucao([]):- !.
mostraSolucao([A|B]) :- 
    mostraLinha(A), nl, mostraSolucao(B).

mostraLinha([]) :- !.
mostraLinha([A|B]) :- 
    write(A), write(' '), mostraLinha(B).

%   Exemplo de consulta:
%   -------------------
%?- sudoku([[4,_,_,_],[_,3,_,_],[_,_,1,_],[_,1,_,2]]).