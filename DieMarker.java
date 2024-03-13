//File Name: DieMarker.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 7 Chapter 7 Program 2 & 3
//Description: Write program that can generate markers at desired intervals
//Last Date Changed: 03/02/2023

import java.util.Random;

/** Class for marking all runs within a series of numDie num of rolls */
public class DieMarker
{
    //Declare private and static ints
    static final int numDie = 20;
    private int[] die = new int[numDie];
    private boolean running;

    /** Create object of DieMarker class with random rolled die */
    public DieMarker()
    {
        Random generator = new Random();
        for(int i = 0; i < numDie; i++)
        {
            die[i] = generator.nextInt(6) + 1;
        }
        running = false;
    }

    /** Roll the all the die in the array to randomize the numbers */
    public void rollDice()
    {
        Random generator = new Random();
        for(int i = 0; i < numDie; i++)
        {
            die[i] = generator.nextInt(6) + 1;
        }
        running = false;
    }

    /** Generate the string of numbers with the markers
        @return String with all generated markers around randomly generated die rolls */
    public String generateAllMarkers()
    {
        String out = "";

        for(int i = 0; i < numDie - 1; i++)
        {
            if((die[i] == die[i + 1]) && !running)
            {
                running = true;
                out += "( ";
            }

            out += die[i] + " ";

            if((die[i] != die[i + 1]) && running)
            {
                running = false;
                out += ") ";
            }
        }

        if(running)
        {
            out += ") ";
        }

        running = false;
        return out;
    }

    /** Generate the string of numbers with the markers
     @return String with generated markers around longest run of randomly generated die rolls */
    public String markLongest()
    {
        String out = "";
        int longestAt = 1, currentAt = 1, longest = 0, counter = 0;

        for(int i = 0; i < numDie - 1; i++)
        {
            if(running)
            {
                counter++;
            }
            if((die[i] == die[i + 1]) && !running)
            {
                running = true;
                currentAt = i;
                counter = 1;
            }
            if((die[i] != die[i + 1]) && running)
            {
                running = false;
                if(counter > longest)
                {
                    longestAt = currentAt;
                    longest = counter;
                }
            }
        }

        for(int i = 0; i < numDie; i++)
        {
            if(i == longestAt)
            {
                out += "( ";
            }
            if(i == longestAt + longest)
            {
                out += ") ";
            }
            out += die[i] + " ";


        }

        return out;
    }
}
