/**********************************
    Resolução da Lista 2
    Lucas Pessoa Oliveira Alves 
***********************************/

/* Exercício 1
Qual é o resultado das seguintes consultas em Prolog?
?- forall(member(X,[1,2,3]),write(X)).
Resposta:
123
true
?- forall(between(1,5,I),(write(I*I),write(’ ’))).
Resposta:
1*1 2*2 3*3 4*4 5*5
true
?- forall(between(10,20,I),write(I:’ ’)).
Resposta:
10: 11: 12: 13: 14: 15: 16: 17: 18: 19: 20:
true
*/

/* Exercício 2
Considere o seguinte programa Prolog:
a:-a(0).
a(X):- X>10,!.
a(X):- write(X),write(’ ’), X1 is X+1,a(X1).
Qual será o resultado da seguinte consulta Prolog:
?- a.
Resposta: 
0 1 2 3 4 5 6 7 8 9 10 
true
*/
a:-a(0).
a(X) :- X>10,!.
a(X):- write(X),write(' '), X1 is X + 1, a(X1).

/* Exercício 3
Faça um predicado que gere a pirâmide abaixo. Use o predicado wN/1.
wN(0):-write(0),!.
wN(N):-write(N),N1 is N-1, wN(N1),write(N).
Exemplo de uso:
?- xxx(3).
   0
  101
 21012
3210123
*/
wN(0):-write(0),!.
wN(N):-write(N),N1 is N-1, wN(N1),write(N).

espaco(0):-!.
espaco(N):- write(' '), N1 is N - 1, espaco(N1).

xxx(N):- forall(between(0,N,I),(N1 is N - I, espaco(N1), wN(I), nl)).

/* Exercício 4
Usando um acumulador, e somente as operações (+)(-)(*), desenvolva um predicado
Prolog para calcular X elevado a Y. Assuma X e Y inteiros.
Acumulador: vem guardando o resultado desde a base
*/
potencia(_, 0, 1):- !.
potencia(X, 1, X):- !.
potencia(X, Y, R) :- Y1 is Y - 1, potencia(X,Y1,Ac), R is X * Ac.
%acumulador nesse caso é o Ac

/* Exercício 5
Dados os fatos:
d(0).
d(1).
Qual é o resultado da seguinte consulta Prolog:
?- findall([A,B],(d(A),d(B)),L).
Resposta: L = [[0, 0], [0, 1], [1, 0], [1, 1]].
Esta consulta encontra uma lista com todas as possiblidades de se escrever uma lista [A,B] com números variandao entre 0 e 1.
*/
d(0).
d(1).

/* Exercício 6
Defina o predicado palindromo/1, que é verdadeiro se a lista é um palı́ndromo,
por exemplo, [a,b,c,d,c,b,a].
*/
ult([X], X):- !.
ult([_|B],X) :- ult(B,X).

palindromo([]):-!.
palindromo([_]):- !.
palindromo([Cabeca|Cauda]) :- ult(Cauda, Ultimo), Ultimo = Cabeca, append(L, [Ultimo], Cauda), palindromo(L),!.

/* Exercício 7
Defina um predicado metIguais/1, que é verdadeiro se uma lista é formada por
duas metades iguais. Use o append. Seguem dois exemplos de uso.
?-metIguais([a,b,c, a,b,c]).
Yes
?-metIguais([a,b,c, a,b,d]).
No
*/
metIguais(Lista) :- append(Metade, Metade, Lista), !.

/* Exercício 8
Faça um predicado insOrd/3, que insere um elemento numa lista mantendo-a ordenada.
Faça duas regras: uma base e uma recursiva.
?-insOrd(4,[2,3,5,7],L).
L=[2,3,4,5,7] Yes
*/

insOrd(X, [A|B], [A|Rs]) :- X > A, !, insOrd(X,B,Rs).
insOrd(X, [A|B], [X,A|B]).

/* Exercício 9
Faça um predicado que particiona/3 uma lista em duas, de tamanho igual se o número de
elementos for par, senão uma delas terá um elemento a mais. Tire dois elementos de uma
lista (se possı́vel) e ponha cada um em uma lista resultado.
*/

particiona(L,L1,L2):- length(L, T),
     T1 is T // 2,
     length(L1, T1),
     append(L1,L2,L),!.

