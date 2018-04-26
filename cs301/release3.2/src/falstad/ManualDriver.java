package falstad;

import falstad.Robot.Turn;
import generation.Distance;

public class ManualDriver implements RobotDriver {

	Robot robot;
	int w,h;
	Distance dist;
	
	public ManualDriver(MazeController maze) {
		robot=new BasicRobot();
		robot.setMaze(maze);
		setDistance(maze.getMazeConfiguration().getMazedists());
	}
	
	@Override
	public void setRobot(Robot r) {
		robot=r;

	}

	@Override
	public void setDimensions(int width, int height) {
		w=width;
		h=height;
	}

	@Override
	public void setDistance(Distance distance) {
		dist=distance;

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
		System.out.println(robot.isInsideRoom());
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
}
