package falstad;

import falstad.Robot.Turn;
import generation.CardinalDirection;

public class WallFollower extends ManualDriver {

	public WallFollower(MazeController maze) {
		super(maze);
	}
	@Override
	public boolean drive2Exit() throws Exception{
		
		while(!robot.hasStopped() && !robot.isAtExit()) {
			
			if(robot.getMaze().hasWall(robot.getCurrentPosition()[0], robot.getCurrentPosition()[1], robot.getCurrentDirection().rotateClockwise())) {
				if(robot.getMaze().hasWall(robot.getCurrentPosition()[0], robot.getCurrentPosition()[1] ,robot.getCurrentDirection())) {
					robot.rotate(Turn.LEFT);//if there's a wall on the right and a wall ahead, try turning left
				}else {
					robot.move(1,false);//if there's no wall ahead we can move forward, so we should
				}
			}else {
				robot.rotate(Turn.RIGHT);//if there's no wall on the right, try moving to the right until we get a wall
				robot.move(1,false);
			}
		}
		if(robot.isAtExit()) {
			return true;
		}
		return false;
	}
	
}
