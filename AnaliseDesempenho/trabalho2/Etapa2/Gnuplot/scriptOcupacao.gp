# Ajustar o tamanho das fontes e a cor dos marcadores na legenda
set style line 1 lc rgb '#0000cc' lt 1.5 lw 1.5
set style line 2 lc rgb '#00ff00' lt 1.5 lw 1.5
set style line 3 lc rgb '#ff0000' lt 1.5 lw 1.5
set style line 4 lc rgb '#ff00ff' lt 1.5 lw 1.5 

# Definir o título do gráfico e os rótulos dos eixos com tamanho de fonte ajustado
set title "{/:Bold Ocupação x Tempo}" font ",20"
set xlabel "Tempo (s)" font ",14"
set ylabel "Ocupação (%)" font ",14"

# Definindo o estilo da linha 5 como pontilhada
set style line 5 dashtype 8 linecolor rgb "black" linewidth 1 # linha pontilhada 

# Definir o estilo da legenda com fonte e quadrados
set key at graph 0.99, graph 0.3 font ",19" box linestyle 5

# Definir o estilo do gráfico com tics ajustados
set ytics 2
set mytics 2

set arrow from graph 0, first 60 to graph 1, first 60 nohead dashtype 2 linewidth 1.5 linecolor rgb "black"
set arrow from graph 0, first 80 to graph 1, first 80 nohead dashtype 2 linewidth 1.5 linecolor rgb "black"
set arrow from graph 0, first 95 to graph 1, first 95 nohead dashtype 2 linewidth 1.5 linecolor rgb "black"
set arrow from graph 0, first 99 to graph 1, first 99 nohead dashtype 2 linewidth 1.5 linecolor rgb "black"

# Gerar o gráfico em SVG
set terminal svg size 1000,800
set output './Graficos/ocupacao_tempo_web.svg'

# Plotar os arquivos com quadrados na legenda
plot "./Dados/ColetaWeb60.txt" using 1:2 with lines linestyle 1 title "Ocupação a 60%", \
     "./Dados/ColetaWeb80.txt" using 1:2 with lines linestyle 2 title "Ocupação a 80%", \
     "./Dados/ColetaWeb95.txt" using 1:2 with lines linestyle 3 title "Ocupação a 95%", \
     "./Dados/ColetaWeb99.txt" using 1:2 with lines linestyle 4 title "Ocupação a 99%"

unset output