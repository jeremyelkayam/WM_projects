package falstad;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import falstad.Constants.StateGUI;
import generation.MazeFactory;
import generation.SingleRandom;
import generation.Order.Builder;

public class ManualDriverTest {
	BasicRobot robot;
	MazeApplication maze;

	private MazeFactory mazeFactory;
	private StubController stubController;
	BasicRobot testRobot = new BasicRobot();
	ManualDriver driver;

	@Before
	public void setUp() throws Exception {
		SingleRandom.setSeed(17);
		robot = new BasicRobot();
		maze = new MazeApplication("Eller");
		maze.repaint();

		boolean det = false;
		// generate a maze
		mazeFactory = new MazeFactory(det);
		// create a StubOrder to set maze aspects
		// our skillLevel is set to 1, and the build type is default
		stubController = new StubController(1, Builder.DFS, det);
		mazeFactory.order(stubController);
		mazeFactory.waitTillDelivered();
		stubController.deliver(stubController.getMazeConfiguration());
		stubController.setState(StateGUI.STATE_PLAY);
		driver=new ManualDriver(stubController);
		stubController.setDriver(driver);
	}

	@Before

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testGetDistance() {
		driver.getDistance();

	}

}
