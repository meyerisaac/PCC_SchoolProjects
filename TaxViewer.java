//File Name: TaxViewer.java
//Author(s): Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu && jdonckels1@go.pasadena.edu
//Assignment: Lab 6 Chapter 5 Program 3
//Description: Calculates taxes based on marital status and income
//Last Date Changed: 02/16/2023

import javax.swing.*;

public class TaxViewer
{
    public static void main(String[] args)
    {
        //Declare variables
        final int minIncome = 0;
        boolean singleStatus = true, statusValid;
        int income;
        double taxes;

        //Prompt user for single status
        do
        {
            String input = JOptionPane.showInputDialog("Are you single?\nY for yes / N for no : ");
            if(input.toLowerCase() == "y")
            {
                singleStatus = true;
                statusValid = true;
            }
            else if(input.toLowerCase() == "n")
            {
                singleStatus = false;
                statusValid = true;
            }
            else
            {
                statusValid = false;
            }
        }while(statusValid);

        //Prompt user for income
        do
        {
            String incomeInput = JOptionPane.showInputDialog("What is your income: ");
            income = Integer.parseInt(incomeInput);
        }while(income < minIncome);

        //Create object with given parameters
        TaxCalculator calculator = new TaxCalculator(singleStatus, income);

        //Calculate taxes
        calculator.calculateTaxes();

        //Store taxes in variable
        taxes = calculator.getTaxes();

        //Display the taxes variable to the user
        JOptionPane.showMessageDialog(null, "Your taxes are $" + taxes);
    }
}

/*Sample Run:
Are you single?
Y for yes / N for no : y
What is your income: 40000

Your taxes are $6400

Process finished with exit code 0
 */