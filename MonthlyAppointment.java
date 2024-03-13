package Appointments;

/** Class for keeping track of a monthly appointment */
public class MonthlyAppointment extends Appointment
{
    private int dayOfMonth;

    /** Constructs object of MonthlyAppointment class */
    public MonthlyAppointment()
    {
    }

    /** Constructs object of MonthlyAppointment class with set dayOfMonth and String description
     * @param day day of month of the appointment
     * @param description description of the appointment */
    public MonthlyAppointment(int day, String description)
    {
        super.setDescription(description);
        dayOfMonth = day;
    }


    @Override
    public boolean occursOn(int year, int month, int day)
    {
        if(dayOfMonth == day)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
