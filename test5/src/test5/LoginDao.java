package test5;
import java.sql.*;
public class LoginDao {
public boolean login(String name,String pwd) throws ClassNotFoundException, SQLException
{
	
	Statement st=null;
	Connection conn=null;
	ResultSet rs=null;
	PreparedStatement ps=null;
	boolean flag=false;
	try {
		 Class.forName("com.mysql.cj.jdbc.Driver");
			//2.获取数据库连接
			String url="jdbc:mysql://localhost:3306/db_01?useSSL=false&serverTimezone=Asia/Shanghai";
			String user="root";
			String password="xmh1998";
		conn=DriverManager.getConnection(url, user, password);
		//3.获取数据库操作对象
		
		String sql="select username from user where username= ? and password = ?";
		//sql语句进行预编译
		ps=conn.prepareStatement(sql);
		//对sql语句进行赋值
		ps.setString(1, name);
		ps.setString(2, pwd);
		rs=ps.executeQuery();
		
		if(rs.next())
		{
			flag=true;
		}
	} catch (SQLException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}finally
	 {
		if(rs!=null)
		{
			rs.close();
		}
		if(ps!=null)
		{
			
			ps.close();
		}
		if(conn!=null)
		{
			conn.close();
		}
	 }
	return flag;
}
}
