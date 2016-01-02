/*
If we are instantiated any class thats implements AutoCloseable ,then an explicit close is not required. At the epilog of the try blocked , automatically close() method will be called
*/

class Demo implements AutoCloseable
{
public void close() 
{
  System.out.println("in close"); 
}
}


public class AutoCloseableDemo
{
public static void main(String [] args)
{
   try(Demo d = new Demo())
  {
  }
  finally
 {
    System.out.println("in finally");
 }
}
}
















