package edu.wm.cs301.jeremyelkayam.gui;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ProgressBar;
import android.widget.Switch;

import edu.wm.cs301.jeremyelkayam.R;
import edu.wm.cs301.jeremyelkayam.falstad.ManualDriver;
import edu.wm.cs301.jeremyelkayam.falstad.MazeController;
import edu.wm.cs301.jeremyelkayam.falstad.MazePanel;
import edu.wm.cs301.jeremyelkayam.falstad.Singleton;

/**
 * Created by jerem on 12/3/2017.
 */

public abstract class PlayActivity extends AppCompatActivity {

    Switch mapSwitch,solutionSwitch,wallsSwitch;
    Button nextScreen;
    Singleton maze;
    MazeController controller;
    ManualDriver robot;
    ProgressBar battBar;
    int contentViewID;

    void setContentViewID(int id){
        contentViewID=id;
    }

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(contentViewID);
        createSwitches();
        maze = maze.getInstance();
        controller = maze.getMazeController();


        maze.getMazeController().setMazePanel((MazePanel) findViewById(R.id.maze_panel));
        robot = controller.getDriver();
        controller.switchToPlayingScreen();
        controller.notifyViewerRedraw();
        battBar=(ProgressBar)findViewById(R.id.batteryProgress);
        battBar.setMax(3000);
        battBar.setProgress(3000);
    }

    public void makeFinishButton(final Intent mainscreen){
        nextScreen = (Button)findViewById(R.id.finish_maze);
        nextScreen.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mainscreen.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
                startActivity(mainscreen);
            }
        });
    }

    public void createSwitches(){
        mapSwitch= (Switch) findViewById(R.id.mapSwitch);
        solutionSwitch= (Switch) findViewById(R.id.solutionSwitch);
        wallsSwitch= (Switch) findViewById(R.id.wallsSwitch);
        final String TAG="switch change:";
        //Log.v(TAG,"hi");
        mapSwitch.setOnCheckedChangeListener(new Switch.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                //Snackbar.make(buttonView, "switched map state", Snackbar.LENGTH_SHORT).show();
                Log.v(TAG, "map state");
            }
        });
        solutionSwitch.setOnCheckedChangeListener(new Switch.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                //Snackbar.make(buttonView, "switched solution state", Snackbar.LENGTH_SHORT).show();
                Log.v(TAG, "solution state");
            }
        });
        wallsSwitch.setOnCheckedChangeListener(new Switch.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                //Snackbar.make(buttonView, "switched walls state", Snackbar.LENGTH_SHORT).show();
                Log.v(TAG, "wall state");
            }
        });
    }


    /*
    void exitMaze(boolean wonGame){
        Intent finishScreen=new Intent(PlayManualActivity.this,FinishActivity.class);
        finishScreen.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
        finishScreen.putExtra("won game?",wonGame);
        startActivity(finishScreen);
    }
    */
}
