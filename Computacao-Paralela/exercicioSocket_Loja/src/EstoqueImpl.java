//Lucas Pessoa Oliveira Alves 2022.1.08.044

import java.util.ArrayList;
import java.util.List;

public class EstoqueImpl implements Estoque {

    private List<Produto> produtos;

    public EstoqueImpl() {
        this.produtos = new ArrayList<>();
    }

    @Override
    public void adicionarProduto(String nome, double preco) {
        produtos.add(new Produto(nome, preco));
        System.out.println("Produto adicionado: " + nome + " - Preço: " + preco);
    }

    @Override
    public List<String> listarProdutos() {
        List<String> lista = new ArrayList<>();
        for (Produto p : produtos) {
            lista.add(p.getNome() + " - R$" + p.getPreco());
        }
        return lista.isEmpty() ? List.of("Nenhum produto no estoque.") : lista;
    }

    @Override
    public String removerProduto(String nome) {
        for (Produto p : produtos) {
            if (p.getNome().equalsIgnoreCase(nome)) {
                produtos.remove(p);
                System.out.println("Produto removido: " + nome);
                return "Produto " + nome + " removido com sucesso.";
            }
        }
        return "Produto " + nome + " não encontrado.";
    }

    @Override
    public List<String> filtrarPorPreco(double minPreco, double maxPreco) {
        List<String> filtrados = new ArrayList<>();
        for (Produto p : produtos) {
            if (p.getPreco() >= minPreco && p.getPreco() <= maxPreco) {
                filtrados.add(p.getNome() + " - R$" + p.getPreco());
            }
        }
        return filtrados.isEmpty() ? List.of("Nenhum produto encontrado no intervalo de preço.") : filtrados;
    }

    // Classe auxiliar Produto
    private static class Produto {
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
