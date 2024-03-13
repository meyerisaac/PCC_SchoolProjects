package Appointments;

/** A class to keep track of an appointment */
public abstract class Appointment
{
    private String description = "";

    /** Constructs an object of Appointment class without a description */
    public Appointment()
    {

    }

    /** Constructs an object of Appointment with a set description
     * @param description String containing the description of the appointment */
    public Appointment(String description)
    {
        this.description = description;
    }

    /** Set the description of the Appointment
     * @param description String containing the description of the appointment */
    public void setDescription(String description)
    {
        this.description = description;
    }

    /**
     Determines if this appointment occurs on the given date.
     @param year the year
     @param month the month
     @param day the day
     @return true if the appointment occurs on the given date.
     */
    public abstract boolean occursOn(int year, int month, int day);

    public String toString()
    {
        return description;
    }
}
