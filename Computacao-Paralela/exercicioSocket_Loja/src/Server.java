//Lucas Pessoa Oliveira Alves 2022.1.08.044

import java.io.*;
import java.net.*;
import java.util.List;

public class Server {

    public static void main(String[] args) {
        Estoque estoque = new EstoqueImpl(); // Usando a implementação

        try (ServerSocket serverSocket = new ServerSocket(12345)) {
            System.out.println("Servidor de estoque iniciado...");

            while (true) {
                Socket clientSocket = serverSocket.accept();
                String clientAddress = clientSocket.getInetAddress().getHostAddress();
                System.out.println("Conexão estabelecida com o cliente: " + clientAddress);

                try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                     PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)) {

                    String comando;
                    while ((comando = in.readLine()) != null) {
                        System.out.println("Comando recebido do cliente: " + comando);
                        String resposta = processarComando(comando, estoque);
                        out.println(resposta);
                        System.out.println("Resposta enviada ao cliente: " + resposta);
                    }

                } catch (IOException e) {
                    e.printStackTrace();
                } finally {
                    System.out.println("Cliente " + clientAddress + " desconectado.");
                    clientSocket.close();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String processarComando(String comando, Estoque estoque) {
        String[] partes = comando.split(";");
        String operacao = partes[0];

        switch (operacao) {
            case "adicionar":
                String nome = partes[1];
                double preco = Double.parseDouble(partes[2]);
                estoque.adicionarProduto(nome, preco);
                return "Produto " + nome + " adicionado com sucesso!";
            case "listar":
                List<String> produtos = estoque.listarProdutos();
                return String.join("\n", produtos);
            case "remover":
                String nomeRemover = partes[1];
                return estoque.removerProduto(nomeRemover);
            case "filtrar":
                double minPreco = Double.parseDouble(partes[1]);
                double maxPreco = Double.parseDouble(partes[2]);
                List<String> produtosFiltrados = estoque.filtrarPorPreco(minPreco, maxPreco);
                return String.join("\n", produtosFiltrados);
            default:
                return "Operação inválida!";
        }
    }
}
