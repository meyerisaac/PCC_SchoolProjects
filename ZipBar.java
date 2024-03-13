//File Name: ZipBar.java
//Author(s): Isaac Meyer & James Donckels
//Email: jdonckels1@go.pasadena.edu & imeyer@go.pasadena.edu
//Assignment: Lab 12 Chapter 8 Program 7
//Description: Write a program that can store and simulate zipcode binary and character values
//Last Date Changed: 03/30/2023

package Lab12ZipCodeProgram;

/** Class keeps track of the binary and character value of each individual bar position in the digit */
public class ZipBar
{
    //Declare instance variables
    private int binaryValue;
    private char symbol;

    /** Constructs object of ZipBar class with integer value
     * @param num binary value of the bar */
    public ZipBar(int num)
    {
        setBinaryValue(num);
    }

    /** Constructs object of ZipBar class with a symbol
     * @param symbol char value of the bar */
    public ZipBar(char symbol)
    {
        setSymbol(symbol);
    }

    /** Set instance variables using an integer
     * @param num binary value of the current ZipBar object */
    public void setBinaryValue(int num)
    {
        if(num == 0)
        {
            binaryValue = 0;
            symbol = ':';
        }
        else if(num == 1)
        {
            binaryValue = 1;
            symbol = '|';
        }
    }

    /** Set instance variables using a character
     * @param Symbol char value of the current ZipBar object */
    public void setSymbol(char Symbol)
    {
        if(symbol == ':')
        {
            binaryValue = 0;
            this.symbol = symbol;
        }
        else if(symbol == '|')
        {
            binaryValue = 1;
            this.symbol = symbol;
        }
    }

    /** Retrieve the binary value of the bar
     * @return integer value of the binary form of bar */
    public int getBinaryValue()
    {
        return binaryValue;
    }

    /** Retrieve the char value of the bar
     * @return char value of the value of the symbol form of bar */
    public String getSymbol()
    {
        return Character.toString(symbol);
    }

}
