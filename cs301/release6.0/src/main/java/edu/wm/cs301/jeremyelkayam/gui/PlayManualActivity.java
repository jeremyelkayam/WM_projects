package edu.wm.cs301.jeremyelkayam.gui;

import android.annotation.SuppressLint;
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
import android.widget.Toast;

import edu.wm.cs301.jeremyelkayam.R;

public class PlayManualActivity extends AppCompatActivity {

    ImageButton button_up, button_right, button_left, button_down;
    Switch mapSwitch,solutionSwitch,wallsSwitch;
    Button nextScreen;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_play_manual);
        buttonPress();
        createSwitches();
        nextScreen = (Button)findViewById(R.id.finish_maze);
        nextScreen.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent mainscreen=new Intent(PlayManualActivity.this, FinishActivity.class);
                mainscreen.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
                startActivity(mainscreen);
                }
            });
    }

    /*
    Handles button presses for left, right, up, and down arrows.
     */
    public void buttonPress(){
        final String TAG="button pressed: ";
        button_down = (ImageButton) findViewById(R.id.downArrow);
        button_left = (ImageButton) findViewById(R.id.leftArrow);
        button_right = (ImageButton) findViewById(R.id.rightArrow);
        button_up = (ImageButton) findViewById(R.id.upArrow);
        button_down.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.v(TAG,"down");
                Snackbar.make(view,"Down pressed",Snackbar.LENGTH_SHORT).show();
            }
        });
        button_up.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.v(TAG,"up");
                Snackbar.make(view,"Up pressed",Snackbar.LENGTH_SHORT).show();
            }
        });
        button_left.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.v(TAG,"left");
                Snackbar.make(view,"Left pressed",Snackbar.LENGTH_SHORT).show();
            }
        });
        button_right.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.v(TAG,"right");
                Snackbar.make(view,"Right pressed",Snackbar.LENGTH_SHORT).show();
            }
        });
    }

    /*
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
