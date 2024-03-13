package Lab11.StationSimulation;

import java.util.ArrayList;
import java.util.Random;

public class Simulation
{
    static final int MAX_STATIONS = 30;
    private Random generator;
    private ArrayList<Car> cars = new ArrayList<>();
    private Station[] stations;
    private double faresCollected = 0.0;
    private double totalRevenuePerMile = 0.0;
    private int milesDriven = 0;

    public Simulation(Random generator)
    {
        this.generator = generator;
    }

    public void loadRandomScenario(int numStations)
    {
        stations = new Station[MAX_STATIONS];

        for(int i = 0; stations.length > i; i++)
        {
            stations[i] = new Station(i + 1);
            int rand = generator.nextInt((MAX_STATIONS * 3) + 10);
            stations[i].setPassengersAtStation(rand);

            for(int j = 0; j < rand / 3; j++)
            {
                Car c = new Car();
                do
                {
                    rand = generator.nextInt(MAX_STATIONS) + 1;
                    c.setDestination(rand);
                }while(rand == c.getDestination());
                cars.add(c);
            }
        }
    }

    public double getRevenuePerMile()
    {
        double totalFare = 0.0;
        double totalMiles = 0.0;
        for(Car c : cars)
        {
            totalFare += c.getFares();
            totalMiles += c.getMilesDriven();
        }
        totalRevenuePerMile = totalFare / totalMiles;
        return totalRevenuePerMile;
    }

    public void addCar(Car car)
    {
        cars.add(car);
    }

    public double getFares()
    {
        return faresCollected;
    }

    public int getMilesDriven()
    {
        return milesDriven;
    }

    public void driveAllCars()
    {
        while (cars.size() > 0)
        {
            for(int i = cars.size() - 1; i >= 0; i--)
            {
                Car car = cars.get(i);
                loadPassengers(stations[car.getLocation() - 1], car);
                car.drive();
                if(car.hasArrived())
                {
                    faresCollected += car.getFares();
                    milesDriven += car.getMilesDriven();
                    cars.remove(i);
                }
            }
        }
    }

    public void loadPassengers(Station station, Car car)
    {
        if(car.hasRoom() && station.hasPeopleWaiting())
        {
            int cDest = car.getDestination();
            for(int i = station.peopleWaiting() - 1; car.hasRoom() && i >= 0; i--)
            {
                Passenger possible = station.get(i);
                int pDest = possible.getDestination();
                int stationNo = station.getNumber();
                if(stationNo > cDest && pDest < stationNo && pDest >= cDest ||
                        stationNo < cDest && pDest > stationNo && pDest <= cDest)
                {
                    car.addPassenger(station.remove(i));
                }
            }
        }
    }

}
