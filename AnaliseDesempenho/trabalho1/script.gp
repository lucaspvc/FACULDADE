# Script para plotar ocupação vs tempo de múltiplos arquivos

set style line 1 lc rgb '#eca318' lt 1 lw 1
set style line 2 lc rgb '#ff00ff' lt 1 lw 1
set style line 3 lc rgb '#ff00ff' lt 1 lw 1
set style line 4 lc rgb '#ff00ff' lt 1 lw 1

# Definir o título do gráfico e os rótulos dos eixos
set title "Ocupação x Tempo"
set xlabel "Tempo (Coleta)"
set ylabel "Ocupação (%)"


# Definir o estilo do gráfico
set key right inside bottom
set ytics 2
set mytics 2


# Gerar o gráfico em SVG
set terminal svg size 800,600
set output 'ocupacao_tempo.svg'

# Plotar os arquivos
plot "Coleta85.txt" using 1:2 with lines linestyle 1 title "Arquivo Coleta 85", \
     "Coleta90.txt" using 1:2 with lines linestyle 2 title "Arquivo Coleta 90", \
     "Coleta95.txt" using 1:2 with lines linestyle 3 title "Arquivo Coleta 95", \
     "Coleta99.txt" using 1:2 with lines linestyle 4 title "Arquivo Coleta 99"

unset output