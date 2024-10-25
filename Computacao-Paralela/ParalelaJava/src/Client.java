import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

public class Client {
    public static void main(String[] args) {

        try {
            Ola stub = (Ola) Naming.lookup("rmi://localhost:12345/Ola");
            System.out.println(stub.digaOla());
        } catch (RemoteException | MalformedURLException | NotBoundException e) {
            e.printStackTrace();
        }
    }
}
