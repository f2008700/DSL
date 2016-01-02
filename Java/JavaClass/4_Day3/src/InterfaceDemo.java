
interface IA 
{
	void set();
}
interface IB 
{
	void disp();
}
interface II extends IA,IB
{
	void set();
	void disp();
}

class CA implements II
{
	public void set()
	{System.out.println("set");}
	public void disp()
	{System.out.println("disp");}
	
}

public class InterfaceDemo {
	public static void main(String[] args) {
		II a = new CA();
		a.set();
		a.disp();
	}

}








