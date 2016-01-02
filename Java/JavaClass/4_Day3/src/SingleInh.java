//base class
 class Emp
{
	protected double Sal;
	protected String Name;
	Emp(double s , String n)
	{
		Sal = s;
		Name = n;
		
	}
	
	public void disp()//overridden
	{
		System.out.println(Name);
		System.out.println(Sal);
	}
	
//	abstract void disp();
	
}


 
class TEmp extends Emp
{
	int duration;
	TEmp(int d,double s , String n)
	{
		super(s,n);
		duration= d;
	}
	
	public void disp()//overriding
	{
		//super.disp();
		System.out.println(Name);
		System.out.println(Sal);
		System.out.println(duration);
	}
}
public class SingleInh {
	public static void main(String[] args) {
		Emp r = new TEmp(2,12000,"Rushil");
		r.disp();
	}
}
