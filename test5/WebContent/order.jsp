<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@page import="test5.product" import="java.util.*" import="java.sql.*"%>
<%@page import="test5.Product_clo" import="java.util.Date"%>
<%@page import="java.text.SimpleDateFormat"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>我的订单</title>
<style>
table {
	margin: 0 auto;
	width: 300px;
	border: 1px solid red;
	border-collapse: collapse;
}
 
th, td {
	text-align: center;
	border: 1px solid green;
}
</style>
</head>
<body>
	<jsp:useBean id="db" scope="application"
		class="test5.DataBaseConnection"></jsp:useBean>
	<%!int total;%>
	<%
		//获取订单生成的时间
		Date date = new Date();
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		String dd = format.format(date);
		session.setAttribute("payDate", dd);
		String d = (String) session.getAttribute("payDate");
	%>
	<table style="width: 600px; background-color: #FFCCCC">
		<tr>
			<td colspan="4"><%=d%>您的订单如下：</td>
		</tr>
		<tr>
			<td>商品名称</td>
			<td>商品单价</td>
			<td>购买数量</td>
			<td>商品价格</td>
		</tr>
		<%
			//取商品信息值
			String name = null;
			ResultSet rs = null;
			Connection conn = null;
			PreparedStatement stmt = null;
			conn = db.getConnection();
			//String sql="insert into order select * from shop.shopcart;";
			String sql = "insert into order(product_id,product_name,product_price,product_num,product_total) select product_id,product_name,product_price,product_quantity,totalprice from shopcart;";
			stmt = conn.prepareStatement(sql);
			stmt.executeUpdate();
			//String name = null;
			sql = "select * from shop.order;";
			stmt = conn.prepareStatement(sql);
			rs = stmt.executeQuery();
			int price = 0;
			int num = 0;
			int totalprice = 0;
			int id = 0;int pronum=0;
		%>
		<%
			while (rs.next()) {
				//显示在购物车里到商品信息
				id=rs.getInt("product_id");
				name = rs.getString("product_name");
				price = rs.getInt("product_price");
				num = rs.getInt("product_num");
				totalprice = rs.getInt("product_total");
				//商品表的库存也要更新
				sql = "select product_quantity from product where product_id="+id;
				stmt = conn.prepareStatement(sql);
				rs=stmt.executeQuery(sql);
				while(rs.next()){
					pronum=rs.getInt(1);
				}
				
				
				sql = "update product set product_quantity = ?  where product_id=?;";
				stmt = conn.prepareStatement(sql);
				stmt.setInt(1, pronum-num);
				stmt.setInt(2, id);
				stmt.executeUpdate();
		%>
 
		<tr>
			<td style="width: 200px;"><%=name%></td>
			<td style="width: 200px;"><%=price%></td>
			<td style="width: 200px;"><%=num%></td>
			<td style="width: 200px;"><%=totalprice%></td>
		</tr>
		<%
			}
		%>
		<tr>
			<td colspan="4">总价?：<%=session.getAttribute("total")%>元
			</td>
		</tr>
	</table>
	<%
		//加入订单表我的购物车表自然要清空了
		sql = "delete from shopcart";
		stmt = conn.prepareStatement(sql);
		stmt.executeUpdate();
		stmt.close();
		//关闭数据库连接
		conn.close();
	%>
	<div align="center">
		<a href="frame.jsp">继续购物</a>
	</div>
</body>
</html>
