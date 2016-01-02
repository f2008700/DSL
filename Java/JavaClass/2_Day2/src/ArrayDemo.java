// Display the different types of Arrays
public class ArrayDemo {
	public static void main(String[] args) {
		int []x = new int [3];
		for(int i=0;i<x.length;i++)
			x[i] = i*2;
		
		for(int i=0;i<x.length;i++)
			System.out.print(x[i]+" ");
		System.out.println();
		System.out.println("-----------");
		
		//multidimentional
		int [][]x1 = new int[2][3];
		//System.out.println("length:"+x1.length);
		for(int i=0;i<2;i++)
			for(int j=0;j<3;j++)
				x1[i][j] = i*j*2;
		
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<3;j++)
				System.out.print(x1[i][j]+" ");
			System.out.println();
		}
		
		System.out.println("--------------");
		
		//Jagged Array
		//multidimentional
		int [][]x2 = new int[3][];
		x2[0] = new int[1];
		x2[1] = new int[2];
		x2[2] = new int[3];
		
		for(int i=0;i<x2.length;i++)
			for(int j=0;j<x2[i].length;j++)
				x2[i][j] = i*j*2;
		
		for(int i=0;i<x2.length;i++)
		{
			for(int j=0;j<x2[i].length;j++)
				System.out.print(x2[i][j]+" ");
			System.out.println();
		}
		
		
		
		
	}

}
