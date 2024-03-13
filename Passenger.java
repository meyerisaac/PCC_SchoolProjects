package Lab11.StationSimulation;

import java.util.Random;

public class Passenger
{
    private String name;
    private int destination;
    private int IDNo = 0;
    static int previousIDNo = -1;

    static final double COST_PER_MILE = 10.00;

    public Passenger(String name, int destination)
    {
        this.name = name;
        this.destination = destination;
        IDNo = previousIDNo++;
    }

    public Passenger()
    {
        Random random = new Random();
        int rand = random.nextInt(Station.NUM_STATIONS) + 1;
        name = "Undisclosed";
        destination = rand;
        IDNo = previousIDNo++;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public void setDestination(int num)
    {
        destination = num;
    }

    public String getName()
    {
        return name;
    }

    public int getIDNo()
    {
        return IDNo;
    }

    public int getDestination()
    {
        return destination;
    }
}
