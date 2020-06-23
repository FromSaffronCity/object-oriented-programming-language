package offlineFive;

import java.util.Scanner;

public class Main {
	
	private int option;
	private double input;
	private Scanner objScanner = new Scanner(System.in); // NOTICE
	
	// For Menu
	public void printMenu() {
		
		System.out.println("Please Select Your Choice:");
		System.out.println("1. Circle");
		System.out.println("2. Cylinder");
		System.out.println("3. Sphere");
		System.out.println("4. Square");
		System.out.println("5. Cube");
		System.out.println("6. Exit");
		
		System.out.print("\nEnter Your Choice : ");
		try {
			scanOption();
		} catch(IntegerInputException e) {
			System.out.println("\n" + e+"\n"); // NOTICE, toString() method is called here 
		} 
		// Here, the User can exit only by entering 6
		
		switch(this.option) {
		
		case 1:
			System.out.print("\nEnter Radius : ");
			try {
				scanInput();
			} catch(DoubleInputException e) {
				System.out.println("\n" + e+"\n"); 
				break;
			} 
			
			Circle objCircle = new Circle(input);
			System.out.println("\nName : " + objCircle.printShape());
			System.out.println("Area : " + objCircle.getArea()+"\n");
			break;
			
		case 2:
			double radius, height; // NOTICE
			System.out.print("\nEnter Radius : ");
			try {
				scanInput();
				radius = this.input;
			} catch(DoubleInputException e) {
				System.out.println("\n" + e+"\n"); 
				break;
			} 
			
			System.out.print("Enter Height : ");
			try {
				scanInput();
				height = this.input;
			} catch(DoubleInputException e) {
				System.out.println("\n" + e+"\n"); 
				break;
			}
			
			Cylinder objCylinder = new Cylinder( radius, height);
			System.out.println("\nName : " + objCylinder.printShape());
			System.out.println("Area of the Base : " + objCylinder.getBaseArea());
			System.out.println("Area of the Surface : " + objCylinder.getArea());
			System.out.println("Volume : " + objCylinder.getVolume()+"\n");
			break;
			
		case 3:
			System.out.print("\nEnter Radius : ");
			try {
				scanInput();
			} catch(DoubleInputException e) {
				System.out.println("\n" + e+"\n"); 
				break;
			} 
			
			Sphere objSphere = new Sphere(input);
			System.out.println("\nName : " + objSphere.printShape());
			System.out.println("Volume : " + objSphere.getVolume()+"\n");
			break;
			
		case 4:
			System.out.print("\nEnter Side : ");
			try {
				scanInput();
			} catch(DoubleInputException e) {
				System.out.println("\n" + e+"\n"); 
				break;
			} 
			
			Square objSquare = new Square(input);
			System.out.println("\nName : " + objSquare.printShape());
			System.out.println("Area : " + objSquare.getArea()+"\n");
			break;
			
		case 5:
			System.out.print("\nEnter Side : ");
			try {
				scanInput();
			} catch(DoubleInputException e) {
				System.out.println("\n" + e+"\n"); 
				break;
			} 
			
			Cube objCube = new Cube(input);
			System.out.println("\nName : " + objCube.printShape());
			System.out.println("Volume : " + objCube.getVolume()+"\n");
			break;
		case 6:
			return ;
		}
		
		printMenu();
	}
	
	// For Input
	public void scanInput() throws DoubleInputException {
		this.input = objScanner.nextDouble();
		
		if(this.input < 0) {
			throw new DoubleInputException(this.input);
		}
	}
		
	// For Option
	public void scanOption() throws IntegerInputException {
		this.option = objScanner.nextInt();
		
		if(!(this.option>=1 && this.option<=6)) {
			throw new IntegerInputException(this.option);
		}
	}
	
	// Main Method
	public static void main(String[] args) {
		
		Main objMain = new Main();
		objMain.printMenu();
		
		System.out.println("\nThank You !!!");
		return ;
	}
}
