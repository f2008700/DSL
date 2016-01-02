class SpeedViolationException extends Exception
{
	String msg;
	public SpeedViolationException(String m) {
		msg=m;
	}
	public String toString()
	{
		return msg;
	}
}

class Vehicle
{
	int speed;
	public void setSpeed(int s)throws SpeedViolationException
	{
		if(s>80)
			throw new SpeedViolationException("Max Threshhold speed shd be 80");
		else
			speed=s;
	}
	
}

public class UserExceptionDemo {
public static void main(String[] args)
{
	Vehicle v = new Vehicle();
	try
	{
	v.setSpeed(90);
	}
	catch (SpeedViolationException e) {
		System.out.println(e);
	}
	System.out.println("in main");
}
}













