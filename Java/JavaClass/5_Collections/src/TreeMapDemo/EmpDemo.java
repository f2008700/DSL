package TreeMapDemo;
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

	public String toString()
	{
		return EmpName+"\t"+Sal;
	}

}

public class EmpDemo {
	public static void main(String[] args) {
		Emp a=null;
		TreeMap<Integer,Emp> s = new TreeMap<Integer,Emp>();
		
		s.put(1,new Emp("Savings",700));
		s.put(3,new Emp("FixedDeposit",900));
		s.put(2,new Emp("Current",800));
		s.put(4,new Emp("Savings",1200));
		s.put(1,new Emp("Current",1500));
		
		
		Set s1 = s.entrySet();
		Iterator t = s1.iterator();
		while(t.hasNext())
		{
			
			Map.Entry e = (Map.Entry)t.next();
			System.out.println(e.getKey()+"\t"+e.getValue());
		}
		
		
		
		
		
	}
}



