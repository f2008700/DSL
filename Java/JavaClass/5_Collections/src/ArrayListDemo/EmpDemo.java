package ArrayListDemo;
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
		ArrayList<Emp> s = new ArrayList<Emp>();
		s.add(new Emp("Savings",700));
		s.add(new Emp("Current",800));
		s.add(new Emp("FixedDeposit",900));
		s.add(new Emp("Savings",1200));
		s.add(3,new Emp("Current",1500));
		s.r
		
		for(int i=0;i<s.size();i++)
		{
			a = s.get(i);
			a.dispAcctDetails();
		}
		System.out.println("--------------------");
		
		
		
		
		
		
		//Method 2
		
		Iterator t = s.iterator();
		while(t.hasNext())
		{
			a = (Emp)t.next();
			a.dispAcctDetails();
			//System.out.println(a);
		}
		
	}

}


/*









class BobokStore
{
	//Book [] b = new Book[5];
	ArrayList a = new ArrayList();
	
	AddBook()
	{
		//b[BookCount]=new Book(....);
		a.add(new Book(...));
	}
	
	disp()
	{
	//	for(int i=0;i<BookCount;i++)
		//	System.out.println(b[i].getBookTitle());
		Book b1 =null;
		Iterator t = a.iterator();
		while(t.hasNext())
		{
			b1 = (Book)t.next();
			System.out.println(b1.getBookTitle());
		}
		//Method2
		for(int i=0;i<a.size();i++)
		{
			b1 = (Book)a.get(i);
			....
		}
			
			
			
		}
	}
	
}

*/







