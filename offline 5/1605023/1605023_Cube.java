package offlineFive;

public class Cube implements Volume {

	private double side;
	private static int cubeCounter = 0;
	
	// Constructor
	public Cube(double side) {
		cubeCounter++;
		this.side = side;
	}
	
	// Implementation
	public double getVolume() {
		return this.side * this.side * this.side;
	}
	
	public String printShape() {
		return "Cube" + cubeCounter;
	}
}
