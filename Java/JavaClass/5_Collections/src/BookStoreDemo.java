import java.util.*;

class Book
{
	private String BookTitle;
	public String getBookTitle() {
		return BookTitle;
	}

	public double getBookCost() {
		return BookCost;
	}

	public int getBookQuantity() {
		return BookQuantity;
	}

	private double BookCost;
	private int BookQuantity;
	
	public Book(String BookTitle,double BookCost,int BookQuantity)
	{
		this.BookCost = BookCost;
		this.BookQuantity = BookQuantity;
		this.BookTitle = BookTitle;
	}
	public String toString()
	{
		return getBookTitle()+"\t"+getBookCost()+"\t"+getBookQuantity();
	}
}
class BookStore
{
	//Book b[]=new Book[5];
	ArrayList a= new ArrayList();
	static int BookCount;
	static
	{
		BookCount=0;
	}
	public void AddBook()
	{
		System.out.println("enter the title,cost and quantity");
		Scanner sc = new Scanner(System.in);
		String name = sc.next();
		double cost = sc.nextDouble();
		int quan = sc.nextInt();
		//b[BookCount]=new Book(name,cost,quan);
		a.add(new Book(name,cost,quan));
		BookCount++;
	}
	
	public void dispBookDetails()
	{
		//for(int i=0;i<BookCount;i++)
		//	System.out.println(b[i].getBookTitle()+"\t"+b[i].getBookCost()+"\t"+b[i].getBookQuantity());
		Book b1=null;
		//Method1
		/*
		for(int i=0;i<a.size();i++)
		{
			b1 = (Book)a.get(i);
			System.out.println(b1.getBookTitle()+"\t"+b1.getBookCost()+"\t"+b1.getBookQuantity());
		}*/
		
		Iterator  t = a.iterator();
		while(t.hasNext())
		{
			b1 = (Book)t.next();
		//	System.out.println(b1.getBookTitle()+"\t"+b1.getBookCost()+"\t"+b1.getBookQuantity());
			System.out.println(b1);
		}
	}
	
	public void searchBook()
	{
		int status=0;
		Book b1=null;
		System.out.println("enter the title and quantity");
		Scanner sc = new Scanner(System.in);
		String name = sc.next();
		int quan = sc.nextInt();
		for(int i=0;i<BookCount;i++)
		{
			b1 = (Book)a.get(i);
			if(b1.getBookTitle().equalsIgnoreCase(name))
			{
				status=1;
				if(b1.getBookQuantity()>=quan)
				{
					System.out.println("Book is available with sufficient stock");
					System.out.println("The Billing Cost:"+b1.getBookCost()*quan);
				}
				else
					System.out.println("Book available but stock is insufficient");
				break;
			}	
		}
		if(status==0)
			System.out.println("Book is not available");
			
	}
}
public class BookStoreDemo {
	public static void main(String[] args) {
		BookStore bs = new BookStore();
		int choice=0;
		do
		{
			System.out.println("1:AddBook 2:DispAllBooks 3:SearchForBook");
			System.out.println("enter your choice");
			Scanner sc = new Scanner(System.in);
			choice = sc.nextInt();
			switch(choice)
			{
			case 1:
				bs.AddBook();
				break;
			case 2:
				bs.dispBookDetails();
				break;
			case 3:
				bs.searchBook();
				break;
				
			}
			System.out.println("enter 1 to continue");
			choice = sc.nextInt();
		}while(choice==1);
	}

}
