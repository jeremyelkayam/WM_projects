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

}
