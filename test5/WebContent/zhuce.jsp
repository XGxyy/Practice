<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>

<html lang="en" class="no-js">

    <head>

        <meta charset="utf-8">
        <title>注册页面(sign in)</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta name="description" content="">
        <meta name="author" content="">

        <!-- CSS -->
        <link rel="stylesheet" href="assets/css/reset.css">
        <link rel="stylesheet" href="assets/css/supersized.css">
        <link rel="stylesheet" href="assets/css/style.css">

        <!-- HTML5 shim, for IE6-8 support of HTML5 elements -->
        <!--[if lt IE 9]>
            <script src="assets/js/html5.js"></script>
        <![endif]-->
	

    </head>

    <body>

        <div class="page-container">
            <h1>注册(sign in)</h1>
            <form action="jiancha.jsp" method="post">
          
                <input type="text" name="name" class="username" placeholder="请输入您的用户名！">
                <input type="password" name="pwd" class="password" placeholder="请输入您的用户密码！">               
                <input type="password" name="pwd1" class="password" placeholder="再次确认密码！">    
                <div class="error"><span>+</span></div>
                <button type="submit" class="submit_button">确认注册</button>
                <button type="button" class="submit_button" onclick="javascript:top.location='login.html';" >有账号去登录 </button>
             </form>
            
           
        </div>
		
        <!-- Javascript -->
        <script src="assets/js/jquery-1.8.2.min.js" ></script>
        <script src="assets/js/supersized.3.2.7.min.js" ></script>
        <script src="assets/js/supersized-init.js" ></script>
        <script src="assets/js/scripts.js" ></script>

    </body>



</html>



