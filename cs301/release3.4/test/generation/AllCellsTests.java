package generation;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({ CellsTest.class, CellsTestIterator.class })
public class AllCellsTests {
	
	
	StubOrder stub=new StubOrder();
	MazeFactory fac=new MazeFactory();
	Cells cells=new Cells();
	MazeController maze=new MazeController(driver);
	
	
			
			
	fac.order(stub);
	fac.waitTillDelivered();
	mazeConfig = ((StubOrder)stub).getConfiguration();
	cells=mazeConfig.getMazeCells()
}
