//File Name: ConvertViewer.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 5 Chapter 5 Program 5
//Description: Convert from the specified units to the specified units
//Last Date Changed: 02/16/2023

import javax.swing.*;

public class ConvertViewer
{
    public static void main(String[] args)
    {
        String firstUnit = Converter.getFirstUnit();
        String secondUnit = Converter.getSecondUnit();

        //Prompt user for valid input
        while(!Converter.checkCompatibility())
        {
            JOptionPane.showMessageDialog(null, "Incompatible Units");
            firstUnit = Converter.getFirstUnit();
            secondUnit = Converter.getSecondUnit();
        }

        //Conversions/Inputs and storing values in variable
        Converter.setToBeConverted();
        double first = Converter.getBefore();
        double second = Converter.convert();

        //Display result to user
        JOptionPane.showMessageDialog(null, first + " " + firstUnit + " = " + second + " " + secondUnit);
    }
}

/*Sample Run:
Convert From? gal
Convert To? l
Value: 5
5.0 gal = 18.9270016 l
 */