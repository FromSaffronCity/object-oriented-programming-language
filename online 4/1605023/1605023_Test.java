package onlineTwo;

import java.lang.String; // No need to import this indeed :D

public class Test {
    public static void main(String[] args) {
        // TuringMachine machine = new TuringMachine(); - will generate error as there is no public constructor in TuringMachine class
    	System.out.println("\tProgram started\n");
    	
        TuringMachine machine = TuringMachine.getInstance();  // there will be only one object of TuringMachine
        // machine = new TuringMachine();  will generate error for the same reason stated above
        
        String encryptedString = "Fdql`mx+Eq`mbd+0+1+0831";
        AirStrike strike = new AirStrike(encryptedString);
        
        machine.decrypt(strike); 
        // NOTICE - decryption is just the next character ( character = character+1 )
        // next character of '+' is ','
        
        AirStrike.Builder builder = new AirStrike.Builder(); // a reference to object of Builder class is created
        
        builder.build(strike);  
        // Set the variables of AirStrike with decryptedString separated by "," in the order of source, destination, day, month, year
        
        System.out.println("INFORMATION :");
        System.out.println(strike.getSource());
        System.out.println(strike.getDestination());
        System.out.println(strike.getDay());
        System.out.println(strike.getMonth());
        System.out.println(strike.getYear());
    }
}
