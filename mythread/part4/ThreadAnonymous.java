package mythread.part4;

class RunnerT extends Thread {
	String t;
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for (int i = 0; i < 5; i++)
			System.out.println(t + " " +  i );
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
  RunnerT( String s){ t = s;}				//ctors
}

class Runner implements Runnable {

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for (int i = 0; i < 5; i++)
			System.out.println("Hello " + i);
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

public class ThreadAnonymous {
	public static void main(String[] args) {
//		Thread t = new Thread(new Runner());
//		Thread t1 = new Thread(new Runner());
//		t.start();
//		t1.start();
		//RunnerT q = new RunnerT().start();
//		RunnerT runner = new RunnerT("s");
//		runner.start();
		
		new RunnerT("Thead T1").start();
		new RunnerT("Thead T2").start();
		//new Thread(q,"TTTT").start();
//		RunnerT v = new RunnerT();
//		RunnerT v1 = new RunnerT();
//		v.start();
//		v1.start();

		Thread t2 = new Thread(new Runnable() {
			@Override
			public void run() {
				// TODO Auto-generated method stub
				for (int i = 0; i < 5; i++)
					System.out.println("Hello Anonymous 1 " + i);
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		t2.start();
		
		new Thread(new Runnable() {
			@Override
			public void run() {
				// TODO Auto-generated method stub
				for (int i = 0; i < 5; i++) {
					System.out.println("Hello Anonymous 2 " + i);
					try {
						Thread.sleep(100);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}

		}).start();
	}
}
