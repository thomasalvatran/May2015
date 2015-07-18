package completereference;

//Demonstrate the clone() method.
class TestClone implements Cloneable {
	int a;
	double b;

	// This method calls Object's clone().
	TestClone cloneTest() {
		try {
			// call clone in Object.
			return (TestClone) super.clone();
		} catch (CloneNotSupportedException e) {
			System.out.println("Cloning not allowed.");
			return this;
		}
	}
}

class CloneDemo {
	public static void main(String args[]) {
		TestClone x1 = new TestClone();
		TestClone x2;
		x1.a = 10;
		x1.b = 20.98;
		x2 = x1.cloneTest(); // clone x1
		System.out.println("x1: " + x1.a + " " + x1.b);
		System.out.println("x2: " + x2.a + " " + x2.b);
		TestClone x3 = (TestClone) x1.cloneTest();
		System.out.println("x3: " + x3.a + " " + x3.b);
		
		TestClone x4 = x1;
		System.out.println("x4: " + x4.a + " " + x4.b);
		
	}
}
