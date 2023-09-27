# Bibliotecas básicas para utilizar o R no Visual Studio Code
library(datasets)
library(base)
library(graphics)
library(grDevices)
library(methods)
library(stats)
library(utils)
library(readxl)
library(RcmdrMisc)

dataset <-
  read_excel("Estatística/AulaDegraficos/Dados_exemplo_implanta_ESF.xlsx")
summary(dataset)

dados <- dataset$Idade
summary(dados)

##################################################
# Tabela de Distribuição de frequência nas classes TDF
###############################################################

# O conjunto de dados já deve ter sido importado do excel com o nome "dataset"

dados <- dataset$taxa_glicose
dados # armazenando as observações no objeto dados

n <- length(dados)
n # número de observações
k <- sqrt(n) + 0.5
k <- round(k, 0) # número de classes
C <- (max(dados) - min(dados)) / (k - 1)
C <- round(C, 2) # Amplitude de classe duas casas decimais
limites <- round(min(dados) - C / 2, 2) + C * (0:k)
# limites
TDF <- hist(dados, breaks = limites, plot = FALSE, right = FALSE)
tabela <- matrix(c(rep(6 * k)), k, 6)
for (i in 1:k)
{
  tabela[i, 1] <- round(TDF$breaks[i], 2)
  tabela[i, 2] <- round(TDF$breaks[i + 1], 2)
  tabela[i, 3] <- round(TDF$mids[i], 2)
  tabela[i, 4] <- (TDF$counts[i])
  tabela[i, 5] <- round(((TDF$counts[i]) / n), 4)
  tabela[i, 6] <- round((100 * TDF$counts[i]) / n, 2)
}
colnames(tabela) <- c("LI", "LS", "Xi", "Fi", "Fr", "Fp")
tabela

##################################################
# Construindo o HIstograma
#####################################################################

# O conjunto de dados já deve ter sido importado do excel com o nome "dataset"

dados <- dataset$taxa_glicose
dados # armazenando as observações no objeto dados

n <- length(dados)
n # número de observações
k <- sqrt(n) + 0.5
k <- round(k, 0) # número de classes
C <- (max(dados) - min(dados)) / (k - 1)
C <- round(C, 2) # Amplitude de classe duas casas decimais
limites <- round(min(dados) - C / 2, 2) + C * (0:k)
# limites
TDF <- hist(dados, breaks = limites, plot = FALSE, right = FALSE)
hist(dados,
  xlab = "Taxa de glicose (mg/dl)", ylab = "Frequência absoluta",
  label = FALSE, col = "gray", main = "", right = FALSE,
  xlim = c(min(TDF$mids) - C, max(TDF$mids) + C), ylim = c(0, (max(TDF$counts) + 1)), breaks = limites, axes = FALSE
)
axis(1, at = limites, pos = c(0, 0))
axis(2, at = c(seq(0:(max(TDF$counts) + 1)) - 1))
