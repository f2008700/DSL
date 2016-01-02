class CA
{
	static CA a1;
	int i;
	static int j;
	static
	{
		j=1;
		a1=null;
	}
	private CA()
	{
		System.out.println("constr");
		i=2;
	}
	public static void disp(CA a)
	{
		System.out.println(a.i+"\t"+j);
	}
	public void display()
	{
		System.out.println(i+"\t"+j);
	}
	public static CA CreateInstance()
	{
		if(a1==null)
			a1= new CA();
		return a1;
	}
	
}
public class Demo {
	public static void main(String[] args) {
		CA r = CA.CreateInstance();
		r.display();
		CA r1 = CA.CreateInstance();
		r1.display();
		
	}

}


















