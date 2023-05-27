%Árvore Genealógica

pai(ricardo,lucas).
pai(ricardo,leonardo).
pai(robson,robsonJr).
pai(moises,joaquim).
%-------------------------------------------------------------
pai(antonio,ricardo).
pai(antonio,robson).
pai(antonio,rosangela).
pai(antonio,moises).
%-------------------------------------------------------------
pai(walter,antonio).
pai(carlos,marta).
%-------------------------------------------------------------
pai(alberoneJr,gabriel).
%-------------------------------------------------------------
pai(alberone,lidyane).
pai(alberone,alberoneJr).
pai(alberone,taty).
pai(alberone,tany).
%-------------------------------------------------------------
pai(cesar,heloisa).
pai(angelo,alberone).
%-------------------------------------------------------------
mae(lidyane,lucas).
mae(lidyane,leonardo).
%-------------------------------------------------------------
mae(rosangela,juan).
mae(rosangela,kamila).
mae(taty,luisa).
mae(tany,lara).
%-------------------------------------------------------------
mae(marta,ricardo).
mae(marta,rosangela).
mae(marta,robson).
mae(marta,moises).
%-------------------------------------------------------------
mae(lindali,marta).
mae(karla,antonio).
%-------------------------------------------------------------
mae(heloisa,lidyane).
mae(heloisa,tany).
mae(heloisa,taty).
mae(heloisa,alberoneJr).
%-------------------------------------------------------------
mae(raimunda,heloisa).
mae(benedete,alberone).
%-------------------------------------------------------------


avoP(X,Y):- pai(X,Z),pai(Z,Y). %avô paterno
avoM(X,Y):- pai(X,Z),mae(Z,Y). %avô materno
avos(X,Y):- pai(X,Z),(mae(Z,Y);pai(Z,Y)). %avôs
avohP(X,Y):- mae(X,Z),pai(Z,Y). %avó paterna
avohM(X,Y):- mae(X,Z),mae(Z,Y). %avó materna
avohs(X,Y):- mae(X,Z),(mae(Z,Y);pai(Z,Y)). %avós
todosavos(X,Y):-(pai(X,Z),(mae(Z,Y);pai(Z,Y)));(mae(X,Z),(mae(Z,Y);pai(Z,Y))). %todos os avós
neto(X,Y):-(pai(Y,Z),(mae(Z,X);pai(Z,X)));(mae(Y,Z),(mae(Z,X);pai(Z,X))). %os netos

irmaoP(X,Y):- pai(Z,X),pai(Z,Y),X\=Y. %irmão paterno
irmaoM(X,Y):- mae(Z,X),mae(Z,Y),X\=Y. %irmão materno
irmao(X,Y):-pai(P,X),pai(P,Y),mae(M,X),mae(M,Y). %irmão
tiosP(X,Y):- pai(Z,Y),pai(W,Z),pai(W,X),X\=Z. %tio paterno
tiosM(X,Y):- mae(Z,Y),pai(W,Z),pai(W,X),X\=Z. %tio materno
primoP(X,Y):- (pai(Z,X);mae(Z,X)),pai(W,Z),pai(W,P),pai(P,Y),Z\=P. %primo por parte de pai
primoM(X,Y):- (pai(Z,X);mae(Z,X)),mae(W,Z),mae(W,P),mae(P,Y),Z\=P. %primo por parte de mãe
todosprimos(X,Y):- ((pai(Z,X);mae(Z,X)),pai(W,Z),pai(W,P),pai(P,Y),Z\=P);
    ((pai(Z,X);mae(Z,X)),mae(W,Z),mae(W,P),mae(P,Y),Z\=P). %todos os primos



antecessor(X,Y):-pai(X,Y).
antecessor(X,Y):-mae(X,Y).
parente(X,Y):-antecessor(X,Y);antecessor(Y,X).
