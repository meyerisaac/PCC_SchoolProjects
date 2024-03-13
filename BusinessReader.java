package TransactionFiler;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class BusinessReader
{
    Scanner in;

    public BusinessReader(File file)
    {
        try
        {
            in = new Scanner(file);
        } catch (FileNotFoundException e)
        {
            throw new RuntimeException(e);
        }
    }

    public ArrayList<String> getLines()
    {
        ArrayList<String> out = new ArrayList<>();

        while(in.hasNextLine())
        {
            out.add(in.nextLine());
        }

        return out;
    }

}
