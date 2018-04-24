package generation;

public class StubOrder implements Order {

	@Override
	public int getSkillLevel() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public Builder getBuilder() {
s		return null;
	}

	@Override
	public boolean isPerfect() {
		return true;
	}

	@Override
	public void deliver(MazeConfiguration mazeConfig) {
		// TODO Auto-generated method stub

	}

	@Override
	public void updateProgress(int percentage) {
		// TODO Auto-generated method stub

	}

}
