package falstad;

import java.util.Arrays;

import falstad.MazeController.UserInput;
import falstad.Robot.Direction;
import falstad.Robot.Turn;
import generation.CardinalDirection;

public class Wizard extends ManualDriver {
	
	public Wizard(MazeController maze) {
		super(maze);
		System.out.println(getDistance());
	}
	
	@Override
	public void move(MazeController.UserInput key) {
		//super.move(key);
		//System.out.println(dist);
		System.out.println(getRobot().getMaze());
		//System.out.print(Arrays.toString(findRelativeNearestNeighbor()));
	}
	
	@Override
	public boolean drive2Exit() throws Exception{
		getRobot().currentMaze.keyDown(UserInput.ToggleLocalMap,0);
		getRobot().currentMaze.keyDown(UserInput.ToggleFullMap,0);
		getRobot().currentMaze.keyDown(UserInput.ToggleSolution,0);
		CardinalDirection robotDirection=getRobot().getCurrentDirection();
		
		int[]nextNeighbor=getRobot().currentMaze.getMazeConfiguration().getNeighborCloserToExit(getRobot().getCurrentPosition()[0], getRobot().getCurrentPosition()[1]);
		while(!getRobot().hasStopped() && !getRobot().isAtExit()) {
			//Thread.sleep(100);
			robotDirection=getRobot().getCurrentDirection();
			nextNeighbor=getRobot().currentMaze.getMazeConfiguration().getNeighborCloserToExit(getRobot().getCurrentPosition()[0], getRobot().getCurrentPosition()[1]);
			CardinalDirection nearestNeighbor=CardinalDirection.getDirection(nextNeighbor[0]-getRobot().getCurrentPosition()[0],getRobot().getCurrentPosition()[1]-nextNeighbor[1]);
			/*
			if(robotDirection==CardinalDirection.North || robotDirection==CardinalDirection.South) {
				robotDirection=robotDirection.oppositeDirection();
			}
			*/
			//System.out.println("robot direction: "+robotDirection);
			//System.out.println("correct direction: "+nearestNeighbor);
			
			if(nearestNeighbor==robotDirection) {
				//System.out.println("moveForward");
				getRobot().move(1, false);
			}else if(nearestNeighbor==robotDirection.oppositeDirection()) {
				//System.out.println("turn around");
				getRobot().rotate(Turn.AROUND);
			}else if(nearestNeighbor==robotDirection.rotateClockwise()) {
				getRobot().rotate(Turn.RIGHT);
			}else if(nearestNeighbor==robotDirection.oppositeDirection().rotateClockwise()) {
				getRobot().rotate(Turn.LEFT);
			}

			//System.out.println("robot direction: "+robot.getCurrentDirection());
			//System.out.println("correct direction: "+nearestNeighbor);
		}
		if(getRobot().isAtExit()) {
			getRobot().exitMaze();
			return true;
		}
		return false;
	}
	
	

}
