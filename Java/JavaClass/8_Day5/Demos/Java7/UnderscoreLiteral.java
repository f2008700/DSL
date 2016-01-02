/*
With Java 7, you can include underscores in numeric literals to make them more readable. The underscore is only present in the representation of the literal in Java code, and will not show up when you print the value.
*/

public class UnderscoreLiteral
{
public static void main(String args[])
{
int tenMillion = 10_00_00_00;
System.out.println("Amount is " + tenMillion);
}
}