//File Name: TaxCalculator.java
//Author(s): Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu && jdonckels1@go.pasadena.edu
//Assignment: Lab 6 Chapter 5 Program 3
//Description: Calculates taxes based on marital status and income
//Last Date Changed: 02/16/2023

/** Calculates taxes paid when given marital status and income */
public class TaxCalculator
{
    private boolean status;
    private int income;
    private double taxes;
    private static final double ten = 0.10, fifteen = 0.15, twentyfive = 0.25;
    private static final int singleMin = 0, singleLow = 8000, singleHigh = 32000, marriedMin = 0, marriedLow = 16000, marriedHigh = 64000,
                            singleBaseLow = 800, singleBaseHigh = 4400, marriedBaseLow = 1600, marriedBaseHigh = 8800;

    /** Creates object of TaxCalculator class
        @param income income of user
        @param status marital status of user */
    public TaxCalculator(boolean status, int income)
    {
        //Set the instance variables with the given parameters
        this.status = status;
        this.income = income;
    }

    /** Calculates the taxes based on the inputted parameters */
    public void calculateTaxes()
    {
        //Apply taxes based on marital status
        if(status)
        {
            if(income > singleMin && income <= singleLow)
            {
                taxes = income * ten;
            }
            else if(income > singleLow && income <= singleHigh)
            {
                taxes = singleBaseLow + ((income - singleLow) * fifteen);
            }
            else
            {
                taxes = singleBaseHigh + ((income - singleHigh) * twentyfive);
            }
        }
        else
        {
            if(income > marriedMin && income <= marriedLow)
            {
                taxes = income * ten;
            }
            else if(income > marriedLow && income <= marriedHigh)
            {
                taxes = marriedBaseLow + ((income - marriedLow) * fifteen);
            }
            else
            {
                taxes = marriedBaseHigh + ((income - marriedHigh) * twentyfive);
            }
        }
    }

    /** Returns the taxes calculated in the object
        @return taxes paid*/
    public double getTaxes()
    {
        return taxes;
    }
}
