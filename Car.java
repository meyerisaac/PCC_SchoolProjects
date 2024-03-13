package Lab11.StationSimulation;

import java.util.ArrayList;
import java.util.Random;

public class Car
{
    private ArrayList<Passenger> passengersInCar;
    private int IDNo, location, fares, milesDriven, destination;
    static int previousCarID = 0;
    static final int MAX_PASSENGERS_PER_CAR = 3;
    public Car()
    {
        passengersInCar = new ArrayList<>(0);
        IDNo = previousCarID++;
        previousCarID++;

        Random random = new Random();
        location = random.nextInt(Station.NUM_STATIONS) + 1;
        destination = random.nextInt(Station.NUM_STATIONS) + 1;

        fares = 0;
        milesDriven = 0;
    }

    public void setDestination(int num)
    {
        destination = num;
    }

    public boolean hasArrived()
    {
        if(location == destination)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public boolean hasRoom()
    {
        if(passengersInCar.size() <= MAX_PASSENGERS_PER_CAR)
        {
            return true;
        }
        return false;
    }

    public double getFares()
    {
        return fares;
    }

    public int getMilesDriven()
    {
        return milesDriven;
    }



    public int getLocation()
    {
        return location;
    }

    public int getDestination()
    {
        return destination;
    }

    public boolean addPassenger(Passenger p)
    {
        if(hasRoom())
        {
            passengersInCar.add(p);
            return true;
        }
        return false;
    }

    public void dropoff(int index)
    {
        passengersInCar.remove(index);
    }

    public void drive()
    {
        if(location < destination)
        {
            location++;
        }
        else
        {
            location--;
        }

        fares += Passenger.COST_PER_MILE * passengersInCar.size();
        milesDriven++;
    }

    public String toString()
    {
        return passengersInCar.toString();
    }
}
