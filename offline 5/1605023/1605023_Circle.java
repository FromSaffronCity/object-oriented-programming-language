package offlineFive;

public class Circle implements Area {
	
	private double radius;
	private static int circleCounter = 0; // static as to make it global. Private as to make it inaccessible from outside the class
	
	// Constructor
	public Circle(double radius) {
		// be sure about one thing, constructor has no return value (not even void)
		
		circleCounter++;
		this.radius = radius;
	}
	
	
	// Access Method
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public double getRadius() {
		return this.radius;
	}
	
	// Implementation
	public double getArea() {
		return 3.1416*(this.radius)*(this.radius);
	}
	
	public String printShape() {
		return "Circle" + circleCounter; // this entire thing is a String here
	}
}
