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

    public NativeTestClass(int id, String name){
        this.id = id;
        this.name = name;
    }

    public native void getAndSetField();

    public void show(){
        Log.i(this.getClass().getSimpleName(), "id = " + id + ", name = " + name);
    }
}
