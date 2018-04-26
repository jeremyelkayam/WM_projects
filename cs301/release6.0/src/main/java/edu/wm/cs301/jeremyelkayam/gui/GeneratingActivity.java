package edu.wm.cs301.jeremyelkayam.gui;

import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.Toast;

import edu.wm.cs301.jeremyelkayam.R;

public class GeneratingActivity extends AppCompatActivity {

    ProgressBar progressBar;
    String fromAMaze=AMazeActivity.robot_driver;
    Handler handler;
    int progress=0;



    private Runnable task=new Runnable() {
        @Override
        public void run() {
            final String TAG="progress: ";
            Log.v(TAG, ""+progress);
            progressBar.setProgress(progress);
            progress++;
            if(progress<=100){
                nextScreen();
            }
        }
    };


    /*
    Navigates to the next activity (PlayManual if it's a manual driver, PlayAuto if it's any other driver)
     */
    protected void nextScreen(){
        final String TAG = "next screen: ";
        if (fromAMaze.equals("Manual")){
            Log.v(TAG, "to the manual screen!");
            Intent manualplay = new Intent(GeneratingActivity.this, PlayManualActivity.class);
            manualplay.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
            startActivity(manualplay);}

        else{
            Log.v(TAG, "to the animation screen!");
            Intent animationplay = new Intent(GeneratingActivity.this, PlayAutoActivity.class);
            animationplay.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
            startActivity(animationplay);
        }
    }

    /*
    Called when screen is created. Sets up everything
     */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_generating);
        progressBar = (ProgressBar) findViewById(R.id.generationProgress);
        Handler handler = new Handler();
        //while(progress<100) {
            handler.postDelayed(task, 50);
        //}
    }
    /*
    Navigates to the next activity (PlayManual if it's a manual driver, PlayAuto if it's any other driver)
     */
    void nextScreen(final  View view){
        nextScreen();
    }

    /*
    Called when back pressed. Sends message to confirm back button press
     */
    @Override
    public void onBackPressed(){
        super.onBackPressed();
        //Toast.makeText(getBaseContext(),"Back pressed",Toast.LENGTH_SHORT).show();
        Log.v("back pressed"," so yeah");
    }


}
