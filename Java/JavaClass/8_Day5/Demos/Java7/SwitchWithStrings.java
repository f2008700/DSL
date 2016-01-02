/*
Unlike theprevious versions, Java 7 supports the case labels of a switch to be of type String 
*/
public class SwitchWithStrings {
	public static void main(String[] args) {
		String Language="English";
		switch(Language)
		{
		case "English":
			System.out.println("case English");
			break;
			
		}
	}

}
