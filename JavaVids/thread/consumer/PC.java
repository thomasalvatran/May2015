package thread.consumer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * 
 * @author tv
 */
class Stock {
	int QOH;

	synchronized void getQOH(int Qreq) {

		if (Qreq > QOH) {
			try {
				System.out.println("Consumer....wait");
				wait(); // put consume thread in wait pool by release the lock
						// on the object
			} catch (InterruptedException ex) {
				Logger.getLogger(Stock.class.getName()).log(Level.SEVERE, null,
						ex);
			}
			//QOH = QOH - Qreq;
			//QOH--;
			//System.out.println("Consumer get 10 remains " + QOH);
		}
		//QOH--;
		QOH = QOH - Qreq;
		System.out.println("Consumer " + QOH);
	}

	synchronized void setQOH() {
		QOH++;
		// Produce;
		notify();
		System.out.println("Producer " + QOH);
//		if (QOH == 10){
//			notify();
//				System.out.println("Notify consumer set QOH " + QOH);
//		}else{
//				System.out.println("set QOH " + QOH);
//		}
	}
}

// class Producer implements Runnable {
class NewProducer extends Thread {
	Stock sk;

	NewProducer(Stock s) {
		sk = s;

	}

	public void run() {
		// sk.getQOH(10);
		while (true) {
			System.out.println("Producer start");
			sk.setQOH();
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}

// class Consumer implements Runnable {
class NewConsumer extends Thread {
	Stock sk;

	NewConsumer(Stock s) {
		sk = s;
	}

	public void run() {
		while (true) {
			System.out.println("Consumer start");
			sk.getQOH(1);
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

}

// public class Consumer {

// }
class PC {
	public static void main(String[] args) {
		Stock q = new Stock();
		// new Producer(q);
		new NewProducer(q).start();

		new NewConsumer(q).start();

		System.out.println("PC main class end");
	}
}