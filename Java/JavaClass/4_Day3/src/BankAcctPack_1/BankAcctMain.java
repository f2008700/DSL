package BankAcctPack_1;
import java.util.Scanner;

class Account
{
	private int AcctNo;
	public int getAcctNo() {
		return AcctNo;
	}
	public String getAcctType() {
		return AcctType;
	}
	public double getAcctBal() {
		return AcctBal;
	}
	private String AcctType;
	private  double AcctBal;
	public Account(String type, double bal,int ano)
	{
		AcctNo = ano;
		AcctType = type;
		AcctBal = bal;
	}
}
class Bank
{
	Account a[];
	static int AcctCount;
	static Bank b;
	static
	{
		b=null;
		
		AcctCount=0;
	}
	private Bank()
	{a = new Account[100];}
	static Bank getInstance()
	{
		if(b==null)
			b = new Bank();
		return b;
	}
	public void CreateAccount()
	{
		Scanner s = new Scanner(System.in);
		System.out.println("enter the AcctType and OpenBal");
		String type = s.next();
		double bal = s.nextDouble();
		a[AcctCount] = new Account(type,bal,(AcctCount+1));
		AcctCount++;
		
		
	}
	public void dispAcctDetails()
	{
		for(int i=0;i<AcctCount;i++)
		System.out.println(a[i].getAcctType() +"  "+a[i].getAcctNo()+"  "+a[i].getAcctBal());
	}
	public void searchByAcctNo()
	{
		boolean status=false;
		Scanner s = new Scanner(System.in);
		System.out.println("enter the acctno");
		int ano = s.nextInt();
		for(int i=0;i<AcctCount;i++)
		{
			if(a[i].getAcctNo() == ano)
			{
				status=true;
				System.out.println("Account with AccountNo "+ano+" is found");
				System.out.println(a[i].getAcctType() +"  "+a[i].getAcctNo()+"  "+a[i].getAcctBal());
				break;
			}
		}
		if(status==false)
			System.out.println("Account with AccountNo "+ano+" is not found");	
	}
	
}
public class BankAcctMain {
	public static void main(String[] args) {
		
		
		Scanner s = new Scanner(System.in);
		int choice;
		Bank b = Bank.getInstance();
		do
		{
			System.out.println("1:Create 2:Display 3:Search");
			System.out.println("enter your choice");
			choice = s.nextInt();
			switch(choice)
			{
			case 1:
				b.CreateAccount();
				break;
				
			case 2:
				b.dispAcctDetails();
				break;
				
			case 3:
				b.searchByAcctNo();
				break;
			}
			System.out.println("enter 1 to continue");
			choice=s.nextInt();
		}while(choice==1);
	}

}

