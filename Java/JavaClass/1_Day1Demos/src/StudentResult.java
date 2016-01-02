class Student
{
	private String name;
	private int m1,m2,m3;
	
	void setStuDetails(String [] args)
	{
		 name = args[0];
		 m1 = Integer.parseInt(args[1]);
		 m2 = Integer.parseInt(args[2]);
		 m3 = Integer.parseInt(args[3]);
	}
	public  void publishResult()
	{
		int avg = (m1+m2+m3)/3;
		System.out.print("Result of "+name+" is : ");
		if((m1<35)|| (m2<35)||(m3<35))
			System.out.println("Failed");
		else
		{
			if(avg>=60)
				System.out.println("First Class");
			else if(avg>=50)
				System.out.println("Second Class");
			else if(avg>=35)
				System.out.println("Pass Class");
		}
	}
}
public class StudentResult {
	
	public static void main(String[] args) {
		Student s=new Student();
		s.setStuDetails(args);
		s.publishResult();
			
	}

}








