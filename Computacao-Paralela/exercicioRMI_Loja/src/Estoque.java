// Nome: João Paulo Martyr Ragazzo 2022.1.08.009
//Lucas Pessoa Oliveira Alves 2022.1.08.044

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface Estoque extends Remote {
    void adicionarProduto(String nome, double preco) throws RemoteException;
    List<String> listarProdutos() throws RemoteException;
    void removerProduto(String nome) throws RemoteException;
    List<String> filtrarPorPreco(double minPreco, double maxPreco) throws RemoteException;
}
