# Nome dos arquivos
TARGET = trab2
TARGET2 = ./Gnuplot/scriptOcupacao.gp
TARGET3 = ./Gnuplot/scriptEn.gp
TARGET4 = ./Gnuplot/scriptEw.gp
TARGET5 = ./Gnuplot/scriptLambda.gp
TARGET6 = ./Gnuplot/scriptLittle.gp

# Parâmetros fixos
PARAMS1 = 100 100000 60 60
PARAMS2 = 100 100000 80 80
PARAMS3 = 100 100000 95 95
PARAMS4 = 100 100000 99 99

# Regra padrão para compilar e rodar o programa duas vezes
all: compile run_all

# Regra para compilar o programa com linkagem da biblioteca matemática
compile:
	gcc $(TARGET).c -o $(TARGET) -lm

# Regra para rodar o programa com os primeiros parâmetros
run1:
	./$(TARGET) $(PARAMS1)

# Regra para rodar o programa com os segundos parâmetros
run2:
	./$(TARGET) $(PARAMS2)

# Regra para rodar o programa com os terceiros parâmetros
run3:
	./$(TARGET) $(PARAMS3)

# Regra para rodar o programa com os quartos parâmetros
run4:
	./$(TARGET) $(PARAMS4)	

# Regra para rodar o gnuplot com os dados colhidos anterioremente
run5:
	gnuplot $(TARGET2)
	gnuplot $(TARGET3)
	gnuplot $(TARGET4)
	gnuplot $(TARGET5)
	gnuplot $(TARGET6)

# Regra para rodar o programa com ambos os parâmetros
run_all: run1 run2 run3 run4 run5

# Limpa os arquivos compilados
clean:
	rm -f $(TARGET)
	rm -rf ./Dados
	rm -rf ./DadosFinais