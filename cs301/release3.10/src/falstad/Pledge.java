package falstad;

import java.util.Random;

import falstad.Robot.Turn;
import generation.CardinalDirection;

public class Pledge extends ManualDriver {
	
	final int RIGHT=0;
	final int LEFT=1;
	final int FORWARD=2;
	Random rand;
	
	public Pledge(MazeController maze) {
		super(maze);
		rand=new Random();
	}
	
	@Override
	public boolean drive2Exit() throws Exception{
		int turnTracker=0;
		while(!robot.hasStopped() && !robot.isAtExit()) {
			
			if(checkWall(LEFT) && checkWall(RIGHT)) {
				if(!checkWall(FORWARD)) {
					robot.move(1,false);
				}else {
					robot.rotate(Turn.LEFT);
					robot.rotate(Turn.LEFT);
					turnTracker-=2;
				}
			}else if(!checkWall(LEFT)) {//if no wall on the left
				if(turnTracker>0) {
					robot.rotate(Turn.LEFT);
					turnTracker--;
				}
			}else if(!checkWall(RIGHT)) {//if no wall on the right
				if(turnTracker<0) {
					robot.rotate(Turn.RIGHT);
					turnTracker++;
				}
			}
			if(checkWall(FORWARD)) {//if a wall is ahead we need to turn
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
	
	public boolean checkWall(int direction) throws Exception {
		CardinalDirection dir=robot.getCurrentDirection();
		
		switch(direction) {
		case LEFT:
			dir=dir.oppositeDirection().rotateClockwise();
			break;
		case RIGHT:
			dir=dir.rotateClockwise();
			break;
		}
		
		return robot.getMaze().hasWall(robot.getCurrentPosition()[0], robot.getCurrentPosition()[1], dir);
	}
}
