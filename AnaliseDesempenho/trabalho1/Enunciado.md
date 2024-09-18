```# Trabalho de Análise de Desempenho

Datas de desenvolvimento:
10/09 12/09 17/09 e 19/09

Data de apresentação 
24/09

---

Trabalho de fato: 
-> Simular 4 cenários de ocupação => 85% - 90% - 95% - 99%
-> Especificar os parâmetros de modo a se obter os cenários desejados 
    Tal tempo médio de serviço 
    Tal taxa de chegada 
    Tem que TENDER aos valores EXATOS
    A idéia é calcular matematicamente o valor, e o simulador deve confirmar. Mas deve ser calculado matemáticamente OBRIGATORIAMENTE
        -> A matemática que dirá o valor 85% ~ 99%

No relatório:
-> Os resultados das simulações
-> Dizer a semente utilizada para a execução da simulação **(é necessário fixar a semente)**

---

Tempo de simulação: 100.000 segundos 
Modificação no código necessária:
FLÁVIO: "E se eu dizer assim? A cada 100 segundos de simulação, eu quero que você faça medidas parciais no simulador."
FLÁVIO: "A cada 100 segundos, eu quero saber E(n), E(w), lambda, ocupação, erro de Little
FLÁVIO: "De 0 a 100, é de 0 a 100. Quando chegar no 200, é de 0 a 200. Quando chegar a 300, é de 0 a 300. Sempre o **acumulado** de 0 aos
        múltiplos de 100."
FLÁVIO: "Tudo isso deve ser feito em uma só execução"
OBSERVAÇÃO IMPORTANTE: TEM QUE SER EXATAMENTE EM 100 - 200 - 300 - 400... NÃO PODE SER MINIMAMENTE FORA DE 100 - 200 - 300 - 400... 
                       TEM QUE SER CRAVADO EM 100 - 200 - 300 - 400... 

---

Gráficos a se gerar:
ESPECIFICAÇÃO: Deve-se gráficos de acordo com a cada 100 segundos de simulação 
              (pode gerar 1.000 pontos, mas não é para fazer dessa forma, os gráficos precisam ser amigáveis) 

- Grafíco de ocupação em função do tempo 
Em um único gráfico tem as medidas de ocupação em de 85% ~ 99%. EM UM ÚNICO GRÁFICO, TEM QUE TER TODAS AS MEDIDAS DE OCUPAÇÃO

- Gráfico de E(n) em função tempo 
Novamente, um único gráfico para as 4 medidas de ocupação 85% ~ 99%.

- Gráfico de E(w) em função do tempo
Novamente, a mesma especificação

- Gráfico de lambda em função do tempo
Novamente, a mesma especificação

- Gráfico do erro de Little em função do tempo
Novamente, a mesma especificação

SOMENTE OS 5 GRÁFICOS NOS INTERESSA - PODEM SER FEITAS EM QUALQUER FERRAMENTA - A IMAGEM TEM QUE SER VETORIAL 
(deve-se possível dar quanto zoom quiser)
SUGESTÃO DE FERRAMENTA PARA FAZER GRÁFICO: gnuplot 
DEFINIÇÃO DE GRÁFICO BEM FEITO:
-> Não tem porque escrever 100 - 200 - 300 ... 100.000 porque vai poluir o gráfico, pode ser de 1000 - 2000... ou 10.000, 20.000
-> 


+0.5 PONTO NA MÉDIA: "A gente consegue calcular préviamente a ocupação?" - "Sim" - 
    "A gente consegue calcular préviamente as demais medidas?"
    "Consigo calcular analiticamente as demais medidas na mão, sem precisar simular?"
        RESPOSTA: SIM/NÃO e JUSTIFIQUE
```