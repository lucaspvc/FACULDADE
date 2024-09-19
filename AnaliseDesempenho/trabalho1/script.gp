# Script para plotar ocupação vs tempo de múltiplos arquivos

# Definir o título do gráfico e os rótulos dos eixos
set title "Ocupação x Tempo"
set xlabel "Tempo (Coleta)"
set ylabel "Ocupação (%)"

# Definir o estilo do gráfico
set grid
set key outside

# Gerar o gráfico em SVG
set terminal svg size 800,600
set output 'ocupacao_tempo.svg'

# Plotar os arquivos
plot "Coleta85.txt" using 1:2 with lines title "Arquivo Coleta 85", \
     "Coleta90.txt" using 1:2 with lines title "Arquivo Coleta 90", \
     "Coleta95.txt" using 1:2 with lines title "Arquivo Coleta 95", \
     "Coleta99.txt" using 1:2 with lines title "Arquivo Coleta 99"

unset output

# Gerar o gráfico em formato para LaTeX
set terminal
set output 'ocupacao_tempo.tex'
replot
unset output
