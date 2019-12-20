<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import="test5.RegisterDao" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
request.setCharacterEncoding("utf-8");
String name=request.getParameter("name");
String pwd=request.getParameter("pwd");
String pwd1=request.getParameter("pwd1");
RegisterDao re=new RegisterDao();
int count=re.register(name,pwd,pwd1);
if(count==1&&name.length()>=1&&name.length()<=6&&pwd.length()>=4&&pwd.equals(pwd1))
{
	   %>
		<a href="login.html"><font color="pink" size="8px">注册成功点此登录</font></a>
		<%
}
else if(count==0)
{
	
	
	 if(name.length()>=1&&name.length()<=6&&pwd.length()>=4&&!pwd.equals(pwd1))
	{
		%>
		<a href="zhuce.jsp"><font color="green" size="6px">再次输入密码不一致点此返回上一级</font></a>
		<%
	}
	else
	{
       %>
		<a href="zhuce.jsp"><font color="green" size="6px">用户名重复或者用户名密码不符合要求点此返回上一级</font></a>
		<%
	}
	
}
 
 
%>
</body>
</html>
