/*
foreach loop is much safer than for loop
*/

import java.util.*;
public class ForEachDemo {
public static void main(String args[])
{
	List<Integer> l = new ArrayList<Integer>();
	l.add(new Integer(1));
	l.add(new Integer(2));
	l.add(new Integer(3));
	
	System.out.println("output via foreach method");
	//foreach loop
	for(Integer num : l)
		System.out.println(num);
	
	
}
}
