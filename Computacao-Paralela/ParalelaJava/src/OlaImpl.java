import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class OlaImpl extends UnicastRemoteObject implements Ola {

    protected OlaImpl() throws RemoteException {
        super();
    }

    private static final long serialVersionUID = 1L;

    public String digaOla() throws RemoteException {
        return "Ola, mundo!";
    }

}
