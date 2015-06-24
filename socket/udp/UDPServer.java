//https://systembash.com/a-simple-java-udp-server-and-udp-client/
//ip=localhost port=9876
package socket.udp;

//import java.io.*;
import java.net.*;

class UDPServer
{
   public static void main(String args[]) throws Exception
      {
         DatagramSocket serverSocket = new DatagramSocket(9877);  //9876 is already used
            byte[] receiveData = new byte[1024];				  //port listen on foreign address
            byte[] sendData = new byte[1024];
            while(true)
               {
                  DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                  serverSocket.receive(receivePacket);
                  String sentence = new String( receivePacket.getData());
                  // convert byte to String
                  System.out.println("RECEIVED: " + sentence);
                  InetAddress IPAddress = receivePacket.getAddress();
                  int port = receivePacket.getPort();
                  String capitalizedSentence = sentence.toUpperCase();
                  sendData = capitalizedSentence.getBytes();
                  DatagramPacket sendPacket =
                  new DatagramPacket(sendData, sendData.length, IPAddress, port);
                  serverSocket.send(sendPacket);
                  System.out.println("IPAddress: " + IPAddress +  " Port: " + port); 
                  //print out port of local address, many local ports connect to one foreign i.e port 80
               }
      }
}