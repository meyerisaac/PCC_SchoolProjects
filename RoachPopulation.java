//File Name: RoachPopulation.java
//Author(s): Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 3 Chapter 3 Program 11
//Description: Class File containing the public interface and methods of the RoachPopulation Class
//Last Date Changed: 02/02/2023

/** A roach population grows and shrinks over time due to breeding and dying off from insecticides. */

public class RoachPopulation
{
    //Initialize the instance variable for population
    private int population;

    /** Constructs a roach population of 0. */
    public RoachPopulation()
    {
    }

    /** Constructs a roach population given an initial population. */
    public RoachPopulation(int population)
    {
        //Sets instant variable to argument
        this.population = population;
    }

    /** doubles the roach population. */
    public void breed()
    {
        population *= 2;
    }


    /**Reduces the roach population size by the given percentage
    @param percent the percentage of roach population to remove*/
    public void spray(double percent)
    {
        population *= (1.0 - percent);
    }

    /** Gets the size of the roach population.
     @return the number of roaches in the population*/
    public int getRoaches()
    {
        return population;
    }

    /** Sets the population size.
     @param population the new population size */
    public void setPopulation(int population)
    {
        this.population = population;
    }
}
