import java.util.Scanner;

// File name: InterestViewer.java
// Authors: James Donckels & Isaac Meyer
// Last Modified: Feb 9 2023
// Assignment: Chapter 5 Lab 4 Programming Project P4.11
// Program to calculate interest
public class InterestViewer {
    public static void main(String[] args)
    {
        // set up scanner for input
        Scanner input = new Scanner(System.in);
        System.out.println("Enter your initial balance: ");
        double userBalance = input.nextDouble();

        InterestCalculator userAcc = new InterestCalculator(userBalance);

        // One month of interest
        userAcc.updateInterest();
        System.out.printf("After first month: %6.3f\n",userAcc.getBalance());
        // test System.out.println(userAcc.getBalance());


        // Second month
        userAcc.updateInterest();
        System.out.printf("After second month:%.2f\n",userAcc.getBalance());
        // test System.out.println(userAcc.getBalance());



        // Third month
        userAcc.updateInterest();
        System.out.printf("After third month: %6.2f\n",userAcc.getBalance());
        // test System.out.println(userAcc.getBalance());


        System.out.println("\nEnd of program.");
    }
}