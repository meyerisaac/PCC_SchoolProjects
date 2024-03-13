package Lab11.StationSimulation;

import java.util.ArrayList;
import java.util.Random;

/** Simple class to represent a pickup, dropoff station. */

public class Station
{
    private ArrayList<Passenger> passengersAtStation;
    private int stationNum;
    static final int MAX_PASSENGERS_STATION = 5;
    static final int NUM_STATIONS = 30;
    static int previousStationNum = 0;

    public Station(int num)
    {
        stationNum = num;
    }

    public void setPassengersAtStation(int numPassengers)
    {
        Random generator = new Random();

        for(int i = 0; i < numPassengers; i++)
        {
            Passenger p = new Passenger();
            int pDest;
            do
            {
                pDest = generator.nextInt(Simulation.MAX_STATIONS) + 1;
            }while(pDest == stationNum);

            String name = "p#" + stationNum + " - " + p.getIDNo();
            p.setDestination(pDest);
            p.setName(name);

            passengersAtStation.add(p);
        }
    }


    public int getNumber()
    {
        return stationNum;
    }

    public void add(Passenger p)
    {
        passengersAtStation.add(p);
    }

    public boolean hasPeopleWaiting()
    {
        if(passengersAtStation.size() > 0)
        {
            for(int i = 0; i < passengersAtStation.size(); i++)
            {
                if(passengersAtStation.get(i).getDestination() != stationNum)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    //Accessor
    public Passenger get(int index)
    {
        //Get passenger
        return passengersAtStation.get(index);
    }

    //Mutator
    public Passenger remove(int index)
    {
        Passenger p = passengersAtStation.get(index);
        passengersAtStation.remove(index);
        return p;
    }

    public int peopleWaiting()
    {
        return passengersAtStation.size();
    }

    public String toString()
    {
        //Returns people.toString()
        return passengersAtStation.toString();
    }
}
