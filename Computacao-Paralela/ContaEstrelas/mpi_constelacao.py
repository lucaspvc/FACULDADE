"""
Exercício
Encontrar a quantidade de estrelas (grupo de pixels branco) numa imagem celeste (imagem preto). A imagem terá 
formato PGM com valores entre 0 e 255m e deve ser lido pelo processo 0. Para processar em paralelo, a imagem deve ser 
dividido em partes iguais na vertical e na horizontal. As estrelas possuem pixels com valores menores do que
20 em tons de cinza.
Nome: Lucas Pessoa Oliveira Alves   R.A: 2022.1.08.044
"""
from mpi4py import MPI
import cv2
import numpy as np

def contar_estrelas_parte(imagem_parte, limiar=200, margem_exclusao=False):
    """
    Conta o número de estrelas em uma parte da imagem, ignorando estrelas conectadas à margem se 'margem_exclusao' for True.
    """
    _, imagem_binaria = cv2.threshold(imagem_parte, limiar, 255, cv2.THRESH_BINARY)
    num_estrelas, rotulos = cv2.connectedComponents(imagem_binaria)
    
    if margem_exclusao:
        # Verificar e remover as estrelas conectadas à margem superior e esquerda
        labels_to_remove = set()

        # Verificar primeira linha (margem superior)
        for x in range(imagem_binaria.shape[1]):
            if rotulos[0, x] > 0:
                labels_to_remove.add(rotulos[0, x])

        # Verificar primeira coluna (margem esquerda)
        for y in range(imagem_binaria.shape[0]):
            if rotulos[y, 0] > 0:
                labels_to_remove.add(rotulos[y, 0])

        # Subtrair as estrelas conectadas às margens
        num_estrelas -= len(labels_to_remove)

    return num_estrelas - 1  # Subtrair 1 para o fundo

def dividir_imagem(imagem, num_processos):
    """
    Divide a imagem em partes iguais horizontalmente, adicionando margens de exclusão.
    """
    altura = imagem.shape[0]
    partes = []
    
    for i in range(num_processos):
        if i == 0:
            parte = imagem[:altura // num_processos]
        else:
            # Outros processos pegam uma linha extra acima para verificar a conexão
            parte = imagem[i * (altura // num_processos) - 1 : (i + 1) * (altura // num_processos)]
        
        partes.append(parte)
    
    return partes

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    # Garantir que o número de processos seja par
    if size % 2 != 0:
        if rank == 0:
            print("Erro: o número de processos deve ser par.")
        return

    limiar_branco = 115 
    arquivos_imagens = ['estrelas1.pgm', 'estrelas2.pgm', 'estrelas3.pgm']
    
    for caminho_imagem in arquivos_imagens:
        if rank == 0:
            imagem = cv2.imread(caminho_imagem, cv2.IMREAD_GRAYSCALE)
            if imagem is None:
                raise ValueError(f"Erro ao carregar a imagem: {caminho_imagem}")
            partes_imagem = dividir_imagem(imagem, size)
        else:
            partes_imagem = None
        
        parte_local = comm.scatter(partes_imagem, root=0)
        
        if rank == 0:
            num_estrelas_local = contar_estrelas_parte(parte_local, limiar=limiar_branco)
        else:
            num_estrelas_local = contar_estrelas_parte(parte_local, limiar=limiar_branco, margem_exclusao=True)
        
    
        num_estrelas_totais = comm.gather(num_estrelas_local, root=0)
        
        if rank == 0:
            total_estrelas = sum(num_estrelas_totais)
            print(f"Arquivo: {caminho_imagem} - Número total de estrelas: {total_estrelas}")

if __name__ == "__main__":
    main()

"""
PARA EXECUÇÃO DO PROGRAMA, É NECESSÁRIO INSTALAÇÃO DO MPI4PY E O SEGUINTE COMANDO:
mpiexec --hostfile hostfile -np <número de processos> python mpi_constelacao.py
"""