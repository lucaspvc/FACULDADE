// Nome: João Paulo Martyr Ragazzo 2022.1.08.009
//Lucas Pessoa Oliveira Alves 2022.1.08.044

import java.rmi.Naming;
import java.util.List;
import java.util.Scanner;

public class Client {

    public static void main(String[] args) {
        try {
            Estoque estoque = (Estoque) Naming.lookup("rmi://localhost:12345/Estoque");

            Scanner scanner = new Scanner(System.in);
            boolean continuar = true;

            while (continuar) {
                System.out.println("Escolha uma operação:");
                System.out.println("1 - Adicionar Produto");
                System.out.println("2 - Listar Produtos");
                System.out.println("3 - Remover Produto");
                System.out.println("4 - Filtrar Produtos por Preço");
                System.out.println("5 - Sair");

                int opcao = scanner.nextInt();
                scanner.nextLine();

                switch (opcao) {
                    case 1:
                        System.out.print("Nome do produto: ");
                        String nome = scanner.nextLine();
                        System.out.print("Preço do produto: ");
                        double preco = scanner.nextDouble();
                        estoque.adicionarProduto(nome, preco);
                        break;
                    case 2:
                        List<String> produtos = estoque.listarProdutos();
                        System.out.println("Produtos no estoque:");
                        for (String produto : produtos) {
                            System.out.println(produto);
                        }
                        break;
                    case 3:
                        System.out.print("Nome do produto a remover: ");
                        String nomeRemover = scanner.nextLine();
                        estoque.removerProduto(nomeRemover);
                        break;
                    case 4:
                        System.out.print("Preço mínimo: ");
                        double minPreco = scanner.nextDouble();
                        System.out.print("Preço máximo: ");
                        double maxPreco = scanner.nextDouble();
                        List<String> produtosFiltrados = estoque.filtrarPorPreco(minPreco, maxPreco);
                        System.out.println("Produtos filtrados:");
                        for (String produto : produtosFiltrados) {
                            System.out.println(produto);
                        }
                        break;
                    case 5:
                        continuar = false;
                        break;
                    default:
                        System.out.println("Opção inválida.");
                }
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}