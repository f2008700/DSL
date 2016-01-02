package BankPack;

import java.util.Scanner;
import BankPack.AcctPack.*;

public class Bank {
	static Account a[];
	static int AcctCount;
	static Bank b;
	static
	{
		b=null;
		a = new Account[100];
		AcctCount=0;
	}
	private Bank()
	{}
	public static Bank getInstance()
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
