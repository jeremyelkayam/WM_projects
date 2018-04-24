package falstad;

import generation.Distance;

public class ManualDriver implements RobotDriver {

	Robot robot;
	int w,h;
	Distance dist;
	
	public ManualDriver(MazeController maze) {
		robot=new BasicRobot();
		robot.setMaze(maze);
	}
	
	@Override
	public void setRobot(Robot r) {
		// TODO Auto-generated method stub

	}

	@Override
	public void setDimensions(int width, int height) {
		// TODO Auto-generated method stub

	}

	@Override
	public void setDistance(Distance distance) {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean drive2Exit() throws Exception {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public float getEnergyConsumption() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int getPathLength() {
		// TODO Auto-generated method stub
		return 0;
	}

}
