package com.example;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/test")
public class Simple extends HttpServlet
{
    private static final long serialVersionUID = -4514173519833365614L;

    private static final Logger logger = Logger.getLogger(Simple.class.getName());

    @Override
    protected void service(final HttpServletRequest request, final HttpServletResponse response)
                    throws ServletException, IOException
    {
        if (logger.isLoggable(Level.FINER))
        {
            logger.entering(Simple.class.getName(), "service", new Object[] { request, response });
        }

        PrintWriter out = response.getWriter();
        out.println("Hello World @ " + new java.util.Date());

        out.println("\nJNI result: " + NativeWrapper.testNativeMethod(request.getParameter("test")));

        if (logger.isLoggable(Level.FINER))
        {
            logger.exiting(Simple.class.getName(), "service");
        }
    }
}
