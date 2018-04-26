package falstad;

import java.util.Arrays;

import falstad.Robot.Turn;
import generation.CardinalDirection;

public class Wizard extends ManualDriver {
	
	public Wizard(MazeController maze) {
		super(maze);
	}
	
	@Override
	public void move(MazeController.UserInput key) {
		super.move(key);
		System.out.print(Arrays.toString(findRelativeNearestNeighbor()));
	}
	
	@Override
	public boolean drive2Exit() throws Exception{
		
		if(robot.isAtExit()) {
			return true;
		}
		return false;
	}
	
	public int[]findRelativeNearestNeighbor(){
		int[]pos=null;
		try {
			pos=robot.getCurrentPosition();
		}catch(Exception e){
			
		}
		int[][]dirs= {{0,1},{1,0},{0,-1},{-1,0}};
		int minDist=Integer.MAX_VALUE;
		int[]minDistPos=dirs[0];
		for(int[]z : dirs) {
			if(!robot.getMaze().hasWall(pos[0],pos[1],CardinalDirection.getDirection(z[0], z[1]))){
				int nextX = pos[0]+z[0];
				int nextY = pos[1]+z[1];
				int currentDist=dist.getDistance(nextX,nextY);
				if(currentDist<minDist){
					minDist=currentDist;
					minDistPos=z;
				}
			}
		}
		
		return minDistPos;
	}
	
	

}
