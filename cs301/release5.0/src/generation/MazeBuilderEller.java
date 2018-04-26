package generation;

/**
 * This class has the responsibility to create a maze of given dimensions
 * (width, height) together with a solution based on a distance matrix. The
 * MazeBuilder implements Runnable such that it can be run a separate thread.
 * The MazeFactory has a MazeBuilder and handles the thread management.
 * 
 * 
 * The maze is built with a randomized version of Eller's algorithm. This means
 * a spanning tree is expanded into a set of cells by removing walls from the
 * maze. Algorithm leaves walls in tact that carry the border flag. Borders are
 * used to keep the outside surrounding of the maze enclosed and to make sure
 * that rooms retain outside walls and do not end up as open stalls.
 * 
 * @author Jones.Andrew, refactored pk
 */

public class MazeBuilderEller extends MazeBuilder implements Runnable {

	public MazeBuilderEller() {
		super();
		System.out.println("MazeBuilderPrim uses Eller's algorithm to generate maze.");
	}

	public MazeBuilderEller(boolean det) {
		super(det);
		System.out.println("MazeBuilderPrim uses Ellers's algorithm to generate maze.");
	}

	@Override
	protected void generatePathways() {
		int[][] set = new int[width][height];
		int i;
		int num_rows = width; // used for creating new sets when shifting row down
		int row = 0;
		int column = 0;
		int rand = 0; // for use w/ random
		Wall wall_south;
		Wall wall_east = null;

		while (row != height) {

			// either initialize or copy sets from previous row
			if (row == 0) {
				// add each cell in the first row to its own set
				for (i = 0; i < width; i++)
					set[i][0] = i;
			}
			// copy top row. If a cell has a wall above it, put it in its own class
			else {
				for (i = 0; i < width; i++) {
					if (cells.hasWall(i, row, CardinalDirection.North))
						set[i][row] = num_rows++;
					else
						set[i][row] = set[i][row - 1];
				}
			}
			// horizontal pathing
			while (column != width) {

				// check for the last row
				if (row == (height - 1)) {
					for (i = 0; i < (width - 1); i++) {
						if (set[i][row] != set[i + 1][row])
							wall_east = new Wall(i, row, CardinalDirection.East);
						cells.deleteWall(wall_east);
					}
					break;
				}

				if (column != (width - 1)) {

					if (set[column][row] != set[column + 1][row]) {
						// get a random number between 0,1

						rand = random.nextIntWithinInterval(0, 1);
					} else {
						column = column + 1;
						continue;
					}
				} else {
					column = column + 1;
					continue;
				}

				// knock down wall
				if (rand == 0) {
					wall_east = new Wall(column, row, CardinalDirection.East);
					cells.deleteWall(wall_east);
					set[column + 1][row] = set[column][row];
				} else
					column = column + 1;
			}

			column = 0;
			// vertical pathing
			while (column != width) {
				if (row == (height - 1))
					break;

				int startCol = column;

				if (column == (width - 1)) { // only gets here is last col is not in set w/ 2nd to last
					wall_south = new Wall(column, row, CardinalDirection.South);
					cells.deleteWall(wall_south);
					break;
				}

				while (true) {

					if (column == (width - 1))
						break;
					if (set[column][row] == set[column + 1][row]) {
						column++;
						continue;
					} else
						break;

				}
				// delete one wall randomly from the set of walls on the bottom
				rand = random.nextIntWithinInterval(startCol, column);
				wall_south = new Wall(rand, row, CardinalDirection.South);
				cells.deleteWall(wall_south);
				column++;

			}
			// increment the row, and do the whole thing again.
			row = row + 1;
			column = 0;
		}
	}

}