package falstad;

import java.util.Random;

import falstad.Robot.Direction;
import falstad.Robot.Turn;
import generation.CardinalDirection;

public class Pledge extends ManualDriver {
	
	
	private Random rand;
	
	
	public Pledge(MazeController maze) {
		super(maze);
		rand=new Random();
	}
	
	@Override
	public boolean drive2Exit() throws Exception{
		int turnTracker=0;
		while(!getRobot().hasStopped() && !getRobot().isAtExit()) {
			System.out.println("turn tracker: "+turnTracker);
			if(!getRobot().checkWall(Direction.FORWARD)) {//if there's no wall ahead of us
				if(!getRobot().checkWall(Direction.LEFT)) {//if there's no wall on the left
					if(turnTracker>0) {
						getRobot().rotate(Turn.LEFT);
						turnTracker--;
					}
				}else if(!getRobot().checkWall(Direction.RIGHT)) {//no wall on the right
					if(turnTracker<0) {
						getRobot().rotate(Turn.RIGHT);
						turnTracker++;
					}
				}
			}else {//wall ahead of us
				if(getRobot().checkWall(Direction.LEFT)) {//if there is a left wall
					getRobot().rotate(Turn.RIGHT);
					turnTracker++;
				}else if(getRobot().checkWall(Direction.RIGHT)) {//if there is a right wall but no left wall
					getRobot().rotate(Turn.LEFT);
					turnTracker--;
				}else {//if there is no right wall or left wall
					if(turnTracker<0) {//if we've made more left turns than right
						getRobot().rotate(Turn.RIGHT);
						turnTracker++;
					}else if(turnTracker>0) {//if more right turns than left
						getRobot().rotate(Turn.LEFT);
						turnTracker--;
					}else {//if equal
						if(rand.nextBoolean()) {
							getRobot().rotate(Turn.LEFT);
							turnTracker--;
						}else{
							getRobot().rotate(Turn.RIGHT);
							turnTracker++;
						}
					}
				}
			}
			if(!getRobot().checkWall(Direction.FORWARD)) {
				getRobot().move(1, false);//move forward
			}
		}
		if(getRobot().isAtExit()) {
			getRobot().exitMaze();
			return true;
		}
		return false;
	}
	
	
}
