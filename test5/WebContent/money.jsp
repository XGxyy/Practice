<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" import="java.util.*" import="java.lang.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>账户充值</title>
<style type="text/css">
body {
	background-color: #FFCCCC;
	width: 400px;
	padding: 250px;
	text-align: center;
	margin: auto;
}
 
</style>
 
</head>
<body>
	<form method="post" action="">
		<table align="center">
			<span style="font-size: 20px">充值金额：</span>
			<input style="font-size: 20px" type="text" name="a" size=15
				maxlength="15" οnkeyup="value=value.replace(/^(0+)|[^\d]+/g,'')">
			<input type="submit" value="确认充值">
		</table>
 
		<%
			int mo;int mon;
			if (session.getAttribute("a") == null) {
				mo = 0;mon=0;
			} else {
				 mo = (Integer) session.getAttribute("a");
			}
			String a = request.getParameter("a");//	取得文本框的值
			if (a == null || a == "") {
				a = "0";
			}
			mon = Integer.parseInt(a);
			mon = mon + mo;//账户余额叠加
			session.setAttribute("a", mon);
		%>
		<br> <br> <span style="font-size: 20px">账户余额：<%=mon%></span><br><br>
		<span style="font-size: 20px"><a href="frame.jsp" name="g">继续购物</a></span>
	<br><br>
	<span style="font-size: 20px"><a href="buy.jsp" name="f">返回购物车</a></a></span>
	</form>
</body>
</html>
