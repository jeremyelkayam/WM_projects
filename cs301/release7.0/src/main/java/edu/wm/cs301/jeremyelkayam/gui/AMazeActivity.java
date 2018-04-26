package edu.wm.cs301.jeremyelkayam.gui;

import android.content.Intent;
import android.media.MediaPlayer;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.ProgressBar;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import edu.wm.cs301.jeremyelkayam.R;
import edu.wm.cs301.jeremyelkayam.falstad.Singleton;

public class AMazeActivity extends AppCompatActivity {

    Spinner generationSpinner,driverSpinner;
    ArrayAdapter<CharSequence> generationAdapter,driverAdapter;
    Button button;
    SeekBar difficultySlider;
    TextView difficultyText;
    public static String generation_alg,robot_driver;
    MediaPlayer backgroundMusic;
    CheckBox loadMaze;
    Singleton maze;

    /*
    Called when the activity is created. Sets up layout and creates spinners.
     */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_amaze);
        backgroundMusic=MediaPlayer.create(getBaseContext(), R.raw.money);
        loadMaze = (CheckBox)findViewById(R.id.loadFile);
        //Makes welcome blink
        RunAnimation();
/*
        loadMazeButton = (Button)findViewById(R.id.revisit);
        loadMaze=true;
        loadMazeButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        */
    }

    void doMusic(){
        backgroundMusic.setLooping(true);
        backgroundMusic.start();
    }

    /*
    Sets up generation and robot spinners.
     */
    protected void createSpinners(){
        final String TAG="selection: ";
        generationSpinner=(Spinner)findViewById(R.id.generation_spinner);
        generationAdapter=ArrayAdapter.createFromResource(this, R.array.generation_algs,android.R.layout.simple_spinner_item);
        generationAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        generationSpinner.setAdapter(generationAdapter);
        generationSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                Log.v(TAG,"algorithm "+adapterView.getItemAtPosition(i));
                //Snackbar.make(view, "Item selected: "+adapterView.getItemAtPosition(i), Snackbar.LENGTH_SHORT).show();
                generation_alg= adapterView.getItemAtPosition(i).toString();
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });
        driverSpinner=(Spinner)findViewById(R.id.driver_spinner);
        driverAdapter=ArrayAdapter.createFromResource(this, R.array.drivers,android.R.layout.simple_spinner_item);
        driverAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        driverSpinner.setAdapter(driverAdapter);
        driverSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                Log.v(TAG,"driver "+adapterView.getItemAtPosition(i));
                //Snackbar.make(view, "Item selected: "+adapterView.getItemAtPosition(i), Snackbar.LENGTH_SHORT).show();
                robot_driver= adapterView.getItemAtPosition(i).toString();
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });
    }

    /*
    Sets up difficulty slider.
     */
    protected void createDifficultyBar() {
        final String TAG = "difficulty_slider";
        difficultySlider = (SeekBar) findViewById(R.id.difficultySlider);
        difficultyText = (TextView) findViewById(R.id.difficultyText);
        difficultySlider.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int val = (progress * (seekBar.getWidth() - 2 * seekBar.getThumbOffset())) / seekBar.getMax();
                difficultyText.setText("" + progress);
                difficultyText.setX(seekBar.getX() + val + seekBar.getThumbOffset() / 2);
                Log.v(TAG,"skill level changed");
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                //Toast.makeText(getBaseContext(), difficultySlider.getProgress() + " selected", Toast.LENGTH_SHORT).show();
                Log.v(TAG, "Skill Level Selected: " + difficultySlider.getProgress());
            }
        });

    }

    protected void onStart(){
        super.onStart();
        maze=maze.getInstance();
        maze.killInstance();
        createSpinners();
        createDifficultyBar();
        doMusic();
    }

    private void RunAnimation()
    {
        Animation a = AnimationUtils.loadAnimation(this, R.anim.alpha);
        a.reset();
        TextView tv = (TextView) findViewById(R.id.Welcome);
        tv.clearAnimation();
        tv.startAnimation(a);
    }

    protected void onStop(){
        super.onStop();
        backgroundMusic.stop();
    }

    /**
     * sends to the next loading screen activity
     * @param view
     */
    public void toLoadScreen(final View view) {
        nextScreen();
    }

    public void nextScreen(){

        final String TAG = "next screen";
        Log.v(TAG, "to the loading screen!");
        Intent intent = new Intent(AMazeActivity.this, GeneratingActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
        intent.putExtra("driver_selected", robot_driver);
        intent.putExtra("builder_selected", generation_alg);
        intent.putExtra("skillLevel_selected", difficultySlider.getProgress());
        intent.putExtra("load_from_file", loadMaze.isChecked());
        Log.v("load from file",Boolean.toString(loadMaze.isChecked()));
        startActivity(intent);
    }



}