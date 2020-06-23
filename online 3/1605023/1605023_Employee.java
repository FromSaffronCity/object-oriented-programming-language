package onlineOne;

public class Employee {

    private int id;
    private String name;
    private double salary;

    // you are not allowed to write any other constructor
    public Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    // add your code here
    
    // Getters for the instance variables
    public int getID() {
    	return this.id;
    }
    
    public String getName() {
    	return this.name;
    }
    
    public double getSalary() {
    	return this.salary;
    }
    
    // EXTRA 
    
    @Override
    public String toString() {
    	return "ID: " + this.id + "\n"+"Name: " + this.name + "\n"+"Salary: " + this.salary + "\n";
    }
}
