//File Name: BikeLock.java
//Author(s): Isaac Meyer & James Donckels
//Email(s): imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 7 Chapter 6 Program 11
//Description: A program that will let user twist the rings on a combination lock to unlock it
//Last Date Changed: 02/23/2023

import javax.swing.*;
import java.util.Random;

/** Class to unlock a bike lock. */
public class BikeLock
{
    //Declare variables
    private final int PASSWORD = 7777;
    static final int TEN = 10, HUNDRED = 100, THOUSAND = 1000, PASS_LENGTH = 4;
    private int r1, r2, r3, r4;

    /** Constructs a bike lock to a random combination. */
    public BikeLock()
    {
        Random generator = new Random();
        r1 = generator.nextInt(TEN);
        r2 = generator.nextInt(TEN);
        r3 = generator.nextInt(TEN);
        r4 = generator.nextInt(TEN);
    }

    /** Constructs a bike lock with the given integer
        @param num num to set the starting bike lock to */
    public BikeLock(String num)
    {
        int temp = Integer.parseInt(num);
        if(temp < 0)
        {
            r1 = 0;
            r2 = 0;
            r3 = 0;
            r4 = 0;
        }
        else if(temp > 9999)
        {
            r1 = 9;
            r2 = 9;
            r3 = 9;
            r4 = 9;
        }
        else
        {
            r1 = temp / THOUSAND;
            r2 = (temp % THOUSAND) / HUNDRED;
            r3 = (temp % HUNDRED) / TEN;
            r4 = temp % TEN;
        }
    }

    /** Return the current combination to the user
        @return the current combination integer */
    public int getCurrent()
    {
        int current = (r1 * THOUSAND) + (r2 * HUNDRED) + (r3 * TEN) + r4;
        return current;
    }

    /** Twist the specified ring by the specified amount
        @param inStr variable for determining if twisting up or down
        @param numTwist number of twists user wants to twist by
        @param ringNum number of the ring that the program is applying the changed onto */
    public void twistRing(String inStr, int numTwist, int ringNum)
    {
        if(inStr.equals("u"))
        {
            twistUp(numTwist, ringNum);
        }
        else if(inStr.equals("d"))
        {
            twistDown(numTwist, ringNum);
        }
        else
        {
            System.out.println("Error 001");
        }
    }

    /** Twist the ring
        @param digitNum number of twists
        @param ringNum number of the current ring */
    public void twistUp(int digitNum, int ringNum)
    {
        switch(ringNum)
        {
            case 1:
                r1 += digitNum;
                r1 = r1 % TEN;
                break;
            case 2:
                r2 += digitNum;
                r2 = r2 % TEN;
                break;
            case 3:
                r3 += digitNum;
                r3 = r3 % TEN;
                break;
            case 4:
                r4 += digitNum;
                r4 = r4 % TEN;
                break;
            default:
                System.out.println("Error 003");
                break;
        }
    }

    /** Twist the ring
     @param digitNum number of twists
     @param ringNum number of the current ring */
    public void twistDown(int digitNum, int ringNum)
    {
        switch(ringNum)
        {
            case 1:
                r1 -= digitNum;
                r1 = r1 % TEN;
                if(r1 < 0)
                {
                    r1 += TEN;
                }
                break;
            case 2:
                r2 -= digitNum;
                r2 = r2 % TEN;
                if(r2 < 0)
                {
                    r2 += TEN;
                }
                break;
            case 3:
                r3 -= digitNum;
                r3 = r3 % TEN;
                if(r3 < 0)
                {
                    r3 += TEN;
                }
                break;
            case 4:
                r4 -= digitNum;
                r4 = r4 % TEN;
                if(r4 < 0)
                {
                    r4 += TEN;
                }
                break;
            default:
                System.out.println("Error 003");
                break;
        }
    }

    /** Check if the current combination is correct
        @return true or false depending on combination and password's compatibility */
    public boolean isCorrect()
    {
        int fin = (r1 * THOUSAND) + (r2 * HUNDRED) + (r3 * TEN) + r4;
        if(fin == PASSWORD)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
