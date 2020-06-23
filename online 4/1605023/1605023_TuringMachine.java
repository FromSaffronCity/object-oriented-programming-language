package onlineTwo;

import java.lang.String;
import java.lang.StringBuffer;

public class TuringMachine {
    // you can have only one constructor of TuringMachine and that won't take any parameters
    // your code here
	
	private static TuringMachine objTM = new TuringMachine();  // NOTICE - objTM = the reference to only object of this class
	
	// private constructor to ensure, only one object of this class can be created
	private TuringMachine() {
		System.out.println("\tConstructor of TuringMachine class called\n");
		
		// it actually has no functionality
		// Just need to provide a default constructor for the declaration of objTM reference
		// in fact, without this defined constructor, objTM can be declared
	}
	
	// static method
	public static TuringMachine getInstance() {
		return objTM; // static reference returned
	}
	
	// another method - NOTICE
    public void decrypt(AirStrike strike) {
        String encryptedString = strike.getEncryptedString();
        
        // your code here
        
        StringBuffer stringBufferObj = new StringBuffer(); // a reference to object of StringBuffer class created
        
        System.out.println("\t=> InitialCapacity of stringBufferObj = " + stringBufferObj.capacity());
        System.out.println("\t=> Initial Length of stringBufferObj = " + stringBufferObj.length()+"\n");
        
        // NOTICE
        for(int counter=0; counter<encryptedString.length(); counter++) {
        	stringBufferObj.append( (char)( ( encryptedString.charAt(counter) ) + 1 ) ); // NOTICE - damn problematic (conversion of integer to character)
        	
        	// System.out.println(encryptedString.charAt(0) + 1); parameter is actually an integer
        	// IMPORTANT - if we do not convert integer to character in the above line of code, the ASCII value of the character will be appended to strinBufferObj instead of character itself 
        	
        	// stringBufferObj.append( (String)( encryptedString.charAt(counter) + 1 ) ); - we can not do this because we can not convert integer to String
        	// stringBufferObj.append( encryptedString.charAt(counter) + 1  ); - we can not do this because the parameter is integer instead of String or character
        	
        	System.out.println("\t=> Current Capacity of stringBufferObj = " + stringBufferObj.capacity());
            System.out.println("\t=> Current Length of stringBufferObj = " + stringBufferObj.length()+"\n");
        }
        
        strike.setDecryptedString( new String(stringBufferObj) ); // set decryptedString here
    }
}

