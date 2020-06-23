package offlineFive;

public class Sphere implements Volume {

	private double radius;
	private static int sphereCounter = 0;
	
	// Constructor
	public Sphere(double radius) {
		sphereCounter++;
		this.radius = radius;
	}
	
	// Implementation
	public double getVolume() {
		return (4.0/3) * 3.1416 * this.radius * this.radius * this.radius;
	}
	
	public String printShape() {
		return "Sphere" + sphereCounter; 
	}
}
