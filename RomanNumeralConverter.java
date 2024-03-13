import java.util.logging.Logger;

/**
 * Class to convert integers to roman numerals.
 */
public class RomanNumeralConverter
{
    // instance variables
    private int num;

    /**
     * Default constructor of RomanNumeralConverter class.
     */
    public RomanNumeralConverter()
    {
        num = 1;
    }

    /**
     * Constructs a RomanNumeralConverter object given a number
     * @param val the number to be converted
     */
    public RomanNumeralConverter(int val)
    {
        num = val;
    }

    /**
     * Gets the number to be converted
     * @return the number to be converted
     */
    public int getNum()
    {
        return num;
    }

    /**
     * Sets the number to be converted
     * @param val the number to be converted
     */
    public void setNum(int val)
    {
        num = val;
    }

    /**
     * Converts num into a string of Roman Numerals.
     * @return Roman Numeral of the number
     */
    public String convertNum()
    {
        int temp = num; // temp is at most a 4 - digit number, and we need each digit individually

        int onesPlace = temp % 10; // ones digit
        temp /= 10; // trim the ones digit from temp

        int tensPlace = temp % 10; // tens digit
        temp /= 10; // trim the tens digit from temp

        int hundredsPlace = temp % 10; // hundreds digit
        temp /= 10; // trim hundreds digit from temp

        int thousandsPlace = temp; // thousands digit will be all that's left after all the trims of temp

        return convertDigit(thousandsPlace, "M", "", "") +
                convertDigit(hundredsPlace, "C", "D", "M") +
                convertDigit(tensPlace, "X", "L", "C") +
                convertDigit(onesPlace, "I", "V", "X");
    }

    /**
     * Converts a single digit to a Roman Numeral
     * @param digit the digit to convert
     * @param one the ones placeholder
     * @param five the middle number
     * @param ten the upper bound for the current digit
     * @return the Roman numeral version of the digit
     */
    public String convertDigit(int digit, String one, String five, String ten)
    {
        switch (digit) {
            case 0:
                return "";
            case 1:
                return one;
            case 2:
                return one + one;
            case 3:
                return one + one + one;
            case 4:
                return one + five;
            case 5:
                return five;
            case 6:
                return five + one;
            case 7:
                return five + one + one;
            case 8:
                return five + one + one + one;
            case 9:
                return one + ten;
            default:
                return "Error in convertDigit";
        }

    }

}
