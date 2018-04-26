package edu.wm.cs301.jeremyelkayam.gui;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.media.MediaPlayer;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import edu.wm.cs301.jeremyelkayam.R;
import edu.wm.cs301.jeremyelkayam.falstad.ManualDriver;
import edu.wm.cs301.jeremyelkayam.falstad.MazeController;
import edu.wm.cs301.jeremyelkayam.falstad.MazePanel;
import edu.wm.cs301.jeremyelkayam.falstad.Singleton;

public class PlayManualActivity extends AppCompatActivity {

    ImageButton button_up, button_right, button_left, button_down;

    Switch mapSwitch,solutionSwitch,wallsSwitch;
    Button nextScreen;
    Singleton maze;
    MazeController controller;
    ManualDriver robot;
    TextView batteryText,distanceText;
    ProgressBar battBar;
    MediaPlayer backgroundMusic;
    ImageView compassRose;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_play_manual);
        maze = maze.getInstance();
        //Log.v("hi","sup");
        //Log.v("hi","sup");
        String savedOrLoaded;
        if(!GeneratingActivity.loadFromFile) {
            savedOrLoaded="Maze saved to file ";
        }else{
            savedOrLoaded="Maze loaded from file ";
        }
        if(!getIntent().getBooleanExtra("did_not_load_did_not_save",true) && maze.getMazeController().getSkillLevel()<=3) {
            Snackbar.make(findViewById(android.R.id.content), savedOrLoaded + GeneratingActivity.filename, Snackbar.LENGTH_LONG).show();
        }
        makeFinishButton(new Intent(PlayManualActivity.this,FinishActivity.class));
        createSwitches();
        controller = maze.getMazeController();
        batteryText = (TextView) findViewById(R.id.batteryLabelNumbers);
        distanceText=(TextView)findViewById(R.id.manualDistanceTraveled);
        backgroundMusic=MediaPlayer.create(getBaseContext(), R.raw.shop);
        compassRose=(ImageView)findViewById(R.id.compassRose);


        maze.getMazeController().setMazePanel((MazePanel) findViewById(R.id.maze_panel));
        robot = controller.getDriver();
        controller.switchToPlayingScreen();
        controller.notifyViewerRedraw();
        battBar=(ProgressBar)findViewById(R.id.batteryProgress);
        battBar.setMax(3000);
        battBar.setProgress(3000);
        buttonPress();
        updateBattery();
        //robot.getRobot().setBatteryLevel(30);
        String tag="direction";

        switch(robot.getRobot().getCurrentDirection()){
            case North:
                Log.v(tag,"north");
                break;
            case East:
                Log.v(tag,"east");
                compassRose.setRotation(compassRose.getRotation() - 90);
                break;
            case West:
                Log.v(tag,"west");
                compassRose.setRotation(compassRose.getRotation() + 90);
                break;
            case South:
                Log.v(tag,"south");
                compassRose.setRotation(compassRose.getRotation() + 180);
                break;
        }

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
                if(!wallsSwitch.isChecked() && !solutionSwitch.isChecked()) {
                    maze.getMazeController().keyDown(MazeController.UserInput.ToggleLocalMap, 0);
                }
                maze.getMazeController().keyDown(MazeController.UserInput.ToggleFullMap,0);
            }
        });
        solutionSwitch.setOnCheckedChangeListener(new Switch.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                //Snackbar.make(buttonView, "switched solution state", Snackbar.LENGTH_SHORT).show();
                Log.v(TAG, "solution state");
                if(!wallsSwitch.isChecked() && !mapSwitch.isChecked()) {
                    maze.getMazeController().keyDown(MazeController.UserInput.ToggleLocalMap, 0);
                }
                maze.getMazeController().keyDown(MazeController.UserInput.ToggleSolution,0);
            }
        });
        wallsSwitch.setOnCheckedChangeListener(new Switch.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                //Snackbar.make(buttonView, "switched walls state", Snackbar.LENGTH_SHORT).show();
                Log.v(TAG, "wall state");
                if(!solutionSwitch.isChecked() && !mapSwitch.isChecked()){
                    maze.getMazeController().keyDown(MazeController.UserInput.ToggleLocalMap,0);
                }
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
                //Snackbar.make(view,"Down pressed",Snackbar.LENGTH_SHORT).show();
                robot.move(MazeController.UserInput.Down);
                updateBattery();
                compassRose.setRotation(compassRose.getRotation() + 180);

            }
        });
        button_up.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.v(TAG,"up");
                //Snackbar.make(view,"Up pressed",Snackbar.LENGTH_SHORT).show();
                robot.move(MazeController.UserInput.Up);
                updateBattery();
                try {
                    if (robot.getRobot().isOutside()) {
                        Log.v("robot status","won the game");
                        exitMaze(true);
                    }
                }catch(Exception e){

                }
            }
        });
        button_left.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.v(TAG,"left");
                //Snackbar.make(view,"Left pressed",Snackbar.LENGTH_SHORT).show();
                robot.move(MazeController.UserInput.Left);
                updateBattery();
                compassRose.setRotation(compassRose.getRotation() + 90);
            }
        });
        button_right.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.v(TAG,"right");
                //Snackbar.make(view,"Right pressed",Snackbar.LENGTH_SHORT).show();
                robot.move(MazeController.UserInput.Right);
                updateBattery();
                compassRose.setRotation(compassRose.getRotation() - 90);
            }
        });


    }

    /*
    Creates switches for showing map, solution, and visible walls.
     */

    void updateBattery(){
        if(robot.getEnergyConsumption()>=3000){
            exitMaze(false);
        }
        batteryText.setText(""+(3000-robot.getEnergyConsumption())+"/3000");
        distanceText.setText("Distance traveled: "+robot.getPathLength());
        battBar.setProgress((int)(3000-robot.getEnergyConsumption()));

    }

    @Override
    public void onBackPressed(){
        super.onBackPressed();
        //Toast.makeText(getBaseContext(),"Back pressed",Toast.LENGTH_SHORT).show();
        Log.v("back pressed"," so yeah");
    }

    void exitMaze(boolean wonGame){
        Intent finishScreen=new Intent(PlayManualActivity.this,FinishActivity.class);
        finishScreen.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
        finishScreen.putExtra("won game?",wonGame);
        startActivity(finishScreen);
    }


    protected void onStart(){
        super.onStart();
        backgroundMusic.setLooping(true);
        backgroundMusic.start();
    }


    protected void onStop(){
        super.onStop();
        backgroundMusic.stop();
        //finish();
    }
}