/* Exercício 10
Faça o predicado merge/3, que junta duas listas ordenadas em uma terceira, mantendo a
ordem. Como segue:
?- merge([a,b,b,k,z], [c,m,n,o], X).
X=[a,b,b,c,k,,m,n,o,z], yes
*/
merge(A,[],A):- !.
merge([],A,A):- !.
merge([A|R1],[B|R2],[A|R]) :- 
    A @=< B, % o '@' ao inicio do operador permite que ele compare caracteres
    merge(R1,[B|R2],R), !. 
merge([A|R1],[B|R2],[B|R]) :-
    B @=< A,
    merge([A|R1],R2,R), !.


/* Exercício 11
O que está errado no programa abaixo? Rode-o com trace, para:
?- max(4,3,M) e
?- max(3,4,M)
max(X,Y,M):-!, X>Y, M=X.
max(X,Y,M):-!, X<=Y, M=Y
R: O operador "<=" não existe e o corte no inicio impossibilita a procura de novas possibilidades caso a condição falhe
*/

/* Exercício 12
O que acontece com o predicado p, abaixo, quando o b é executado?
a. b. p:-!,a. p:-b.
R: O predicado p sempre será verdadeiro se a for verdadeiro, visto que sua primeira cláusula possui um corte 
 logo no início, e não tenterá outras possibilidades.
*/

/* Exercício 13 
Usando findall, defina e teste os predicados pred1/2, pred2/2 e pred3/2 que modificam
uma lista, conforme ilustrado nos seguintes exemplos:
?- pred1([a,b,c,d,e],L).
L = [[a],[b],[c],[d],[e]]
?- pred2([a,b,c,d,e],L).
L = [pred(a,a),pred(b,b),pred(c,c),pred(d,d),pred(e,e)]
?- pred3([a,b,c,d,e],L).
L = [[element,a],[element,b],[element,c],[element,d],[element,e]]
*/

elem([A|_], A).
elem([_|B], X) :- elem(B,X). 

pred1(A,L) :- findall([X],(elem(A,X)),L).

pred2(A,L) :- findall(pred(X,X),elem(A,X),L).

pred3(A,L) :- findall([element,X],elem(A,X),L).


/* Exercício 14
Considere o seguinte problema: “Há dois jarros com capacidades de 3 e 4 litros,
respectivamente. Nenhum dos jarros contém qualquer medida ou escala, de modo que só
se pode saber o conteúdo exato quando eles estão cheios. Sabendo-se que podemos
encher ou esvaziar um jarro, bem como transferir água de um jarro para outro, encontre
uma sequência de passos que deixe o jarro de 4 litros com exatamente 2 litros de água”.
Considere que o estado inicial pode ser representado pela lista [0,0], indicando que os
jarros de 3 e 4 litros estão vazios inicialmente e a meta é [_,2]. Complete os predicados
transforma abaixo para descrever todas as transformações possíveis de estados desse
problema.
transforma('encher o jarro 1', [X,Y], [3,Y]) :- X < 3.
transforma('enchar o jarro 2', ...
transforma('esvaziar o jarro 1', ...
transforma('esvaziar o jarro 2', ...
transforma('transferir do jarro 1 para o 2', ...
transforma('transferir do jarro 2 para o 1', ...
%--- considerando que ainda restara agua no jarro de origem
transforma('transferir do jarro 1 para o 2', ...
transforma('transferir do jarro 2 para o 1', ...
*/
/*
transforma('encher o jarro 1', [X,Y], [3,Y]) :- X < 3.
transforma('enchar o jarro 2', [X,Y], [X,4]) :- Y < 4.
transforma('esvaziar o jarro 1', [X,Y], [0,Y]) :- X > 0.
transforma('esvaziar o jarro 2', [X,Y], [X,0]) :- Y > 0.
transforma('transferir do jarro 1 para o 2', [X,Y], [0,Y1]) :- X > 0, Y < 4, Y1 is X + Y, Y1 =< 4.
transforma('transferir do jarro 2 para o 1', [X,Y], [X1,0]) :- Y > 0, X < 3, X1 is X + Y, X1 =< 3. 
%--- considerando que ainda restara agua no jarro de origem
transforma('transferir do jarro 1 para o 2', [X,Y], [X1,4]) :- X > 0, Y < 4, BALDAO is X + Y, BALDAO > 4, X1 is BALDAO - 4.
transforma('transferir do jarro 2 para o 1', [X,Y], [3,Y1]) :- X < 3, Y > 0, BALDAO is X + Y, BALDAO > 3, Y1 is BALDAO - 3.
*/

