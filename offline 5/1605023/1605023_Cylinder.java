package offlineFive;

public class Cylinder implements Area, Volume {
	
	// NOTICE this class
	
	private double radius;
	private double height;
	private static int cylinderCounter = 0;
	
	// Constructor
	public Cylinder(double radius, double height) {
		cylinderCounter++;
		this.radius = radius;
		this.height = height;
	}
	
	// Implementation
	public double getArea() {
		// this method returns the surface area of Cylinder
		
		return 2*3.1416*this.height*this.radius;
	}
	
	public double getVolume() {
		return 3.1416 * this.radius * this.radius * this.height;
	}
	
	public String printShape() {
		return "Cylinder" + cylinderCounter;
	}
	
	// Another Area
	public double getBaseArea() {
		// this method returns the base area of Cylinder
		
		return 3.1416 * this.radius * this.radius;
	}
}
