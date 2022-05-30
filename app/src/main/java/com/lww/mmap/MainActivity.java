package com.lww.mmap;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.lww.mmap.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'mmap' library on application startup.
    static {
        System.loadLibrary("mmap");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
        binding.sampleText.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                JNIDemo jniDemo = new JNIDemo();
                jniDemo.wiite();

            }
        });
    }

    /**
     * A native method that is implemented by the 'mmap' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    public void dump(View view) {
        startActivity(new Intent(MainActivity.this,MainActivity2.class));
    }
}