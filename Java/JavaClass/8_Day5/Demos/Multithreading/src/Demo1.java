class UserThread implements Runnable
{
	Thread t,mt;
	String name;
	
	UserThread(String n,Thread mt)
	{
		this.mt = mt;
		name = n;
		t = new Thread(this,name);
		t.start();
	}
	public void run()
	{
		try
		{
			for(int i=1;i<=10;i++)
			{
				mt.join();
				System.out.println(name+"------"+i);
				Thread.sleep(1000);
			}
			
		}
		catch(InterruptedException e)
		{
			System.out.println(e);
		}
	}
}
public class Demo1 {
	public static void main(String[] args) {
		Thread mt = Thread.currentThread();
		System.out.println(mt.getName()+" "+mt.getPriority());
		mt.setName("MainThread");
		mt.setPriority(8);
		System.out.println(mt.getName()+" "+mt.getPriority());
		
		UserThread u = new UserThread("ChildThread",mt);
	
		try
		{
			for(int i=1;i<=10;i++)
			{
				u.t.join();
				System.out.println(mt.getName()+"------"+i);
				Thread.sleep(1000);
			}
			
		}
		catch(InterruptedException e)
		{
			System.out.println(e);
		}
		
	}

}
