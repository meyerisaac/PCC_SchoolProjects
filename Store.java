import java.util.ArrayList;
import java.util.Collections;


public class Store
{
    //Declare instance variables
    private ArrayList<Customer> customerList;

    /** Constructs a store object
     customerList initially size 0 */
     public Store()
    {

    }

    /** Create a new obj Adds a customer object with a given sale to the list of customers
     * @param customerName the name of the customer
     * @param amount the value of the customer’s sale */
    public void addSale(String customerName, double amount)
    {

    }

    public void sortCustomers()
    {
        Collections.sort(customerList);
    }

    /** returns a list of the best customers
     * @param topN the number of customers to put in the list
     * @return an arrayList of customer names */
    public ArrayList<String> nameOfBestCustomers(int topN)
    {

        return customerList;
    }
}
