package offlineFive;

// import java.lang.Object for java.lang.Object.toString(); 

public class IntegerInputException extends Exception {
	
	// NOTICE
	
	private int exceptionValue;
	public static final long serialVersionUID = 1L; // NO IDEA what it does. Used just to avoid warning
	
	public IntegerInputException(int exceptionValue) {
		this.exceptionValue = exceptionValue;
	}
	
	@Override
	public String toString() {
		return this.exceptionValue + " is an Invalid Input - Try Again";
	}

}
