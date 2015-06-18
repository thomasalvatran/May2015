package mythread.tcp.runnable;

public class AppSingleThreadedServer {
	public static void main(String args[]){
		SingleThreadedServer server = new SingleThreadedServer(6789);
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
