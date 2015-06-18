package mythread.threadpooled.runnable;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;

public class WorkerRunnable implements Runnable {

	protected Socket clientSocket = null;
	protected String serverText = null;
	String clientSentence;

	public WorkerRunnable(Socket clientSocket, String serverText) {
		this.clientSocket = clientSocket;
		this.serverText = serverText;
	}

	public void run() {
		try {
			InputStream input = clientSocket.getInputStream();
			OutputStream output = clientSocket.getOutputStream();
			BufferedReader inFromClient =
	                new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
			long time = System.currentTimeMillis();
			
			clientSentence = inFromClient.readLine();
	        System.out.println("FROM CLIENT: " + clientSentence);
	        
			output.write(("HTTP/1.1 200 OK\n\nWorkerRunnable: "
					+ this.serverText + " - " + time + "").getBytes());
			output.close();
			input.close();
			System.out.println("Request processed time: " + time);
		} catch (IOException e) {
			// report exception somewhere.
			e.printStackTrace();
		}
	}
}
