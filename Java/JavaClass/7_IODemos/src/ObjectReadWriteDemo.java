import java.io.*;
class Emp implements Serializable
{
    int id;
    int sal;
    Emp(int i,int s)
   {
      id=i;
      sal=s;
   }

   void disp()
   {
      System.out.println(id+"\t"+sal);
   }
 
}

class ObjectReadWriteDemo
{
   public static void main(String args[])throws Exception
   {
       ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("F:\\ObjectsData.txt"));
       ObjectInputStream in = new ObjectInputStream(new FileInputStream("F:\\ObjectsData.txt"));
       Emp e1 = new Emp(1,1000);
       Emp e2 = new Emp(2,2000);

       out.writeObject(e1);
       out.writeObject(e2);

       Emp r;
       r =(Emp) in.readObject();
       r.disp();

       r = (Emp)in.readObject();
       r.disp();

       in.close();
       out.close();
    }
}