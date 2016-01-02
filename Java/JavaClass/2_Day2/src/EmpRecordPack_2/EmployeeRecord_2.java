// Same as EmployeeRecord_1.java. Just using the "this" keyword
package EmpRecordPack_2;

import java.util.Scanner;


class Emp
{
	private String Name;
	private double Sal;
	
	Emp()
	{
		System.out.println("def");
		Name = "Jack";
		Sal=12000;
	}
	Emp(String Name, double Sal)
	{
		System.out.println("par");
		this.Name =Name;//instance variable hiding
		this.Sal=Sal;
	}
	
	Emp(Emp e2)
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
public class EmployeeRecord_2 {
	public static void main(String[] args) {
		
		Emp e1 = new Emp();	
		e1.dispEmpDetails();
		System.out.println("-------------");
		
		
		Scanner s = new Scanner(System.in);
		String n;
		double sal;
		n = s.next();
		sal = s.nextDouble();
		Emp e2 = new Emp(n,sal);
	
		e2.dispEmpDetails();
		
		System.out.println("-------------");
		Emp e3 = new Emp(e2);
		
		e3.dispEmpDetails();
		
		
		
		
	}

}








