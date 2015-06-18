package mythread.thread.part1.demo2;

class Runner implements Runnable{  // interface public void 

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for (int i = 0; i < 10; i++)
			System.out.println("Hello " + i);
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
		
}
public class App {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Thread t1 = new Thread(new Runner());
		Thread t2= new Thread(new Runner());
		t1.start();
		t2.start();
		
	}

}
