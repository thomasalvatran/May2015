package mythread.part4;

import java.util.List;
import java.util.ArrayList;
import java.util.Random;

import java.util.List;
import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * 
 * @author tv
 */
public class Worker {
	private Random random = new Random();
	private List<Integer> List1 = new ArrayList<Integer>();
	private List<Integer> List2 = new ArrayList<Integer>();

	public void stageOne() {
		try {
			Thread.sleep(1);
		} catch (InterruptedException ex) {
			Logger.getLogger(Worker.class.getName())
					.log(Level.SEVERE, null, ex);
		}
		List1.add(random.nextInt(100));
	}

	public void stageTwo() {
		try {
			Thread.sleep(1);
		} catch (InterruptedException ex) {
			Logger.getLogger(Worker.class.getName())
					.log(Level.SEVERE, null, ex);
		}
		List2.add(random.nextInt(100));

	}

	public void process() {
		for (int i = 0; i < 1000; i++)
			stageOne();
			stageTwo();
	}

	public void main() {
		System.out.println("Starting...");
		long start = System.currentTimeMillis();
		new Thread(new Runnable() {

			@Override
			public void run() {
				// System.out.println(""); //To change body of generated
				// methods, choose Tools | Templates | Generated Method Body
				process();
			}
		}).start();
		long end = System.currentTimeMillis();
		System.out.println("Time take: " + (end - start));
		System.out.println("List1: " + List1.size() + "; List2; "
				+ List2.size());
	}
}
