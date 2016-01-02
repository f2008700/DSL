/*
Static imports enables the features that we can import only the required static members instead of the entire package elements
*/
StaticDemo.java
package StaticPackage;

public class StaticDemo {
   public static int i=12;
   public static void fun()
   {
	   System.out.println("inside static function");
   }
   public static class StaticClass
   {
	   public void disp()
	   {
		   System.out.println("inside static class disp func");
	   }
   }
}
*******************************************************************************
StaticClientDemo.java

package StaticPackage.StaticClientPackage;

import static StaticPackage.StaticDemo.i;
import static StaticPackage.StaticDemo.fun;
import static StaticPackage.StaticDemo.StaticClass;

public class StaticClientDemo {
	public static void main(String args[])
	{
		System.out.println("static data member value is :"+i);
		System.out.println("invoking the static function");
		fun();
		System.out.println("using the static class");
		StaticClass s = new StaticClass();
		s.disp();
	}

}
