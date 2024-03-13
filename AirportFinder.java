import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/** Class for finding all airports within a given city */
public class AirportFinder
{
    private Scanner airportScanner;
    private String cityToSearch = "";
    private ArrayList<String> airportsList;


    /** Construct an object of AirportFinder class */
    public AirportFinder()
    {
        airportsList = new ArrayList<>();
    }


    /** Construct an object of AirportFinder class with given parameter
     @param cityName name of the city to find airports in
     @param fileName name of file to look through*/
    public AirportFinder(String cityName, File fileName)
    {
        airportsList = new ArrayList<>();
        cityToSearch = cityName;
        try
        {
            airportScanner = new Scanner(fileName);
        } catch (FileNotFoundException e)
        {
            throw new RuntimeException(e);
        }
    }

    /** Check the given line to see if the searched name and found name match
     @param line String to search through
     @return if found and searched city names match up */
    public boolean checkLine(String line)
    {
        int i = -1;
        int index1;
        do
        {
            i++;
            index1 = i;
        }while(!Character.isDigit(line.charAt(i)));
        int index2 = line.indexOf('"', index1 + 1);
        int index3 = line.indexOf('"', index2 + 1);
        int index4 = line.indexOf('"', index3 + 1);
        int index5 = line.indexOf('"', index4 + 1);

        String currCityName = line.substring(index4 + 1, index5);

        return currCityName.equals(cityToSearch);
    }

    public boolean isNewEntry(String line)
    {
        return (Character.isDigit(line.charAt(0)));
    }

    /** Parse the Airport's name from the given string
     @param line String to grab airport name from
     @return airport name */
    public String parseAirportName(String line)
    {
        int i = -1;
        int index1;
        do
        {
            index1 = i++;
        }while(!Character.isDigit(line.charAt(i)));
        int index2 = line.indexOf('"', index1 + 1);
        int index3 = line.indexOf('"', index2 + 1);

        return line.substring(index2 + 1, index3);
    }

    /** Search through airport.dat and add all airport names to the private ArrayList */
    public void searchAirports()
    {
        String line;

        while(airportScanner.hasNext())
        {
            line = airportScanner.nextLine();

            if(checkLine(line) && isNewEntry(line))
            {
                airportsList.add(parseAirportName(line));
            }
        }
    }
    /** Retrieve and return the private ArrayList
     @return names of all airports with given city */
    public ArrayList<String> getAirportsList()
    {
        return airportsList;
    }
}


