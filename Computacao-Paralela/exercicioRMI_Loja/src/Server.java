// Nome: João Paulo Martyr Ragazzo 2022.1.08.009
//Lucas Pessoa Oliveira Alves 2022.1.08.044

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class Server {

    public static void main(String[] args) {

        try {
            EstoqueImpl estoque = new EstoqueImpl();
            LocateRegistry.createRegistry(12345);
            Naming.rebind("rmi://localhost:12345/Estoque", estoque);
            System.out.println("Servidor de estoque pronto...");
        } catch (RemoteException | MalformedURLException e) {
            e.printStackTrace();
        }
    }
}
