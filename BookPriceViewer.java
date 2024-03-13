//File Name: BookPriceViewer.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 4 Chapter 4 Program 4.7
//Description: Calculate the price of a book order after taking into account of tax and shipping fees
//Last Date Changed: 02/09/2023

//Import class files
import javax.swing.*;

public class BookPriceViewer
{
    public static void main(String[] args)
    {
        //Declare and initialize all variables
        int numBooks;
        double orderPrice;

        //Get and validate user input
        do
        {
            String numBooksString = JOptionPane.showInputDialog("How Many Books Ordered: ");
            String orderPriceString = JOptionPane.showInputDialog("Total Price Before All Fees: ");
            numBooks = Integer.parseInt(numBooksString);
            orderPrice = Double.parseDouble(orderPriceString);
        }while(numBooks < 0 || orderPrice < 0);

        //Create object for price calculation
        BookPriceCalculator price1 = new BookPriceCalculator(orderPrice, numBooks);

        //Calculate the total cost
        price1.computeTotalCost();

        //Return/Display the total cost to the user
        System.out.printf("Total Price After All Fees: $%.2f", price1.getTotal());
    }
}

/*Sample Run:
How Many Books Ordered: 20
Total Price Before All Fees: 20

Total Price After All Fees: $61.50
Process finished with exit code 0
 */
