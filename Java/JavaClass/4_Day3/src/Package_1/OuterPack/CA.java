package OuterPack;
import OuterPack.InnerPack.*;

public class CA {
	int i=12;
	public int getI()
	{
		return i;
	}
	public void disp()
	{
		System.out.println(i);
		CB b1 = new CB();
		System.out.println(b1.getJ());
	}

}
