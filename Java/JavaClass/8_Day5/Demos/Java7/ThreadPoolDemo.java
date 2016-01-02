import java.util.Scanner;
import java.util.concurrent.*;

class UserThread_1 implements Runnable
{
	String Name;
	static Executor pool = Executors.newFixedThreadPool(3);
	public UserThread_1(String n)
	{
		Name=n;
		pool.execute(this);
	}
	public void run()
    {
		try
		{
		 Scanner sc = new Scanner(System.in);
		 System.out.println(Name+" entered : enter an integer");
		 Thread.sleep(3000);
		 int val = sc.nextInt();
		 val++;
		 System.out.println(val);
		 System.out.println(Name +" task completed");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
    }
	
}
public class ThreadPoolDemo
{
	public static void main(String[] args) 
	{
	        UserThread_1 u1 = new UserThread_1("FirstThread");
	        UserThread_1 u2 = new UserThread_1("SecondThread");
	        UserThread_1 u3 = new UserThread_1("ThirdThread");
	        UserThread_1 u4 = new UserThread_1("FourthThread");
	       
	}
}











