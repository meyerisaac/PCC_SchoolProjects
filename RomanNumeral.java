//File Name: RomanNumeral.java
//Author(s): Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 6 Chapter 5 Program 10
//Description: Converts an integer between 0 and 40000 to a Roman Numeral
//Last Date Changed: 02/16/2023

import javax.swing.*;
import java.util.Scanner;

public class RomanNumeral
{
    public static void main(String[] args)
    {
        final int min = 0, max = 40000;
        int input;
        String output;
        Scanner in = new Scanner(System.in);

        do {
            String inputStr = JOptionPane.showInputDialog("Input number to be converted: ");
            input = Integer.parseInt(inputStr);
        }while(input <= min || input >= max);

        //System.out.println(input);

        RomanNumeralConverter converter1 = new RomanNumeralConverter(input);

        converter1.convert();

        output = converter1.getRomanNumeral();

        JOptionPane.showMessageDialog(null, "Your Roman Numeral Is " + output);
    }
}

/* Sample Run:
Input number to be converted: 72
Your Roman Numeral Is : LXXII

Process finished with exit code 0
 */