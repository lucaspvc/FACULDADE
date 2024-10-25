import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {

    public static void main(String[] args) throws RemoteException {

        try {

            Registry registry = LocateRegistry.createRegistry(12345);
            Naming.rebind("rmi://localhost:12345/Ola",new OlaImpl());
            System.out.println("Server ready....");

        }catch (RemoteException | MalformedURLException e){
            e.printStackTrace();
        }
    }

}
