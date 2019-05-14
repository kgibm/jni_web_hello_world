package com.example;

public class NativeWrapper
{
    static {
        System.loadLibrary("NativeWrapper");
    }
    
    public static native String testNativeMethod(String str);
}
