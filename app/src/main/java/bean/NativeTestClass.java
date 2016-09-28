package bean;

import android.util.Log;

/**
 * bean
 * [function]
 * [detail]
 * Created by Sky on 2016/9/23.
 * modify by
 */

public class NativeTestClass {

    private static final String TAG = "NativeTestClass";

    private int id;

    private String name;

    private User user;

    private int[] number = {1, 2, 3, 4};

    public String[] strings = {"stl", "c++", "c11", "debug"};

    private User[] childrenUsers = {new User(1, "1"), new User(2, "2"), new User(3, "3"), new
            User(4, "4")};

    public NativeTestClass(int id, String name, User user) {
        this.id = id;
        this.name = name;
        this.user = user;
    }

    /**
     * 测试获取与设置基本字段和String字段
     */
    public native void getAndSetField();

    /**
     * 测试获取与设置对象字段
     */
    public native void getAndSetObjectField();

    /**
     * native调用java层show方法
     */
    public native void nativeShow();

    /**
     * 测试native层获取java层数组，并设置新的值
     */
    public native void getAndSetIntArray();

    /**
     * 获取和设置对象数组的值
     * */
    public native void getAndSetStringArray(String[] strings);

    /**
     * 打印所有的数据
     * */
    public void show() {
        Log.i(TAG, "id = " + id + ", name = " + name + ", user = " + user);
        printArray();
    }

    public void printArray(){
        StringBuilder toString = new StringBuilder();
        for (int i = 0; i < number.length; i++) {
            toString.append("number[" + i + "] = " + number[i] + "\n");
        }
        Log.i(TAG, toString.toString());
    }

    public void printString(){
        StringBuilder toString = new StringBuilder();
        for (int i = 0; i < strings.length; i++) {
            toString.append("number[" + i + "] = " + strings[i] + "\n");
        }
        Log.i(TAG, toString.toString());
    }
}
