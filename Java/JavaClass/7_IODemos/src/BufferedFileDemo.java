import java.io.*;
import java.util.Scanner;
public class BufferedFileDemo {
	public static void main(String[] args) 
	{
		try
		{
		BufferedWriter br = new BufferedWriter(new FileWriter("F:\\StringDemo.txt"));
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		br.write(str);
		br.close();
		sc.close();
		
		
		
		BufferedReader br1 = new BufferedReader(new FileReader("F:\\StringDemo.txt"));
		String str1 = br1.readLine(); 
		System.out.println(str1);
		br1.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
	}

}
