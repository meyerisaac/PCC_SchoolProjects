//File Name: BookPriceCalculator.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 4 Chapter 4 Program 4.7
//Description: Calculate the price of a book order after taking into account of tax and shipping fees
//Last Date Changed: 02/09/2023

/** Class used for the calculation of total cost of book orders */
public class BookPriceCalculator {

    private double totalCost;
    private int numOfBooks;
    private static final double bookTax = 0.075;
    private static final int shippingFeePerBook = 2;

    /** Creates object of BookOrder class
     @param totalCost  set instance variable totalCost to this num
     @param numOfBooks set instance variable numOfBooks to this num */
    public BookPriceCalculator(double totalCost, int numOfBooks)
    {
        this.totalCost = totalCost;
        this.numOfBooks = numOfBooks;
    }

    /** Calculate the total cost of the book order after taxes and shipping fees */
    public void computeTotalCost()
    {
        totalCost *= (1.0 + bookTax);
        totalCost += (shippingFeePerBook * numOfBooks);
    }

    /** Retrieves the total cost of the order
     @return total cost of the book order */
    public double getTotal()
    {
        return totalCost;
    }
}
