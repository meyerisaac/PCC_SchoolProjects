//File Name: ReverseThreeCalculator.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadenad.edu
//Assignment: Assignment 4 Chapter 4 Program 4.3
//Description: Calculate and show the sum, difference, and reverse of a given int
//Last Date Changed: 02/09/2023

/** Class that allows user to utilize methods to
    reverse order of 3 numbers and getting the last 3 numbers of an int */
public class ReverseThreeCalculator
{
    //Declare private int to hold num of object
    private int num, reverseNum;

    /** Get the user number and set private int to the number */
    public ReverseThreeCalculator(int num)
    {
        int hundreds = (num % 1000) / 100;
        int tens = (num % 100) / 10;
        int ones = (num % 10);

        this.num = (hundreds * 100) + (tens * 10) + ones;

        reverseNum = (ones * 100) + (tens * 10) + hundreds;
    }

    /** Get the last 3 numbers of the int variable */
    public int getInt()
    {
        return num;
    }

/** Retrieve the last 3 numbers of an int variable
 @return retrieve the reverse integer */
 public int getReverseNum()
    {
        return reverseNum;
    }

    /** Get difference
     @return return the calculated difference */
    public int getDifference()
    {
        return Math.abs(num - reverseNum);
    }

    /** Get sum
     @return return calculated sum */
    public int getSum(int num, int reverseNum)
    {
        return (num + reverseNum);
    }

    /** Reverse the 3 numbers’ order
     @param num int to be reversed
     @return reversed int */

    public int getReverse(int num)
    {
        int hundreds = (num % 1000) / 100;
        int tens = (num % 100) / 10;
        int ones = (num % 10);

        return ((ones * 100) + (tens * 10) + hundreds);
    }
}
