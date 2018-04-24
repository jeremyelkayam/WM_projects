package falstad;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import falstad.Constants.StateGUI;
import generation.MazeConfiguration;
import generation.MazeFactory;
import generation.SingleRandom;
import generation.Order.Builder;

public class WizardTest {

	BasicRobot robot;
	MazeApplication maze;
	
	private Wizard driver;
	private MazeFactory mazeFactory;
	//private StubOrder stubOrder;
	private MazeConfiguration configuration;
	private StubController stubController;
	BasicRobot testRobot = new BasicRobot();
	
	@Before
	public void setUp() throws Exception{
		SingleRandom.setSeed(17);
		robot = new BasicRobot();
		maze = new MazeApplication("Eller"); 
		maze.repaint();	
		
		boolean det = false;
		// generate a maze 
		mazeFactory = new MazeFactory(det);
		// create a StubController to set maze aspects 
		// our skillLevel is set to 1, and the build type is default
		stubController = new StubController(1, Builder.DFS, det);
		mazeFactory.order(stubController);
		mazeFactory.waitTillDelivered();
		stubController.deliver(stubController.getMazeConfiguration());
		stubController.setState(StateGUI.STATE_PLAY);
		driver=new Wizard(stubController);
		stubController.setDriver(driver);
}
	
	
	
	@Test
	/**
	 * 
	 * Tests whether the driver leads the robot to the exit 
	 */
	public void exitFound() throws Exception {
		
		
		//boolean result = driver.drive2Exit();
		
		//assertEquals(result, true);
	}
}
