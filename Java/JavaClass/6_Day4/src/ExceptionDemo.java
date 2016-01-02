



class Arithmetic
{
	int i;
	public Arithmetic()
	{
		i=12;
	}
	void divide(int d)
	{
		try
		{
			i=i/d;
			
			try
			{
				int [] x = new int[2];
				x[56]=45;
			}
			catch(ArithmeticException e)
			{
			}
			finally
			{
				
			}
			
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("caught outer");
		}
		
		catch(ArithmeticException e)
		{
			e.printStackTrace();
			throw e;//rethrow
	     }
		catch(Exception e)
		{
			System.out.println("caught in divide"+e);
		}
		finally
		{
			System.out.println("finally");
		}
	}
}
public class ExceptionDemo {
	public static void main(String[] args) {
		Arithmetic a = new Arithmetic();
		try
		{
		a.divide(2);
		}
		catch(Exception e)
		{
			System.out.println("caught in main");
		}
		System.out.println("in main");
	}

}







