<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>支付界面</title>
<style>
body {
	background-color: #FFCCCC;
	width: 400px;
	padding: 250px;
	text-align: center;
	margin: auto;
}
 
div {
	font-size: 20px;
}
</style>
</head>
<body>
 
	<%
		Integer a = (Integer) session.getAttribute("a");//账户余额
		Integer total = (Integer) session.getAttribute("total");//支付金额
		if (session.getAttribute("a") == null) {
			a = 0;
		} 
		if (a >= total) {
			a = a - total;
			session.setAttribute("a", a);
	%>
	<div>支付成功！正在生成订单...</div>
	<%
		response.setHeader("Refresh","3;url=buy.jsp"); //3秒跳转到支付订单
		} else {
	%>
	<div>
		余额不足！请充值或者返回购物车<br>
		<br> <a href="money.jsp" target="_parent">账户充值</a> <br> <br>
		<a href="buy.jsp">返回购物车</a> <br> <br>
	</div>
	<%
		}
	%>
</body>
</html>
