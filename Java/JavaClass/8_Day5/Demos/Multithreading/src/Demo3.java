class Target
{
	public  void display(String s)
	{
		try
		{
		System.out.print("["+s);
		Thread.sleep(1000);
		System.out.println("]");
		}
		catch(InterruptedException e)
		{
			System.out.println(e);
		}
	}
}

class MyThread extends Thread
{
	Target t;
	
	String name;
	MyThread(String n,Target t)
	{
		
		this.t=t;
		name=n;
		start();
		
	}
	public void run()
	{
		synchronized(t)
		{
		t.display(name);
		}
	}
}

public class Demo3 {
	public static void main(String[] args) {
		Target t = new Target();
		MyThread t1 = new MyThread("Hello",t);
		MyThread t2 = new MyThread("World",t);
		MyThread t3 = new MyThread("Program",t);
	}

}







