package edu.wm.cs301.jeremyelkayam.gui;

import android.content.Context;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;

import edu.wm.cs301.jeremyelkayam.R;
import edu.wm.cs301.jeremyelkayam.falstad.Singleton;
import pl.droidsonroids.gif.GifDrawable;
import pl.droidsonroids.gif.GifTextView;

public class FinishActivity extends AppCompatActivity {

    //Button restart;
    TextView winLoseText,debriefText;
    boolean wonGame;
    Singleton maze;
    ImageView face;
    GifTextView gtv;

    @Override

    /*
    Called when the activity is created. Sets up the activity's layout

    @param savedInstanceState
     */
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_finish);
        //init();
        maze=maze.getInstance();
        winLoseText = (TextView) findViewById(R.id.winLoseText);
        debriefText = (TextView) findViewById(R.id.debriefText);
        wonGame=getIntent().getBooleanExtra("won game?",false);
        Log.v("smiley tag",""+R.drawable.smiley);
        face=(ImageView)findViewById(R.id.smileyFrown);
        final MediaPlayer jingle;
        if(wonGame){
            winLoseText.setText("You win!");
            face.setImageResource(R.drawable.smiley);
            jingle= MediaPlayer.create(this, R.raw.win);
        }else{
            winLoseText.setText("You lose!");
            face.setImageResource(R.drawable.frowny);
            jingle= MediaPlayer.create(this, R.raw.lose);
        }//maybe add a smiley or frowny face depending
        float final_batt=maze.getMazeController().getDriver().getRobot().getBatteryLevel();
        if(final_batt<0) {
            final_batt = 0;
        }

        debriefText.setText("Your final battery level was: "+final_batt+"\n\nYour distance traveled was: "+maze.getMazeController().getDriver().getRobot().getOdometerReading()+"\n\nPress the back button on the top left to play again!");
        jingle.setLooping(false);
        jingle.start();
        maze.killInstance();

        Vibrator v =  (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
        v.vibrate(500);
        GifDrawable gif=null;

        gtv = (GifTextView)findViewById(R.id.confetti);
        if(!wonGame){
            gtv.setVisibility(View.INVISIBLE);
        }
    }


    /*
    .
    Sets up the back button

    public void init(){
        restart = (Button)findViewById(R.id.back2Start);
        restart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //Toast.makeText(getBaseContext(),"Back pressed",Toast.LENGTH_SHORT).show();
                Log.v("back pressed"," so yeah");
                Intent mainscreen=new Intent(FinishActivity.this, AMazeActivity.class);
                mainscreen.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|Intent.FLAG_ACTIVITY_SINGLE_TOP);
                startActivity(mainscreen);
            }
        });
    }
    */

    @Override
    public void onBackPressed(){
        super.onBackPressed();
        //Toast.makeText(getBaseContext(),"Back pressed",Toast.LENGTH_SHORT).show();

    }
}
