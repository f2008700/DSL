// Display the constructor overloading concept
import java.util.Scanner;


class Emp
{
	private String Name;
	private double Sal;
	
	void setEmpDetails()
	{
		System.out.println("def");
		Name = "Jack";
		Sal=12000;
	}
	void setEmpDetails(String n, double s)
	{
		System.out.println("par");
		Name =n;
		Sal=s;
	}
	
	void setEmpDetails(Emp e2)
	{
		System.out.println("copy");
		Name = e2.Name;
		Sal=e2.Sal;
	}
	void dispEmpDetails()
	{
		System.out.println(Name+" "+Sal);
	}
}
public class EmployeeRecord_1 {
	public static void main(String[] args) {
		Emp e1 = new Emp();
		e1.setEmpDetails();
		
		
		e1.dispEmpDetails();
		System.out.println("-------------");
		
		Emp e2 = new Emp();
		Scanner s = new Scanner(System.in);
		String n;
		double sal;
		n = s.next();
		sal = s.nextDouble();
		e2.setEmpDetails(n,sal);
		e2.dispEmpDetails();
		
		System.out.println("-------------");
		Emp e3 = new Emp();
		e3.setEmpDetails(e2);
		e3.dispEmpDetails();
		
		
	}

}








