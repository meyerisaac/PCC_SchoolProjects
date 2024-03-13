//File Name: probabilityTester.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 6 Chapter 6 Program 9
//Description: Run a number of tests on given parameters to find the net result after desired number of loops
//Last Date Changed: 02/20/2023

import java.util.Random;

/** Runs a number of specific probabilities multiple times to calculate the total amount lost or won */
public class probabilityTester
{
    private int numRuns, triesPerRun, prob, totalProb;
    private long amount;
    /** Creates object of probabilityTester class */
    public probabilityTester()
    {
        numRuns = 0;
        triesPerRun = 0;
        prob = 0;
        totalProb = 0;
        amount = 0;
    }

    /** Creates object of probabilityTester class with given parameters
     @param prob probability of each run
     @param numRuns number of times simulation should be run
     @param triesPerRun range of each roll
     @param totalProb number of runs in each simulation */
    public probabilityTester(int prob, int numRuns, int triesPerRun, int totalProb)
    {
        this.prob = prob;
        this.totalProb = totalProb;
        this.numRuns = numRuns;
        this.triesPerRun = triesPerRun;
        amount = 0;
    }

    /** Set the parameters of an object of probabilityTester class
     @param prob probability of each run
     @param numRuns number of times simulation should be run
     @param triesPerRun range of each roll
     @param totalProb number of runs in each simulation */
    public void setParameters(int prob, int numRuns, int triesPerRun, int totalProb)
    {
        this.prob = prob;
        this.totalProb = totalProb;
        this.numRuns = numRuns;
        this.triesPerRun = triesPerRun;
        amount = 0;
    }

    /** Calculate the total amount won or lost after running simulations with given parameters
     @return total amount won or lost */
    public long run()
    {
        Random generator = new Random();
        boolean tempLoop;
        int numGen, counter;

        for(int i = 0; i < numRuns; i++)
        {
            tempLoop = true;
            counter = 0;

            for(int j = 0;(tempLoop) && i < totalProb; j++)
            {
                numGen = (generator.nextInt(triesPerRun) + 1);

                if(numGen > prob)
                {
                    amount--;
                    counter++;
                }
                else if(numGen == prob)
                {
                    amount += counter + 1;
                    tempLoop = false;
                }
            }
        }

        return amount;
    }

    /** Retrieve the total amount calculated
    @return total amount calculated in .run() method */
    public long getAmount()
    {
        return amount;
    }
}
