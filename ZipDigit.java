//File Name: ZipDigit.java
//Author(s): Isaac Meyer & James Donckels
//Email: jdonckels1@go.pasadena.edu & imeyer@go.pasadena.edu
//Assignment: Lab 12 Chapter 8 Program 7
//Description: Write a program that can store and simulate zipcode binary and character values
//Last Date Changed: 03/30/2023

package Lab12ZipCodeProgram;

import static java.lang.Integer.parseInt;

/** Class for keeping track of an individual digit */
public class ZipDigit
{
    //Declare instance variables
    static final int NUM_BARS = 5;
    static final int VALUE_ONE = 7;
    static final int VALUE_TWO = 4;
    static final int VALUE_THREE = 2;
    static final int VALUE_FOUR = 1;
    static final int VALUE_FIVE = 0;

    private ZipBar[] bars;
    private int num;
    private String allNum;
    private String allBars;

    /** Creates object of ZipDigit class
     * @param num the number to be intialized in this digit */
    public ZipDigit(int num)
    {
        bars = new ZipBar[NUM_BARS];

        for(int i = 0; i < NUM_BARS; i++)
        {
            bars[i] = new ZipBar(0);
        }

        for(int i = 0; i < bars.length; i++)
        {
            bars[i].setBinaryValue(0);
        }
        int temp = num;

        if(temp >= VALUE_ONE)
        {
            temp -= VALUE_ONE;
            bars[0].setBinaryValue(1);
        }
        else
        {
            bars[0].setBinaryValue(0);
        }
        if(temp >= VALUE_TWO)
        {
            temp -= VALUE_TWO;
            bars[1].setBinaryValue(1);
        }
        else
        {
            bars[1].setBinaryValue(0);
        }
        if(temp >= VALUE_THREE)
        {
            temp -= VALUE_THREE;
            bars[2].setBinaryValue(1);
        }
        else
        {
            bars[2].setBinaryValue(0);
        }
        if(temp >= VALUE_FOUR)
        {
            temp -= VALUE_FOUR;
            bars[3].setBinaryValue(1);
        }
        else
        {
            bars[3].setBinaryValue(0);
        }
        if(getBinaryTotal() == 1)
        {
            bars[4].setBinaryValue(1);
        }
        else
        {
            bars[4].setBinaryValue(0);
        }

        this.num = num;
        allBars = numToSymbol(num);
    }

    /** Creates object of ZipDigit class
     * @param barCode the number of the digit in barcode form */
    public ZipDigit(String barCode)
    {
        bars = new ZipBar[NUM_BARS];

        for(int i = 0; i < NUM_BARS; i++)
        {
            bars[i] = new ZipBar(0);
        }

        allBars = barCode;
        num = symbolToNum();
    }

    /** Returns a number based on symbols
     * @param num number to be converted
     * @return symbol form of the converted num*/
    public String numToSymbol(int num)
    {
        String numInSymbol = String.valueOf(num);
        String out = "";
        int count = 0;
        int temp = num;

        if(temp >= VALUE_ONE)
        {
            temp -= VALUE_ONE;
            out += "|";
            count++;
        }
        else
        {
            out += ":";
        }
        if(temp >= VALUE_TWO)
        {
            temp -= VALUE_TWO;
            out += "|";
            count++;
        }
        else
        {
            out += ":";
        }
        if(temp >= VALUE_THREE)
        {
            temp -= VALUE_THREE;
            out += "|";
            count++;
        }
        else
        {
            out += ":";
        }
        if(temp >= VALUE_FOUR)
        {
            temp -= VALUE_FOUR;
            out += "|";
            count++;
        }
        else
        {
            out += ":";
        }
        if(count == 1)
        {
            out += "|";
        }
        else
        {
            out += ":";
        }

        return out;
    }

    /** Returns the number value of the symbols */
    public int symbolToNum()
    {
        int total = 0;

        for(int i = 0; i < bars.length; i++)
        {
            switch(i)
            {
                case 0:
                    total = addIfOne(total, i);
                case 1:
                    total = addIfOne(total, i);
                case 2:
                    total = addIfOne(total, i);
                case 3:
                    total = addIfOne(total, i);
                case 4:
                    total = addIfOne(total, i);
                default:
                    break;
            }
        }
        return total;
    }

    /** Get the total of 1s in the array
     * @return integer value of number of 1s */
    public int getBinaryTotal()
    {
        int total = 0;

        for(int i = 0; i < bars.length; i++)
        {
            total += bars[i].getBinaryValue();
        }

        return total;
    }

    /** Add value if the total value if the asociated binary value is 1
     * @param total number to be added to
     * @param add number to add
     * @return the new total after applying changes */
    public int addIfOne(int total, int add)
    {
        int tempTotal = total;
        if(bars[add].getBinaryValue() == 1)
        {
            switch(add)
            {
                case 0:
                    return (tempTotal += VALUE_ONE);
                case 1:
                    return (tempTotal += VALUE_TWO);
                case 2:
                    return (tempTotal += VALUE_THREE);
                case 3:
                    return (tempTotal += VALUE_FOUR);
                case 4:
                    return (tempTotal += VALUE_FIVE);
                default:
                    System.out.println("Error in addIfOne() method!");
                    break;
            }
        }
        return tempTotal;
    }

    /** Returns bar code form of the ZipDigit
     * @return String of the bar code */
    public String getBarCode()
    {
        return allBars;
    }
}
