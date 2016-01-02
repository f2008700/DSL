package BankPack.AcctPack;

public class Account {
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
