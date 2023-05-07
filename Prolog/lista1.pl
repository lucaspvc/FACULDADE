%Lista de Exercício
%Autor: Lucas Pessoa Oliveira Alves

%exercício 1
analisa_lista([]):- write('A lista está vazia').
analisa_lista([A|B]):- write('A cabeça da lista é: '),write(A),nl,
    write('A cauda da lista é: '),write(B).

%exercício 2