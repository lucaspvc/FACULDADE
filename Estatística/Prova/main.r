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

# Leitura dos dados no formato xlsx utilizando a biblioteca (readxl)
Dataset <- read_excel("Estatística/Prova/dados1.xlsx")

tempo <- Dataset$Tempo
tempo

TamanhoPop <- length(tempo)
TamanhoPop

amostra <- sample(tempo, TamanhoPop)
amostra

mediacs <- mean(tempo)
mediacs

sum(amostra)
sum(tempo)


mediana <- median(tempo)
mediana

sd(tempo)

Boxplot( ~ Tempo, data=Dataset, id=list(method="y"), main="Lucas Alves")

dados <- Dataset$Tempo

# Tabela corrigida com o numero de casas decimais
tabela <- function(dados, cd) {
  A <- max(dados) - min(dados)
  n <- length(dados)
  if (n <= 100) {
    k <- ceiling(sqrt(n))
  } else {
    k <- ceiling(5 * log10(n))
  }
  C <- round(A / (k - 1), cd)
  LI <- c(rep(0, (k + 1)))
  media <- c(NA)
  LI[1] <- round(min(dados) - (C) / 2, cd)
  for (i in 2:(k + 1)) {
    LI[i] <- round(LI[i - 1] + C, cd)
    media[i - 1] <- mean(c(LI[i], LI[i - 1]))
  }
  limites <- LI
  TDF <- hist(dados, breaks = limites, plot = FALSE, right = FALSE)
  tabela <- matrix(c(rep(6 * k)), k, 6)

  for (i in 1:k) {
    tabela[i, 1] <- round(LI[i], cd)
    tabela[i, 2] <- round(LI[i + 1], cd)
    tabela[i, 3] <- round(media[i], cd)
    tabela[i, 4] <- (TDF$counts[i])
    tabela[i, 5] <- round(((TDF$counts[i]) / n), 4)
    tabela[i, 6] <- round((100 * TDF$counts[i]) / n, 2)
  }

  colnames(tabela) <- c("LI", "LS", "X", "Fa", "Fr", "Fp")
  return(tabela)
}

tabela(dados, 1)
 
# Histograma
quebras <- function(dados, cd) {
  A <- max(dados) - min(dados)
  n <- length(dados)
  if (n <= 100) {
    k <- ceiling(sqrt(n))
  } else {
    k <- ceiling(5 * log10(n))
  }
  C <- round(A / (k - 1), cd)

  LI <- c(rep(0, (k + 1)))
  LI[1] <- round(min(dados) - (C) / 2, cd)
  for (i in 2:(k + 1)) {
    LI[i] <- round(LI[i - 1] + C, cd)
  }

  return(LI)
}

limites <- quebras(dados, 3)
limites

# Construindo as informa��es Tabela de Distribui��o de Frequ�ncias

TDF <- hist(dados, breaks = limites, plot = FALSE, right = FALSE)
TDF

hist(
  dados,
  label = FALSE, main = "Lucas Alves",
  xlab = expression(paste("Tempo (Min)")),
  ylab = "Frequencia absoluta",
  ylim = c(0, (max(TDF$counts) + 1)),
  breaks = limites, axes = FALSE, right = FALSE
)
axis(1, at = limites, pos = c(0, 0))
axis(2, at = c(seq(0:(max(TDF$counts) + 1)) - 1))