#1-a
#==================================================================================
n=750      #tamanho da amostra#
np=180        # número de sucessos em n#
pe=np/n;pe     # proporção amostral
conf=0.90  # nível de confiança#
alfa=1-conf;alfa  # nível de significância#
me_p=qnorm(1-alfa/2)*(sqrt(pe*(1-pe))/sqrt(n));me_p  #calculando a margem de erro#
IC_p=cbind(pe-me_p,  pe +me_p);IC_p

#Existe 90% de confiança de que a proporção de crianças desse bairo que não possui cárie, esteja entre 21,435% e 26,565%

#==================================================================================
#1-b
#==================================================================================
pap= 0.24      #propor  o na amostra piloto
merrod=  0.025   #margem de erro desejada, deve sempre ser em DECIMAL
conf=0.99  # n vel de confian
alfa=1-conf;alfa  # n vel de signific ncia
n_novo_pi=((qnorm(alfa/2,lower.tail = FALSE)*(sqrt(pap*(1-pap))/merrod)))^2  
n_novo_pi

#O tamanho amostral mínimo, com 99% de confiança e com o erro de estimação máximo de 2,5%, deve ser de 1937.

#==================================================================================
#2-a
#==================================================================================
75.8+67.0+67.7+76.4+98.2+82.9+88.8+82.3+62.2+87.2+73.2
861.7/11
Dataset <- readXL("/home/2022.1.08.044/FACULDADE/Estatística/Prova2/dados2.xlsx", rownames=FALSE, header=TRUE, na="", sheet="Sheet1",
   stringsAsFactors=TRUE)
library(abind, pos=16)
library(e1071, pos=17)
numSummary(Dataset[,"peso", drop=FALSE], statistics=c("mean", "sd", "IQR", "quantiles"), quantiles=c(0,.25,.5,.75,1))
My= 78.336      # média amostral
DPy= 10.760      # desvio padrão amostral
ny=  11         # tamanho da amostra 
conf=0.90      # nível de confiança#
alfa=1-conf;alfa  # nível de significância# 
me_mi=qt((alfa/2),ny-1,lower.tail = FALSE)*(DPy/sqrt(ny));me_mi    #calculando a margem de erro#
IC_mi=cbind(My-me_mi,My+me_mi);IC_mi

#Existe 90% de confiança de que a média dos pesos dos pacientes atendidos por esse PSF, esteja entre 72,456kg e 84,216kg.

#==================================================================================
#2-b
#==================================================================================
DPap= 10.760   # desvio Padr o da amostra piloto
nap=  11   #tamanho da amostra piloto
conf=0.99  # n vel de confian a#
alfa=1-conf;alfa  # n vel de signific ncia#
merrod= 2.5  #margem de erro desejada, NA MESMA UNIDADE DA M DIA#
n_novo_mi=(qt((alfa/2),nap-1,lower.tail = FALSE)*DPap/merrod)^2   ; n_novo_mi

#O tamanho amostral, com 99% de confiança e o erro máximo na estima de peso médio seja 2,5kg, deve ser de 187.

#==================================================================================
#3-a
#==================================================================================

local({
  .Table <- data.frame(Probability=dpois(1:19, lambda=20))
  rownames(.Table) <- 1:19 
  print(.Table)
})
#X: número de interrupções em 2,5 semanas
#X~Poisson(20)
#P(x=12)=?
#P(X=12)=0.01762517126771
#P(X=12)=0.018

#==================================================================================
#3-b
#==================================================================================
ppois(c(3), lambda=4, lower.tail=FALSE)

#X: número de interrupções em 0,5 semanas
#X~Poisson(4)
#P(x>=3)=?
#P(X>=3)=0.5665299
#P(X=12)=0.566

#==================================================================================
#4
#==================================================================================
#dados:
#solteiros=62
#casados=149
#divorciados=68
#viucos=65
###########
#<25= 61
#25<x<40=120
#>40=163
#total=344

#==================================================================================
#4-a seja viuva
#==================================================================================
#P(a)=279/344=0,811 ou 81,1%

#==================================================================================
#4-b seja solteira ou tenha mais que 40 anos de idade
#==================================================================================
#P(solteira)=62/344=0,180
#P(>40)=163/344=0,474
#P(solteira OU >40)=0,654 ou 65,4%

#==================================================================================
#4-c seja divorciada, dado que tenha entre 25 e 40 anos de idade
#==================================================================================
#P(divorciada entre 25 e 40)= 23/120=0,192 ou 19,2%

#==================================================================================
#5-a
#==================================================================================
#X~N(1980,22)
#P(X>2000)
pnorm(c(2000), mean=1980, sd=22, lower.tail=FALSE)
#P(X>2000)=0.1816511
#P(X>2000)=0.182 ou 18,2%

#==================================================================================
#5-b
#==================================================================================
#X~N(1980,22)
#P(1930=<X<=1990)=P(X>= 1930)- P(X>=1990)= 0.9884787-0.3247181=0.664ou 66,4%

pnorm(c(1930), mean=1980, sd=22, lower.tail=FALSE)
pnorm(c(1990), mean=1980, sd=22, lower.tail=FALSE)

#==================================================================================
#5-c
#==================================================================================
#X~N(1980,22)
qnorm(c(0.05), mean=1980, sd=22, lower.tail=TRUE)
#Aproximadamente, 1943,813 ml deixa 5% dos refrigerante abaixo dele

