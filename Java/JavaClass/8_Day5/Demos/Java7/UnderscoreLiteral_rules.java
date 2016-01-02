/*
With Java 7, you can include underscores in numeric literals to make them more readable. The underscore is only present in the representation of the literal in Java code, and will not show up when you print the value.
More rules and examples


1. Consecutive underscores is illegal.
int n = 1000______000;

2. Underscores can be included in other numeric types as well.

double d = 1000_000.0d;
long l = 1000_000l;
int hex = 0xdead_c0de;
int bytes = 0x1000_0000;

3. Underscore can be included after the decimal point.
double example8 = 1000_000.000_000d;

4. It is illegal to start a literal with an underscore
int i=_1000;

5. It is illegal to end a literal with an underscore.
int i=1000_;

6. It is also illegal to have underscore be just before or after a decimal point.
int i=10_._00
 
*/

public class UnderscoreLiteral
{
public static void main(String args[])
{
int tenMillion = 10_00_00_00;
System.out.println("Amount is " + tenMillion);
}
}