//File Name: clockTester.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 10 Chapter 9 Program 2
//Description: Write classes that can find the time in current or other time zones
//Last Date Changed: 04/04/2023

package Clocks;

public class clockTester
{
    public static void main(String[] args)
    {
        int timeZoneDiff = 3;
        Clock currentTime = new Clock();
        WorldClock otherTime = new WorldClock(timeZoneDiff);

        System.out.println("Current time here is: " + currentTime.getTime() + "\nTime in other time zone(" + timeZoneDiff + " timezones away) is: " + otherTime.getTime());
    }
}

/*Sample Run:
Current time here is: 10:57
Time in other time zone(3 timezones away) is: 13:57

Process finished with exit code 0
 */