<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" import="java.util.*" import="java.sql.*"%>
<%@page import="test5.product"%>
<%@page import="test5.Product_clo"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>我的购物车</title>
</head>
<body>
	<jsp:useBean id="db" scope="application"
		class="test5.DataBaseConnection"></jsp:useBean>
	<%
	
	
	//String proid=request.getParameter("id");
 	//String proname=request.getParameter("name");
 	//String proprice=request.getParameter("price");
 
		String proid= session.getAttribute("id").toString(); //从购物页面获取的商品id
		String proname= session.getAttribute("name").toString(); //从购物页面获取的商品name	
		String proprice= session.getAttribute("price").toString(); //从购物页面获取的商品price
		String op = request.getParameter("op");
		ResultSet rs = null;
		Connection conn = null;
		PreparedStatement stmt = null;
		conn = db.getConnection();
		Product_clo clo = new Product_clo();
		String sql = null;
		ArrayList<Integer> list = new ArrayList();
		try {
			//将所选商品加入购物车表中
			if (op.equals("add")) {
				list = clo.getCartId();//链表存的是购物车商品的id
				int pid = 0;
				int num = 0;
				int totalprice = 0;
				pid = Integer.parseInt(proid);//从购物页面传过来的id，强转int后面好比较
				int cartid = 0;
				int price = 0;
				if (list.contains(pid)) {//如果链表里有，那说明该商品已经存在于购物车，在数量上加1即可
					//得先从购物车把该商品id的相关的数量和价格查询出来
					sql = "select product_price,product_quantity from shopcart where product_id="+pid;
					stmt = conn.prepareStatement(sql);
					rs = stmt.executeQuery(sql);
					while(rs.next()){
						price = rs.getInt(1);
						num = rs.getInt(2);
					}
					num = num + 1;//再此基础上加1
					totalprice = price * num;//更新该商品的总价
					sql = "update shopcart set product_quantity = ?, totalprice = ?  where product_id=?;";
					stmt = conn.prepareStatement(sql);
					stmt.setInt(1, num);
					stmt.setInt(2, totalprice);
					stmt.setInt(3, pid);
					stmt.executeUpdate();
					out.print("pid = cartid");
					response.sendRedirect("buy.jsp");//重定向到购物车
					stmt.close();
					conn.close();
				} else {//没有购物车匹配不到该商品则直接插入
					sql = "insert into shopcart(product_id,product_name,product_price,product_quantity,totalprice) values(?,?,?,?,?);";
					stmt = conn.prepareStatement(sql);
					stmt.setString(1, proid);
					stmt.setString(2, proname);
					stmt.setString(3, proprice);
					stmt.setInt(4, 1);
					stmt.setString(5, proprice);
					stmt.executeUpdate();
					stmt.close();
					conn.close();
					response.sendRedirect("buy.jsp");
				}
			}
			//在购物车中删除商品
			if (op.equals("del")) {
				int id = Integer.parseInt(request.getParameter("id"));
				sql = "delete from shopcart where product_id=?;";
				stmt = conn.prepareStatement(sql);
				stmt.setInt(1, id);
				stmt.executeUpdate();
				stmt.close();
				conn.close();
				response.sendRedirect("buy.jsp");
			}
			//更改商品的数量
			if (op.equals("update")) {
				int totalprice = 0;
				int total = 0;
				int id = Integer.parseInt(request.getParameter("id"));
				int num = Integer.parseInt(request.getParameter("num"));
				int price = Integer.parseInt(request.getParameter("price"));
				totalprice = price * num;
				sql = "update shopcart set product_quantity = ?, totalprice = ?  where product_id=?;";
				stmt = conn.prepareStatement(sql);
				stmt.setInt(1, num);
				stmt.setInt(2, totalprice);
				stmt.setInt(3, id);
				stmt.executeUpdate();
				stmt.close();
				conn.close();
				response.sendRedirect("buy.jsp");
			}
			//清空购物车
			if (op.equals("clear")) {
				sql = "delete from shopcart;";
				stmt = conn.prepareStatement(sql);
				stmt.executeUpdate();
				stmt.close();
				//关闭数据库连接
				conn.close();
				//重定向到购物车页面
				response.sendRedirect("buy.jsp");
			}
 
		} catch (
 
		Exception ex) {
			ex.printStackTrace();
		}
	%>
</body>
</html>
