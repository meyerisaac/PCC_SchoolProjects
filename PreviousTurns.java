package Program1;

/** Object class to keep track of all turns made by a lock */
public class PreviousTurns
{
    //Declare all instance and class variables
    private int dialPosition;
    private int turnDirection;

    /** Creates at object of PreviousTurns class
     * @param position position of the turn
     * @param direction direction made by the turn*/
    public PreviousTurns(int position, int direction)
    {
        dialPosition = position;
        turnDirection = direction;
    }

    /** Retrieve the position stored in object
     * @return integer value of stored position */
    public int getDialPosition()
    {
        return dialPosition;
    }

    /** Retrieve thie direction stored in the object
     * @return positive for right turn and negative for left turn */
    public int getDirection()
    {
        return turnDirection;
    }
}
