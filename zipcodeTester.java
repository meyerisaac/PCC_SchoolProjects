//File Name: zipcodeTester.java
//Author(s): Isaac Meyer & James Donckels
//Email: jdonckels1@go.pasadena.edu & imeyer@go.pasadena.edu
//Assignment: Lab 12 Chapter 8 Program 7
//Description: Write a program that can store and simulate zipcode binary and character values
//Last Date Changed: 03/30/2023

package Lab12ZipCodeProgram;

public class zipcodeTester
{
    public static void main(String[] args)
    {
        int example = 12345;

        ZipCode tester1 = new ZipCode(example);

        String out = tester1.getBarForm();;

        System.out.println("Bar Code form of number is " + out);
    }
}