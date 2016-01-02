/*
Java 7 supports catch to be of multiple types
Adavantage: overloading of catches with the same algorithm can be eliminated
*/

public class MultipleCatches {
	public static void main(String[] args) {
		try
		{
			
			
		}
		catch(ArithmeticException | NullPointerException e)
		{}
	}

}