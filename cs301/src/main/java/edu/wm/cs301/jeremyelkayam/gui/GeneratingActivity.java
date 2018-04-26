package edu.wm.cs301.jeremyelkayam.gui;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Handler;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;

import edu.wm.cs301.jeremyelkayam.R;
import edu.wm.cs301.jeremyelkayam.falstad.Explorer;
import edu.wm.cs301.jeremyelkayam.falstad.ManualDriver;
import edu.wm.cs301.jeremyelkayam.falstad.MazeFileReader;
import edu.wm.cs301.jeremyelkayam.falstad.MazeFileWriter;
import edu.wm.cs301.jeremyelkayam.falstad.MazePanel;
import edu.wm.cs301.jeremyelkayam.falstad.Pledge;
import edu.wm.cs301.jeremyelkayam.falstad.RobotDriver;
import edu.wm.cs301.jeremyelkayam.falstad.Singleton;
import edu.wm.cs301.jeremyelkayam.falstad.WallFollower;
import edu.wm.cs301.jeremyelkayam.falstad.Wizard;
import edu.wm.cs301.jeremyelkayam.generation.MazeConfiguration;
import edu.wm.cs301.jeremyelkayam.generation.MazeFactory;
import edu.wm.cs301.jeremyelkayam.generation.Order;

public class GeneratingActivity extends AppCompatActivity {

    ProgressBar progressBar;
    String fromAMaze=AMazeActivity.robot_driver;
    public static Handler handler;
    int progress=0;
    private Singleton maze;
    RobotDriver driver;
    String driverName,builderName;
    int difficultyLevel;
    private MazeFactory factory = new MazeFactory();
    private int progressStatus;
    private boolean backButtonPressed;
    static boolean loadFromFile;
    static String filename;


    /*
    Navigates to the next activity (PlayManual if it's a manual driver, PlayAuto if it's any other driver)
     */
    protected void nextScreen(){

        boolean didNotLoadDidNotSave=false;

        if(!loadFromFile && difficultyLevel<=3) {
            if(new File(filename).exists()){
                Log.v("file already exists ", filename);
                didNotLoadDidNotSave=true;
            }else {
                MazeConfiguration mazeConfig = maze.getMazeController().getMazeConfiguration();
                MazeFileWriter.store(filename,
                        mazeConfig.getWidth(),
                        mazeConfig.getHeight(),
                        0,
                        0, //both rooms and expected partiters are unnecessary for loading a maze.
                        mazeConfig.getRootnode(),
                        mazeConfig.getMazecells(),
                        mazeConfig.getMazedists().getDists(),
                        mazeConfig.getStartingPosition()[0],
                        mazeConfig.getStartingPosition()[1]);
                Log.v("file saved to", filename);
            }
        }

        final String TAG = "next screen: ";
        if (fromAMaze.equals("Manual")){
            Log.v(TAG, "to the manual screen!");
            Intent manualplay = new Intent(GeneratingActivity.this, PlayManualActivity.class);
            manualplay.putExtra("did_not_load_did_not_save",didNotLoadDidNotSave);
            manualplay.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
            startActivity(manualplay);
        }

        else{
            Log.v(TAG, "to the animation screen!");
            Intent animationplay = new Intent(GeneratingActivity.this, PlayAutoActivity.class);
            animationplay.putExtra("did_not_load_did_not_save",didNotLoadDidNotSave);
            animationplay.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
            startActivity(animationplay);
        }

        finish();
    }

