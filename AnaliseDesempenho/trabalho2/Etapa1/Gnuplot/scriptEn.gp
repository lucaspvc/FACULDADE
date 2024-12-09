#########################################################################################################
# Ajustar o tamanho das fontes e a cor dos marcadores na legenda
set style line 1 lc rgb '#0000cc' lt 1.5 lw 1.5
set style line 2 lc rgb '#00ff00' lt 1.5 lw 1.5
set style line 3 lc rgb '#ff0000' lt 1.5 lw 1.5
set style line 4 lc rgb '#ff00ff' lt 1.5 lw 1.5 

# Definir o título do gráfico e os rótulos dos eixos com tamanho de fonte ajustado
set title "{/:Bold E[n] x Tempo}" font ",20"
set xlabel "Tempo (s)" font ",14"
set ylabel "E[n]" font ",14"

# Definindo o estilo da linha 5 como pontilhada
set style line 5 dashtype 8 linecolor rgb "black" linewidth 1 # linha pontilhada 

# Definir o estilo da legenda com fonte e quadrados
set key left inside top font ",19" box linestyle 5

# Definir o estilo do gráfico com tics ajustados
set tics font "Arial,10"
set ytics 10
set mytics 2

# Gerar o gráfico em SVG
set terminal svg size 1000,700
set output './Graficos/eN_tempo.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/Coleta60.txt" using 1:3 with lines linestyle 1 title "Ocupação a 60%", \
     "./Dados/Coleta85.txt" using 1:3 with lines linestyle 2 title "Ocupação a 85%", \
     "./Dados/Coleta95.txt" using 1:3 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/Coleta99.txt" using 1:3 with lines linestyle 4 title "Ocupação a 99%"

unset output