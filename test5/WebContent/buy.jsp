<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" import="java.util.*" import="java.sql.*"%>
<%@page import="test5.product"%>
<%@page import="test5.Product_clo"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>我的购物车</title>
<style type="text/css">
body {
	background-color: #FFCCCC;
}
 
th, td {
	text-align: center;
}
</style>
 
<script type="text/javascript">
	function updateNum(id, num, price) {
		var quantity=document.getElementById("quantity").value;
		var qua = parseInt(quantity);
		var n = parseInt(num);
		var reg=/^[0-9]*[1-9][0-9]*$/;//只能输入正整数的正则表达式
		if(!reg.test(num)){
			alert("只能输入正整数！");
			num=1;
		}
		if(n>qua){
			alert("库存不足！");
			num=1;
		}
		  var url = "shopcart.jsp?op=update&id=" + id + "&num=" + num + "&price="
				+ price;
		window.location = url;    
	}
	//其实这复选框功能在这个实验并卵用，我没有太多的精力去实验了。这个复选框可以不要的
	//按全选框则选择所有复选框
	function selectAll() {
		var oInput = document.getElementsByName("cartCheckBox");
		for (var i = 0; i < oInput.length; i++) {
			oInput[i].checked = document.getElementById("allCheckBox").checked;
		}
	}
	//如果有其中一个没有被选中，则取消全选框，或全部复选框选中，则全选框也选中
	function selectSingle() {
		var k = 0;
		var oInput = document.getElementsByName("cartCheckBox");
		for (var i = 0; i < oInput.length; i++) {
			if (oInput[i].checked == false) {
				k = 1;
				break;
			}
		}
		if (k == 0) {
			document.getElementById("allCheckBox").checked = true;
		} else {
			document.getElementById("allCheckBox").checked = false;
		}
	}
</script>
</head>
<body>
	<h2>我的购物车</h2>
	<hr>
	<jsp:useBean id="db" scope="application"
		class="test5.DataBaseConnection"></jsp:useBean>
	<form method="post" action="pay.jsp">
		<table style="width:600px; background-color:#FFCCCC">
	<%!int total=0;int s; %>
			<tr>
				<td class="title_1"><input id="allCheckBox" type="checkbox"
					value="" οnclick="selectAll()" />全选</td>
				<td>商品名称</td>
				<td>商品单价</td>
				<td>购买数量</td>
				<td>购买金额</td>
				<td>编辑</td>
				<td></td>
			</tr>
			<%
				try {
					int quantity = 0;
					ResultSet rs = null;
					Connection conn = null;
					PreparedStatement stmt = null;
					Statement stmts = null;
					String id = null;String sql=null;
					String inputid = null;
					conn = db.getConnection();
					Product_clo clo = new Product_clo();
					ArrayList<product> list = clo.getAllProduct();
					if (list != null && list.size() > 0) {
						for (int i = 0; i < list.size(); i++) {
							product pro = list.get(i);
							quantity = pro.getQuantity();
						}
					}
					
					sql = "select * from shopcart;";
					stmt = conn.prepareStatement(sql);
					rs = stmt.executeQuery();
					int t = 0;
					String name = null;
					String price = null;
					int num = 0;
					String totalprice = null;
					int to;
					while (rs.next()) {
						//显示在购物车里到商品信息
						id = rs.getString("product_id");
						name = rs.getString("product_name");
						price = rs.getString("product_price");
						num = rs.getInt("product_quantity");
						totalprice = rs.getString("totalprice");
						
			%>
			<tr>
				<td class="cart_td_1"><input name="cartCheckBox"
					type="checkbox" value="product1" οnclick="selectSingle()" /></td>
				<td><%=name%></td>
				<td align="center"><%=price%></td>
				<%
							out.println("<td><input type=text size=8 name=num id=num value=" + num + " onChange=\"updateNum('" + id + "',this.value,'"
									+ price + "')\" ></td>");
				%>
				<td><%=totalprice%></td>
				<td><a href='shopcart.jsp?op=del&id=<%=id%>'>删除</a></td>
				<td><input type="hidden" name="quantity" id="quantity"
					value="<%=quantity%>" /></td>
			</tr>
 
			<%
				}
					sql = "select sum(totalprice) from shopcart;";//算全部商品总价
					stmts = conn.createStatement();
					rs = stmts.executeQuery(sql);
					while (rs.next()) {
						total=rs.getInt(1);
					}
					session.setAttribute("total",total);
					 s=(Integer)session.getAttribute("total");
			%>
			</tr>
			<%
				stmt.close();
					//关闭数据库连接
					conn.close();
				} catch (Exception ex) {
					ex.printStackTrace();
				}
			%>
			
			
			<% %>
		</table>
		<img alt=""  width="50" hight="50">
		商品总价：<%=s%> 元
		<input type="submit" value="立即购买"  /> 
		
	</form>
 
	<br>
	<a href="frame.jsp">继续购物</a>
	<a href="shopcart.jsp?op=clear">清空购物车</a>
</body>
</html>
