package falstad;

import java.util.Arrays;

import falstad.Robot.Turn;
import generation.Distance;

public class ManualDriver implements RobotDriver {

	BasicRobot robot;
	int w,h;
	Distance dist;
	
	public ManualDriver(MazeController maze) {
		robot=new BasicRobot();
		robot.setMaze(maze);
		robot.getMaze().setDriver(this);
		//System.out.println(maze);
		//System.out.println(maze.getMazeConfiguration());
		//System.out.print("Distance address ");
		//System.out.println(maze.getMazeConfiguration().getMazedists());
		setDistance(maze.getMazeConfiguration().getMazedists());
	}
	
	@Override
	public void setRobot(Robot r) {
		robot=(BasicRobot)r;

	}
	
	public Robot getRobot() {
		return robot;
	}

	@Override
	public void setDimensions(int width, int height) {
		w=width;
		h=height;
	}

	@Override
	public void setDistance(Distance distance) {
		System.out.println("Setting distance");
		dist=distance;
		System.out.println("Distance set");
		
	}

	@Override
	public boolean drive2Exit() throws Exception {
		return false;
	}

	@Override
	public float getEnergyConsumption() {
		return 3000-robot.getBatteryLevel();
	}

	@Override
	public int getPathLength() {
		return robot.getOdometerReading();
	}
	public void move(MazeController.UserInput key) {
		//System.out.println(robot.isInsideRoom());
		/*
		System.out.println(robot.getCurrentDirection());
		System.out.println(robot.getCurrentDirection().rotateClockwise());
		try {
			System.out.println(Arrays.toString(robot.getCurrentPosition()));
		} catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		try {
			System.out.println(robot.getMaze().hasWall(robot.getCurrentPosition()[0], robot.getCurrentPosition()[1], robot.getCurrentDirection().rotateClockwise()));
			System.out.println(robot.getMaze().hasWall(robot.getCurrentPosition()[0], robot.getCurrentPosition()[1], robot.getCurrentDirection()));

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		*/
		switch(key) {
		case Down:
			robot.rotate(Turn.AROUND);
			break;
		case Left:
			robot.rotate(Turn.LEFT);
			break;
		case Right:
			robot.rotate(Turn.RIGHT);
			break;
		case Up:
			robot.move(1, true);
			break;
		default:
			break;
		
		}
	}

	public void reset() {
		MazeController maze=robot.getMaze();
		robot=new BasicRobot();
		robot.setMaze(maze);
		robot.getMaze().setDriver(this);
		setDistance(maze.getMazeConfiguration().getMazedists());
	}
}
