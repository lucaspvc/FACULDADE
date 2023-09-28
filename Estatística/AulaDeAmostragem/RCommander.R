library(readxl)
#Leitura no Linux da faculdade
#Dataset <- read_excel("/home/2022.1.08.044/Desktop/Estatística/AuladeAmostragem/Dados_Aula_Pratica_Amostragem.xlsx")

#Leitura no Windows em casa
Dataset <- read_excel("Estatística/AuladeAmostragem/Dados_Aula_Pratica_Amostragem.xlsx")

#Ao inv�s de usar o comando apresentado anteriormente, repita o processo
#utilizado em sala de aula
print("Hello world")

#Determinando que a Idade � a vari�vel resposta
dados<-Dataset$Idade

#Tamanho da popula��o
N<-length(dados)

N

#Tamanho da amostra
n<-80

#Amostragem casual simples

#Fazendo a amostra direta da vari�vel idade
amostracs<-sample(dados,n)
amostracs


mediacs<-mean(amostracs)
mediacs

#Amostragem sistemática

#Tamanho do pulo

pulo<-round(N/n,0)
pulo

#Criando um vetor para guardar as observa��es sorteadas
obsist<-c()

#Sorteando o primeiro elemento amostral
obsist[1]<-sample(pulo,1)
obsist[1]

#Determinado os demais elementos amostrais
for(i in 2:n)
obsist[i]<-obsist[i-1]+pulo

obsist

#Tomando a idade dos elementos amostrados

amostrasist<-c()
for(i in 1:n)
amostrasist[i]<-dados[obsist[i]]

amostrasist
mediasist<-mean(amostrasist)
mediasist


#Amostragem estratificada

#Estratificando pela atua��o
aprendeu<-Dataset$Aprendeu
aprendeu

#Verificando quantos elementos tem na popula��o de cada atua��o
summary(aprendeu)

#Tamanho da população de 1
N1<-1867
#Tamanho da população de 2
N2<-1148
#Tamanho da população de 3
N3<-1176
#Tamanho da população de 4
N4<-1207
#Tamanho da população de 5
N5<-229
#Tamanho da população de 6
N6<-264
#Tamanho da população de 7
N7<-1082
#Tamanho da população de 8
N8<-551
#Tamanho da população de 9
N9<-188

N<-length(aprendeu)
N

#Definir o tamanho da amostra em cada estrato

TamanhoPop<-c(N1,N2,N3,N4,N5,N6,N7,N8,N9)
TamanhoPop

Tamanhoamos<-round((TamanhoPop/N)*n,0)
Tamanhoamos
sum(Tamanhoamos)

aprendeu1<-c()
aprendeu2<-c()
aprendeu3<-c()
aprendeu4<-c()
aprendeu5<-c()
aprendeu6<-c()
aprendeu7<-c()
aprendeu8<-c()
aprendeu9<-c()

c1<-1
c2<-1
c3<-1
c4<-1
c5<-1
c6<-1
c7<-1
c8<-1
c9<-1

for(i in 1:N){
    if(aprendeu[i]=="1"){
        aprendeu1[c1]<-dados[i]
        c1<-c1+1
        }
        else if(aprendeu[i]=="2"){
            aprendeu2[c2]<-dados[i]
            c2<-c2+1
        }
        else if(aprendeu[i]=="3"){
            aprendeu3[c3]<-dados[i]
            c3<-c3+1
        }
        else if(aprendeu[i]=="4"){
            aprendeu4[c4]<-dados[i]
            c4<-c4+1
        }
        else if(aprendeu[i]=="5"){
            aprendeu5[c5]<-dados[i]
            c5<-c5+1
        }
        else if(aprendeu[i]=="6"){
            aprendeu6[c6]<-dados[i]
            c6<-c6+1
        }            
        else if(aprendeu[i]=="7"){
            aprendeu7[c7]<-dados[i]
            c7<-c7+1
        }
        else if(aprendeu[i]=="8"){
            aprendeu8[c8]<-dados[i]
            c8<-c8+1
        }
        else{
            aprendeu9[c9]<-dados[i]
            c9<-c9+1
        }                                    
}

aprendeu1
aprendeu2
aprendeu3
aprendeu4
aprendeu5
aprendeu6
aprendeu7
aprendeu8
aprendeu9

#Amostrando o estrato de 1
amostra1<-sample(aprendeu1,Tamanhoamos[1])
#Amostrando o estrato de 2
amostra2<-sample(aprendeu2,Tamanhoamos[2])
#Amostrando o estrato de 3
amostra3<-sample(aprendeu3,Tamanhoamos[3])
#Amostrando o estrato de 4
amostra4<-sample(aprendeu4,Tamanhoamos[4])
#Amostrando o estrato de 5
amostra5<-sample(aprendeu5,Tamanhoamos[5])
#Amostrando o estrato de 6
amostra6<-sample(aprendeu6,Tamanhoamos[6])
#Amostrando o estrato de 7
amostra7<-sample(aprendeu7,Tamanhoamos[7])
#Amostrando o estrato de 8
amostra8<-sample(aprendeu8,Tamanhoamos[8])
#Amostrando o estrato de 9
amostra9<-sample(aprendeu9,Tamanhoamos[9])

#Juntando os elementos amostrados em um �nico conjunto de dados
amostraest<-c(amostra1,amostra2,amostra3,amostra4,amostra5,amostra6,amostra6,amostra7,amostra8,amostra9)
amostraest

#M�dia da idade a amostra obtida pela t�cnica de amostragem estratificada.

mediaest<-mean(amostraest)
mediaest

#Calculando os erros de estima��o;

#M�dia da popula��o

mediapop<-mean(dados)

#Erro de estima��o: casual simples

errocs<-abs(mediacs-mediapop)
errocs


#Erro de estima��o: sistem�tica

errosist<-abs(mediasist-mediapop)
errosist


#Erro de estima��o: estratificada

erroest<-abs(mediaest-mediapop)
erroest