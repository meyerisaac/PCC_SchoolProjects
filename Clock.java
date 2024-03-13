package Clocks;

/** Class for finding and returning the time */
public class Clock
{
    /** Construct object of Clock class */
    public Clock()
    {

    }

    /** Retrieve the current time in the form of a String
     * @return the current time */
    public String getTime()
    {
        String hour = getHour();
        String minute = getMinute();

        return hour + ":" + minute;
    }

    /** Retrieves the current time's hour in String form
     * @return String form of current hour */
    public String getHour()
    {
        String time = java.time.LocalTime.now().toString();
        return (String.valueOf(time.charAt(0)) + String.valueOf(time.charAt(1)));
    }

    /** Retrieves the current time's minute in String form
     * @return String form of the current minute */
    public String getMinute()
    {
        String time = java.time.LocalTime.now().toString();
        return (String.valueOf(time.charAt(3)) + String.valueOf(time.charAt(4)));
    }
}
