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
		getRobot().currentMaze.keyDown(UserInput.ToggleLocalMap,0);
		getRobot().currentMaze.keyDown(UserInput.ToggleFullMap,0);
		//robot.currentMaze.keyDown(UserInput.ToggleSolution,0);
		
		while(!getRobot().hasStopped() && !getRobot().isAtExit()) {
			/*
			System.out.println("next obstacle ahead"+robot.distanceToObstacle(Direction.FORWARD));
			System.out.println("next obstacle on left"+robot.distanceToObstacle(Direction.LEFT));
			System.out.println("next obstacle on right"+robot.distanceToObstacle(Direction.RIGHT));
			*/
			if(getRobot().distanceToObstacle(Direction.RIGHT)==0) {
				System.out.println("wall on right");
				if(getRobot().distanceToObstacle(Direction.FORWARD)==0) {
					System.out.println("wall ahead");
					getRobot().rotate(Turn.LEFT);//if there's a wall on the right and a wall ahead, try turning left
				}else {
					getRobot().move(1,false);//if there's no wall ahead we can move forward, so we should
				}
			}else {
				System.out.println("no wall on right");
				getRobot().rotate(Turn.RIGHT);//if there's no wall on the right, try moving to the right until we get a wall
				getRobot().move(1, false);
			}
			
			System.out.println("next obstacle ahead"+getRobot().distanceToObstacle(Direction.FORWARD));
			System.out.println("next obstacle on left"+getRobot().distanceToObstacle(Direction.LEFT));
			System.out.println("next obstacle on right"+getRobot().distanceToObstacle(Direction.RIGHT));
			
			
			//Thread.sleep(1000);
		}
		if(getRobot().isAtExit()) {
			getRobot().exitMaze();
			return true;
		}
		return false;
	}
	
}
