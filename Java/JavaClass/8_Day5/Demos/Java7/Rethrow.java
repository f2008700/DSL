/*
In the previous versions, if there is a rethrow of a checked excetion,the throws clause manadatory had to match the type of the rethrow varible i.e. throws Exception because e is of type Exception

This is avoided is Java 7 i.e the thrown type and the throws  tag can be different. Also the catch parameter can be prefixed with final to avoid multiples catches for a given try

*/
public class Rethrow
{
public static void main(String [] args)throws InterruptedException
{
   try
   {
	   throw new InterruptedException();
   }
   catch(final Exception e)
   {
	   throw e;
   }

}
}