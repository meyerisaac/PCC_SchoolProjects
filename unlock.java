//File Name: unlock.java
//Author(s): Isaac Meyer & James Donckels
//Email(s): imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 7 Chapter 6 Program 11
//Description: A program that will let user twist the rings on a combination lock to unlock it
//Last Date Changed: 02/23/2023

import javax.swing.*;

public class unlock
{
    public static void main(String[] args)
    {
        //Declare and initialize variables
        final int TEN = 10, HUNDRED = 100, THOUSAND = 1000;
        String inStr = "", inNumTwist = "";

        //Create object of BikeLock class
        BikeLock lock1 = new BikeLock();

        //Loop until combination is correct
        do
        {
            //Display current combination
            JOptionPane.showMessageDialog(null, "Current Lock: " + lock1.getCurrent());

            //Declare variable to keep track of current ring number
            int ringNum = 1;

            //Loop through the all 4 rings
            for (int i = 1; i <= THOUSAND; i *= TEN)
            {
                //Prompt user for an upward or downward twist on current ring
                do {
                    inStr = JOptionPane.showInputDialog("Ring #" + ringNum + " - U for up / D for down");
                    inStr = inStr.toLowerCase();
                } while (!(inStr.equals("u") || inStr.equals("d")));

                int temp;

                //Prompt user for the number of twists on current ring
                do
                {
                    inNumTwist = JOptionPane.showInputDialog("Number of twists: ");
                    temp = Integer.parseInt(inNumTwist);
                } while (temp < 0);

                //Apply the twists with the methods in BikeLock class
                lock1.twistRing(inStr, temp, ringNum);

                //Update current ring
                ringNum++;
            }

            //Let user know if current combination is still incorrect
            if(!lock1.isCorrect())
            {
                JOptionPane.showMessageDialog(null, "Current Combination Incorrect - Continuing . . . ");
            }
        } while (!lock1.isCorrect());

        //Let user know the combination has been successfully inputted
        JOptionPane.showMessageDialog(null, "Combination Correct!");
    }
}