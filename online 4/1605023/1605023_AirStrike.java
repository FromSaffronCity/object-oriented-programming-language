package onlineTwo;

import java.lang.String;

public class AirStrike {

    private String source;
    private String destination;
    private int day;
    private int month;
    private int year;
    // you can't have any public/private setter methods for the above 5 variables

    private String encryptedString;
    private String decryptedString;

    // you can't write any other constructor
    public AirStrike(String encryptedString) {
        this.encryptedString = encryptedString;  // when this constructor is called, the constructor of nested class will not be called( unlike its super class if exists)
    }

    // Getter for encryptedString
    public String getEncryptedString() {
        return this.encryptedString;
    }

    // Setter for decryptedString
    public void setDecryptedString(String decryptedString) {
        this.decryptedString = decryptedString;
    }

    // your code here
    
    // static nested class Builder
 	static class Builder {
 		
 		// default constructor
 		public Builder() {
 			System.out.println("\tConstructor of Builder static nested class called\n");
 		}
 		
 		public void build(AirStrike strike) {
 			// as Builder is a static nested class, its methods need to access into member of outer AirStrike class with a reference to object of outer class (No direct access)
 			
 			String[] splittedData = strike.decryptedString.split(",");
 			
 			strike.source = splittedData[0];
 			strike.destination = splittedData[1];
 			strike.day = Integer.parseInt(splittedData[2]);
 			strike.month = Integer.parseInt(splittedData[3]);
 			strike.year = Integer.parseInt(splittedData[4]);
 		}
 	}
    
    // Getters for 5 variables
    public String getSource() {
    	return this.source;
    }
    
    public String getDestination() {
    	return this.destination;
    }
    
    public int getDay() {
    	return this.day;
    }
    
    public int getMonth() {
    	return this.month;
    }
    
    public int getYear() {
    	return this.year;
    }
}