    void generateMaze(){
        handler = new Handler();
        backButtonPressed = false;

        new Thread(new Runnable() {

            @Override
            public void run() {
                MazePanel panel = new MazePanel(getApplicationContext());
                maze.getMazeController().setMazePanel(panel);
                if(fromAMaze.equals("Wizard")) {
                    driver = new Wizard(maze.getMazeController());
                }else if(fromAMaze.equals("Wall Follower")) {
                    driver = new WallFollower(maze.getMazeController());
                }
                else if(fromAMaze.equals("Explorer")){
                    driver=new Explorer(maze.getMazeController());
                }else if(fromAMaze.equals("Manual")){
                    driver=new ManualDriver(maze.getMazeController());
                }else{
                    driver=new Pledge(maze.getMazeController());
                }
                maze.updateDriver((ManualDriver) driver);
                switch (builderName) {
                    case "DFS":
                        maze.updateBuilder(Order.Builder.DFS);
                        break;
                    case "Eller":
                        maze.updateBuilder(Order.Builder.Prim); //Eller's algorithm was not implemented
                        break;
                    case "Prim":
                        maze.updateBuilder(Order.Builder.Prim);
                        break;
                }
                maze.updateSkillLevel(difficultyLevel);
                Log.v("generating screen","attempting to load maze from file");
                if(loadFromFile && new File(filename).exists() && difficultyLevel<=3) {
                    progressBar.setIndeterminate(true);
                    TextView text = (TextView) findViewById(R.id.gentext);
                    text.setText("Loading maze...");
                    setTitle("Loading maze...");
                    Log.v("loading file",filename);
                    MazeFileReader mfr=new MazeFileReader(filename);
                    MazeConfiguration mazeConfig=mfr.getMazeConfiguration();
                    maze.getMazeController().deliver(mazeConfig);
                    Log.v("generating screen","maze file loaded");
                    progressStatus=100;
                    Log.v("percent done",""+Integer.parseInt(maze.getMazeController().getPercentDone()));
                }else {
                    if(loadFromFile && difficultyLevel<=3){
                        Log.v("generating screen","file not found, generating new maze");
                        Snackbar.make(findViewById(android.R.id.content),"File not found for difficulty level "+difficultyLevel+", generating new maze",Snackbar.LENGTH_SHORT).show();
                    }
                    factory.order(maze.getMazeController());
                }
                final String tag="";
                Log.v(tag, "Driver used: " + maze.getMazeController().getDriver());
                Log.v(tag, "Builder used: " + maze.getMazeController().getBuilder());
                Log.v(tag, "Difficulty level: " + maze.getMazeController().getSkillLevel());

                while (progressStatus < 100) {
                    //Log.v(tag, "PercentDone: " + maze.getMazeController().getPercentDone());
                    progressStatus = Integer.parseInt(maze.getMazeController().getPercentDone());
                    //progressStatus++;
                    handler.post(new Runnable() {
                        @SuppressLint("SetTextI18n")
                        @Override
                        public void run() {
                            //progressStatusTextView.setText(progressStatus + "%");
                            progressBar.setProgress(progressStatus);

                        }
                    });
                }
                try {
                    Thread.sleep(200);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if (!backButtonPressed) {
                    Log.v("load end","to next screen");
                    nextScreen();
                    //writeToFile(skillLevel);
                }
            }


        }).start();
    }

    /*
    Called when screen is created. Sets up everything
     */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setGenerationSpecs();
        filename = getApplicationContext().getFilesDir() + "/" + "mazedifficulty"+difficultyLevel+".xml";
        maze=maze.getInstance();
        setContentView(R.layout.activity_generating);
        progressBar = (ProgressBar) findViewById(R.id.generationProgress);
    }

    protected void onStart(){
        super.onStart();
        //setGenerationSpecs();
        generateMaze();
        Log.v("started","generation screen");
    }
    protected void onStop(){
        super.onStop();
        Log.v("stopped","generation screen");
        //finish();
    }

    void setGenerationSpecs(){
        Intent intent = getIntent();
        if (intent != null) {
            driverName = intent.getStringExtra("driver_selected");
            builderName = intent.getStringExtra("builder_selected");
            difficultyLevel= intent.getIntExtra("skillLevel_selected", 0);
            loadFromFile=intent.getBooleanExtra("load_from_file",false);
        }
    }
    /*
    Navigates to the next activity (PlayManual if it's a manual driver, PlayAuto if it's any other driver)
     */
    void nextScreen(final  View view){
        nextScreen();
        //finish();
    }

    /*
    Called when back pressed. Sends message to confirm back button press
     */
    @Override
    public void onBackPressed(){
        super.onBackPressed();
        Log.v("back pressed"," so yeah");
        backButtonPressed=true;
    }
}
