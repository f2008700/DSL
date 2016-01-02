
public class StringDemo {
	public static void main(String args[])
	{
		String str = "Hello";
		char ch = str.charAt(1);
		System.out.println(ch);
		
		String str1 = "HELLO";
		if(str.compareTo(str1)==0)
			System.out.println("The strings are same");
		else
			System.out.println("The strings are different");
		
		if(str.compareToIgnoreCase(str1)==0)
			System.out.println("The strings are same");
		else
			System.out.println("The strings are different");
		
		str.concat(str1);
		//str = str.concat(str1);
		System.out.println(str);
		
		boolean b = str.endsWith("llo");
		System.out.println(b);

		if(str.equals(str1))
			System.out.println("The strings are same");
		else
			System.out.println("The strings are different");
		
		byte b1[] = str.getBytes();
		for(int i=0;i<b1.length;i++)
		System.out.print(b1[i]+" ");
		System.out.println();
		
		char c[]=new char[6];
		
		str.getChars(0, 5, c, 0);
		for(int i=0;i<c.length;i++)
			System.out.print(c[i]+" ");
		System.out.println();
		
		int j = str.indexOf('l');
		System.out.println(j);
		
		j = str.lastIndexOf('l');
		System.out.println(j);
		
		String str3 = "Here is a demo.It is of String methods";
		str3 = str3.replaceAll("is", "sis");
		System.out.println(str3);
		
		//StringBuffer 
		//StringBuffer s1 ="Ajay";
		
		
		
		StringBuffer s1=new StringBuffer("Hello");
		String s2 = "Ajay";
	    s1.append(s2);
	
		System.out.println(s1);
		s1.append(s2);
		System.out.println(s1);
		
		s1.insert(9, '!');
		System.out.println(s1);
		
		s1.delete(0, 5);
		System.out.println(s1);
		
		s1.reverse();
		System.out.println(s1);
	
	}

}
