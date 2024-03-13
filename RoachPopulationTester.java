//File Name: RoachPopulationTester.java
//Author(s): Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 3 Chapter 3 Program 11
//Description: Run methods of RoachPopulation class. Breed and spray 3 times and display the current population
//at each stage of the algorithm.
//Last Date Changed: 02/02/2023

public class RoachPopulationTester {
    public static void main(String[] args)
    {
        //Declare and initialize variables
        int population = 10;
        double sprayPercentage = 0.10;

        //Create object of RoachPopulation Class
        RoachPopulation test1 = new RoachPopulation(population);

        //Print out current population after construction and expected population
        System.out.println("Beginning population is " + test1.getRoaches());
        System.out.println("Expected output is " + population);

        //Breed and spray 3 times
        for(int i = 0; i < 3; i++)
        {
            //Breed and display value of object and expected value
            test1.breed();
            population *= 2;
            System.out.println("Population after breeding is " + test1.getRoaches() + " for run #" + (i + 1));
            System.out.println("Expected output is " + population);

            //Spray and display value of object and expected value
            test1.spray(sprayPercentage);
            population *= (1.0 - sprayPercentage);
            System.out.println("Population after spraying is " + test1.getRoaches() + " for run #" + (i + 1));
            System.out.println("Expected output is " + population);
        }

        //Say hi to the user
        System.out.println("Hello world!");
    }
}

/*Sample Run:
Beginning population is 10
Expected output is 10
Population is 20 for run #1
Expected output is 20
Population is 18 for run #1
Expected output is 18
Population is 36 for run #2
Expected output is 36
Population is 32 for run #2
Expected output is 32
Population is 64 for run #3
Expected output is 64
Population is 57 for run #3
Expected output is 57
Hello world!

Process finished with exit code 0
 */