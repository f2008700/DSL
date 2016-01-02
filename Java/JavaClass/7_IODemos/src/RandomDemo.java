import java.io.*;
public class RandomDemo
{
public static void main(String args[]) throws IOException
{

  RandomAccessFile r = new RandomAccessFile("F:\\Data.txt","rw");
  long pos = r.getFilePointer();
  System.out.println("File Pointer position is :"+ pos);
    int data;
    r.seek(10);
    data  = r.read();
    System.out.print(data+" ");
   /* while(data == -1)
   {
       System.out.print(data+" ");
      // data = r.read();
     //  r.write(45);
       
   }*/
r.close();
}
}   
