class Account
{
	String AcctType;
	int AcctBal;
	
	Account(String type,int bal)
	{
		AcctType = type;
		AcctBal = bal;
	}
	void dispAcctDetails()
	{
		System.out.println(AcctType+"\t"+AcctBal);
	}
}
public class AccountDemo {
	public static void main(String[] args) {
		Account a = new Account("Savings",1200);
		a.dispAcctDetails();
	}

}
