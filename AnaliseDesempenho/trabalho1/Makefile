# Nome do arquivo sem extensão
TARGET = trab1
# Parâmetros fixos
PARAMS = 0.5 0.495 100000

# Regra padrão para compilar e rodar o programa
all: compile run

# Regra para compilar o programa com linkagem da biblioteca matemática
compile:
	gcc $(TARGET).c -o $(TARGET) -lm

# Regra para rodar o programa com os parâmetros definidos
run:
	./$(TARGET) $(PARAMS)

# Limpa os arquivos compilados
clean:
	rm -f $(TARGET)