/* Questão 1
Considere os seguintes fatos sobre alguns carros:
1- carro(fusca,branco,1974).
2- carro(gol,vermelho,1980).
3- carro(voyage,preto,1978).
4- carro(gol,branco,2001).
5- carro(uno,branco,2004).
Escreva uma consulta unsando findall para obter uma lista contendo marca e anos dos carros brancos da seguinte forma:
L = [fusca-1974,gol-2001,uno-2004]
*/
carro(fusca,branco,1974).
carro(gol,vermelho,1980).
carro(voyage,preto,1978).
carro(gol,branco,2001).
carro(uno,branco,2004).

% RESPOSTA: findal(M-A,carro(M,branco,A),L).

/* Questão 2
Escreva o predicado prolog pares/2 que separa os valores pares de uma lista conforme o seguinte exemplo de uso:
?- pares([1,2,3,4],X).
X = [2, 4].
Considere a expressão (A mod 2) =:= 0 para testea se o valor de A é par
*/

pares([A|B],[A|Y]):- A mod 2 =:= 0, !, pares(B,Y).
pares([_|B],Y):-pares(B,Y).
pares([],[]).


/* Questão 3
Implemente o predicado trunca/3 para truncar uma lista de valores, conforme o seguinte exemplo de uso:
?- trunca([10,20,30,40,50,60],4,L).
L = [10,20,30,40].
*/

trunca(_,0,[]).
trunca([A|B],X,L):- X1 is X - 1, trunca(B,X1,L1), append([A],L1,L),!.

/* Questão 4
Dados os fatos:
d(0).
d(1).
Qual é o resultado da seguinte consulta prolog:
?- findall([A,B],(d(A),d(B)), L).

Resposta: L = [[0, 0], [0, 1], [1, 0], [1, 1]].
Esta consulta encontra uma lista com todas as possiblidades de se escrever uma lista [A,B] com números variandao entre 0 e 1.
*/

/* Questão 5
Considere o seguinte problema: “Há dois jarros com capacidades de 3 e 4 litros,
respectivamente. Nenhum dos jarros contém qualquer medida ou escala, de modo que só
se pode saber o conteúdo exato quando eles estão cheios. Sabendo-se que podemos
encher ou esvaziar um jarro, bem como transferir água de um jarro para outro, encontre
uma sequência de passos que deixe o jarro de 4 litros com exatamente 2 litros de água”.
Considere que o estado inicial pode ser representado pela lista [0,0], indicando que os
jarros de 3 e 4 litros estão vazios inicialmente e a meta é [_,2]. Complete os predicados
transforma abaixo para descrever todas as transformações possíveis de estados desse
problema.
transforma('encher o jarro 1', [X,Y], [3,Y]) :- X < 3.
transforma('enchar o jarro 2', ...
transforma('esvaziar o jarro 1', ...
transforma('esvaziar o jarro 2', ...
transforma('transferir do jarro 1 para o 2', ...
transforma('transferir do jarro 2 para o 1', ...
%--- considerando que ainda restara agua no jarro de origem
transforma('transferir do jarro 1 para o 2', ...
transforma('transferir do jarro 2 para o 1', ...
*/

/*
RESPOSTA:
transforma('encher o jarro 1', [X,Y], [3,Y]) :- X < 3.
transforma('enchar o jarro 2', [X,Y], [X,4]) :- Y < 4.
transforma('esvaziar o jarro 1', [X,Y], [0,Y]) :- X > 0.
transforma('esvaziar o jarro 2', [X,Y], [X,0]) :- Y > 0.
transforma('transferir do jarro 1 para o 2', [X,Y], [0,Y1]) :- X > 0, Y < 4, Y1 is X + Y, Y1 =< 4.
transforma('transferir do jarro 2 para o 1', [X,Y], [X1,0]) :- Y > 0, X < 3, X1 is X + Y, X1 =< 3. 
%--- considerando que ainda restara agua no jarro de origem
transforma('transferir do jarro 1 para o 2', [X,Y], [X1,4]) :- X > 0, Y < 4, BALDAO is X + Y, BALDAO > 4, X1 is BALDAO - 4.
transforma('transferir do jarro 2 para o 1', [X,Y], [3,Y1]) :- X < 3, Y > 0, BALDAO is X + Y, BALDAO > 3, Y1 is BALDAO - 3.
*/