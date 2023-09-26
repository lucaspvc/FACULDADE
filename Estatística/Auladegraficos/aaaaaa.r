library(readxl)
library(ploty)
Dataset <- read_excel("/home/2022.1.08.044/Desktop/Estatística/Auladegraficos/Dados_Aula_Pratica_Amostragem.xlsx")
summary(Dataset)
summary(dados)

dados <- Dataset$Idade

#Tabela corrigida com o n�mero de casas decimais

tabela<-function(dados,cd) {
    A<-max(dados)-min(dados)
    n<-length(dados) 
    if(n<=100) {
        k<-ceiling(sqrt(n))
    } else { 
        k<-ceiling(5*log10(n))
    }
    C<-round(A/(k-1),cd)
    LI<-c(rep(0,(k+1)))
    media<-c(NA)
    LI[1]<-round(min(dados)-(C)/2,cd)
    for(i in 2:(k+1)) {
        LI[i]<-round(LI[i-1]+C,cd)
        media[i-1]<-mean(c(LI[i],LI[i-1]))
    }
    limites<-LI
    TDF<-hist(dados,breaks=limites,plot=FALSE,right=FALSE)
    tabela<-matrix(c(rep(6*k)),k,6)

    for(i in 1:k) {
        tabela[i,1]<-round(LI[i],cd)
        tabela[i,2]<-round(LI[i+1],cd)
        tabela[i,3]<-round(media[i],cd)
        tabela[i,4]<-(TDF$counts[i])
        tabela[i,5]<-round(((TDF$counts[i])/n),5)
        tabela[i,6]<-round((100*TDF$counts[i])/n,3)
    }

    colnames(tabela)<-c("LI","LS","X","Fa","Fr","Fp")
    return(tabela)

}

tabela(dados,1)

porcentagem<-tabela(dados,1)[,6]
porcentagem
sum(porcentagem[1:6])

#Histograma

quebras<-function(dados,cd) {
  A<-max(dados)-min(dados)
  n<-length(dados) 
  if(n<=100) {
    k<-ceiling(sqrt(n))
  } else {
    k<-ceiling(5*log10(n))
  }
  C<-round(A/(k-1),cd)
  
  LI<-c(rep(0,(k+1)))
  LI[1]<-round(min(dados)-(C)/2,cd)
  for(i in 2:(k+1)) {
    LI[i]<-round(LI[i-1]+C,cd)
  }
  
  return(LI)
}

limites<-quebras(dados,3)
limites

#Construindo as informa��es Tabela de Distribui��o de Frequ�ncias

TDF<-hist(dados,breaks=limites,plot=FALSE,right=FALSE)
TDF

hist(
  dados,label=FALSE,main="",
  xlab=expression(paste("Idade (Anos)")), 
    ylab="Frequencia absoluta", 
    ylim=c(0,(max(TDF$counts)+1)),
    breaks=limites,axes=FALSE,right=FALSE
)
axis(1,at=limites,pos=c(0,0))
axis(2,at=c(seq(0:(max(TDF$counts)+1))-1))

Dataset <- within(Dataset, {
  Aprendeu <- as.factor(Aprendeu)
})
with(Dataset, Barplot(Aprendeu, xlab="Aprendeu", ylab="Frequency", label.bars=TRUE))
with(Dataset, Barplot(Aprendeu, xlab="Forma que o trabalhador de TI aprendeu a programar", ylab="Frequencia", 
  label.bars=TRUE))
with(Dataset, Barplot(Aprendeu, xlab="Forma que o trabalhador de TI aprendeu a programar", ylab="Frequencia", 
  scale="percent", label.bars=TRUE))
library(colorspace, pos=16)
with(Dataset, piechart(Atuacao, xlab="Atuacao do entusiasta de TI", ylab="", main="Atuacao", col=rainbow_hcl(3), 
  scale="percent"))
library(abind, pos=17)
library(e1071, pos=18)
numSummary(Dataset[,"Idade", drop=FALSE], statistics=c("mean", "sd", "quantiles", "CV"), quantiles=c(0,.25,.5,.75,
  1))

Boxplot( ~ Idade, data=Dataset, id=list(method="y"))
