// File name: RomanNumeralTester.java
// Authors: James Donckels & Isaac Meyer
// Last Modified: Feb 16 2023
// Assignment: Chapter 5 Lab 6 Programming Project 5.10
// Description: program to convert integers to roman numerals

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class RomanNumeralTester
{
    public static void main(String[] args)
    {
        final int MAX = 3999;
        String repeatProgram = "Y";

        while (repeatProgram.equals("Y"))
        {
            Logger.getGlobal().setLevel(Level.OFF);
            // set up scanner and input
            Scanner input = new Scanner(System.in);
            System.out.print("Enter a number: ");


            while (!input.hasNextInt()) // validate number input
            {
                System.out.print("\nInvalid input. Please enter a number: ");
                String temp = input.nextLine();
            }
            int numInput = input.nextInt();
            while (numInput <= 0 || numInput > MAX)
            {
                System.out.println("\nInvalid input. Please re-enter a number: ");
                while (!input.hasNextInt()) // validate number input
                {
                    System.out.print("\nInvalid input. Please enter a number: ");
                    String temp = input.nextLine();
                }
                numInput = input.nextInt();
            }

            Logger.getGlobal().info("Input: " + numInput);
            // now we have a validated number

            // construct the converter object with the input number as an instance variable
            RomanNumeralConverter numConverter = new RomanNumeralConverter(numInput);
            Logger.getGlobal().info("Digit test: " +
                    numConverter.convertDigit(8,"I", "V", "X"));

            // Output
            System.out.println("\n" + numInput + " in Roman Numerals: " + numConverter.convertNum());

            System.out.println("\nWould you like to repeat the program? (Y/N)");
            repeatProgram = input.next().toUpperCase();
        }


        System.out.println("\nEnd of program.");
    }
}

/* Sample Run

Enter a number: 72

72 in Roman Numerals: LXXII

Would you like to repeat the program? (Y/N)
y
Enter a number: 57

57 in Roman Numerals: LVII

Would you like to repeat the program? (Y/N)
y
Enter a number: 1978

1978 in Roman Numerals: MCMLXXVIII

Would you like to repeat the program? (Y/N)
n

End of program.

 */