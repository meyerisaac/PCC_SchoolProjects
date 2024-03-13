//File Name: ZipCode.java
//Author(s): Isaac Meyer & James Donckels
//Email: jdonckels1@go.pasadena.edu & imeyer@go.pasadena.edu
//Assignment: Lab 12 Chapter 8 Program 7
//Description: Write a program that can store and simulate zipcode binary and character values
//Last Date Changed: 03/30/2023

package Lab12ZipCodeProgram;

/**
 * Class to represent a zipcode by digits which could be in number form or bar form.
 */
public class ZipCode
{
    private ZipDigit[] digits;

    public static final int ZIP_CODE_SIZE = 6;

    /**
     * Constructs a zip code given a code
     */
    public ZipCode(int code)
    {
        int temp = code;
        int d1 = temp % 10;
        temp /= 10;
        int d2 = temp % 10;
        temp /= 10;
        int d3 = temp % 10;
        temp /= 10;
        int d4 = temp % 10;
        temp /= 10;
        int d5 = temp;

        int checkDigit = 10 - ((d1 + d2 + d3 + d4 + d5) % 10);

        digits = new ZipDigit[ZIP_CODE_SIZE];
        digits[0] = new ZipDigit(d1);
        digits[1] = new ZipDigit(d2);
        digits[2] = new ZipDigit(d3);
        digits[3] = new ZipDigit(d4);
        digits[4] = new ZipDigit(d5);
        digits[5] = new ZipDigit(checkDigit);

    }

    /**
     * @return the full zipcode in bar code form
     */
    public String getBarForm()
    {
        String temp = "|"
                + digits[0].getBarCode()
                + digits[1].getBarCode()
                + digits[2].getBarCode()
                + digits[3].getBarCode()
                + digits[4].getBarCode()
                + digits[5].getBarCode()
                + "|";
        return temp;
    }


}
