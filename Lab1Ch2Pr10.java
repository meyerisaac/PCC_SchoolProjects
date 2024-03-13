import java.time.LocalDate;

public class Lab1Ch2Pr10 {
    public static void main(String[] args)
    {

        LocalDate today = LocalDate.now(); // Today’s date
        LocalDate previousDate = today.minusDays(10000);//Date 10000 days ago
        LocalDate piDay = LocalDate.of(2023, 3, 14); //initialize to date on piDay
        LocalDate firstDay = LocalDate.of(2023, 1, 1); //initialize to first day of year
        LocalDate programmerDay = firstDay.plusDays(256 - 1); //initialize to programmer day from first day


        System.out.println(piDay.getDayOfWeek().toString()); //print day of week for pi day
        System.out.println(programmerDay);                   //print date of programmer day
        System.out.println(programmerDay.getDayOfWeek().toString());    //print day of week for programmer day
        System.out.println(previousDate);                               //display previousDate
        System.out.println(previousDate.getDayOfWeek().toString());     //display day of week of previousDate

        System.out.println("Bye world!");
    }
}

/*Sample Run:
TUESDAY
2023-09-13
WEDNESDAY
1995-09-03
SUNDAY
Bye world!
 */