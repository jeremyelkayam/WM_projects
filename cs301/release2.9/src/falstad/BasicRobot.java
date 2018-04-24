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
		int z=0;
		//System.out.println("yo");
		while(!hasStopped() && z<distance) {
			if(!manual && currentMaze.checkMove(1)) {//if we're using manual control and can move forward
				
			}
			currentMaze.keyDown(UserInput.Up, 0);
			batteryLevel-=getEnergyForStepForward();
			//System.out.println("hi");
			z++;
			distanceTraveled++;
			batteryLevel-=getEnergyForStepForward();
		}
	}

	@Override
	public int[] getCurrentPosition() throws Exception {
		return currentMaze.getCurrentPosition();
	}

	@Override
	public void setMaze(MazeController maze) {
		currentMaze=maze;
	}

	@Override
	public boolean isAtExit(){
		int[][]directions= {{0, 1},{1, 0},{0, -1},{-1,0}};
		for(int[]z : directions) {
			int[] pos= null;
			try {
				pos = getCurrentPosition();
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			if(!currentMaze.hasWall(pos[0],pos[1],CardinalDirection.getDirection(z[0], z[1])) && currentMaze.isOutside(pos[0]+z[0],pos[1]+z[1])) {
				return true; //for all directions, if there is no wall in a direction, and the next space is outside of the maze, we're at the exit
			}
		}
		return false;
	}

	@Override
	public boolean canSeeExit(Direction direction) throws UnsupportedOperationException {
		int x=0;
		int y=0;
		try {
			x=getCurrentPosition()[0];
			y=getCurrentPosition()[1];
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		while(!currentMaze.hasWall(x,y,getCurrentDirection())){
			x+=getCurrentDirection().getDirection()[0];
			y+=getCurrentDirection().getDirection()[1];//keep walking forward until we can't anymore
			if(currentMaze.isOutside(x,y)) {// if we're outside, we can see the exit
				return true;
			}
		}
		
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
		return currentMaze.getCurrentDirection();
	}

	@Override
	public float getBatteryLevel() {
		return batteryLevel;
	}

	@Override
	public void setBatteryLevel(float level) {
		batteryLevel=level;
	}

	@Override
	public int getOdometerReading() {
		return distanceTraveled;
	}

	@Override
	public void resetOdometer() {
		distanceTraveled=0;
	}

	@Override
	public float getEnergyForFullRotation() {
		return 12;
	}

	@Override
	public float getEnergyForStepForward() {
		return 5;
	}

	@Override
	public boolean hasStopped() {
		if(batteryLevel<=0) {
			return true;
		}
		return !currentlyMoving;
	}

	@Override
	public int distanceToObstacle(Direction direction) throws UnsupportedOperationException {
		return 0;
	}

	@Override
	public boolean hasDistanceSensor(Direction direction) {
		return false;
	}

}
