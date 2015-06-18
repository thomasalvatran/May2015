package mythread.callable.par13;

import java.io.IOException;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class App {
	public static void main(String[] args) {
		ExecutorService executor = Executors.newCachedThreadPool();
		Future<Integer> future = executor.submit(new Callable<Integer>() {

			@Override
			public Integer call() throws Exception {
				Random random = new Random();
				int duration = random.nextInt(4000);
				if (duration > 200){
					throw new IOException("Sleeping for to long");
				}
				System.out.println("Starting...");
				Thread.sleep(duration);
				System.out.println("Finished...");
				return duration;
			}

		});
		executor.shutdown();
		try {
			System.out.println("Result is: " + future.get());
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ExecutionException e) {
			//			System.out.println(e.getMessage());
			IOException ex = (IOException) e.getCause();
			System.out.println(ex.getMessage());
			
		}
	}
}