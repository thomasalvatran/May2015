package thread.pipe;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;
import java.util.Random;

/**
 * 
 * @author tv
 */
class NumGen extends Thread {
	DataOutputStream dos;

	NumGen(PipedOutputStream pos) { // ctor
		{
			try {
				dos = new DataOutputStream(pos);
			} catch (Exception e) {
			}
		}

	}

	public void run() {
		try {
			Random ran = new Random();
			double d;
			while (true) {
				d = ran.nextFloat() * 1000;
				dos.writeDouble(d);
				System.out.printf("Write Output Stream random %4.3f \n", d);
				// dos.writeDouble(1);
				Thread.sleep(1000);
				dos.flush();
			}

		} catch (Exception e) {
		}
	}
}

class RunAvg extends Thread {
	DataInputStream dis;

	RunAvg(PipedInputStream pis) {
		dis = new DataInputStream(pis); // ctor
	}

	public void run() {
		while (true) {
			try {
				double x = dis.readDouble();
				System.out.printf("Read input Stream %16.3f \n", x);
			} catch (IOException e) {
				e.printStackTrace();
			}

		}
	}

}

class PipeTest {
	public static void main(String[] args) {
		try {
			PipedOutputStream pos = new PipedOutputStream();
			PipedInputStream pis = new PipedInputStream(pos);
			NumGen ng = new NumGen(pos);
			RunAvg ra = new RunAvg(pis);
			ng.start();
			ra.start();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
