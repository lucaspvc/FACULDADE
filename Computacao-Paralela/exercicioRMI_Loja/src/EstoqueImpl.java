// Nome: João Paulo Martyr Ragazzo 2022.1.08.009
//Lucas Pessoa Oliveira Alves 2022.1.08.044

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.List;

public class EstoqueImpl extends UnicastRemoteObject implements Estoque {

    private List<Produto> produtos;

    protected EstoqueImpl() throws RemoteException {
        produtos = new ArrayList<>();
    }

    @Override
    public void adicionarProduto(String nome, double preco) throws RemoteException {
        produtos.add(new Produto(nome, preco));
        System.out.println("Produto adicionado: " + nome + " - Preço: " + preco);
    }

    @Override
    public List<String> listarProdutos() throws RemoteException {
        List<String> lista = new ArrayList<>();
        for (Produto p : produtos) {
            lista.add(p.getNome() + " - R$" + p.getPreco());
        }
        return lista;
    }

    @Override
    public void removerProduto(String nome) throws RemoteException {
        produtos.removeIf(p -> p.getNome().equals(nome));
        System.out.println("Produto removido: " + nome);
    }

    @Override
    public List<String> filtrarPorPreco(double minPreco, double maxPreco) throws RemoteException {
        List<String> filtrados = new ArrayList<>();
        for (Produto p : produtos) {
            if (p.getPreco() >= minPreco && p.getPreco() <= maxPreco) {
                filtrados.add(p.getNome() + " - R$" + p.getPreco());
            }
        }
        return filtrados;
    }

    private class Produto {
        private String nome;
        private double preco;

        public Produto(String nome, double preco) {
            this.nome = nome;
            this.preco = preco;
        }

        public String getNome() {
            return nome;
        }

        public double getPreco() {
            return preco;
        }
    }
}
