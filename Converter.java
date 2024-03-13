//File Name: Converter.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 5 Chapter 5 Program 5
//Description: Convert from the specified units to the specified units
//Last Date Changed: 02/16/2023

import javax.swing.*;
import java.util.Scanner;
import java.lang.Character;
import java.util.logging.Logger;

/** Class for unit conversion */
public class Converter
{
    static final double flozToMl = 29.57344, lToMl = 1000, galToFloz = 128, ozToG = 28.34952, kgToG = 1000,
                    lbToOz = 16, inToMm = 25.4, mmToCm = 0.1, cmToM = 0.01, mToKm = 0.001, ftToIn = 12, miToFt = 5280;
    static final int inputMin = 0;
    static boolean volume1, volume2, weight1, weight2, length1, length2;
    static String unit1, unit2;
    static double toBeConverted, Converted;

    /** Set the first conversion unit
     @return unit to be converted */
    static String getFirstUnit()
    {
        volume1 = false;
        weight1 = false;
        length1 = false;

        do
        {
            String first = JOptionPane.showInputDialog("Convert From?(fl oz, gal, oz, lb, in, ft, mi)");
            first = first.toLowerCase();
            switch(first)
            {
                case "gal":
                    unit1 = "gal";
                    volume1 = true;
                    break;
                case "fl oz":
                    unit1 = "fl oz";
                    volume1 = true;
                    break;
                case "oz":
                    unit1 = "oz";
                    weight1 = true;
                    break;
                case "lb":
                    unit1 = "lb";
                    weight1 = true;
                    break;
                case "in":
                    unit1 = "in";
                    length1 = true;
                    break;
                case "ft":
                    unit1 = "ft";
                    length1 = true;
                    break;
                case "mi":
                    unit1 = "mi";
                    length1 = true;
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Error In getFirstUnit() method");
                    break;
            }
        }while(!volume1 && !weight1 && !length1);
        return unit1;
    }

    /** Set the second conversion unit
     @return unit to be converted into */
    static String getSecondUnit()
    {
        volume2 = false;
        weight2 = false;
        length2 = false;

        do
        {
            String second = JOptionPane.showInputDialog("Convert From?(ml, l, g, kg, mm, cm, m, km)");
            second = second.toLowerCase();
            switch(second)
            {
                case "ml":
                    unit2 = "ml";
                    volume2 = true;
                    break;
                case "l":
                    unit2 = "l";
                    volume2 = true;
                    break;
                case "g":
                    unit2 = "g";
                    weight2 = true;
                    break;
                case "kg":
                    unit2 = "kg";
                    weight2 = true;
                    break;
                case "mm":
                    unit2 = "mm";
                    length2 = true;
                    break;
                case "cm":
                    unit2 = "cm";
                    length2 = true;
                    break;
                case "m":
                    unit2 = "m";
                    length2 = true;
                    break;
                case "km":
                    unit2 = "km";
                    length2 = true;
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Error In getSecondUnit() method");
                    break;
            }
        }while(!volume2 && !weight2 && !length2);
        return unit2;
    }

    /** Check the compatibility of the two units
        @return true or false depending on compatibility */
    static boolean checkCompatibility()
    {
        if((volume1 != volume2) || (weight1 != weight2) || (length1 != length2))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    /** Set the initial num to be converted */
    static void setToBeConverted()
    {
        do
        {
            String in = JOptionPane.showInputDialog("Value? ");
            toBeConverted = Integer.parseInt(in);
        }while(toBeConverted < inputMin);
    }

    /** Convert the given num based on the inputted parameters
        @return converted unit value */
    static double convert()
    {
        if(volume1)
        {
            switch(unit1)
            {
                case "fl oz":
                    Converted = toBeConverted * flozToMl;
                    if(unit2 == "l")
                    {
                        Converted *= (1/lToMl);
                    }
                    break;
                case "gal":
                    Converted = (toBeConverted * galToFloz) * flozToMl;
                    if(unit2 == "l")
                    {
                        Converted *= (1/lToMl);
                    }
                    System.out.println(Converted);
                    break;
            }
        }
        else if(weight1)
        {
            switch(unit1)
            {
                case "oz":
                    Converted = toBeConverted * ozToG;
                    if(unit2 == "kg")
                    {
                        Converted *= (1/kgToG);
                    }
                    break;
                case "lb":
                    Converted = (toBeConverted * lbToOz) * ozToG;
                    if(unit2 == "kg")
                    {
                        Converted *= (1/kgToG);
                    }
                    break;
            }
        }
        else if(length1)
        {
            switch(unit1)
            {
                case "in":
                    Converted = toBeConverted * inToMm;
                    if(unit2 == "cm")
                    {
                        Converted *= mmToCm;
                    }
                    else if(unit2 == "m")
                    {
                        Converted *= (mmToCm * cmToM);
                    }
                    else if(unit2 == "km")
                    {
                        Converted *= (mmToCm * cmToM * mToKm);
                    }
                    break;
                case "ft":
                    Converted = toBeConverted * ftToIn * inToMm;
                    if(unit2 == "cm")
                    {
                        Converted *= mmToCm;
                    }
                    else if(unit2 == "m")
                    {
                        Converted *= (mmToCm * cmToM);
                    }
                    else if(unit2 == "km")
                    {
                        Converted *= (mmToCm * cmToM * mToKm);
                    }
                    break;
                case "mi":
                    Converted = toBeConverted * miToFt * ftToIn * inToMm;
                    if(unit2 == "cm")
                    {
                        Converted *= mmToCm;
                    }
                    else if(unit2 == "m")
                    {
                        Converted *= (mmToCm * cmToM);
                    }
                    else if(unit2 == "km")
                    {
                        Converted *= (mmToCm * cmToM * mToKm);
                    }
                    break;
            }
        }
        else
        {
            JOptionPane.showMessageDialog(null, "Error In convert() method");
        }
        return Converted;
    }

    /** Retrieve the initially inputted num
        @return num of first inputted num*/
    static double getBefore()
    {
        return toBeConverted;
    }
}
