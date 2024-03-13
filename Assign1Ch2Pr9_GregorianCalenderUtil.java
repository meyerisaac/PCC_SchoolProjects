import java.util.Calendar;
import java.util.GregorianCalendar;

public class Assign1Ch2Pr9_GregorianCalenderUtil
{
    public GregorianCalendar addHundredDays(GregorianCalendar date)
    {
        //Add 100 days to the given GregorianCalender object and return it
         date.add(Calendar.DAY_OF_MONTH, 100);
         return date;
    }

    public String dateToWeekday(GregorianCalendar date)
    {
        //Get the integer value of the day of the week
        int num = date.get(Calendar.DAY_OF_WEEK);

        //Switch case and return day in string format
        switch(num) {
            case 1:
                return "Sunday";
            case 2:
                return "Monday";
            case 3:
                return "Tuesday";
            case 4:
                return "Wednesday";
            case 5:
                return "Thursday";
            case 6:
                return "Friday";
            case 7:
                return "Saturday";
            default:
                System.out.println("Error in public String dateToWeekday(GregorianCalender date) switch case");
                break;
        }
        return " ";
    }

    public String dateToMonth(GregorianCalendar date)
    {
        //Get integer value of the month
        int num = date.get(Calendar.MONTH);

        //Switch case and return month in string format
        switch(num)
        {
            case 0:
                return "January";
            case 1:
                return "February";
            case 2:
                return "March";
            case 3:
                return "April";
            case 4:
                return "May";
            case 5:
                return "June";
            case 6:
                return "July";
            case 7:
                return "August";
            case 8:
                return "September";
            case 9:
                return "October";
            case 10:
                return "November";
            case 11:
                return "December";
            default:
                System.out.println("Error in dateToMonth switch case");
                break;
        }

        return " ";
    }

    //This method will output the date in both integer and string format given a GregorianCalender object
    public void out(GregorianCalendar date)
    {
        //Create the util object so we can use the methods we've written in this file
        Assign1Ch2Pr9_GregorianCalenderUtil util = new Assign1Ch2Pr9_GregorianCalenderUtil();

        //Get the integer and strings we'll be using in the output and store them in variables
        int dayOfMonth = date.get(Calendar.DAY_OF_MONTH), monthOfYear = date.get(Calendar.MONTH) + 1, year = date.get(Calendar.YEAR);
        String weekDay = util.dateToWeekday(date), month = util.dateToMonth(date);

        //Output in the set format
        System.out.println("The date is " + monthOfYear + "-" + dayOfMonth + "-" + year + "\n" + weekDay + " of " + month);
    }
}
