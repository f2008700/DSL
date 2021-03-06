import java.util.*;

class Item
{
	String Desc;
	public String getDesc() {
		return Desc;
	}
	public void setDesc(String desc) {
		Desc = desc;
	}
	public double getRate() {
		return Rate;
	}
	public void setRate(double rate) {
		Rate = rate;
	}
	double Rate;
}

class SaleItem
{
	Item t;
	public Item getT() {
		return t;
	}
	public void setT(Item t) {
		this.t = t;
	}
	public int getQuantity() {
		return Quantity;
	}
	public void setQuantity(int quantity) {
		Quantity = quantity;
	}
	int Quantity;
}

class ItemCatalog
{
	static TreeMap<String,Double> m ;
	static
	{
		m = new TreeMap<String,Double>();
		m.put("Pencil", 12.50);
		m.put("Pen", 24.0);
		m.put("Book", 75.50);
	}
	
	static double CheckAvailability(String desc)
	{
		
		double rate=0.0;
		Set s1 = m.entrySet();
		Iterator t = s1.iterator();
		while(t.hasNext())
		{
			Map.Entry<String, Double> e = (Map.Entry<String, Double>)t.next();
			String str = e.getKey();
			if(str.equalsIgnoreCase(desc))
			{
				rate = e.getValue();
				break;
			}
		} 
		return rate;
	}
	static void dispAvailableItems()
	{
		System.out.println("Items Available Are");
		Set s1 = m.entrySet();
		Iterator t = s1.iterator();
		while(t.hasNext())
		{
			Map.Entry<String, Double> e = (Map.Entry<String, Double>)t.next();
			String str = e.getKey();
			double rate = e.getValue();
			System.out.println(str+"\t"+rate);
		}
	}
}
class SaleList
{
	ArrayList<SaleItem> a = new ArrayList<SaleItem>();
	void addItems()
	{
		String desc;
		int quan,choice;
		double rate;
		ItemCatalog.dispAvailableItems();
		System.out.println("----------------------------------------------------");
		do
		{
			System.out.println("enter the required item desc and quantity");
			Scanner s = new Scanner(System.in);
			desc = s.next();
			quan = s.nextInt();
			rate = ItemCatalog.CheckAvailability(desc);
			if(rate == 0.0)
				System.out.println("Item does not exists");
			else
			{
				Item t1 = new Item();
				t1.setDesc(desc);
				t1.setRate(rate);
				SaleItem t = new SaleItem();
				t.setQuantity(quan);
				t.setT(t1);
				a.add(t);
			}
			System.out.println("enter 1 to add one more item");
			choice = s.nextInt();
			System.out.println("----------------------------------------------------");
			
		}while(choice==1);
	}
	void CalcGrandTotal()
	{
		SaleItem st=null;
		Item t=null;
		double grandTotal = 0.0,TotalItemCost=0.0;
		System.out.println("----------------------------------------------------");
		System.out.println("                       Bill                         ");
		System.out.println("----------------------------------------------------");
		
		for(int i=0;i<a.size();i++)
		{
			st = a.get(i);
			t = st.getT();
			TotalItemCost = (t.getRate()*st.getQuantity());
			System.out.println(t.getDesc()+"\t"+t.getRate()+"\t"+st.getQuantity()+"\t"+TotalItemCost);
			grandTotal +=TotalItemCost ;
			
		}
		System.out.println("Grandtotal:"+grandTotal);
	}
}

class SaleListThread extends Thread
{
	String name;
	SaleList l;
	
	SaleListThread(String n,SaleList l)
	{
		
		name = n;
		this.l=l;
		start();
	}
	public void run()
	{
		System.out.println(name +" task begins");
		l.addItems();
		System.out.println(name +" task ended");
	}
}
public class POS {
	public static void main(String[] args)throws InterruptedException {
		SaleList l = new SaleList();
		SaleListThread t = new SaleListThread("ChilThread",l);
		t.join();
		System.out.println(Thread.currentThread().getName() +" thread task begins");
		l.CalcGrandTotal();
		System.out.println(Thread.currentThread().getName() +" thread task ended");
	}

}





