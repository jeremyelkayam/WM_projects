package generation;

import static org.junit.Assert.*;

import org.junit.Test;

public class MazeFactoryTest {

   /**
	 * 
	 * 
	 */
	public void setUp() {
		
	}
	
	@Test
	public void testDeterministic() {
		
	}
	
	//TODO this
	private boolean checkIfSolvable(MazeContainer m) {
		int[]startpos=m.getStartingPosition();
		if (m.getDistanceToExit(startpos[0],startpos[1])<3) {
			
		}
		return false;
	}
	
	

}
