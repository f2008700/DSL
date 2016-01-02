/*
Java 7 supports try to be parameterised and if multiple inputs are there as the try, they should be separated by ; 
Also the close() on the IO classes are also not needed (i.e br.close()).When the scope of the block ends, implicilty the IO resource is automatically closed
*/
import java.io.*;
import java.util.Scanner;
public class ParameterisedTry {
	public static void main(String[] args) 
	{
		try(BufferedWriter br = new BufferedWriter(new FileWriter("F:\\Java7\\StringDemo.txt")))
		{
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		String str = sc.readLine();
		br.write(str);
		
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
	}

}