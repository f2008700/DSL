import java.util.Scanner;

class Account
{
	int AcctNo;
	String AcctType;
	double AcctBal;
	private Account(String type, double bal,int ano)
	{
		AcctNo = ano;
		AcctType = type;
		AcctBal = bal;
	}
	
	public static Account CreateAccount(int ano)
	{
		Scanner s = new Scanner(System.in);
		System.out.println("enter the AcctType and OpenBal");
		String type = s.next();
		double bal = s.nextDouble();
		Account a = new Account(type,bal,(ano+1));
		return a;
		
	}
	public static void dispAcctDetails(Account [] a,int n)
	{
		for(int i=0;i<n;i++)
		System.out.println(a[i].AcctType +"  "+a[i].AcctNo+"  "+a[i].AcctBal);
	}
	public static void searchByAcctNo(Account []a,int n)
	{
		boolean status=false;
		Scanner s = new Scanner(System.in);
		System.out.println("enter the acctno");
		int ano = s.nextInt();
		for(int i=0;i<n;i++)
		{
			if(a[i].AcctNo == ano)
			{
				status=true;
				System.out.println("Account with AccountNo "+ano+" is found");
				System.out.println(a[i].AcctType +"  "+a[i].AcctNo+"  "+a[i].AcctBal);
				break;
			}
		}
		if(status==false)
			System.out.println("Account with AccountNo "+ano+" is not found");	
	}
	
}
public class AccountDemoAssign {
	public static void main(String[] args) {
		int ano=0;
		Account a[]=new Account[100];
		Scanner s = new Scanner(System.in);
		int choice;
		do
		{
			System.out.println("1:Create 2:Display 3:Search");
			System.out.println("enter your choice");
			choice = s.nextInt();
			switch(choice)
			{
			case 1:
				a[ano] = Account.CreateAccount(ano);
				ano++;
				break;
				
			case 2:
				Account.dispAcctDetails(a, ano);
				break;
				
			case 3:
				Account.searchByAcctNo(a, ano);
				break;
			}
			System.out.println("enter 1 to continue");
			choice=s.nextInt();
		}while(choice==1);
	}

}
