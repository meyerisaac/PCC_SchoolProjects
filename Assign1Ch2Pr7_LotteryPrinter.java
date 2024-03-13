import java.util.*;

public class Assign1Ch2Pr7_LotteryPrinter {
    public static void main(String[] args)
    {
        //Build the new Random object
        Random num = new Random();

        //Create a String for the space character(not sure why char doesn't work)
        String space = " ";

        //This was a test module I was using to verify the random number generator working
        //int lottery = num.nextInt(49) + 1;

        //Output message generating a new number as the program goes along
        System.out.println("Use these lottery numbers to win: " + (num.nextInt(49) + 1)
        + space + (num.nextInt(49) + 1) + space + (num.nextInt(49) + 1) + space +
        (num.nextInt(49) + 1) + space + (num.nextInt(49) + 1) + space + (num.nextInt(49) + 1));
    }
}

/*Sample Run:
Use these lottery numbers to win: 45 8 11 8 15 20
 */