package offlineFive;

public class Square implements Area {
	
	private double side;
	private static int squareCounter = 0;
	
	// Constructor
	public Square(double side) {
		squareCounter++;
		this.side = side;
	}
	
	// Access Method
	public void setSide(double side) {
		this.side = side;
	}
	
	public double getSide() {
		return this.side;
	}
	
	// Implementation
	public double getArea() {
		return (this.side)*(this.side);
	}
	
	public String printShape() {
		return "Square" + squareCounter;
	}
}
