package edu.wm.cs301.jeremyelkayam.gui;

import android.content.Intent;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ImageButton;
import android.widget.Switch;

import edu.wm.cs301.jeremyelkayam.R;

public class PlayAutoActivity extends AppCompatActivity {

    ImageButton playpause_button;
    boolean play_pause=true;
    Switch mapSwitch,solutionSwitch,wallsSwitch;
    Button nextScreen;

    /*
    Sets up maze. Called when maze is created
     */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_play_auto);
        playPause();
        createSwitches();

        nextScreen = (Button)findViewById(R.id.finish_maze_auto);
        nextScreen.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent mainscreen=new Intent(PlayAutoActivity.this, FinishActivity.class);

                mainscreen.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
                startActivity(mainscreen);
            }
        });
    }
    /*
        Sets up play-pause button. Called in onCreate()
      */
    public void playPause(){

        playpause_button = (ImageButton) findViewById(R.id.playPause);
        playpause_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final String TAG = "playpause";
                if (play_pause) {
                    playpause_button.setImageResource(R.drawable.ic_pause_black_24dp);
                    play_pause = false;
                    Snackbar.make(v, "Playing", Snackbar.LENGTH_SHORT).show();
                    Log.v(TAG, "Robot started");
                }
                else {
                    playpause_button.setImageResource(R.drawable.ic_play_arrow_black_24dp);
                    play_pause = true;
                    Snackbar.make(v, "Paused", Snackbar.LENGTH_SHORT).show();
                    Log.v(TAG, "Robot paused");
                }
            }
        });
    }/*
    Creates switches for showing map, solution, and visible walls.
     */
    public void createSwitches(){
        mapSwitch= (Switch) findViewById(R.id.mapSwitch);
        solutionSwitch= (Switch) findViewById(R.id.solutionSwitch);
        wallsSwitch= (Switch) findViewById(R.id.wallsSwitch);
        final String TAG="switch change:";
        Log.v(TAG,"hi");
        mapSwitch.setOnCheckedChangeListener(new Switch.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                Snackbar.make(buttonView, "switched map state", Snackbar.LENGTH_SHORT).show();
                Log.v(TAG, "map state");
            }
        });
        solutionSwitch.setOnCheckedChangeListener(new Switch.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                Snackbar.make(buttonView, "switched solution state", Snackbar.LENGTH_SHORT).show();
                Log.v(TAG, "solution state");
            }
        });
        wallsSwitch.setOnCheckedChangeListener(new Switch.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                Snackbar.make(buttonView, "switched walls state", Snackbar.LENGTH_SHORT).show();
                Log.v(TAG, "wall state");
            }
        });
    }

    @Override
    public void onBackPressed(){
        super.onBackPressed();
        //Toast.makeText(getBaseContext(),"Back pressed",Toast.LENGTH_SHORT).show();
        Log.v("back pressed"," so yeah");
    }


}
