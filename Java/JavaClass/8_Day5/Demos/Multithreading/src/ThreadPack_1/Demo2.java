package ThreadPack_1;

class UserThread extends Thread
{
	String name;
	Thread mt;
	
	UserThread(String n,Thread mt)
	{
		this.mt = mt;
		name = n;
		start();
	}
	public void run()
	{
		try
		{
			for(int i=1;i<=10;i++)
			{
			    if(i==5)
			    	mt.resume();
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
public class Demo2 {
	public static void main(String[] args) {
		Thread mt = Thread.currentThread();
		System.out.println(mt.getName()+" "+mt.getPriority());
		mt.setName("MainThread");
		mt.setPriority(8);
		System.out.println(mt.getName()+" "+mt.getPriority());
		
		UserThread u = new UserThread("ChildThread",mt);
	
		try
		{
			mt.suspend();
			for(int i=1;i<=10;i++)
			{
			//	u.join();
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
