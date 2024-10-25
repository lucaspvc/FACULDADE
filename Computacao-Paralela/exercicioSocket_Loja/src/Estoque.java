//Lucas Pessoa Oliveira Alves 2022.1.08.044

import java.util.List;

public interface Estoque {

    void adicionarProduto(String nome, double preco);

    List<String> listarProdutos();

    String removerProduto(String nome);

    List<String> filtrarPorPreco(double minPreco, double maxPreco);
}
