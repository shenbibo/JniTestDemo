package com.study.sky.jnitestdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import bean.NativeTestClass;
import bean.User;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        NativeTestClass testClass =
                new NativeTestClass(123, "shenbibo", new User(456, "java string name"));

        //获取并设置对象字段
        testClass.getAndSetField();
        testClass.getAndSetObjectField();
        testClass.nativeShow();

        //获取并设置Int数组字段
        testClass.getAndSetIntArray();
        testClass.nativeShow();

        //获取并设置String数组字段
        testClass.getAndSetStringArray(testClass.strings);
        testClass.printString();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
