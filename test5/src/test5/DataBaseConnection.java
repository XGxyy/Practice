package test5;
import java.sql.*;
 
 
public class DataBaseConnection {
	 private static Connection conn=null;//数据库的连接对象
	    private Statement stmt=null;//创建Statement对象
	
		
	/*
	private static String driverStr="com.mysql.cj.jdbc.Driver";//驱动列表	
	private static String connStr="jdbc:mysql://localhost:3306/db_01";//db_01是我自己的数据库名
    private static String dbusername="root";//数据库用户名
    private static String dbpassword="xmh1998";//密码和数据库一致      */ 
   
	public DataBaseConnection() {		}
//一个静态方法，返回一个数据库的连接，这样达到了对数据库连接统一控制的目的
	public static Connection getConnection() throws SQLException {
		try{
			Class.forName("com.mysql.cj.jdbc.Driver");
			//2.获取数据库连接
			String url="jdbc:mysql://localhost:3306/db_01?useSSL=false&serverTimezone=Asia/Shanghai";
			String user="root";
			String password="xmh1998";
		conn=DriverManager.getConnection(url, user, password);
			//连接数据库			
		}
		catch(Exception ex){System.out.println("无法同数据库建立连接！");}		
		return conn;
	}
	public int executeUpdate(String s)
	{
	    int result=0;
	    try{
	    	stmt = conn.createStatement();//创建Statement语句
	    	result=stmt.executeUpdate(s);//执行更新语句
	    	}
	    catch(Exception ex){System.out.println("执行更新错误！");}
	    return result;
	}
	public ResultSet executeQuery(String s)
	{
		ResultSet rs=null;
		try{rs=stmt.executeQuery(s);}//执行查询语句
		catch(Exception ex){System.out.println("执行查询错误！");}
		return rs;
	}
	public void close()//关闭与数据库的连接
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
				System.out.println("连接数据库正常");
			}
			else {
				System.out.println("连接数据库异常");
			}
		} catch (Exception ex) {
			// TODO: handle exception
			ex.printStackTrace();
		}
	}
	
}
