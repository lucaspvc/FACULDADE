//Lucas Pessoa Oliveira Alves 2022.1.08.044

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {

    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 12345);
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             Scanner scanner = new Scanner(System.in)) {

            boolean continuar = true;

            while (continuar) {
                System.out.println("Escolha uma operação:");
                System.out.println("1 - Adicionar Produto");
                System.out.println("2 - Listar Produtos");
                System.out.println("3 - Remover Produto");
                System.out.println("4 - Filtrar Produtos por Preço");
                System.out.println("5 - Sair");

                int opcao = scanner.nextInt();
                scanner.nextLine();  // Consumir a quebra de linha

                String comando = "";

                switch (opcao) {
                    case 1:
                        System.out.print("Nome do produto: ");
                        String nome = scanner.nextLine();
                        System.out.print("Preço do produto: ");
                        double preco = scanner.nextDouble();
                        comando = "adicionar;" + nome + ";" + preco;
                        break;
                    case 2:
                        comando = "listar";
                        break;
                    case 3:
                        System.out.print("Nome do produto a remover: ");
                        String nomeRemover = scanner.nextLine();
                        comando = "remover;" + nomeRemover;
                        break;
                    case 4:
                        System.out.print("Preço mínimo: ");
                        double minPreco = scanner.nextDouble();
                        System.out.print("Preço máximo: ");
                        double maxPreco = scanner.nextDouble();
                        comando = "filtrar;" + minPreco + ";" + maxPreco;
                        break;
                    case 5:
                        continuar = false;
                        continue;
                    default:
                        System.out.println("Opção inválida.");
                        continue;
                }

                out.println(comando); // Envia o comando para o servidor
                String resposta = in.readLine(); // Recebe a resposta do servidor
                System.out.println("Resposta do servidor:\n" + resposta);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
