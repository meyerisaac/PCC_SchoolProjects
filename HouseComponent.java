import javax.swing.*;
import java.awt.*;

/**
 * This component draws houses.
 */
public class HouseComponent extends JComponent
{
    public void paintComponent(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        House testHouse = new House();

        // unit house
        testHouse.draw(g2);

        // more houses
        House house2 = new House(50,20,10,Color.RED);
        house2.draw(g2);

        House house3 = new House(100,300,5,Color.MAGENTA);
        house3.draw(g2);

        House house4 = new House(0,350,6,Color.BLUE);
        house4.draw(g2);

        Color purple = new Color(115, 24, 192);
        House house5 = new House(250,0,3,purple);
        house5.draw(g2);

        Color green = new Color(23, 197, 23);
        House house6 = new House(250,100,15,green);
        house6.draw(g2);

    }
}
