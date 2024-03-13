package TransactionFiler;

import java.util.ArrayList;
import java.util.Scanner;

public class BusinessWriter
{

    public BusinessWriter()

    static String parseLine(int index, ArrayList<String> list)
    {
        for(int i = 0; i < list.size(); i++)
        {
            if(i == index)
            {
                return list.get(i);
            }
        }
        return null;
    }

    static String getCategory(String line)
    {
        Scanner in = new Scanner(line);
        String next;

        next = in.next();
        next = in.next();//Gets to the second string in

        next = " " + next.substring(1);
        next.trim();

        return next;
    }
}
