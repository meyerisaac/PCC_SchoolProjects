package Clocks;

/** Class for calculating times in other time zones */
public class WorldClock extends Clock
{
    private int timeZoneDiff;

    /** Constructs WorldCLock with no parameters */
    public WorldClock()
    {
        timeZoneDiff = 0;
    }

    /** Constructs a WorldClock with a set time zone difference
     * @param timeZoneDiff num of time zones the created object is away from current time zone */
    public WorldClock(int timeZoneDiff)
    {
        this.timeZoneDiff = timeZoneDiff;
    }

    /** Retrieves the time's hour in String form
     * @return String form of the hour */
    @Override
    public String getHour()
    {
        String originalTime = java.time.LocalTime.now().toString();
        int time = Integer.parseInt(String.valueOf(originalTime.charAt(0)) + String.valueOf(originalTime.charAt(1)));
        time += timeZoneDiff;
        return String.valueOf(time);
    }
}
