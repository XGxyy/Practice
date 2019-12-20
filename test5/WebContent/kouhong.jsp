<%@page import="test5.product"%>
<%@page import="test5.Product_clo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>在线购物</title>
<style type="text/css">
body {
	background-color: #FFCCCC;
}
 
img {
	width: 300px;
	height: 400px;
}
</style>
 
</head>
<body>
	<jsp:useBean id="db" scope="application"
		class="test5.DataBaseConnection"></jsp:useBean>
	<form action="shopcart.jsp?op=add" method="post">
		<table>
			<tr>
				<!-- 遍历商品全部信息 -->
				<%
					String op, name, type, msg;
					int price, quantity;
					int id;
					Product_clo clo = new Product_clo();
					ArrayList<product> list = clo.getAllProduct();
					if (list != null && list.size() > 0) {
						for (int i = 2; i < 3; i++) {
							product pro = list.get(i);
							session.setAttribute("id",pro.getId()); 
							session.setAttribute("name", pro.getName());
							session.setAttribute("price", pro.getPrice());
							
						    id = pro.getId();
							name = pro.getName();
							price = pro.getPrice();
							type = pro.getType();
							msg = pro.getMsg();
							quantity = pro.getQuantity(); 
				%><td><td><li><a href="frame.jsp">返回首页</a></li><br>
				<img alt="商品图片" src="images/<%=pro.getPicture()%>"></td>
				<td>
					<dd>商品ID：<%=id%></dd>	<br>
					<dd>商品名称：<%=name%></dd>	<br>
					<dd>商品价格：<%=price%></dd>	<br>
					<dd>商品类型：<%=type%></dd>	<br>
					<dd>商品介绍：<%=msg%></dd> <br>
					<dd>商品库存：<%=quantity%></dd><br> 
				    <dd><input type="submit"  value="加入购物车"> </dd> <br> 
					   
 
 
				</td>
 
			</tr>
			<%
				}
				}
			%>
		</table>
		<br>
	</form>
 
</body>
</html>

 