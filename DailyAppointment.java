package Appointments;

/** Clas to keep track of a daily appointment */
public class DailyAppointment extends Appointment
{
    /** Construct a daily appointmnet with a set description
     * @param description String description of the appointment */
    public DailyAppointment(String description)
    {
        super.setDescription(description);
    }

    @Override
    public boolean occursOn(int year, int month, int day)
    {
        return true;
    }
}
