// Create a class with singleton element in it. Using the a specialized parameter.
class PrintSpool
{
	static PrintSpool p;
	int capacity;
	static
	{
		p=null;
	}
	private PrintSpool()
	{
		System.out.println("constr");
		capacity = 2;
	}
	static PrintSpool CreateInstance()
	{
		if(p==null)
			p = new PrintSpool();
		return p;
	}
	void disp()
	{
		System.out.println(capacity);
	}
}
public class SingletonDemo {
	public static void main(String[] args) {
		PrintSpool p1 = PrintSpool.CreateInstance();
		PrintSpool p2 = PrintSpool.CreateInstance();
		p1.disp();
		p2.disp();
		
		}
}
