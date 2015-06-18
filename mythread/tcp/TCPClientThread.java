package mythread.tcp;

import java.io.*;
import java.net.*;
import java.util.Scanner;

class TCPClientThread
{
 public static void main(String argv[]) throws Exception
 {
  String sentence;
  String modifiedSentence;
  int port;
  while (true){
  Scanner in = new Scanner(System.in);
  System.out.println("Enter your port either 1234 or 6789");
  port = in.nextInt();
//  System.out.println(port);
  
  BufferedReader inFromUser = new BufferedReader( new InputStreamReader(System.in));
  Socket clientSocket = new Socket("localhost", port); //Socket(client) host and port
  DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
  BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
  System.out.println("Enter data to the server");
  
  sentence = inFromUser.readLine();
  outToServer.writeBytes(sentence + '\n');
  modifiedSentence = inFromServer.readLine();
  System.out.println("FROM SERVER: " + modifiedSentence);
  clientSocket.close();
  }
 }
}
