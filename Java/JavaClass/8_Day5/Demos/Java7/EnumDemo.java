/*
Enum
Enums in java are internally considered as classes and hence the declaration of an enum can be placed at the global scope. The elements of the enum are internally considered as final and static.
But global scope does not apply for other types of data types like int, float etc.
EnumDemo


*/

enum Colors{red,green,blue};

public class EnumDemo{
	static String str;
	public static void setColors(Colors c)
	{
		if(c.equals(Colors.red))
			str ="Red Color";
		else if(c.equals(Colors.green))
				str ="Green Color";
		else if(c.equals(Colors.blue))
			str = "Blue Color";
		else
			str = "no match";
	
		System.out.println(str);
	}
	public static void main(String args[])
	{
		Colors []c = Colors.values();
		Colors c1 = Colors.blue;
		for(Colors r : c)
			System.out.println(r + " is at the index "+r.ordinal());
		EnumDemo.setColors(c1);
	}
}
