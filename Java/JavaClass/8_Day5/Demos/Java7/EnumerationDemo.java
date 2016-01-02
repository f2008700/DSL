/*
Enumerations
public interface Enumeration
An object that implements the Enumeration interface generates a series of elements, one at a time. Successive calls to the nextElement method return successive elements of the series. 
For example, to print all elements of a vector v: 
     for (Enumeration e = v.elements() ; e.hasMoreElements() ;) {
         System.out.println(e.nextElement());

     }

*/

import java.util.*;
public class EnumerationDemo{
	public static void main(String args[])
	{
		Vector v = new Vector();
		v.add(new Integer(1));
		v.add(new Integer(2));
		v.add(new Integer(3));
		v.add(new Integer(4));
		
		System.out.println("The elements of the Vector are :");
		for (Enumeration e = v.elements() ; e.hasMoreElements() ;) 
	         System.out.println(e.nextElement());	
	}
}
