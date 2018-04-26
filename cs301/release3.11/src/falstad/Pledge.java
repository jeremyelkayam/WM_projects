package falstad;

import java.util.Random;

import falstad.Robot.Direction;
import falstad.Robot.Turn;
import generation.CardinalDirection;

public class Pledge extends ManualDriver {
	
	
	Random rand;
	
	public Pledge(MazeController maze) {
		super(maze);
		rand=new Random();
	}
	
	@Override
	public boolean drive2Exit() throws Exception{
		int turnTracker=0;
		while(!robot.hasStopped() && !robot.isAtExit()) {
			
			if(checkWall(Direction.LEFT) && checkWall(Direction.RIGHT)) {
				if(!checkWall(Direction.FORWARD)) {
					robot.move(1,false);
				}else {
					robot.rotate(Turn.LEFT);
					robot.rotate(Turn.LEFT);
					turnTracker-=2;
				}
			}else if(!checkWall(Direction.LEFT)) {//if no wall on the left
				if(turnTracker>0) {
					robot.rotate(Turn.LEFT);
					turnTracker--;
				}
			}else if(!checkWall(Direction.RIGHT)) {//if no wall on the right
				if(turnTracker<0) {
					robot.rotate(Turn.RIGHT);
					turnTracker++;
				}
			}
			if(checkWall(Direction.FORWARD)) {//if a wall is ahead we need to turn
				if(turnTracker==0) {
					if(rand.nextBoolean()) {
						robot.rotate(Turn.LEFT);
						turnTracker--;
					}else {
						robot.rotate(Turn.RIGHT);
						turnTracker++;
					}
				}else if(turnTracker<0) {
					robot.rotate(Turn.RIGHT);
					turnTracker++;
				}else if(turnTracker>0) {
					robot.rotate(Turn.LEFT);
					turnTracker--;
				}
			}else {//if there's no wall, we can move ahead
				robot.move(1, false);
			}
		}
		if(robot.isAtExit()) {
			return true;
		}
		return false;
	}
	
	public boolean checkWall(Direction direction) throws Exception {
		return robot.distanceToObstacle(direction)==0;
	}
}
