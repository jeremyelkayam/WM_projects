package falstad;

import falstad.MazeController.UserInput;
import falstad.Robot.Direction;
import falstad.Robot.Turn;
import generation.CardinalDirection;

public class WallFollower extends ManualDriver {

	public WallFollower(MazeController maze) {
		super(maze);
	}
	
	@Override
	public void move(MazeController.UserInput key) {
		
	}
	
	@Override
	public boolean drive2Exit() throws Exception{
		robot.currentMaze.keyDown(UserInput.ToggleLocalMap,0);
		robot.currentMaze.keyDown(UserInput.ToggleFullMap,0);
		//robot.currentMaze.keyDown(UserInput.ToggleSolution,0);
		
		while(!robot.hasStopped() && !robot.isAtExit()) {
			/*
			System.out.println("next obstacle ahead"+robot.distanceToObstacle(Direction.FORWARD));
			System.out.println("next obstacle on left"+robot.distanceToObstacle(Direction.LEFT));
			System.out.println("next obstacle on right"+robot.distanceToObstacle(Direction.RIGHT));
			*/
			if(robot.distanceToObstacle(Direction.RIGHT)==0) {
				System.out.println("wall on right");
				if(robot.distanceToObstacle(Direction.FORWARD)==0) {
					System.out.println("wall ahead");
					robot.rotate(Turn.LEFT);//if there's a wall on the right and a wall ahead, try turning left
				}else {
					robot.move(1,false);//if there's no wall ahead we can move forward, so we should
				}
			}else {
				System.out.println("no wall on right");
				robot.rotate(Turn.RIGHT);//if there's no wall on the right, try moving to the right until we get a wall
				robot.move(1, false);
			}
			
			System.out.println("next obstacle ahead"+robot.distanceToObstacle(Direction.FORWARD));
			System.out.println("next obstacle on left"+robot.distanceToObstacle(Direction.LEFT));
			System.out.println("next obstacle on right"+robot.distanceToObstacle(Direction.RIGHT));
			
			
			//Thread.sleep(1000);
		}
		if(robot.isAtExit()) {
			robot.exitMaze();
			return true;
		}
		return false;
	}
	
}
