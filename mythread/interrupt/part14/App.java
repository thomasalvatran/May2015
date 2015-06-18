package mythread.interrupt.part14;

import java.util.Random;

public class App {

	/**
	 * @param args
	 * @throws InterruptedException 
	 */
	public static void main(String[] args) throws InterruptedException {
		System.out.println("Starting");
		
		Thread thread = new Thread(new Runnable() {
			
			@Override
			public void run() {
				Random random = new Random();
				for (int i = 0; i < 1E6; i++){
//					try {
//						Thread.sleep(1);
//					} catch (InterruptedException e) {
//						System.out.println("We've been interrupted");
//					}
					if(Thread.currentThread().isInterrupted()){
						System.out.println("Interrupt");
						break;
					}
					Math.sin(random.nextDouble());
				}
				
			}
		});
		thread.start();
		
		Thread.sleep(500);
		thread.interrupt();
		
		thread.join();
		
		System.out.println("Finished");

	}

}
