// Using static members in the class. And maintaining an ID sequence for the number of objects
package EmpRecordPack_3;


import java.util.Scanner;


class Emp
{
	private String Name;
	private double Sal;
	private final int EmpID;
	private static final String OrgName;
	
	static
	{
		System.out.println("static block");
		OrgName = "AAA";
	}
	
	
	Emp(String Name, double Sal,int EmpID)
	{
		System.out.println("par");
		this.Name =Name;//instance variable hiding
		this.Sal=Sal;
		this.EmpID = EmpID;
		
	}
	
	static void dispEmpDetails(Emp r)
	{
		System.out.println(r.EmpID+" "+r.Name+" "+r.Sal +" "+OrgName);
	}
}
public class EmpRecord_3 {
	public static void main(String[] args) {
		
		String Name;
		double Sal;
		int id=1;
		Scanner s = new Scanner(System.in);
		Emp [] e = new Emp[3];
		for(int i=0;i<e.length;i++)
		{
			Name = s.next();
			Sal = s.nextDouble();
			e[i] = new Emp(Name,Sal,id++);
			
		}
		
		System.out.println("------------");
		for(int i=0;i<e.length;i++)
			Emp.dispEmpDetails(e[i]);
		
	}

}








