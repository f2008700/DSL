class Person
{
	String FName;
	String LName;
	
	Person(String FName,String LName ){
		this.FName = FName;
		this.LName = LName;
	}
	public String toString()
	{
		return FName+" "+LName;
	}
	
}
public class Overloading {
	public static void main(String[] args) {
		Person p = new Person("Shobha","Bhardwaj");
		System.out.println(p);
	}

}









