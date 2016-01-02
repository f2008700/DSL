package StackDemo;
import java.util.*;
class Emp
{
	String EmpName;
	int Sal;
	
	Emp(String EmpName,int Sal)
	{
		this.EmpName = EmpName;
		this.Sal = Sal;
	}
	void dispAcctDetails()
	{
		System.out.println(EmpName+"\t"+Sal);
	}
}

public class EmpDemo {
	public static void main(String[] args) {
		Emp a=null;
		Stack s = new Stack();
		
		
		s.push(new Emp("Shobha",700));
		s.push(new Emp("Sheela",800));
		s.push(new Emp("Shaila",900));
		s.push(new Emp("Rushil",1200));
		System.out.println(s.size());
		
		while(s.size()>0)
		{
			a = (Emp)s.pop();
			a.dispAcctDetails();
			
		}
		
	}

}

