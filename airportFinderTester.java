import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class airportFinderTester
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("What is the city name you are searching for: ");
        String userAns = in.nextLine();

        String fileName = "airport.dat";
        File fileToSearch = new File(fileName);

        AirportFinder tester = new AirportFinder(userAns, fileToSearch);
        tester.searchAirports();

        ArrayList<String> airportsList = tester.getAirportsList();

        System.out.println("All the found airports are: ");

        for(int i = 0; i < airportsList.size(); i++)
        {
            System.out.println(airportsList.get(i));
        }
    }
}