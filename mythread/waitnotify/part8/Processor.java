package mythread.waitnotify.part8;

import java.util.Scanner;

public class Processor {
	public void produce() throws InterruptedException{
		synchronized (this) {
			System.out.println("Producer thread running...");
			wait();  //call within synchronize block hand the lock
			System.out.println("Resumed");
		}
	}
	public void consumer() throws InterruptedException{
		Scanner scanner = new Scanner(System.in);
		Thread.sleep(2000);
		
		synchronized (this) {
		System.out.println("waiting for return key");
		scanner.nextLine();
		notify();
		Thread.sleep(5000);
		
		}
	}
}
