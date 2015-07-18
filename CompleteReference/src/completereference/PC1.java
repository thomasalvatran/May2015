package completereference;

import java.util.logging.Level;
import java.util.logging.Logger;


/**
 * 
 * @author tv
 */
// A correct implementation of a Producer1 and Consumer1. p.207 The complete reference
class Q1 {
	int n;
	boolean valueSet = false;

	synchronized int get() { // wait and notify always called from monitor(sync)
								// Video javavids Java: Thread wait and notify
		if (!valueSet)
			try {
				wait();
			} catch (InterruptedException e) {
				System.out.println("InterruptedException caught");
			}
		System.out.println("Got: " + n);
		valueSet = false;
		notify();
		return n;
	}

	synchronized void put(int n) {
		if (valueSet)
			try {
				wait();
			} catch (InterruptedException e) {
				System.out.println("InterruptedException caught");
			}
		this.n = n;
		valueSet = true;
		System.out.println("Put: " + n);
		notify();
	}
}

class Producer1 implements Runnable {
	Q1 Q1;

	Producer1(Q1 Q1) {
		this.Q1 = Q1;
		new Thread(this, "Producer1").start();
	}

	public void run() {
		int i = 0;
		while (true) {
			Q1.put(i++);
			try {
				Thread.sleep(1000);
			} catch (InterruptedException ex) {
				Logger.getLogger(Producer1.class.getName()).log(Level.SEVERE,
						null, ex);
			}
		}
	}
}

class Consumer1 implements Runnable {
	Q1 Q1;

	Consumer1(Q1 Q1) {
		this.Q1 = Q1;
		new Thread(this, "Consumer1").start();
	}

	public void run() {
		while (true) {
			Q1.get();
		}
	}
}

class PC1 {
	public static void main(String args[]) {
		Q1 Q1 = new Q1();
		//Consumer1 a = new Consumer1(Q1);
		new Producer1(Q1);
		new Consumer1(Q1);
		System.out.println("Press Control-C to stop.");
	}
}
