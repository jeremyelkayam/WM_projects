package falstad;

import java.util.Arrays;

import falstad.Robot.Turn;
import generation.CardinalDirection;

public class Wizard extends ManualDriver {
	
	public Wizard(MazeController maze) {
		super(maze);
		System.out.println(dist);
	}
	
	@Override
	public void move(MazeController.UserInput key) {
		super.move(key);
		System.out.println(dist);
		System.out.println(robot.currentMaze);
		//System.out.print(Arrays.toString(findRelativeNearestNeighbor()));
	}
	
	@Override
	public boolean drive2Exit() throws Exception{
		
		robot.getMaze().notifyViewerRedraw();
		int[]nextNeighbor=robot.currentMaze.getMazeConfiguration().getNeighborCloserToExit(robot.getCurrentPosition()[0], robot.getCurrentPosition()[1]);
		while(!robot.hasStopped() && !robot.isAtExit()) {
			nextNeighbor=robot.currentMaze.getMazeConfiguration().getNeighborCloserToExit(robot.getCurrentPosition()[0], robot.getCurrentPosition()[1]);
			CardinalDirection nearestNeighbor=CardinalDirection.getDirection(robot.getCurrentPosition()[0]-nextNeighbor[0],robot.getCurrentPosition()[1]-nextNeighbor[1]);
			
			if(nearestNeighbor==robot.getCurrentDirection()) {
				robot.move(1, false);
			}else if(nearestNeighbor==robot.getCurrentDirection().oppositeDirection()) {
				robot.rotate(Turn.AROUND);
				robot.move(1, false);
			}else if(nearestNeighbor==robot.getCurrentDirection().rotateClockwise()) {
				robot.rotate(Turn.RIGHT);
				robot.move(1, false);
			}else if(nearestNeighbor==robot.getCurrentDirection().oppositeDirection().rotateClockwise()) {
				robot.rotate(Turn.LEFT);
				robot.move(1, false);
			}
		}
		if(robot.isAtExit()) {
			return true;
		}
		return false;
	}
	
	

}
