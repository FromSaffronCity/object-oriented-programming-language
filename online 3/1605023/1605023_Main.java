package onlineOne;

import java.util.Random;  // Random is a class from java.util package

public class Main {
    public static void main(String[] args) {
        Employee[] e = new Employee[6];  // an array containing 6 references to objects of Employee class
        
        Random r = new Random();  // a reference to object of Random class created (for generating random numbers)
        
        for (int i = 0; i < 6; i++) {
            e[i] = new Employee(i+1, "E" + (i+1), 10000 * r.nextDouble());  // NOTICE - creating new employee
            
            // "E" + (i+1) is a String 
            // java.util.Random.nextDouble() method returns a random double value ranged between 0.0 to 1.0
        }
        
        // EXTRA
        for (int i = 0; i < 6; i++) {
            System.out.println(e[i]);
        }
        
        Department[] d = new Department[2];  // an array containing 2 references to objects of Department class
        
        for (int i = 0; i < 2; i++) {
            d[i] = new Department(i+1, "D" + (i+1));  // creating new department
        }
        
        // PROCESS 1
        d[0].addEmployee(e[0]); // add the employee to this department
        d[0].addEmployee(e[1]); // add the employee to this department
        d[1].addEmployee(e[2]); // add the employee to this department
        d[1].addEmployee(e[3]); // add the employee to this department
        d[1].addEmployee(e[4]); // add the employee to this department
        d[1].addEmployee(e[5]); // add the employee to this department
        
        // PROCESS 2
        System.out.println("Total Salary for Department 1:" + d[0].getDepartmentSalary()); // prints the total salary of this department
        System.out.println("Total Salary for Department 2:" + d[1].getDepartmentSalary()); // prints the total salary of this department
        
        // PROCESS 3
        System.out.println("\nMax Wager of Department 1:" + d[0].getMaxSalaryEmployee().getName()); // prints the name of the employee with highest salary in this department
        System.out.println("Max Wager of Department 1:" + d[1].getMaxSalaryEmployee().getName()); // prints the name of the employee with highest salary in this department
        
        // PROCESS 4
        System.out.println("\nTOTAL SALARY:" + Department.getTotalSalary()); // prints the total salary of all departments
        // getTotalSalary() is a static method
    }
}