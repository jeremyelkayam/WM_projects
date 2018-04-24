package edu.wm.cs301.jeremyelkayam.gui;

import android.content.Intent;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import edu.wm.cs301.jeremyelkayam.R;

public class AMazeActivity extends AppCompatActivity {

    Spinner generationSpinner,driverSpinner;
    ArrayAdapter<CharSequence> generationAdapter,driverAdapter;
    Button button;
    SeekBar difficultySlider;
    TextView difficultyText;
    public static String generation_alg,robot_driver;

    /*
    Called when the activity is created. Sets up layout and creates spinners.
     */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_amaze);
        createSpinners();
        createDifficultyBar();
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
                Snackbar.make(view, "Item selected: "+adapterView.getItemAtPosition(i), Snackbar.LENGTH_SHORT).show();
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
                Snackbar.make(view, "Item selected: "+adapterView.getItemAtPosition(i), Snackbar.LENGTH_SHORT).show();
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
                Toast.makeText(getBaseContext(), difficultySlider.getProgress() + " selected", Toast.LENGTH_SHORT).show();
                Log.v(TAG, "Skill Level Selected: " + difficultySlider.getProgress());
            }
        });

    }

    /**
     * sends to the next loading screen activity
     * @param view
     */
    public void toLoadScreen(final View view) {
        final String TAG = "next screen";
        Log.v(TAG, "to the loading screen!");
        Intent intent = new Intent(AMazeActivity.this, GeneratingActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
        startActivity(intent);
    }

}