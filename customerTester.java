//File Name: customerTester.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 9 Chapter 8 Program 10
//Description: Class that will keep track of customer spending's and award discounts appropriately so
//Last Date Changed: 03/23/2023

package Program10;

import java.util.Scanner;

public class customerTester
{
    public static void main(String[] args)
    {
        //Create object of Customer class
        Customer Bob = new Customer();
        Scanner in = new Scanner(System.in);

        //Declare variables needed
        int ans = 1, shopNum;
        double amountPaid;

        //Loop as long as user desires
        do
        {
            //Prompt user input for shop to make purchase at
            do
            {
                System.out.println("What shop will you make a purchase in?(1 - 20)");
                shopNum = in.nextInt();
            } while (shopNum > Customer.NUM_SHOPS || shopNum <= 0);

            //Prompt user for amount of the purchase
            do
            {
                System.out.println("How much is the purchase? ");
                amountPaid = in.nextDouble();
            } while (amountPaid <= 0);

            //Make the purchase in the object
            Bob.makePurchase(amountPaid, shopNum);

            //Update the user on the object information
            System.out.println("Total Spent(Discount Included) = $" + Bob.getTotalSpent() + "\nTotal Discount = $" + Bob.getDiscountAmount() + "\nNumber of Shops = " + Bob.getNumShops());

            System.out.println("Do you want to continue? 0 for No / Any # for Yes");
            ans = in.nextInt();
        }while(ans != 0);
    }
}

/* Sample Run:
What shop will you make a purchase in?(1 - 20)
2
How much is the purchase?
20
Total Spent(Discount Included) = $20.0
Total Discount = $0.0
Number of Shops = 1
Do you want to continue? 0 for No / Any # for Yes
2
What shop will you make a purchase in?(1 - 20)
2
How much is the purchase?
10
Total Spent(Discount Included) = $30.0
Total Discount = $0.0
Number of Shops = 1
Do you want to continue? 0 for No / Any # for Yes
3
What shop will you make a purchase in?(1 - 20)
3
How much is the purchase?
13
Total Spent(Discount Included) = $43.0
Total Discount = $0.0
Number of Shops = 2
Do you want to continue? 0 for No / Any # for Yes
5
What shop will you make a purchase in?(1 - 20)
7
How much is the purchase?
57
Total Spent(Discount Included) = $90.0
Total Discount = $10.0
Number of Shops = 3
Do you want to continue? 0 for No / Any # for Yes
0

Process finished with exit code 0
 */