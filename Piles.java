import java.util.Arrays;
import java.util.Random;

public class Piles
{
    static final int NUM_CARDS = 45, CORRECT_LENGTH = 9;
    int numPiles;
    private int[] piles;
    public Piles()
    {
        Random generator = new Random();
        numPiles = generator.nextInt(NUM_CARDS) + 1;
        piles = new int[numPiles];
        setArray();
    }

    public Piles(int num)
    {
        numPiles = num;
        piles = new int[numPiles];
        setArray();
    }

    public void setArray()
    {
        int numLeft = NUM_CARDS;
        Random generator = new Random();

        for(int i = 0; i < numPiles - 1; i++)
        {
            piles[i] = generator.nextInt(numLeft + 1);
            numLeft -= piles[i];
            if(numLeft < 0)
            {
                numLeft = 0;
            }
        }
        piles[numPiles - 1] = numLeft;
        removeZeroes();
    }

    public void simRound()
    {
        decrementPiles();
        removeZeroes();
        increaseSize();
    }

    public void decrementPiles()
    {
        for(int i = 0; i < numPiles; i++)
        {
            if(piles[i] > 0)
            {
                piles[i]--;
            }
        }
    }

    public void removeZeroes()
    {
        for(int i = 0; i < numPiles - 1; i++)
        {
            if(piles[i] == 0)
            {
                for(int j = i; j < numPiles - 2; j++)
                {
                    piles[j] = piles[j + 1];
                }
                numPiles--;
            }
        }
    }

    public void increaseSize()
    {
        if(numPiles < piles.length)
        {
            piles[numPiles] = numPiles;
        }
        else if(numPiles == piles.length)
        {
            piles = Arrays.copyOf(piles, numPiles + 1);
            piles[numPiles] = numPiles;
        }
    }

    public void displayArray()
    {
        for(int i = 0; i < numPiles; i++)
        {
            System.out.print(piles[i] + " ");
        }
    }

    public boolean isDone()
    {
        Arrays.sort(piles);
        if(piles.length != CORRECT_LENGTH)
        {
            return false;
        }
        else if(piles[0] == 1 && piles[CORRECT_LENGTH - 1] == CORRECT_LENGTH)
        {
            System.out.println("Game Over! :)x");
            return true;
        }
        else
        {
            System.out.println("Error 001");
            return true;
        }
    }
}
