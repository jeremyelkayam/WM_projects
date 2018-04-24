package falstad;

import java.util.Arrays;

import falstad.MazeController.UserInput;
import falstad.Robot.Direction;
import falstad.Robot.Turn;
import generation.CardinalDirection;

public class Wizard extends ManualDriver {
	
	public Wizard(MazeController maze) {
		super(maze);
		System.out.println(dist);
	}
	
	@Override
	public void move(MazeController.UserInput key) {
		//super.move(key);
		//System.out.println(dist);
		System.out.println(robot.currentMaze);
		//System.out.print(Arrays.toString(findRelativeNearestNeighbor()));
	}
	
	@Override
	public boolean drive2Exit() throws Exception{
		robot.currentMaze.keyDown(UserInput.ToggleLocalMap,0);
		robot.currentMaze.keyDown(UserInput.ToggleFullMap,0);
		robot.currentMaze.keyDown(UserInput.ToggleSolution,0);
		CardinalDirection robotDirection=robot.getCurrentDirection();
		
		int[]nextNeighbor=robot.currentMaze.getMazeConfiguration().getNeighborCloserToExit(robot.getCurrentPosition()[0], robot.getCurrentPosition()[1]);
		while(!robot.hasStopped() && !robot.isAtExit()) {
			//Thread.sleep(100);
			robotDirection=robot.getCurrentDirection();
			nextNeighbor=robot.currentMaze.getMazeConfiguration().getNeighborCloserToExit(robot.getCurrentPosition()[0], robot.getCurrentPosition()[1]);
			CardinalDirection nearestNeighbor=CardinalDirection.getDirection(nextNeighbor[0]-robot.getCurrentPosition()[0],robot.getCurrentPosition()[1]-nextNeighbor[1]);
			/*
			if(robotDirection==CardinalDirection.North || robotDirection==CardinalDirection.South) {
				robotDirection=robotDirection.oppositeDirection();
			}
			*/
			//System.out.println("robot direction: "+robotDirection);
			//System.out.println("correct direction: "+nearestNeighbor);
			
			if(nearestNeighbor==robotDirection) {
				//System.out.println("moveForward");
				robot.move(1, false);
			}else if(nearestNeighbor==robotDirection.oppositeDirection()) {
				//System.out.println("turn around");
				robot.rotate(Turn.AROUND);
			}else if(nearestNeighbor==robotDirection.rotateClockwise()) {
				robot.rotate(Turn.RIGHT);
			}else if(nearestNeighbor==robotDirection.oppositeDirection().rotateClockwise()) {
				robot.rotate(Turn.LEFT);
			}

			//System.out.println("robot direction: "+robot.getCurrentDirection());
			//System.out.println("correct direction: "+nearestNeighbor);
		}
		if(robot.isAtExit()) {
			robot.exitMaze();
			return true;
		}
		return false;
	}
	
	

}
