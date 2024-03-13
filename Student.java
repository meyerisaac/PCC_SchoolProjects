//File Name: student.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 3 Chapter 3 Program 8
//Description: Class file with all method declaration and definition
//Last Date Changed: 01/31/2023

/**Keeps track of student scores*/
public class Student
{
    //Declare all the private and static ints needed
    private String name;
    private int ID;
    private int total = 0, numQuiz = 0;
    static int numID;

    /**Constructs Student object with the required arguments*/
    public Student(String firstName, String lastName)
    {
        ID = numID;
        numID++;
        name = firstName + " " + lastName;
    }

    /**Retrieves the name of the student
     @return the name of student*/
    public String getName()
    {
        return name;
    }

    /**Adds an inputted quiz score to the object
     @param score the quiz score inputted*/
    public void addQuiz(int score)
    {
        total += score;
        numQuiz++;
    }

    /**Retrieves the total score of all inputted quizzes
     @return the total score of the student*/
    public double getTotalScore()
    {
        return total;
    }

    /**Retrieves the average score of all inputted quizzes
     @return the average score of the student*/
    public double getAverageScore()
    {
        double average = total / numQuiz;
        return average;
    }

}
