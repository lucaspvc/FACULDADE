# Ajustar o tamanho das fontes e a cor dos marcadores na legenda
set style line 1 lc rgb '#0000cc' lt 1.5 lw 1.5
set style line 2 lc rgb '#00ff00' lt 1.5 lw 1.5
set style line 3 lc rgb '#ff0000' lt 1.5 lw 1.5
set style line 4 lc rgb '#ff00ff' lt 1.5 lw 1.5 

# Definir o título do gráfico e os rótulos dos eixos com tamanho de fonte ajustado
set title "{/:Bold Ocupação x Tempo}" font ",20"
set xlabel "Tempo (s)" font ",14"
set ylabel "Ocupação (%)" font ",14"

# Definir o estilo da legenda com fonte e quadrados
set key right inside bottom font ",12" box

# Definir o estilo do gráfico com tics ajustados
set ytics 2
set mytics 2

# Gerar o gráfico em SVG
set terminal svg size 1000,700
set output './Graficos/ocupacao_tempo.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/Coleta85.txt" using 1:2 with lines linestyle 1 title "Ocupação a 85%", \
     "./Dados/Coleta90.txt" using 1:2 with lines linestyle 2 title "Ocupação a 90%", \
     "./Dados/Coleta95.txt" using 1:2 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/Coleta99.txt" using 1:2 with lines linestyle 4 title "Ocupação a 99%"

unset output

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

# Definir o estilo da legenda com fonte e quadrados
set key left inside top font ",12" box

# Definir o estilo do gráfico com tics ajustados
set tics font "Arial,10"
set ytics 10
set mytics 2

# Gerar o gráfico em SVG
set terminal svg size 1000,700
set output './Graficos/eN_tempo.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/Coleta85.txt" using 1:3 with lines linestyle 1 title "Ocupação a 85%", \
     "./Dados/Coleta90.txt" using 1:3 with lines linestyle 2 title "Ocupação a 90%", \
     "./Dados/Coleta95.txt" using 1:3 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/Coleta99.txt" using 1:3 with lines linestyle 4 title "Ocupação a 99%"

unset output

#########################################################################################################

# Ajustar o tamanho das fontes e a cor dos marcadores na legenda
set style line 1 lc rgb '#0000cc' lt 1.5 lw 1.5
set style line 2 lc rgb '#00ff00' lt 1.5 lw 1.5
set style line 3 lc rgb '#ff0000' lt 1.5 lw 1.5
set style line 4 lc rgb '#ff00ff' lt 1.5 lw 1.5 

# Definir o título do gráfico e os rótulos dos eixos com tamanho de fonte ajustado
set title "{/:Bold E[w] x Tempo}" font ",20"
set xlabel "Tempo (s)" font ",14"
set ylabel "E[w]" font ",14"

# Definir o estilo da legenda com fonte e quadrados
set key left inside top font ",12" box

# Definir o estilo do gráfico com tics ajustados
set tics font "Arial,10"
set ytics 10
set mytics 2

# Gerar o gráfico em SVG
set terminal svg size 1000,700
set output './Graficos/eW_tempo.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/Coleta85.txt" using 1:4 with lines linestyle 1 title "Ocupação a 85%", \
     "./Dados/Coleta90.txt" using 1:4 with lines linestyle 2 title "Ocupação a 90%", \
     "./Dados/Coleta95.txt" using 1:4 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/Coleta99.txt" using 1:4 with lines linestyle 4 title "Ocupação a 99%"

unset output

#########################################################################################################

# Ajustar o tamanho das fontes e a cor dos marcadores na legenda
set style line 1 lc rgb '#0000cc' lt 1.5 lw 1.5
set style line 2 lc rgb '#00ff00' lt 1.5 lw 1.5
set style line 3 lc rgb '#ff0000' lt 1.5 lw 1.5
set style line 4 lc rgb '#ff00ff' lt 1.5 lw 1.5 

# Definir o título do gráfico e os rótulos dos eixos com tamanho de fonte ajustado
set title "{/:Bold Lambda x Tempo}" font ",20"
set xlabel "Tempo (s)" font ",14"
set ylabel "Lambda" font ",14"

# Definir o estilo da legenda com fonte e quadrados
set key right inside bottom font ",12" box

# Definir o estilo do gráfico com tics ajustados
set tics font "Arial,10"
set ytics 0.1
set mytics 2

set yrange [0.4:1.05]

set arrow from graph 0, first 1 to graph 1, first 1 nohead dashtype 2 linewidth 1.5 linecolor rgb "black"


# Gerar o gráfico em SVG
set terminal svg size 1000,700
set output './Graficos/lambda_tempo.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/Coleta85.txt" using 1:5 with lines linestyle 1 title "Ocupação a 85%", \
     "./Dados/Coleta90.txt" using 1:5 with lines linestyle 2 title "Ocupação a 90%", \
     "./Dados/Coleta95.txt" using 1:5 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/Coleta99.txt" using 1:5 with lines linestyle 4 title "Ocupação a 99%"

unset output

#########################################################################################################

# Ajustar o tamanho das fontes e a cor dos marcadores na legenda
set style line 1 lc rgb '#0000cc' lt 1.5 lw 1.5
set style line 2 lc rgb '#00ff00' lt 1.5 lw 1.5
set style line 3 lc rgb '#ff0000' lt 1.5 lw 1.5
set style line 4 lc rgb '#ff00ff' lt 1.5 lw 1.5 

# Definir o título do gráfico e os rótulos dos eixos com tamanho de fonte ajustado
set title "{/:Bold Erro de Little x Tempo}" font ",20"
set xlabel "Tempo (s)" font ",14"
set ylabel "Little" font ",14"

# Definir o estilo da legenda com fonte e quadrados
set key right inside bottom font ",12" box

# Definir o estilo do gráfico com tics ajustados
set tics font "Arial,10"

set yrange [-1e-16:1e-16] 

# Gerar o gráfico em SVG
set terminal svg size 1000,700
set output './Graficos/little_tempo.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/Coleta85.txt" using 1:6 with lines linestyle 1 title "Ocupação a 85%", \
     "./Dados/Coleta90.txt" using 1:6 with lines linestyle 2 title "Ocupação a 90%", \
     "./Dados/Coleta95.txt" using 1:6 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/Coleta99.txt" using 1:6 with lines linestyle 4 title "Ocupação a 99%"

unset output