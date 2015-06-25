package thread.banner;

import java.awt.*;
import java.applet.*;

//Javavids welcome program Java multi threads  (video 11)
public class Banner extends Applet implements Runnable {
	Thread t;
	String s = " Welcome to Banner Program";

	public void start() {
		if (t == null) {
			t = new Thread(this);
			t.start();
		}
	}

	public void stop() {
		if (t != null) {
			t.stop();
		}
	}

	public void paint(Graphics g) {
		g.drawString(s, 10, 50);
	}

	public void run() {
		char ch;
		while (true) {
			ch = s.charAt(0);
			s = s.substring(1, s.length());
			s += ch;
			repaint();
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
			}
		}
	}
}
// public class ThreadTest5 {
// public static void main(String args[]) {
//
// DispThread dt1 = new DispThread("Hello");
// DispThread dt2 = new DispThread("World");
// dt1.start(); // call user thread from main thread
// dt2.start();
//
// }

// }
