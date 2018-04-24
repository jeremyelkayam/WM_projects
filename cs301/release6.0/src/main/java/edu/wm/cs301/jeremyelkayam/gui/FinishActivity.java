package edu.wm.cs301.jeremyelkayam.gui;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import edu.wm.cs301.jeremyelkayam.R;

public class FinishActivity extends AppCompatActivity {

    Button restart;


    @Override

    /*
    Called when the activity is created. Sets up the activity's layout

    @param savedInstanceState
     */
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_finish);
        init();
    }

    /*
    Sets up the back button
     */
    public void init(){
        restart = (Button)findViewById(R.id.back2Start);
        restart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getBaseContext(),"Back pressed",Toast.LENGTH_SHORT).show();
                Log.v("back pressed"," so yeah");
                Intent mainscreen=new Intent(FinishActivity.this, AMazeActivity.class);
                mainscreen.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
                startActivity(mainscreen);
            }
        });
    }

    @Override
    public void onBackPressed(){
        super.onBackPressed();
        //Toast.makeText(getBaseContext(),"Back pressed",Toast.LENGTH_SHORT).show();

    }
}
