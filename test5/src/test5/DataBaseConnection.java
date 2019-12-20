package test5;
import java.sql.*;
 
 
public class DataBaseConnection {
	 private static Connection conn=null;//���ݿ�����Ӷ���
	    private Statement stmt=null;//����Statement����
	
		
	/*
	private static String driverStr="com.mysql.cj.jdbc.Driver";//�����б�	
	private static String connStr="jdbc:mysql://localhost:3306/db_01";//db_01�����Լ������ݿ���
    private static String dbusername="root";//���ݿ��û���
    private static String dbpassword="xmh1998";//��������ݿ�һ��      */ 
   
	public DataBaseConnection() {		}
//һ����̬����������һ�����ݿ�����ӣ������ﵽ�˶����ݿ�����ͳһ���Ƶ�Ŀ��
	public static Connection getConnection() throws SQLException {
		try{
			Class.forName("com.mysql.cj.jdbc.Driver");
			//2.��ȡ���ݿ�����
			String url="jdbc:mysql://localhost:3306/db_01?useSSL=false&serverTimezone=Asia/Shanghai";
			String user="root";
			String password="xmh1998";
		conn=DriverManager.getConnection(url, user, password);
			//�������ݿ�			
		}
		catch(Exception ex){System.out.println("�޷�ͬ���ݿ⽨�����ӣ�");}		
		return conn;
	}
	public int executeUpdate(String s)
	{
	    int result=0;
	    try{
	    	stmt = conn.createStatement();//����Statement���
	    	result=stmt.executeUpdate(s);//ִ�и������
	    	}
	    catch(Exception ex){System.out.println("ִ�и��´���");}
	    return result;
	}
	public ResultSet executeQuery(String s)
	{
		ResultSet rs=null;
		try{rs=stmt.executeQuery(s);}//ִ�в�ѯ���
		catch(Exception ex){System.out.println("ִ�в�ѯ����");}
		return rs;
	}
	public void close()//�ر������ݿ������
	{
		try{
			stmt.close();
			conn.close();
		}
		catch(Exception e){}
	}
	public static void main(String[] args) {
		try {
			Connection conn=DataBaseConnection.getConnection();
			if(conn!=null)
			{
				System.out.println("�������ݿ�����");
			}
			else {
				System.out.println("�������ݿ��쳣");
			}
		} catch (Exception ex) {
			// TODO: handle exception
			ex.printStackTrace();
		}
	}
	
}
