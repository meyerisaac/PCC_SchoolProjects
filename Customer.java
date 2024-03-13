//File Name: Customer.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 9 Chapter 8 Program 10
//Description: Class that will keep track of customer spending's and award discounts appropriately so
//Last Date Changed: 03/23/2023

package Program10;

/** Class to keep track of customer purchases in different shops */
public class Customer
{
    //Declare all variables needed in class
    private boolean[] shops;
    private double totalSpent, totalDiscount;
    private int discountCounter;
    static final int NUM_SHOPS = 20, NUM_SHOPS_REQUIRED = 3, AMOUNT_NEEDED = 100;
    static final double DISCOUNT = 10.0;

    /** Creates object of Customer class, initializing all the variables */
    public Customer()
    {
        shops = new boolean[NUM_SHOPS];
        for(int i = 0; i < NUM_SHOPS; i++)
        {
            shops[i] = false;
        }
        totalSpent = 0;
        discountCounter = 0;
        totalDiscount = 0;
    }

    /** Update the total amount spent in the object and calculate the discount accumulated
     * @param amount the money spent
     * @param shopNum the shop the money was spent at */
    public void makePurchase(double amount, int shopNum)
    {
        totalSpent += amount;
        markShop(shopNum);

        if(countMarkedShops() >= NUM_SHOPS_REQUIRED)
        {
            totalDiscount = ((int)totalSpent/ AMOUNT_NEEDED) * DISCOUNT;
        }
    }

    /** Reset all instance variable for a fresh start */
    public void reset()
    {
        totalSpent = 0;
        discountCounter = 0;
        totalDiscount = 0;
        for(int i = 0; i < NUM_SHOPS; i++)
        {
            shops[i] = false;
        }
    }

    /** Mark the shop that was bought at in array
     * @param num number of the shop bought at */
    public void markShop(int num)
    {
        shops[num - 1] = true;
    }

    /** Count the number of shops that have been shopped at
     * @return the number of marked shops */
    public int countMarkedShops()
    {
        int counter = 0;
        for(int i = 0; i < NUM_SHOPS; i++)
        {
            if(shops[i])
            {
                counter++;
            }
        }

        return counter;
    }

    /** Retrieve the total money spent by the customer
     * @return the total amount spent */
    public double getTotalSpent()
    {
        return (totalSpent - totalDiscount);
    }

    /** Retrieve the total discount accumulated
     * @return the total amount saved */
    public double getDiscountAmount()
    {
        return (totalDiscount);
    }

    /** Retrieve the total number of shops marked
     * @return the num of shops */
    public int getNumShops()
    {
        return countMarkedShops();
    }
}
