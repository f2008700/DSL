/*
Java 7 can interpred the informtion within the argular bracket of the collection if t is already mentioned on the left hand side
*/

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
	
public class CollectionDemo{
	public static void main(String[] args) {
		Emp a=null;
		List<Emp> s = new ArrayList<>();
		s.add(new Emp("Shobha",700));
		s.add(new Emp("Sheela",800));
		s.add(new Emp("Shaila",900));
		s.add(new Emp("Jack",1200));
		s.add(3,new Emp("Rushil",1500));
		
		
		for(int i=0;i<s.size();i++)
		{
			a = s.get(i);
			a.dispAcctDetails();
		}
		System.out.println("--------------------");
		
		
	}

}

