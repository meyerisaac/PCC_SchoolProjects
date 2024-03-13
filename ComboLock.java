//File Name: Program1.tester.java
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 9 Chapter 8 Program 1
//Description: A lock that will unlock if given the correct input
//Last Date Changed: 03/23/2023

package Program1;

import java.util.ArrayList;


/** Class for simulating a lock that requires a right turn, left turn, and right turn to unlock */
public class ComboLock
{
    //Declare all instance and class variables needed
    private int passOne, passTwo, passThree, currentDial;
    private ArrayList<PreviousTurns> previousTurnsArrayList;
    static final int DIALMAX = 39, DIALMIN = 0, RIGHT_TURN = 1, LEFT_TURN = -1;
    private boolean firstCorrect, secondCorrect, thirdCorrect;

    /** Creates object of ComboLock class */
    public ComboLock()
    {
        passOne = 0;
        passTwo = 0;
        passThree = 0;
        currentDial = 0;
        firstCorrect = false;
        secondCorrect = false;
        thirdCorrect = false;
        previousTurnsArrayList = new ArrayList<>(0);
    }

    /** Creates object of class ComboLock
     * @param first first number of lock password
     * @param second second number of lock password
     * @param third third number of lock password*/
    public ComboLock(int first, int second, int third)
    {
        passOne = first;
        passTwo = second;
        passThree = third;
        currentDial = 0;
        firstCorrect = false;
        secondCorrect = false;
        thirdCorrect = false;
        previousTurnsArrayList = new ArrayList<>(0);
    }

    /** Reset all parameters in object */
    public void reset()
    {
        currentDial = 0;
        firstCorrect = false;
        secondCorrect = false;
        thirdCorrect = false;
    }


    /** Retrieve the current position of the lock's dial
     * @return integer number representing current position */
    public int getPosition()
    {
        return currentDial;
    }

    /** Turn the lock's dial to the right
     * @param ticks number of turns */
    public int rightTurn(int ticks)
    {
        currentDial += ticks;

        if(currentDial > DIALMAX)
        {
            currentDial -= DIALMAX + 1;
        }

        previousTurnsArrayList.add(new PreviousTurns(ticks, RIGHT_TURN));

        return currentDial;
    }

    /** Turn the lock's dial to the left
     * @param ticks number of turns */
    public int leftTurn(int ticks)
    {
        currentDial -= ticks;

        if(currentDial < DIALMIN)
        {
            currentDial += DIALMAX + 1;
        }

        previousTurnsArrayList.add(new PreviousTurns(ticks, LEFT_TURN));

        return currentDial;
    }

    /** Check if the lock is unlocked
     * @return true if lock is open and false if lock is closed */
    public boolean openLock()
    {
        int locationFirstTurn = 0, locationSecondTurn = 0;
        for(int i = previousTurnsArrayList.size() - 1; i >= 0; i--)
        {
            if(!firstCorrect)
            {
                if((previousTurnsArrayList.get(i).getDialPosition() == passOne) && (previousTurnsArrayList.get(i).getDirection() == RIGHT_TURN))
                {
                    firstCorrect = true;
                    locationFirstTurn = previousTurnsArrayList.get(i).getDialPosition();
                }
            }
            else if(firstCorrect && !secondCorrect)
            {
                if((previousTurnsArrayList.get(i).getDialPosition() == passTwo) && (previousTurnsArrayList.get(i).getDirection() == LEFT_TURN))
                {
                    for(int j = previousTurnsArrayList.get(i).getDialPosition(); j > locationFirstTurn; j--)
                    {
                        if(previousTurnsArrayList.get(i).getDirection() != LEFT_TURN)
                        {
                            firstCorrect = false;
                        }
                    }
                    secondCorrect = true;
                    locationSecondTurn = previousTurnsArrayList.get(i).getDialPosition();
                }
            }
            else if(firstCorrect && secondCorrect && !thirdCorrect)
            {
                if((previousTurnsArrayList.get(i).getDialPosition() == passThree) && (previousTurnsArrayList.get(i).getDirection() == RIGHT_TURN))
                {
                    for(int j = previousTurnsArrayList.get(i).getDialPosition(); j > locationSecondTurn; j--)
                    {
                        if(previousTurnsArrayList.get(i).getDirection() != RIGHT_TURN)
                        {
                            firstCorrect = false;
                            secondCorrect = false;
                        }
                    }
                    thirdCorrect = true;
                }
            }

            if(firstCorrect && secondCorrect && thirdCorrect)
            {
                return true;
            }
        }

        return false;
    }


}
