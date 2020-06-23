package OfflineFour;

import java.lang.String;
import java.util.Scanner;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.ArrayList;
import java.util.List;


public class Main {
	
	private static final String DATABASE_TEXTFILE_NAME = "cars.txt";  // it Acts as global variable being accessible from all classes
	private static List<Car> carList = new ArrayList<Car>(); // NOTICE
	
	// These two variable have something to do with 'static reference'
	
	private Scanner objScanner = new Scanner(System.in);

	public static void main(String[] args) {
		
		Main objMain = new Main(); // NOTICE
		
		String[] arrayInputFile; 
		
		// reading Data from Database Text File
		try {
			String inputtedLine;
			BufferedReader brObj = new BufferedReader(new FileReader(DATABASE_TEXTFILE_NAME) );
			
			while(true) {
				inputtedLine = brObj.readLine();
				
				if(inputtedLine == null) {
					System.out.println("\t=> Data Successfully Read from Text File");
					break;
				}
				
				System.out.println("\t=> Data Reading ...");
				arrayInputFile = inputtedLine.split(",");
				
				// distributing Individual Car Data (array length = 32)
				for(int counter=0; counter<arrayInputFile.length; counter+=8) {
					
					// IMPORTANT !!!!!
					carList.add( new Car( arrayInputFile[counter], Integer.parseInt(arrayInputFile[counter+1]), arrayInputFile[counter+2], arrayInputFile[counter+3], arrayInputFile[counter+4], arrayInputFile[counter+5], arrayInputFile[counter+6], Integer.parseInt(arrayInputFile[counter+7]) ) ); 
				}
			}
			
			brObj.close();
			
		} catch(Exception e) {
			System.out.println("\t=> Error Found While Reading Data from Text File");
			
			e.printStackTrace(); // absolutely no idea what it does -_-
		}
		
		// printing Menu
		objMain.printMainMenu(); // Need to create an object of Main class here
		
		
		// writing Data to Text File
		try {
			
			BufferedWriter bwObj = new BufferedWriter(new FileWriter(DATABASE_TEXTFILE_NAME));
			
			// IMPORTANT !!! 
			System.out.println("\t=>Data writing to Text File ...");
			
			for(int counter=0; counter<carList.size(); counter++) {
				
				bwObj.write( carList.get(counter).getRegistrationNumber() + "," );
				bwObj.write( Integer.toString(carList.get(counter).getYearMade()) + "," ); // for conversion of integer to String
				bwObj.write( carList.get(counter).getColourOne() + "," );
				bwObj.write( carList.get(counter).getColourTwo() + "," );
				bwObj.write( carList.get(counter).getColourThree() + "," );
				bwObj.write( carList.get(counter).getCarMake() + "," );
				bwObj.write( carList.get(counter).getCarModel() + "," );
				bwObj.write( Integer.toString(carList.get(counter).getCarPrice()) );
				
				if(counter<(carList.size()-1))
					bwObj.write(",");
			}
			
			bwObj.close();
			
		} catch (Exception e) {
			System.out.println("\t=> Error Found While Writing Data to Text File");
			
			e.printStackTrace(); // absolutely no idea what it does -_-
		}
		
		System.out.println("\t=>Data Successfully Written to Text File");
		
		System.out.println("\nThank you :D");
		return;
	}
	
	public void printMainMenu() {
		System.out.println("\nMain Menu: \n");
		System.out.println("1. Search Cars");
		System.out.println("2. Add Car");
		System.out.println("3. Delete Car");
		System.out.println("4. Exit System");
		
		System.out.print("\nEnter Your Option (From 1-4) : ");
		int optionInt = objScanner.nextInt();
		objScanner.nextLine(); // IMPORTANT to avoid reading \n from previous input
		
		switch(optionInt) {
		
		case 1:
			printSubMenu(); // Need not to create an object of Main class here
			printMainMenu(); // Need not to create an object of Main class here
			break;
		case 2:
			addCar();
			printMainMenu();
			break;
		case 3:
			deleteCar();
			printMainMenu();
			break;
		case 4:
			break;
		default:
			System.out.println("\nOption Not Found - Kindly choose a Valid Option");
			printMainMenu(); // NOTICE - I can do this !!!
		}
		
		return;
	}
	
