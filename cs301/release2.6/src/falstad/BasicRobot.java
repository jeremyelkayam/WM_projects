package falstad;

import falstad.MazeController.UserInput;
import generation.CardinalDirection;

public class BasicRobot implements Robot {
	
	int distanceTraveled;
	float batteryLevel;
	MazeController currentMaze;
	boolean currentlyMoving; //determines whether or not robot is ready to move. If not, it is stopped. If the robot's battery runs out, it stops regardless of this. 
	
	public BasicRobot() {
		resetOdometer();
		setBatteryLevel(3000);
		currentlyMoving=true;
		// TODO Auto-generated constructor stub
	}

	@Override
	public void rotate(Turn turn) {
		switch(turn) {
		case AROUND:
			currentMaze.keyDown(UserInput.Left,0);
			currentMaze.keyDown(UserInput.Left,0);//tell maze to turn left twice
			batteryLevel-=getEnergyForFullRotation()/2;
			break;
		case LEFT:
			currentMaze.keyDown(UserInput.Left,0);//tell maze to turn left once
			batteryLevel-=getEnergyForFullRotation()/4;
			break;
		case RIGHT:
			currentMaze.keyDown(UserInput.Right, 0);
			batteryLevel-=getEnergyForFullRotation()/4;
			break;
		default:
			break;
		
		}
	}

	@Override
	public void move(int distance, boolean manual) {
		// TODO Auto-generated method stub

	}

	@Override
	public int[] getCurrentPosition() throws Exception {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void setMaze(MazeController maze) {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean isAtExit() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean canSeeExit(Direction direction) throws UnsupportedOperationException {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean isInsideRoom() throws UnsupportedOperationException {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean hasRoomSensor() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public CardinalDirection getCurrentDirection() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public float getBatteryLevel() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public void setBatteryLevel(float level) {
		// TODO Auto-generated method stub

	}

	@Override
	public int getOdometerReading() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public void resetOdometer() {
		// TODO Auto-generated method stub

	}

	@Override
	public float getEnergyForFullRotation() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public float getEnergyForStepForward() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public boolean hasStopped() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public int distanceToObstacle(Direction direction) throws UnsupportedOperationException {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public boolean hasDistanceSensor(Direction direction) {
		// TODO Auto-generated method stub
		return false;
	}

}
