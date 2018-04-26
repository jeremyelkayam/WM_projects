package generation;

import generation.Order.Builder;

/**
 * This class is used to create a test maze for MazeFactoryTest and
 * MazeBuilderEllerTest. It stores relevant information in order to build a
 * maze. An object from this class will be passed onto the test classes.
 */

public class StubOrder implements Order {
	// this class implements the methods of the Order interface
	private int skillLevel;
	private Builder mazeType;
	private boolean perfectMaze;
	private MazeConfiguration mazeConfiguration;
	int percentLoaded;

	public StubOrder(int skill, Builder builder, boolean perfect) {
		// we will store maze attributes like skill level and maze build type into
		// StubOrder
		skillLevel = skill;
		mazeType = builder;
		perfectMaze = perfect;
	}

	@Override
	// returns skill level
	public int getSkillLevel() {
		return skillLevel;
	}

	@Override
	// returns the maze type (File, Prim, Eller, DFS)
	public Builder getBuilder() {
		return mazeType;
	}

	@Override
	// determines whether maze is perfect or not
	public boolean isPerfect() {
		return perfectMaze;
	}

	@Override
	public void deliver(MazeConfiguration mazeConfig) {
		mazeConfiguration = mazeConfig;
	}

	@Override
	public void updateProgress(int percentage) {
		percentLoaded = percentage;
	}

	public MazeConfiguration getMazeDetails() {
		return mazeConfiguration;
	}
}
