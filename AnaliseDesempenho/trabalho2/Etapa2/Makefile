# Nome dos arquivos
TARGET = trab2
TARGET2 = ./Gnuplot/scriptOcupacao.gp
TARGET3 = ./Gnuplot/scriptEn.gp
TARGET4 = ./Gnuplot/scriptEw.gp
TARGET5 = ./Gnuplot/scriptLambda.gp
TARGET6 = ./Gnuplot/scriptLittle.gp


# Parâmetros fixos
PARAMS1 = 100 100000 0.60 0.80 0.95 0.99

# Regra padrão para compilar e rodar o programa duas vezes
all: compile run_all

# Regra para compilar o programa com linkagem da biblioteca matemática
compile:
	gcc $(TARGET).c -o $(TARGET) -lm


run1:
	./$(TARGET) $(PARAMS1)

# Regra para rodar o gnuplot com os dados colhidos anterioremente
run2:
	gnuplot $(TARGET2)
	gnuplot $(TARGET3)
	gnuplot $(TARGET4)
	gnuplot $(TARGET5)
	gnuplot $(TARGET6)

# Regra para rodar o programa com ambos os parâmetros
run_all: run1 
#run2

# Limpa os arquivos compilados
clean:
	rm -f $(TARGET)
