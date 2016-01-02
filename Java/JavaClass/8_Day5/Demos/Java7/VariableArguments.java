/*
Variable Arguments
Note: here numbers is internally interpreted as an array of integers.The variable argument should always be the last parameter in the function declaration.
*/

class Arithmetic
{
	public void Add(String str, int... numbers)
	{
		int result=0;
		for(int num : numbers)
		result = result + num;
		System.out.println(str+result);
	}
}
public class VariableArguments {
public static void main(String args[])
{
	Arithmetic ar = new Arithmetic();
	ar.Add("The sum is :",1,2);
	ar.Add("The sum is :",1,2,3);
	ar.Add("The sum is :",1,2,3,4);
}
}
