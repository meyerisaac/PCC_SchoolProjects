//File Name: DiscountViewer.java
//Author: Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 5Chapter 4 Program 4.12
//Description: Calculate a discount rate based on the number of referrals and rentals that a customer has
//Last Date Changed: 02/09/2023

//Import classes
import javax.swing.*;

public class DiscountViewer
{
    public static void main(String[] args)
    {
        //Declare variables
        int numRef, numRentals;

        //Loop until valid input
        do
        {
            //Get input from user
            String ref = JOptionPane.showInputDialog("Enter number of referrals: ");
            String rent = JOptionPane.showInputDialog("Enter number of rentals: ");

            //Convert String input into int
            numRef = Integer.parseInt(ref);
            numRentals = Integer.parseInt(rent);
        }while(numRef < 0 || numRentals < 0);

        //Create object of DiscountCalculator class
        DiscountCalculator discount1 = new DiscountCalculator(numRentals, numRef);

        //Use calculate method to get interest rate
        double discount = discount1.calculate();

        //Show user the discount
        JOptionPane.showMessageDialog(null, "Discount is: " + discount + " percent");

    }
}