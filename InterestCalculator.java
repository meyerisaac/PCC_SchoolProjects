/**
 * Class to calculate interest.
 */
public class InterestCalculator
{
    // Constants
    private static final double APR = 0.06;

    // Instance variables
    private double balance;

    /**
     * Default Constructor for InterestCalculator object
     */
    public InterestCalculator()
    {
        balance = 0;
    }

    /**
     * Constructor that sets initial balance
     * @param initialBalance the initial balance
     */
    public InterestCalculator(double initialBalance)
    {
        balance = initialBalance;
    }

    /**
     * Compounds the interest for one month
     */
    public void updateInterest()
    {
        balance *= (1.00 + APR/12);
    }

    /**
     * Gets the balance
     * @return the balance
     */
    public double getBalance()
    {
        return balance;
    }


}
