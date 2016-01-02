import java.io.*;
public class FileWriteDemo
{
public static void main(String args[]) throws IOException
{
    OutputStream  out = new FileOutputStream("F:\\Data.txt");
    int data = 1;
    while(data != 255)
    {
           out.write(data);
           data++;
    }
    out.write(-1);
    out.write(25);
   
    out.close();
}
}
