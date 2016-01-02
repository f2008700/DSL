import java.sql.*;
public class CreateDemo {
	public static void main(String[] args)
	{
		Connection con=null;
		try
		{


			    Class.forName("oracle.jdbc.driver.OracleDriver").newInstance();	
			    con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe","aaa","user123");
				System.out.println("successfully connected");
				/*Statement st = con.createStatement();
				String cs = "Create Table EMP(EmpID Number(10),EmpName varchar(20),EmpSal Number(10))";
				st.execute(cs);
				
				cs = "Insert into Emp Values(1,'Rushil',12000)";
				st.executeUpdate(cs);
				
				cs = "Insert into Emp Values(2,'Shobha',22000)";
				st.executeUpdate(cs);
				
				cs = "Insert into Emp Values(3,'kanth',32000)";
				st.executeUpdate(cs);
				
				String cs = "Update Emp set EmpSal=? Where EmpID LIKE ?";
				PreparedStatement p = con.prepareStatement(cs);
				p.setInt(1,40000);
				p.setInt(2,1);
				p.executeUpdate();				
				p.close();*/
				
				Statement st = con.createStatement();
				String cs = "Select * from Emp";
				ResultSet rs = st.executeQuery(cs);
				ResultSetMetaData rsmd = rs.getMetaData();
				while(rs.next())
				{
					for(int i=1;i<=rsmd.getColumnCount();i++)
					{
						System.out.print(rs.getString(i)+"\t");
					}
					System.out.println();
					
				}
				st.close();
				con.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
	}

}





