package AccountDemo;


import java.util.Scanner;

class Account
{
	int AcctNo;
	

	public int getAcctNo() {
		return AcctNo;
	}

	public String getAcctType() {
		return AcctType;
	}

	public double getAcctBal() {
		return AcctBal;
	}
	String AcctType;
	double AcctBal;
	public Account(String type, double bal,int ano)
	{
		AcctNo = ano;
		AcctType = type;
		AcctBal = bal;
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
				
				System.out.println("enter the AcctType and OpenBal");
				String type = s.next();
				double bal = s.nextDouble();
				a[ano] = new Account(type,bal,(ano+1));
				ano++;
				break;
				
			case 2:
				for(int i=0;i<ano;i++)
					System.out.println(a[i].getAcctType() +"  "+a[i].getAcctNo()+"  "+a[i].getAcctBal());
				break;
				
			case 3:
				boolean status=false;
				
				
				System.out.println("enter the acctno");
				int no = s.nextInt();
				for(int i=0;i<ano;i++)
				{
					if(a[i].getAcctNo() == no)
					{
						status=true;
						System.out.println("Account with AccountNo "+no+" is found");
						System.out.println(a[i].getAcctType() +"  "+a[i].getAcctNo()+"  "+a[i].getAcctBal());
						break;
					}
				}
				if(status==false)
					System.out.println("Account with AccountNo "+no+" is not found");	
				break;
			}
			System.out.println("enter 1 to continue");
			choice=s.nextInt();
		}while(choice==1);
	}

}

