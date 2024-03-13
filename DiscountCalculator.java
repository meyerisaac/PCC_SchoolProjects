
/** Calculate the discount of a customer using the number of referrals and rentals by a customer */

public class DiscountCalculator
{
    private int numRentals;
    private double numRef;
    private static final double maxDiscount = 75.0;

    /** Creates an object of DiscountCalculator class */
    public DiscountCalculator()
    {
        numRentals = 0;
        numRef = 0;
    }

    /** Creates object of DIscountCalculator class with initial parameters
     @param numRef number of referrals
     @param numRentals number of rentals */
    public DiscountCalculator(int numRentals, int numRef)
    {
        this.numRentals = numRentals;
        this.numRef = numRef;
    }

    /** Calculates the discount rate
     @return discount rate */
    public double calculate()
    {
        double discount = numRef + numRentals;
        return Math.min(discount,maxDiscount);
    }
}
