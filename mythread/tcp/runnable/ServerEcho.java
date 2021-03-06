package mythread.tcp.runnable;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


	public class ServerEcho {

	    public static void main(String[] args) {
	    	
	        new ServerEcho().startServer();
	    }

	    public void startServer() {
	        final ExecutorService clientProcessingPool = Executors.newFixedThreadPool(10);
	        
	        Runnable serverTask = new Runnable() {
	            @Override
	            public void run() {
	                try {
	                    ServerSocket serverSocket = new ServerSocket(6789);
	                    System.out.println("Waiting for clients to connect...");
	                    while (true) {
	                        Socket clientSocket = serverSocket.accept();
	                        clientProcessingPool.submit(new ClientTask(clientSocket));
	                    }
	                } catch (IOException e) {
	                    System.err.println("Unable to process client request");
	                    e.printStackTrace();
	                }
	            }
	        };
	        Thread serverThread = new Thread(serverTask);
	        serverThread.start();

	    }

	    private class ClientTask implements Runnable {
	        private final Socket clientSocket;
	        String clientSentence;
	        String capitalizedSentence;
	        private ClientTask(Socket clientSocket) {
	            this.clientSocket = clientSocket;
	        }

	        @Override
	        public void run() {
	            try {
	            	System.out.println("Got a client !!!");
	                DataOutputStream outToClient = new DataOutputStream(clientSocket.getOutputStream());
	                BufferedReader inFromClient =
	                        new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
	                clientSentence = inFromClient.readLine();
	                System.out.println("Received: " + clientSentence);
	                capitalizedSentence = clientSentence.toUpperCase() + '\n';
	                outToClient.writeBytes(capitalizedSentence);
	                clientSocket.close();
	            } catch (IOException e) {
	                e.printStackTrace();
	            }
	        }
	    }

	}



