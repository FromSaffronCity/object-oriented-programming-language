package offlineFive;

// import java.lang.Object for java.lang.Object.toString(); 

public class DoubleInputException extends Exception {
	
	// NOTICE
	
	private double exceptionValue;
	public static final long serialVersionUID = 1L; // NO IDEA what it does. Used just to avoid warning
	
	public DoubleInputException(double exceptionValue) {
		this.exceptionValue = exceptionValue;
	}
	
	@Override
	public String toString() {
		return this.exceptionValue + " is an Invalid Input - Try Again";
	}

}
