import java.awt.*;

/**
 * This can be used to draw a house.
 */
public class House
{
    /**
     * Instance Variables
     */
    private int xPos;
    private int yPos;
    private int size;
    private Color houseColor;

    /**
     * Constructs a default House object.
     */
    public House()
    {
        xPos = 0;
        yPos = 0;
        size = 1;
        houseColor = Color.DARK_GRAY;
    }

    /**
     * Constructs a House given a position and size.
     * @param x the x position of the bottom left corner of the house
     * @param y the y position of the bottom left corner of the house
     * @param houseSize the scale factor of the house
     * @param initialColor the color of the house
     */
    public House(int x, int y, int houseSize, Color initialColor)
    {
        xPos = x;
        yPos = y;
        size = houseSize;
        houseColor = initialColor;
    }

    /**
     * Draws the House object.
     * @param g2 where all the house components will be
     */
    public void draw(Graphics2D g2)
    {
        // set color of house
        g2.setColor(houseColor);

        // Create the triangle that will be the roof
        int[] triangleXCoords = {xPos, xPos + (size * 7), xPos + (size * 14)};
        int[] triangleYCoords = {yPos + (size * 7), yPos, yPos + (size * 7)};
        Polygon triangle = new Polygon(triangleXCoords,triangleYCoords,3);
        g2.fill(triangle);

        // Create the rectangle that will be the frame of the house
        Rectangle houseFrame = new Rectangle(xPos, yPos + (size * 7),
                size * 14, size * 13);
        g2.fill(houseFrame);

        // create the door of the house
        Rectangle door = new Rectangle(xPos + (size * 5),yPos + (size * 14),
                size * 4,size * 6);
        g2.setColor(Color.BLACK);
        g2.fill(door);

        // create the left window
        Rectangle leftWindow = new Rectangle(xPos + (size),yPos + (size * 9),
                size * 3, size * 3);
        g2.fill(leftWindow);

        // create the right window
        Rectangle rightWindow = new Rectangle(xPos + (size * 10), yPos + (size * 9),
                size * 3, size * 3);
        g2.fill(rightWindow);

        // create a chimney
        int[] chimneyXCoords = {xPos + (size * 10),xPos + (size * 10),xPos + (size * 12),xPos + (size * 12)};
        int[] chimneyYCoords = {yPos + (size * 3),yPos,yPos,yPos + (size * 5)};
        Polygon chimney = new Polygon(chimneyXCoords,chimneyYCoords,4);
        g2.setColor(houseColor);
        g2.fill(chimney);
    }
}
