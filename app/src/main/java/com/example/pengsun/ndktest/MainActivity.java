package com.example.pengsun.ndktest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public int number = 0;//定义一个属性

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI() + intFromJNI());

        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                LogD("befor nombuer is " + number);
//                sayHello();
//                selfHello();
                Persion p = getPersion(1, 1.78f, "sphahaha");
                LogD("p is " + p.toString());
            }
        });
    }

    private void LogD(String msg) {
        Log.d("MainActivity", msg);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    //定义一个本地方法
    public native void sayHello();

    //定义一个本地方法
    public native void selfHello();


    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native int intFromJNI();

    public native Persion getPersion(int a, float b, String c);

    public int max(int a, int b) {
        LogD("max is " + String.valueOf(a > b ? a : b));
        return a > b ? a : b;
    }

}
