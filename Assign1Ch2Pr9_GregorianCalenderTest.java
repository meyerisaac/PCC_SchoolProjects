import javax.swing.*;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Assign1Ch2Pr9_GregorianCalenderTest
{
    public static void main(String[] args)
    {
        //Create the GregorianCalender objects we'll be using
        GregorianCalendar dateTest = new GregorianCalendar();
        GregorianCalendar myBirthday = new GregorianCalendar(2004,
                Calendar.AUGUST, 25);

        //Create our util objects, so we can utilize the methods we've programmed
        Assign1Ch2Pr9_GregorianCalenderUtil dateUtil = new Assign1Ch2Pr9_GregorianCalenderUtil(); // Today’s date

        //Use the addHundredDays method of the object we created and output its date
        System.out.println("Adding One Hundred Days..");
        dateUtil.addHundredDays(dateTest);
        dateUtil.out(dateTest);

        //Output the programmer's birthdate
        System.out.println("\nThe Date Of This Programs Programmer's Birthday..");
        dateUtil.out(myBirthday);

        //Use the addHundredDays method 100 times to add a total of 10,000 days and output the date
        System.out.println("\nAdding Ten Thousand Days To Programmer's Birthday..");
        for(int i = 0; i < 100; i++)
        {
            dateUtil.addHundredDays(myBirthday);
        }
        dateUtil.out(myBirthday);
    }
}

/*Sample Run:
Adding One Hundred Days..
The date is 4-29-2023
Saturday of April

The Date Of This Programs Programmer's Birthday..
The date is 8-25-2004
Wednesday of August

Adding Ten Thousand Days To Programmer's Birthday..
The date is 1-11-2032
Sunday of January

Process finished with exit code 0
 */