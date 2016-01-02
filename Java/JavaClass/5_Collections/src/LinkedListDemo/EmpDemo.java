package LinkedListDemo;
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
		LinkedList s = new LinkedList();
		s.add(new Emp("Savings",700));
		s.add(new Emp("Current",800));
		s.add(new Emp("FixedDeposit",900));
		s.add(new Emp("Savings",1200));
		s.add(3,new Emp("Current",1500));
		s.addFirst(new Emp("Savings",2000));
		s.addLast(new Emp("Savings",3000));
		
		for(int i=0;i<s.size();i++)
		{
			a = (Emp)s.get(i);
			a.dispAcctDetails();
		}
		System.out.println("--------------------");
		//Method 2
		s.removeFirst();
		s.removeLast();
		Iterator t = s.iterator();
		while(t.hasNext())
		{
			a = (Emp)t.next();
			a.dispAcctDetails();
			//System.out.println(a);
		}
		
	}

}


