import java.awt.*;
import javax.swing.JComponent;
/**
 * This component draws two car shapes.
 */

public class CarComponent extends JComponent
{
    private Color one, two;
    public void getColors(Color one, Color two)
    {
        this.one = one;
        this.two = two;
    }
    public void paintComponent(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        Car car1 = new Car(0, 0, one);

        int x = getWidth() - 60;
        int y = getHeight() - 30;

        Car car2 = new Car(x, y, two);

//        g2.setColor(one);
        car1.draw(g2);
//        g2.setColor(two);
        car2.draw(g2);
    }
}