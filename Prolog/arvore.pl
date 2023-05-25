%Árvore Genealógica

pai(ricardo,lucas).
pai(ricardo,leonardo).
pai(antonio,ricardo).
pai(alberone,lidyane).
pai(antonio,robson).
pai(antonio,rosangela).
pai(antonio,moises).
pai(alberone,alberoneJr).
pai(alberone,taty).
pai(alberone,tany).

mae(lidyane,lucas).
mae(lidyane,leonardo).
mae(marta,ricardo).
mae(heloisa,lidyane).
mae(marta,rosangela).
mae(marta,robson).
mae(marta,moises).
mae(heloisa,tany).
mae(heloisa,taty).
mae(heloisa,alberoneJr).
''''''''''''''''''''''''''''''''''''
avoP(X,Y):- pai(X,Z),pai(Z,Y). %avô paterno
avoM(X,Y):- pai(X,Z),mae(Z,Y). %avô materno
avos(X,Y):- pai(X,Z),(mae(Z,Y);pai(Z,Y)). %avôs
avohP(X,Y):- mae(X,Z),pai(Z,Y). %avó paterna
avohM(X,Y):- mae(X,Z),mae(Z,Y). %avó materna
avohs(X,Y):- mae(X,Z),(mae(Z,Y);pai(Z,Y)). %avós
todosavos(X,Y):-(pai(X,Z),(mae(Z,Y);pai(Z,Y)));(mae(X,Z),(mae(Z,Y);pai(Z,Y))). %todos os avós
neto(X,Y):-(pai(Y,Z),(mae(Z,X);pai(Z,X)));(mae(Y,Z),(mae(Z,X);pai(Z,X))).
neto1(X,Y):-
    pai(Y,Z),pai(Z,X);
    mae(Y,Z),pai(Z,X);
    pai(Y,Z),mae(Z,X);
    mae(Y,Z),mae(Z,X).

irmaoP(X,Y):- pai(Z,X),pai(Z,Y),X\=Y. %irmão paterno
irmaoM(X,Y):- mae(Z,X),mae(Z,Y),X\=Y. %irmão materno
irmao(X,Y):-pai(P,X),pai(P,Y),mae(M,X),mae(M,Y). %irmão
tiosP(X,Y):- pai(Z,Y),pai(W,Z),pai(W,X),X\=Z. %tio paterno
tiosM(X,Y):- mae(Z,Y),irmaoP(X,Z). %tio materno

antecessor(X,Y):-pai(X,Y).
antecessor(X,Y):-mae(X,Y).
antecessor(X,Y):-pai(X,Z),antecessor(Z,Y).
antecessor(X,Y):-mae(X,Z),antecessor(Z,Y).
parente(X,Y):-antecessor(X,Y);antecessor(Y,X).