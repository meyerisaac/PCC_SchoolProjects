//File Name: ReverseThreeViewer.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadenad.edu
//Assignment: Assignment 4 Chapter 4 Program 4.3
//Description: Calculate and show the sum, difference, and reverse of a given int
//Last Date Changed: 02/09/2023

//Import class files
import javax.swing.*;

public class ReverseThreeViewer
{
    public static void main(String[] args)
    {
        //Get user input
        String numString = JOptionPane.showInputDialog("Input A Number:");
        ReverseThreeCalculator reverse1 = new ReverseThreeCalculator(Integer.parseInt(numString));

        //Calculate and store all numbers
        int num = reverse1.getInt();
        int reverseNum = reverse1.getReverseNum();
        int difference = reverse1.getDifference();
        int reverseDifference = reverse1.getReverse(difference);
        int sum = reverse1.getSum(difference, reverseDifference);

        //Output all numbers
        JOptionPane.showMessageDialog(null, "Input: " + num +
                "\nReverse: " + reverseNum + "\nDifference: " + difference +
                "\nReverse: " + reverseDifference + "\nSum: " + sum);
    }
}