import java.io.*;
public class FileReadDemo
{
public static void main(String args[]) throws IOException
{
    InputStream  in = new FileInputStream("F:\\Data.txt");
    int data = in.read();
    while(data != -1)
    {
       System.out.print(data+" "); 
       data = in.read();
    }
    
    in.close();
}
}
