// Controlling the main Thread.
class Runner implements Runnable {

	Runner() {
		Thread t = new Thread(this, "Child Thread ");
		t.start();
	}

	public void run() {
		Thread t = Thread.currentThread();
		t.setPriority(Thread.NORM_PRIORITY + 2);
		try {
			for (int i = 0; i < 5; i++) {
				System.out.println("Current Thread: " + t + i);
				Thread.sleep(10);
			}
		} catch (InterruptedException e) {
			System.out.println("Child thread interrupted");
		}
		System.out.println("Child Thread exiting");
	}
}

class CurrentThreadDemo {
	public static void main(String args[]) {
		// Thread thread = new Thread(new Runner());
		// thread.start();
//		Runner runner = new Runner();   //HEAP
		new Runner();					//STACK
		Thread t = Thread.currentThread();
		System.out.println("Current thread: " + t);
		// change the name of the thread
		t.setName("My Thread");
		System.out.println("After name change: " + t);
		try {
			for (int n = 5; n > 0; n--) {
				System.out.println(n);
				Thread.sleep(10);
			}
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
		System.out.println("Main Thread exiting");
	}
}