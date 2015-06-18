package mythread.tcp;

//https://systembash.com/a-simple-java-tcp-server-and-tcp-client/

import java.io.*;
import java.net.*;

class Runner implements Runnable{
	 String clientSentence;
     String capitalizedSentence;
     int port;
     protected boolean      isStopped    = false;
	public void run() {
		try {
			ServerSocket welcomeSocket = new ServerSocket(port);
			
			System.out.println("Thread is waiting for clients to connect port: " + port + " ...");
			while(!isStopped())
		       {
				 System.out.println("Wait for client on port " + welcomeSocket.getLocalPort() + " InetAddress " + welcomeSocket.getInetAddress()+ " Channel " + welcomeSocket.getChannel());
		          Socket connectionSocket = welcomeSocket.accept();
		          BufferedReader inFromClient =
		             new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
		          DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
		          clientSentence = inFromClient.readLine();
		          System.out.println("Received: " + clientSentence + " on thread port " + port);
		          capitalizedSentence = clientSentence.toUpperCase() + '\n';
		          outToClient.writeBytes(capitalizedSentence);
		       }
			 welcomeSocket.close();
			 System.out.println("socket closed");
			 
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Server Stopped.") ;
		
	}
	public Runner (int port){
		this.port = port;
	}
	
	 private boolean isStopped() {
		    System.out.println(this.isStopped);
	        return this.isStopped;
	    }
	public void stopThread(){
		this.isStopped = true;
		System.out.println("Thread stop...");
		
     
     }

}
class TCPServerThread
{
 public static void main(String argv[]) throws Exception
    {
	 
      final Runner runner = new Runner(6789);  //Start thread with port 6789
      final Runner runner1 = new Runner(1234);
       Thread t1 = new Thread(runner);
       Thread t2 = new Thread(runner1);
       t1.start();
       t2.start();
       
//       t1.sleep(10000);
//       t2.sleep(1000);
//       runner.stopThread();
//       runner1.stopThread();
      
 
       new Thread (new Runnable() {
		
		@Override
		public void run() {
			// TODO Auto-generated method stub
			try {
				
				Thread.sleep(1000);
				System.out.println("Thread 3 running...");
				runner.stopThread();
				runner1.stopThread();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}).start();
      
    }
}
