package OfflineFour;

public class Car {
    
	private String registrationNumber;
	private int yearMade;
	private String colourOne;
	private String colourTwo;
	private String colourThree;
	private String carMake;
	private String carModel;
	private int carPrice;
	
	// To avoid complexity while reading and writing data from/to text file, array for color is avoided
	
	// Constructor
	public Car(String registrationNumber, int yearMade,String colourOne, String colourTwo, String colourThree, String carMake, String carModel, int carPrice) {
		this.registrationNumber = registrationNumber;
		this.yearMade = yearMade;
		this.colourOne = colourOne;
		this.colourTwo = colourTwo;
		this.colourThree = colourThree;
		this.carMake = carMake;
		this.carModel = carModel;
		this.carPrice = carPrice;
	}
	
	// Accessor Methods for registrationNumber
	public void setRegistrationNumber(String registrationNumber) {
		this.registrationNumber = registrationNumber;
	}
	
	public String getRegistrationNumber() {
		return this.registrationNumber;
	}
	
	// Accessor Methods for yearMade
	public void setYearMade(int yearMade) {
		this.yearMade = yearMade;
	}
	
	public int getYearMade() {
		return this.yearMade;
	} 
	
	// Accessor Methods for colourOne
	public void setColourOne(String colourOne) {
		this.colourOne = colourOne;
	}
	
	public String getColourOne() {
		return this.colourOne;
	}
	
	// Accessor Methods for colourTwo
	public void setColourTwo(String colourTwo) {
		this.colourTwo = colourTwo;
	}
	
	public String getColourTwo() {
		return this.colourTwo;
	}
	
	// Accessor Methods for colourThree
	public void setColourThree(String colourThree) {
		this.colourThree = colourThree;
	}
	
	public String getColourThree() {
		return this.colourThree;
	}
	
	// Accessor Methods for carMake
	public void setCarMake(String carMake) {
		this.carMake = carMake;
	}
	
	public String getCarMake() {
		return this.carMake;
	}
	
	// Accessor Methods for carModel
	public void setCarModel(String carModel) {
		this.carModel = carModel;
	}
	
	public String getCarModel() {
		return this.carModel;
	}
	
	// Accessor Methods for carPrice
	public void setCarPrice(int carPrice) {
		this.carPrice = carPrice;
	}
	
	public int getCarPrice() {
		return this.carPrice;
	} 
	
	// Another Method
	public void printCar() {
		System.out.println("\nRegistration Number : " + this.registrationNumber);
		System.out.println("Year Made : " + this.yearMade);
		System.out.println("Car Colour One : " + this.colourOne);
		System.out.println("Car Colour Two : " + this.colourTwo);
		System.out.println("Car Colour Three : " + this.colourThree);
		System.out.println("Car Make : " + this.carMake);
		System.out.println("Car Model : " + this.carModel);
		System.out.println("Price : " + this.carPrice);
	}
}
