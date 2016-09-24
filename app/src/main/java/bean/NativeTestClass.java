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

    private int id;

    private String name;

    private User user;

    public NativeTestClass(int id, String name, User user){
        this.id = id;
        this.name = name;
        this.user = user;
    }

    /**
     * 测试获取与设置基本字段和String字段
     * */
    public native void getAndSetField();

    /**
     * 测试获取与设置对象字段
     * */
    public native void getAndSetObjectField();

    public native void nativeShow();

    public void show(){
        Log.i(this.getClass().getSimpleName(), "id = " + id + ", name = " + name + ", user = " + user);
    }
}
