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
			System.out.println("turn tracker: "+turnTracker);
			if(!checkWall(Direction.FORWARD)) {//if there's no wall ahead of us
				if(!checkWall(Direction.LEFT)) {//if there's no wall on the left
					if(turnTracker>0) {
						robot.rotate(Turn.LEFT);
						turnTracker--;
					}
				}else if(!checkWall(Direction.RIGHT)) {//no wall on the right
					if(turnTracker<0) {
						robot.rotate(Turn.RIGHT);
						turnTracker++;
					}
				}
			}else {//wall ahead of us
				if(checkWall(Direction.LEFT)) {//if there is a left wall
					robot.rotate(Turn.RIGHT);
					turnTracker++;
				}else if(checkWall(Direction.RIGHT)) {//if there is a right wall but no left wall
					robot.rotate(Turn.LEFT);
					turnTracker--;
				}else {//if there is no right wall or left wall
					if(turnTracker<0) {//if we've made more left turns than right
						robot.rotate(Turn.RIGHT);
						turnTracker++;
					}else if(turnTracker>0) {//if more right turns than left
						robot.rotate(Turn.LEFT);
						turnTracker--;
					}else {//if equal
						if(rand.nextBoolean()) {
							robot.rotate(Turn.LEFT);
							turnTracker--;
						}else{
							robot.rotate(Turn.RIGHT);
							turnTracker++;
						}
					}
				}
			}
			if(!checkWall(Direction.FORWARD)) {
				robot.move(1, false);//move forward
			}
			/*
			if(checkWall(Direction.LEFT) && checkWall(Direction.RIGHT)) {//walls on both sides
				if(!checkWall(Direction.FORWARD)) {
					System.out.println("surrounded by walls on both sides, moving forward");
					robot.move(1,false);
				}else {
					System.out.println("can't move forward, turning around");
					robot.rotate(Turn.LEFT);
					robot.rotate(Turn.LEFT);
					turnTracker-=2;
				}
			}else if(!checkWall(Direction.LEFT)) {//if no wall on the left
				System.out.println("no wall on left");
				if(turnTracker>0) {
					System.out.println("moving left");
					robot.rotate(Turn.LEFT);
					turnTracker--;
				}
			}else if(!checkWall(Direction.RIGHT)) {//if no wall on the right
				System.out.println("no wall on right");
				if(turnTracker<0) {
					System.out.println("moving right");
					robot.rotate(Turn.RIGHT);
					turnTracker++;
				}
			}
			if(checkWall(Direction.FORWARD)) {//if a wall is ahead we need to turn
				System.out.println("wall ahead");
				if(checkWall(Direction.LEFT)) {
					robot.rotate(Turn.RIGHT);
					robot.move(1, false);
					turnTracker++;
				}else if(checkWall(Direction.RIGHT)) {
					robot.rotate(Turn.LEFT);
					robot.move(1, false);
					turnTracker--;
				}else {
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
				}
			}else {//if there's no wall, we can move ahead
				System.out.println("moving forward");
				robot.move(1, false);
			}
			*/
			//Thread.sleep(1000);
		}
		if(robot.isAtExit()) {
			robot.exitMaze();
			return true;
		}
		return false;
	}
	
	public boolean checkWall(Direction direction) throws Exception {
		return robot.distanceToObstacle(direction)==0;
	}
}
