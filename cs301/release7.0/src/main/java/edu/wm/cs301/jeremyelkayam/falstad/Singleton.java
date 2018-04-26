package edu.wm.cs301.jeremyelkayam.falstad;

import edu.wm.cs301.jeremyelkayam.generation.MazeConfiguration;
import edu.wm.cs301.jeremyelkayam.generation.MazeContainer;
import edu.wm.cs301.jeremyelkayam.generation.Order;

/**
 * Created by jerem on 12/3/2017.
 */

public class Singleton {

    private MazeController controller = new MazeController();
    private MazeConfiguration mazeConfiguration = new MazeContainer();

    private static Singleton instance = new Singleton();

    public Singleton() {

        //controller = new MazeController();
    }

    public static Singleton getInstance() {
        if (instance == null){
            instance = new Singleton();
        }
        return instance;
    }

    public void updateDriver(ManualDriver driver) {
        controller.setDriver(driver);
    }

    public void updateBuilder(Order.Builder builder) {
        controller.setBuilder(builder);
    }

    public void updateSkillLevel(int skillLevel) {
        controller.setSkillLevel(skillLevel);
    }

    public MazeController getMazeController() {
        return controller;
    }

    public void killInstance() {
        instance = null;
    }

}
