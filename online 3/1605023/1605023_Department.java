package onlineOne;

public class Department {

    private int id;
    private String name;
    private Employee[] employees;
    private int employeeCount;
    
    // NOTICE - there can be at most 20 departments (DAMN IMPORTANT)  
    private static Department[] staticArrayDepartment = new Department[20];
    private static int departmentCount = 0; // it is, actually, not needed as departmentCount is automatically assigned with 0

    // you are not allowed to write any other constructor
    public Department(int id, String name) {
        this.id = id;
        this.name = name;
        this.employees = new Employee[10];  // an array containing 10 references to objects of Employee class
        this.employeeCount = 0;  // it is, actually, not needed as employeeCount is automatically assigned with 0

        // DAMN IMPORTANT
        addDepartment(this);  // DAMN IMPORTANT
    }

    // add your code here
    public void addEmployee(Employee objEmployee) {
    	this.employees[employeeCount++] = new Employee(objEmployee.getID(), objEmployee.getName(), objEmployee.getSalary());
    	
    	/*
    	 *  IMPORTANT - this.employees[employeeCount++] = objEmployee; means now, we have two references referring to same object of Employee class
    	 *  this.employees[employeeCount++] = new Employee(objEmployee.getID(), objEmployee.getName(), objEmployee.getSalary()); 
    	 *  means now, we have two references refering to two different objects of Employee class having same information
    	 */
    }
    
    public double getDepartmentSalary() {
    	double totalSalary = 0;
    	
    	for(int counter = 0; counter<this.employeeCount; counter++) {
    		totalSalary += employees[counter].getSalary();
    	}
    	
    	return totalSalary;
    }
    
    public Employee getMaxSalaryEmployee() {
    	int maxIndex = -1;  // NOTICE - IMPORTANT
    	double maxSalary = -1;  // NOTICE - IMPORTANT
    	
    	for(int counter = 0; counter<employeeCount; counter++) {
    		if(maxSalary < employees[counter].getSalary() ) {
    			maxSalary = employees[counter].getSalary();
    			maxIndex = counter;
    		}
    	}
    	
    	return employees[maxIndex];
    }
    
    // DAMN IMPORTANT
    public static double getTotalSalary() {
    	double totalSalary = 0;
    	
    	for(int counter = 0; counter<departmentCount; counter++) {
    		totalSalary += staticArrayDepartment[counter].getDepartmentSalary();
    	}
    	
    	return totalSalary;
    }
    
    // EXTRA
    public int getID() {
    	return this.id;
    }
    
    public String getName() {
    	return this.name;
    }
    
    // EXTRA but DELICIOUSLY IMPORTANT - this method needs not to be static
    public void addDepartment(Department departmentObj) {
    	staticArrayDepartment[departmentCount++] = departmentObj;
    	
    	/*
    	 *  IMPORTANT - staticArrayDepartment[departmentCount++] = departmentObj;
    	 *  means staticArrayDepartment[i] and deparmentObj are two references referring to same object of Department class
    	 *  And, values are added and changed in object, not references
    	 *  HENCE, ANY CHANGES TAKE PLACE IN OBJECT WILL BE VISIBLE BY BOTH NON-STATIC AND STATIC REFERENCES
    	 */
    }
}
