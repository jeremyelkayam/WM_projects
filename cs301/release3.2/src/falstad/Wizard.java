package falstad;

import java.util.Arrays;

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
			int currentDist=dist.getDistance(pos[0]+z[0],pos[1]+z[1]);
			if(currentDist<minDist){
				minDist=currentDist;
				minDistPos=z;
			}
		}
		
		return minDistPos;
	}
	
	

}
