# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -std=c++11

# Nome do programa
TARGET = programa

# Arquivos fonte
SRCS = buscaLocal.c++


# Regra padrão
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regra para executar o programa com os parâmetros fornecidos
run: $(TARGET)
	.\$(TARGET) 100 2000 1 2 3 4 5 6 7 8 9 10 11

# Limpeza dos arquivos gerados
clean:
	rm -f $(TARGET)
