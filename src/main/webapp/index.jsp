<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="java.util.*, java.net.*" %>
<!DOCTYPE html>
<html>
  <head>
    <title>Hello World</title>
    <meta charset="UTF-8">
  </head>
  <body>
    <h1>Hello World</h1>
    <p>Current Time:</p>
    <p>
    <%
    out.println(new Date() + " @ " + InetAddress.getLocalHost());
    %>
    </p>
  </body>
</html>
