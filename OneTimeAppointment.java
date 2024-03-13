package Appointments;

/** Class to keep track of a one time appointment */
public class OneTimeAppointment extends Appointment
{
    private int day;
    private int month;
    private int year;

    /** Construct an one time appointment with default parameters */
    public OneTimeAppointment()
    {
        day = 1;
        month = 1;
        year = 1;
        super.setDescription("");
    }

    /** Construct an one time appointment with a set date and desription
     * @param year num of year
     * @param month num of month
     * @param day num of day
     * @param description String description of the appointment*/
    public OneTimeAppointment(int year, int month, int day, String description)
    {
        this.year = year;
        this.month = month;
        this.day = day;
        super.setDescription(description);
    }

    @Override
    public boolean occursOn(int year, int month, int day)
    {
        if(this.year == year && this.month == month && this.day == day)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
