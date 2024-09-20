# Nome dos arquivos
TARGET = trab1
TARGET2 = ./Gnuplot/scriptOcupacao.gp
TARGET3 = ./Gnuplot/scriptEn.gp
TARGET4 = ./Gnuplot/scriptEw.gp
TARGET5 = ./Gnuplot/scriptLambda.gp
TARGET6 = ./Gnuplot/scriptLittle.gp


# Parâmetros fixos
PARAMS1 = 1.00 0.85 100000 85
PARAMS2 = 1.00 0.90 100000 90
PARAMS3 = 1.00 0.95 100000 95
PARAMS4 = 1.00 0.99 100000 99


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
