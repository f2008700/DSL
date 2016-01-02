package BankAcctMainPack;

import java.util.Scanner;
import BankPack.*;

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
