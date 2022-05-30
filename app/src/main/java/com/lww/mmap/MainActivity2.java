package com.lww.mmap;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Toast;

public class MainActivity2 extends AppCompatActivity {

    // Used to load the 'mmap' library on application startup.
    static {
        System.loadLibrary("mmap");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        JNIDemo jniDemo = new JNIDemo();
        Toast.makeText(this,jniDemo.read(),Toast.LENGTH_LONG).show();
    }
}