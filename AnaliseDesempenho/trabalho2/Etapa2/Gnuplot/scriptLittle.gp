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

# Definindo o estilo da linha 5 como pontilhada
set style line 5 dashtype 8 linecolor rgb "black" linewidth 1 # linha pontilhada 

# Definir o estilo da legenda com fonte e quadrados
set key left inside top font ",19" box linestyle 5

# Definir o estilo do gráfico com tics ajustados
set tics font "Arial,10"

set yrange [-0.0000009:0.0000015] 
set xrange[20000:100000]


set arrow from graph 0, first 0 to graph 1, first 0 nohead dashtype 2 linewidth 1.5 linecolor rgb "black"


# Gerar o gráfico em SVG
set terminal svg size 1000,800
set output './Graficos/little_tempo_web.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/ColetaWeb60.txt" using 1:6 with lines linestyle 1 title "Ocupação a 60%", \
     "./Dados/ColetaWeb80.txt" using 1:6 with lines linestyle 2 title "Ocupação a 80%", \
     "./Dados/ColetaWeb95.txt" using 1:6 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/ColetaWeb99.txt" using 1:6 with lines linestyle 4 title "Ocupação a 99%"

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

# Definindo o estilo da linha 5 como pontilhada
set style line 5 dashtype 8 linecolor rgb "black" linewidth 1 # linha pontilhada 

# Definir o estilo da legenda com fonte e quadrados
set key left inside top font ",19" box linestyle 5

# Definir o estilo do gráfico com tics ajustados
set tics font "Arial,10"

set yrange [-0.000000000010:0.00000000001] 

set arrow from graph 0, first 0 to graph 1, first 0 nohead dashtype 2 linewidth 1.5 linecolor rgb "black"


# Gerar o gráfico em SVG
set terminal svg size 1000,800
set output './Graficos/little_tempo_chamadas.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/ColetaChamadaReal60.txt" using 1:6 with lines linestyle 1 title "Ocupação a 60%", \
     "./Dados/ColetaChamadaReal80.txt" using 1:6 with lines linestyle 2 title "Ocupação a 80%", \
     "./Dados/ColetaChamadaReal95.txt" using 1:6 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/ColetaChamadaReal99.txt" using 1:6 with lines linestyle 4 title "Ocupação a 99%"

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

# Definindo o estilo da linha 5 como pontilhada
set style line 5 dashtype 8 linecolor rgb "black" linewidth 1 # linha pontilhada 

# Definir o estilo da legenda com fonte e quadrados
set key left inside top font ",19" box linestyle 5

# Definir o estilo do gráfico com tics ajustados
set tics font "Arial,10"

set yrange [-0.0000009:0.0000015] 

set arrow from graph 0, first 0 to graph 1, first 0 nohead dashtype 2 linewidth 1.5 linecolor rgb "black"


# Gerar o gráfico em SVG
set terminal svg size 1000,800
set output './Graficos/little_tempo_total.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/ColetaTotal60.txt" using 1:6 with lines linestyle 1 title "Ocupação a 60%", \
     "./Dados/ColetaTotal80.txt" using 1:6 with lines linestyle 2 title "Ocupação a 80%", \
     "./Dados/ColetaTotal95.txt" using 1:6 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/ColetaTotal99.txt" using 1:6 with lines linestyle 4 title "Ocupação a 99%"

unset output