	public void printSubMenu() {
		System.out.println("\nCar Searching Options: \n");
		System.out.println("1. By Registration Number");
		System.out.println("2. By Car Make and Car Model");
		System.out.println("3. Back to Main Menu");
		
		System.out.print("\nEnter Your Option (From 1-3) : ");
		int optionInt = objScanner.nextInt();
		objScanner.nextLine(); // IMPORTANT to avoid reading \n from previous input
		
		switch(optionInt) {
				
		case 1:
			searchByRegNum();
			printSubMenu();
			break;
		case 2:
			searchByCarMakeAndCarModel();
			printSubMenu();
			break;
		case 3:
		    break;
		default:
			System.out.println("\nOption Not Found - Kindly choose a Valid Option");
			printSubMenu(); // NOTICE - I can do this !!!
		}
		
		return;		
	}
	
	public void addCar() {
		
		System.out.print("\nEnter the Registration Number of the Car(to be added): ");
		String registrationNumber = objScanner.nextLine();
		// assuming all registration numbers are unique and containing number and uppercase letter (no lowercase letter)
		
		// checking whether the same registration number exists or not
		for(Car identifier : carList) {
			if( registrationNumber.equals(identifier.getRegistrationNumber()) ) {
				System.out.println("\nWe have a Car with Same Reg. Number - Please Try with Another Car");
				return;
			}
		}
		
		// adding Further Information
		System.out.print("\nEnter the Year the Car was Made : ");
		int yearMade = objScanner.nextInt();
		objScanner.nextLine(); // IMPORTANT to avoid reading \n from previous input
		
		System.out.print("\nEnter Car Colour One : ");
		String colourOne = objScanner.nextLine();
		System.out.print("\nEnter Car Colour Two (If not available, then press Enter): ");
		String colourTwo = objScanner.nextLine();
		System.out.print("\nEnter Car Colour Three (If not available, then press Enter): ");
		String colourThree = objScanner.nextLine();
		
		System.out.print("\nEnter the Car Make : ");
		String  carMake = objScanner.nextLine();
		System.out.print("\nEnter the Car Model : ");
		String  carModel = objScanner.nextLine();
		
		System.out.print("\nEnter the Price : ");
		int carPrice = objScanner.nextInt();
		
		carList.add( new Car(registrationNumber, yearMade, colourOne, colourTwo, colourThree, carMake, carModel, carPrice) );
		System.out.println("\nData Successfully Added");
		
		return;
	}
	
	public void deleteCar() {
		
		System.out.print("\nEnter the Registration Number of the Car(to be deleted): ");
		String registrationNumber = objScanner.nextLine();
		
		if( getMatchingIndex(registrationNumber) == -1 ) {
			System.out.println("\nNo Such Car Found - Please Try Again");
		}
		else {
			carList.remove( getMatchingIndex(registrationNumber) );
			System.out.println("\nData Successfully Deleted");
		}
		
		return;
	}
	
	public void searchByRegNum() {
		
		System.out.print("\nEnter the Registration Number of the Car(to be searched): ");
		String registrationNumber = objScanner.nextLine();
		
		if( getMatchingIndex(registrationNumber) == -1 ) 
			System.out.println("\nNo Such Car with this Registration Number Found - Please Try Again");
		else 
			carList.get( getMatchingIndex(registrationNumber) ).printCar();
		
		return;
	}
	
	public int getMatchingIndex(String registrationNumber) {
		
		for(int counter=0; counter<carList.size(); counter++) {
			if( ( registrationNumber.toUpperCase() ).equals(carList.get(counter).getRegistrationNumber()) ) 
				return counter;
		}
		
		return -1;
	}
	
	public void searchByCarMakeAndCarModel() {
		
		int printedCar = 0;
		
		System.out.print("\nEnter the Car Make of the Car(to be searched): ");
		String carMake = objScanner.nextLine();
		
		System.out.print("\nEnter the Car Model (or type ANY for all available models of this Car Make): ");
		String carModel = objScanner.nextLine();
		
		for(int counter = 0; counter<carList.size(); counter++) {
			
			if( ( carMake.toUpperCase() ).equals( carList.get(counter).getCarMake().toUpperCase() ) ) {
				if( ( carModel.toUpperCase() ).equals("ANY") || ( carModel.toUpperCase() ).equals( carList.get(counter).getCarModel().toUpperCase() )) {
					carList.get(counter).printCar();
					printedCar++;
				}
			}
		}
		
		if(printedCar == 0)
			System.out.println("\nNo Such Car with this Car Make and Car Model Found - Please Try Again");
		
		return;
	}
}
