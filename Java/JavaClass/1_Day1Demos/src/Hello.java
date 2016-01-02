
public class Hello {
	 public static void main(String [] args){
	     for(int i=0;i<args.length;i++)
	     System.out.print(args[i]+" ");
	     System.out.println();
	     
	     int n1 = Integer.parseInt(args[0]);
	     int n2 = Integer.parseInt(args[1]);
	    
	     System.out.println(n1+n2);
	  }
}
