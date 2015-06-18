//http://tutorials.jenkov.com/java-multithreaded-servers/multithreaded-server.html
package mythread.tcp.multithreaded.runnable;

import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;

import mythread.tcp.runnable.SingleThreadedServer;

class MultiThreadedServer implements Runnable{

    protected int          serverPort   = 6789;
    protected ServerSocket serverSocket = null;
    protected boolean      isStopped    = false;
    protected Thread       runningThread= null;

    public MultiThreadedServer(int port){
        this.serverPort = port;
    }

    public void run(){
        synchronized(this){
            this.runningThread = Thread.currentThread();
        }
        openServerSocket();   //call function openserverSocket
        while(! isStopped()){
            Socket clientSocket = null;
            try {
                clientSocket = this.serverSocket.accept();
            } catch (IOException e) {
                if(isStopped()) {
                    System.out.println("Server Stopped.") ;
                    return;
                }
                throw new RuntimeException(
                    "Error accepting client connection", e);
            }
            new Thread(
                new WorkerRunnable(
                    clientSocket, "Multithreaded Server")
            ).start();
        }
        System.out.println("Server Stopped.") ;
    }


    private synchronized boolean isStopped() {
        return this.isStopped;
    }

    public synchronized void stop(){
        this.isStopped = true;
        try {
            this.serverSocket.close();
        } catch (IOException e) {
            throw new RuntimeException("Error closing server", e);
        }
    }

    private void openServerSocket() {
        try {
            this.serverSocket = new ServerSocket(this.serverPort);
        } catch (IOException e) {
            throw new RuntimeException("Cannot open port 6789", e);
        }
    }

}
public class AppMultiThreadedServer {
	public static void main(String args[]){
//		SingleThreadedServer server = new SingleThreadedServer(6789);
		MultiThreadedServer server = new MultiThreadedServer(6789);
		new Thread(server).start();

		try {
		    Thread.sleep(10 * 10000);
		} catch (InterruptedException e) {
		    e.printStackTrace();  
		}
		System.out.println("Stopping Server");
		server.stop();
	}
}
