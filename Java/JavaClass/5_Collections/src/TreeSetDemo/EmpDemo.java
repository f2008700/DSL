package TreeSetDemo;

//import java.io.Serializable;
import java.util.*;
class Emp implements Comparable
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

	
	
	public String toString()
	{
		return EmpName+"\t"+Sal;
	}

	@Override
	public int compareTo(Object arg0) {
		// TODO Auto-generated method stub
		Emp a = (Emp)arg0;
		if(this.Sal>a.Sal)
			return 1;//no swap
		else 
			return -1;//swap
		
	}
	
	
}
public class EmpDemo {
	public static void main(String[] args) {
		Emp a=null;
		TreeSet s = new TreeSet();
		s.add(new Emp("Savings",700));
		s.add(new Emp("Current",1800));
		s.add(new Emp("FixedDeposit",900));
		s.add(new Emp("Savings",1200));
		
		Iterator t = s.iterator();
		while(t.hasNext())
		{
			a = (Emp)t.next();
			a.dispAcctDetails();
		}
	}

}


