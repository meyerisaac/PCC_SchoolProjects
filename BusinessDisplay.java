package TransactionFiler;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;

public class BusinessDisplay
{
    public static <ArrayList> void main(String[] args)
    {
        File transactionsIn = new File("transactions.txt");
        BusinessReader transactionsReader = new BusinessReader(transactionsIn);
        java.util.ArrayList<String> allTransactions = transactionsReader.getLines();
        java.util.ArrayList<String> transactionCategories = new java.util.ArrayList<>();

        
    }
}