package DictionaryDemo;
import java.util.*;
import java.util.Map.Entry;

class Dictionary
{
	TreeMap<String, ArrayList<String>> tm = new TreeMap<String, ArrayList<String>>();
	
	public void AddInfo()
	{
		Information info= new Information();
		ArrayList<String> a = info.getAr();
		String w=info.getWord();
		int MeaningCount=0;
		Scanner sc = new Scanner(System.in);
		System.out.println("enter a word");
		w = sc.next();
		System.out.println("enter the number of meanings");
		MeaningCount = sc.nextInt();
		for(int i=0;i<MeaningCount;i++)
		{
			System.out.println("enter the meaning");
			a.add(sc.next());
		}
		info.setWord(w);
		info.setAr(a);
		tm.put(w,a);
		
	}
	
	
	public void dispDetails()
	{
		ArrayList<String> a=null;
		Set<Entry<String, ArrayList<String>>> s = tm.entrySet();
		Iterator<Entry<String, ArrayList<String>>> t = s.iterator();
		while(t.hasNext())
		{
			Map.Entry<String, ArrayList<String>> e = t.next();
			
			System.out.println("Word:"+e.getKey());
			a = e.getValue();
			System.out.println("Meanings are:");
			for(int i=0;i<a.size();i++)
				System.out.print(a.get(i)+" ");
			System.out.println();
			System.out.println("---------------");
		}
	}
	
	
	public void search()
	{
		Scanner sc = new Scanner(System.in);
		String word=null,w=null;
		System.out.println("enter the word to search");
		word = sc.next();
		int status=0;
		
		ArrayList<String> a=null;
		Set<Entry<String, ArrayList<String>>> s = tm.entrySet();
		Iterator<Entry<String, ArrayList<String>>> t = s.iterator();
		while(t.hasNext())
		{
			Map.Entry<String, ArrayList<String>> e = t.next();
			
			w = (String)e.getKey();
			if(w.equalsIgnoreCase(word))
			{
				status=1;
				System.out.println("word is found");
				a = (ArrayList<String>)e.getValue();
				System.out.println("Meanings are:");
				for(int i=0;i<a.size();i++)
					System.out.print(a.get(i)+" ");
				System.out.println();
				System.out.println("---------------");
				break;
			}
		}
		if(status==0)
			System.out.println("word not existing");
	}
}

class Information
{
	String word;
	public void setWord(String word) {
		this.word = word;
	}

	public void setAr(ArrayList<String> ar) {
		this.ar = ar;
	}

	public String getWord() {
		return word;
	}

	public ArrayList<String> getAr() {
		return ar;
	}

	ArrayList<String> ar = new ArrayList<String>();
	
}
public class DictionaryCode {
	public static void main(String[] args) {
		Dictionary d = new Dictionary();
		int choice=0;
		do
		{
			System.out.println("1:Add 2:display 3:Search");
			System.out.println("enter your choice");
			Scanner sc = new Scanner(System.in);
			choice = sc.nextInt();
			switch(choice)
			{
			case 1:
				d.AddInfo();
				break;
			case 2:
				d.dispDetails();
				break;
			case 3:
				d.search();
				break;
			}
			System.out.println("enter 1 to continue");
			choice=sc.nextInt();
		}while(choice==1);
		
	}

}
