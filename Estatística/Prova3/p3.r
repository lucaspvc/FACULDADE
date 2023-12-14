#Questão 1
n=500
ns=360
p0<-1 # Valor a ser testado (assumido) para Pi#
binom.test(ns, n, p = p0,alternative="two.side")

#Questão 2
Dataset <- readXL("/home/2022.1.08.044/FACULDADE/Estatística/Prova3/dados_questao2.xlsx", rownames=FALSE, header=TRUE, na="", 
  sheet="Sheet1", stringsAsFactors=TRUE)
with(Dataset, (t.test(peso.KG., alternative='greater', mu=73, conf.level=.95)))

#Questão 3
n=620
ns=490
p0<-0.90 # Valor a ser testado (assumido) para Pi#

binom.test(ns, n, p = p0,alternative="two.side")

#questaõ 4


Dataset <- readXL("/home/2022.1.08.044/FACULDADE/Estatística/Prova3/dados_questao4.xlsx", rownames=FALSE, header=TRUE, na="", 
  sheet="Sheet1", stringsAsFactors=TRUE)
with(Dataset, (t.test(empresa.A, empresa.B, alternative='two.sided', conf.level=.95, paired=TRUE)))
summary(Dataset)
Dataset <- readXL("/home/2022.1.08.044/FACULDADE/Estatística/Prova3/dados_questao4.xlsx", rownames=FALSE, header=TRUE, na="", 
  sheet="Sheet1", stringsAsFactors=TRUE)
Dataset <- readXL("/home/2022.1.08.044/FACULDADE/Estatística/Prova3/dados_questao4.xlsx", rownames=FALSE, header=TRUE, na="", 
  sheet="Sheet1", stringsAsFactors=TRUE)

Tapply(tempo.min. ~ empresas, var, na.action=na.omit, data=Dataset) # variances by group
var.test(tempo.min. ~ empresas, alternative='two.sided', conf.level=.95, data=Dataset)
t.test(tempo.min.~empresas, alternative='greater', conf.level=.95, var.equal=FALSE, data=Dataset)

#Questão 5

Dataset <- readXL("/home/2022.1.08.044/FACULDADE/Estatística/Prova3/dados_questao5.xlsx", rownames=FALSE, header=TRUE, na="", 
  sheet="Sheet1", stringsAsFactors=TRUE)


summary(Dataset)

with(Dataset, cor.test(Peso.Coporal.g., Peso.do.coração.g., alternative="two.sided", method="pearson"))
library(lattice, pos=18)
scatterplot(Peso.do.coração.g.~Peso.Coporal.g., regLine=FALSE, smooth=FALSE, boxplots=FALSE, data=Dataset)
scatterplot(Peso.do.coração.g.~Peso.Coporal.g., regLine=FALSE, smooth=list(span=0.5, spread=FALSE), boxplots=FALSE, data=Dataset)
RegModel.1 <- lm(Peso.Coporal.g.~Peso.do.coração.g., data=Dataset)
summary(RegModel.1)

