package falstad;

import falstad.Robot.Direction;
import falstad.Robot.Turn;
import generation.CardinalDirection;

public class Explorer extends ManualDriver {

	int[][]visitcounts;
	public Explorer(MazeController maze) {
		super(maze);
		visitcounts=new int[h][w];
		try {
			visitcounts[robot.getCurrentPosition()[0]][robot.getCurrentPosition()[1]]++;
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Override
	public boolean drive2Exit() {
		while(!robot.hasStopped() && !robot.isAtExit()) {
			int min=Integer.MAX_VALUE;
			Direction mindir = null;
			int x=0;
			int y=0;
			try {
				x=robot.getCurrentPosition()[0];
				y = robot.getCurrentPosition()[1];
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			if(robot.distanceToObstacle(Direction.FORWARD)!=0) {//no wall ahead
				CardinalDirection card=robot.directionToCardinal(Direction.FORWARD);
				if(card==CardinalDirection.North || card==CardinalDirection.South) {
					card=card.oppositeDirection();
				}
				int[]dir=card.getDirection();
				
				if(min>visitcounts[x+dir[0]][y+dir[1]]) {
					min=visitcounts[x+dir[0]][y+dir[1]];
					mindir=Direction.FORWARD;
				}
			}
			if(robot.distanceToObstacle(Direction.BACKWARD)!=0) {//no wall ahead
				CardinalDirection card=robot.directionToCardinal(Direction.BACKWARD);
				if(card==CardinalDirection.North || card==CardinalDirection.South) {
					card=card.oppositeDirection();
				}
				int[]dir=card.getDirection();
				try {
				if(min>visitcounts[x+dir[0]][y+dir[1]]) {
					min=visitcounts[x+dir[0]][y+dir[1]];
					mindir=Direction.BACKWARD;
				}
				}catch(ArrayIndexOutOfBoundsException aioobe) {
				
				}
			}
			if(robot.distanceToObstacle(Direction.LEFT)!=0) {//no wall ahead
				CardinalDirection card=robot.directionToCardinal(Direction.LEFT);
				if(card==CardinalDirection.North || card==CardinalDirection.South) {
					card=card.oppositeDirection();
				}
				int[]dir=card.getDirection();
				
				if(min>visitcounts[x+dir[0]][y+dir[1]]) {
					min=visitcounts[x+dir[0]][y+dir[1]];
					mindir=Direction.LEFT;
				}
			}
			if(robot.distanceToObstacle(Direction.RIGHT)!=0) {//no wall ahead
				CardinalDirection card=robot.directionToCardinal(Direction.RIGHT);
				if(card==CardinalDirection.North || card==CardinalDirection.South) {
					card=card.oppositeDirection();
				}
				int[]dir=card.getDirection();
				
				if(min>visitcounts[x+dir[0]][y+dir[1]]) {
					min=visitcounts[x+dir[0]][y+dir[1]];
					mindir=Direction.RIGHT;
				}
			}
			
			switch(mindir) {
			case BACKWARD:
				robot.rotate(Turn.AROUND);
			case LEFT:
				robot.rotate(Turn.LEFT);
				break;
			case RIGHT:
				robot.rotate(Turn.RIGHT);
				break;
			default:
				break;
			}
			robot.move(1, false);
			try {
				visitcounts[robot.getCurrentPosition()[0]][robot.getCurrentPosition()[1]]++;
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		return false;	
	}
		
	
	
}
